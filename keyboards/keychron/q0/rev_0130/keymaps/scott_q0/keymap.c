/* Copyright 2022 @ Keychron (https://www.keychron.com)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H

enum layers {
    LAYER_00,
    LAYER_01,
    LAYER_02,
    LAYER_03
};

enum custom_keycodes {
  CP_OPN = SAFE_RANGE,
  CP_TOEN,
  CP_TOHM,
  CP_LINE
};


bool process_record_user(uint16_t keycode, keyrecord_t* record) {
  switch (keycode) {
    case CP_LINE:  // Selects the current line and copies it to the clipboard.
        if (record->event.pressed) {
            SEND_STRING(SS_TAP(X_HOME) SS_LSFT(SS_TAP(X_END)) SS_LCTL("c"));
        }
        break;

    case CP_TOHM:  // Selects from the current position to Home and copies it to the clipboard.
        if (record->event.pressed) {
            SEND_STRING(SS_LSFT(SS_TAP(X_HOME)) SS_LCTL("c"));
        }
        break;

    case CP_TOEN:  // Selects from the current position to End and copies it to the clipboard.
        if (record->event.pressed) {
            SEND_STRING(SS_LSFT(SS_TAP(X_END)) SS_LCTL("c"));
        }
        break;

    case CP_OPN:  // Copies the selected text to clipboard, opens a new browser window, pastes and goes.
        if (record->event.pressed) {
            SEND_STRING(SS_LCTL("c") SS_DELAY(50) SS_LCTL("tv") SS_TAP(X_ENT));
        }
        break;
    }

    return true;
}



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
        Layer: LAYER_00 - Default

        ┌────────┬────────┬────────┬────────┐
        │  Tab   │ Bk Spc │ Lyr Dn │ Lyr Up |   // Top Row
        ├────────┼────────┼────────┼────────┤
        │ Num Lk │ Num /  │ Num *  │ Num -  |   // Row
        ├────────┼────────┼────────┼────────┤
        │ Num 7  │ Num 8  │ Num 9  │  Num   |   // Row
        ├────────┼────────┼────────┤   +    │
        │ Num 4  │ Num 5  │ Num 6  │        |   // Row
        ├────────┼────────┼────────┼────────┤
        │ Num 1  │ Num 2  │ Num 3  │  Num   |   // Row
        ├────────┴────────┼────────┤  Ent   │
        │      Num 0      │ Num .  │        |   // Bottom Row
        └─────────────────┴────────┴────────┘
     */
    [LAYER_00] = LAYOUT_numpad_6x4(
        KC_BSPC,        KC_TAB,         TO(LAYER_03),   TO(LAYER_01),
        KC_NUM,         KC_PSLS,        KC_PAST,        KC_PMNS,
        KC_P7,          KC_P8,          KC_P9,
        KC_P4,          KC_P5,          KC_P6,          KC_PPLS,
        KC_P1,          KC_P2,          KC_P3,
        KC_P0,                          KC_PDOT,        KC_PENT),

    /*
        Layer: LAYER_01 - Arrows, Mouse
    */
    [LAYER_01] = LAYOUT_numpad_6x4(
        _______,        _______,        TO(LAYER_00),   TO(LAYER_02),
        KC_BTN1,        KC_MS_U,        KC_BTN2,        _______,
        KC_MS_L,        KC_MS_D,        KC_MS_R,
        KC_PGUP,        KC_UP,          KC_PGDN,        _______,
        KC_LEFT,        KC_DOWN,        KC_RIGHT,
        _______,                        _______,        _______),

    /*
        Layer: LAYER_02 - Media
    */
    [LAYER_02] = LAYOUT_numpad_6x4(
        _______,        _______,        TO(LAYER_01),   TO(LAYER_03),
        KC_MSEL,        KC_MUTE,        KC_VOLD,        KC_VOLU,
        _______,        KC_MPRV,        KC_MNXT,
        _______,        _______,        _______,        KC_MPLY,
        CP_LINE,        CP_TOHM,        CP_TOEN,
        _______,                        _______,        CP_OPN),

    /*
        Layer: LAYER_03 - TBD
    */
    [LAYER_03] = LAYOUT_numpad_6x4(
        _______,        _______,        TO(LAYER_02),   TO(LAYER_00),
        _______,        _______,        _______,        _______,
        _______,        _______,        _______,
        _______,        _______,        _______,        _______,
        _______,        _______,        _______,
        _______,                        _______,        _______)
};

bool rgb_matrix_indicators_user(void) {
    switch (get_highest_layer(layer_state)) {
        case LAYER_00:
            rgb_matrix_set_color_all(0,255,255); // Cyan
            break;
        case LAYER_01:
            rgb_matrix_set_color_all(255,128,0); // Orange
            break;
        case LAYER_02:
            rgb_matrix_set_color_all(255,0,255); // Magenta
            break;
        case LAYER_03:
            rgb_matrix_set_color_all(255,0,0); // Red
            break;
        default:
            break;
    }
    return true;
}
