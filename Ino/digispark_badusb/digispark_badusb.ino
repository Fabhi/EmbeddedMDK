#include "DigiKeyboard.h"
void setup() {
  // put your setup code here, to run once:
  // NO SETUP REQUIRED
}

void loop() {
  // put your main code here, to run repeatedly:
//  DigiKeyboard.sendKeyStroke(0);

  DigiKeyboard.delay(0);
  DigiKeyboard.sendKeyStroke(0, MOD_GUI_LEFT);
  DigiKeyboard.delay(1000);
  DigiKeyboard.print("cmd");
  DigiKeyboard.delay(1000);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
}
