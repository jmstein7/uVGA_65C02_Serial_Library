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

;
; uVGA Text and String Commands
; Main Text Commands

;Clear the Screen

uClear_Screen   PHA
                LDA #>F_gfx_Cls ;*simply sends the clear command
                JSR Put_Chr
                LDA #<F_gfx_Cls
                JSR Put_Chr
                JSR getAck
                PLA
                RTS

;move cursor to X/Y Position (Line/Column)
uMove_Cursor    PHA
                LDA #>F_txt_MoveCursor
                JSR Put_Chr
                LDA #<F_txt_MoveCursor
                JSR Put_Chr
                LDA txt_lineH       ;*Target Line
                JSR Put_Chr
                LDA txt_lineL
                JSR Put_Chr
                LDA txt_columnH     ;*Target Column
                JSR Put_Chr
                LDA txt_columnL
                JSR Put_Chr
                JSR getAck
                PLA
                RTS

uPut_Character  PHA
                LDA #>F_putCH   ;*Command
                JSR Put_Chr
                LDA #<F_putCH
                JSR Put_Chr
                LDA txt_charH   ;*Character byte
                JSR Put_Chr
                LDA txt_charL
                JSR Put_Chr
                JSR getAck
                PLA
                RTS

uPut_String     PHA       ;*The Put String command prints a string to the display.
                PHX
                LDX #0
                LDA #>F_putstr
                JSR Put_Chr
                LDA #<F_putstr
                JSR Put_Chr
@next_char      LDA Txt_String1,X   ;*Here, we index a pointer to the
                JSR Put_Chr         ; string. Loads a character at a time.
                CMP #0              ;*String is terminated with a NULL
                BEQ @done
                INX 
                BRA @next_char
@done           JSR getAckResp
                PLX
                PLA
                RTS

;
uChar_Width     PHA     ;*The Character Width command is used to calculate
                        ; the width in pixel units for a character,
                        ; based on the currently selected font. 
                LDA #>F_charwidth
                JSR Put_Chr
                LDA #<F_charwidth
                JSR Put_Chr
                                ;
                PLA             ;*Pull Character value from stack
                                ;
                JSR Put_Chr     ; (The ASCII character for the width calculation) 
                                ; 
                JSR getAckResp  ;*Returns the width in pixels of the character
                                ;
                RTS
;
uChar_Height    PHA     ;*The Character height command is used to calculate
                        ; the height in pixel units for a character,
                        ; based on the currently selected font. 
                LDA #>F_charheight
                JSR Put_Chr
                LDA #<F_charheight
                JSR Put_Chr
                                ;
                PLA             ;*Pull Character value from stack
                                ;
                JSR Put_Chr     ; (The ASCII character for the height calculation) 
                                ; 
                JSR getAckResp  ;*Returns the height in pixels of the character
                                ;
                RTS
;
uTxt_Foreground  PHA                  ;*sets the text foreground colour, and 
                 LDA #>F_txt_FGcolour ; reports back the previous foreground colour
                 JSR Put_Chr
                 LDA #<F_txt_FGcolour
                 JSR Put_Chr
                 LDA uColorH
                 JSR Put_Chr
                 LDA uColorL
                 JSR Put_Chr
                 JSR getAckResp
                 PLA
                 RTS

uTxt_Backround  PHA                   ;*sets the text backround colour, and 
                LDA #>F_txt_BGcolour  ; reports back the previous backround colour
                JSR Put_Chr
                LDA #<F_txt_BGcolour
                JSR Put_Chr
                LDA uColorH
                JSR Put_Chr
                LDA uColorL
                JSR Put_Chr
                JSR getAckResp
                PLA
                RTS

uTxt_Opacity    PHA   ;*selects whether or not the 'background' pixels are drawn
                LDA #>F_txt_Opacity ;*Default mode is OPAQUE with BLACK background
                JSR Put_Chr
                LDA #<F_txt_Opacity
                JSR Put_Chr
                LDA #0
                JSR Put_Chr
                LDA txt_opacity   ;*Mode 1 ON  (Opaque)
                JSR Put_Chr       ;*Mode 0 OFF (Transparent)
                JSR getAckResp
                PLA
                RTS

uSet_Font       PHA       ;*sets the required font using its ID
                LDA #>F_txt_FontID
                JSR Put_Chr
                LDA #<F_txt_FontID
                JSR Put_Chr         ;*0 for FONT1 = System font
                LDA #0              ; 1 for FONT2
                JSR Put_Chr         ; 2 for FONT3 = Default font
                LDA uFont           ;*Font is held in uFont mem location
                JSR Put_Chr
                JSR getAckResp ;*reports back the previous Font ID used
                PLA
                RTS    
                ; 
uText_Width
                PHA     ;*sets the text width multiplier between 1 and 16,
                        ; and returns the previous multiplier.
                        ;
                        ;*Uses the byte in the accumulator as the multiplier value 
                LDA #>F_txt_Width
                JSR Put_Chr
                LDA #<F_txt_Width
                JSR Put_Chr
                ;
                LDA #0          ;*High byte
                JSR Put_Chr     ; 
                PLA             ;*Pull value byte from accumulator (width multiplier)
                AND #%00011111  ; AND with accumulator to mask all but 1st five bits
                JSR Put_Chr     ;*1 to 16 (Default =1)
                                ; 
                JSR getAckResp  ;*Returns Previous Multiplier value.
                                ;*Restore registers
                RTS
                ;
                ; 
uText_Height
                PHA     ;*sets the text Height multiplier between 1 and 16,
                        ; and returns the previous multiplier.
                        ;
                        ;*Uses the byte in the accumulator as the multiplier value 
                LDA #>F_txt_Height
                JSR Put_Chr
                LDA #<F_txt_Height
                JSR Put_Chr
                ;
                LDA #0          ;*High byte
                JSR Put_Chr     ; 
                PLA             ;*Pull value byte from accumulator (height multiplier)
                AND #%00011111  ; AND with accumulator to mask all but 1st five bits
                JSR Put_Chr     ;*1 to 16 (Default =1)
                                ; 
                JSR getAckResp  ;*Returns Previous Multiplier value.
                                ;*Restore registers
                RTS
                ; 
