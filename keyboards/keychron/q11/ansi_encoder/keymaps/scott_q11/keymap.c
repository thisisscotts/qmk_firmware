/* Copyright 2023 @ Keychron (https://www.keychron.com)
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



/**********************************************************************************************************
 *                                              Debugging
 **********************************************************************************************************/

//#include "print.h"

// void keyboard_post_init_user(void) {
//   Customise these values to desired behaviour
//   debug_enable=true;
//   debug_matrix=true;
//   debug_keyboard=true;
//   debug_mouse=true;
// }

/**********************************************************************************************************
 *                                              Combos
 **********************************************************************************************************/

// define combo names
enum combos {
    COMBO_HOME,
    COMBO_PGUP,
    COMBO_DELETE,
    COMBO_END_KEY, // "COMBO_END" is already used in QMK source elsewhere
    COMBO_PGDN,
    COMBO_BSPC,
    COMBO_LYR0,
    COMBO_LYR1,
    COMBO_LYR2,
    COMBO_LYR3,

    COMBO_LENGTH // nifty trick to avoid manually specifying how many combos you have
};

uint16_t COMBO_LEN = COMBO_LENGTH; // nifty trick continued

// define keys that make up combos

// Left hand
const uint16_t PROGMEM fd_combo[] = {KC_F, KC_D, COMBO_END};
const uint16_t PROGMEM ds_combo[] = {KC_D, KC_S, COMBO_END};
const uint16_t PROGMEM re_combo[] = {KC_R, KC_E, COMBO_END};
// Right hand
const uint16_t PROGMEM jk_combo[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM kl_combo[] = {KC_K, KC_L, COMBO_END};
const uint16_t PROGMEM ui_combo[] = {KC_U, KC_I, COMBO_END};
// Layers
const uint16_t PROGMEM fj_combo[] = {KC_F, KC_J, COMBO_END};
const uint16_t PROGMEM dk_combo[] = {KC_D, KC_K, COMBO_END};
const uint16_t PROGMEM sl_combo[] = {KC_S, KC_L, COMBO_END};
const uint16_t PROGMEM ascln_combo[] = {KC_A, KC_SCLN, COMBO_END};

// map combo names to their keys and the key they trigger
combo_t key_combos[] = {
    // Left hand
    [COMBO_DELETE]  = COMBO(fd_combo, KC_DELETE),
    [COMBO_HOME]    = COMBO(ds_combo, KC_HOME),
    [COMBO_PGUP]    = COMBO(re_combo, KC_PGUP),
    // Right hand
    [COMBO_BSPC]    = COMBO(jk_combo, KC_BSPC),
    [COMBO_END_KEY] = COMBO(kl_combo, KC_END),
    [COMBO_PGDN]    = COMBO(ui_combo, KC_PGDN),
    // Layers
    [COMBO_LYR0]    = COMBO(fj_combo, TO(0)),
    [COMBO_LYR1]    = COMBO(dk_combo, TO(1)),
    [COMBO_LYR2]    = COMBO(sl_combo, TO(2)),
    [COMBO_LYR3]    = COMBO(ascln_combo, TO(3)),
};


/**********************************************************************************************************
 *                                              Custom Keycodes
 **********************************************************************************************************/

enum custom_keycodes_scott {
  CP_SIMP,
  PA_SIMP,
  PA_PEML,
  PA_WEML
};


/**********************************************************************************************************
 *                                              Layers
 **********************************************************************************************************/

enum layers{
    LAYER_00,
    LAYER_01,
    LAYER_02,
    LAYER_03
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [LAYER_00] = LAYOUT_91_ansi(
        KC_MUTE,  KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,     KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,     KC_F12,   KC_HOME,  KC_END,   KC_MUTE,
        CP_SIMP,  KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,      KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,    KC_EQL,   KC_BSPC,            KC_PGUP,
        PA_SIMP,  KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,      KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,    KC_RBRC,  KC_BSLS,            KC_PGDN,
        KC_DEL,   KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,      KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,              KC_ENT,             KC_DEL,
        _______,  KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,      KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,              KC_RSFT,  KC_UP,
        _______,  KC_LCTL,  KC_LWIN,  KC_LALT,  MO(LAYER_01),       KC_BSPC,                       KC_SPC,             KC_RALT,  MO(LAYER_01),KC_RCTL, KC_LEFT,  KC_DOWN,  KC_RGHT),

    [LAYER_01] = LAYOUT_91_ansi(
        _______,  _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,            _______,
        _______,  _______,  _______,  KC_PGUP,  KC_UP,    KC_PGDN,  _______,   _______,  KC_7,     KC_8,     KC_9,     _______,  _______,    _______,  _______,            _______,
        _______,  _______,  _______,  KC_LEFT,  KC_DOWN,  KC_RGHT,  _______,   _______,  KC_4,     KC_5,     KC_6,     _______,  _______,              _______,            _______,
        _______,  _______,            _______,  _______,  _______,  _______,   _______,  KC_1,     KC_2,     KC_3,     _______,  _______,              _______,  TO(2),
        _______,  _______,  _______,  _______,  _______,            KC_SPC,                        KC_0,               _______,  _______,    _______,  _______,  TO(0),    _______),

    [LAYER_02] = LAYOUT_91_ansi(
        _______,  _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,            _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,            _______,
        _______,  _______,  _______,  PA_WEML,  _______,  _______,  _______,   _______,  _______,  _______,  PA_PEML,  _______,  _______,              _______,            _______,
        _______,  _______,            _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,  _______,              _______,  TO(3),
        _______,  _______,  _______,  _______,  _______,            _______,                       _______,            _______,  _______,    _______,  _______,  TO(1),    _______),

    [LAYER_03] = LAYOUT_91_ansi(
        RGB_TOG,  _______,  KC_BRID,  KC_BRIU,  _______,  _______,  RGB_VAD,   RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,    KC_VOLU,  _______,  _______,  RGB_TOG,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,            _______,
        _______,  RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,   _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,            _______,
        _______,  _______,  RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,   _______,  _______,  _______,  _______,  _______,  _______,              _______,            _______,
        _______,  _______,            _______,  _______,  _______,  _______,   _______,  NK_TOGG,  _______,  _______,  _______,  _______,              _______,  TO(0),
        _______,  _______,  _______,  _______,  _______,            _______,                       _______,            _______,  _______,    _______,  _______,  TO(2),    _______)
};


/**********************************************************************************************************
 *                                              Encoder
 **********************************************************************************************************/

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [LAYER_00] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [LAYER_01] = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______) },
    [LAYER_02] = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______) },
    [LAYER_03] = { ENCODER_CCW_CW(RGB_MOD, RGB_RMOD), ENCODER_CCW_CW(RGB_MOD, RGB_RMOD) }
};
#endif // ENCODER_MAP_ENABLE

/**********************************************************************************************************
 *                                              Processing
 **********************************************************************************************************/

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

    switch (keycode) {
        case CP_SIMP:  // Simple copy to clipboard.
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("c"));
            }
            break;

        case PA_SIMP:  // Simple paste from clipboard.
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("v"));
            }
            break;

        case PA_PEML:  // Paste personal email
            if (record->event.pressed) {
                SEND_STRING("this.is.scotts.email.address@gmail.com");
            }
            break;

        case PA_WEML:  // Paste work email
            if (record->event.pressed) {
                SEND_STRING("scottmorgan@chevron.com");
            }
            break;
    }

    return true;
}
