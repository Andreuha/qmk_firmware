#include QMK_KEYBOARD_H

#include "action_layer.h"



#define _COLEMAK 0
#define _QWERTY 1
#define _RAISE 2
#define _LOWER 3
#define _NAVIGATION 4


// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO
#define ooooooo KC_NO

//Switch Layouts
#define SWBASE M(_COLEMAK)
#define SWQWERTY M(_QWERTY)

// layer access
#define RSESPC LT( 2, KC_SPC)
#define LWRSPC LT( 3, KC_SPC)
#define NAVSPC LT( 4, KC_SPC)

// Key Combos
#define CTRLSFT LCTL(KC_LSFT)
#define CTLALTSFT LALT(LCTL(KC_LSFT))
#define CTLALTDEL LALT(LCTL(KC_DEL))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_COLEMAK] = LAYOUT( \
    KC_TAB,     KC_Q,     KC_W,     KC_F,     KC_P,     KC_G,    KC_LBRC,     ooooooo, ooooooo,              KC_RBRC,       KC_J,    KC_L,    KC_U,      KC_Y,      KC_SCLN,  KC_BSPC,         ooooooo,  ooooooo,  \
    KC_ESC,     KC_A,     KC_R,     KC_S,     KC_T,     KC_D,    KC_DEL,      ooooooo, ooooooo,              KC_BSLASH,     KC_H,    KC_N,    KC_E,      KC_I,      KC_O,     KC_QUOT,         ooooooo,  ooooooo,  \
    KC_LSFT,    KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,    KC_HOME,     ooooooo, ooooooo,              KC_END,        KC_K,    KC_M,    KC_COMM,   KC_DOT,    KC_SLSH,  SFT_T(KC_ENT),   ooooooo,  ooooooo,  \
    KC_LCTL,    CTRLSFT,  KC_LGUI,  KC_LALT,  LWRSPC,   NAVSPC,  CTLALTSFT,   ooooooo, ooooooo,              SFT_T(KC_ENT), NAVSPC,  RSESPC,  KC_LEFT,   KC_DOWN,   KC_UP,    CTL_T(KC_RIGHT), ooooooo,  ooooooo,  \
    ooooooo,    ooooooo,  ooooooo,  ooooooo,  ooooooo,  ooooooo, ooooooo,     ooooooo, ooooooo,              ooooooo,       ooooooo, ooooooo, ooooooo,   ooooooo,   ooooooo,  ooooooo,         ooooooo,  ooooooo,  \
    ooooooo,    ooooooo,  ooooooo,  ooooooo,  ooooooo,  ooooooo, ooooooo,     ooooooo, ooooooo,              ooooooo,       ooooooo, ooooooo, ooooooo,   ooooooo,   ooooooo,  ooooooo,         ooooooo,  ooooooo   \
),
[_QWERTY] = LAYOUT( \
  KC_TAB,     KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,    KC_LBRC,     ooooooo, ooooooo,               KC_RBRC,       KC_Y,    KC_U,    KC_I,      KC_O,      KC_P,     KC_BSPC,         ooooooo,  ooooooo,  \
  KC_ESC,     KC_A,     KC_S,     KC_D,     KC_F,     KC_G,    KC_DEL,      ooooooo, ooooooo,               KC_BSLASH,     KC_H,    KC_J,    KC_K,      KC_L,      KC_SCLN,  KC_QUOT,         ooooooo,  ooooooo,  \
  KC_LSFT,    KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,    KC_HOME,     ooooooo, ooooooo,               KC_END,        KC_N,    KC_M,    KC_COMM,   KC_DOT,    KC_SLSH,  SFT_T(KC_ENT),   ooooooo,  ooooooo,  \
  KC_LCTL,    CTRLSFT,  KC_LGUI,  KC_LALT,  LWRSPC,   NAVSPC,  CTLALTSFT,   ooooooo, ooooooo,               SFT_T(KC_ENT), NAVSPC,  RSESPC,  KC_LEFT,   KC_DOWN,   KC_UP,    CTL_T(KC_RIGHT), ooooooo,  ooooooo,  \
  ooooooo,    ooooooo,  ooooooo,  ooooooo,  ooooooo,  ooooooo, ooooooo,     ooooooo, ooooooo,               ooooooo,       ooooooo, ooooooo, ooooooo,   ooooooo,   ooooooo,  ooooooo,         ooooooo,  ooooooo,  \
  ooooooo,    ooooooo,  ooooooo,  ooooooo,  ooooooo,  ooooooo, ooooooo,     ooooooo, ooooooo,               ooooooo,       ooooooo, ooooooo, ooooooo,   ooooooo,   ooooooo,  ooooooo,         ooooooo,  ooooooo   \
),
[_RAISE] = LAYOUT( \
    CTLALTDEL,  KC_EXLM,  KC_AT,    KC_HASH,  KC_DLR,   KC_PERC,   XXXXXXX,  ooooooo, ooooooo,            XXXXXXX,  KC_CIRC,  KC_AMPR,  KC_ASTR,  KC_LPRN,  KC_RPRN,  _______, ooooooo, ooooooo,    \
    KC_DEL,     KC_1,     KC_2,     KC_3,     KC_4,     KC_5,      XXXXXXX,  ooooooo, ooooooo,            XXXXXXX,  KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     _______, ooooooo, ooooooo,   \
    _______,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,  ooooooo, ooooooo,            XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  _______, ooooooo, ooooooo,        \
    _______,    _______,  _______,  _______,  _______,  _______,   _______,  ooooooo, ooooooo,            _______,  _______,  _______,  _______,  _______,  _______,  _______, ooooooo, ooooooo,      \
    ooooooo,    ooooooo,  ooooooo,  ooooooo,  ooooooo,  ooooooo,   ooooooo,  ooooooo, ooooooo,            ooooooo,  ooooooo,  ooooooo,  ooooooo,  ooooooo,  ooooooo,  ooooooo, ooooooo, ooooooo,    \
    ooooooo,    ooooooo,  ooooooo,  ooooooo,  ooooooo,  ooooooo,   ooooooo,  ooooooo, ooooooo,            ooooooo,  ooooooo,  ooooooo,  ooooooo,  ooooooo,  ooooooo,  ooooooo, ooooooo, ooooooo    \
),
[_LOWER] = LAYOUT( \
    CTLALTDEL,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    XXXXXXX,   KC_PSCREEN,    ooooooo, ooooooo,            XXXXXXX,  XXXXXXX,  KC_UNDS,  KC_PLUS,  KC_LCBR,  KC_RCBR,  _______, ooooooo, ooooooo,    \
    KC_DEL,     KC_F5,    KC_F6,    KC_F7,    KC_F8,    XXXXXXX,   KC_SCROLLLOCK, ooooooo, ooooooo,            XXXXXXX,  XXXXXXX,  KC_MINS,  KC_EQL,   KC_LBRC,  KC_RBRC,  _______, ooooooo, ooooooo,   \
    _______,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   XXXXXXX,   KC_PAUSE,      ooooooo, ooooooo,            XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  _______, ooooooo, ooooooo,        \
    _______,    _______,  _______,  _______,  _______,  _______,   KC_INSERT,     ooooooo, ooooooo,            _______,  _______,  _______,  _______,  _______,  _______,  _______, ooooooo, ooooooo,      \
    ooooooo,    ooooooo,  ooooooo,  ooooooo,  ooooooo,  ooooooo,   ooooooo,       ooooooo, ooooooo,            ooooooo,  ooooooo,  ooooooo,  ooooooo,  ooooooo,  ooooooo,  ooooooo, ooooooo, ooooooo,    \
    ooooooo,    ooooooo,  ooooooo,  ooooooo,  ooooooo,  ooooooo,   ooooooo,       ooooooo, ooooooo,            ooooooo,  ooooooo,  ooooooo,  ooooooo,  ooooooo,  ooooooo,  ooooooo, ooooooo, ooooooo    \
),
[_NAVIGATION] = LAYOUT( \
    CTLALTDEL,  SWBASE,   SWQWERTY, XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  ooooooo,  ooooooo,            XXXXXXX,  XXXXXXX,  KC_HOME,  KC_PGDN,  KC_PGUP,  KC_END,   _______, ooooooo, ooooooo,        \
    KC_DEL,     _______,  XXXXXXX,  KC_LSFT,  KC_LCTL,  XXXXXXX,  _______,  ooooooo,  ooooooo,            _______,  XXXXXXX,  KC_LEFT,  KC_DOWN,  KC_UP,    KC_RIGHT, _______, ooooooo, ooooooo,        \
    KC_CAPS,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  _______,  ooooooo,  ooooooo,            _______,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  _______, ooooooo, ooooooo,       \
    _______,    _______,  _______,  _______,  _______,  _______,  _______,  ooooooo,  ooooooo,            _______,  _______,  _______,  _______,  _______,  _______,  _______, ooooooo, ooooooo,        \
    ooooooo,    ooooooo,  ooooooo,  ooooooo,  ooooooo,  ooooooo,  ooooooo,  ooooooo,  ooooooo,            ooooooo,  ooooooo,  ooooooo,  ooooooo,  ooooooo,  ooooooo,  ooooooo, ooooooo, ooooooo,        \
    ooooooo,    ooooooo,  ooooooo,  ooooooo,  ooooooo,  ooooooo,  ooooooo,  ooooooo,  ooooooo,            ooooooo,  ooooooo,  ooooooo,  ooooooo,  ooooooo,  ooooooo,  ooooooo, ooooooo, ooooooo      \
)


};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
      switch(id) {
        case _COLEMAK:
          if (record->event.pressed) {
            persistent_default_layer_set(1UL<<_COLEMAK);
          }
          break;
        case _QWERTY:
          if (record->event.pressed) {
            persistent_default_layer_set(1UL<<_QWERTY);
          }
          break;
      }
    return MACRO_NONE;
};