uText_Xgap
                PHA     ;*sets the pixel gap between characters (x-axis),
                        ; where the gap is in pixel units (from 0 to 32)
                        ;
                        ;*Uses the byte in the accumulator as the pixel count value 
                LDA #>F_txt_Xgap
                JSR Put_Chr
                LDA #<F_txt_Xgap
                JSR Put_Chr
                ;
                LDA #0          ;*High byte
                JSR Put_Chr     ; 
                PLA             ;*Pull value byte from accumulator (height multiplier)
                AND #%00111111  ; AND with accumulator to mask all but lower six bits
                JSR Put_Chr     ;*0 to 32 (Default =0)
                                ; 
                JSR getAckResp  ;*Returns Previous pixel count.
                                ;*Restore registers
                RTS
                ;
uText_Ygap
                PHA     ;*sets the pixel gap between characters (y-axis),
                        ; where the gap is in pixel units (from 0 to 32)
                        ;
                        ;*Uses the byte in the accumulator as the pixel count value 
                LDA #>F_txt_Ygap
                JSR Put_Chr
                LDA #<F_txt_Ygap
                JSR Put_Chr
                ;
                LDA #0          ;*High byte
                JSR Put_Chr     ; 
                PLA             ;*Pull value byte from accumulator (height multiplier)
                AND #%00111111  ; AND with accumulator to mask all but lower six bits
                JSR Put_Chr     ;*0 to 32 (Default =0)
                                ; 
                JSR getAckResp  ;*Returns Previous pixel count.
                                ;*Restore registers
                RTS
                ;
uText_Wrap
                PHA     ;*sets the pixel position where text wrap will occur at RHS.
                        ; The value is in pixels. The default value is 0.
                        ;
                        ;*Uses X for the upper byte and Y for the lower byte
                LDA #>F_txt_Wrap
                JSR Put_Chr
                LDA #<F_txt_Wrap
                JSR Put_Chr
                ;
                TXA             ;*uses the value in X for the  
                JSR Put_Chr     ; upper byte 
                TYA             ;*uses the value in Y for the
                JSR Put_Chr     ; lower byte 
                                ;*0 for OFF.
                                ; 1 to N for ON, in Pixels.
                JSR getAckResp  ;*Returns the previous wrap position
                ;
                PLA                ;*Restore registers
                RTS
                ;
/* BOLD/Italic/Inverse/Underlined are all defined, thus:
BOLD                   = $10      ; TEXT_ATTRIBUTES bold text
ITALIC                 = $20      ; TEXT_ATTRIBUTES italic text
INVERSE                = $40      ; TEXT_ATTRIBUTES inverse text
UNDERLINED             = $80      ; TEXT_ATTRIBUTES underlined
*/

uTxt_AttSet             PHA
                        LDA #>F_txt_Attributes
                        JSR Put_Chr
                        LDA #<F_txt_Attributes
                        JSR Put_Chr
                        LDA #0
                        JSR Put_Chr
                        PLA 
                        ORA uTXT_Attributes     ; Set unset bits viz A
                        STA uTXT_Attributes     ; Store to memory
                        JSR Put_Chr             ; Put to device
                        JSR getAckResp
                        RTS

uTxt_AttReset           PHA
                        LDA #>F_txt_Attributes
                        JSR Put_Chr
                        LDA #<F_txt_Attributes
                        JSR Put_Chr
                        LDA #0
                        JSR Put_Chr
                        PLA
                        AND uTXT_Attributes     ; Mask Accumulator with only ON bits
                        EOR uTXT_Attributes     ; Flip ON to OFF
                        STA uTXT_Attributes     ; Store result to memory
                        JSR Put_Chr             ; Put to device
                        JSR getAckResp
                        RTS
/*
;*
; Picaso Graphical Routines
;*
*/
uChange_Color
                PHA     ;*changes all oldColor pixels to newColor
                        ; within the clipping window area.
                        ;
                LDA #>F_gfx_ChangeColour
                JSR Put_Chr
                LDA #<F_gfx_ChangeColour
                JSR Put_Chr
                ;
                LDA uColor2H  ;*Old Color
                JSR Put_Chr   ; to be changed
                LDA uColor2L
                JSR Put_Chr
                ;
                LDA uColorH   ;*New color
                JSR Put_Chr   ; to replace the old
                LDA uColorL
                JSR Put_Chr
                ;
                JSR getAck
                              ;*Restore registers
                PLA
                RTS

uDraw_Circle     PHA            ; hollow circle
                 PHY
                ;
                 LDA #>F_gfx_Circle
                 JSR Put_Chr
                 LDA #<F_gfx_Circle
                 JSR Put_Chr

                 LDY #0
@XYR             LDA uXpointH,Y
                 JSR Put_Chr
                 CPY #5
                 BEQ @next
                 INY 
                 BRA @XYR

@next            LDA uColorH
                 JSR Put_Chr
                 LDA uColorL
                 JSR Put_Chr
                 JSR getAck
                ;
                 PLY
                 PLA
                 RTS

uFilled_Circle   PHA    ; filled circle
                 PHY
                ;
                 LDA #>F_gfx_CircleFilled
                 JSR Put_Chr
                 LDA #<F_gfx_CircleFilled
                 JSR Put_Chr

                 LDY #0
@XYR             LDA uXpointH,Y
                 JSR Put_Chr
                 CPY #5
                 BEQ @next
                 INY 
                 BRA @XYR

@next            LDA uColorH
                 JSR Put_Chr
                 LDA uColorL
                 JSR Put_Chr
                 JSR getAck
                ;
                 PLY
                 PLA
                 RTS

