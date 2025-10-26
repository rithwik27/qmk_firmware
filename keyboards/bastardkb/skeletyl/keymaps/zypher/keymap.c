/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

#define _LAYER0 0
#define _LAYER1 1
#define _LAYER2 2
#define _LAYER3 3

enum custom_keycodes {
    LAYER0 = SAFE_RANGE,
    LAYER1,
    LAYER2,
    LAYER3,
    OFFICE,
    MW,
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case OFFICE:
        if (record->event.pressed) {
            SEND_STRING("p1");
            // when keycode QMKBEST is pressed
        } else {
            // when keycode QMKBEST is released
            SEND_STRING(SS_TAP(X_ENTER));
        }
        break;

    case MW:
        if (record->event.pressed) {
            SEND_STRING("p2");
            // when keycode QMKURL is pressed
        } else {
            // when keycode QMKURL is released
            SEND_STRING(SS_TAP(X_ENTER));
        }
        break;
    }
    return true;
};

 const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

 [_LAYER0] = LAYOUT_split_3x5_3(
    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
    LALT_T(KC_A), RCTL_T(KC_S), RGUI_T(KC_D), RSFT_T(KC_F), LT(1,KC_G), LT(1,KC_H), RSFT_T(KC_J), RGUI_T(KC_K), RCTL_T(KC_L), RALT_T(KC_QUOT),
    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,
    KC_LGUI, LT(1,KC_TAB), KC_BSPC, KC_SPC, LT(2,KC_ENT), LT(3,KC_ESC)
),

[_LAYER1] = LAYOUT_split_3x5_3(
    KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,
    LALT_T(KC_1), RCTL_T(KC_2), LGUI_T(KC_3), RSFT_T(KC_4), KC_5, KC_SCLN, RSFT_T(KC_MINS), LGUI_T(KC_EQL), RCTL_T(KC_LBRC), RALT_T(KC_RBRC),
    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_COLN, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR,
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO
),

[_LAYER2] = LAYOUT_split_3x5_3(
    OFFICE,  MW,      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_PGDN, KC_PGUP, KC_NO,   KC_NO,
    RALT_T(KC_NO), RCTL_T(KC_NO), RGUI_T(KC_GRV), RSFT_T(KC_BSLS), KC_NO, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_NO,
    KC_NO,   KC_NO,   KC_TILD, KC_PIPE, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
    KC_NO,   KC_NO,   KC_DEL,  KC_NO,   KC_NO,   KC_NO
),

[_LAYER3] = LAYOUT_split_3x5_3(
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,
    RALT_T(KC_NO), RCTL_T(KC_NO), RGUI_T(KC_NO), RSFT_T(KC_NO), KC_NO, KC_NO, RSFT_T(KC_NO), RGUI_T(KC_NO), RCTL_T(KC_NO), RALT_T(KC_NO),
    QK_BOOT, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO
)

};
