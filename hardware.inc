;******************************************************************************
; Game Boy hardware constant definitions
; https://github.com/gbdev/hardware.inc
;******************************************************************************

; To the extent possible under law, the authors of this work have
; waived all copyright and related or neighboring rights to the work.
; See https://creativecommons.org/publicdomain/zero/1.0/ for details.
; SPDX-License-Identifier: CC0-1.0

; If this file was already included, don't do it again
if !def(HARDWARE_INC)

; Check for the minimum supported RGBDS version
if !def(__RGBDS_MAJOR__) || !def(__RGBDS_MINOR__) || !def(__RGBDS_PATCH__)
    fail "This version of 'hardware.inc' requires RGBDS version 0.5.0 or later"
endc
if __RGBDS_MAJOR__ == 0 && __RGBDS_MINOR__ < 5
    fail "This version of 'hardware.inc' requires RGBDS version 0.5.0 or later."
endc

; Define the include guard and the current hardware.inc version
; (do this after the RGBDS version check since the `def` syntax depends on it)
def HARDWARE_INC equ 1
def HARDWARE_INC_VERSION equs "4.10.0"

; Usage: rev_Check_hardware_inc <min_ver>
; Examples:
;     rev_Check_hardware_inc 1.2.3
;     rev_Check_hardware_inc 1.2   (equivalent to 1.2.0)
;     rev_Check_hardware_inc 1     (equivalent to 1.0.0)
MACRO rev_Check_hardware_inc
    def hw_inc_cur_ver\@ equs strrpl("{HARDWARE_INC_VERSION}", ".", ",")
    def hw_inc_min_ver\@ equs strrpl("\1", ".", ",")
    def hw_inc_def_check\@ equs """MACRO hw_inc_check\@
        if \\1 != \\4 || (\\2 < \\5 || (\\2 == \\5 && \\3 < \\6))
            fail "Version \\1.\\2.\\3 of 'hardware.inc' is incompatible with requested version \\4.\\5.\\6"
        endc
    \nENDM"""
    hw_inc_def_check\@
    hw_inc_check\@ {hw_inc_cur_ver\@}, {hw_inc_min_ver\@}, 0, 0
    purge hw_inc_cur_ver\@, hw_inc_min_ver\@, hw_inc_def_check\@, hw_inc_check\@
ENDM


;******************************************************************************
; Memory-mapped registers ($FFxx range)
;******************************************************************************

; -- JOYP / P1 ($FF00) --------------------------------------------------------
; Joypad face buttons
def rJOYP equ $FF00

def JOYPB_GET_BTN  equ 5 ; 0 = reading buttons     [r/w]
def JOYPB_GET_DPAD equ 4 ; 0 = reading Control Pad [r/w]
    def JOYPF_GET equ %00_11_0000 ; select which inputs to read from the lower nybble
        def JOYP_GET_BTN  equ %00_01_0000 ; reading A/B/Select/Start buttons
        def JOYP_GET_DPAD equ %00_10_0000 ; reading Control Pad directions
        def JOYP_GET_NONE equ %00_11_0000 ; reading nothing

def JOYPB_START  equ 3 ; 0 = Start is pressed  (if reading buttons)     [ro]
def JOYPB_SELECT equ 2 ; 0 = Select is pressed (if reading buttons)     [ro]
def JOYPB_B      equ 1 ; 0 = B is pressed      (if reading buttons)     [ro]
def JOYPB_A      equ 0 ; 0 = A is pressed      (if reading buttons)     [ro]
def JOYPB_DOWN   equ 3 ; 0 = Down is pressed   (if reading Control Pad) [ro]
def JOYPB_UP     equ 2 ; 0 = Up is pressed     (if reading Control Pad) [ro]
def JOYPB_LEFT   equ 1 ; 0 = Left is pressed   (if reading Control Pad) [ro]
def JOYPB_RIGHT  equ 0 ; 0 = Right is pressed  (if reading Control Pad) [ro]
    def JOYPF_INPUTS equ %0000_1111
    def JOYPF_START  equ 1 << JOYPB_START
    def JOYPF_SELECT equ 1 << JOYPB_SELECT
    def JOYPF_B      equ 1 << JOYPB_B
    def JOYPF_A      equ 1 << JOYPB_A
    def JOYPF_DOWN   equ 1 << JOYPB_DOWN
    def JOYPF_UP     equ 1 << JOYPB_UP
    def JOYPF_LEFT   equ 1 << JOYPB_LEFT
    def JOYPF_RIGHT  equ 1 << JOYPB_RIGHT

; Combined input byte, with Control Pad in high nybble (conventional order)
def PADB_DOWN   equ 7
def PADB_UP     equ 6
def PADB_LEFT   equ 5
def PADB_RIGHT  equ 4
def PADB_START  equ 3
def PADB_SELECT equ 2
def PADB_B      equ 1
def PADB_A      equ 0
    def PADF_DOWN   equ 1 << PADB_DOWN
    def PADF_UP     equ 1 << PADB_UP
    def PADF_LEFT   equ 1 << PADB_LEFT
    def PADF_RIGHT  equ 1 << PADB_RIGHT
    def PADF_START  equ 1 << PADB_START
    def PADF_SELECT equ 1 << PADB_SELECT
    def PADF_B      equ 1 << PADB_B
    def PADF_A      equ 1 << PADB_A

