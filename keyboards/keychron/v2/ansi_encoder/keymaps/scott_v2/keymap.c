/* Copyright 2021 @ Keychron (https://www.keychron.com)
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
#include "keychron_common.h"
//#include "print.h"

// clang-format off

/**********************************************************************************************************
 *                                              Debugging
 **********************************************************************************************************/

//void keyboard_post_init_user(void) {
  // Customise these values to desired behaviour
  //debug_enable=true;
  //debug_matrix=true;
  //debug_keyboard=true;
  //debug_mouse=true;
//}

/**********************************************************************************************************
 *                                              Combos
 **********************************************************************************************************/

// define combo names
enum combos {
    COMBO_LCTL,
    COMBO_LALT,
    COMBO_LSFT,
    COMBO_HOME,
    COMBO_PGUP,
    COMBO_DELETE,
    COMBO_RCTL,
    COMBO_RALT,
    COMBO_RSFT,
    COMBO_END_KEY, // "COMBO_END" is already used in QMK source elsewhere
    COMBO_PGDN,
    COMBO_BSPC,
    COMBO_LYR0,
    COMBO_LYR1,
    COMBO_LYR2,
    COMBO_LYR3,
    // more here...

    COMBO_LENGTH // nifty trick to avoid manually specifying how many combos you have
};

uint16_t COMBO_LEN = COMBO_LENGTH; // nifty trick continued

// define keys that make up combos

// Left hand
const uint16_t PROGMEM fd_combo[] = {KC_F, KC_D, COMBO_END};
const uint16_t PROGMEM fs_combo[] = {KC_F, KC_S, COMBO_END};
const uint16_t PROGMEM ds_combo[] = {KC_D, KC_S, COMBO_END};
const uint16_t PROGMEM er_combo[] = {KC_E, KC_R, COMBO_END};
const uint16_t PROGMEM vc_combo[] = {KC_V, KC_C, COMBO_END};
const uint16_t PROGMEM fds_combo[] = {KC_F, KC_D, KC_S, COMBO_END};
// Right hand
const uint16_t PROGMEM jk_combo[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM jl_combo[] = {KC_J, KC_L, COMBO_END};
const uint16_t PROGMEM kl_combo[] = {KC_K, KC_L, COMBO_END};
const uint16_t PROGMEM ui_combo[] = {KC_U, KC_I, COMBO_END};
const uint16_t PROGMEM mcomma_combo[] = {KC_M, KC_COMMA, COMBO_END};
const uint16_t PROGMEM jkl_combo[] = {KC_J, KC_K, KC_L, COMBO_END};
// Layers
const uint16_t PROGMEM fj_combo[] = {KC_F, KC_J, COMBO_END};
const uint16_t PROGMEM dk_combo[] = {KC_D, KC_K, COMBO_END};
const uint16_t PROGMEM sl_combo[] = {KC_S, KC_L, COMBO_END};
const uint16_t PROGMEM ascln_combo[] = {KC_A, KC_SCLN, COMBO_END};

// map combo names to their keys and the key they trigger
combo_t key_combos[] = {
    // Left hand
    [COMBO_LCTL] = COMBO(fd_combo, KC_LCTL),
    [COMBO_LALT] = COMBO(fs_combo, KC_LALT),
    [COMBO_LSFT] = COMBO(ds_combo, KC_LSFT),
    [COMBO_HOME] = COMBO(er_combo, KC_HOME),
    [COMBO_PGUP] = COMBO(vc_combo, KC_PGUP),
    [COMBO_DELETE] = COMBO(fds_combo, KC_DELETE),
    // Right hand
    [COMBO_RCTL] = COMBO(jk_combo, KC_RCTL),
    [COMBO_RALT] = COMBO(jl_combo, KC_RALT),
    [COMBO_RSFT] = COMBO(kl_combo, KC_RSFT),
    [COMBO_END_KEY] = COMBO(ui_combo, KC_END),
    [COMBO_PGDN] = COMBO(mcomma_combo, KC_PGDN),
    [COMBO_BSPC] = COMBO(jkl_combo, KC_BSPC),
    // Layers
    [COMBO_LYR0] = COMBO(fj_combo, TO(0)),
    [COMBO_LYR1] = COMBO(dk_combo, TO(1)),
    [COMBO_LYR2] = COMBO(sl_combo, TO(2)),
    [COMBO_LYR3] = COMBO(ascln_combo, TO(3)),
    // more here...
};

/**********************************************************************************************************
 *                                              Custom Keycodes
 **********************************************************************************************************/

enum custom_keycodes_scott {
  CP_OPN = SAFE_RANGE,
  CP_TOEN,
  CP_TOHM,
  CP_LINE,
  PA_EMAIL
};


/**********************************************************************************************************
 *                                              Processing
 **********************************************************************************************************/

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // Keychron custom codes
    if (!process_record_keychron(keycode, record)) {
        return false;

    // Else Scott's custom codes
    } else {
        switch (keycode) {
            case CP_OPN:  // Copies the selected text to clipboard, opens a new browser window, pastes and goes.
                if (record->event.pressed) {
                    SEND_STRING(SS_LCTL("c") SS_DELAY(50) SS_LCTL("tv") SS_TAP(X_ENT));
                }
                break;

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

            case PA_EMAIL:  // Send email when keycode is pressed
                if (record->event.pressed) {
                    SEND_STRING("this.is.scotts.email.address@gmail.com");
                }
                break;
        }
    }

    return true;
}


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
    [LAYER_00] = LAYOUT_ansi_67(
        KC_ESC,  KC_1,     KC_2,     KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,          KC_MUTE,
        KC_TAB,  KC_Q,     KC_W,     KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,          KC_DEL,
        KC_CAPS, KC_A,     KC_S,     KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,  KC_QUOT,            KC_ENT,           KC_HOME,
        KC_LSFT,           KC_Z,     KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,   KC_SLSH,            KC_RSFT, KC_UP,
        KC_LCTL, KC_LGUI,  KC_LALT,                             KC_SPC,                             KC_RALT,  MO(LAYER_01), MO(LAYER_02), KC_LEFT, KC_DOWN, KC_RGHT),

    [LAYER_01] = LAYOUT_ansi_67(
        KC_TILD, KC_F1,    KC_F2,    KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,   KC_F12,   _______,          _______,
        _______, _______,  _______,  KC_UP,   _______, _______, _______, KC_7,    KC_8,    KC_9,    KC_PMNS,  _______,  _______,  _______,          _______,
        _______, _______,  KC_LEFT,  KC_DOWN, KC_RGHT, _______, _______, KC_4,    KC_5,    KC_6,    KC_PPLS,  _______,            _______,          KC_END,
        _______,           _______,  _______, _______, _______, _______, KC_0,    KC_1,    KC_2,    KC_3,     _______,            _______, TO(2),
        _______, _______,  _______,                             _______,                            KC_DOT,   _______,  _______,  _______, TO(0),   _______),

    [LAYER_02] = LAYOUT_ansi_67(
        KC_GRV,  _______,  _______,  _______, _______, _______, _______, _______, _______, _______, _______,  _______,  _______,  _______,          _______,
        _______, _______,  _______,  _______, _______, _______, _______, _______, _______, _______, _______,  _______,  _______,  _______,          _______,
        _______, _______,  _______,  CP_LINE, CP_TOHM, _______, _______, CP_TOEN, CP_OPN,  PA_EMAIL, _______,  _______,            _______,          _______,
        _______,           _______,  _______, _______, _______, _______, _______, _______, _______, _______,  _______,            _______, TO(3),
        _______, _______,  _______,                             _______,                            _______,  _______,  _______,  _______, TO(1),   _______),

    [LAYER_03] = LAYOUT_ansi_67(
        _______, KC_BRID,  KC_BRIU,  KC_TASK, KC_FLXP, RGB_VAD, RGB_VAI, KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE,  KC_VOLD,  KC_VOLU,  _______,          RGB_TOG,
        RGB_TOG, RGB_MOD,  RGB_VAI,  RGB_HUI, RGB_SAI, RGB_SPI, _______, _______, _______, _______, _______,  _______,  _______,  _______,          _______,
        _______, RGB_RMOD, RGB_VAD,  RGB_HUD, RGB_SAD, RGB_SPD, _______, _______, _______, _______, _______,  _______,            _______,          _______,
        _______,           _______,  _______, _______, _______, _______, NK_TOGG, _______, _______, _______,  _______,            _______, TO(0),
        _______, _______,  _______,                             _______,                            _______,  _______,  _______,  _______, TO(2),   _______)
};


