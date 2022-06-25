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

uVGA_ACK	    = $7C
txt_lineL       = $88
txt_lineH       = $89
txt_columnL     = $8A
txt_columnH     = $8B
txt_charL       = $8C
txt_charH       = $8D
uColorH         = $8E
uColorL         = $8F
uFont           = $90
uTXT_Attributes = $91
uXpointH	    = $92
uXpointL	    = $93
uYpointH	    = $94
uYpointL	    = $95
uRadiusH	    = $96
uRadiusL        = $97
uX2pointH	    = $98
uX2pointL	    = $99
uY2pointH	    = $9A
uY2pointL	    = $9B
uX3pointH	    = $9C
uX3pointL	    = $9D
uY3pointH	    = $9E
uY3pointL	    = $9F
uAngleH	    = $A0
uAngleL	    = $A1
uDistanceH      = $A2
uDistanceL	    = $A3
uXRadiusH	    = $A4
uXRadiusL       = $A5
uYRadiusH	    = $A6
uYRadiusL       = $A7
uMemAddressH    = $A8
uMemAddressL    = $A9
uWordValueH     = $AA
uWordValueL     = $AB
txt_opacity	    = $AC
uColor2H	    = $AD
uColor2L	    = $AE
txt_WidthH      = $AF
txt_WidthL      = $B0
txt_HeightH     = $B1
txt_HeightL     = $B2
uScaleH	    = $B3
uScaleL         = $B4
uMsecH	    = $B5
uMsecL	    = $B6

;
;   The 16 bit RGB (565) Color Chart
;   uVGA Colors is
;   Based Upon Original 
;   Nomenclature by 4D Forum Member: skadoo
;

ALICEBLUE               = $F7DF
ANTIQUEWHITE            = $FF5A
AQUA                    = $07FF
AQUAMARINE              = $7FFA
AZURE                   = $F7FF
BEIGE                   = $F7BB
BISQUE                  = $FF38
BLACK                   = $0000
BLANCHEDALMOND          = $FF59
BLUE                    = $001F
BLUEVIOLET              = $895C
BROWN                   = $A145
BURLYWOOD               = $DDD0
CADETBLUE               = $5CF4
CHARTREUSE              = $7FE0
CHOCOLATE               = $D343
CORAL                   = $FBEA
CORNFLOWERBLUE          = $64BD
CORNSILK                = $FFDB
CRIMSON                 = $D8A7
CYAN                    = $07FF
DARKBLUE                = $0011
DARKCYAN                = $0451
DARKGOLDENROD           = $BC21
DARKGRAY                = $AD55
DARKGREEN               = $0320
DARKKHAKI               = $BDAD
DARKMAGENTA             = $8811
DARKOLIVEGREEN          = $5345
DARKORANGE              = $FC60
DARKORCHID              = $9999
DARKRED                 = $8800
DARKSALMON              = $ECAF
DARKSEAGREEN            = $8DF1
DARKSLATEBLUE           = $49F1
DARKSLATEGRAY           = $2A69
DARKTURQUOISE           = $067A
DARKVIOLET              = $901A
DEEPPINK                = $F8B2
DEEPSKYBLUE             = $05FF
DIMGRAY                 = $6B4D
DODGERBLUE              = $1C9F
FIREBRICK               = $B104
FLORALWHITE             = $FFDE
FORESTGREEN             = $2444
FUCHSIA                 = $F81F
GAINSBORO               = $DEFB
GHOSTWHITE              = $FFDF
GOLD                    = $FEA0
GOLDENROD               = $DD24
GRAY                    = $8410
GREEN                   = $0400
GREENYELLOW             = $AFE5
HONEYDEW                = $F7FE
HOTPINK                 = $FB56
INDIANRED               = $CAEB
INDIGO                  = $4810
IVORY                   = $FFFE
KHAKI                   = $F731
LAVENDER                = $E73F
LAVENDERBLUSH           = $FF9E
LAWNGREEN               = $7FE0
LEMONCHIFFON            = $FFD9
LIGHTBLUE               = $AEDC
LIGHTCORAL              = $F410
LIGHTCYAN               = $E7FF
LIGHTGOLD               = $FFDA
LIGHTGREEN              = $9772
LIGHTGREY               = $D69A
LIGHTPINK               = $FDB8
LIGHTSALMON             = $FD0F
LIGHTSEAGREEN           = $2595
LIGHTSKYBLUE            = $867F
LIGHTSLATEGRAY          = $7453
LIGHTSTEELBLUE          = $B63B
LIGHTYELLOW             = $FFFC
LIME                    = $07E0
LIMEGREEN               = $3666
LINEN                   = $FF9C
MAGENTA                 = $F81F
MAROON                  = $8000
MEDIUMAQUAMARINE        = $6675
MEDIUMBLUE              = $0019
MEDIUMORCHID            = $BABA
MEDIUMPURPLE            = $939B
MEDIUMSEAGREEN          = $3D8E
MEDIUMSLATEBLUE         = $7B5D
MEDIUMSPRINGGREEN       = $07D3
MEDIUMTURQUOISE         = $4E99
MEDIUMVIOLETRED         = $C0B0
MIDNIGHTBLUE            = $18CE
MINTCREAM               = $F7FF
MISTYROSE               = $FF3C
MOCCASIN                = $FF36
NAVAJOWHITE             = $FEF5
NAVY                    = $0010
OLDLACE                 = $FFBC
OLIVE                   = $8400
OLIVEDRAB               = $6C64
ORANGE                  = $FD20
ORANGERED               = $FA20
ORCHID                  = $DB9A
PALEGOLDENROD           = $EF55
PALEGREEN               = $9FD3
PALETURQUOISE           = $AF7D
PALEVIOLETRED           = $DB92
PAPAYAWHIP              = $FF7A
PEACHPUFF               = $FED7
PERU                    = $CC27
PINK                    = $FE19
PLUM                    = $DD1B
POWDERBLUE              = $B71C
PURPLE                  = $8010
RED                     = $F800
ROSYBROWN               = $BC71
ROYALBLUE               = $435C
SADDLEBROWN             = $8A22
SALMON                  = $FC0E
SANDYBROWN              = $F52C
SEAGREEN                = $2C4A
SEASHELL                = $FFBD
SIENNA                  = $A285
SILVER                  = $C618
SKYBLUE                 = $867D
SLATEBLUE               = $6AD9
SLATEGRAY               = $7412
SNOW                    = $FFDF
SPRINGGREEN             = $07EF
STEELBLUE               = $4416
TAN                     = $D5B1
TEAL                    = $0410
THISTLE                 = $DDFB
TOMATO                  = $FB08
TURQUOISE               = $471A
VIOLET                  = $EC1D
WHEAT                   = $F6F6
WHITE                   = $FFFF
WHITESMOKE              = $F7BE
YELLOW                  = $FFE0
YELLOWGREEN             = $9E66

