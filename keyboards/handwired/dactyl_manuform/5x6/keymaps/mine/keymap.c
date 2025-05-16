#include QMK_KEYBOARD_H

#define LGUIALT TD(LGUIALT_)
#define TD_FN TD(TD_FN_)

enum layers {
    _MN, // main
    _SM, // symbols
    _FN, // fn
    _MS, // mouse movements
};

typedef enum {
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_DOUBLE_TAP,
    TD_DOUBLE_HOLD
} td_state_t;

typedef struct {
    bool is_layer_active;
    td_state_t state;
} td_tap_t;

enum tap_dance_aliases {
    LGUIALT_,
    TD_FN_,
};

// Function associated with all tap dances
td_state_t cur_dance(tap_dance_state_t *state);

// Functions associated with individual tap dances
void on_each_tap_td_fn(tap_dance_state_t *state, void *user_data);
void td_fn_finished(tap_dance_state_t *state, void *user_data);
void td_fn_reset(tap_dance_state_t *state, void *user_data);

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_MN] = LAYOUT_5x6(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,                         KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_BSLS,
        KC_ESC , KC_A   , KC_S   , KC_D   , KC_F   , KC_G   ,                         KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_ENT ,
        KC_LSFT, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   ,                         KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, KC_RSFT,
                          KC_LBRC, KC_LCBR,                                                             KC_RCBR, KC_RBRC,
                                                      LGUIALT, KC_SPC ,     KC_BSPC, MO(_SM),
                                                      XXXXXXX, KC_LCTL,     TD_FN  , XXXXXXX,
                                                      XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX
    ),
    [_SM] = LAYOUT_5x6(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        _______, KC_EXLM, KC_AT  , KC_HASH, KC_DLR , KC_PERC,                         KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
        _______, KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,                         KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , _______,
        _______, KC_GRV , KC_QUOT, KC_DQUO, KC_TILD, _______,                         _______, KC_EQL , KC_PLUS, KC_MINS, KC_UNDS, _______,
                          XXXXXXX, XXXXXXX,                                                             XXXXXXX, XXXXXXX,
                                                      _______, _______,     _______, _______,
                                                      XXXXXXX, _______,     _______, XXXXXXX,
                                                      XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX
    ),
    [_FN] = LAYOUT_5x6(
        XXXXXXX, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  ,                         KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 ,
        _______, KC_PSCR, KC_VOLD, KC_MUTE, KC_VOLU, KC_DEL ,                         KC_F12 , KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, _______,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                         KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, XXXXXXX, _______,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
                          KC_HOME, KC_END ,                                                             KC_INS , KC_LSCR,
                                                      _______, _______,     KC_RCTL, KC_RALT,
                                                      XXXXXXX, _______,     _______, XXXXXXX,
                                                      XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX
    ),
    [_MS] = LAYOUT_5x6(
        _______, _______, _______, _______, _______, _______,                         _______, _______, _______, _______, _______, _______,
        _______, _______, MS_WHLU, _______, _______, _______,                         _______, _______, _______, _______, _______, _______,
        _______, _______, MS_WHLD, _______, MS_BTN1, MS_BTN1,                         MS_LEFT, MS_DOWN, MS_UP  , MS_RGHT, _______, _______,
        _______, _______, _______, _______, _______, _______,                         _______, _______, _______, _______, _______, _______,
                          _______, _______,                                                             _______, _______,
                                                      _______, MS_BTN3,     _______, _______,
                                                      _______, _______,     _______, _______,
                                                      _______, _______,     _______, _______
    ),
};

td_state_t cur_dance(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (!state->pressed) return TD_SINGLE_TAP;
        else return TD_SINGLE_HOLD;
    } else if (state->count == 2) {
        if (!state->pressed) return TD_DOUBLE_TAP;
        else return TD_DOUBLE_HOLD;
    }
    else return TD_UNKNOWN;
}

static td_tap_t td_fn_tap_state = {
    .is_layer_active = false,
    .state = TD_NONE
};

void on_each_tap_td_fn(tap_dance_state_t *state, void *user_data) {
    // On first tap, activate _FN layer
    if (state->count == 1) {
        layer_on(_FN);
        td_fn_tap_state.is_layer_active = true;
    }
    // On second tap, turn off _FN layer and activate _MS layer
    else if (state->count == 2) {
        layer_off(_FN);
        layer_on(_MS);
        td_fn_tap_state.is_layer_active = true;
    }
}

void td_fn_finished(tap_dance_state_t *state, void *user_data) {
    td_fn_tap_state.state = cur_dance(state);
}

void td_fn_reset(tap_dance_state_t *state, void *user_data) {
    if (td_fn_tap_state.state == TD_SINGLE_TAP || td_fn_tap_state.state == TD_SINGLE_HOLD) {
        // Turn off _FN layer if it was a single tap or hold
        layer_off(_FN);
    } else if (td_fn_tap_state.state == TD_DOUBLE_TAP || td_fn_tap_state.state == TD_DOUBLE_HOLD) {
        // Turn off _MS layer if it was a double tap or hold
        layer_off(_MS);
    }

    td_fn_tap_state.is_layer_active = false;
    td_fn_tap_state.state = TD_NONE;
}

tap_dance_action_t tap_dance_actions[] = {
    [LGUIALT_] = ACTION_TAP_DANCE_DOUBLE(KC_LALT, KC_LGUI),
    [TD_FN_] = ACTION_TAP_DANCE_FN_ADVANCED(on_each_tap_td_fn, td_fn_finished, td_fn_reset),
};
