;******************************************************************************
; Super Game Boy command constant definitions
; https://github.com/gbdev/hardware.inc
;******************************************************************************

; To the extent possible under law, the authors of this work have
; waived all copyright and related or neighboring rights to the work.
; See https://creativecommons.org/publicdomain/zero/1.0/ for details.
; SPDX-License-Identifier: CC0-1.0

; If this file was already included, don't do it again
if !def(SGB_INC)

; Define the include guard
def SGB_INC equ 1


;******************************************************************************
; SGB packet constants
;******************************************************************************

def SGB_PACKET_SIZE equ 16


;******************************************************************************
; SGB command prefixes
;******************************************************************************

def SGB_HEADER_COMMAND equ %11111000
def SGB_HEADER_LENGTH  equ %00000111

def S_SGB_COMMAND equ 3

def SGB_PAL01    equ $00 << S_SGB_COMMAND
def SGB_PAL23    equ $01 << S_SGB_COMMAND
def SGB_PAL03    equ $02 << S_SGB_COMMAND
def SGB_PAL12    equ $03 << S_SGB_COMMAND
def SGB_ATTR_BLK equ $04 << S_SGB_COMMAND
def SGB_ATTR_LIN equ $05 << S_SGB_COMMAND
def SGB_ATTR_DIV equ $06 << S_SGB_COMMAND
def SGB_ATTR_CHR equ $07 << S_SGB_COMMAND
def SGB_SOUND    equ $08 << S_SGB_COMMAND
def SGB_SOU_TRN  equ $09 << S_SGB_COMMAND
def SGB_PAL_SET  equ $0A << S_SGB_COMMAND
def SGB_PAL_TRN  equ $0B << S_SGB_COMMAND
def SGB_ATRC_EN  equ $0C << S_SGB_COMMAND
def SGB_TEST_EN  equ $0D << S_SGB_COMMAND
def SGB_ICON_EN  equ $0E << S_SGB_COMMAND
def SGB_DATA_SND equ $0F << S_SGB_COMMAND
def SGB_DATA_TRN equ $10 << S_SGB_COMMAND
def SGB_MLT_REQ  equ $11 << S_SGB_COMMAND
def SGB_JUMP     equ $12 << S_SGB_COMMAND
def SGB_CHR_TRN  equ $13 << S_SGB_COMMAND
def SGB_PCT_TRN  equ $14 << S_SGB_COMMAND
def SGB_ATTR_TRN equ $15 << S_SGB_COMMAND
def SGB_ATTR_SET equ $16 << S_SGB_COMMAND
def SGB_MASK_EN  equ $17 << S_SGB_COMMAND
def SGB_OBJ_TRN  equ $18 << S_SGB_COMMAND
def SGB_PAL_PRI  equ $19 << S_SGB_COMMAND
def SGB_STUB1    equ $1A << S_SGB_COMMAND
def SGB_STUB2    equ $1B << S_SGB_COMMAND
def SGB_STUB3    equ $1C << S_SGB_COMMAND
def SGB_STUB4    equ $1D << S_SGB_COMMAND
def SGB_STUB5    equ $1E << S_SGB_COMMAND
def SGB_STUB6    equ $1F << S_SGB_COMMAND


;******************************************************************************
; SGB command-related values
;******************************************************************************

; -- SGB_PAL01 ($00) ----------------------------------------------------------

def A_SGB_PAL01_COLOR_0       equ $01 ; $01-$02
def A_SGB_PAL01_PAL_0_COLOR_1 equ $03 ; $03-$04
def A_SGB_PAL01_PAL_0_COLOR_2 equ $05 ; $05-$06
def A_SGB_PAL01_PAL_0_COLOR_3 equ $07 ; $07-$08
def A_SGB_PAL01_PAL_1_COLOR_1 equ $09 ; $09-$0A
def A_SGB_PAL01_PAL_1_COLOR_2 equ $0B ; $0B-$0C
def A_SGB_PAL01_PAL_1_COLOR_3 equ $0D ; $0D-$0E


; -- SGB_PAL23 ($01) ----------------------------------------------------------