;
; Serial 4D Constants
; SPE Version 1.1 
;
F_bus_In = $FFD3
F_bus_Out = $FFD2
F_bus_Read = $FFCF
F_bus_Set = $FFD1
F_bus_Write = $FFD0
F_charheight = $001D
F_charwidth = $001E
F_file_Close = $FF18
F_file_Count = $0001
F_file_Dir = $0002
F_file_Erase = $0003
F_file_Error = $FF1F
F_file_Exec = $0004
F_file_Exists = $0005
F_file_FindFirst = $0006
F_file_FindNext = $FF1B
F_file_GetC = $FF0E
F_file_GetS = $0007
F_file_GetW = $FF0C
F_file_Image = $FF11
F_file_Index = $FF15
F_file_LoadFunction = $0008
F_file_LoadImageControl = $0009
F_file_Mount = $FF03
F_file_Open = $000A
F_file_PlayWAV = $000B
F_file_PutC = $001F
F_file_PutS = $0020
F_file_PutW = $FF0D
F_file_Read = $000C
F_file_Rewind = $FF08
F_file_Run = $000D
F_file_ScreenCapture = $FF10
F_file_Seek = $FF16
F_file_Size = $000E
F_file_Tell = $000F
F_file_Unmount = $FF02
F_file_Write = $0010
F_gfx_BevelShadow = $FF98
F_gfx_BevelWidth = $FF99
F_gfx_BGcolour = $FFA4
F_gfx_Button = $0011
F_gfx_ChangeColour = $FFB4
F_gfx_Circle = $FFC3
F_gfx_CircleFilled = $FFC2
F_gfx_Clipping = $FFA2
F_gfx_ClipWindow = $FFB5
F_gfx_Cls = $FFCD
F_gfx_Contrast = $FF9C
F_gfx_Ellipse = $FFB2
F_gfx_EllipseFilled = $FFB1
F_gfx_FrameDelay = $FF9F
F_gfx_Get = $FFA6
F_gfx_GetPixel = $FFC0
F_gfx_Line = $FFC8
F_gfx_LinePattern = $FF9B
F_gfx_LineTo = $FFCA
F_gfx_MoveTo = $FFCC
F_gfx_Orbit = $0012
F_gfx_OutlineColour = $FF9D
F_gfx_Panel = $FFAF
F_gfx_PenSize = $FFA5
F_gfx_Polygon = $0013
F_gfx_PolygonFilled = $0014
F_gfx_Polyline = $0015
F_gfx_PutPixel = $FFC1
F_gfx_Rectangle = $FFC5
F_gfx_RectangleFilled = $FFC4
F_gfx_ScreenCopyPaste = $FFAD
F_gfx_ScreenMode = $FF9E
F_gfx_Set = $FFCE
F_gfx_SetClipRegion = $FFB3
F_gfx_Slider = $FFAE
F_gfx_Transparency = $FFA0
F_gfx_TransparentColour = $FFA1
F_gfx_Triangle = $FFBF
F_gfx_TriangleFilled = $FFA9
F_img_ClearAttributes = $FF45
F_img_Darken = $FF4B
F_img_Disable = $FF4C
F_img_Enable = $FF4D
F_img_GetWord = $FF48
F_img_Lighten = $FF4A
F_img_SetAttributes = $FF46
F_img_SetPosition = $FF4E
F_img_SetWord = $FF49
F_img_Show = $FF47
F_img_Touched = $FF44
F_media_Flush = $FF8A
F_media_Image = $FF8B
F_media_Init = $FF89
F_media_RdSector = $0016
F_media_ReadByte = $FF8F
F_media_ReadWord = $FF8E
F_media_SetAdd = $FF93
F_media_SetSector = $FF92
F_media_Video = $FF95
F_media_VideoFrame = $FF94
F_media_WriteByte = $FF8D
F_media_WriteWord = $FF8C
F_media_WrSector = $0017
F_mem_Free = $FF24
F_mem_Heap = $FF23
F_peekM = $0027
F_pin_HI = $FFD6
F_pin_LO = $FFD5
F_pin_Read = $FFD4
F_pin_Set = $FFD7
F_pokeM = $0028
F_putCH = $FFFE
F_putstr = $0018
F_snd_BufSize = $FEFE
F_snd_Continue = $FEFB
F_snd_Pause = $FEFC
F_snd_Pitch = $FEFF
F_snd_Playing = $FEFA
F_snd_Stop = $FEFD
F_snd_Volume = $FF00
F_sys_Sleep = $FF3B
F_touch_DetectRegion = $FF39
F_touch_Get = $FF37
F_touch_Set = $FF38
F_txt_Attributes = $FFDA
F_txt_BGcolour = $FFE6
F_txt_Bold = $FFDE
F_txt_FGcolour = $FFE7
F_txt_FontID = $FFE5
F_txt_Height = $FFE3
F_txt_Inverse = $FFDC
F_txt_Italic = $FFDD
F_txt_MoveCursor = $FFE9
F_txt_Opacity = $FFDF
F_txt_Set = $FFE8
F_txt_Underline = $FFDB
F_txt_Width = $FFE4
F_txt_Wrap = $FFD9
F_txt_Xgap = $FFE2
F_txt_Ygap = $FFE1
F_file_CallFunction = $0019
F_sys_GetModel = $001A
F_sys_GetVersion = $001B
F_sys_GetPmmC = $001C
F_writeString = $0021
F_readString = $0022
F_blitComtoDisplay = $0023
F_file_FindFirstRet = $0024
F_file_FindNextRet = $0025
F_setbaudWait = $0026

