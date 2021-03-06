#include "lap50.h"


// Key Combos
#define CTRLSFT LCTL(KC_LSFT)
#define CTLALTSFT LALT(LCTL(KC_LSFT))
#define CTLALTDEL LALT(LCTL(KC_DEL))
#define LTSYMWIN LT(2,KC_LGUI)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = KEYMAP( /* lap50 - QWERTY */
      KC_ESC,   KC_1,     KC_2,     KC_3,    KC_4,     KC_5,     KC_6,     KC_7,    KC_8,     KC_9,     KC_0,     KC_DEL,  \
      KC_TAB,   KC_Q,     KC_W,     KC_E,    KC_R,     KC_T,     KC_Y,     KC_U,    KC_I,     KC_O,     KC_P,     KC_BSPC,  \
      KC_CAPS,  KC_A,     KC_S,     KC_D,    KC_F,     KC_G,     KC_H,     KC_J,    KC_K,     KC_L,               KC_ENT,   \
      KC_LSFT,            KC_Z,     KC_X,     KC_C,    KC_V,     KC_B,     KC_N,     KC_M,    KC_COMM,  SFT_T(KC_DOT),SFT_T(KC_SLSH),  \
      KC_LCTL,  KC_LGUI,  KC_LALT,                     LT(1,KC_SPC),                                    KC_RALT,  MO(2) \
  ),
  [1] = KEYMAP( /* lap50 - Arrows */
      KC_GRV,   KC_F1,    KC_F2,     KC_F3,      KC_F4,       KC_F5,       KC_F6,       KC_F6,      KC_F6,      KC_F7,       KC_F10,    _______,  \
      KC_TAB,   XXXXXXX,  KC_UP,     XXXXXXX,    XXXXXXX,     XXXXXXX,     KC_HOME,    KC_PGDN,    KC_PGUP,     KC_END,      KC_MINS,   KC_EQL,  \
      XXXXXXX,  KC_LEFT,  KC_DOWN,   KC_RIGHT,   XXXXXXX,     XXXXXXX,     KC_LEFT,    KC_DOWN,    KC_UP,       KC_RIGHT,               _______,     \
      _______,            XXXXXXX,   XXXXXXX,    XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,    XXXXXXX,    XXXXXXX,     _______,    XXXXXXX,  \
      _______,  KC_LGUI,  _______,                     _______,                                                              CTRLSFT,    _______ \
  ),
  [2] = KEYMAP( /* lap50 - Empty */
      _______,  KC_F11,   KC_F12,    XXXXXXX,    XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,    XXXXXXX,    XXXXXXX,     XXXXXXX,    CTLALTDEL,  \
      _______,  XXXXXXX,  XXXXXXX,   XXXXXXX,    XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,    XXXXXXX,    KC_LBRC,     KC_RBRC,    KC_BSLS,  \
      _______,  XXXXXXX,  KC_PSCREEN,XXXXXXX,    XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,    KC_SCLN,    KC_QUOT,                 _______,   \
      _______,            XXXXXXX,   KC_PAUSE,   KC_SLCK,     KC_INSERT,     XXXXXXX,     XXXXXXX,    XXXXXXX,    LSFT(KC_COMM),SFT_T(LSFT(KC_DOT)),LSFT(KC_SLSH),  \
      _______,  _______,  _______,                     _______,                                                              _______,    _______ \
  ),
  [9] = KEYMAP( /* lap50 - Empty */
      _______,  _______,  _______,   _______,    _______,     _______,     _______,     _______,    _______,    _______,     _______,    _______,  \
      _______,  _______,  _______,   _______,    _______,     _______,     _______,     _______,    _______,    _______,     _______,    _______,  \
      _______,  _______,  _______,   _______,   _______,     _______,     _______,      _______,    _______,    _______,                 _______,   \
      _______,            _______,   _______,    _______,     _______,     _______,     _______,    _______,    _______,     _______,    _______,  \
      _______,  _______,  _______,                     _______,                                                              _______,    _______ \
  )
};

const uint16_t PROGMEM fn_actions[] = {

};


const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
          if (record->event.pressed) {
            register_code(KC_RSFT);
          } else {
            unregister_code(KC_RSFT);
          }
        break;
      }
    return MACRO_NONE;
};
