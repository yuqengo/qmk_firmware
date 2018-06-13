#include "lets_split.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;


// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO
#define _______ KC_TRNS
#define JP_ZHTG KC_GRV  // hankaku/zenkaku|kanzi
#define JP_YEN  KC_INT3 // yen, |
#define JP_CIRC KC_EQL  // ^, ~
#define JP_AT   KC_LBRC // @, `
#define JP_LBRC KC_RBRC // [, {
#define JP_COLN KC_QUOT // :, *
#define JP_RBRC KC_NUHS // ], }
#define JP_BSLS KC_INT1 // \, _
#define JP_MHEN KC_INT5 // muhenkan
#define JP_HENK KC_INT4 // henkan
#define JP_KANA KC_INT2 // katakana/hiragana|ro-mazi


//Aliases for shifted symbols
#define JP_DQT  LSFT(KC_2)    // "
#define JP_AMPR LSFT(KC_6)    // &
#define JP_QUOT LSFT(KC_7)    // '
#define JP_LPRN LSFT(KC_8)    // (
#define JP_RPRN LSFT(KC_9)    // )
#define JP_EQL  LSFT(KC_MINS) // =
#define JP_TILD LSFT(JP_CIRC) // ~
#define JP_PIPE LSFT(JP_YEN)  // |
#define JP_GRV  LSFT(JP_AT)   // `
#define JP_LCBR LSFT(JP_LBRC) // {
#define JP_PLUS LSFT(KC_SCLN) // +
#define JP_ASTR LSFT(JP_COLN) // *
#define JP_RCBR LSFT(JP_RBRC) // }
#define JP_UNDS LSFT(JP_BSLS) // _

// These symbols are correspond to US101-layout.
#define JP_MINS KC_MINS // -
#define JP_SCLN KC_SCLN // ;
#define JP_COMM KC_COMM // ,
#define JP_DOT  KC_DOT  // .
#define JP_SLSH KC_SLSH // /
// shifted
#define JP_EXLM KC_EXLM // !
#define JP_HASH KC_HASH // #
#define JP_DLR  KC_DLR  // $
#define JP_PERC KC_PERC // %
#define JP_LT   KC_LT   // <
#define JP_GT   KC_GT   // >
#define JP_QUES KC_QUES // ?

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _FN 3
enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  FN,
};
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


	[_QWERTY] = KEYMAP( \
		KC_Q,  KC_W,   KC_E,           KC_R,  KC_T,    KC_LGUI, KC_APP,  KC_Y,    KC_U,  KC_I,           KC_O,   KC_P,   \
		KC_A,  KC_S,   KC_D,           KC_F,  KC_G,    KC_SPC,  KC_NO,   KC_H,    KC_J,  KC_K,           KC_L,   KC_MINS,\
		KC_Z,  KC_X,   KC_C,           KC_V,  KC_B,    KC_TAB,  KC_ENT,  KC_N,    KC_M,  KC_COMM,        KC_DOT, KC_SLSH,\
		FN,    KC_ESC, ALT_T(JP_MHEN), LOWER, KC_LSFT, KC_LCTL, KC_LCTL, KC_LSFT, RAISE, ALT_T(JP_HENK), KC_ESC, FN      \
    ), 

	[_LOWER] = KEYMAP( \
		KC_PGUP, KC_BTN1, KC_UP  , KC_BTN2, _______, _______, _______, KC_ESC,  KC_7, KC_8,    KC_9,    _______, \
		KC_BSPC, KC_LEFT, KC_DOWN, KC_RGHT, KC_DEL,  _______, _______, KC_SPC,  KC_4, KC_5,    KC_6,    _______, \
		KC_PGDN, KC_HOME, KC_BTN3, KC_END , _______, _______, _______, KC_ENT,  KC_1, KC_2,    KC_3,    _______, \
		_______, _______, _______, _______, _______, _______, _______, _______, KC_0, _______, _______, _______  \
    ),

	[_RAISE] = KEYMAP( \
		JP_TILD, JP_LBRC, JP_LCBR, JP_LPRN, JP_QUOT, _______, _______, JP_DQT,  JP_RPRN, JP_RCBR, JP_RBRC, JP_PIPE, \
		JP_EXLM, JP_AT  , JP_HASH, JP_DLR,  JP_PERC, _______, _______, JP_CIRC, JP_AMPR, JP_ASTR, JP_SCLN, JP_COLN, \
		JP_GRV,  _______, _______, _______, _______, _______, _______, _______, _______, JP_PLUS, JP_UNDS, JP_BSLS, \
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  \
    ),

	[_FN] = KEYMAP( \
		KC_BTN4, KC_BTN5, _______, _______, _______, RESET  , _______, _______, KC_F7,   KC_F8,   KC_F9,   KC_F12,  \
		_______, _______, _______, _______, _______, _______, _______, _______, KC_F4,   KC_F5,   KC_F6,   KC_F11,  \
		_______, _______, _______, _______, _______, _______, _______, _______, KC_F1,   KC_F2,   KC_F3,   KC_F10,  \
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  \
    )
};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
      } else {
        layer_off(_LOWER);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
      } else {
        layer_off(_RAISE);
      }
      return false;
      break;
    case FN:
      if (record->event.pressed) {
        layer_on(_FN);
      } else {
        layer_off(_FN);
      }
      return false;
      break;
  }
  return true;
}
