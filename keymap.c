#include QMK_KEYBOARD_H

// qmk compile -kb ergotravel/rev1 -km qmk_ergotravel_keymap

// #define _QWERTY 0
// #define _LOWER 1
// #define _RAISE 2
// #define _ADJUST 16
// enum custom_keycodes {
//   QWERTY = SAFE_RANGE,
//   LOWER,
//   RAISE,
//   ADJUST,
// };
// #define CALTDEL LCTL(LALT(KC_DEL))
// #define TSKMGR LCTL(LSFT(KC_ESC))

enum my_keycodes {
  KC_UALT = SAFE_RANGE, // add new key code starting from qmk's safe value
};
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT(KC_ESC, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_PSCR, KC_DEL, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSLS, KC_TAB, KC_A, KC_S, KC_D, KC_F, KC_G, KC_GRV, KC_BSPC, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_SPC, ANY(KC_UALT), KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_LCTL, KC_LGUI, KC_LALT, KC_LALT, MO(1), LT(2,KC_SPC), LT(3,KC_ENT), MO(4), KC_LEFT, KC_UP, KC_DOWN, KC_RGHT),
  [1] = LAYOUT(KC_GRV, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_NO, KC_TRNS, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_NO, KC_1, KC_2, KC_3, KC_4, KC_5, KC_NO, KC_TRNS, KC_6, KC_7, KC_8, KC_9, KC_0, KC_F12, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, MO(5), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
  [2] = LAYOUT(KC_GRV, KC_EXLM, KC_CIRC, KC_AMPR, KC_LBRC, KC_UNDS, KC_NO, KC_TRNS, KC_NO, KC_RBRC, KC_BSLS, KC_NO, KC_NO, KC_NO, KC_NO, KC_MINS, KC_PLUS, KC_EQL, KC_LPRN, KC_LT, KC_NO, KC_TRNS, KC_GT, KC_RPRN, KC_SCLN, KC_QUES, KC_DQUO, KC_QUOT, KC_TRNS, KC_SLSH, KC_ASTR, KC_PIPE, KC_LCBR, KC_PERC, KC_TRNS, KC_TRNS, KC_HASH, KC_RCBR, KC_AT, KC_DLR, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_ENT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
  [3] = LAYOUT(KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_PGUP, KC_HOME, KC_UP, KC_END, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_NO, KC_NO, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_WH_U, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_WH_L, KC_WH_D, KC_WH_R, KC_NO),
  [4] = LAYOUT(KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_NLCK, KC_P7, KC_P8, KC_P9, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_NO, KC_P4, KC_P5, KC_P6, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_P1, KC_P2, KC_P3, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_P0, KC_PDOT, KC_COMM, KC_NO),
  [5] = LAYOUT(KC_NO, RESET, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, ANY(UC_MOD), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_MUTE, KC_VOLD, KC_NO, KC_VOLU, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_NO, KC_NO, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO)
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  // static uint8_t ualt_registeredkc = KC_NO;
  static bool ualt_active = false;

  switch (keycode) {
    case KC_UALT:
      // go into umlaut mode while held
      if (record->event.pressed) { // pressed
        ualt_active = true; 
      } else { // released
        ualt_active = false;
      }
      return false; // Skip all further processing of this key
      // break;
    default: // other keys
      if(ualt_active) { // umlaut mode
        // allow shift press/release to be sent in ualt mode, so uppercase letters dont depend on shift being pressed before ualt
        switch (keycode) {
          case KC_LSFT: 
            return true;
          case KC_RSFT:
            return true;
        }
        if (record->event.pressed) { // pressed any other key in umlaut mode
          bool shifted = get_mods() & MOD_MASK_SHIFT;
          switch (keycode) {
            case KC_A:
              if (shifted)
                send_unicode_string("Ä");
              else
                send_unicode_string("ä");
              break;
            case KC_O:
              if (shifted)
                send_unicode_string("Ö");
              else
                send_unicode_string("ö");
              break;
            case KC_U:
              if (shifted)
                send_unicode_string("Ü");
              else
                send_unicode_string("ü");
              break;
            case KC_S:
              send_unicode_string("ß");
              break;
            case KC_E:
              send_unicode_string("€");
              break;
            case KC_N:
              if (shifted)
                send_unicode_string("Ñ");
              else
                send_unicode_string("ñ");
              break;
            case KC_1:
              send_unicode_string("¡");
              break;
            case KC_SLASH:
              send_unicode_string("¿");
              break;
            default:
              // ualt_registeredkc = keycode;
              // register_code16(RALT(ualt_registeredkc));
              // TODO better fallbacks, and just make another dedicated physical compose key
              break;
            }
          return false;
        } else { // released any other key
          // if(ualt_registeredkc != KC_NO)
          // 	unregister_code16(RALT(ualt_registeredkc));
          // ualt_registeredkc = KC_NO;
          // TODO ALLOW SHIFT
          return false;
        }
      } else {
        // not in umlaut mode, ie any normal keypress
        return true; // do default key processing.
      }
      // break;
  }
  return true;
}