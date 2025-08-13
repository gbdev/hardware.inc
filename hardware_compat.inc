;******************************************************************************
; Deprecated Game Boy hardware constant definitions for backwards compatibility
; https://github.com/gbdev/hardware.inc
;******************************************************************************

; To the extent possible under law, the authors of this work have
; waived all copyright and related or neighboring rights to the work.
; See https://creativecommons.org/publicdomain/zero/1.0/ for details.
; SPDX-License-Identifier: CC0-1.0

; If this file was already included, don't do it again
if !def(HARDWARE_COMPAT_INC)

; Check for hardware.inc to have been previously included
if !def(HARDWARE_INC)
    fail "'hardware_compat.inc' requires 'hardware.inc'"
endc

; Define the include guard
; (do this after the hardware.inc check since the `def` syntax depends on it)
def HARDWARE_COMPAT_INC equ 1


;******************************************************************************
; Memory-mapped registers ($FFxx range)
;******************************************************************************

def JOYPB_GET_BTN  equ B_JOYP_GET_BUTTONS
def JOYPB_GET_DPAD equ B_JOYP_GET_CTRL_PAD
    def JOYPF_GET equ JOYP_GET
        def JOYP_GET_BTN  equ JOYP_GET_BUTTONS
        def JOYP_GET_DPAD equ JOYP_GET_CTRL_PAD
def JOYPB_START    equ B_JOYP_START
def JOYPB_SELECT   equ B_JOYP_SELECT
def JOYPB_B        equ B_JOYP_B
def JOYPB_A        equ B_JOYP_A
def JOYPB_DOWN     equ B_JOYP_DOWN
def JOYPB_UP       equ B_JOYP_UP
def JOYPB_LEFT     equ B_JOYP_LEFT
def JOYPB_RIGHT    equ B_JOYP_RIGHT
    def JOYPF_INPUTS equ JOYP_INPUTS
    def JOYPF_START  equ JOYP_START
    def JOYPF_SELECT equ JOYP_SELECT
    def JOYPF_B      equ JOYP_B
    def JOYPF_A      equ JOYP_A
    def JOYPF_DOWN   equ JOYP_DOWN
    def JOYPF_UP     equ JOYP_UP
    def JOYPF_LEFT   equ JOYP_LEFT
    def JOYPF_RIGHT  equ JOYP_RIGHT

def PADB_DOWN   equ B_PAD_DOWN
def PADB_UP     equ B_PAD_UP
def PADB_LEFT   equ B_PAD_LEFT
def PADB_RIGHT  equ B_PAD_RIGHT
def PADB_START  equ B_PAD_START
def PADB_SELECT equ B_PAD_SELECT
def PADB_B      equ B_PAD_B
def PADB_A      equ B_PAD_A
    def PADF_DOWN   equ PAD_DOWN
    def PADF_UP     equ PAD_UP
    def PADF_LEFT   equ PAD_LEFT
    def PADF_RIGHT  equ PAD_RIGHT
    def PADF_START  equ PAD_START
    def PADF_SELECT equ PAD_SELECT
    def PADF_B      equ PAD_B
    def PADF_A      equ PAD_A

def PADB_SWAP_START  equ B_PAD_SWAP_START
def PADB_SWAP_SELECT equ B_PAD_SWAP_SELECT
def PADB_SWAP_B      equ B_PAD_SWAP_B
def PADB_SWAP_A      equ B_PAD_SWAP_A
def PADB_SWAP_DOWN   equ B_PAD_SWAP_DOWN
def PADB_SWAP_UP     equ B_PAD_SWAP_UP
def PADB_SWAP_LEFT   equ B_PAD_SWAP_LEFT
def PADB_SWAP_RIGHT  equ B_PAD_SWAP_RIGHT
    def PADF_SWAP_START  equ PAD_SWAP_START
    def PADF_SWAP_SELECT equ PAD_SWAP_SELECT
    def PADF_SWAP_B      equ PAD_SWAP_B
    def PADF_SWAP_A      equ PAD_SWAP_A
    def PADF_SWAP_DOWN   equ PAD_SWAP_DOWN
    def PADF_SWAP_UP     equ PAD_SWAP_UP
    def PADF_SWAP_LEFT   equ PAD_SWAP_LEFT
    def PADF_SWAP_RIGHT  equ PAD_SWAP_RIGHT

