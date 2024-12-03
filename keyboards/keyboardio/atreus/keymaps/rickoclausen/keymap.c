// Copyright (C) 2019, 2020  Keyboard.io, Inc
//
// this is the style you want to emulate.
// This is the canonical layout file for the Quantum project. If you want to add another keyboard,

#include QMK_KEYBOARD_H

enum layer_names {
    _QW,
    _RS,
    _LW,
    _BO,
    TD_MINUS_UNDERSCORE,
    TD_QUOTE,
    TD_EQUAL,
};


// Tap Dance definitions
tap_dance_action_t tap_dance_actions[] = {
    [TD_MINUS_UNDERSCORE] = ACTION_TAP_DANCE_DOUBLE(KC_MINUS, KC_UNDERSCORE),
    [TD_QUOTE] = ACTION_TAP_DANCE_DOUBLE(KC_QUOTE, KC_DOUBLE_QUOTE),
    [TD_EQUAL] = ACTION_TAP_DANCE_DOUBLE(KC_EQUAL, KC_PLUS)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QW] = LAYOUT( /* Qwerty */
    KC_Q,         KC_W,         KC_E,         KC_R,         KC_T,                                     KC_Y,                   KC_U,           KC_I,         KC_O,     KC_P    ,
    KC_A,         KC_S, LSFT_T(KC_D), KC_F,         KC_G,                                     KC_H,                   KC_J,   RSFT_T(KC_K), KC_L,     KC_SCLN ,
    LSFT_T(KC_Z), KC_X,         KC_C,         KC_V,         KC_B,             KC_GRV,     KC_BSLS,    KC_N,                   KC_M,           KC_COMM,      KC_DOT,   KC_SLSH ,
    KC_NO,        KC_NO,        KC_NO,        KC_LEFT_GUI,  LT(_RS, KC_SPC),  KC_TAB,     RALT_T(KC_ENTER),   LT(_LW, KC_BACKSPACE),  RCTL_T(KC_ESC), KC_NO,        KC_NO,    KC_NO ),

  [_RS] = LAYOUT( /* [> RAISE <] */
    KC_EXLM,  KC_AT, KC_HASH,   KC_DOLLAR,  KC_PERCENT,                   KC_CIRCUMFLEX,          KC_AMPERSAND,     KC_ASTERISK,      KC_NO,  KC_NO  ,
    KC_NO,    KC_NO, TD(TD_EQUAL), TD(TD_MINUS_UNDERSCORE) ,   TD(TD_QUOTE),                     KC_BACKSLASH,           KC_LEFT_PAREN,    KC_RIGHT_PAREN,   KC_NO,  KC_NO  ,
    KC_LSFT,  KC_NO, KC_NO,     KC_NO,      KC_NO,      KC_NO,  KC_NO,    KC_NO,                  KC_LEFT_BRACKET,  KC_RIGHT_BRACKET, KC_NO,  KC_NO  ,
    KC_NO,    KC_NO, KC_NO,     KC_NO,      KC_NO,      KC_NO, KC_ENTER, LT(_BO, KC_BACKSPACE),  KC_NO,            KC_NO,            KC_NO,  KC_NO ),

  [_LW] = LAYOUT( /* [> LOWER <] */
    KC_1,  KC_2,  KC_3,   KC_4,   KC_5,                             KC_NO, KC_NO,   KC_NO,  KC_NO,    KC_NO  ,
    KC_6,  KC_7,  KC_8,   KC_9,   KC_0,                             KC_LEFT, KC_DOWN, KC_UP,KC_RIGHT, KC_NO  ,
    KC_NO, KC_NO, KC_NO,  KC_NO,  KC_NO,            KC_NO, KC_NO,   KC_NO, KC_NO,   KC_NO,  KC_NO,    KC_NO  ,
    KC_NO, KC_NO, KC_NO,  KC_LEFT_GUI,  LT(_BO, KC_SPC),  KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO,  KC_NO,    KC_NO ),

    /*
     *
     */
  [_BO] = LAYOUT( /* [> RESET LAYER <] */
    KC_NO,  KC_NO, KC_NO, KC_NO, KC_NO,               KC_NO, KC_NO,   KC_NO,  KC_NO,  QK_BOOT  ,
    KC_NO,  KC_NO, KC_NO, KC_NO, KC_NO,               LALT(KC_LEFT),  KC_NO,  KC_NO,  LALT(KC_RIGHT),  KC_SPC  ,
    KC_NO,  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO,  KC_NO,  KC_NO  ,
    KC_NO,  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO,  KC_NO,  KC_NO )
};