;
; 4D Constants, needs to be inserted into your PicAxe Program, if you want to use them, until such time as PicAxe supports includes
;
; // baud divisor rates for setbaud(n);

MIDI                   = $09
BAUD_110               = $00
BAUD_300               = $01
BAUD_600               = $02
BAUD_1200              = $03
BAUD_2400              = $04
BAUD_4800              = $05
BAUD_9600              = $06
BAUD_14400             = $07
BAUD_19200             = $08
BAUD_31250             = $09
BAUD_38400             = $0A
BAUD_56000             = $0B
BAUD_57600             = $0C
BAUD_115200            = $0D
BAUD_128000            = $0E
BAUD_256000            = $0F
BAUD_300000            = $10
BAUD_375000            = $11
BAUD_500000            = $12
BAUD_600000            = $13

; //------------------------------------------------------------------//
; // CONSTANTS
; //------------------------------------------------------------------//;
; // generic constants

ENABLE                 = $01
DISABLE                = $00
HI                     = $01
LO                     = $00
INPUT4D                = $01  ; Renamed to avoid conflict with PicAxe Basic
OUTPUT4D               = $00  ; Renamed to avoid conflict with PicAxe Basic
ON4D                   = $01  ; Renamed to avoid conflict with PicAxe Basic
OFF4D                  = $00  ; Renamed to avoid conflict with PicAxe Basic