; Combined input byte, with Control Pad in low nybble (swapped order)
def PADB_SWAP_START  equ 7
def PADB_SWAP_SELECT equ 6
def PADB_SWAP_B      equ 5
def PADB_SWAP_A      equ 4
def PADB_SWAP_DOWN   equ 3
def PADB_SWAP_UP     equ 2
def PADB_SWAP_LEFT   equ 1
def PADB_SWAP_RIGHT  equ 0
    def PADF_SWAP_START  equ 1 << PADB_SWAP_START
    def PADF_SWAP_SELECT equ 1 << PADB_SWAP_SELECT
    def PADF_SWAP_B      equ 1 << PADB_SWAP_B
    def PADF_SWAP_A      equ 1 << PADB_SWAP_A
    def PADF_SWAP_DOWN   equ 1 << PADB_SWAP_DOWN
    def PADF_SWAP_UP     equ 1 << PADB_SWAP_UP
    def PADF_SWAP_LEFT   equ 1 << PADB_SWAP_LEFT
    def PADF_SWAP_RIGHT  equ 1 << PADB_SWAP_RIGHT

; -- SB ($FF01) ---------------------------------------------------------------
; Serial transfer data [r/w]
def rSB equ $FF01

; -- SC ($FF02) ---------------------------------------------------------------
; Serial transfer control
def rSC equ $FF02

def SCB_START  equ 7 ; reading 1 = transfer in progress, writing 1 = start transfer        [r/w]
def SCB_SPEED  equ 1 ; (CGB only) 1 = use faster internal clock                            [r/w]
def SCB_SOURCE equ 0 ; 0 = use external clock ("slave"), 1 = use internal clock ("master") [r/w]
    def SCF_START  equ 1 << SCB_START
    def SCF_SPEED  equ 1 << SCB_SPEED
        def SC_SLOW equ 0 << SCB_SPEED
        def SC_FAST equ 1 << SCB_SPEED
    def SCF_SOURCE equ 1 << SCB_SOURCE
        def SC_EXTERNAL equ 0 << SCB_SOURCE
        def SC_INTERNAL equ 1 << SCB_SOURCE

; -- $FF03 is unused ----------------------------------------------------------

; -- DIV ($FF04) --------------------------------------------------------------
; Divider register [r/w]
def rDIV equ $FF04

; -- TIMA ($FF05) -------------------------------------------------------------
; Timer counter [r/w]
def rTIMA equ $FF05

; -- TMA ($FF06) --------------------------------------------------------------
; Timer modulo [r/w]
def rTMA equ $FF06

; -- TAC ($FF07) --------------------------------------------------------------
; Timer control
def rTAC equ $FF07

def TACB_START equ 2 ; enable incrementing TIMA [r/w]
    def TACF_STOP  equ 0 << TACB_START
    def TACF_START equ 1 << TACB_START

def TACF_CLOCK equ %000000_11 ; the frequency at which TIMER_CNT increments [r/w]
    def TACF_4KHZ   equ %000000_00 ; every 256 M-cycles = ~4 KHz on DMG
    def TACF_262KHZ equ %000000_01 ; every 4 M-cycles = ~262 KHz on DMG
    def TACF_65KHZ  equ %000000_10 ; every 16 M-cycles = ~65 KHz on DMG
    def TACF_16KHZ  equ %000000_11 ; every 64 M-cycles = ~16 KHz on DMG

; -- $FF08-$FF0E are unused ---------------------------------------------------

; -- IF ($FF0F) ---------------------------------------------------------------
; Pending interrupts
def rIF equ $FF0F

def IFB_JOYPAD equ 4 ; 1 = joypad interrupt is pending [r/w]
def IFB_SERIAL equ 3 ; 1 = serial interrupt is pending [r/w]
def IFB_TIMER  equ 2 ; 1 = timer  interrupt is pending [r/w]
def IFB_STAT   equ 1 ; 1 = STAT   interrupt is pending [r/w]
def IFB_VBLANK equ 0 ; 1 = VBlank interrupt is pending [r/w]
    def IFF_JOYPAD equ 1 << IFB_JOYPAD
    def IFF_SERIAL equ 1 << IFB_SERIAL
    def IFF_TIMER  equ 1 << IFB_TIMER
    def IFF_STAT   equ 1 << IFB_STAT
    def IFF_VBLANK equ 1 << IFB_VBLANK

; -- AUD1SWEEP / NR10 ($FF10) -------------------------------------------------
; Audio channel 1 sweep
def rAUD1SWEEP equ $FF10

def AUD1SWEEPF_TIME equ %0_111_0000 ; how long between sweep iterations
                                    ; (in 128 Hz ticks, ~7.8 ms apart) [r/w]

def AUD1SWEEPB_DIR equ 3 ; sweep direction [r/w]
    def AUD1SWEEPF_DIR  equ 1 << AUD1SWEEPB_DIR
        def AUD1SWEEP_UP   equ 0 << AUD1SWEEPB_DIR
        def AUD1SWEEP_DOWN equ 1 << AUD1SWEEPB_DIR

def AUD1SWEEP_SHIFT equ %00000_111 ; how much the period increases/decreases per iteration [r/w]

; -- AUD1LEN / NR11 ($FF11) ---------------------------------------------------
; Audio channel 1 length timer and duty cycle
def rAUD1LEN equ $FF11

; These values are also applicable to AUD2LEN
def AUDLENF_DUTY equ %11_000000 ; ratio of time spent high vs. time spent low [r/w]
    def AUDLEN_DUTY_12_5 equ %00_000000 ; 12.5%
    def AUDLEN_DUTY_25   equ %01_000000 ; 25%
    def AUDLEN_DUTY_50   equ %10_000000 ; 50%
    def AUDLEN_DUTY_75   equ %11_000000 ; 75%

; This value is also applicable to AUD2LEN and AUD4LEN
def AUDLENF_TIMER equ %00_111111 ; initial length timer (0-63) [wo]

; -- AUD1ENV / NR12 ($FF12) ---------------------------------------------------
; Audio channel 1 volume and envelope
def rAUD1ENV equ $FF12

; Values are also applicable to AUD2ENV and AUD4ENV

def AUDENVF_INIT_VOL equ %1111_0000 ; initial volume [r/w]