def A_SGB_PAL23_COLOR_0       equ $01 ; $01-$02
def A_SGB_PAL23_PAL_2_COLOR_1 equ $03 ; $03-$04
def A_SGB_PAL23_PAL_2_COLOR_2 equ $05 ; $05-$06
def A_SGB_PAL23_PAL_2_COLOR_3 equ $07 ; $07-$08
def A_SGB_PAL23_PAL_3_COLOR_1 equ $09 ; $09-$0A
def A_SGB_PAL23_PAL_3_COLOR_2 equ $0B ; $0B-$0C
def A_SGB_PAL23_PAL_3_COLOR_3 equ $0D ; $0D-$0E


; -- SGB_PAL03 ($02) ----------------------------------------------------------

def A_SGB_PAL03_COLOR_0       equ $01 ; $01-$02
def A_SGB_PAL03_PAL_0_COLOR_1 equ $03 ; $03-$04
def A_SGB_PAL03_PAL_0_COLOR_2 equ $05 ; $05-$06
def A_SGB_PAL03_PAL_0_COLOR_3 equ $07 ; $07-$08
def A_SGB_PAL03_PAL_3_COLOR_1 equ $09 ; $09-$0A
def A_SGB_PAL03_PAL_3_COLOR_2 equ $0B ; $0B-$0C
def A_SGB_PAL03_PAL_3_COLOR_3 equ $0D ; $0D-$0E


; -- SGB_PAL12 ($03) ----------------------------------------------------------

def A_SGB_PAL12_COLOR_0       equ $01 ; $01-$02
def A_SGB_PAL12_PAL_1_COLOR_1 equ $03 ; $03-$04
def A_SGB_PAL12_PAL_1_COLOR_2 equ $05 ; $05-$06
def A_SGB_PAL12_PAL_1_COLOR_3 equ $07 ; $07-$08
def A_SGB_PAL12_PAL_2_COLOR_1 equ $09 ; $09-$0A
def A_SGB_PAL12_PAL_2_COLOR_2 equ $0B ; $0B-$0C
def A_SGB_PAL12_PAL_2_COLOR_3 equ $0D ; $0D-$0E


; -- SGB_ATTR_BLK ($04) -------------------------------------------------------

def A_SGB_ATTR_BLK_NUM_SETS equ $01

; data set byte 0 (control code) values
def S_SGB_ATTR_BLK_INSIDE_AREA    equ 0
def S_SGB_ATTR_BLK_RECTANGLE_AREA equ 1
def S_SGB_ATTR_BLK_OUTSIDE_AREA   equ 2

; data set byte 1 (color palettes) values
def S_SGB_ATTR_BLK_INSIDE_PAL    equ 0 ; bit 0-1
def S_SGB_ATTR_BLK_RECTANGLE_PAL equ 2 ; bit 2-3
def S_SGB_ATTR_BLK_OUTSIDE_PAL   equ 4 ; bit 4-5


; -- SGB_ATTR_LIN ($05) -------------------------------------------------------

def A_SGB_ATTR_LIN_NUM_SETS equ $01

; data set values
def S_SGB_ATTR_LIN_LINE equ 0 ; bit 0-4
def S_SGB_ATTR_LIN_PAL  equ 5 ; bit 5-6
def S_SGB_ATTR_LIN_MODE equ 7
    def SGB_ATTR_LIN_VERTICAL   equ 0 << S_SGB_ATTR_LIN_MODE
    def SGB_ATTR_LIN_HORIZONTAL equ 1 << S_SGB_ATTR_LIN_MODE


; -- SGB_ATTR_DIV ($06) -------------------------------------------------------

def A_SGB_ATTR_DIV_PAL_HV equ $01

; A_SGB_ATTR_DIV_PAL_HV values
def S_SGB_ATTR_DIV_POST_LINE_PAL equ 0 ; bit 0-1
def S_SGB_ATTR_DIV_PRE_LINE_PAL  equ 2 ; bit 2-3
def S_SGB_ATTR_DIV_LINE_PAL      equ 4 ; bit 4-5
def S_SGB_ATTR_DIV_MODE          equ 6
    def SGB_ATTR_DIV_VERTICAL   equ 0 << S_SGB_ATTR_DIV_MODE
    def SGB_ATTR_DIV_HORIZONTAL equ 1 << S_SGB_ATTR_DIV_MODE


; -- SGB_ATTR_CHR ($07) -------------------------------------------------------