; //------------------------------------------------------------------------------
; // Pin related constants
; //------------------------------------------------------------------------------

IO1_PIN                = $01       ; pin 2 J1
IO2_PIN                = $02       ; pin 1 J1
IO3_PIN                = $03       ; pin 3 J1
IO4_PIN                = $04       ; pin 5 J1 (also used for BUS_RD)
IO5_PIN                = $05       ; pin 9 J2 (also used for BUS_WR)
BUS_RD_PIN             = $04       ; pin 5 J1 (alias IO4_PIN)
BUS_WR_PIN             = $05       ; pin 9 J2 (alias IO5_PIN)
BACKLITE               = $06       ; backlite control pin
AUDIO_ENABLE           = $07       ; amplifier chip control pin
BUS_0                  = $08       ; pin 27 of J1
BUS_1                  = $09       ; pin 25 of J1
BUS_2                  = $0A      ; pin 23 of J1
BUS_3                  = $0B      ; pin 21 of J1
BUS_4                  = $0C      ; pin 19 of J1
BUS_5                  = $0D      ; pin 17 of J1
BUS_6                  = $0E      ; pin 13 of J2
BUS_7                  = $0F      ; pin 11 of J2

; //------------------------------------------------------------------------------
; //gfx_Set() related constants
; //------------------------------------------------------------------------------

PEN_SIZE               = $10      ; not necessary to use (legacy mode)
BACKGROUND_COLOUR      = $11
OBJECT_COLOUR          = $12      ; line / circle / rectangle generic colour
CLIPPING               = $13      ; clipping ON / OFF
TRANSPARENT_COLOUR     = $24      ; (only on displays with specific hware feature)
TRANSPARENCY           = $25      ; 0 = OFF, 1 = ON (only on displays with specific hware feature)
FRAME_DELAY            = $26      ; legacy mode, see pokeB(IMAGE_DELAY, n);
SCREEN_MODE            = $27      ; LANDSCAPE, LANDSCAPE_R, PORTRAIT, PORTRAIT_R
OUTLINE_COLOUR         = $28      ; if not BLACK (0) , used for outline around circles,rectangles and filled polygons
CONTRAST               = $29      ; for OLED,cahnge contrast, for LCD on or off only
LINE_PATTERN           = $2A      ; used for patterned lines, 16bit value (0 = no pattern, '1's = pattern)
COLOUR_MODE            = $2B      ; select 8 or 16 bit colour mode
BEVEL_WIDTH            = $2C      ; button bevel width
BEVEL_SHADOW           = $2D      ; button bevel shadow depth
X_ORIGIN               = $2E      ; display position X offset
Y_ORIGIN               = $2F      ; display position X offset


; //gfx_Get() related constants

X_MAX                  = $00       ; current orientations screen maximum X co-ordinate
Y_MAX                  = $01       ; current orientations screen maximum Y co-ordinate
LEFT_POS               = $02       ; last objects left co-ord
TOP_POS                = $03       ; last objects top co-ord
RIGHT_POS              = $4       ; last objects right co-ord
BOTTOM_POS             = $05       ; last objects bottom co-ord
X_ORG                  = $06       ; display position X offset
Y_ORG                  = $07       ; display position X offset

SOLID                  = $00       ; PEN_SIZE
OUTLINE                = $01       ; PEN_SIZE
STYLE1                 = $02
STYLE2                 = $03

LANDSCAPE              = $00       ; SCREEN_MODE (north)
LANDSCAPE_R            = $01       ; SCREEN_MODE (south)
PORTRAIT               = $02       ; SCREEN_MODE (west)
PORTRAIT_R             = $03       ; SCREEN_MODE (east)

COLOUR8                = $01       ; COLOUR_MODE 8 bit colour mode (not supported)
COLOUR16               = $00       ; COLOUR_MODE 16 bit colour mode

DOWN                   = $00
UP                     = $01
HIDE                   = $02
SELECT                 = $03
SELECT_MULTIPLE        = $04

BUTTON_DOWN            = $00
BUTTON_UP              = $01