def SCB_START  equ B_SC_START
def SCB_SPEED  equ B_SC_SPEED
def SCB_SOURCE equ B_SC_SOURCE
    def SCF_START  equ SC_START
    def SCF_SPEED  equ SC_SPEED
    def SCF_SOURCE equ SC_SOURCE

def TACB_START equ B_TAC_START
    def TACF_STOP  equ TAC_STOP
    def TACF_START equ TAC_START
def TACF_CLOCK equ TAC_CLOCK
    def TACF_4KHZ   equ TAC_4KHZ
    def TACF_262KHZ equ TAC_262KHZ
    def TACF_65KHZ  equ TAC_65KHZ
    def TACF_16KHZ  equ TAC_16KHZ

def IFB_JOYPAD equ B_IF_JOYPAD
def IFB_SERIAL equ B_IF_SERIAL
def IFB_TIMER  equ B_IF_TIMER
def IFB_STAT   equ B_IF_STAT
def IFB_VBLANK equ B_IF_VBLANK
    def IFF_JOYPAD equ IF_JOYPAD
    def IFF_SERIAL equ IF_SERIAL
    def IFF_TIMER  equ IF_TIMER
    def IFF_STAT   equ IF_STAT
    def IFF_VBLANK equ IF_VBLANK

def AUD1SWEEPF_TIME equ AUD1SWEEP_TIME
def AUD1SWEEPB_DIR  equ B_AUD1SWEEP_DIR
    def AUD1SWEEPF_DIR equ AUD1SWEEP_DIR

def AUD1LENF_DUTY  equ AUD1LEN_DUTY
def AUD1LENF_TIMER equ AUD1LEN_TIMER

def AUD1ENVF_INIT_VOL equ AUD1ENV_INIT_VOLUME
def AUD1ENVB_DIR      equ B_AUD1ENV_DIR
    def AUD1ENVF_DIR equ AUD1ENV_DIR
def AUD1ENVF_PACE     equ AUD1ENV_PACE

def AUD1HIGHB_RESTART     equ B_AUD1HIGH_RESTART
def AUD1HIGHB_LEN_ENABLE  equ B_AUD1HIGH_LEN_ENABLE
def AUD1HIGHF_PERIOD_HIGH equ AUD1HIGH_PERIOD_HIGH

def AUD2LENF_DUTY  equ AUD2LEN_DUTY
def AUD2LENF_TIMER equ AUD2LEN_TIMER

def AUD2ENVF_INIT_VOL equ AUD2ENV_INIT_VOLUME
def AUD2ENVB_DIR      equ B_AUD2ENV_DIR
    def AUD2ENVF_DIR equ AUD2ENV_DIR
def AUD2ENVF_PACE     equ AUD2ENV_PACE

def AUD2HIGHB_RESTART     equ B_AUD2HIGH_RESTART
def AUD2HIGHB_LEN_ENABLE  equ B_AUD2HIGH_LEN_ENABLE
def AUD2HIGHF_PERIOD_HIGH equ AUD2HIGH_PERIOD_HIGH

def AUD3ENAB_ENABLE equ B_AUD3ENA_ENABLE

def AUD3LEVELF_VOLUME equ AUD3LEVEL_VOLUME

def AUD3HIGHB_RESTART     equ B_AUD3HIGH_RESTART
def AUD3HIGHB_LEN_ENABLE  equ B_AUD3HIGH_LEN_ENABLE
def AUD3HIGHF_PERIOD_HIGH equ AUD3HIGH_PERIOD_HIGH

def AUD4LENF_TIMER equ AUD4LEN_TIMER

def AUD4ENVF_INIT_VOL equ AUD4ENV_INIT_VOLUME
def AUD4ENVB_DIR      equ B_AUD4ENV_DIR
    def AUD4ENVF_DIR equ AUD4ENV_DIR
def AUD4ENVF_PACE     equ AUD4ENV_PACE