def A_SGB_ATTR_CHR_X_COORD  equ $01
def A_SGB_ATTR_CHR_Y_COORD  equ $02
def A_SGB_ATTR_CHR_NUM_SETS equ $03 ; $03-$04
def A_SGB_ATTR_CHR_ORDER    equ $05

; A_SGB_ATTR_CHR_ORDER values
def A_SGB_ATTR_CHR_ROWS    equ $00
def A_SGB_ATTR_CHR_COLUMNS equ $01


; -- SGB_SOUND ($08) ----------------------------------------------------------

def A_SGB_SOUND_A     equ $01
def A_SGB_SOUND_B     equ $02
def A_SGB_SOUND_FLAGS equ $03
def A_SGB_SOUND_SCORE equ $04

; A_SGB_SOUND_FLAGS values
def S_SGB_SOUND_A_PITCH  equ 0
    def SGB_SOUND_A_PITCH_0     equ 0 << S_SGB_SOUND_A_PITCH
    def SGB_SOUND_A_PITCH_1     equ 1 << S_SGB_SOUND_A_PITCH
    def SGB_SOUND_A_PITCH_2     equ 2 << S_SGB_SOUND_A_PITCH
    def SGB_SOUND_A_PITCH_3     equ 3 << S_SGB_SOUND_A_PITCH
def S_SGB_SOUND_A_VOLUME equ 2
    def SGB_SOUND_A_VOLUME_HIGH equ 0 << S_SGB_SOUND_A_VOLUME
    def SGB_SOUND_A_VOLUME_MED  equ 1 << S_SGB_SOUND_A_VOLUME
    def SGB_SOUND_A_VOLUME_LOW  equ 2 << S_SGB_SOUND_A_VOLUME
    def SGB_SOUND_A_VOLUME_OFF  equ 3 << S_SGB_SOUND_A_VOLUME
def S_SGB_SOUND_B_PITCH  equ 4
    def SGB_SOUND_B_PITCH_0     equ 0 << S_SGB_SOUND_B_PITCH
    def SGB_SOUND_B_PITCH_1     equ 1 << S_SGB_SOUND_B_PITCH
    def SGB_SOUND_B_PITCH_2     equ 2 << S_SGB_SOUND_B_PITCH
    def SGB_SOUND_B_PITCH_3     equ 3 << S_SGB_SOUND_B_PITCH
def S_SGB_SOUND_B_VOLUME equ 6
    def SGB_SOUND_B_VOLUME_HIGH equ 0 << S_SGB_SOUND_B_VOLUME
    def SGB_SOUND_B_VOLUME_MED  equ 1 << S_SGB_SOUND_B_VOLUME
    def SGB_SOUND_B_VOLUME_LOW  equ 2 << S_SGB_SOUND_B_VOLUME

; A_SGB_SOUND_A values
def SGB_SOUND_A_RETRIGGER       equ $00
def SGB_SOUND_A_NINTENDO        equ $01
def SGB_SOUND_A_GAME_OVER       equ $02
def SGB_SOUND_A_DROP            equ $03
def SGB_SOUND_A_OK_A            equ $04
def SGB_SOUND_A_OK_B            equ $05
def SGB_SOUND_A_SELECT_A        equ $06
def SGB_SOUND_A_SELECT_B        equ $07
def SGB_SOUND_A_SELECT_C        equ $08
def SGB_SOUND_A_ERROR           equ $09
def SGB_SOUND_A_CATCH           equ $0A
def SGB_SOUND_A_KNOCK           equ $0B
def SGB_SOUND_EXPLOSION_SMALL   equ $0C
def SGB_SOUND_EXPLOSION_MEDIUM  equ $0D
def SGB_SOUND_EXPLOSION_LARGE   equ $0E
def SGB_SOUND_DEFEAT_A          equ $0F
def SGB_SOUND_DEFEAT_B          equ $10
def SGB_SOUND_HIT_A             equ $11
def SGB_SOUND_HIT_B             equ $12
def SGB_SOUND_A_BREATH_IN       equ $13
def SGB_SOUND_A_ROCKET_A        equ $14
def SGB_SOUND_A_ROCKET_B        equ $15
def SGB_SOUND_A_ESCAPING_BUBBLE equ $16
def SGB_SOUND_A_JUMP            equ $17
def SGB_SOUND_A_JUMP_FAST       equ $18
def SGB_SOUND_A_JET_TAKEOFF     equ $19
def SGB_SOUND_A_JET_LANDING     equ $1A
def SGB_SOUND_A_CUP_BREAKING    equ $1B
def SGB_SOUND_A_GLASS_BREAKING  equ $1C
def SGB_SOUND_A_LEVEL_UP        equ $1D
def SGB_SOUND_A_INSERT_AIR      equ $1E
def SGB_SOUND_A_SWORD_SWING     equ $1F
def SGB_SOUND_A_WATER_FALLING   equ $20
def SGB_SOUND_A_FIRE            equ $21
def SGB_SOUND_A_WALL_COLLAPSING equ $22
def SGB_SOUND_A_CANCEL          equ $23
def SGB_SOUND_A_WALKING         equ $24
def SGB_SOUND_A_BLOCKING_STRIKE equ $25
def SGB_SOUND_A_PICTURE_FLOATS  equ $26
def SGB_SOUND_A_FADE_IN         equ $27
def SGB_SOUND_A_FADE_OUT        equ $28
def SGB_SOUND_A_WINDOW_OPENING  equ $29
def SGB_SOUND_A_WINDOW_CLOSING  equ $2A
def SGB_SOUND_A_LASER_BIG       equ $2B
def SGB_SOUND_A_STONE_GATE      equ $2C
def SGB_SOUND_A_TELEPORTATION   equ $2D
def SGB_SOUND_A_LIGHTNING       equ $2E
def SGB_SOUND_A_EARTHQUAKE      equ $2F
def SGB_SOUND_A_LASER_SMALL     equ $30
def SGB_SOUND_A_STOP            equ $80

