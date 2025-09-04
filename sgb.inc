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
; SGB Packet Size
;******************************************************************************

def SGB_PACKET_SIZE             equ 16


;******************************************************************************
; SGB Command Prefixes
;******************************************************************************

def S_SGB_COMMAND               equ 3

def SGB_PAL01                   equ $00 << S_SGB_COMMAND
def SGB_PAL23                   equ $01 << S_SGB_COMMAND
def SGB_PAL03                   equ $02 << S_SGB_COMMAND
def SGB_PAL12                   equ $03 << S_SGB_COMMAND
def SGB_ATTR_BLK                equ $04 << S_SGB_COMMAND
def SGB_ATTR_LIN                equ $05 << S_SGB_COMMAND
def SGB_ATTR_DIV                equ $06 << S_SGB_COMMAND
def SGB_ATTR_CHR                equ $07 << S_SGB_COMMAND
def SGB_SOUND                   equ $08 << S_SGB_COMMAND
def SGB_SOU_TRN                 equ $09 << S_SGB_COMMAND
def SGB_PAL_SET                 equ $0A << S_SGB_COMMAND
def SGB_PAL_TRN                 equ $0B << S_SGB_COMMAND
def SGB_ATRC_EN                 equ $0C << S_SGB_COMMAND
def SGB_TEST_EN                 equ $0D << S_SGB_COMMAND
def SGB_ICON_EN                 equ $0E << S_SGB_COMMAND
def SGB_DATA_SND                equ $0F << S_SGB_COMMAND
def SGB_DATA_TRN                equ $10 << S_SGB_COMMAND
def SGB_MLT_REQ                 equ $11 << S_SGB_COMMAND
def SGB_JUMP                    equ $12 << S_SGB_COMMAND
def SGB_CHR_TRN                 equ $13 << S_SGB_COMMAND
def SGB_PCT_TRN                 equ $14 << S_SGB_COMMAND
def SGB_ATTR_TRN                equ $15 << S_SGB_COMMAND
def SGB_ATTR_SET                equ $16 << S_SGB_COMMAND
def SGB_MASK_EN                 equ $17 << S_SGB_COMMAND
def SGB_OBJ_TRN                 equ $18 << S_SGB_COMMAND
def SGB_PAL_PRI                 equ $19 << S_SGB_COMMAND
def SGB_STUB1                   equ $1A << S_SGB_COMMAND
def SGB_STUB2                   equ $1B << S_SGB_COMMAND
def SGB_STUB3                   equ $1C << S_SGB_COMMAND
def SGB_STUB4                   equ $1D << S_SGB_COMMAND
def SGB_STUB5                   equ $1E << S_SGB_COMMAND
def SGB_STUB6                   equ $1F << S_SGB_COMMAND


;******************************************************************************
; SGB_SOUND Packet Indices
;******************************************************************************

def A_SGB_SOUND_A               equ $01
def A_SGB_SOUND_B               equ $02
def A_SGB_SOUND_FLAGS           equ $03


;******************************************************************************
; SGB_SOUND_FLAGS Values
;******************************************************************************

def S_SGB_SOUND_A_PITCH   equ 0

    def SGB_SOUND_A_PITCH_0     equ 0 << S_SGB_SOUND_A_PITCH
    def SGB_SOUND_A_PITCH_1     equ 1 << S_SGB_SOUND_A_PITCH
    def SGB_SOUND_A_PITCH_2     equ 2 << S_SGB_SOUND_A_PITCH
    def SGB_SOUND_A_PITCH_3     equ 3 << S_SGB_SOUND_A_PITCH

def S_SGB_SOUND_A_VOLUME  equ 2

    def SGB_SOUND_A_VOLUME_HIGH equ 0 << S_SGB_SOUND_A_VOLUME
    def SGB_SOUND_A_VOLUME_MED  equ 1 << S_SGB_SOUND_A_VOLUME
    def SGB_SOUND_A_VOLUME_LOW  equ 2 << S_SGB_SOUND_A_VOLUME
    def SGB_SOUND_A_VOLUME_OFF  equ 3 << S_SGB_SOUND_A_VOLUME

def S_SGB_SOUND_B_PITCH   equ 4

    def SGB_SOUND_B_PITCH_0     equ 0 << S_SGB_SOUND_B_PITCH
    def SGB_SOUND_B_PITCH_1     equ 1 << S_SGB_SOUND_B_PITCH
    def SGB_SOUND_B_PITCH_2     equ 2 << S_SGB_SOUND_B_PITCH
    def SGB_SOUND_B_PITCH_3     equ 3 << S_SGB_SOUND_B_PITCH

def S_SGB_SOUND_B_VOLUME  equ 6

    def SGB_SOUND_B_VOLUME_HIGH equ 0 << S_SGB_SOUND_B_VOLUME
    def SGB_SOUND_B_VOLUME_MED  equ 1 << S_SGB_SOUND_B_VOLUME
    def SGB_SOUND_B_VOLUME_LOW  equ 2 << S_SGB_SOUND_B_VOLUME


;******************************************************************************
; SGB_SOUND_A Values
;******************************************************************************

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


;******************************************************************************
; SGB_SOUND_B Values
;******************************************************************************

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


;******************************************************************************
; SGB_MLT_REQ Packet Indices
;******************************************************************************

def A_SGB_MLT_REQ_PLAYERS       equ $01


;******************************************************************************
; SGB_MLT_REQ_PLAYERS Values
;******************************************************************************

def SGB_MLT_REQ_PLAYERS_ONE     equ $00
def SGB_MLT_REQ_PLAYERS_TWO     equ $01
def SGB_MLT_REQ_PLAYERS_FOUR    equ $01


;******************************************************************************
; SGB_CHR_TRN Packet Indices
;******************************************************************************

def A_SGB_CHR_TRN_DEST          equ $01


;******************************************************************************
; SGB_CHR_TRN_DEST Values
;******************************************************************************

def SGB_CHR_TRN_DEST_BG_0       equ $00
def SGB_CHR_TRN_DEST_BG_1       equ $01
def SGB_CHR_TRN_DEST_OBJ_0      equ $02
def SGB_CHR_TRN_DEST_OBJ_1      equ $03


;******************************************************************************
; SGB_MASK_EN Packet Indices
;******************************************************************************

def A_SGB_MASK_EN_MASK          equ $01


;******************************************************************************
; SGB_MASK_EN_MASK Values
;******************************************************************************

def SGB_MASK_EN_MASK_CANCEL     equ $00
def SGB_MASK_EN_MASK_FREEZE     equ $01
def SGB_MASK_EN_MASK_BLACK      equ $02
def SGB_MASK_EN_MASK_COLOR_0    equ $03

endc ; SGB_INC