def AUDENVB_DIR equ 3 ; direction of volume envelope [r/w]
    def AUDENVF_DIR equ 1 << AUDENVB_DIR
        def AUDENV_DOWN equ 0 << AUDENVB_DIR
        def AUDENV_UP   equ 1 << AUDENVB_DIR

def AUDENVF_PACE equ %00000_111 ; how long between envelope iterations
                                ; (in 64 Hz ticks, ~15.6 ms apart) [r/w]

; -- AUD1LOW / NR13 ($FF13) ---------------------------------------------------
; Audio channel 1 period (low 8 bits) [rw]
def rAUD1LOW equ $FF13

; -- AUD1HIGH / NR14 ($FF14) --------------------------------------------------
; Audio channel 1 period (high 3 bits) and control
def rAUD1HIGH equ $FF14

; Values are also applicable to AUD2HIGH and AUD3HIGH

def AUDHIGHB_RESTART    equ 7 ; 1 = restart the channel [wo]
def AUDHIGHB_LEN_ENABLE equ 6 ; 1 = reset the channel after the length timer expires [rw]
    def AUDHIGH_RESTART    equ 1 << AUDHIGHB_RESTART
    def AUDHIGH_LENGTH_OFF equ 0 << AUDHIGHB_LEN_ENABLE
    def AUDHIGH_LENGTH_ON  equ 1 << AUDHIGHB_LEN_ENABLE

def AUDHIGHF_PERIOD_HIGH equ %00000_111 ; upper 3 bits of the channel's period [rw]

; -- $FF15 is unused ----------------------------------------------------------

; -- AUD2LEN / NR21 ($FF16) ---------------------------------------------------
; Audio channel 2 length timer and duty cycle
def rAUD2LEN equ $FF16

; Values are reused from AUD1LEN

; -- AUD2ENV / NR22 ($FF17) ---------------------------------------------------
; Audio channel 2 volume and envelope
def rAUD2ENV equ $FF17

; Values are reused from AUD1ENV

; -- AUD2LOW / NR23 ($FF18) ---------------------------------------------------
; Audio channel 2 period (low 8 bits) [rw]
def rAUD2LOW equ $FF18

; -- AUD2HIGH / NR24 ($FF19) --------------------------------------------------
; Audio channel 2 period (high 3 bits) and control
def rAUD2HIGH equ $FF19

; Values are reused from AUD1HIGH

; -- AUD3ENA / NR30 ($FF1A) ---------------------------------------------------
; Audio channel 3 enable
def rAUD3ENA equ $FF1A

def AUD3ENAB_ENABLE equ 7 ; 1 = channel is active [rw]
    def AUD3ENA_OFF equ 0 << AUD3ENAB_ENABLE
    def AUD3ENA_ON  equ 1 << AUD3ENAB_ENABLE

; -- AUD3LEN / NR31 ($FF1B) ---------------------------------------------------
; Audio channel 3 length timer [wo]
def rAUD3LEN equ $FF1B

; -- AUD3LEVEL / NR32 ($FF1C) -------------------------------------------------
; Audio channel 3 volume
def rAUD3LEVEL equ $FF1C

def AUD3LEVELF_VOLUME equ %0_11_00000 ; volume level [rw]
    def AUD3LEVEL_MUTE equ %0_00_00000 ; 0% (muted)
    def AUD3LEVEL_100  equ %0_01_00000 ; 100%
    def AUD3LEVEL_50   equ %0_10_00000 ; 50%
    def AUD3LEVEL_25   equ %0_11_00000 ; 25%

; -- AUD3LOW / NR33 ($FF1D) ---------------------------------------------------
; Audio channel 3 period (low 8 bits) [rw]
def rAUD3LOW equ $FF1D

; -- AUD3HIGH / NR34 ($FF1E) --------------------------------------------------
; Audio channel 3 period (high 3 bits) and control
def rAUD3HIGH equ $FF1E

; Values are reused from AUD1HIGH

; -- $FF1F is unused ----------------------------------------------------------

; -- AUD4LEN / NR41 ($FF20) ---------------------------------------------------
; Audio channel 4 length timer [wo]
def rAUD4LEN equ $FF20

; AUDLENF_TIMER value is reused from AUD1LEN

; -- AUD4ENV / NR42 ($FF21) ---------------------------------------------------
; Audio channel 4 volume and envelope
def rAUD4ENV equ $FF21

; Values are reused from AUD1ENV

; -- AUD4POLY / NR43 ($FF22) --------------------------------------------------
; Audio channel 4 period and randomness
def rAUD4POLY equ $FF22

def AUD4POLYF_SHIFT equ %1111_0000 ; coarse control of the channel's period [rw]

def AUD4POLYB_WIDTH equ 3 ; controls the noise generator (LFSR)'s step width [rw]
    def AUD4POLY_15STEP equ 0 << AUD4POLYB_WIDTH
    def AUD4POLY_7STEP  equ 1 << AUD4POLYB_WIDTH

def AUD4POLYF_DIV equ %00000_111 ; fine control of the channel's period [rw]

; -- AUD4GO / NR44 ($FF23) ----------------------------------------------------
; Audio channel 4 control
def rAUD4GO equ $FF23

def AUD4GOB_RESTART    equ 7 ; 1 = restart the channel [wo]
def AUD4GOB_LEN_ENABLE equ 6 ; 1 = reset the channel after the length timer expires [rw]
    def AUD4GO_RESTART    equ 1 << AUD4GOB_RESTART
    def AUD4GO_LENGTH_OFF equ 0 << AUD4GOB_LEN_ENABLE
    def AUD4GO_LENGTH_ON  equ 1 << AUD4GOB_LEN_ENABLE

; -- AUDVOL / NR50 ($FF24) ----------------------------------------------------
; Audio master volume and VIN mixer
def rAUDVOL equ $FF24