uDraw_Line       PHA    ;*Draw a line from point
                 PHY    ; to point
                ;
                 LDA #>F_gfx_Line
                 JSR Put_Chr
                 LDA #<F_gfx_Line
                 JSR Put_Chr

                 LDY #0                 ;*first X and Y
@XY1             LDA uXpointH,Y         ; coordinates
                 JSR Put_Chr
                 CPY #3
                 BEQ @second
                 INY 
                 BRA @XY1

@second          LDY #0                 ;*second X and Y
@XY2             LDA uX2pointH,Y        ; coordinates
                 JSR Put_Chr
                 CPY #3
                 BEQ @next
                 INY 
                 BRA @XY2

@next            LDA uColorH            ;*set color
                 JSR Put_Chr
                 LDA uColorL
                 JSR Put_Chr
                 JSR getAck
                ;
                 PLY
                 PLA
                 RTS

uDraw_Rectangle  PHA    ;*Draw a Rectangle 
                 PHY    ; to point
                ;
                 LDA #>F_gfx_Rectangle
                 JSR Put_Chr
                 LDA #<F_gfx_Rectangle
                 JSR Put_Chr

                 LDY #0                 ;*top left
@XY1             LDA uXpointH,Y         ; coordinates
                 JSR Put_Chr
                 CPY #3
                 BEQ @second
                 INY 
                 BRA @XY1

@second          LDY #0                 ;*bottom right
@XY2             LDA uX2pointH,Y        ; coordinates
                 JSR Put_Chr
                 CPY #3
                 BEQ @next
                 INY 
                 BRA @XY2

@next            LDA uColorH            ;*set color
                 JSR Put_Chr
                 LDA uColorL
                 JSR Put_Chr
                 JSR getAck
                ;
                 PLY
                 PLA
                 RTS
                 
uFilled_Rectangle  PHA    ;*Draw a Filled Rectangle 
                   PHY    ; to point
                          ;
                 LDA #>F_gfx_RectangleFilled
                 JSR Put_Chr
                 LDA #<F_gfx_RectangleFilled
                 JSR Put_Chr

                 LDY #0                 ;*top left
@XY1             LDA uXpointH,Y         ; coordinates
                 JSR Put_Chr
                 CPY #3
                 BEQ @second
                 INY 
                 BRA @XY1

@second          LDY #0                 ;*bottom right
@XY2             LDA uX2pointH,Y        ; coordinates
                 JSR Put_Chr
                 CPY #3
                 BEQ @next
                 INY 
                 BRA @XY2

@next            LDA uColorH            ;*set color
                 JSR Put_Chr
                 LDA uColorL
                 JSR Put_Chr
                 JSR getAck
                ;
                 PLY
                 PLA
                 RTS

uDraw_Polyline  PHA       ;*plots lines between points specified by 
                PHY       ; a pair of arrays using the specified color.
                PHX
                
                 LDA #>F_gfx_Polyline
                 JSR Put_Chr
                 LDA #<F_gfx_Polyline
                 JSR Put_Chr
                 
                              ; How many Words?
                 LDA #0       ; High Byte is $00
                 JSR Put_Chr 
                 LDX uXcoordinateN
                 DEX
                 LDY uYcoordinateN
                 TYA
                 DEY
                 LSR A
                 JSR Put_Chr  ;*Output Low Byte for N

                 LDX #0               ;*Output X 
                 LDY #0               ;
@XY1             LDA uXcoordinate,X   ; coordinates
                 JSR Put_Chr
                 CPX uXcoordinateNR
                 BEQ @XY2
                 INX 
                 BRA @XY1
     
                                       ;*Output Y
@XY2             LDA uYcoordinate,Y    ; coordinates
                 JSR Put_Chr
                 CPY uYcoordinateNR
                 BEQ @next
                 INY 
                 BRA @XY2

@next            LDA uColorH            ;*set color
                 JSR Put_Chr
                 LDA uColorL
                 JSR Put_Chr
                 JSR getAck
                
                 PLX
                 PLY
                 PLA
                 RTS
                
uDraw_Polygon   PHA       ;*plots lines between points specified by 
                PHY       ; a pair of arrays using the specified color.
                PHX       ; The last point is drawn back to the first point
                          ; completing the polygon.
                          ;
                 LDA #>F_gfx_Polygon
                 JSR Put_Chr
                 LDA #<F_gfx_Polygon
                 JSR Put_Chr
                 
                              ; How many Words?
                 LDA #0       ; High Byte is $00
                 JSR Put_Chr 
                 LDX uXcoordinateN
                 DEX
                 LDY uYcoordinateN
                 TYA
                 DEY
                 LSR A
                 JSR Put_Chr  ;*Output Low Byte for N

                 LDX #0               ;*Output X 
                 LDY #0               ;
@XY1             LDA uXcoordinate,X   ; coordinates
                 JSR Put_Chr
                 CPX uXcoordinateNR
                 BEQ @XY2
                 INX 
                 BRA @XY1
     
                                       ;*Output Y
@XY2             LDA uYcoordinate,Y    ; coordinates
                 JSR Put_Chr
                 CPY uYcoordinateNR
                 BEQ @next
                 INY 
                 BRA @XY2

@next            LDA uColorH            ;*set color
                 JSR Put_Chr
                 LDA uColorL
                 JSR Put_Chr
                 JSR getAck
                
                 PLX
                 PLY
                 PLA
                 RTS

uFilled_Polygon   PHA       ;*draws a solid Polygon between specified vertices 
                PHY         ; using the specified color.
                PHX
                
                 LDA #>F_gfx_PolygonFilled
                 JSR Put_Chr
                 LDA #<F_gfx_PolygonFilled
                 JSR Put_Chr
                 
                              ; How many Words?
                 LDA #0       ; High Byte is $00
                 JSR Put_Chr 
                 LDX uXcoordinateN
                 DEX
                 LDY uYcoordinateN
                 TYA
                 DEY
                 LSR A
                 JSR Put_Chr  ;*Output Low Byte for N

                 LDX #0               ;*Output X 
                 LDY #0               ;