def AUD4POLYF_SHIFT equ AUD4POLY_SHIFT
def AUD4POLYB_WIDTH equ B_AUD4POLY_WIDTH
def AUD4POLYF_DIV   equ AUD4POLY_DIV

def AUD4GOB_RESTART    equ B_AUD4GO_RESTART
def AUD4GOB_LEN_ENABLE equ B_AUD4GO_LEN_ENABLE

def AUDVOLB_VIN_LEFT  equ B_AUDVOL_VIN_LEFT
    def AUDVOLF_LEFT equ AUDVOL_LEFT
def AUDVOLB_VIN_RIGHT equ B_AUDVOL_VIN_RIGHT
    def AUDVOLF_RIGHT equ AUDVOL_RIGHT

def AUDTERMB_4_LEFT  equ B_AUDTERM_4_LEFT
def AUDTERMB_3_LEFT  equ B_AUDTERM_3_LEFT
def AUDTERMB_2_LEFT  equ B_AUDTERM_2_LEFT
def AUDTERMB_1_LEFT  equ B_AUDTERM_1_LEFT
def AUDTERMB_4_RIGHT equ B_AUDTERM_4_RIGHT
def AUDTERMB_3_RIGHT equ B_AUDTERM_3_RIGHT
def AUDTERMB_2_RIGHT equ B_AUDTERM_2_RIGHT
def AUDTERMB_1_RIGHT equ B_AUDTERM_1_RIGHT

def AUDENAB_ENABLE     equ B_AUDENA_ENABLE
def AUDENAB_ENABLE_CH4 equ B_AUDENA_ENABLE_CH4
def AUDENAB_ENABLE_CH3 equ B_AUDENA_ENABLE_CH3
def AUDENAB_ENABLE_CH2 equ B_AUDENA_ENABLE_CH2
def AUDENAB_ENABLE_CH1 equ B_AUDENA_ENABLE_CH1
    def AUDENAF_CH4_OFF equ AUDENA_CH4_OFF
    def AUDENAF_CH4_ON  equ AUDENA_CH4_ON
    def AUDENAF_CH3_OFF equ AUDENA_CH3_OFF
    def AUDENAF_CH3_ON  equ AUDENA_CH3_ON
    def AUDENAF_CH2_OFF equ AUDENA_CH2_OFF
    def AUDENAF_CH2_ON  equ AUDENA_CH2_ON
    def AUDENAF_CH1_OFF equ AUDENA_CH1_OFF
    def AUDENAF_CH1_ON  equ AUDENA_CH1_ON

def LCDCB_ON      equ B_LCDC_ENABLE
def LCDCB_WIN9C00 equ B_LCDC_WIN_MAP
def LCDCB_WINON   equ B_LCDC_WINDOW
def LCDCB_BLKS    equ B_LCDC_BLOCKS
def LCDCB_BG9C00  equ B_LCDC_BG_MAP
def LCDCB_OBJ16   equ B_LCDC_OBJ_SIZE
def LCDCB_OBJON   equ B_LCDC_OBJS
def LCDCB_BGON    equ B_LCDC_BG
def LCDCB_PRION   equ B_LCDC_PRIO
    def LCDCF_OFF     equ LCDC_OFF
    def LCDCF_ON      equ LCDC_ON
    def LCDCF_WIN9800 equ LCDC_WIN_9800
    def LCDCF_WIN9C00 equ LCDC_WIN_9C00
    def LCDCF_WINOFF  equ LCDC_WIN_OFF
    def LCDCF_WINON   equ LCDC_WIN_ON
    def LCDCF_BLKS    equ LCDC_BLOCKS
        def LCDCF_BLK21 equ LCDC_BLOCK21
        def LCDCF_BLK01 equ LCDC_BLOCK01
    def LCDCF_BG9800  equ LCDC_BG_9800
    def LCDCF_BG9C00  equ LCDC_BG_9C00
    def LCDCF_OBJ8    equ LCDC_OBJ_8
    def LCDCF_OBJ16   equ LCDC_OBJ_16
    def LCDCF_OBJOFF  equ LCDC_OBJ_OFF
    def LCDCF_OBJON   equ LCDC_OBJ_ON
    def LCDCF_BGOFF   equ LCDC_BG_OFF
    def LCDCF_BGON    equ LCDC_BG_ON
    def LCDCF_PRIOFF  equ LCDC_PRIO_OFF
    def LCDCF_PRION   equ LCDC_PRIO_ON

