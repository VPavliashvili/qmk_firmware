// first custom keymap attempt for my avalanche/v4
// NOTE: this build is 60% with pinky broken off

#include QMK_KEYBOARD_H

#define T_LANG S(KC_LALT)
#define TD_MS TD(TD_MS_)

enum layers {
    _MN, // main
    _SM, // symbols
    _NM, // numbers
    _FN, // fn
    _MS, // mouse movements
    _GG, // gaming
};

// Define a type for as many tap dance states as you need
typedef enum {
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_DOUBLE_TAP
} td_state_t;

typedef struct {
    bool is_press_action;
    td_state_t state;
} td_tap_t;

enum tap_dance_aliases {
    TD_MS_
};

// Function associated with all tap dances
td_state_t cur_dance(tap_dance_state_t *state);

// Functions associated with individual tap dances
void ql_finished(tap_dance_state_t *state, void *user_data);
void ql_reset(tap_dance_state_t *state, void *user_data);

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_MN] = LAYOUT(
                 XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                 KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,                                     KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_BSPC,
        XXXXXXX, KC_ESC , KC_A   , KC_S   , KC_D   , KC_F   , KC_G   ,                                     KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_ENT , XXXXXXX,
                 KC_LSFT, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_N   , KC_M   , KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                                            KC_MUTE, KC_LGUI, MO(_SM), KC_SPC , KC_LCTL, TD_MS  , MO(_FN), MO(_NM), KC_RGUI, KC_MPLY
    ),
    [_SM] = LAYOUT(
                 _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                 _______, KC_GRV , KC_TILD, KC_LBRC, KC_LCBR, _______,                                     _______, KC_RCBR, KC_RBRC, _______, _______, _______,
        XXXXXXX, T_LANG , KC_BSLS, KC_QUOT, KC_DQUO, KC_PIPE, _______,                                     _______, KC_EQL , KC_PLUS, KC_MINS, KC_UNDS, _______, XXXXXXX,
                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                            _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
    [_NM] = LAYOUT(
                 _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                 _______, KC_EXLM, KC_AT  , KC_HASH, KC_DLR , KC_PERC,                                     KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
        XXXXXXX, _______, KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,                                     KC_6   , KC_7   , KC_8   , KC_9,    KC_0   , _______, XXXXXXX,
                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                            _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
    [_FN] = LAYOUT(
                 _______, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  ,                                     KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 ,
                 _______, KC_PSCR, XXXXXXX, XXXXXXX, XXXXXXX, KC_DEL ,                                     KC_F12 , KC_HOME, KC_PGDN, KC_PGUP, KC_END , _______,
        XXXXXXX, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                     KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, XXXXXXX, _______, XXXXXXX,
                 _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
                                            _______, TO(_GG), _______, _______, KC_LALT, KC_RALT, _______, _______, _______, _______
    ),
    [_MS] = LAYOUT(
                 _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
                 _______, _______, MS_WHLU, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
        _______, _______, _______, MS_WHLD, _______, MS_BTN1, MS_BTN1,                                     MS_LEFT, MS_DOWN, MS_UP  , MS_RGHT, _______, _______, _______,
                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                            _______, _______, _______, MS_BTN3, _______, _______, _______, _______, _______, _______
    ),
    [_GG] = LAYOUT( // TODO
                 KC_ESC , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,                                     KC_6   , KC_7   , KC_8   , KC_9,    KC_0   , KC_MINS,
                 KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,                                     KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_BSLS,
        XXXXXXX, KC_BSPC, KC_A   , KC_S   , KC_D   , KC_F   , KC_G   ,                                     KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_QUOT, XXXXXXX,
                 KC_LSFT, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , _______, _______, _______, _______, KC_N   , KC_M   , KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                                            _______, TO(_MN), KC_SPC , _______, _______, _______, _______, KC_ENT , _______, _______
    ),
};

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
    static int i = 0;

    if (index == 0) {
        // my specific encoder which I already soldered on pcb
        // is faulty and activates twice instead of once per cycle
        // making it skip every second signal is the fix
        i++;
        if (i % 2 == 0) {
            return false;
        }

        if (clockwise) {
            tap_code_delay(KC_VOLU, 100);
        } else {
            tap_code_delay(KC_VOLD, 100);
        }
    } else if (index == 1) { /* Second encoder */
        if (clockwise) {
            tap_code_delay(KC_MPRV, 100);
        } else {
            tap_code_delay(KC_MNXT, 100);
        }
    }
    return false;
}
#endif


#ifdef OLED_ENABLE
static void render_layer(void) {
    oled_write_P(PSTR("Layer: "), false);

    switch (get_highest_layer(layer_state)) {
        case _MN:
            // oled_write_ln_P(PSTR("main"), false);
            oled_write_ln_P(PSTR("main"), false);
            break;
        case _SM:
            oled_write_ln_P(PSTR("symbols"), false);
            break;
        case _NM:
            oled_write_ln_P(PSTR("numbers"), false);
            break;
        case _FN:
            oled_write_ln_P(PSTR("fn"), false);
            break;
        case _MS:
            oled_write_ln_P(PSTR("mouse"), false);
            break;
        case _GG:
            oled_write_ln_P(PSTR("gaming"), false);
            break;
        default:
            oled_write_ln_P(PSTR("no layer found"), false);
    }
}

// unfortunately using i2c for split connection
// forces same oled output for both halves
// so no separate screen rendering logic implemented
bool oled_task_user(void) {

    render_layer();

    return false;
}
#endif

// Determine the current tap dance state
td_state_t cur_dance(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (!state->pressed) return TD_SINGLE_TAP;
        else return TD_SINGLE_HOLD;
    } else if (state->count == 2) return TD_DOUBLE_TAP;
    else return TD_UNKNOWN;
}

// Initialize tap structure associated with example tap dance key
static td_tap_t ql_tap_state = {
    .is_press_action = true,
    .state = TD_NONE
};

// Functions that control what our tap dance key does
void ql_finished(tap_dance_state_t *state, void *user_data) {
    ql_tap_state.state = cur_dance(state);
    switch (ql_tap_state.state) {
        case TD_SINGLE_TAP:
            tap_code(KC_RCTL);
            break;
        case TD_DOUBLE_TAP:
            // Check to see if the layer is already set
            if (layer_state_is(_MS)) {
                // If already set, then switch it off
                layer_off(_MS);
            } else {
                // If not already set, then switch the layer on
                layer_on(_MS);
            }
            break;
        default:
            break;
    }
}

void ql_reset(tap_dance_state_t *state, void *user_data) {
    // If the key was held down and now is released then switch off the layer
    if (ql_tap_state.state == TD_SINGLE_HOLD || ql_tap_state.state == TD_DOUBLE_TAP) {
        layer_off(_MS);
    }
    ql_tap_state.state = TD_NONE;
}

tap_dance_action_t tap_dance_actions[] = {
    [TD_MS_] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, ql_finished, ql_reset)
};

// // Set a long-ish tapping term for tap-dance keys
// uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
//     switch (keycode) {
//         case QK_TAP_DANCE ... QK_TAP_DANCE_MAX:
//             return 275;
//         default:
//             return TAPPING_TERM;
//     }
// }