@XY1             LDA uXcoordinate,X   ; coordinates
                 JSR Put_Chr
                 CPX uXcoordinateNR
                 BEQ @XY2
                 INX 
                 BRA @XY1
     
                                       ;*Output Y
@XY2             LDA uYcoordinate,Y    ; coordinates
                 JSR Put_Chr
                 CPY uYcoordinateNR
                 BEQ @next
                 INY 
                 BRA @XY2

@next            LDA uColorH            ;*set color
                 JSR Put_Chr
                 LDA uColorL
                 JSR Put_Chr
                 JSR getAck
                
                 PLX
                 PLY
                 PLA
                 RTS

uDraw_Triangle:  PHA    ;*Draw a Triangle 
                 PHY    ;*three XY vertices
                ;
                 LDA #>F_gfx_Triangle
                 JSR Put_Chr
                 LDA #<F_gfx_Triangle
                 JSR Put_Chr

                 LDY #0                 ;*first
@XYV1            LDA uXpointH,Y         ; vertice
                 JSR Put_Chr
                 CPY #3
                 BEQ @second_third
                 INY 
                 BRA @XYV1

@second_third    LDY #0                 ;*second and 
@XYV23           LDA uX2pointH,Y        ; third vertices
                 JSR Put_Chr
                 CPY #7
                 BEQ @next
                 INY 
                 BRA @XYV23

@next            LDA uColorH            ;*set color
                 JSR Put_Chr
                 LDA uColorL
                 JSR Put_Chr
                 JSR getAck
                ;
                 PLY
                 PLA
                 RTS

uFilled_Triangle: PHA    ;*Draw a filled triangle 
                  PHY    ;*three XY vertices
                ;
                 LDA #>F_gfx_TriangleFilled
                 JSR Put_Chr
                 LDA #<F_gfx_TriangleFilled
                 JSR Put_Chr

                 LDY #0                 ;*first
@XYV1            LDA uXpointH,Y         ; vertice
                 JSR Put_Chr
                 CPY #3
                 BEQ @second_third
                 INY 
                 BRA @XYV1

@second_third    LDY #0                 ;*second and 
@XYV23           LDA uX2pointH,Y        ; third vertices
                 JSR Put_Chr
                 CPY #7
                 BEQ @next
                 INY 
                 BRA @XYV23

@next            LDA uColorH            ;*set color
                 JSR Put_Chr
                 LDA uColorL
                 JSR Put_Chr
                 JSR getAck
                ;
                 PLY
                 PLA
                 RTS

;Calculate_Orbit
uCalculate_Orbit      
                 PHA            ;*calculates the x, y coordinates of
                 PHY            ; a distant point relative to the current origin
                 PHX
                 PHP            ;* Save State
                ;
                ;* The Command
                 LDA #>F_gfx_Orbit
                 JSR Put_Chr
                 LDA #<F_gfx_Orbit
                 JSR Put_Chr
                 ;* Load the angle and the distance
                 ;  from the current origin.
                 LDY #0
@XY1             LDA uAngleH,Y
                 JSR Put_Chr
                 CPY #3
                 BEQ @next
                 INY 
                 BRA @XY1
                 ;
                ;Get Reply from Processor
                ;
@next            JSR getAck2Words    ; Get two Words,         
                                     ; the x, y coordinates
@complete        PLP                 ;* Restore State
                 PLX
                 PLY
                 PLA
                 RTS 

uPut_Pixel       PHA            ; draw one pixel at
                 PHY            ; the XY coordinate
                ;
                 LDA #>F_gfx_PutPixel
                 JSR Put_Chr
                 LDA #<F_gfx_PutPixel
                 JSR Put_Chr

                 LDY #0
@XY1             LDA uXpointH,Y
                 JSR Put_Chr
                 CPY #3
                 BEQ @next
                 INY 
                 BRA @XY1

@next            LDA uColorH
                 JSR Put_Chr
                 LDA uColorL
                 JSR Put_Chr
                 JSR getAck
                ;
                 PLY
                 PLA
                 RTS

uRead_Pixel      PHA            ;*Use to read the color of a
                 PHY            ; pixel at the XY coordinate
                 PHX
                 PHP            ;* Save State
                ;
                ;* The Command
                 LDA #>F_gfx_GetPixel
                 JSR Put_Chr
                 LDA #<F_gfx_GetPixel
                 JSR Put_Chr
                 ;* Load the X and Y coordinates
                 LDY #0
@XY1             LDA uXpointH,Y
                 JSR Put_Chr
                 CPY #3
                 BEQ @next
                 INY 
                 BRA @XY1
                ;
                ;Get Reply from Processor
                ;
@next            JSR getAckResp             
                ;
@complete        PLP            ;* Restore State
                 PLX
                 PLY
                 PLA
                 RTS    
                 ;
uMove_Origin
                PHA     ;*moves the XY origin to a new position
                PHY     ; for graphics and text
                        ;
                LDA #>F_gfx_MoveTo
                JSR Put_Chr
                LDA #<F_gfx_MoveTo
                JSR Put_Chr
                ;
                LDY #0                 ;*coordinates of the 
@XY1            LDA uXpointH,Y         ; new origin point
                JSR Put_Chr            ;*Load uXpoint and uYpoint
                CPY #3
                BEQ @second
                INY 
                BRA @XY1
@second
                JSR getAck
                ;
                PLY              ;*Restore registers
                PLA
                RTS
;
uDraw_Move
                PHA     ;*Specifies the horizontal and vertical position of
                PHY     ; the line end as well as the new origin.
                        ; AKA Draw Line & Move Origin
                LDA #>F_gfx_LineTo
                JSR Put_Chr
                LDA #<F_gfx_LineTo
                JSR Put_Chr
                ;
                LDY #0                 ;*coordinates of the 
