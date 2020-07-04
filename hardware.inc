;*
;* Gameboy Hardware definitions
;*
;* Based on Jones' hardware.inc
;* And based on Carsten Sorensen's ideas.
;*
;* Rev 1.1 - 15-Jul-97 : Added define check
;* Rev 1.2 - 18-Jul-97 : Added revision check macro
;* Rev 1.3 - 19-Jul-97 : Modified for RGBASM V1.05
;* Rev 1.4 - 27-Jul-97 : Modified for new subroutine prefixes
;* Rev 1.5 - 15-Aug-97 : Added _HRAM, PAD, CART defines
;*                     :  and Nintendo Logo
;* Rev 1.6 - 30-Nov-97 : Added rDIV, rTIMA, rTMA, & rTAC
;* Rev 1.7 - 31-Jan-98 : Added _SCRN0, _SCRN1
;* Rev 1.8 - 15-Feb-98 : Added rSB, rSC
;* Rev 1.9 - 16-Feb-98 : Converted I/O registers to $FFXX format
;* Rev 2.0 -           : Added GBC registers
;* Rev 2.1 -           : Added MBC5 & cart RAM enable/disable defines
;* Rev 2.2 -           : Fixed NR42,NR43, & NR44 equates
;* Rev 2.3 -           : Fixed incorrect _HRAM equate
;* Rev 2.4 - 27-Apr-13 : Added some cart defines (AntonioND)
;* Rev 2.5 - 03-May-15 : Fixed format (AntonioND)
;* Rev 2.6 - 09-Apr-16 : Added GBC OAM and cart defines (AntonioND)
;* Rev 2.7 - 19-Jan-19 : Added rPCMXX (ISSOtm)
;* Rev 2.8 - 03-Feb-19 : Added audio registers flags (Álvaro Cuesta)
;* Rev 2.9 - 28-Feb-20 : Added utility rP1 constants

; If all of these are already defined, don't do it again.

    IF !DEF(HARDWARE_INC)
HARDWARE_INC SET 1

rev_Check_hardware_inc : MACRO
;NOTE: REVISION NUMBER CHANGES MUST BE ADDED
;TO SECOND PARAMETER IN FOLLOWING LINE.
    IF  \1 > 2.9 ;PUT REVISION NUMBER HERE
        WARN    "Version \1 or later of 'hardware.inc' is required."
    ENDC
ENDM

_HW          EQU $FF00 ; $FF00->$FF7F,$FFFF

_VRAM        EQU $8000 ; $8000->$9FFF
_SCRN0       EQU $9800 ; $9800->$9BFF
_SCRN1       EQU $9C00 ; $9C00->$9FFF
_SRAM        EQU $A000 ; $A000->$BFFF
_RAM         EQU $C000 ; $C000->$DFFF
_OAMRAM      EQU $FE00 ; $FE00->$FE9F
_AUD3WAVERAM EQU $FF30 ; $FF30->$FF3F
_HRAM        EQU $FF80 ; $FF80->$FFFE

; *** MBC5 Equates ***

rRAMG        EQU $0000 ; $0000->$1fff
rROMB0       EQU $2000 ; $2000->$2fff
rROMB1       EQU $3000 ; $3000->$3fff - If more than 256 ROM banks are present.
rRAMB        EQU $4000 ; $4000->$5fff - Bit 3 enables rumble (if present)


; --
; -- OAM flags
; --

OAMF_PRI        EQU %10000000 ; Priority
OAMF_YFLIP      EQU %01000000 ; Y flip
OAMF_XFLIP      EQU %00100000 ; X flip
OAMF_PAL0       EQU %00000000 ; Palette number; 0,1 (DMG)
OAMF_PAL1       EQU %00010000 ; Palette number; 0,1 (DMG)
OAMF_BANK0      EQU %00000000 ; Bank number; 0,1 (GBC)
OAMF_BANK1      EQU %00001000 ; Bank number; 0,1 (GBC)

OAMF_PALMASK    EQU %00000111 ; Palette (GBC)

OAMB_PRI        EQU 7 ; Priority 
OAMB_YFLIP      EQU 6 ; Y flip 
OAMB_XFLIP      EQU 5 ; X flip 
OAMB_PAL1       EQU 4 ; Palette number; 0,1 (DMG) 
OAMB_BANK1      EQU 3 ; Bank number; 0,1 (GBC) 


;***************************************************************************
;*
;* Custom registers
;*
;***************************************************************************