def STATB_LYC    equ B_STAT_LYC
def STATB_MODE10 equ B_STAT_MODE_2
def STATB_MODE01 equ B_STAT_MODE_1
def STATB_MODE00 equ B_STAT_MODE_0
def STATB_LYCF   equ B_STAT_LYCF
def STATB_BUSY   equ B_STAT_BUSY
    def STATF_LYC    equ STAT_LYC
    def STATF_MODE10 equ STAT_MODE_2
    def STATF_MODE01 equ STAT_MODE_1
    def STATF_MODE00 equ STAT_MODE_0
    def STATF_LYCF   equ STAT_LYCF
    def STATF_BUSY   equ STAT_BUSY
def STATF_MODE   equ STAT_MODE
    def STATF_HBL    equ STAT_HBLANK
    def STATF_VBL    equ STAT_VBLANK
    def STATF_OAM    equ STAT_OAM
    def STATF_LCD    equ STAT_LCD

def SYSF_MODE equ SYS_MODE
    def SYSF_CGB  equ SYS_CGB
    def SYSF_DMG  equ SYS_DMG
    def SYSF_PGB1 equ SYS_PGB1
    def SYSF_PGB2 equ SYS_PGB2

def SPDB_DBLSPEED equ B_SPD_DOUBLE
def SPDB_PREPARE  equ B_SPD_PREPARE
    def SPDF_DBLSPEED equ SPD_DOUBLE
    def SPDF_PREPARE  equ SPD_PREPARE

def BANKB_ON equ B_BANK_ON
    def BANKF_ON  equ BANK_ON
    def BANKF_OFF equ BANK_OFF

def VDMA_LENB_MODE equ B_VDMA_LEN_MODE
    def VDMA_LENF_MODE equ VDMA_LEN_MODE
        def VDMA_LENF_MODE_GP  equ VDMA_LEN_MODE_GENERAL
        def VDMA_LENF_MODE_HBL equ VDMA_LEN_MODE_HBLANK
def VDMA_LENB_BUSY equ B_VDMA_LEN_BUSY
    def VDMA_LENF_BUSY equ VDMA_LEN_BUSY
        def VDMA_LENF_NO  equ VDMA_LEN_NO
        def VDMA_LENF_YES equ VDMA_LEN_YES
def VDMA_LENB_SIZE equ VDMA_LEN_SIZE

def RPF_READ   equ RP_READ
    def RPF_DISREAD equ RP_DISABLE
    def RPF_ENREAD  equ RP_ENABLE
def RPB_DATAIN equ B_RP_DATA_IN
def RPB_LED_ON equ B_RP_LED_ON
    def RPF_DATAIN equ RP_DATA_IN
    def RPF_LED_ON equ RP_LED_ON
        def RPF_WRITE_LO equ RP_WRITE_LOW
        def RPF_WRITE_HI equ RP_WRITE_HIGH

def BGPIB_AUTOINC equ B_BGPI_AUTOINC
    def BGPIF_AUTOINC equ BGPI_AUTOINC
def BGPIF_INDEX   equ BGPI_INDEX

def OBPIB_AUTOINC equ B_OBPI_AUTOINC
    def OBPIF_AUTOINC equ OBPI_AUTOINC
def OBPIF_INDEX   equ OBPI_INDEX

def OPRIB_PRI equ B_OPRI_PRIORITY
    def OPRIF_PRI equ OPRI_PRIORITY

def WBKF_BANK equ WBK_BANK

def PCM12F_CH2 equ PCM12_CH2
def PCM12F_CH1 equ PCM12_CH1

def PCM34F_CH4 equ PCM34_CH4
def PCM34F_CH3 equ PCM34_CH3

def IEB_JOYPAD equ B_IE_JOYPAD
def IEB_SERIAL equ B_IE_SERIAL
def IEB_TIMER  equ B_IE_TIMER
def IEB_STAT   equ B_IE_STAT
def IEB_VBLANK equ B_IE_VBLANK
    def IEF_JOYPAD equ IE_JOYPAD
    def IEF_SERIAL equ IE_SERIAL
    def IEF_TIMER  equ IE_TIMER
    def IEF_STAT   equ IE_STAT
    def IEF_VBLANK equ IE_VBLANK