SLIDER_SUNKEN          = $00
SLIDER_RAISED          = $01
SLIDER_HIDE            = $02

hPROGRESSBAR_RAISED    = $FFFF     ; low byte
hPROGRESSBAR_SUNKEN    = $FFFE     ; low byte
PROGRESSBAR_HIDE       = $02

PANEL_SUNKEN           = $00
PANEL_RAISED           = $01
PANEL_HIDE             = $02

; //------------------------------------------------------------------------------
; //txt_Set() related constants
; //------------------------------------------------------------------------------

TEXT_COLOUR            = $00       ; text foreground colr
TEXT_BACKGROUND        = $01       ; text background colr
TEXT_HIGHLIGHT         = $01       ; text background colr
FONT_ID                = $02       ; default 0, else points to data statement font
FONT_SIZE              = $02       ; compatibility
TEXT_WIDTH             = $03       ; text width multiplier
TEXT_HEIGHT            = $04       ; text height multiplier
TEXT_XGAP              = $05       ; horizontal text gap (default 1)
TEXT_YGAP              = $06       ; vertical text gap (default 1)
TEXT_PRINTDELAY        = $07       ; for 'teletype' like effect when printing
TEXT_OPACITY           = $08       ; text mode flag, TRANSPARENT or OPAQUE
TEXT_BOLD              = $09       ; embolden text (auto reset)
TEXT_ITALIC            = $0A      ; italicize text (auto reset)
TEXT_INVERSE           = $0B      ; invert text (auto reset)
TEXT_UNDERLINED        = $0C      ; underline text (auto reset)
TEXT_ATTRIBUTES        = $0D      ; controls BOLD/ITALIC/INVERSE/UNDERLINE simultaneously
TEXT_WRAP              = $0E      ; Sets the pixel position where text wrap will occur at RHS

; //------------------------------------------------------------------------------
; //txt_Set() related arguments
; // NB:- FONT4 must be inherited if required,
; // eg #inherit "FONT4.fnt"
; //------------------------------------------------------------------------------

FONT1                  = $00       ; (same as system font)
FONT2                  = $01
FONT3                  = $02       ; Default Font

TRANSPARENT            = $00       ; TEXT_OPACITY  transparent  text
OPAQUE                 = $01       ; TEXT_OPACITY  opaque text

BOLD                   = $10      ; TEXT_ATTRIBUTES bold text
ITALIC                 = $20      ; TEXT_ATTRIBUTES italic text
INVERSE                = $40      ; TEXT_ATTRIBUTES inverse text
UNDERLINED             = $80     ; TEXT_ATTRIBUTES underlined

; //touch_Set() related constants
TOUCH_ENABLE           = $00
TOUCH_DISABLE          = $01
TOUCH_REGIONDEFAULT    = $02

; //touch_Get() related constants
TOUCH_STATUS           = $00
TOUCH_GETX             = $01
TOUCH_GETY             = $02
NOTOUCH                = $00
TOUCH_PRESSED          = $01
TOUCH_RELEASED         = $02
TOUCH_MOVING           = $03

; // image control offset related constants
IMG_COUNT              = $00
IMG_ENTRYLEN           = $01
IMG_MODE               = $02
IMG_GCI_FILENAME       = $03
IMG_DAT_FILENAME       = $04
IMG_GCIFILE_HANDLE     = $05

; // image attribute flags
; // for img_SetAttributes(...) and img_ClearAttributes(...)
I_ENABLED             = $8000  ; low byte
I_DARKEN              = $4000  ; low byte
I_LIGHTEN             = $2000  ; low byte
I_TOUCHED             = $1000  ; low byte
I_Y_LOCK              = $0800  ; low byte
I_X_LOCK              = $0400  ; low byte
I_TOPMOST             = $0200  ; low byte
I_STAYONTOP           = $0100  ; low byte
I_MOVIE                = $0080  ; bit 7,   image is a movie
I_NOGROUP              = $0040  ; bit 6,   set to exclude image refresh when using img_Show(hndl, ALL);
I_TOUCH_DISABLE        = $0020  ; bit 5,   set to disable touch for this image, default=1 for movie, 0 for image
I_COLOUR16             = $0010  ; bit 4,   indicates 16 bit colour mode
;     // bits 0-3 reserved

I_ALL                   = $FFFF  ; low byte