// Use a bool to determine whether to show default RGB or custom colours based on layer
bool custom_layer_rgb = false;

// Set bool depending on state of Windows/Mac switch
bool dip_switch_update_user(uint8_t index, bool active) {
    switch (index) {
        case 0:
            if(active) {
                //print("Dip switch active");
                custom_layer_rgb = true;
            } else {
                //print("Dip switch not active");
                custom_layer_rgb = false;
            }
            break;
    }
    return true;
}

// Display custom RGB colours per layer if the custom mode is selected
bool rgb_matrix_indicators_user(void) {
    if (custom_layer_rgb == true) {
        switch (get_highest_layer(layer_state)) {
            case LAYER_00:
                rgb_matrix_set_color_all(0,255,255); // Cyan
                break;
            case LAYER_01:
                rgb_matrix_set_color_all(255,128,0); // Orange
                break;
            case LAYER_02:
                rgb_matrix_set_color_all(0,255,0); // Green
                break;
            case LAYER_03:
                rgb_matrix_set_color_all(255,0,255); // Magenta
                break;
            default:
                break;
        }
    }
    return true;
}



/**********************************************************************************************************
 *                                              Encoder
 **********************************************************************************************************/

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [LAYER_00] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [LAYER_01] = { ENCODER_CCW_CW(_______, _______)},
    [LAYER_02] = { ENCODER_CCW_CW(_______, _______)},
    [LAYER_03] = { ENCODER_CCW_CW(RGB_VAD, RGB_VAI)}
};
#endif // ENCODER_MAP_ENABLE



