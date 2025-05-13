#include QMK_KEYBOARD_H

enum layers {
    _MN, // main
    _SM, // symbols
    _NM, // numbers
    _FN, // fn
    _MS, // mouse movements
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_MN] = LAYOUT_5x6(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,                         KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_BSPC,
        KC_ESC , KC_A   , KC_S   , KC_D   , KC_F   , KC_G   ,                         KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_ENT ,
        KC_LSFT, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   ,                         KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, KC_RSFT,
                          XXXXXXX, XXXXXXX,                                                             XXXXXXX, XXXXXXX,
                                                      KC_LALT, KC_SPC ,     MO(_SM), MO(_NM),
                                                      XXXXXXX, KC_LCTL,     MO(_FN), XXXXXXX,
                                                      XXXXXXX, KC_LGUI,     KC_RGUI, XXXXXXX
    ),
    [_SM] = LAYOUT_5x6(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        _______, KC_GRV , KC_TILD, KC_LBRC, KC_LCBR, _______,                         _______, KC_RCBR, KC_RBRC, _______, _______, _______,
        _______, KC_BSLS, KC_QUOT, KC_DQUO, KC_PIPE, _______,                         _______, KC_EQL , KC_PLUS, KC_MINS, KC_UNDS, _______,
        _______, _______, _______, _______, _______, _______,                         _______, _______, _______, _______, _______, _______,
                          XXXXXXX, XXXXXXX,                                                             XXXXXXX, XXXXXXX,
                                                      _______, _______,     _______, _______,
                                                      XXXXXXX, _______,     _______, XXXXXXX,
                                                      XXXXXXX, _______,     _______, XXXXXXX
    ),
    [_NM] = LAYOUT_5x6(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        _______, KC_EXLM, KC_AT  , KC_HASH, KC_DLR , KC_PERC,                         KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
        _______, KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,                         KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , _______,
        _______, _______, _______, _______, _______, _______,                         _______, _______, _______, _______, _______, _______,
                          XXXXXXX, XXXXXXX,                                                             XXXXXXX, XXXXXXX,
                                                      _______, _______,     _______, _______,
                                                      XXXXXXX, _______,     _______, XXXXXXX,
                                                      XXXXXXX, _______,     _______, XXXXXXX
    ),
    [_FN] = LAYOUT_5x6(
        XXXXXXX, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  ,                         KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 ,
        _______, KC_PSCR, KC_VOLD, KC_MUTE, KC_VOLU, KC_DEL ,                         KC_F12 , KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, _______,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                         KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, XXXXXXX, _______,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
                          KC_HOME, KC_END ,                                                             KC_INS , KC_LSCR,
                                                      _______, _______,     KC_RCTL, KC_RALT,
                                                      XXXXXXX, _______,     _______, XXXXXXX,
                                                      XXXXXXX, _______,     _______, XXXXXXX
    ),
};
