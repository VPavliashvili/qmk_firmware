// first custom keymap attempt for my avalanche/v4
// NOTE: this build is 60% with pinky broken off

#include QMK_KEYBOARD_H

enum layers {
    _MN, // main
    _SM, // symbols
    _NM, // numbers
    _FN, // fn
    _MS, // mouse movements
    _GG, // gaming
};

#define T_LANG S(KC_LALT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_MN] = LAYOUT(
                 XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                 KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,                                     KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_BSLS,
        XXXXXXX, KC_BSPC, KC_A   , KC_S   , KC_D   , KC_F   , KC_G   ,                                     KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_QUOT, XXXXXXX,
                 KC_LSFT, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , KC_LALT, MO(_FN), MO(_MS), KC_ESC , KC_N   , KC_M   , KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                                            KC_MUTE, KC_LGUI, MO(_SM), KC_SPC , KC_LCTL, KC_RCTL, KC_ENT , MO(_NM), KC_RGUI, KC_MPLY
    ),
    [_SM] = LAYOUT(
                 _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                 _______, KC_GRV , KC_TILD, KC_LBRC, KC_LCBR, _______,                                     _______, KC_RCBR, KC_RBRC, _______, _______, _______,
        XXXXXXX, T_LANG , KC_BSLS, KC_QUOT, KC_DQUO, KC_PIPE, _______,                                     _______, KC_EQL , KC_PLUS, KC_MINS, KC_UNDS, _______, XXXXXXX,
                 _______, _______, _______, _______, _______, _______, _______, _______, _______, XXXXXXX, _______, _______, _______, _______, _______, _______,
                                            _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
    [_NM] = LAYOUT(
                 _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                 _______, KC_EXLM, KC_AT  , KC_HASH, KC_DLR , KC_PERC,                                     KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
        XXXXXXX, _______, KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,                                     KC_6   , KC_7   , KC_8   , KC_9,    KC_0   , _______, XXXXXXX,
                 _______, _______, _______, _______, _______, _______, _______, _______, _______, XXXXXXX, _______, _______, _______, _______, _______, _______,
                                            _______, _______, XXXXXXX, _______, _______, _______, _______, _______, _______, _______
    ),
    [_FN] = LAYOUT(
                 _______, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  ,                                     KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 ,
                 _______, KC_PSCR, XXXXXXX, XXXXXXX, XXXXXXX, KC_DEL ,                                     XXXXXXX, KC_HOME, KC_PGDN, KC_PGUP, KC_END , XXXXXXX,
        XXXXXXX, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                     KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, XXXXXXX, XXXXXXX, XXXXXXX,
                 _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, _______, KC_F12 , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
                                            _______, TO(_GG), _______, _______, _______, _______, _______, KC_RALT, _______, _______
    ),
    [_MS] = LAYOUT(
                 _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
                 _______, _______, MS_WHLU, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
        _______, _______, _______, MS_WHLD, _______, MS_BTN1, MS_BTN1,                                     MS_LEFT ,MS_DOWN ,MS_UP   ,MS_RGHT, _______, _______, _______,
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

bool oled_task_user(void) {

    render_layer();

    return false;
}
#endif