@XY1            LDA uXpointH,Y         ; new point of origin
                JSR Put_Chr            ;*Load uXpoint and uYpoint
                CPY #3
                BEQ @second
                INY 
                BRA @XY1
@second
                JSR getAck
                              ;*Restore registers
                PLY
                PLA
                RTS
                ;
uClipping
                PHA     ;*Push accumulator value (on/off) to stack
                        ;*Enables or Disables the ability for Clipping to be used.
                        ; for Clipping to be used.
                        ;*Uses the byte in the accumulator for the value (on/off)
                LDA #>F_gfx_Clipping
                JSR Put_Chr
                LDA #<F_gfx_Clipping
                JSR Put_Chr
                ;
                LDA #0          ;*High byte
                JSR Put_Chr     ; 
                PLA             ;*Pull value byte from accumulator
                AND #%00000001  ; AND with accumulator to mask all but 1st bit
                JSR Put_Chr     ; 0 = DISABLE CLIPPING
                                ; 1 = ENABLE CLIPPING
                JSR getAck
                                ;*Restore registers
                RTS
                ;
uClip_Window    PHA     ;*Specifies the horizontal and vertical position of
                PHY     ; the top left corner of the clipping window.
                        ; 
                LDA #>F_gfx_ClipWindow
                JSR Put_Chr
                LDA #<F_gfx_ClipWindow
                JSR Put_Chr
                LDY #0                 ;*coordinates of the top left corner 
@XY1            LDA uXpointH,Y         ; of the clipping window
                JSR Put_Chr            ;*Load uXpoint and uYpoint
                CPY #3
                BEQ @second
                INY 
                BRA @XY1
@second         LDY #0                 ;*coordinates of the bottom right corner
@XY2            LDA uX2pointH,Y        ; of the clipping window
                JSR Put_Chr            ;*Load uX2point and uY2point
                CPY #3
                BEQ @next
                INY 
                BRA @XY2
@next           JSR getAck
                                       ;*Restore registers
                PLY
                PLA
                RTS
                ;
uExtend_Clip    PHA ; Extend Clip Region
                LDA #>F_gfx_SetClipRegion
                JSR Put_Chr
                LDA #<F_gfx_SetClipRegion
                JSR Put_Chr
                JSR getAck
                PLA
                RTS
                ;
                ;Ellipse Routines
                ;
;* Draw Ellipse
uDraw_Ellipse:   PHA    ;*Draw a Ellipse
                 PHY    ;
                ;
                 LDA #>F_gfx_Ellipse
                 JSR Put_Chr
                 LDA #<F_gfx_Ellipse
                 JSR Put_Chr

                 LDY #0                 ;*X and Y
@XYV1            LDA uXpointH,Y         ; Center point
                 JSR Put_Chr
                 CPY #3
                 BEQ @second_third
                 INY 
                 BRA @XYV1

@second_third    LDY #0                 ;*Xrad and 
@XYV23           LDA uXRadiusH,Y        ; Yrad vertices
                 JSR Put_Chr
                 CPY #3
                 BEQ @next
                 INY 
                 BRA @XYV23

@next            LDA uColorH            ;*set color
                 JSR Put_Chr
                 LDA uColorL
                 JSR Put_Chr
                 JSR getAck
                ;
                 PLY
                 PLA
                 RTS
;* Now, Fill Ellipse
uFill_Ellipse:   PHA    ;*Draw a Filled Ellipse
                 PHY    ;
                ;
                 LDA #>F_gfx_EllipseFilled
                 JSR Put_Chr
                 LDA #<F_gfx_EllipseFilled
                 JSR Put_Chr

                 LDY #0                 ;*X and Y
@XYV1            LDA uXpointH,Y         ; Center point
                 JSR Put_Chr
                 CPY #3
                 BEQ @second_third
                 INY 
                 BRA @XYV1

@second_third    LDY #0                 ;*Xrad and 
@XYV23           LDA uXRadiusH,Y        ; Yrad vertices
                 JSR Put_Chr
                 CPY #3
                 BEQ @next
                 INY 
                 BRA @XYV23

@next            LDA uColorH            ;*set color
                 JSR Put_Chr
                 LDA uColorL
                 JSR Put_Chr
                 JSR getAck
                ;
                 PLY
                 PLA
                 RTS
                ;
uDraw_Button    PHA     ;*Draw Button command draws a
                PHY     ; 3 dimensional Text Button
                PHX     ; Accumulator used for button state (on/off)
                        ; 
                LDA #>F_gfx_Button
                JSR Put_Chr
                LDA #<F_gfx_Button
                JSR Put_Chr
                                ;
                LDA #0          ;*High byte
                JSR Put_Chr     ; 
                PLA             ;*Pull STATE value from accumulator
                AND #%00000001  ;*AND accumulator to mask all but 1st bit
                JSR Put_Chr     ; 0 = BUTTON PRESSED DOWN
                                ; 1 = BUTTON UP
                LDY #0                 ;*coordinates of the top left corner 
@XY1            LDA uXpointH,Y         ; of the button on the screen
                JSR Put_Chr            ;*Load uXpoint and uYpoint
                CPY #3
                BEQ @second
                INY 
                BRA @XY1
                ;
@second         LDA uColorH  ;*Sets the button color
                JSR Put_Chr  ; (uColor)
                LDA uColorL
                JSR Put_Chr
                ;
                LDA uColor2H  ;*Sets the text color
                JSR Put_Chr   ; (uColor2)
                LDA uColor2L
                JSR Put_Chr
                ;
                LDA #0        ;*Sets the FONT ID to use
                JSR Put_Chr   ; 0 for FONT1 = System font
                LDA uFont     ; 1 for FONT2
                JSR Put_Chr   ; 2 for FONT3 = Default font
                ;
                LDY #0                 ;*Setting the text width and 
@XY2            LDA txt_WidthH,Y       ; height
                JSR Put_Chr            ;*Load txt_Width and txt_Height
                CPY #3
                BEQ @next
                INY 
                BRA @XY2
                ;
