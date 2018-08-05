#ifndef lap50_H
#define lap50_H

#include "quantum.h"

#define KEYMAP( \
    K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, K0B,  \
    K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, K1B,  \
    K20, K21, K22, K23, K24, K25, K26, K27, K28, K29,      K2B,  \
    K30,      K32, K33, K34, K35, K36, K37, K38, K39, K2A, K3B,  \
    K40,      K42, K44,           K46,                K4A, K4B  \
    ) { \
  {  K00,  K01,    K02,    K03,    K04,    K05,    K06,    K07,    K08,    K09,   K0A,   K0B,   },  \
  {  K10,  K11,    K12,    K13,    K14,    K15,    K16,    K17,    K18,    K19,   K1A,   K1B,   },  \
  {  K20,  K21,    K22,    K23,    K24,    K25,    K26,    K27,    K28,    K29,   KC_NO, K2B,   },  \
  {  K30,  KC_NO,  K32,    K33,    K34,    K35,    K36,    K37,    K38,    K39,   K2A,   K3B,   },  \
  {  K40,  KC_NO,  K42,    K44,    KC_NO,  KC_NO,  K46,    KC_NO,  KC_NO,  KC_NO, K4A,   K4B }   \
}

#endif
