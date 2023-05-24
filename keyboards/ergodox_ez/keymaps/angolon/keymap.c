#include QMK_KEYBOARD_H
#include "version.h"

enum layers {
    BASE,  // default layer
    SYMB,  // symbols
    MDIA,  // media keys
};

enum custom_keycodes {
    DV_DOLLAR = SAFE_RANGE,
    DV_AMPERSAND,
    DV_SQUARE_OPEN,
    DV_CURLY_OPEN,
    DV_CURLY_CLOSE,
    DV_PAREN_OPEN,
    DV_EQUAL,
    DV_STAR,
    DV_PAREN_CLOSE,
    DV_PLUS,
    DV_SQUARE_CLOSE,
    DV_EXCLAIM,
    DV_HASH,
    DV_AT,
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   &%   |  [7  |  {5  |  }3  |  (1  |  =9  | HOME |           | END  |  *0  |  )2  |  +4  |  ]6  |  !8  |   #`   |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |   $~   |  ;:  |  ,<  |  .>  |   P  |   Y  | DEL  |           | Back |   F  |   G  |   C  |   R  |   L  |   /?   |
 * |--------+------+------+------+------+------|      |           | space|------+------+------+------+------+--------|
 * |   \|   |   A  |   O  |   E  |   U  |   I  |------|           |------|   D  |   H  |   T  |   N  |   S  |   -_   |
 * |--------+------+------+------+------+------| TAB  |           | F5   |------+------+------+------+------+--------|
 * | Ctrl-P |  '"  |   Q  |   J  |   K  |   X  |      |           |      |   B  |   M  |   W  |   V  |   Z  |   @^   |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |Grv/L1| PgDn | PgUp | Down |  Up  |                                       | Left |Right |Ctrl-B| SNIP | ~L1  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |Super | L3   |       | VolUp| Play |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | ALT  |       |VolDwn|        |      |
 *                                 | Shift|Enter |------|       |------|  ESC   |Space |
 *                                 |      |      | CTRL |       |Option|        |      |
 *                                 `--------------------'       `----------------------'
 */
[BASE] = LAYOUT_ergodox_pretty(
  // left hand
  DV_AMPERSAND,    DV_SQUARE_OPEN, KC_2,          KC_3,    KC_4,    KC_5,    KC_HOME,                KC_END,     KC_6,    KC_7,     KC_8,    KC_9,              KC_0,           KC_MINS,
  DV_DOLLAR,       KC_SEMICOLON,   KC_COMMA,      KC_DOT,  KC_P,    KC_Y,    KC_DEL,           KC_BACKSPACE,     KC_F,    KC_G,     KC_C,    KC_R,              KC_L,          KC_SLASH,
  KC_BACKSLASH,    KC_A,           KC_O,          KC_E,    KC_U,    KC_I,                                        KC_D,    KC_H,     KC_T,    KC_N,              KC_S,          KC_MINUS,
  KC_LSFT,         KC_QUOTE,       KC_Q,          KC_J,    KC_K,    KC_X,    KC_TAB,               KC_F5,        KC_B,    KC_M,     KC_W,    KC_V,              KC_Z,           KC_RSFT,
  LT(SYMB,KC_GRV), KC_PAGE_DOWN,   KC_PAGE_UP, KC_DOWN,   KC_UP,                                                       KC_LEFT, KC_RIGHT, KC_LBRC, KC_RBRC, TT(SYMB),
                                                           ALT_T(KC_APP), KC_LGUI,                KC_VOLD, KC_MEDIA_PLAY_PAUSE,
                                                                    OSM(MOD_LALT),                KC_VOLU,
                                           OSM(MOD_LSFT), KC_ENTER, OSM(MOD_LCTL),          OSM(MOD_LGUI),           KC_ESCAPE, KC_SPACE
),
/* Keymap 1: Symbol Layer
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |Version  |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |   !  |   @  |   {  |   }  |   |  |      |           |      |   Up |   7  |   8  |   9  |   *  |   F12  |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |   #  |   $  |   (  |   )  |   `  |------|           |------| Down |   4  |   5  |   6  |   +  |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |   %  |   ^  |   [  |   ]  |   ~  |      |           |      |   &  |   1  |   2  |   3  |   \  |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | EPRM  |      |      |      |      |                                       |      |    . |   0  |   =  |      |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |Animat|      |       |Toggle|Solid |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |Bright|Bright|      |       |      |Hue-  |Hue+  |
 *                                 |ness- |ness+ |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[SYMB] = LAYOUT_ergodox_pretty(
  // left hand
  _______,    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______,     _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
  _______, KC_EXLM, KC_AT,   KC_LCBR, KC_RCBR, KC_PIPE, _______,     _______, KC_UP,   KC_7,    KC_8,    KC_9,    KC_ASTR, KC_F12,
  _______, KC_HASH, KC_DLR,  KC_LPRN, KC_RPRN, KC_GRV,               KC_DOWN, KC_4,    KC_5,    KC_6,    KC_PLUS, _______,
  _______, KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_TILD, _______,     _______, KC_AMPR, KC_1,    KC_2,    KC_3,    KC_BSLS, _______,
  EE_CLR,  _______, _______, _______, _______,                                         _______, KC_DOT,  KC_0,    KC_EQL,  _______,
                                               RGB_MOD, _______,     RGB_TOG, RGB_M_P,
                                                        _______,     _______,
                                      RGB_VAD, RGB_VAI, _______,     _______, RGB_HUD, RGB_HUI
),
/* Keymap 2: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      | MsUp |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |MsLeft|MsDown|MsRght|      |------|           |------|      |      |      |      |      |  Play  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      | Prev | Next |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      | Lclk | Rclk |                                       |VolUp |VolDn | Mute |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |Brwser|
 *                                 |      |      |------|       |------|      |Back  |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[MDIA] = LAYOUT_ergodox_pretty(
  // left hand
  _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, KC_MS_U, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
  _______, _______, KC_MS_L, KC_MS_D, KC_MS_R, _______,                       _______, _______, _______, _______, _______, KC_MPLY,
  _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, KC_MPRV, KC_MNXT, _______, _______,
  _______, _______, _______, KC_BTN1, KC_BTN2,                                         KC_VOLU, KC_VOLD, KC_MUTE, _______, _______,

                                               _______, _______,     _______, _______,
                                                        _______,     _______,
                                      _______, _______, _______,     _______, _______, KC_WBAK
),
};
// clang-format on

// Because some dvorak keys get mapped to more than one traditional key depending on the shift modifier,
// we'll need to store these so that we can unregister it when incompatible key/shift inputs are entered.

typedef struct dv_key_info_t {
    uint16_t dv_key;
    uint16_t kb_key;
    uint8_t virtual_shift_mods;
} dv_key_info;

const static dv_key_info DV_NO_KEY = { .dv_key = 0, .kb_key = 0, .virtual_shift_mods = 0 };
static dv_key_info dv_key_down = DV_NO_KEY;
static uint8_t physical_shift_mods = 0;

dv_key_info dv_to_kb_key(uint16_t dv_key, bool shifted) {
    dv_key_info key = { .dv_key = dv_key, .kb_key = 0, .virtual_shift_mods = 0 };
    switch (dv_key) {
        case DV_DOLLAR: key.kb_key = shifted ? KC_GRAVE : KC_4;
                        key.virtual_shift_mods = MOD_MASK_SHIFT;
                        break;

        case DV_AMPERSAND: key.kb_key = shifted ? KC_5 : KC_7;
                           key.virtual_shift_mods = MOD_MASK_SHIFT;
                           break;

        case DV_SQUARE_OPEN: key.kb_key = shifted ? KC_7 : KC_LEFT_BRACKET;
                             break;
    }

    return key;
}

void swap_dv_key(dv_key_info next_key) {
    // Unregister the existing key if we have one
    if (dv_key_down.kb_key) {
        unregister_code16(dv_key_down.kb_key);
    }

    // If there's no next dvorak key, restore the physical shift modifiers
    // by hacking them into the stored NO_DV_KEY 
    if (!next_key.dv_key) {
        next_key.virtual_shift_mods = physical_shift_mods;
    }

    // Change modifiers as necessary.
    uint8_t current_mods = get_mods();
    if (current_mods != next_key.virtual_shift_mods) {
        uint8_t to_del = current_mods & ~next_key.virtual_shift_mods;
        uint8_t to_add = next_key.virtual_shift_mods & ~current_mods;
        if (to_del) {
            del_mods(to_del);
        }
        if (to_add) {
            add_mods(to_add);
        }
    }

    // Register the new key if it exists.
    if (next_key.kb_key) {
        register_code16(next_key.kb_key);
    }

    // Persist state.
    dv_key_down = next_key;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    uint8_t os_shift = get_oneshot_mods() & MOD_MASK_SHIFT;
    bool shifted = physical_shift_mods || os_shift;
    uint8_t mods;
    dv_key_info mapped;
    switch (keycode) {
        case OSM(MOD_LSFT):
        case KC_LEFT_SHIFT:
        case KC_RIGHT_SHIFT:
            if (IS_QK_ONE_SHOT_MOD(keycode)) {
                mods = QK_ONE_SHOT_MOD_GET_MODS(keycode);
            } else {
                mods = MOD_BIT(keycode);
            }

            if (record->event.pressed) {
                physical_shift_mods |= mods;
            } else {
                physical_shift_mods &= ~mods;
            }

            if (dv_key_down.dv_key) {
                // Only swap the key-code being sent if shift is being pressed,
                // or released after being held for more than a tap's length.
                // We can't really do anything sensible with a tap (I think?).
                // TODO: maybe we can do something more sensible?
                if (record->event.pressed || !record->tap.count) {
                    mapped = dv_to_kb_key(dv_key_down.dv_key, record->event.pressed);
                } else {
                    mapped = DV_NO_KEY;
                }
                swap_dv_key(mapped);
                return false;
            } else {
                return true;
            }

        default:
            mapped = dv_to_kb_key(keycode, shifted);
            if (mapped.kb_key) {
                if (record->event.pressed) {
                    // the first time a dv key is pressed, it will interfere with 
                    // other non-dv keys, so turn them off before we mess
                    // with shift
                    if (!dv_key_down.dv_key) {
                        clear_keyboard_but_mods();
                    }
                    swap_dv_key(mapped);
                    return false;
                } else {
                    // releasing the currently held dv key
                    if (keycode == dv_key_down.dv_key) {
                        swap_dv_key(DV_NO_KEY);
                    }

                    // In the else case, the keyboard has released a key which we've already ungeristered.
                    return false;
                }
            } else {
                // DV keys mess with KB keys, and the converse is also true. So when we push a
                // KB key with a DV key still held, we need to unregister the DV key.
                if (dv_key_down.dv_key && record->event.pressed) {
                    swap_dv_key(DV_NO_KEY);
                }
                return true;

            }
            break;
    }
    return true;
}

// Runs just one time when the keyboard initializes.
void keyboard_post_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
    rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
};

// Runs whenever there is a layer state change.
layer_state_t layer_state_set_user(layer_state_t state) {
    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();

    uint8_t layer = get_highest_layer(state);
    switch (layer) {
        case 0:
#ifdef RGBLIGHT_COLOR_LAYER_0
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
            break;
        case 1:
            ergodox_right_led_1_on();
#ifdef RGBLIGHT_COLOR_LAYER_1
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
#endif
            break;
        case 2:
            ergodox_right_led_2_on();
#ifdef RGBLIGHT_COLOR_LAYER_2
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
#endif
            break;
        case 3:
            ergodox_right_led_3_on();
#ifdef RGBLIGHT_COLOR_LAYER_3
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_3);
#endif
            break;
        case 4:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
#ifdef RGBLIGHT_COLOR_LAYER_4
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_4);
#endif
            break;
        case 5:
            ergodox_right_led_1_on();
            ergodox_right_led_3_on();
#ifdef RGBLIGHT_COLOR_LAYER_5
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_5);
#endif
            break;
        case 6:
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
#ifdef RGBLIGHT_COLOR_LAYER_6
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
#endif
            break;
        case 7:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
#ifdef RGBLIGHT_COLOR_LAYER_7
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_7);
#endif
            break;
        default:
            break;
    }

    return state;
};