;******************************************************************************
; Cartridge registers (MBC)
;******************************************************************************

def CART_SRAM_DISABLE equ RAMG_SRAM_DISABLE
def CART_SRAM_ENABLE  equ RAMG_SRAM_ENABLE

def RTC_S  equ RAMB_RTC_S
def RTC_M  equ RAMB_RTC_M
def RTC_H  equ RAMB_RTC_H
def RTC_DL equ RAMB_RTC_DL
def RTC_DH equ RAMB_RTC_DH
    def RTC_DHB_CARRY equ B_RAMB_RTC_DH_CARRY
    def RTC_DHB_HALT  equ B_RAMB_RTC_DH_HALT
    def RTC_DHB_HIGH  equ B_RAMB_RTC_DH_HIGH
        def RTC_DHF_CARRY equ RAMB_RTC_DH_CARRY
        def RTC_DHF_HALT  equ RAMB_RTC_DH_HALT
        def RTC_DHF_HIGH  equ RAMB_RTC_DH_HIGH

def CARTB_RUMBLE_ON equ B_RAMB_RUMBLE
def CARTF_RUMBLE_ON equ RAMB_RUMBLE
def CART_RUMBLE_OFF equ RAMB_RUMBLE_OFF
def CART_RUMBLE_ON  equ RAMB_RUMBLE_ON


;******************************************************************************
; Screen-related constants
;******************************************************************************

def SCRN_X   equ SCREEN_WIDTH_PX
def SCRN_Y   equ SCREEN_HEIGHT_PX
def SCRN_X_B equ SCREEN_WIDTH
def SCRN_Y_B equ SCREEN_HEIGHT
def SCRN_B   equ SCREEN_AREA

def SCRN_VX   equ TILEMAP_WIDTH_PX
def SCRN_VY   equ TILEMAP_HEIGHT_PX
def SCRN_VX_B equ TILEMAP_WIDTH
def SCRN_VY_B equ TILEMAP_HEIGHT
def SCRN_V_B  equ TILEMAP_AREA

def TILE_X equ TILE_WIDTH
def TILE_Y equ TILE_HEIGHT
def TILE_B equ TILE_SIZE

def COLOR_B equ COLOR_SIZE
    def COLORF_GREEN_LOW  equ COLOR_GREEN_LOW
    def COLORF_RED        equ COLOR_RED
    def COLORF_BLUE       equ COLOR_BLUE
    def COLORF_GREEN_HIGH equ COLOR_GREEN_HIGH

def PAL_B equ PAL_SIZE

def _SCRN0 equ TILEMAP0
def _SCRN1 equ TILEMAP1


;******************************************************************************
; OBJ-related constants
;******************************************************************************

def OAMB_PRI     equ B_OAM_PRIO
def OAMB_YFLIP   equ B_OAM_YFLIP
def OAMB_XFLIP   equ B_OAM_XFLIP
def OAMB_PAL1    equ B_OAM_PAL1
def OAMB_BANK1   equ B_OAM_BANK1
def OAMF_PALMASK equ OAM_PALETTE
    def OAMF_PRI   equ OAM_PRIO
    def OAMF_YFLIP equ OAM_YFLIP
    def OAMF_XFLIP equ OAM_XFLIP
    def OAMF_PAL0  equ OAM_PAL0
    def OAMF_PAL1  equ OAM_PAL1
    def OAMF_BANK0 equ OAM_BANK0
    def OAMF_BANK1 equ OAM_BANK1
def OBJ_B        equ OBJ_SIZE

def OAM_B equ OAM_SIZE


;******************************************************************************
; Boot-up register values
;******************************************************************************

def BOOTUPB_B_AGB equ B_BOOTUP_B_AGB


;******************************************************************************
; Aliases
;******************************************************************************

