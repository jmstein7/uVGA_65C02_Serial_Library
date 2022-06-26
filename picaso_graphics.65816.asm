/*
MIT License

Copyright (c) 2022 Jonathan Stein (New York, USA)

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/
                                             ;*I use RetroAssembler
          .setting "HandleLongBranch", true  ;
	  .target "65816"                    ;*Target can be '816 or 'C02
	  .format "prg"                      ;

;Important Equates

ACIA            = $DF14         ;
ACIA_Data	= $DF14		;*Adjust these addresses to point 
ACIA_Status	= $DF15		; to YOUR 6551 (ACIA)!
ACIA_Command	= $DF16		;
ACIA_Control	= $DF17
EIFR		= $DF45
EIER		= $DF47
                                ;*These are for an ACIA to
uVGA            = $DF10         ; uVGA connection
uVGA_Data	= $DF10		;(I jumper CTS to RTS)
uVGA_Status	= $DF11         ;*uVGA-III Serial Enviornment
uVGA_Command	= $DF12         ; my COM speed is set to 115200
uVGA_Control	= $DF13

;Parallel Interface Bus (for 65C265 only)
PIBER		= $DF79
PIBFR		= $DF78
PIR2		= $DF7A
PIR3		= $DF7B
PIR4		= $DF7C
PIR5		= $DF7D
PIR6		= $DF7E
PIR7 		= $DF7F

;useful subroutines
soft_reset      = $7E           ;*address for soft reset on your system
ECHO            = $80           ;*print character routine
get_byte        = $82           ;*grab character routine
delay           = $84           ;*a delay routine

;DP/ZP storage addresses/pseudo-registers
retry		= $3d		; retry counter 
retry2		= $3e		; 2nd counter

MSGL      	= $86
MSGH      	= $87

Send_low        = $78		;Receive Start Address/Page
Send_High 	= $79
Send_bytesL	= $7A		;Number of bytes to receive
Send_bytesH	= $7B

.include "picaso_constants.inc"

;
; End of Picaso 4D preamble "includes"


	        *= $1000		; Start of program (adjust to your needs)
                
                SEI
                PHA             ;*Saving registers
                PHX
                PHY
	        PHP             ;*State Saved
                SEP #$30        ;*Only for '816 or '265
;
;       BEGIN MAIN TEST PROGRAM
;     (some random test routines)
;
                JSR uClear_Screen
                LDA #>HOTPINK
                STA uColorH
                LDA #<HOTPINK
                STA uColorL
                JSR uTxt_Foreground
                LDA #<MSG2
                STA MSGL
                LDA #>MSG2
		STA MSGH
                JSR uCopy_String      ;* Copy MSG to string buffer
                JSR uPut_String
                STZ txt_charH
                LDA #$0A 
                STA txt_charL
                JSR uPut_Character
                LDA #$0D 
                STA txt_charL
                JSR uPut_Character
                ;JSR Short_Pause
                LDA #<MSG3
                STA MSGL
                LDA #>MSG3
		STA MSGH
                JSR uCopy_String      ;* Copy MSG to string buffer
                LDA #>CYAN
                STA uColorH
                LDA #<CYAN
                STA uColorL
                JSR uTxt_Foreground
                JSR uPut_String

                LDA #$0A 
                STA txt_charL
                JSR uPut_Character
                LDA #$0D 
                STA txt_charL
                JSR uPut_Character
                ;
                ;Demo
                ;
                ; Draw One pixel
                STZ uXpointH
                STZ uYpointH
                LDA #$50
                STA uXpointL
                LDA #$64 
                STA uYpointL
                LDA #>RED
                STA uColorH
                LDA #<RED
                STA uColorL
                JSR uPut_Pixel
                ; Draw a circle
                STZ uRadiusH
                STZ uXpointH
                LDA #$96
                STA uXpointL
                STZ uYpointH
                LDA #$E6
                STA uYpointL
                LDA #$32
                STA uRadiusL
                LDA #>ROYALBLUE
                STA uColorH
                LDA #<ROYALBLUE
                STA uColorL
                JSR uFilled_Circle
                ; Draw a Filled Triangle
                STZ uXpointH
                STZ uYpointH
                STZ uX2pointH
                STZ uY2pointH
                STZ uX3pointH
                STZ uY3pointH
                LDA #$32
                STA uXpointL
                LDA #$3C 
                STA uYpointL
                LDA #$14
                STA uX2pointL
                LDA #$AA 
                STA uY2pointL
                LDA #$46
                STA uX3pointL
                LDA #$AA  
                STA uY3pointL
                LDA #>PLUM
                STA uColorH
                LDA #<PLUM
                STA uColorL
                JSR uFilled_Triangle
                ;
                ; Get Orbit 
                STZ uAngleH
                STZ uDistanceH
                LDA #$28
                STA uAngleL
                LDA #$3C 
                STA uDistanceL
                JSR uCalculate_Orbit
                ;* print to debug
                JSR NEW_LINE
                ; Draw an Ellipse
                STZ uXpointH
                STZ uYpointH
                STZ uXRadiusH
                STZ uYRadiusH
                LDA #$96
                STA uXpointL
                LDA #$E6 
                STA uYpointL
                LDA #$68
                STA uXRadiusL
                LDA #$7F 
                STA uYRadiusL
                LDA #>Orange
                STA uColorH
                LDA #<Orange
                STA uColorL
                JSR uDraw_Ellipse
                ;*Get One pixel's color
                STZ uXpointH
                STZ uYpointH
                LDA #$50
                STA uXpointL
                LDA #$64 
                STA uYpointL
                JSR uRead_Pixel
                ;
                ;*Draw Polyline
                ;
                JSR Reset_XYCoordinates
                STZ uXpointH
                STZ uYpointH
                LDA #$0A
                STA uXpointL
                LDA #$05
                STA uYpointL
                JSR Set_XYCoordinates
                LDA #$50
                STA uXpointL
                LDA #$C8
                STA uYpointL
                JSR Set_XYCoordinates
                LDA #$B4
                STA uXpointL
                LDA #$50
                STA uYpointL
                JSR Set_XYCoordinates
                LDA #>LAWNGREEN
                STA uColorH
                LDA #<LAWNGREEN
                STA uColorL
                JSR uDraw_Polygon
                ;
                ;*Test SD card tools
                ;
                LDA #<MSG5
                STA MSGL
                LDA #>MSG5
		STA MSGH
                JSR uCopy_String        ;*Move file name to String Buffer
                ;
                JSR uFile_Mount
                LDA "w"                 ;*open new file for writing
                JSR uFile_Open          ; and get file handle
                ;
                LDA #<MSG4
                STA MSGL
                LDA #>MSG4
		STA MSGH
                JSR uCopy_String        ;*Move MSG4 to String Buffer
                ;
                JSR uWrite_String2SD    ;*Write MSG4 to SD
                JSR uFile_Close
                ;
                LDA #<MSG2
                STA MSGL
                LDA #>MSG2
		STA MSGH
                JSR uCopy_String        ;*Overwrite string buffer
                ;
                ;
                LDA #<MSG5
                STA MSGL
                LDA #>MSG5
		STA MSGH
                JSR uCopy_String        ;*Move file name to String Buffer
                ;
                JSR uFile_Mount
                LDA "r"                 ;*open new file for reading
                JSR uFile_Open          ; and get the file handle
                ;
                LDA #14                 ;*Get 14 characters from the SD
                JSR uReadSD_2String
                JSR uFile_Close
                JSR uFile_Unmount
                
;       RESTORE STATE AND RETURN
                ;Done and restore state
Done            SEP #$10
                PLP
                PLY
                PLX
                PLA
                CLI
                JMP (soft_reset)

;       END OF PROGRAM

.include "picaso_routines.inc"  ;Main Library Includes/Routines

;       ACIA Routines

NEW_LINE        LDA #$0D
                JSR (ECHO,x)    ;* New line.
                RTS

SHWMSG          PHX ;*save X
                PHY ;*save Y
                LDX #0
                LDY #0
@PRINT          LDA (MSGL),Y
                BEQ @DONEX
                JSR (ECHO,x)
                INY 
                BNE @PRINT
@DONEX          PLY ;*restore y
                PLX ;*restore x
                RTS

                *= $2000        ; set origin (buffer and variables must be in RAM)
				; 256 byte buffer (must start at page edge)
Buffer1	.word	$0000,$0000,$0000,$0000,$0000,$0000,$0000,$0000
	.word	$0000,$0000,$0000,$0000,$0000,$0000,$0000,$0000
	.word	$0000,$0000,$0000,$0000,$0000,$0000,$0000,$0000
	.word	$0000,$0000,$0000,$0000,$0000,$0000,$0000,$0000
	.word	$0000,$0000,$0000,$0000,$0000,$0000,$0000,$0000
	.word	$0000,$0000,$0000,$0000,$0000,$0000,$0000,$0000
	.word	$0000,$0000,$0000,$0000,$0000,$0000,$0000,$0000
	.word	$0000,$0000,$0000,$0000,$0000,$0000,$0000,$0000
	.word	$0000,$0000,$0000,$0000,$0000,$0000,$0000,$0000
	.word	$0000,$0000,$0000,$0000,$0000,$0000,$0000,$0000
	.word	$0000,$0000,$0000,$0000,$0000,$0000,$0000,$0000
	.word	$0000,$0000,$0000,$0000,$0000,$0000,$0000,$0000
	.word	$0000,$0000,$0000,$0000,$0000,$0000,$0000,$0000
	.word	$0000,$0000,$0000,$0000,$0000,$0000,$0000,$0000
	.word	$0000,$0000,$0000,$0000,$0000,$0000,$0000,$0000
	.word	$0000,$0000,$0000,$0000,$0000,$0000,$0000,$0000

BRindx				; buffer read index
	.byte $00

BWindx				; buffer write index
	.byte $00

Sendf                           ; am sending flag
	.byte $00

WByte                           ; temp store for the byte to be sent
	.byte $00
;
;messages/strings and buffers
;
        .align $10, $00

Txt_String1	.word	$0000,$0000,$0000,$0000,$0000,$0000,$0000,$0000
	        .word	$0000,$0000,$0000,$0000,$0000,$0000,$0000,$0000
	        .word	$0000,$0000,$0000,$0000,$0000,$0000,$0000,$0000
	        .word	$0000,$0000,$0000,$0000,$0000,$0000,$0000,$0000
	        .word	$0000,$0000,$0000,$0000,$0000,$0000,$0000,$0000
	        .word	$0000,$0000,$0000,$0000,$0000,$0000,$0000,$0000
	        .word	$0000,$0000,$0000,$0000,$0000,$0000,$0000,$0000
	        .word	$0000,$0000,$0000,$0000,$0000,$0000,$0000,$0000
	        .word	$0000,$0000,$0000,$0000,$0000,$0000,$0000,$0000
	        .word	$0000,$0000,$0000,$0000,$0000,$0000,$0000,$0000
	        .word	$0000,$0000,$0000,$0000,$0000,$0000,$0000,$0000
	        .word	$0000,$0000,$0000,$0000,$0000,$0000,$0000,$0000
	        .word	$0000,$0000,$0000,$0000,$0000,$0000,$0000,$0000
	        .word	$0000,$0000,$0000,$0000,$0000,$0000,$0000,$0000
	        .word	$0000,$0000,$0000,$0000,$0000,$0000,$0000,$0000
	        .word	$0000,$0000,$0000,$0000,$0000,$0000,$0000,$0000

        .align $10, $00

uYcoordinate	.word	$0000,$0000,$0000,$0000,$0000,$0000,$0000,$0000
	        .word	$0000,$0000,$0000,$0000,$0000,$0000,$0000,$0000
	        .word	$0000,$0000,$0000,$0000,$0000,$0000,$0000,$0000
	        .word	$0000,$0000,$0000,$0000,$0000,$0000,$0000,$0000
	        .word	$0000,$0000,$0000,$0000,$0000,$0000,$0000,$0000
	        .word	$0000,$0000,$0000,$0000,$0000,$0000,$0000,$0000
	        .word	$0000,$0000,$0000,$0000,$0000,$0000,$0000,$0000
	        .word	$0000,$0000,$0000,$0000,$0000,$0000,$0000,$0000
	        .word	$0000,$0000,$0000,$0000,$0000,$0000,$0000,$0000
	        .word	$0000,$0000,$0000,$0000,$0000,$0000,$0000,$0000
	        .word	$0000,$0000,$0000,$0000,$0000,$0000,$0000,$0000
	        .word	$0000,$0000,$0000,$0000,$0000,$0000,$0000,$0000
	        .word	$0000,$0000,$0000,$0000,$0000,$0000,$0000,$0000
	        .word	$0000,$0000,$0000,$0000,$0000,$0000,$0000,$0000
	        .word	$0000,$0000,$0000,$0000,$0000,$0000,$0000,$0000
	        .word	$0000,$0000,$0000,$0000,$0000,$0000,$0000,$0000
uYcoordinateN	.word	$0000
uYcoordinateNR  .word	$0000

        .align $10, $00

uXcoordinate	.word	$0000,$0000,$0000,$0000,$0000,$0000,$0000,$0000
	        .word	$0000,$0000,$0000,$0000,$0000,$0000,$0000,$0000
	        .word	$0000,$0000,$0000,$0000,$0000,$0000,$0000,$0000
	        .word	$0000,$0000,$0000,$0000,$0000,$0000,$0000,$0000
	        .word	$0000,$0000,$0000,$0000,$0000,$0000,$0000,$0000
	        .word	$0000,$0000,$0000,$0000,$0000,$0000,$0000,$0000
	        .word	$0000,$0000,$0000,$0000,$0000,$0000,$0000,$0000
	        .word	$0000,$0000,$0000,$0000,$0000,$0000,$0000,$0000
	        .word	$0000,$0000,$0000,$0000,$0000,$0000,$0000,$0000
	        .word	$0000,$0000,$0000,$0000,$0000,$0000,$0000,$0000
	        .word	$0000,$0000,$0000,$0000,$0000,$0000,$0000,$0000
	        .word	$0000,$0000,$0000,$0000,$0000,$0000,$0000,$0000
	        .word	$0000,$0000,$0000,$0000,$0000,$0000,$0000,$0000
	        .word	$0000,$0000,$0000,$0000,$0000,$0000,$0000,$0000
	        .word	$0000,$0000,$0000,$0000,$0000,$0000,$0000,$0000
	        .word	$0000,$0000,$0000,$0000,$0000,$0000,$0000,$0000
uXcoordinateN	.word	$0000
uXcoordinateNR  .word	$0000
        .align $10, $00

;*Routines tro Enter Multiple Xand Y Coordinates
;*Use for Polygons, Polylines,
; and anything else with N x/y Coordinates
; 
;*Call the routine below to reset the array
; pointers
;
Reset_XYCoordinates
        STZ uYcoordinateN ;*Reset N
        STZ uXcoordinateN ; pointers
        RTS

;*Set the coordinates to store in 
; uXpoint and uYpoint  
; then call the Subroutine to add to array
;
Set_XYCoordinates
        PHA
        PHX
        PHY     ;*Store Registers
        ;
        LDX uXcoordinateN       ;*Load X NPointer
        LDY uYcoordinateN       ;*Load Y NPointer
                                ;
                                ;*Store X-Coordinate
        LDA uXpointH
        STA uXcoordinate,X
        INX                     ; Increment X
        LDA uXpointL
        STA uXcoordinate,X
        INX
        STX uXcoordinateN
        DEX
        STX uXcoordinateNR
        ;
                                ;*Store Y-Coordinate
        LDA uYpointH
        STA uYcoordinate,Y
        INY                     ; Increment Y
        LDA uYpointL
        STA uYcoordinate,Y
        INY
        STY uYcoordinateN
        DEY 
        STY uYcoordinateNR
        ;
        ;
        PLY     ;*Restore Registers
        PLX
        PLA
        RTS
;

;
; read the data out of the buffer a byte at a time and decrement the pointer.
; the routine is called with the byte to read sent out to A. 

DecReadb      
        PHY   
        LDY	BWindx		; get write index
        LDA	Buffer1,Y	; get it   
        CPY     #0              ; if we're at the first byte
        BEQ     @done           ; then don't decrement counter
        DEC     BWindx          ; otherwise, decrement the index
@done   PLY
	RTS

; write the data to the buffer a byte at a time and increment the pointer.
; the routine is called with the byte to write in A. 

Incwritb                        ;Write to Buffer
	STA	WByte		; save byte to write
	LDA	BRindx		; get read index
        SEC                     ; set carry for subtract
	SBC	BWindx		; subtract write index
	BEQ	Dowrite		; if equal then buffer empty so do write
	CMP	#$02		; need at least n+1 bytes to avoid rollover
	BCC	Incwritb	; loop if no space

                                ; construct and write data to buffer
Dowrite PHY
	LDY	BWindx		; get write index
	LDA	WByte		; get byte to write
	STA	Buffer1,Y	; save it
        INY                     ; increment index to next byte
	STY	BWindx		; save new write index byte

Doingit PLY
	RTS
;
; get byte from the buffer and increment the pointer. If the buffer is empty then
; exit with the carry flag set else exit with carry clear and the byte in A

Increadb                        ; Read from buffer
	LDY	BRindx		; get buffer read index
	CPY	BWindx		; compare write index
	BEQ	@NOktoread	; branch if empty (= sets carry)
	LDA	Buffer1,Y	; get byte from buffer
        INY                     ; increment pointer
	STY	BRindx		; save buffer read index
        CLC                     ; clear not ok flag

@NOktoread
	RTS

; this is the main routine. takes a byte at a time from the buffer
; and does some thing with it. also sets up the device(s) for the next 

; no registers altered

Buffer_Out
        PHA                     ; save A
        PHX                     ;  X
        PHY                     ; save X
        PHP                     ;  Y
                                ; save Y
@Getnext
	JSR	Increadb	; increment pointer and read byte from buffer
	BCS	@ExitRTS	; branch if no byte to do

; here are the guts of the routine such as sending the byte to the ACIA or a
; printer port or some other byte device. it will also ensure the device is set to
; generate an interrupt when it's completed it's task

	LDA	#$FF		; set byte
	STA	Sendf		; set sending flag
	BRA	@ResExit	; restore the registers & exit

                                ; all done so clear the flag restore the regs & exit
@ExitRTS                        ; clear byte
	STZ	Sendf		; clear sending flag

@ResExit
        PLP
        PLY                     ; pull Y
        PLX                     ; restore it
        PLA                     ; pull X
        RTS                     ; restore it
                                ; restore A
                                ; exit properly

Reset_Buffer1
        STZ BRindx ;*Reset the buffer 1
        STZ BWindx ; read and write pointers
        RTS

;*****************************************************
;	Delay
;
;	Delay For Cycles 
;
;*****************************************************

Delay_16	phx
		ldx #$830 ; restore to #$00
@AL1	        dex
		bne @AL1
		plx
		rts

Short_Pause     PHX
                PHY
                LDY #$80
@again          LDX #$ff
@delay          CPX #0
                BEQ @continue
                DEX 
                BRA @delay
@continue       CPY #0
                BEQ @finished
                DEY 
                BRA @again
@finished       PLY
                PLX
                RTS

                ;messages/strings
                .align $10, $00
MSG1      .textz "uVGA - Invalid Response "
MSG2      .textz "Hello World!"
MSG3      .textz "Processor 2 is Online!"
MSG4      .textz "SD Card System is Online!"
MSG5      .textz "test_sd.txt"