def AUDVOLB_VIN_LEFT  equ 7 ; 1 = output VIN to left ear (SO2, speaker 2) [rw]
    def AUDVOL_VIN_LEFT equ 1 << AUDVOLB_VIN_LEFT

def AUDVOLF_LEFT equ %0_111_0000 ; 0 = barely audible, 7 = full volume [rw]

def AUDVOLB_VIN_RIGHT equ 3 ; 1 = output VIN to right ear (SO1, speaker 1) [rw]
    def AUDVOL_VIN_RIGHT equ 1 << AUDVOLB_VIN_RIGHT

def AUDVOLF_RIGHT equ %00000_111 ; 0 = barely audible, 7 = full volume [rw]

; -- AUDTERM / NR51 ($FF25) ---------------------------------------------------
; Audio channel mixer
def rAUDTERM equ $FF25

def AUDTERMB_4_LEFT  equ 7 ; 1 = output channel 4 to left  ear [rw]
def AUDTERMB_3_LEFT  equ 6 ; 1 = output channel 3 to left  ear [rw]
def AUDTERMB_2_LEFT  equ 5 ; 1 = output channel 2 to left  ear [rw]
def AUDTERMB_1_LEFT  equ 4 ; 1 = output channel 1 to left  ear [rw]
def AUDTERMB_4_RIGHT equ 3 ; 1 = output channel 4 to right ear [rw]
def AUDTERMB_3_RIGHT equ 2 ; 1 = output channel 3 to right ear [rw]
def AUDTERMB_2_RIGHT equ 1 ; 1 = output channel 2 to right ear [rw]
def AUDTERMB_1_RIGHT equ 0 ; 1 = output channel 1 to right ear [rw]
    def AUDTERM_4_LEFT  equ 1 << AUDTERMB_4_LEFT
    def AUDTERM_3_LEFT  equ 1 << AUDTERMB_3_LEFT
    def AUDTERM_2_LEFT  equ 1 << AUDTERMB_2_LEFT
    def AUDTERM_1_LEFT  equ 1 << AUDTERMB_1_LEFT
    def AUDTERM_4_RIGHT equ 1 << AUDTERMB_4_RIGHT
    def AUDTERM_3_RIGHT equ 1 << AUDTERMB_3_RIGHT
    def AUDTERM_2_RIGHT equ 1 << AUDTERMB_2_RIGHT
    def AUDTERM_1_RIGHT equ 1 << AUDTERMB_1_RIGHT

; -- AUDENA / NR52 ($FF26) ----------------------------------------------------
; Audio master enable
def rAUDENA equ $FF26

def AUDENAB_ENABLE     equ 7 ; 0 = disable the APU, saving power (resets all audio registers to 0!) [r/w]
def AUDENAB_ENABLE_CH4 equ 3 ; 1 = channel 4 is running [ro]
def AUDENAB_ENABLE_CH3 equ 2 ; 1 = channel 3 is running [ro]
def AUDENAB_ENABLE_CH2 equ 1 ; 1 = channel 2 is running [ro]
def AUDENAB_ENABLE_CH1 equ 0 ; 1 = channel 1 is running [ro]
    def AUDENA_OFF      equ 0 << AUDENAB_ENABLE
    def AUDENA_ON       equ 1 << AUDENAB_ENABLE
    def AUDENAF_CH4_OFF equ 0 << AUDENAB_ENABLE_CH4
    def AUDENAF_CH4_ON  equ 1 << AUDENAB_ENABLE_CH4
    def AUDENAF_CH3_OFF equ 0 << AUDENAB_ENABLE_CH3
    def AUDENAF_CH3_ON  equ 1 << AUDENAB_ENABLE_CH3
    def AUDENAF_CH2_OFF equ 0 << AUDENAB_ENABLE_CH2
    def AUDENAF_CH2_ON  equ 1 << AUDENAB_ENABLE_CH2
    def AUDENAF_CH1_OFF equ 0 << AUDENAB_ENABLE_CH1
    def AUDENAF_CH1_ON  equ 1 << AUDENAB_ENABLE_CH1

; -- $FF27-$FF2F are unused ---------------------------------------------------

; -- AUD3WAVE ($FF30-$FF3F) ---------------------------------------------------
; Audio channel 3 wave pattern RAM
def _AUD3WAVERAM equ $FF30 ; $FF30-$FF3F

def rAUD3WAVE_0 equ $FF30
def rAUD3WAVE_1 equ $FF31
def rAUD3WAVE_2 equ $FF32
def rAUD3WAVE_3 equ $FF33
def rAUD3WAVE_4 equ $FF34
def rAUD3WAVE_5 equ $FF35
def rAUD3WAVE_6 equ $FF36
def rAUD3WAVE_7 equ $FF37
def rAUD3WAVE_8 equ $FF38
def rAUD3WAVE_9 equ $FF39
def rAUD3WAVE_A equ $FF3A
def rAUD3WAVE_B equ $FF3B
def rAUD3WAVE_C equ $FF3C
def rAUD3WAVE_D equ $FF3D
def rAUD3WAVE_E equ $FF3E
def rAUD3WAVE_F equ $FF3F

; -- LCDC ($FF40) -------------------------------------------------------------
; LCD graphics control
def rLCDC equ $FF40

def LCDCF_OFF     equ %00000000 ; LCD Control Operation
def LCDCF_ON      equ %10000000 ; LCD Control Operation
def LCDCF_WIN9800 equ %00000000 ; Window Tile Map Display Select
def LCDCF_WIN9C00 equ %01000000 ; Window Tile Map Display Select
def LCDCF_WINOFF  equ %00000000 ; Window Display
def LCDCF_WINON   equ %00100000 ; Window Display
def LCDCF_BLK21   equ %00000000 ; BG & Window Tile Data Select
def LCDCF_BLK01   equ %00010000 ; BG & Window Tile Data Select
def LCDCF_BG9800  equ %00000000 ; BG Tile Map Display Select
def LCDCF_BG9C00  equ %00001000 ; BG Tile Map Display Select
def LCDCF_OBJ8    equ %00000000 ; OBJ Construction
def LCDCF_OBJ16   equ %00000100 ; OBJ Construction
def LCDCF_OBJOFF  equ %00000000 ; OBJ Display
def LCDCF_OBJON   equ %00000010 ; OBJ Display
def LCDCF_BGOFF   equ %00000000 ; BG Display
def LCDCF_BGON    equ %00000001 ; BG Display