def P1F_GET_BTN  equ JOYP_GET_BTN
def P1F_GET_DPAD equ JOYP_GET_DPAD
def P1F_GET_NONE equ JOYP_GET_NONE
def P1F_5        equ JOYP_GET_DPAD
def P1F_4        equ JOYP_GET_BTN
def P1F_3        equ JOYPF_DOWN
def P1F_2        equ JOYPF_UP
def P1F_1        equ JOYPF_LEFT
def P1F_0        equ JOYPF_RIGHT

def KEY0F_MODE equ SYSF_MODE
    def KEY0F_CGB  equ SYSF_CGB
    def KEY0F_DMG  equ SYSF_DMG
    def KEY0F_PGB1 equ SYSF_PGB1
    def KEY0F_PGB2 equ SYSF_PGB2

def KEY1F_DBLSPEED equ SPDF_DBLSPEED
def KEY1F_PREPARE  equ SPDF_PREPARE

def HDMA5B_MODE equ VDMA_LENB_MODE
    def HDMA5F_MODE_GP  equ VDMA_LENF_MODE_GP
    def HDMA5F_MODE_HBL equ VDMA_LENF_MODE_HBL
def HDMA5F_BUSY equ VDMA_LENF_BUSY

def BCPSB_AUTOINC equ BGPIB_AUTOINC
    def BCPSF_AUTOINC equ BGPIF_AUTOINC

def OCPSB_AUTOINC equ OBPIB_AUTOINC
    def OCPSF_AUTOINC equ OBPIF_AUTOINC

def rSMBK equ rWBK


;******************************************************************************
; Memory regions
;******************************************************************************

; Prefer RGBASM and RGBLINK features instead of these values.
; Note that the value of `STARTOF(<section_type>)` is determined at link time.

def _ROM     equ $0000 ; $0000-$3FFF / $0000-$7FFF (prefer `STARTOF(ROM0)`)
def _ROMBANK equ $4000 ; $4000-$7FFF               (prefer `STARTOF(ROMX)`)
def _VRAM    equ $8000 ; $8000-$9FFF               (prefer `STARTOF(VRAM)`)
def _SRAM    equ $A000 ; $A000-$BFFF               (prefer `STARTOF(SRAM)`)
def _RAM     equ $C000 ; $C000-$CFFF / $C000-$DFFF (prefer `STARTOF(WRAM0)`)
def _RAMBANK equ $D000 ; $D000-$DFFF               (prefer `STARTOF(WRAMX)`)
def _OAMRAM  equ $FE00 ; $FE00-$FE9F               (prefer `STARTOF(OAM)`)
def _IO      equ $FF00 ; $FF00-$FF7F, $FFFF        (prefer `ldh [c]` to `ld [_IO+c]`)
def _HRAM    equ $FF80 ; $FF80-$FFFE               (prefer `STARTOF(HRAM)`)


;******************************************************************************
; Cartridge header
;******************************************************************************

; Prefer RGBFIX instead of these values.
; Zero-filled space can be reserved for fixable header values like this:
;
;     SECTION "Cartridge header", ROM0[$0100]
;         nop :: jp $0150  ; Entry point ($0100-$0104)
;         ds $150 - @, $00 ; Header ($0104-$014FF) filled with $00s for RGBFIX to populate

; -- Nintendo logo ($0104-$0133) ----------------------------------------------
; Prefer `rgbfix -f/--fix-spec l` for the official logo, or `rgbfix -L <logo_file>` for a custom one
MACRO NINTENDO_LOGO
    db $CE,$ED,$66,$66,$CC,$0D,$00,$0B,$03,$73,$00,$83,$00,$0C,$00,$0D
    db $00,$08,$11,$1F,$88,$89,$00,$0E,$DC,$CC,$6E,$E6,$DD,$DD,$D9,$99
    db $BB,$BB,$67,$63,$6E,$0E,$EC,$CC,$DD,$DC,$99,$9F,$BB,$B9,$33,$3E
ENDM

; -- CGB compatibility code ($0143) -------------------------------------------
def CART_COMPATIBLE_DMG     equ $00 ; default value if header is zero-filled
def CART_COMPATIBLE_DMG_GBC equ $80 ; prefer `rgbfix -c/--color-compatible`
def CART_COMPATIBLE_GBC     equ $C0 ; prefer `rgbfix -C/--color-only`