; --
; -- P1 ($FF00)
; -- Register for reading joy pad info.    (R/W)
; --
oP1 EQU $00
rP1 EQU (_HW + oP1)

P1F_5 EQU %00100000 ; P15 out port, set to 0 to get buttons
P1F_4 EQU %00010000 ; P14 out port, set to 0 to get dpad
P1F_3 EQU %00001000 ; P13 in port
P1F_2 EQU %00000100 ; P12 in port
P1F_1 EQU %00000010 ; P11 in port
P1F_0 EQU %00000001 ; P10 in port

P1F_GET_DPAD EQU P1F_5
P1F_GET_BTN  EQU P1F_4
P1F_GET_NONE EQU P1F_4 | P1F_5

; --
; -- SB ($FF01)
; -- Serial Transfer Data (R/W)
; --
oSB EQU $01
rSB EQU (_HW + oSB)


; --
; -- SC ($FF02)
; -- Serial I/O Control (R/W)
; --
oSC EQU $02
rSC EQU (_HW + oSC)


; --
; -- DIV ($FF04)
; -- Divider register (R/W)
; --
oDIV EQU $04
rDIV EQU (_HW + oDIV)


; --
; -- TIMA ($FF05)
; -- Timer counter (R/W)
; --
oTIMA EQU $05
rTIMA EQU (_HW + oTIMA)


; --
; -- TMA ($FF06)
; -- Timer modulo (R/W)
; --
oTMA EQU $06
rTMA EQU (_HW + oTMA)


; --
; -- TAC ($FF07)
; -- Timer control (R/W)
; --
oTAC EQU $07
rTAC EQU (_HW + oTAC)

TACF_START  EQU %00000100
TACF_STOP   EQU %00000000
TACF_4KHZ   EQU %00000000
TACF_16KHZ  EQU %00000011
TACF_65KHZ  EQU %00000010
TACF_262KHZ EQU %00000001


; --
; -- IF ($FF0F)
; -- Interrupt Flag (R/W)
; --
oIF EQU $0F
rIF EQU (_HW + oIF)