def LCDCB_ON      equ 7 ; LCD Control Operation
def LCDCB_WIN9C00 equ 6 ; Window Tile Map Display Select
def LCDCB_WINON   equ 5 ; Window Display
def LCDCB_BLKS    equ 4 ; BG & Window Tile Data Select
def LCDCB_BG9C00  equ 3 ; BG Tile Map Display Select
def LCDCB_OBJ16   equ 2 ; OBJ Construction
def LCDCB_OBJON   equ 1 ; OBJ Display
def LCDCB_BGON    equ 0 ; BG Display
; "Window Character Data Select" follows BG


; --
; -- STAT ($FF41)
; -- LCDC Status   (R/W)
; --
def rSTAT equ $FF41

def STATF_LYC     equ  %01000000 ; LYC=LY Coincidence (Selectable)
def STATF_MODE10  equ  %00100000 ; Mode 10
def STATF_MODE01  equ  %00010000 ; Mode 01 (V-Blank)
def STATF_MODE00  equ  %00001000 ; Mode 00 (H-Blank)
def STATF_LYCF    equ  %00000100 ; Coincidence Flag
def STATF_HBL     equ  %00000000 ; H-Blank
def STATF_VBL     equ  %00000001 ; V-Blank
def STATF_OAM     equ  %00000010 ; OAM-RAM is used by system
def STATF_LCD     equ  %00000011 ; Both OAM and VRAM used by system
def STATF_BUSY    equ  %00000010 ; When set, VRAM access is unsafe

def STATB_LYC     equ  6
def STATB_MODE10  equ  5
def STATB_MODE01  equ  4
def STATB_MODE00  equ  3
def STATB_LYCF    equ  2
def STATB_BUSY    equ  1

; --
; -- SCY ($FF42)
; -- Scroll Y (R/W)
; --
def rSCY equ $FF42


; --
; -- SCX ($FF43)
; -- Scroll X (R/W)
; --
def rSCX equ $FF43


; --
; -- LY ($FF44)
; -- LCDC Y-Coordinate (R)
; --
; -- Values range from 0-153. 144-153 is the VBlank period.
; --
def rLY equ $FF44


; --
; -- LYC ($FF45)
; -- LY Compare (R/W)
; --
; -- When LY==LYC, STATF_LYCF will be set in STAT
; --
def rLYC equ $FF45


; --
; -- DMA ($FF46)
; -- DMA Transfer and Start Address (W)
; --
def rDMA equ $FF46


; --
; -- BGP ($FF47)
; -- BG Palette Data (W)
; --
; -- Bit 7-6 - Intensity for %11
; -- Bit 5-4 - Intensity for %10
; -- Bit 3-2 - Intensity for %01
; -- Bit 1-0 - Intensity for %00
; --
def rBGP equ $FF47


; --
; -- OBP0 ($FF48)
; -- Object Palette 0 Data (W)
; --
; -- See BGP for info
; --
def rOBP0 equ $FF48


; --
; -- OBP1 ($FF49)
; -- Object Palette 1 Data (W)
; --
; -- See BGP for info
; --
def rOBP1 equ $FF49


; --
; -- WY ($FF4A)
; -- Window Y Position (R/W)
; --
; -- 0 <= WY <= 143
; -- When WY = 0, the window is displayed from the top edge of the LCD screen.
; --
def rWY equ $FF4A


; --
; -- WX ($FF4B)
; -- Window X Position (R/W)
; --
; -- 7 <= WX <= 166
; -- When WX = 7, the window is displayed from the left edge of the LCD screen.
; -- Values of 0-6 and 166 are unreliable due to hardware bugs.
; --
def rWX equ $FF4B

def WX_OFS equ 7 ; add this to a screen position to get a WX position


; --
; -- SPEED ($FF4D)
; -- Select CPU Speed (R/W)
; --
def rKEY1 equ $FF4D
def rSPD  equ rKEY1

def KEY1F_DBLSPEED equ %10000000 ; 0=Normal Speed, 1=Double Speed (R)
def KEY1F_PREPARE  equ %00000001 ; 0=No, 1=Prepare (R/W)


; --
; -- VBK ($FF4F)
; -- Select Video RAM Bank (R/W)
; --
; -- Bit 0 - Bank Specification (0: Specify Bank 0; 1: Specify Bank 1)
; --
def rVBK equ $FF4F


; --
; -- HDMA1 ($FF51)
; -- High byte for Horizontal Blanking/General Purpose DMA source address (W)
; -- CGB Mode Only
; --
def rHDMA1 equ $FF51


; --
; -- HDMA2 ($FF52)
; -- Low byte for Horizontal Blanking/General Purpose DMA source address (W)
; -- CGB Mode Only
; --
def rHDMA2 equ $FF52


; --
; -- HDMA3 ($FF53)
; -- High byte for Horizontal Blanking/General Purpose DMA destination address (W)
; -- CGB Mode Only
; --
def rHDMA3 equ $FF53


; --
; -- HDMA4 ($FF54)
; -- Low byte for Horizontal Blanking/General Purpose DMA destination address (W)
; -- CGB Mode Only
; --
def rHDMA4 equ $FF54


; --
; -- HDMA5 ($FF55)
; -- Transfer length (in tiles minus 1)/mode/start for Horizontal Blanking, General Purpose DMA (R/W)
; -- CGB Mode Only
; --
def rHDMA5 equ $FF55