; -- SGB flag ($0146) ---------------------------------------------------------
def CART_INDICATOR_GB  equ $00 ; default value if header is zero-filled
def CART_INDICATOR_SGB equ $03 ; prefer `rgblink -s/--sgb-compatible`

; -- Cartridge type ($0147) ---------------------------------------------------
; Prefer `rgblink -m/--mbc_type <mbc_type>`
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

; -- ROM size ($0148) ---------------------------------------------------------
; Prefer `rgbfix -p/--pad_value <pad_value>`, which pads to the smallest valid size
def CART_ROM_32KB   equ $00 ;   2 banks
def CART_ROM_64KB   equ $01 ;   4 banks
def CART_ROM_128KB  equ $02 ;   8 banks
def CART_ROM_256KB  equ $03 ;  16 banks
def CART_ROM_512KB  equ $04 ;  32 banks
def CART_ROM_1024KB equ $05 ;  64 banks
def CART_ROM_2048KB equ $06 ; 128 banks
def CART_ROM_4096KB equ $07 ; 256 banks
def CART_ROM_8192KB equ $08 ; 512 banks
def CART_ROM_1152KB equ $52 ;  72 banks
def CART_ROM_1280KB equ $53 ;  80 banks
def CART_ROM_1536KB equ $54 ;  96 banks

; -- SRAM size ($0149) --------------------------------------------------------
; Prefer `rgbfix -r/--ram_size <ram_size>`
def CART_SRAM_NONE  equ 0 ; none
def CART_SRAM_2KB   equ 1 ;  1 incomplete bank (homebrew only)
def CART_SRAM_8KB   equ 2 ;  1 bank
def CART_SRAM_32KB  equ 3 ;  4 banks
def CART_SRAM_128KB equ 4 ; 16 banks

; -- Destination code ($014A) -------------------------------------------------
def CART_DEST_JAPANESE     equ $00 ; default value if header is zero-filled
def CART_DEST_NON_JAPANESE equ $01 ; prefer `rgbfix -j/--non-japanese`


;******************************************************************************
; Deprecated constants
;******************************************************************************

def AUDLENF_DUTY equ AUD1LENF_DUTY
    def AUDLEN_DUTY_12_5 equ AUD1LEN_DUTY_12_5
    def AUDLEN_DUTY_25   equ AUD1LEN_DUTY_25
    def AUDLEN_DUTY_50   equ AUD1LEN_DUTY_50
    def AUDLEN_DUTY_75   equ AUD1LEN_DUTY_75

def AUDLENF_TIMER equ AUD1LENF_TIMER

def AUDENVF_INIT_VOL equ AUD1ENVF_INIT_VOL

def AUDENVB_DIR equ AUD1ENVB_DIR
    def AUDENVF_DIR equ AUD1ENVF_DIR
        def AUDENV_DOWN equ AUD1ENV_DOWN
        def AUDENV_UP   equ AUD1ENV_UP

def AUDENVF_PACE equ AUD1ENVF_PACE

def AUDHIGHB_RESTART    equ AUD1HIGHB_RESTART
def AUDHIGHB_LEN_ENABLE equ AUD1HIGHB_LEN_ENABLE
    def AUDHIGH_RESTART    equ AUD1HIGH_RESTART
    def AUDHIGH_LENGTH_OFF equ AUD1HIGH_LENGTH_OFF
    def AUDHIGH_LENGTH_ON  equ AUD1HIGH_LENGTH_ON

def AUDHIGHF_PERIOD_HIGH equ AUD1HIGHF_PERIOD_HIGH

def LCDCB_BG8000 equ LCDCB_BLKS
    def LCDCF_BG8800 equ LCDCF_BLK21
    def LCDCF_BG8000 equ LCDCF_BLK01

def IEB_HILO equ IEB_JOYPAD
    def IEF_HILO equ IEF_JOYPAD
def IEF_LCDC equ IEF_STAT

def sizeof_OAM_ATTRS equ OBJ_B

def _VRAM8000 equ _VRAM
def _VRAM8800 equ _VRAM + $800
def _VRAM9000 equ _VRAM + $1000

endc ; HARDWARE_COMPAT_INC