; A_SGB_SOUND_B values
def SGB_SOUND_B_RETRIGGER       equ $00
def SGB_SOUND_B_APPLAUSE_SMALL  equ $01
def SGB_SOUND_B_APPLAUSE_MED    equ $02
def SGB_SOUND_B_APPLAUSE_LARGE  equ $03
def SGB_SOUND_B_WIND            equ $04
def SGB_SOUND_B_RAIN            equ $05
def SGB_SOUND_B_STORM           equ $06
def SGB_SOUND_B_STORM_W_THUNDER equ $07
def SGB_SOUND_B_LIGHTNING       equ $08
def SGB_SOUND_B_EARTHQUAKE      equ $09
def SGB_SOUND_B_AVALANCHE       equ $0A
def SGB_SOUND_B_WAVE            equ $0B
def SGB_SOUND_B_RIVER           equ $0C
def SGB_SOUND_B_WATERFALL       equ $0D
def SGB_SOUND_B_RUNNING_SMALL   equ $0E
def SGB_SOUND_B_RUNNING_HORSE   equ $0F
def SGB_SOUND_B_WARNING         equ $10
def SGB_SOUND_B_CAR_APPROACHING equ $11
def SGB_SOUND_B_JET_FLYING      equ $12
def SGB_SOUND_B_UFO_FLYING      equ $13
def SGB_SOUND_B_ELECTOMAGNETIC  equ $14
def SGB_SOUND_B_SCORE_UP        equ $15
def SGB_SOUND_B_FIRE            equ $16
def SGB_SOUND_B_CAMERA_SHUTTER  equ $17
def SGB_SOUND_B_WRITE           equ $18
def SGB_SOUND_B_SHOW_UP         equ $19
def SGB_SOUND_B_STOP            equ $80


; -- SGB_PAL_SET ($0A) --------------------------------------------------------

def A_SGB_PAL_SET_PAL_0 equ $01 ; $01-$02
def A_SGB_PAL_SET_PAL_1 equ $03 ; $03-$04
def A_SGB_PAL_SET_PAL_2 equ $05 ; $05-$06
def A_SGB_PAL_SET_PAL_3 equ $07 ; $07-$08
def A_SGB_PAL_SET_FLAGS equ $09

; A_SGB_PAL_SET_FLAGS values
def S_SGB_PAL_SET_ATF_NUM   equ 0 ; bit 0-5
def S_SGB_PAL_SET_MASK_EN   equ 6
    def SGB_PAL_SET_CANCEL_MASK_EN equ 1 << S_SGB_PAL_SET_MASK_EN
def S_SGB_PAL_SET_APPLY_ATF equ 7
    def SGB_PAL_SET_APPLY_ATF      equ 1 << S_SGB_PAL_SET_APPLY_ATF