def HDMA5F_MODE_GP  equ %00000000 ; General Purpose DMA (W)
def HDMA5F_MODE_HBL equ %10000000 ; HBlank DMA (W)
def HDMA5B_MODE equ 7 ; DMA mode select (W)

; -- Once DMA has started, use HDMA5F_BUSY to check when the transfer is complete
def HDMA5F_BUSY equ %10000000 ; 0=Busy (DMA still in progress), 1=Transfer complete (R)


; --
; -- RP ($FF56)
; -- Infrared Communications Port (R/W)
; -- CGB Mode Only
; --
def rRP equ $FF56

def RPF_ENREAD   equ %11000000
def RPF_DATAIN   equ %00000010 ; 0=Receiving IR Signal, 1=Normal
def RPF_WRITE_HI equ %00000001
def RPF_WRITE_LO equ %00000000

def RPB_LED_ON   equ 0
def RPB_DATAIN   equ 1


; --
; -- BCPS/BGPI ($FF68)
; -- Background Color Palette Specification (aka Background Palette Index) (R/W)
; --
def rBCPS equ $FF68
def rBGPI equ rBCPS

def BCPSF_AUTOINC equ %10000000 ; Auto Increment (0=Disabled, 1=Increment after Writing)
def BCPSB_AUTOINC equ 7
def BGPIF_AUTOINC equ BCPSF_AUTOINC
def BGPIB_AUTOINC equ BCPSB_AUTOINC


; --
; -- BCPD/BGPD ($FF69)
; -- Background Color Palette Data (aka Background Palette Data) (R/W)
; --
def rBCPD equ $FF69
def rBGPD equ rBCPD


; --
; -- OCPS/OBPI ($FF6A)
; -- Object Color Palette Specification (aka Object Background Palette Index) (R/W)
; --
def rOCPS equ $FF6A
def rOBPI equ rOCPS

def OCPSF_AUTOINC equ %10000000 ; Auto Increment (0=Disabled, 1=Increment after Writing)
def OCPSB_AUTOINC equ 7
def OBPIF_AUTOINC equ OCPSF_AUTOINC
def OBPIB_AUTOINC equ OCPSB_AUTOINC


; --
; -- OCPD/OBPD ($FF6B)
; -- Object Color Palette Data (aka Object Background Palette Data) (R/W)
; --
def rOCPD equ $FF6B
def rOBPD equ rOCPD


; --
; -- OPRI ($FF6C)
; -- Object Priority Mode (R/W)
; -- CGB Only

; --
; -- Priority can be changed only from the boot ROM
; --
def rOPRI equ $FF6C

def OPRI_OAM   equ 0 ; Prioritize objects by location in OAM (CGB Mode default)
def OPRI_COORD equ 1 ; Prioritize objects by x-coordinate (Non-CGB Mode default)



; --
; -- SMBK/SVBK ($FF70)
; -- Select Main RAM Bank (R/W)
; --
; -- Bit 2-0 - Bank Specification (0,1: Specify Bank 1; 2-7: Specify Banks 2-7)
; --
def rSVBK equ $FF70
def rSMBK equ rSVBK


; --
; -- PCM12 ($FF76)
; -- Sound channel 1&2 PCM amplitude (R)
; --
; -- Bit 7-4 - Copy of sound channel 2's PCM amplitude
; -- Bit 3-0 - Copy of sound channel 1's PCM amplitude
; --
def rPCM12 equ $FF76


; --
; -- PCM34 ($FF77)
; -- Sound channel 3&4 PCM amplitude (R)
; --
; -- Bit 7-4 - Copy of sound channel 4's PCM amplitude
; -- Bit 3-0 - Copy of sound channel 3's PCM amplitude
; --
def rPCM34 equ $FF77


; --
; -- IE ($FFFF)
; -- Interrupt Enable (R/W)
; --
def rIE equ $FFFF

def IEF_JOYPAD equ %00010000 ; Transition from High to Low of Pin number P10-P13
def IEF_SERIAL equ %00001000 ; Serial I/O transfer end
def IEF_TIMER  equ %00000100 ; Timer Overflow
def IEF_STAT   equ %00000010 ; STAT
def IEF_VBLANK equ %00000001 ; V-Blank

def IEB_JOYPAD equ 4
def IEB_SERIAL equ 3
def IEB_TIMER  equ 2
def IEB_STAT   equ 1
def IEB_VBLANK equ 0


;******************************************************************************
; Memory regions
;******************************************************************************

; Prefer `STARTOF(<section type>)` when the value can be determined at link time
def _ROM     equ $0000 ; $0000-$3FFF / $0000-$7FFF (prefer `STARTOF(ROM0)`)
def _ROMBANK equ $4000 ; $4000-$7FFF               (prefer `STARTOF(ROMX)`)
def _VRAM    equ $8000 ; $8000-$9FFF               (prefer `STARTOF(VRAM)`)
def _SRAM    equ $A000 ; $A000-$BFFF               (prefer `STARTOF(SRAM)`)
def _RAM     equ $C000 ; $C000-$CFFF / $C000-$DFFF (prefer `STARTOF(WRAM0)`)
def _RAMBANK equ $D000 ; $D000-$DFFF               (prefer `STARTOF(WRAMX)`)
def _OAMRAM  equ $FE00 ; $FE00-$FE9F               (prefer `STARTOF(OAM)`)
def _IO      equ $FF00 ; $FF00-$FF7F, $FFFF
def _HRAM    equ $FF80 ; $FF80-$FFFE               (prefer `STARTOF(HRAM)`)


;******************************************************************************
; Cartridge registers (MBC)
;******************************************************************************

; -- RAMG ($0000-$1FFF) -------------------------------------------------------
; RAM enable [w]
def rRAMG equ $0000