@next           LDX #0
@next_char      LDA Txt_String1,X
                JSR Put_Chr
                CMP #0
                BEQ @done
                INX 
                BRA @next_char
                ;
@done           JSR getAck
                ;*Restore registers
                PLX
                PLY
                RTS
                ;
uDraw_Panel     PHA     ;*Draw Panel command draws a
                PHY     ; 3 dimensional Text Panel
                        ; accumulator used for state (recessed/raised)
                        ; 
                LDA #>F_gfx_Panel
                JSR Put_Chr
                LDA #<F_gfx_Panel
                JSR Put_Chr
                                ;
                LDA #0          ;*Null high byte
                JSR Put_Chr     ; 
                PLA             ;*Pull STATE value from stack
                AND #%00000001  ;*AND accumulator to mask all but 1st bit
                JSR Put_Chr     ; 0 = Panel recessed.
                                ; 1 = Panel raised
                LDY #0                 ;*X and Y coordinates of the top left corner 
@XY1            LDA uXpointH,Y         ; of the panel on the screen
                JSR Put_Chr            ;*Load uXpoint and uYpoint
                CPY #3
                BEQ @second
                INY 
                BRA @XY1
                ;
@second         LDY #0                 ;*Setting the text width and 
@XY2            LDA txt_WidthH,Y       ; height
                JSR Put_Chr            ;*Load txt_Width and txt_Height
                CPY #3
                BEQ @next
                INY 
                BRA @XY2
@next           ;
                LDA uColorH  ;*Sets the panel color
                JSR Put_Chr  ; (uColor)
                LDA uColorL
                JSR Put_Chr
                ;
                JSR getAck
                ;*Restore registers
                PLY
                RTS
                ;
uDraw_Slider    PHA     ;*Draw Slider command draws a
                PHY     ; 3 dimensional slider
                        ;*accumulator used for state (indented/raised/hidden)
                        ;*X register sets initial slider value
                LDA #>F_gfx_Slider
                JSR Put_Chr
                LDA #<F_gfx_Slider
                JSR Put_Chr
                                ;
                LDA #0          ;*Null high byte
                JSR Put_Chr     ; 
                PLA             ;*Pull STATE value from stack
                AND #%00000011  ;*AND accumulator to mask all but 1st two bits
                JSR Put_Chr     ; 0 = Slider 
                                ; 1 = Slider raised
                                ; 2 - Slider Hidden
                LDY #0                 ;*coordinates of the top left corner 
@XY1            LDA uXpointH,Y         ; of the slider on the screen
                JSR Put_Chr            ;*Load uXpoint and uYpoint
                CPY #3
                BEQ @second
                INY 
                BRA @XY1
                ;
@second         LDY #0                 ;*Setting bottom corner
@XY2            LDA uX2pointH,Y        ; position of the slider
                JSR Put_Chr            ;*(uX2pointH)
                CPY #3
                BEQ @next
                INY 
                BRA @XY2
@next           ;
                LDA uColorH  ;*Sets the slider color
                JSR Put_Chr  ; (uColor)
                LDA uColorL
                JSR Put_Chr
                ;
                LDY #0               ;*sets the full scale range of 
@XYS3           LDA uScaleH,Y        ; the slider for the thumb from 0 to n.
                JSR Put_Chr          ;*(uScale)
                CPY #1
                BEQ @next_one
                INY 
                BRA @XYS3
                             ;
@next_one
                LDA #0       ;*Set the initial value
                JSR Put_Chr  ; the slider is set to
                TXA          ;*X register value is used for the 
                JSR Put_Chr  ; initial setting (if above zero)
                             ;
                JSR getAck
                             ;*Restore registers
                PLY
                RTS
                ;
                ;
uCopy_Paste     PHA     ;*Screen Copy Paste command copies an area of a screen from a 
                PHY     ; size given by width and height parameters and pastes it to
                        ; and pastes it to another location
                        ; 
                LDA #>F_gfx_ScreenCopyPaste
                JSR Put_Chr
                LDA #<F_gfx_ScreenCopyPaste
                JSR Put_Chr
                        ;
                LDY #0                 ;*coordinates of the top left corner 
@XY1            LDA uXpointH,Y         ; of the area to be copied
                JSR Put_Chr            ;*uXpoint and uYpoint
                CPY #3
                BEQ @second
                INY 
                BRA @XY1
                ;
@second         LDY #0                 ;*coordinates of the top left corner
@XY2            LDA uX2pointH,Y        ; where the paste will be made
                JSR Put_Chr            ;*(uX2point and uY2point)
                CPY #3
                BEQ @next
                INY 
                BRA @XY2
@next           ;
                LDY #0                 ;*Setting the width and the height 
@WH1            LDA txt_WidthH,Y       ; of the copied/pasted area
                JSR Put_Chr            ;*reuses txt_Width and txt_Height
                CPY #3                 ; ZP/DP vars
                BEQ @next2
                INY 
                BRA @WH1
@next2
                JSR getAck
                                       ;*Restore registers
                PLY
                PLA
                RTS
                ;
                ;
uBevel_Shadow   PHA     ;*Bevel Shadow command changes the graphics
                        ; “Draw Button” commands bevel shadow depth
                        ;*accumulator used for bevel depth value 
                LDA #>F_gfx_BevelShadow
                JSR Put_Chr
                LDA #<F_gfx_BevelShadow
                JSR Put_Chr
                                ;
                LDA #0          ;*Null high byte
                JSR Put_Chr     ; 
                PLA             ;*Pull STATE value from stack
                AND #%00000111  ;*AND accumulator to mask all but 1st three bits
                JSR Put_Chr     ; 0 = No Bevel Shadow 
                                ; 1-4 = Number of Pixels Deep (Default = 3)
                JSR getAckResp  ;*Returns Previous Bevel Shadow status.
                                ;*Restore registers
                RTS
