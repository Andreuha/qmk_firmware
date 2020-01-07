#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 16
#define _NAVIGATION 3

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
/*this is to make lower/raise act as spacebars as well*/
  LOWER=LT(_LOWER,KC_SPACE),
  RAISE=LT(_RAISE,KC_SPACE),
  //LOWER,
  //RAISE,
  ADJUST,
  NAVIGATION,
};

// #define KC_ KC_TRNS
#define _______ KC_TRNS
#define XXXXXXX KC_NO
#define XXXX KC_NO

#define NAVSPC LT( 3, KC_SPC)
#define LWRSPC LT( 1, KC_SPC)
#define RSESPC LT( 2, KC_SPC)
#define CAD LCTL(LALT(KC_DELETE))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT(
  //,--------+--------+--------+--------+--------+--------+--------.        ,--------+--------+--------+--------+--------+--------+--------.
     KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_PSCR,          KC_EQL, KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN,    KC_BSPC,
  //|--------+--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------+--------|
     KC_ESC,  KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    KC_DEL,           KC_MINS,  KC_H,    KC_N,    KC_E,    KC_I,    KC_O,   KC_QUOT,
  //|--------+--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------+--------|
     KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_ENT,             KC_BSLS,  KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, SFT_T(KC_ENT),
  //|--------+--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------+--------|
     KC_LCTL, LCTL(KC_LSFT), KC_LGUI, KC_LALT,    NAVSPC,   RAISE,            LOWER, NAVSPC,            KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT
  //`--------+--------+--------+--------+--------+--------+--------/        \--------+--------+--------+--------+--------+--------+--------'
  ),

  [_LOWER] = LAYOUT(
  //,--------+--------+--------+--------+--------+--------+--------.        ,--------+--------+--------+--------+--------+--------+--------.
     KC_GRV,  KC_F1,  KC_F2,   KC_F3,  KC_F4,  XXXXXXX,    _______,             KC_LBRC,    XXXXXXX,    KC_UNDS, KC_PLUS,  KC_LCBR,  KC_RCBR,    KC_DEL,
  //|--------+--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------+--------|
     KC_DEL,  KC_F5,  KC_F6,   KC_F7,  KC_F8,  XXXXXXX,   _______,            KC_RBRC,    XXXXXXX,    KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
  //|--------+--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------+--------|
     _______, KC_F9,  KC_F10,  KC_F11, KC_F12,  XXXXXXX,  _______,           _______,  XXXXXXX,    XXXXXXX,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
  //|--------+--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------+--------|
     _______, _______, _______, _______,           KC_SPC,   _______,           _______,  KC_SPC,             KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
  //`--------+--------+--------+--------+--------+--------+--------/        \--------+--------+--------+--------+--------+--------+--------'
  ),

  [_RAISE] = LAYOUT(
  //,--------+--------+--------+--------+--------+--------+--------.        ,--------+--------+--------+--------+--------+--------+--------.
     KC_TILD,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,    _______,         _______,    KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,    KC_BSPC,
  //|--------+--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------+--------|
     KC_DEL,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    _______,             _______,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------+--------|
     _______, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    _______,             _______,  XXXXXXX,    XXXXXXX,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
  //|--------+--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------+--------|
     _______, _______, _______, _______,           KC_SPC,   _______,           _______,  KC_SPC,             KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
  //`--------+--------+--------+--------+--------+--------+--------/        \--------+--------+--------+--------+--------+--------+--------'
  ),

  [_ADJUST] = LAYOUT(
  //,-~-------+--------+--------+--------+--------+--------+--------.        ,--------+--------+--------+--------+--------+--------+--------.
     RESET,  XXXX,    XXXX,    XXXX,    KC_PAUSE,    XXXX,    XXXX,            XXXX,    KC_7,    KC_8,    KC_9,    XXXX,    XXXX,  XXXX,
  //|--------+--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------+--------|
     CAD,    XXXX,    XXXX,    KC_SCROLLLOCK,    XXXX,    XXXX,    XXXX,             XXXX,    KC_4,    KC_5,    KC_6,    KC_INSERT,    XXXX,    XXXX,
  //|--------+--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------+--------|
     KC_CAPS, XXXX,    XXXX,    XXXX,    XXXX,    XXXX,    XXXX,             KC_0,    KC_1,    KC_2,    KC_3,    XXXX,    XXXX, XXXX,
  //|--------+--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------+--------|
     XXXX,    XXXX,    XXXX,    XXXX,           _______,    _______,           _______,    _______,        KC_DOT,    XXXX,    XXXX, XXXX
  //`--------+--------+--------+--------+--------+--------+--------/        \--------+--------+--------+--------+--------+--------+--------'
),

[_NAVIGATION] = LAYOUT(
//,--------+--------+--------+--------+--------+--------+--------.        ,--------+--------+--------+--------+--------+--------+--------.
   XXXXXXX,  XXXX,    XXXX,    XXXX,    XXXX,    XXXX,    RESET,             KC_RCBR,    XXXX,    KC_HOME, KC_PGDN, KC_PGUP, KC_END,    KC_BSPC,
//|--------+--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------+--------|
   KC_DEL,  XXXX,    XXXX,    KC_LSFT,    KC_LCTL,    XXXX,    _______,             KC_LCBR,     XXXX,    KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT,    KC_DEL,
//|--------+--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------+--------|
   KC_LSFT, XXXX,    XXXX,    XXXX,    XXXX,    XXXX,    _______,             _______,  XXXX,    XXXX,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
//|--------+--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------+--------|
   KC_LCTL, LCTL(KC_LSFT), KC_MENU, KC_LALT,           _______,   _______,           _______,  _______,            KC_LEFT, KC_UP,   KC_DOWN, KC_RGHT
//`--------+--------+--------+--------+--------+--------+--------/        \--------+--------+--------+--------+--------+--------+--------'
)

};







bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(tone_qwerty);
        #endif
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      /* return false gets commented out when using raise/lower as space bars*/
      //return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      /* return false gets commented out when using raise/lower as space bars*/
      //return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
    case NAVIGATION:
      if (record->event.pressed) {
        layer_on(_NAVIGATION);
      } else {
        layer_off(_NAVIGATION);
      }
      return false;
      break;
  }
  return true;
};