; Common values
def CART_SRAM_ENABLE  equ $0A
def CART_SRAM_DISABLE equ $00

; MBC3-specific values
def RTC_S  equ $08 ; seconds counter (0-59)
def RTC_M  equ $09 ; minutes counter (0-59)
def RTC_H  equ $0A ; hours counter (0-23)
def RTC_DL equ $0B ; days counter, low byte (0-255)
def RTC_DH equ $0C ; days counter, high bit and other flags
    def RTC_DHB_OVERFLOW equ 7 ; 1 = days counter overflowed    [w]
    def RTC_DHB_HALT     equ 6 ; 0 = run timer, 1 = stop timer  [w]
    def RTC_DHB_HIGH     equ 0 ; days counter, high bit (bit 8) [w]
        def RTC_DHF_OVERFLOW equ 1 << RTC_DHB_OVERFLOW
        def RTC_DHF_HALT     equ 1 << RTC_DHB_HALT
        def RTC_DHF_HIGH     equ 1 << RTC_DHB_HIGH

; -- ROMB0 ($2000-$3FFF) ------------------------------------------------------
; ROM bank number [w]
def rROMB0 equ $2000

; -- ROMB1 ($3000-$3FFF) ------------------------------------------------------
; (MBC5 only) ROM bank number bit 8 [w]
def rROMB1 equ $3000

; -- RAMB ($4000-$5FFF) -------------------------------------------------------
; RAM bank number [w]
def rRAMB equ $4000

def CARTB_RUMBLE_ON equ 3 ; (MBC5 and MBC7 only) enable the rumble motor (if any)
    def CART_RUMBLE_ON equ 1 << CARTB_RUMBLE_ON

; -- RTCLATCH ($6000-$7FFF) ---------------------------------------------------
; (MBC3 only) RTC latch clock data [w]
def rRTCLATCH equ $6000

; Write $00 then $01 to latch the current time into the RTC registers
def RTCLATCH_START  equ $00
def RTCLATCH_FINISH equ $01


;***************************************************************************
;*
;* CPU values on bootup (a=type, b=qualifier)
;*
;***************************************************************************

def BOOTUP_A_DMG    equ $01 ; Dot Matrix Game
def BOOTUP_A_CGB    equ $11 ; Color Game Boy
def BOOTUP_A_MGB    equ $FF ; Mini Game Boy (Pocket Game Boy)

; if a=BOOTUP_A_CGB, bit 0 in b can be checked to determine if real CGB or
; other system running in GBC mode
def BOOTUP_B_CGB    equ %00000000
def BOOTUP_B_AGB    equ %00000001   ; GBA, GBA SP, Game Boy Player, or New GBA SP


;***************************************************************************
;*
;* Interrupt vector addresses
;*
;***************************************************************************

def INT_HANDLER_VBLANK equ $0040
def INT_HANDLER_STAT   equ $0048
def INT_HANDLER_TIMER  equ $0050
def INT_HANDLER_SERIAL equ $0058
def INT_HANDLER_JOYPAD equ $0060


;***************************************************************************
;*
;* Header
;*
;***************************************************************************

