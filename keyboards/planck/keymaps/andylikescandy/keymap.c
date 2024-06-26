/* Copyright 2015-2017 Jack Humbert
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

#include "planck.h"
#include "action_layer.h"

extern keymap_config_t keymap_config;

enum planck_layers {
  _QWERTY,
  _COLEMAK,
  _DVORAK,
  _LOWER,
  _RAISE,
  _PLOVER,
  _ADJUST,
  _NAVIGATION
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  DVORAK,
  PLOVER,
  BACKLIT,
  EXT_PLV
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define _NAVIGATION 8
#define NAVL MO(_NAVIGATION)
#define NAVSPC LT( 8, KC_SPC)
//#define SHFTENT SHFT_T(KC_ENT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Qwerty
   * ,-----------------------------------------------------------------------------------.
   * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
   * |------+------+------+------+------+-------------+------+------+------+------+------|
   * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
   * |------+------+------+------+------+------|------+------+------+------+------+------|
   * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Shift |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * | Ctrl | CS   |  Alt | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
   * `-----------------------------------------------------------------------------------'
   */
  [_QWERTY] = {
    {KC_TAB,  KC_Q,           KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC},
    {KC_ESC,  KC_A,           KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT},
    {KC_LSFT, KC_Z,           KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, SFT_T(KC_ENT) },
    {KC_LCTL, LCTL(KC_LSFT),  KC_LGUI, KC_LALT, LOWER,   NAVSPC,  NAVSPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT}
  },

  /* Colemak
   * ,-----------------------------------------------------------------------------------.
   * | Tab  |   Q  |   W  |   F  |   P  |   G  |   J  |   L  |   U  |   Y  |   ;  | Bksp |
   * |------+------+------+------+------+-------------+------+------+------+------+------|
   * | Esc  |   A  |   R  |   S  |   T  |   D  |   H  |   N  |   E  |   I  |   O  |  "   |
   * |------+------+------+------+------+------|------+------+------+------+------+------|
   * | Shift|   Z  |   X  |   C  |   V  |   B  |   K  |   M  |   ,  |   .  |   /  |SftEnt|
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * | Ctrl | CS   |  Alt | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
   * `-----------------------------------------------------------------------------------'
   */
  [_COLEMAK] = {
    {KC_TAB,  KC_Q,           KC_W,    KC_F,    KC_P,    KC_G,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSPC},
    {KC_ESC,  KC_A,           KC_R,    KC_S,    KC_T,    KC_D,    KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT},
    {KC_LSFT, KC_Z,           KC_X,    KC_C,    KC_V,    KC_B,    KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, SFT_T(KC_ENT)  },
    {KC_LCTL, LCTL(KC_LSFT),  KC_LGUI, KC_LALT, LOWER,   NAVSPC,  NAVSPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT}
  },

  // /* Dvorak
  //  * ,-----------------------------------------------------------------------------------.
  //  * | Tab  |   "  |   ,  |   .  |   P  |   Y  |   F  |   G  |   C  |   R  |   L  | Bksp |
  //  * |------+------+------+------+------+-------------+------+------+------+------+------|
  //  * | Esc  |   A  |   O  |   E  |   U  |   I  |   D  |   H  |   T  |   N  |   S  |  /   |
  //  * |------+------+------+------+------+------|------+------+------+------+------+------|
  //  * | Shift|   ;  |   Q  |   J  |   K  |   X  |   B  |   M  |   W  |   V  |   Z  |Enter |
  //  * |------+------+------+------+------+------+------+------+------+------+------+------|
  //  * | Brite| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
  //  * `-----------------------------------------------------------------------------------'
  //  */
  [_DVORAK] = {
    {KC_TAB,  KC_QUOT,          KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_BSPC},
    {KC_ESC,  KC_A,             KC_O,    KC_E,    KC_U,    KC_I,    KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_QUOT},
    {KC_LSFT, KC_SCLN,          KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    SFT_T(KC_ENT) },
    {KC_LCTL, LCTL(KC_LSFT),    KC_LGUI, KC_LALT, LOWER,   NAVSPC,  NAVSPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT}
  },
  //
// /* Lower
// * ,-----------------------------------------------------------------------------------.
// * |   ~  |  F1  |  F2  |  F3  |  F4  |      |      |   _  |   +  |   {  |   }  | Bksp |
// * |------+------+------+------+------+-------------+------+------+------+------+------|
// * |  Del |  F5  |  F6  |  F7  |  F8  |      |      |   -  |   =  |   [  |   ]  |  |   |
// * |------+------+------+------+------+------|------+------+------+------+------+------|
// * |      |  F9  |  F10 |  F11 |  F12 |      |      |      |      |      |      |Enter |
// * |------+------+------+------+------+------+------+------+------+------+------+------|
// * |      |      |      |      |      |             |      | HOME | PGDN | PGUP | END  |
// * `-----------------------------------------------------------------------------------'
// */
[_LOWER] = {
  { KC_TILD, KC_F1,  KC_F2,   KC_F3,  KC_F4,  XXXXXXX,  XXXXXXX, KC_UNDS, KC_PLUS,  KC_LCBR,  KC_RCBR,   KC_BSPC },
  { KC_DEL , KC_F5,  KC_F6,   KC_F7,  KC_F8,  XXXXXXX,  XXXXXXX, KC_MINS, KC_EQL,   KC_LBRC,  KC_RBRC,   KC_PIPE },
  { _______, KC_F9,  KC_F10,  KC_F11, KC_F12, _______,  _______, _______, _______,  _______,  _______,   KC_ENT },
  { _______, _______, _______, _______, _______, KC_SPC, KC_SPC, _______, KC_HOME,  KC_PGDN,  KC_PGUP,   KC_END }
},