; // image control entry offsets
IMAGE_LOWORD           = $00       ; WORD image address LO
IMAGE_HIWORD           = $01       ; WORD image address HI
IMAGE_XPOS             = $02       ; WORD image location X
IMAGE_YPOS             = $03       ; WORD image location Y
IMAGE_WIDTH            = $04       ; WORD image width
IMAGE_HEIGHT           = $05       ; WORD image height
IMAGE_FLAGS            = $06       ; WORD image flags
IMAGE_DELAY            = $07       ; WORD inter frame delay
IMAGE_FRAMES           = $08       ; WORD number of frames
IMAGE_INDEX            = $09       ; WORD current frame
IMAGE_CLUSTER          = $0A      ; WORD image start cluster  pos (for FAT16 only)
IMAGE_SECTOR           = $0B      ; WORD image start sector in cluster pos (for FAT16 only)
IMAGE_TAG              = $0C      ; WORD user variable #1
IMAGE_TAG2             = $0D      ; WORD user variable #2

; // DISK struct offsets
DISK_FIRST_SECT_LO     = $00       ; DWORD address of the first sector of the FAT partition (LO word)
DISK_FIRST_SECT_HI     = $01       ;       address of the first sector of the FAT partition (HI word)
DISK_FAT_LO            = $02       ; DWORD address of FAT (LO word)
DISK_FAT_HI            = $03       ;       address of FAT (HI word)
DISK_ROOT_LO           = $04       ; DWORD address of root directory (LO word)
DISK_ROOT_HI           = $05       ;       address of root directory (HI word)
DISK_DATA_LO           = $06       ; DWORD address of data area (LO word)
DISK_DATA_HI           = $07       ;       address of data area (HI word)
DISK_MAXCLUS_LO        = $08       ; DWORD max number of clusters in partition (LO word)
DISK_MAXCLUS_HI        = $09       ;       max number of clusters in partition (HI word)
DISK_MAXROOT           = $0A      ; WORD  max entries in root directory
DISK_FATSIZE           = $0B      ; WORD  number of sectors in FAT
DISK_FATCOPIES         = $0C      ; WORD  number of fat copies
DISK_SECT_PER_CLUS     = $0D      ; WORD  number of sectors per cluster
DISK_TYPE              = $0E      ; WORD  type of fat
DISK_BUF               = $0F      ; WORD  pointer to 512 byte info buffer

; // FILE struct offsets
FILE_FIRST_CLUSTER     = $00       ; WORD  first cluster
FILE_CURR_CLUSTER      = $01       ; WORD  current cluster in file
FILE_CURR_SECTOR       = $02       ; WORD  sector in current cluster
FILE_CURR_SECTOR_POS   = $03       ; WORD  position in current sector
FILE_CURR_SECTOR_TOP   = $04       ; WORD  number bytes in current sector buffer
FILE_SEEK_POS_LO       = $05       ; DWORD position in the file (LO word)
FILE_SEEK_POS_HI       = $06       ;       position in the file (HI word)
FILE_SIZE_LO           = $07       ; DWORD file size (LO word)
FILE_SIZE_HI           = $08       ;       file size (HI word)
FILE_TIME              = $09       ; WORD  last update time
FILE_DATE              = $0A      ; WORD  last update date
FILE_NAME              = $0B      ; WORD  12 byte buffer for filename
FILE_MODE              = $11      ; WORD  file mode 'r', 'w', 'a'
FILE_ATTRIBUTES        = $12      ; WORD  files attributes
FILE_PAGEFLAG          = $13      ; WORD  cache check flag
FILE_ENTRY             = $14      ; WORD  entry position in cur directory
FILE_DISK              = $16      ; WORD* pointer to DISK mount media structure
FILE_BUFFER            = $17      ; WORD*  sector buffer

; // timer control  related constants
TIMER0                 = $00
TIMER1                 = $01
TIMER2                 = $02
TIMER3                 = $03
TIMER4                 = $04
TIMER5                 = $05
TIMER6                 = $06
TIMER7                 = $07

; // I2C timing related constants
I2C_SLOW               = $00
I2C_MED                = $01
I2C_FAST               = $02

; // spi_Init(...)  mode arguments
SPI_SLOW               = $02       ; 750khz
SPI_MED                = $01       ; 3mhz
SPI_FAST               = $00       ; 12mhz
RXMODE_0               = $00       ; receive sample pos
RXMODE_1               = $01       ; receive sample pos
CKMODE_0               = $00       ; transmit sample pos
CKMODE_1               = $01       ; transmit sample pos
CKMODE_2               = $02       ; transmit sample pos
CKMODE_3               = $03       ; transmit sample pos