;
uBevel_Width    PHA     ;*Bevel Width command changes the graphics
                        ; “Draw Button” commands bevel width
                        ;*accumulator used for bevel width value 
                LDA #>F_gfx_BevelWidth
                JSR Put_Chr
                LDA #<F_gfx_BevelWidth
                JSR Put_Chr
                                ;
                LDA #0          ;*Null high byte
                JSR Put_Chr     ; 
                PLA             ;*Pull STATE value from stack
                AND #%00001111  ;*AND accumulator to mask all but 1st four bits
                JSR Put_Chr     ; 0 = No Bevel 
                                ; 1-15 = Number of Pixels Wide (Default = 2)
                JSR getAckResp  ;*Returns Previous Bevel width.
                                ;*Restore registers
                RTS
;
                ;*Set Background Color
uBackground_Colour  
                PHA
                LDA #>F_gfx_BGcolour
                JSR Put_Chr
                LDA #<F_gfx_BGcolour
                JSR Put_Chr
                LDA uColorH
                JSR Put_Chr
                LDA uColorL
                JSR Put_Chr
                JSR getAckResp
                PLA
                RTS
;
                ;*Sets the outline colour for rectangles and circles.
uOutline_Color  
                PHA
                LDA #>F_gfx_OutlineColour
                JSR Put_Chr
                LDA #<F_gfx_OutlineColour
                JSR Put_Chr
                ;
                LDA uColorH
                JSR Put_Chr
                LDA uColorL
                JSR Put_Chr
                JSR getAckResp  ;*response is the Previous 
                PLA             ; Outline Colour.
                RTS
;
uFrame_Delay        ;*sets the inter frame delay for  
                PHA ;  the “Media Video” command
                LDA #>F_gfx_FrameDelay
                JSR Put_Chr
                LDA #<F_gfx_FrameDelay
                JSR Put_Chr
                ;
                LDA uMsecH
                JSR Put_Chr
                LDA uMsecL
                JSR Put_Chr
                JSR getAckResp  ;*response is the Previous 
                PLA             ; frame delay, in MS.
                RTS
;
uLine_Pattern                   ;*sets the line draw pattern for line drawing.   
                PHA             ; if set to zero, the lines are solid
                LDA #>F_gfx_LinePattern
                JSR Put_Chr
                LDA #<F_gfx_LinePattern
                JSR Put_Chr
                TXA             ;*uses the value in X for the  
                JSR Put_Chr     ; upper byte
                TYA             ;*uses the value in Y for the
                JSR Put_Chr     ; lower byte
                JSR getAckResp  ;*response is the Previous 
                PLA             ; frame delay, in MS.
                RTS
;
uScreen_Mode    PHA     ;*alters the graphics orientation between
                        ; LANDSCAPE, LANDSCAPE_Rev, PORTRAIT, PORTRAIT_Rev
                        ;*accumulator used for mode value
                LDA #>F_gfx_ScreenMode
                JSR Put_Chr
                LDA #<F_gfx_ScreenMode
                JSR Put_Chr
                                ;
                LDA #0          ;*Null high byte
                JSR Put_Chr     ; 
                PLA             ;*Pull MODE value off the stack
                AND #%00000011  ;*AND accumulator to mask all but 1st two bits
                JSR Put_Chr     ; 0 = LANDSCAPE, 1 = LANDSCAPE REVERSE 
                                ; 2 = PORTRAIT, 3 = PORTRAIT REVERSE
                JSR getAckResp  ;*Returns Previous screen mode.
                                ;*Restore registers
                RTS
;
uTransparency   PHA     ;*The Transparency command turns
                        ; the transparency ON or OFF (0/1).
                        ;*accumulator used for mode value
                LDA #>F_gfx_Transparency
                JSR Put_Chr
                LDA #<F_gfx_Transparency
                JSR Put_Chr
                                ;
                LDA #0          ;*Null high byte
                JSR Put_Chr     ; 
                PLA             ;*Pull MODE value off the stack
                AND #%00000001  ;*AND accumulator to mask all but 1st bit
                JSR Put_Chr     ; 0 = Transparency OFF 
                                ; 1 = Transparency ON
                JSR getAckResp  ;*Returns Previous Transparency value.
                                ;*Restore registers
                RTS
;
uTransparent_Color              ;*The Transparent Color command alters the   
                PHA             ; color that needs to be made transparent.
                LDA #>F_gfx_TransparentColour
                JSR Put_Chr
                LDA #<F_gfx_TransparentColour
                JSR Put_Chr
                TXA             ;*uses the value in X for the  
                JSR Put_Chr     ; upper byte of the color
                TYA             ;*uses the value in Y for the
                JSR Put_Chr     ; lower byte of the color
                JSR getAckResp  ;*response is the Previous 
                PLA             ; Transparent Color
                RTS
;
uSet_Graphics                   ;*Sets the Graphics Parameters
                                ;
                PHA             ;*Push A (function value) to the stack 
                LDA #>F_gfx_Set
                JSR Put_Chr
                LDA #<F_gfx_Set
                JSR Put_Chr
                LDA #0          ;*Null high byte
                JSR Put_Chr     ; 
                PLA             ;*Pull A (function) value off the stack (load)
                JSR Put_Chr     ;*Function = 18 Object Color, Function = 32 Screen Resolution
                                ; Function = 33 Page Display, Function = 34 Page Read, and
                                ; Function = 35 Page Write
                TXA             ;*uses the value in X for the  
                JSR Put_Chr     ; upper byte 
                TYA             ;*uses the value in Y for the
                JSR Put_Chr     ; lower byte 
                JSR getAck      ; 
                                ;*Screen Resolution:  0 for 320x240, 1 for 640 x 480, and
                RTS             ;                     2 for 800 x 480
                                ;*Pages are 0-4 for 320x240, e.g.
                                ;*Color is $0-$FFFF
