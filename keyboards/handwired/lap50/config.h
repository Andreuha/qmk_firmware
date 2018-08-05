/*
Layout created 2018 by Andrew Terentyev <andreuha@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation
*/

#ifndef CONFIG_H
#define CONFIG_H

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0x6060
#define DEVICE_VER      0x0001
#define MANUFACTURER    andylikescandy
#define PRODUCT         lap50
#define DESCRIPTION     Advanced Programming Keeb Layout

/* key matrix size */
#define MATRIX_ROWS 5
#define MATRIX_COLS 12

/*
 * Keyboard Matrix Assignments
 *
 * Change this to how you wired your keyboard
 * COLS: AVR pins used for columns, left to right
 * ROWS: AVR pins used for rows, top to bottom
 * DIODE_DIRECTION: COL2ROW = COL = Anode (+), ROW = Cathode (-, marked on diode)
 *                  ROW2COL = ROW = Anode (+), COL = Cathode (-, marked on diode)
 *
*/
#define MATRIX_ROW_PINS { D4, D0, D1, D2, D3 }
#define MATRIX_COL_PINS { C6, D7, B4, B5, B6, B2, B3, B1, F7, F6, F5, F4 }
#define UNUSED_PINS

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW



/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCING_DELAY 1


#define PERMISSIVE_HOLD



/*
 * Magic Key Options
 *
 * Magic keys are hotkey commands that allow control over firmware functions of
 * the keyboard. They are best used in combination with the HID Listen program,
 * found here: https://www.pjrc.com/teensy/hid_listen.html
 *
 * The options below allow the magic key functionality to be changed. This is
 * useful if your keyboard/keypad is missing keys and you want magic key support.
 *
 */

/* key combination for magic key command */
#define IS_COMMAND() ( \
    keyboard_report->mods == (MOD_BIT(KC_LSHIFT) | MOD_BIT(KC_RSHIFT)) \
)

/* control how magic key switches layers */
//#define MAGIC_KEY_SWITCH_LAYER_WITH_FKEYS  true
//#define MAGIC_KEY_SWITCH_LAYER_WITH_NKEYS  true
//#define MAGIC_KEY_SWITCH_LAYER_WITH_CUSTOM false

/* override magic key keymap */
//#define MAGIC_KEY_SWITCH_LAYER_WITH_FKEYS
//#define MAGIC_KEY_SWITCH_LAYER_WITH_NKEYS
//#define MAGIC_KEY_SWITCH_LAYER_WITH_CUSTOM
//#define MAGIC_KEY_HELP1          H
//#define MAGIC_KEY_HELP2          SLASH
//#define MAGIC_KEY_DEBUG          D
//#define MAGIC_KEY_DEBUG_MATRIX   X
//#define MAGIC_KEY_DEBUG_KBD      K
//#define MAGIC_KEY_DEBUG_MOUSE    M
//#define MAGIC_KEY_VERSION        V
//#define MAGIC_KEY_STATUS         S
//#define MAGIC_KEY_CONSOLE        C
//#define MAGIC_KEY_LAYER0_ALT1    ESC
//#define MAGIC_KEY_LAYER0_ALT2    GRAVE
//#define MAGIC_KEY_LAYER0         0
//#define MAGIC_KEY_LAYER1         1
//#define MAGIC_KEY_LAYER2         2
//#define MAGIC_KEY_LAYER3         3
//#define MAGIC_KEY_LAYER4         4
//#define MAGIC_KEY_LAYER5         5
//#define MAGIC_KEY_LAYER6         6
//#define MAGIC_KEY_LAYER7         7
//#define MAGIC_KEY_LAYER8         8
//#define MAGIC_KEY_LAYER9         9
//#define MAGIC_KEY_BOOTLOADER     PAUSE
//#define MAGIC_KEY_LOCK           CAPS
//#define MAGIC_KEY_EEPROM         E
//#define MAGIC_KEY_NKRO           N
//#define MAGIC_KEY_SLEEP_LED      Z

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT
//#define NO_ACTION_MACRO
//#define NO_ACTION_FUNCTION

#endif