; //------------------------------------------------------------------------------
; // system WORD variables accesible with peekW and pokeW or pointer access
; // Note that the txt_Set variables (0-15) and gfx_set variables (16-31)
; // can also be accessed with peekW and pokeW
; //------------------------------------------------------------------------------

RANDOM_LO              = 32      ; random number generator LO word
RANDOM_HI              = 33      ; random number generator LO word
SYSTEM_TIMER_LO        = 34      ; 1msec 32 bit free running timer LO word
SYSTEM_TIMER_HI        = 35      ; 1msec 32 bit free running timer HI word
TMR0                   = 36      ; user timer0
TMR1                   = 37      ; user timer1
TMR2                   = 38      ; user timer2
TMR3                   = 39      ; user timer3 (10msec resolution)
TMR4                   = 40      ; user timer0
TMR5                   = 41      ; user timer1
TMR6                   = 42      ; user timer2
TMR7                   = 43      ; user timer3 (10msec resolution)
SYS_X_MAX              = 44      ; display hardware X res-1
SYS_Y_MAX              = 45      ; display hardware Y res-1
GFX_XMAX               = 46      ; current display width-1 determined by portrait / landscape swapping
GFX_YMAX               = 47      ; current display width-1 determined by portrait / landscape swapping
GFX_LEFT               = 48      ; virtual left point for most recent object
GFX_TOP                = 49      ; virtual top point for most recent object
GFX_RIGHT              = 50      ; virtual right point for most recent object
GFX_BOTTOM             = 51      ; virtual bottom point for most recent object
GFX_X1                 = 52      ; clipped left point for current object
GFX_Y1                 = 53      ; clipped top point for current object
GFX_X2                 = 54      ; clipped right point for current object
GFX_Y2                 = 55      ; clipped bottom point for current object
GFX_X_ORG              = 56      ; current X origin
GFX_Y_ORG              = 57      ; current Y origin
GFX_HILITE_LINE        = 58      ; current multi line button hilite line
GFX_LINE_COUNT         = 59      ; count of lines in multiline button
GFX_LAST_SELECTION     = 60      ; last selected line
GFX_HILIGHT_BACKGROUND = 61      ; multi button hilite background colour
GFX_HILIGHT_FOREGROUND = 62      ; multi button hilite background colour
GFX_BUTTON_FOREGROUND  = 63      ; store default text colour for hilite line tracker
GFX_BUTTON_BACKGROUND  = 64      ; store default button colour for hilite line tracker
GFX_BUTTON_MODE        = 65      ; store current buttons mode
GFX_TOOLBAR_HEIGHT     = 66      ; height above
GFX_STATUSBAR_HEIGHT   = 67      ; height below
GFX_LEFT_GUTTER_WIDTH  = 68      ; width to left
GFX_RIGHT_GUTTER_WIDTH = 69      ; width to right
GFX_PIXEL_SHIFT        = 70      ; pixel shift for button depress illusion (default 1)
GFX_RECT_X1            = 71      ; gp rect, used by multiline button to hilite required line
GFX_RECT_Y1            = 72
GFX_RECT_X2            = 73
GFX_RECT_Y2            = 74
GFX_THUMB_PERCENT      = 75      ; size of slider thumb as percentage
GFX_THUMB_BORDER_DARK  = 76      ; darker shadow of thumb
GFX_THUMB_BORDER_LIGHT = 77      ; lighter shadow of thumb
TOUCH_XMINCAL          = 78      ; touch calibration value
TOUCH_YMINCAL          = 79      ; touch calibration value
TOUCH_XMAXCAL          = 80      ; touch calibration value
TOUCH_YMAXCAL          = 81      ; touch calibration value
IMG_WIDTH              = 82      ; width of currently loaded image
IMG_HEIGHT             = 83      ; height of currently loaded image
IMG_FRAME_DELAY        = 84      ; 0 if image, else inter frame delay for movie
IMG_FLAGS              = 85      ; bit 4 determines colour mode, other bits reserved
IMG_FRAME_COUNT        = 86      ; count of frames in a movie
IMG_PIXEL_COUNT_LO     = 87      ; count of pixels in the current frame
IMG_PIXEL_COUNT_HI     = 88      ; count of pixels in the current frame
IMG_CURRENT_FRAME      = 89      ; last frame shown
MEDIA_ADDRESS_LO       = 90      ; uSD byte address LO
MEDIA_ADDRESS_HI       = 91      ; uSD byte address HI
MEDIA_SECTOR_LO        = 92      ; uSD sector address LO
MEDIA_SECTOR_HI        = 93      ; uSD sector address HI
MEDIA_SECTOR_COUNT     = 94      ; uSD number of bytes remaining in sector
TEXT_XPOS              = 95      ; text current x pixel position
TEXT_YPOS              = 96      ; text current y pixel position
TEXT_MARGIN            = 97      ; text left pixel pos for carriage return
TXT_FONT_ID            = 98      ; font type, 0 = system font, else pointer to user font
TXT_FONT_MAX           = 99      ; max number of chars in font
TXT_FONT_OFFSET        = 100     ; starting offset (normally 0x20)
TXT_FONT_WIDTH         = 101     ; current font width
TXT_FONT_HEIGHT        = 102     ; current font height
GFX_TOUCH_REGION_X1    = 103     ; touch capture region
GFX_TOUCH_REGION_Y1    = 104
GFX_TOUCH_REGION_X2    = 105
GFX_TOUCH_REGION_Y2    = 106
GFX_CLIP_LEFT_VAL      = 107     ; left clipping point (set with gfx_ClipWindow(...)
GFX_CLIP_TOP_VAL       = 108     ; top clipping point (set with gfx_ClipWindow(...)
GFX_CLIP_RIGHT_VAL     = 109     ; right clipping point (set with gfx_ClipWindow(...)
GFX_CLIP_BOTTOM_VAL    = 110     ; bottom clipping point (set with gfx_ClipWindow(...)
GFX_CLIP_LEFT          = 111     ; current clip value (reads full size if clipping turned off)
GFX_CLIP_TOP           = 112     ; current clip value (reads full size if clipping turned off)
GFX_CLIP_RIGHT         = 113     ; current clip value (reads full size if clipping turned off)
GFX_CLIP_BOTTOM        = 114     ; current clip value (reads full size if clipping turned off)
GRAM_PIXEL_COUNT_LO    = 115     ; LO word of count of pixels in the set GRAM area
GRAM_PIXEL_COUNT_HI    = 116     ; HI word of count of pixels in the set GRAM area
TOUCH_RAW_X            = 117     ; 12 bit raw A2D X value from touch screen
TOUCH_RAW_Y            = 118     ; 12 bit raw A2D Y value from touch screen
GFX_LAST_CHAR_WIDTH    = 119     ; calculated char width from last call to charWidth function
GFX_LAST_CHAR_HEIGHT   = 120     ; calculated height from last call to charHeight function
GFX_LAST_STR_WIDTH     = 121     ; calculated width from last call to strWidth function
GFX_LAST_STR_HEIGHT    = 122     ; calculated height from last call to strHeight function

; //------------------------------------------------------------------------------
; // FILEIO Error Code Constants
; //------------------------------------------------------------------------------

FE_OK                  = 0       ; IDE function succeeded
FE_IDE_ERROR           = 1       ; IDE command execution error
FE_NOT_PRESENT         = 2       ; CARD not present
FE_PARTITION_TYPE      = 3       ; WRONG partition type, not FAT16
FE_INVALID_MBR         = 4       ; MBR sector invalid signature
FE_INVALID_BR          = 5       ; Boot Record invalid signature
FE_DISK_NOT_MNTD       = 6       ; Media not mounted
FE_FILE_NOT_FOUND      = 7       ; File not found in open for read
FE_INVALID_FILE        = 8       ; File not open
FE_FAT_EOF             = 9       ; Fat attempt to read beyond EOF
FE_EOF                 = 10      ; Reached the end of file
FE_INVALID_CLUSTER     = 11      ; Invalid cluster value > maxcls
FE_DIR_FULL            = 12      ; All root dir entry are taken
FE_DISK_FULL           = 13      ; All clusters in partition are taken
FE_FILE_OVERWRITE      = 14      ; A file with same name exist already
FE_CANNOT_INIT         = 15      ; Cannot init the CARD
FE_CANNOT_READ_MBR     = 16      ; Cannot read the MBR
FE_MALLOC_FAILED       = 17      ; Malloc could not allocate the FILE struct
FE_INVALID_MODE        = 18      ; Mode was not r.w.
FE_FIND_ERROR          = 19      ; Failure during FILE search
FE_INVALID_FNAME       = 20      ; bad filename
FE_INVALID_MEDIA       = 21      ; bad media
FE_SECTOR_READ_FAIL    = 22      ; sector read failed
FE_SECTOR_WRITE_FAIL   = 23      ; sector write failed