;*
;* Nintendo scrolling logo
;* (Code won't work on a real Game Boy)
;* (if next lines are altered.)
MACRO NINTENDO_LOGO
    DB  $CE,$ED,$66,$66,$CC,$0D,$00,$0B,$03,$73,$00,$83,$00,$0C,$00,$0D
    DB  $00,$08,$11,$1F,$88,$89,$00,$0E,$DC,$CC,$6E,$E6,$DD,$DD,$D9,$99
    DB  $BB,$BB,$67,$63,$6E,$0E,$EC,$CC,$DD,$DC,$99,$9F,$BB,$B9,$33,$3E
ENDM

; $0143 Color Game Boy compatibility code
def CART_COMPATIBLE_DMG     equ $00
def CART_COMPATIBLE_DMG_GBC equ $80
def CART_COMPATIBLE_GBC     equ $C0

; $0146 Game Boy/Super Game Boy indicator
def CART_INDICATOR_GB       equ $00
def CART_INDICATOR_SGB      equ $03

; $0147 Cartridge type
def CART_ROM                     equ $00
def CART_ROM_MBC1                equ $01
def CART_ROM_MBC1_RAM            equ $02
def CART_ROM_MBC1_RAM_BAT        equ $03
def CART_ROM_MBC2                equ $05
def CART_ROM_MBC2_BAT            equ $06
def CART_ROM_RAM                 equ $08
def CART_ROM_RAM_BAT             equ $09
def CART_ROM_MMM01               equ $0B
def CART_ROM_MMM01_RAM           equ $0C
def CART_ROM_MMM01_RAM_BAT       equ $0D
def CART_ROM_MBC3_BAT_RTC        equ $0F
def CART_ROM_MBC3_RAM_BAT_RTC    equ $10
def CART_ROM_MBC3                equ $11
def CART_ROM_MBC3_RAM            equ $12
def CART_ROM_MBC3_RAM_BAT        equ $13
def CART_ROM_MBC5                equ $19
def CART_ROM_MBC5_RAM            equ $1A
def CART_ROM_MBC5_RAM_BAT        equ $1B
def CART_ROM_MBC5_RUMBLE         equ $1C
def CART_ROM_MBC5_RAM_RUMBLE     equ $1D
def CART_ROM_MBC5_RAM_BAT_RUMBLE equ $1E
def CART_ROM_MBC7_RAM_BAT_GYRO   equ $22
def CART_ROM_POCKET_CAMERA       equ $FC
def CART_ROM_BANDAI_TAMA5        equ $FD
def CART_ROM_HUDSON_HUC3         equ $FE
def CART_ROM_HUDSON_HUC1         equ $FF

; $0148 ROM size
; these are kilobytes
def CART_ROM_32KB   equ $00 ; 2 banks
def CART_ROM_64KB   equ $01 ; 4 banks
def CART_ROM_128KB  equ $02 ; 8 banks
def CART_ROM_256KB  equ $03 ; 16 banks
def CART_ROM_512KB  equ $04 ; 32 banks
def CART_ROM_1024KB equ $05 ; 64 banks
def CART_ROM_2048KB equ $06 ; 128 banks
def CART_ROM_4096KB equ $07 ; 256 banks
def CART_ROM_8192KB equ $08 ; 512 banks
def CART_ROM_1152KB equ $52 ; 72 banks
def CART_ROM_1280KB equ $53 ; 80 banks
def CART_ROM_1536KB equ $54 ; 96 banks

; $0149 SRAM size
; these are kilobytes
def CART_SRAM_NONE  equ 0
def CART_SRAM_8KB   equ 2 ; 1 bank
def CART_SRAM_32KB  equ 3 ; 4 banks
def CART_SRAM_128KB equ 4 ; 16 banks

; $014A Destination code
def CART_DEST_JAPANESE     equ $00
def CART_DEST_NON_JAPANESE equ $01


;***************************************************************************
;*
;* Screen related
;*
;***************************************************************************

def _SCRN0   equ $9800 ; $9800-$9BFF
def _SCRN1   equ $9C00 ; $9C00-$9FFF

def SCRN_X    equ 160 ; Width of screen in pixels
def SCRN_Y    equ 144 ; Height of screen in pixels. Also corresponds to the value in LY at the beginning of VBlank.
def SCRN_X_B  equ 20  ; Width of screen in bytes
def SCRN_Y_B  equ 18  ; Height of screen in bytes

def SCRN_VX   equ 256 ; Virtual width of screen in pixels
def SCRN_VY   equ 256 ; Virtual height of screen in pixels
def SCRN_VX_B equ 32  ; Virtual width of screen in bytes
def SCRN_VY_B equ 32  ; Virtual height of screen in bytes


;***************************************************************************
;*
;* OAM related
;*
;***************************************************************************

; OAM attributes
; each entry in OAM RAM is 4 bytes (sizeof_OAM_ATTRS)
RSRESET
def OAMA_Y              RB  1   ; y pos plus 16
def OAMA_X              RB  1   ; x pos plus 8
def OAMA_TILEID         RB  1   ; tile id
def OAMA_FLAGS          RB  1   ; flags (see below)
def sizeof_OAM_ATTRS    RB  0

def OAM_Y_OFS equ 16 ; add this to a screen-relative Y position to get an OAM Y position
def OAM_X_OFS equ 8  ; add this to a screen-relative X position to get an OAM X position

def OAM_COUNT           equ 40  ; number of OAM entries in OAM RAM

; flags
def OAMF_PRI        equ %10000000 ; Priority
def OAMF_YFLIP      equ %01000000 ; Y flip
def OAMF_XFLIP      equ %00100000 ; X flip
def OAMF_PAL0       equ %00000000 ; Palette number; 0,1 (DMG)
def OAMF_PAL1       equ %00010000 ; Palette number; 0,1 (DMG)
def OAMF_BANK0      equ %00000000 ; Bank number; 0,1 (GBC)
def OAMF_BANK1      equ %00001000 ; Bank number; 0,1 (GBC)

def OAMF_PALMASK    equ %00000111 ; Palette (GBC)

def OAMB_PRI        equ 7 ; Priority
def OAMB_YFLIP      equ 6 ; Y flip
def OAMB_XFLIP      equ 5 ; X flip
def OAMB_PAL1       equ 4 ; Palette number; 0,1 (DMG)
def OAMB_BANK1      equ 3 ; Bank number; 0,1 (GBC)


; Aliases

def rP1   equ rJOYP
def rNR10 equ rAUD1SWEEP
def rNR11 equ rAUD1LEN
def rNR12 equ rAUD1ENV
def rNR13 equ rAUD1LOW
def rNR14 equ rAUD1HIGH
def rNR21 equ rAUD2LEN
def rNR22 equ rAUD2ENV
def rNR23 equ rAUD2LOW
def rNR24 equ rAUD2HIGH
def rNR30 equ rAUD3ENA
def rNR31 equ rAUD3LEN
def rNR32 equ rAUD3LEVEL
def rNR33 equ rAUD3LOW
def rNR34 equ rAUD3HIGH
def rNR41 equ rAUD4LEN
def rNR42 equ rAUD4ENV
def rNR43 equ rAUD4POLY
def rNR44 equ rAUD4GO
def rNR50 equ rAUDVOL
def rNR51 equ rAUDTERM
def rNR52 equ rAUDENA

; Deprecated constants. Please avoid using.

def IEB_HILO equ IEB_JOYPAD
def IEF_HILO equ 1 << IEB_JOYPAD

def IEF_LCDC   equ %00000010 ; LCDC (see STAT)
def _VRAM8000  equ _VRAM
def _VRAM8800  equ _VRAM+$800
def _VRAM9000  equ _VRAM+$1000
def CART_SRAM_2KB   equ 1 ; 1 incomplete bank
def LCDCF_BG8800  equ %00000000 ; BG & Window Tile Data Select
def LCDCF_BG8000  equ %00010000 ; BG & Window Tile Data Select
def LCDCB_BG8000  equ 4 ; BG & Window Tile Data Select

def P1F_5 equ JOYP_GET_DPAD
def P1F_4 equ JOYP_GET_BTN
def P1F_3 equ JOYPF_DOWN
def P1F_2 equ JOYPF_UP
def P1F_1 equ JOYPF_LEFT
def P1F_0 equ JOYPF_RIGHT

def P1F_GET_DPAD equ JOYP_GET_DPAD
def P1F_GET_BTN  equ JOYP_GET_BTN
def P1F_GET_NONE equ JOYP_GET_NONE

endc ; HARDWARE_INC