; --
; -- AUD1SWEEP/NR10 ($FF10)
; -- Sweep register (R/W)
; --
; -- Bit 6-4 - Sweep Time
; -- Bit 3   - Sweep Increase/Decrease
; --           0: Addition    (frequency increases???)
; --           1: Subtraction (frequency increases???)
; -- Bit 2-0 - Number of sweep shift (# 0-7)
; -- Sweep Time: (n*7.8ms)
; --
oNR10 EQU $10
rNR10 EQU (_HW + oNR10)
rAUD1SWEEP EQU rNR10

AUD1SWEEP_UP   EQU %00000000
AUD1SWEEP_DOWN EQU %00001000


; --
; -- AUD1LEN/NR11 ($FF11)
; -- Sound length/Wave pattern duty (R/W)
; --
; -- Bit 7-6 - Wave Pattern Duty (00:12.5% 01:25% 10:50% 11:75%)
; -- Bit 5-0 - Sound length data (# 0-63)
; --
oNR11 EQU $11
rNR11 EQU (_HW + oNR11)
rAUD1LEN EQU rNR11


; --
; -- AUD1ENV/NR12 ($FF12)
; -- Envelope (R/W)
; --
; -- Bit 7-4 - Initial value of envelope
; -- Bit 3   - Envelope UP/DOWN
; --           0: Decrease
; --           1: Range of increase
; -- Bit 2-0 - Number of envelope sweep (# 0-7)
; --
oNR12 EQU $12
rNR12 EQU (_HW + oNR12)
rAUD1ENV EQU rNR12


; --
; -- AUD1LOW/NR13 ($FF13)
; -- Frequency lo (W)
; --
oNR13 EQU $13
rNR13 EQU (_HW + oNR13)
rAUD1LOW EQU rNR13


; --
; -- AUD1HIGH/NR14 ($FF14)
; -- Frequency hi (W)
; --
; -- Bit 7   - Initial (when set, sound restarts)
; -- Bit 6   - Counter/consecutive selection
; -- Bit 2-0 - Frequency's higher 3 bits
; --
oNR14 EQU $14
rNR14 EQU (_HW + oNR14)
rAUD1HIGH EQU rNR14


; --
; -- AUD2LEN/NR21 ($FF16)
; -- Sound Length; Wave Pattern Duty (R/W)
; --
; -- see AUD1LEN for info
; --
oNR21 EQU $16
rNR21 EQU (_HW + oNR21)
rAUD2LEN EQU rNR21


; --
; -- AUD2ENV/NR22 ($FF17)
; -- Envelope (R/W)
; --
; -- see AUD1ENV for info
; --
oNR22 EQU $17
rNR22 EQU (_HW + oNR22)
rAUD2ENV EQU rNR22


; --
; -- AUD2LOW/NR23 ($FF18)
; -- Frequency lo (W)
; --
oNR23 EQU $18
rNR23 EQU (_HW + oNR23)
rAUD2LOW EQU rNR23


; --
; -- AUD2HIGH/NR24 ($FF19)
; -- Frequency hi (W)
; --
; -- see AUD1HIGH for info
; --
oNR24 EQU $19
rNR24 EQU (_HW + oNR24)
rAUD2HIGH EQU rNR24


; --
; -- AUD3ENA/NR30 ($FF1A)
; -- Sound on/off (R/W)
; --
; -- Bit 7   - Sound ON/OFF (1=ON,0=OFF)
; --
oNR30 EQU $1A
rNR30 EQU (_HW + oNR30)
rAUD3ENA EQU rNR30


; --
; -- AUD3LEN/NR31 ($FF1B)
; -- Sound length (R/W)
; --
; -- Bit 7-0 - Sound length
; --
oNR31 EQU $1B
rNR31 EQU (_HW + oNR31)
rAUD3LEN EQU rNR31


; --
; -- AUD3LEVEL/NR32 ($FF1C)
; -- Select output level
; --
; -- Bit 6-5 - Select output level
; --           00: 0/1 (mute)
; --           01: 1/1
; --           10: 1/2
; --           11: 1/4
; --
oNR32 EQU $1C
rNR32 EQU (_HW + oNR32)
rAUD3LEVEL EQU rNR32


; --
; -- AUD3LOW/NR33 ($FF1D)
; -- Frequency lo (W)
; --
; -- see AUD1LOW for info
; --
oNR33 EQU $1D
rNR33 EQU (_HW + oNR33)
rAUD3LOW EQU rNR33


; --
; -- AUD3HIGH/NR34 ($FF1E)
; -- Frequency hi (W)
; --
; -- see AUD1HIGH for info
; --
oNR34 EQU $1E
rNR34 EQU (_HW + oNR34)
rAUD3HIGH EQU rNR34


; --
; -- AUD4LEN/NR41 ($FF20)
; -- Sound length (R/W)
; --
; -- Bit 5-0 - Sound length data (# 0-63)
; --
oNR41 EQU $20
rNR41 EQU (_HW + oNR41)
rAUD4LEN EQU rNR41


; --
; -- AUD4ENV/NR42 ($FF21)
; -- Envelope (R/W)
; --
; -- see AUD1ENV for info
; --
oNR42 EQU $21
rNR42 EQU (_HW + oNR42)
rAUD4ENV EQU rNR42


; --
; -- AUD4POLY/NR43 ($FF22)
; -- Polynomial counter (R/W)
; --
; -- Bit 7-4 - Selection of the shift clock frequency of the (scf)
; --           polynomial counter (0000-1101)
; --           freq=drf*1/2^scf (not sure)
; -- Bit 3 -   Selection of the polynomial counter's step
; --           0: 15 steps
; --           1: 7 steps
; -- Bit 2-0 - Selection of the dividing ratio of frequencies (drf)
; --           000: f/4   001: f/8   010: f/16  011: f/24
; --           100: f/32  101: f/40  110: f/48  111: f/56  (f=4.194304 Mhz)
; --
oNR43 EQU $22
rNR43 EQU (_HW + oNR43)
rAUD4POLY EQU rNR43


; --
; -- AUD4GO/NR44 ($FF23)
; -- (has wrong name and value (ff30) in Dr.Pan's doc!)
; --
; -- Bit 7 -   Inital
; -- Bit 6 -   Counter/consecutive selection
; --
oNR44 EQU $23
rNR44 EQU (_HW + oNR44)
rAUD4GO EQU rNR44 ; silly name!


; --
; -- AUDVOL/NR50 ($FF24)
; -- Channel control / ON-OFF / Volume (R/W)
; --
; -- Bit 7   - Vin->SO2 ON/OFF (Vin??)
; -- Bit 6-4 - SO2 output level (volume) (# 0-7)
; -- Bit 3   - Vin->SO1 ON/OFF (Vin??)
; -- Bit 2-0 - SO1 output level (volume) (# 0-7)
; --
oNR50 EQU $24
rNR50 EQU (_HW + oNR50)
rAUDVOL EQU rNR50

AUDVOL_VIN_LEFT  EQU %10000000 ; SO2
AUDVOL_VIN_RIGHT EQU %00001000 ; SO1


; --
; -- AUDTERM/NR51 ($FF25)
; -- Selection of Sound output terminal (R/W)
; --
; -- Bit 7   - Output sound 4 to SO2 terminal
; -- Bit 6   - Output sound 3 to SO2 terminal
; -- Bit 5   - Output sound 2 to SO2 terminal
; -- Bit 4   - Output sound 1 to SO2 terminal
; -- Bit 3   - Output sound 4 to SO1 terminal
; -- Bit 2   - Output sound 3 to SO1 terminal
; -- Bit 1   - Output sound 2 to SO1 terminal
; -- Bit 0   - Output sound 0 to SO1 terminal
; --
oNR51 EQU $25
rNR51 EQU (_HW + oNR51)
rAUDTERM EQU rNR51

; SO2
AUDTERM_4_LEFT  EQU %10000000
AUDTERM_3_LEFT  EQU %01000000
AUDTERM_2_LEFT  EQU %00100000
AUDTERM_1_LEFT  EQU %00010000
; SO1
AUDTERM_4_RIGHT EQU %00001000
AUDTERM_3_RIGHT EQU %00000100
AUDTERM_2_RIGHT EQU %00000010
AUDTERM_1_RIGHT EQU %00000001


; --
; -- AUDENA/NR52 ($FF26)
; -- Sound on/off (R/W)
; --
; -- Bit 7   - All sound on/off (sets all audio regs to 0!)
; -- Bit 3   - Sound 4 ON flag (doesn't work!)
; -- Bit 2   - Sound 3 ON flag (doesn't work!)
; -- Bit 1   - Sound 2 ON flag (doesn't work!)
; -- Bit 0   - Sound 1 ON flag (doesn't work!)
; --
oNR52 EQU $26
rNR52 EQU (_HW + oNR52)
rAUDENA EQU rNR52

AUDENA_ON    EQU %10000000
AUDENA_OFF   EQU %00000000  ; sets all audio regs to 0!


; --
; -- LCDC ($FF40)
; -- LCD Control (R/W)
; --
oLCDC EQU $40
rLCDC EQU (_HW + oLCDC)

LCDCF_OFF     EQU %00000000 ; LCD Control Operation
LCDCF_ON      EQU %10000000 ; LCD Control Operation
LCDCF_WIN9800 EQU %00000000 ; Window Tile Map Display Select
LCDCF_WIN9C00 EQU %01000000 ; Window Tile Map Display Select
LCDCF_WINOFF  EQU %00000000 ; Window Display
LCDCF_WINON   EQU %00100000 ; Window Display
LCDCF_BG8800  EQU %00000000 ; BG & Window Tile Data Select
LCDCF_BG8000  EQU %00010000 ; BG & Window Tile Data Select
LCDCF_BG9800  EQU %00000000 ; BG Tile Map Display Select
LCDCF_BG9C00  EQU %00001000 ; BG Tile Map Display Select
LCDCF_OBJ8    EQU %00000000 ; OBJ Construction
LCDCF_OBJ16   EQU %00000100 ; OBJ Construction
LCDCF_OBJOFF  EQU %00000000 ; OBJ Display
LCDCF_OBJON   EQU %00000010 ; OBJ Display
LCDCF_BGOFF   EQU %00000000 ; BG Display
LCDCF_BGON    EQU %00000001 ; BG Display
; "Window Character Data Select" follows BG


; --
; -- STAT ($FF41)
; -- LCDC Status   (R/W)
; --
oSTAT EQU $41
rSTAT EQU (_HW + oSTAT)

STATF_LYC     EQU  %01000000 ; LYC=LY Coincidence (Selectable)
STATF_MODE10  EQU  %00100000 ; Mode 10
STATF_MODE01  EQU  %00010000 ; Mode 01 (V-Blank)
STATF_MODE00  EQU  %00001000 ; Mode 00 (H-Blank)
STATF_LYCF    EQU  %00000100 ; Coincidence Flag
STATF_HB      EQU  %00000000 ; H-Blank
STATF_VB      EQU  %00000001 ; V-Blank
STATF_OAM     EQU  %00000010 ; OAM-RAM is used by system
STATF_LCD     EQU  %00000011 ; Both OAM and VRAM used by system
STATF_BUSY    EQU  %00000010 ; When set, VRAM access is unsafe


; --
; -- SCY ($FF42)
; -- Scroll Y (R/W)
; --
oSCY EQU $42
rSCY EQU (_HW + oSCY)


; --
; -- SCY ($FF43)
; -- Scroll X (R/W)
; --
oSCX EQU $43
rSCX EQU (_HW + oSCX)


; --
; -- LY ($FF44)
; -- LCDC Y-Coordinate (R)
; --
; -- Values range from 0->153. 144->153 is the VBlank period.
; --
oLY EQU $44
rLY EQU (_HW + oLY)


; --
; -- LYC ($FF45)
; -- LY Compare (R/W)
; --
; -- When LY==LYC, STATF_LYCF will be set in STAT
; --
oLYC EQU $45
rLYC EQU (_HW + oLYC)


; --
; -- DMA ($FF46)
; -- DMA Transfer and Start Address (W)
; --
oDMA EQU $46
rDMA EQU (_HW + oDMA)


; --
; -- BGP ($FF47)
; -- BG Palette Data (W)
; --
; -- Bit 7-6 - Intensity for %11
; -- Bit 5-4 - Intensity for %10
; -- Bit 3-2 - Intensity for %01
; -- Bit 1-0 - Intensity for %00
; --
oBGP EQU $47
rBGP EQU (_HW + oBGP)


; --
; -- OBP0 ($FF48)
; -- Object Palette 0 Data (W)
; --
; -- See BGP for info
; --
oOBP0 EQU $48
rOBP0 EQU (_HW + oOBP0)


; --
; -- OBP1 ($FF49)
; -- Object Palette 1 Data (W)
; --
; -- See BGP for info
; --
oOBP1 EQU $49
rOBP1 EQU (_HW + oOBP1)


; --
; -- WY ($FF4A)
; -- Window Y Position (R/W)
; --
; -- 0 <= WY <= 143
; --
oWY EQU $4A
rWY EQU (_HW + oWY)


; --
; -- WX ($FF4B)
; -- Window X Position (R/W)
; --
; -- 7 <= WX <= 166
; --
oWX EQU $4B
rWX EQU (_HW + oWX)


; --
; -- KEY 1 ($FF4D)
; -- Select CPU Speed (R/W)
; --
oKEY1 EQU $4D
rKEY1 EQU (_HW + oKEY1)


; --
; -- VBK ($FF4F)
; -- Select Video RAM Bank (R/W)
; --
; -- Bit 0 - Bank Specification (0: Specify Bank 0; 1: Specify Bank 1)
; --
oVBK EQU $4F
rVBK EQU (_HW + oVBK)


; --
; -- HDMA1 ($FF51)
; -- Horizontal Blanking, General Purpose DMA (W)
; --
oHDMA1 EQU $51
rHDMA1 EQU (_HW + oHDMA1)


; --
; -- HDMA2 ($FF52)
; -- Horizontal Blanking, General Purpose DMA (W)
; --
oHDMA2 EQU $52
rHDMA2 EQU (_HW + oHDMA2)


; --
; -- HDMA3 ($FF53)
; -- Horizontal Blanking, General Purpose DMA (W)
; --
oHDMA3 EQU $53
rHDMA3 EQU (_HW + oHDMA3)


; --
; -- HDMA4 ($FF54)
; -- Horizontal Blanking, General Purpose DMA (W)
; --
oHDMA4 EQU $54
rHDMA4 EQU (_HW + oHDMA4)


; --
; -- HDMA5 ($FF55)
; -- Horizontal Blanking, General Purpose DMA (R/W)
; --
oHDMA5 EQU $55
rHDMA5 EQU (_HW + oHDMA5)


; --
; -- RP ($FF56)
; -- Infrared Communications Port (R/W)
; --
oRP EQU $56
rRP EQU (_HW + oRP)


; --
; -- BCPS ($FF68)
; -- Background Color Palette Specification (R/W)
; --
oBCPS EQU $68
rBCPS EQU (_HW + oBCPS)


; --
; -- BCPD ($FF69)
; -- Background Color Palette Data (R/W)
; --
oBCPD EQU $69
rBCPD EQU (_HW + oBCPD)


; --
; -- BCPS ($FF6A)
; -- Object Color Palette Specification (R/W)
; --
oOCPS EQU $6A
rOCPS EQU (_HW + oOCPS)


; --
; -- BCPD ($FF6B)
; -- Object Color Palette Data (R/W)
; --
oOCPD EQU $6B
rOCPD EQU (_HW + oOCPD)


; --
; -- SVBK ($FF70)
; -- Select Main RAM Bank (R/W)
; --
; -- Bit 2-0 - Bank Specification (0,1: Specify Bank 1; 2-7: Specify Banks 2-7)
; --
oSVBK EQU $70
rSVBK EQU (_HW + oSVBK)


; --
; -- PCM12 ($FF76)
; -- Sound channel 1&2 PCM amplitude (R)
; --
; -- Bit 7-4 - Copy of sound channel 2's PCM amplitude
; -- Bit 3-0 - Copy of sound channel 1's PCM amplitude
; --
oPCM12 EQU $76
rPCM12 EQU (_HW + oPCM12)


; --
; -- PCM34 ($FF77)
; -- Sound channel 3&4 PCM amplitude (R)
; --
; -- Bit 7-4 - Copy of sound channel 4's PCM amplitude
; -- Bit 3-0 - Copy of sound channel 3's PCM amplitude
; --
oPCM34 EQU $77
rPCM34 EQU (_HW + oPCM34)


; --
; -- IE ($FFFF)
; -- Interrupt Enable (R/W)
; --
oIE EQU $FF
rIE EQU (_HW + oIE)

IEF_HILO   EQU %00010000 ; Transition from High to Low of Pin number P10-P13
IEF_SERIAL EQU %00001000 ; Serial I/O transfer end
IEF_TIMER  EQU %00000100 ; Timer Overflow
IEF_LCDC   EQU %00000010 ; LCDC (see STAT)
IEF_VBLANK EQU %00000001 ; V-Blank


;***************************************************************************
;*
;* Flags common to multiple sound channels
;*
;***************************************************************************

; --
; -- Square wave duty cycle
; --
; -- Can be used with AUD1LEN and AUD2LEN
; -- See AUD1LEN for more info
; --
AUDLEN_DUTY_12_5    EQU %00000000 ; 12.5%
AUDLEN_DUTY_25      EQU %01000000 ; 25%
AUDLEN_DUTY_50      EQU %10000000 ; 50%
AUDLEN_DUTY_75      EQU %11000000 ; 75%


; --
; -- Audio envelope flags
; --
; -- Can be used with AUD1ENV, AUD2ENV, AUD4ENV
; -- See AUD1ENV for more info
; --
AUDENV_UP           EQU %00001000
AUDENV_DOWN         EQU %00000000


; --
; -- Audio trigger flags
; --
; -- Can be used with AUD1HIGH, AUD2HIGH, AUD3HIGH
; -- See AUD1HIGH for more info
; --

AUDHIGH_RESTART     EQU %10000000
AUDHIGH_LENGTH_ON   EQU %01000000
AUDHIGH_LENGTH_OFF  EQU %00000000


;***************************************************************************
;*
;* CPU value on bootup (a=type)
;*
;***************************************************************************

CPU_DMG	EQU	$01	; Dot Matrix Game
CPU_CGB	EQU	$11	; Color GameBoy
CPU_MGB	EQU	$FF	; Mini GameBoy (Pocket GameBoy)


;***************************************************************************
;*
;* Cart related
;*
;***************************************************************************

; $0143 Color GameBoy compatibility code
CART_COMPATIBLE_DMG     EQU $00
CART_COMPATIBLE_DMG_GBC EQU $80
CART_COMPATIBLE_GBC     EQU $C0

; $0146 GameBoy/Super GameBoy indicator
CART_INDICATOR_GB       EQU $00
CART_INDICATOR_SGB      EQU $03

; $0147 Cartridge type
CART_ROM                     EQU $00
CART_ROM_MBC1                EQU $01
CART_ROM_MBC1_RAM            EQU $02
CART_ROM_MBC1_RAM_BAT        EQU $03
CART_ROM_MBC2                EQU $05
CART_ROM_MBC2_BAT            EQU $06
CART_ROM_RAM                 EQU $08
CART_ROM_RAM_BAT             EQU $09
CART_ROM_MMM01               EQU $0B
CART_ROM_MMM01_RAM           EQU $0C
CART_ROM_MMM01_RAM_BAT       EQU $0D
CART_ROM_MBC3_BAT_RTC        EQU $0F
CART_ROM_MBC3_RAM_BAT_RTC    EQU $10
CART_ROM_MBC3                EQU $11
CART_ROM_MBC3_RAM            EQU $12
CART_ROM_MBC3_RAM_BAT        EQU $13
CART_ROM_MBC5                EQU $19
CART_ROM_MBC5_BAT            EQU $1A
CART_ROM_MBC5_RAM_BAT        EQU $1B
CART_ROM_MBC5_RUMBLE         EQU $1C
CART_ROM_MBC5_RAM_RUMBLE     EQU $1D
CART_ROM_MBC5_RAM_BAT_RUMBLE EQU $1E
CART_ROM_MBC7_RAM_BAT_GYRO   EQU $22
CART_ROM_POCKET_CAMERA       EQU $FC
CART_ROM_BANDAI_TAMA5        EQU $FD
CART_ROM_HUDSON_HUC3         EQU $FE
CART_ROM_HUDSON_HUC1         EQU $FF

; $0148 ROM size
CART_ROM_256K EQU $00 ; 2 banks
CART_ROM_512K EQU $01 ; 4 banks
CART_ROM_1M   EQU $02 ; 8 banks
CART_ROM_2M   EQU $03 ; 16 banks
CART_ROM_4M   EQU $04 ; 32 banks
CART_ROM_8M   EQU $05 ; 64 banks
CART_ROM_16M  EQU $06 ; 128 banks
CART_ROM_32M  EQU $07 ; 256 banks
CART_ROM_64M  EQU $08 ; 512 banks
CART_ROM_9M   EQU $52 ; 72 banks
CART_ROM_10M  EQU $53 ; 80 banks
CART_ROM_12M  EQU $54 ; 96 banks

; $0149 RAM size
CART_RAM_NONE EQU 0
CART_RAM_16K  EQU 1 ; 1 incomplete bank
CART_RAM_64K  EQU 2 ; 1 bank
CART_RAM_256K EQU 3 ; 4 banks
CART_RAM_1M   EQU 4 ; 16 banks

CART_RAM_ENABLE  EQU $0A
CART_RAM_DISABLE EQU $00

; $014A Destination code
CART_DEST_JAPANESE     EQU $00
CART_DEST_NON_JAPANESE EQU $01


;***************************************************************************
;*
;* Keypad related
;*
;***************************************************************************

PADF_DOWN   EQU $80
PADF_UP     EQU $40
PADF_LEFT   EQU $20
PADF_RIGHT  EQU $10
PADF_START  EQU $08
PADF_SELECT EQU $04
PADF_B      EQU $02
PADF_A      EQU $01

PADB_DOWN   EQU $7
PADB_UP     EQU $6
PADB_LEFT   EQU $5
PADB_RIGHT  EQU $4
PADB_START  EQU $3
PADB_SELECT EQU $2
PADB_B      EQU $1
PADB_A      EQU $0


;***************************************************************************
;*
;* Screen related
;*
;***************************************************************************

SCRN_X    EQU 160 ; Width of screen in pixels
SCRN_Y    EQU 144 ; Height of screen in pixels
SCRN_X_B  EQU 20  ; Width of screen in bytes
SCRN_Y_B  EQU 18  ; Height of screen in bytes

SCRN_VX   EQU 256 ; Virtual width of screen in pixels
SCRN_VY   EQU 256 ; Virtual height of screen in pixels
SCRN_VX_B EQU 32  ; Virtual width of screen in bytes
SCRN_VY_B EQU 32  ; Virtual height of screen in bytes

;*
;* Nintendo scrolling logo
;* (Code won't work on a real GameBoy)
;* (if next lines are altered.)
NINTENDO_LOGO : MACRO
    DB  $CE,$ED,$66,$66,$CC,$0D,$00,$0B,$03,$73,$00,$83,$00,$0C,$00,$0D
    DB  $00,$08,$11,$1F,$88,$89,$00,$0E,$DC,$CC,$6E,$E6,$DD,$DD,$D9,$99
    DB  $BB,$BB,$67,$63,$6E,$0E,$EC,$CC,$DD,$DC,$99,$9F,$BB,$B9,$33,$3E
ENDM

    ENDC ;HARDWARE_INC