/* Raise
* ,-----------------------------------------------------------------------------------.
* |   `  |  !   |  @   |  #   |  $   |  %   |  ^   |   &  |   *  |  (   |   )  | Bksp |
* |------+------+------+------+------+-------------+------+------+------+------+------|
* | Del  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |  \   |
* |------+------+------+------+------+------|------+------+------+------+------+------|
* |      |      |      |      |      |      |      |      |      |      |      |Enter |
* |------+------+------+------+------+------+------+------+------+------+------+------|
* |      |      |      |      |      |             |      | HOME | PGDN | PGUP | END  |
* `-----------------------------------------------------------------------------------'
*/
[_RAISE] = {
  { KC_GRV,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,    KC_BSPC },
  { KC_DEL,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,       KC_BSLS },
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,    KC_ENT },
  { _______, _______, _______, _______, _______, KC_SPC, KC_SPC, _______, KC_HOME, KC_PGDN, KC_PGUP,    KC_END }
},

/* Plover layer (http://opensteno.org)
 * ,-----------------------------------------------------------------------------------.
 * |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |   S  |   T  |   P  |   H  |   *  |   *  |   F  |   P  |   L  |   T  |   D  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |   S  |   K  |   W  |   R  |   *  |   *  |   R  |   B  |   G  |   S  |   Z  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Exit |      |      |   A  |   O  |             |   E  |   U  |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */

[_PLOVER] = {
  {KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1   },
  {XXXXXXX, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC},
  {XXXXXXX, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT},
  {EXT_PLV, XXXXXXX, XXXXXXX, KC_C,    KC_V,    XXXXXXX, XXXXXXX, KC_N,    KC_M,    XXXXXXX, XXXXXXX, XXXXXXX}
},

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * | Reset|      |      |      |      |      |      |      |      |      |      | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |C.A.D.|      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | CAPS |      |      |      |      |      |      |Insert|PntScn|Scroll|Pause |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |Qwerty|Colemk|Dvorak|Plover|
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = {
  {RESET,               XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX },
  {LALT(LCTL(KC_DEL)),  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX},
  {KC_CAPSLOCK,         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_INS, KC_PSCR, KC_SLCK, KC_PAUS, XXXXXXX},
  {_______,             _______, _______, _______, _______, _______, _______, _______, QWERTY,  COLEMAK, DVORAK, XXXXXXX}  //PLOVER}
},
/* Navigation
* ,-----------------------------------------------------------------------------------.
* |      |      |      |      |      |      |      | Home | PgDn | PgUp | End  |ctlBsp|
* |------+------+------+------+------+-------------+------+------+------+------+------|
* |  Del |Ctl+A |      |Shift | Ctrl |      |      | Left | Down |  Up  |Right |  Del |
* |------+------+------+------+------+------|------+------+------+------+------+------|
* | C+S  |Ctl+z |Ctl+x |Ctl+c |Ctl+v |      |      |      |Shift |Shift |Shift |Enter |
* |------+------+------+------+------+------+------+------+------+------+------+------|
* |C+A+S |      |      |      |      |             |      |C+Left|C+Down| C+Up |C+Right|
* `-----------------------------------------------------------------------------------'
*/
[_NAVIGATION] = {
  {XXXXXXX,             XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,       XXXXXXX, XXXXXXX,       KC_HOME, KC_PGDN, KC_PGUP, KC_END,      LCTL(KC_BSPC) },
  {KC_DEL,              LCTL(KC_A), XXXXXXX, KC_LSFT, KC_LCTL,    XXXXXXX, XXXXXXX,       KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT,     KC_DEL},
  {LCTL(KC_LSFT),       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,       XXXXXXX, XXXXXXX,       XXXXXXX, KC_RSFT, KC_RSFT, KC_RSFT,         KC_ENT},
  {_______,             _______, _______,  _______, _______,      _______, _______,       LCTL(KC_LEFT), LCTL(KC_DOWN), LCTL(KC_UP), LCTL(KC_RGHT), _______}
}


};

#ifdef AUDIO_ENABLE
  float plover_song[][2]     = SONG(PLOVER_SOUND);
  float plover_gb_song[][2]  = SONG(PLOVER_GOODBYE_SOUND);
#endif

uint32_t layer_state_set_user(uint32_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        print("mode just switched to qwerty and this is a huge string\n");
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case COLEMAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_COLEMAK);
      }
      return false;
      break;
    case DVORAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_DVORAK);
      }
      return false;
      break;
    case BACKLIT:
      if (record->event.pressed) {
        register_code(KC_RSFT);
        #ifdef BACKLIGHT_ENABLE
          backlight_step();
        #endif
        PORTE &= ~(1<<6);
      } else {
        unregister_code(KC_RSFT);
        PORTE |= (1<<6);
      }
      return false;
      break;
    case PLOVER:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          stop_all_notes();
          PLAY_SONG(plover_song);
        #endif
        layer_off(_RAISE);
        layer_off(_LOWER);
        layer_off(_ADJUST);
        layer_on(_PLOVER);
        if (!eeconfig_is_enabled()) {
            eeconfig_init();
        }
        keymap_config.raw = eeconfig_read_keymap();
        keymap_config.nkro = 1;
        eeconfig_update_keymap(keymap_config.raw);
      }
      return false;
      break;
    case EXT_PLV:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(plover_gb_song);
        #endif
        layer_off(_PLOVER);
      }
      return false;
      break;
  }
  return true;
}