;
;
uGet_Graphics                   ;*Retrieves various graphics parameters
                                ;
                PHA             ;*Push A (MODE) to the stack 
                LDA #>F_gfx_Get
                JSR Put_Chr
                LDA #<F_gfx_Get
                JSR Put_Chr
                LDA #0          ;*Send the null high byte
                JSR Put_Chr     ; 
                PLA             ;*Pull A (MODE) value off the stack (and load A)
                AND #%00000111  ; AND the accumulator to mask all but 1st three bits
                JSR Put_Chr     /*
                                mode = 0 : X_MAX returns Horizontal Resolution - 1
                                mode = 1 : Y_MAX returns Vertical Resolution - 1 
                                mode = 2 : Returns the left location of the last drawn object
                                mode = 3 : Returns the top location of the last drawn object
                                mode = 4 : Returns the right location of the last drawn object
                                mode = 5 : Returns the bottom location of the last drawn object
                                */
                JSR getAckResp  ;*returns the various graphics parameters
                                ;
                RTS             ; 
;
;********************
; Memory Operations *
;********************
;
uPeekM:      
                 PHA            ;*Use to read a
                 PHY            ; Location in Memory
                ;
                ;* The Command
                 LDA #>F_peekM
                 JSR Put_Chr
                 LDA #<F_peekM
                 JSR Put_Chr
                 ;* Load the memory address to peek
                 LDY #0
@XY1             LDA uMemAddressH,Y
                 JSR Put_Chr
                 CPY #1
                 BEQ @next
                 INY 
                 BRA @XY1
                 ;
                ;Get Reply from Processor
                ;
@next            JSR getAckResp    ;*Get memory value and       
                ;                  ; write to buffer
@complete        PLY                 ;*Restore
                 PLA
                 RTS 
uPokeM:      
                 PHA            ;*Use to write to a
                 PHY            ; Location in Memory
                ;
                ;* The Command
                 LDA #>F_pokeM
                 JSR Put_Chr
                 LDA #<F_pokeM
                 JSR Put_Chr
                 ;*Load the memory address to poke
                 ; and the value to poke to the address
                 LDY #0
@XY1             LDA uMemAddressH,Y
                 JSR Put_Chr
                 CPY #3
                 BEQ @next
                 INY 
                 BRA @XY1
                 ;
                ;Get Reply from Processor
                ;
@next            JSR getAck    ;*Get Ack       
                ;              
@complete        PLY           ;*Restore Registers
                 PLA
                 RTS 
;
; Intrinsic Picaso uVGA routines
;

getAck:         PHA
@not_yet        LDA uVGA_Status
                AND #%10000000
                CMP #%10000000
                BNE @not_yet
                LDA uVGA_Data  
                STA uVGA_ACK
                CMP #$15
                BNE @okay
                JSR InvalidResponse
@okay           PLA
                RTS
;
getAckResp:     PHA     ; store
                PHX     ; A
@not_yet        LDA uVGA_Status
                AND #%10000000
                CMP #%10000000
                BNE @not_yet
                LDA uVGA_Data
                STA uVGA_ACK
                CMP #$15
                BEQ @invalid
                LDX #1
@response       LDA uVGA_Status
                AND #%10000000
                CMP #$80
                BNE @response
                LDA uVGA_Data
                JSR Incwritb
                CPX #0
                BEQ @okay
                DEX 
                BRA @response
@invalid        JSR InvalidResponse
@okay           PLX
                PLA     ; restore
                RTS
;
getAck2Words:   PHA     ; store
                PHX     ; A
@not_yet        LDA uVGA_Status
                AND #%10000000
                CMP #%10000000
                BNE @not_yet
                LDA uVGA_Data
                STA uVGA_ACK
                CMP #$15
                BEQ @invalid
                LDX #3
@response       LDA uVGA_Status
                AND #%10000000
                CMP #$80
                BNE @response
                LDA uVGA_Data
                JSR Incwritb
                CPX #0
                BEQ @okay
                DEX 
                BRA @response
@invalid        JSR InvalidResponse
@okay           PLX
                PLA     ; restore
                RTS
;
getAckRes2Words:        PHA     ; store
                PHX     ; A
@not_yet        LDA uVGA_Status
                AND #%10000000
                CMP #%10000000
                BNE @not_yet
                LDA uVGA_Data
                STA uVGA_ACK
                CMP #$15
                BEQ @invalid
                LDX #5
@response       LDA uVGA_Status
                AND #%10000000
                CMP #$80
                BNE @response
                LDA uVGA_Data
                JSR Incwritb
                CPX #0
                BEQ @okay
                DEX 
                BRA @response
@invalid        JSR InvalidResponse
@okay           PLX
                PLA     ; restore
                RTS

InvalidResponse: PHA
                 PHX
                 PHY
                 LDA #<MSG1
                 STA MSGL
                 LDA #>MSG1
		 STA MSGH
                 JSR SHWMSG      ;* Show message
                 JSR NEW_LINE    ;* New line.
                 PLY
                 PLX
                 PLA
                 RTS
;
; input chr from uVGA (no waiting)
;
;					;
GetByte		PHX
                PHY
                LDY #0
@again          LDX #$88
@delay          CPX #0
                BEQ @continue
                DEX 
                BRA @delay
@continue       CPY #0
                BEQ @finished
                DEY 
                BRA @again
@finished       LDA uVGA_Data	        ; get chr from serial port, don't wait 			; if loop times out, CLC, else SEC and return
                PLY
                PLX
                rts			; with character in "A"
;
; output to OutPut Port
;

Put_Chr	   	PHX
                LDX #$88
@delay          CPX #0
                BEQ @continue
                DEX 
                BRA @delay
@continue       STA uVGA_Data       ; put character to Port
                PLX
               	RTS                 ; done

uCopy_String    PHY ;*save Y
                PHA
                LDY #0
@PRINT          LDA (MSGL),Y
                STA Txt_String1,Y
                CMP #$00
                BEQ @DONEX
                INY 
                BRA @PRINT
@DONEX          PLA
                PLY ;*restore y
                RTS