; -- SGB_ATRC_EN ($0C) --------------------------------------------------------

def A_SGB_ATRC_EN_ATRC equ $01

; A_SGB_ATRC_EN_ATRC values
def A_SGB_ATRC_EN_ATRC_ENABLE  equ $00
def A_SGB_ATRC_EN_ATRC_DISABLE equ $01


; -- SGB_ICON_EN ($0E) --------------------------------------------------------

def A_SGB_ICON_EN_FLAGS equ $01

; A_SGB_ICON_EN_FLAGS values
def S_SGB_ICON_EN_BUILTIN_PAL     equ 0
    def SGB_ICON_EN_ENABLE_BUILTIN_PAL      equ 0 << S_SGB_ICON_EN_BUILTIN_PAL
    def SGB_ICON_EN_DISABLE_BUILTIN_PAL     equ 1 << S_SGB_ICON_EN_BUILTIN_PAL
def S_SGB_ICON_EN_CONTR_SCREEN    equ 1
    def SGB_ICON_EN_ENABLE_CONTR_SCREEN     equ 0 << S_SGB_ICON_EN_CONTR_SCREEN
    def SGB_ICON_EN_DISABLE_CONTR_SCREEN    equ 1 << S_SGB_ICON_EN_CONTR_SCREEN
def S_SGB_ICON_EN_PACKET_TRANSFER equ 2
    def SGB_ICON_EN_ENABLE_PACKET_TRANSFER  equ 0 << S_SGB_ICON_EN_PACKET_TRANSFER
    def SGB_ICON_EN_DISABLE_PACKET_TRANSFER equ 1 << S_SGB_ICON_EN_PACKET_TRANSFER


; -- SGB_MLT_REQ ($11) --------------------------------------------------------

def A_SGB_MLT_REQ_PLAYERS equ $01

; A_SGB_MLT_REQ_PLAYERS values
def SGB_MLT_REQ_PLAYERS_ONE  equ %00
def SGB_MLT_REQ_PLAYERS_TWO  equ %01
def SGB_MLT_REQ_PLAYERS_FOUR equ %11


; -- SGB_CHR_TRN ($13) --------------------------------------------------------

def A_SGB_CHR_TRN_DEST equ $01

; A_SGB_CHR_TRN_DEST values
def SGB_CHR_TRN_DEST_BG_0  equ %00
def SGB_CHR_TRN_DEST_BG_1  equ %01
def SGB_CHR_TRN_DEST_OBJ_0 equ %10
def SGB_CHR_TRN_DEST_OBJ_1 equ %11


; -- SGB_PCT_TRN ($14) --------------------------------------------------------

; SGB border: BG map entry high byte values
def S_SGB_BORDER_PALETTE equ 2 ; bit 2-4
    def SGB_BORDER_PAL4  equ 4 << S_SGB_BORDER_PALETTE
    def SGB_BORDER_PAL5  equ 5 << S_SGB_BORDER_PALETTE
    def SGB_BORDER_PAL6  equ 6 << S_SGB_BORDER_PALETTE
def S_SGB_BORDER_XFLIP   equ 6
    def SGB_BORDER_XFLIP equ 1 << S_SGB_BORDER_XFLIP
def S_SGB_BORDER_YFLIP   equ 7
    def SGB_BORDER_YFLIP equ 1 << S_SGB_BORDER_YFLIP


; -- SGB_ATTR_SET ($16) -------------------------------------------------------

def A_SGB_ATTR_SET_FILE_NUMBER equ $01

; A_SGB_ATTR_SET_FILE_NUMBER values
def S_SGB_ATTR_SET_MASK_EN equ 6
    def SGB_ATTR_SET_CANCEL_MASK_EN equ 1 << S_SGB_ATTR_SET_MASK_EN


; -- SGB_MASK_EN ($17) --------------------------------------------------------

def A_SGB_MASK_EN_MASK equ $01

; A_SGB_MASK_EN_MASK values
def SGB_MASK_EN_MASK_CANCEL  equ $00
def SGB_MASK_EN_MASK_FREEZE  equ $01
def SGB_MASK_EN_MASK_BLACK   equ $02
def SGB_MASK_EN_MASK_COLOR_0 equ $03

endc ; SGB_INC
