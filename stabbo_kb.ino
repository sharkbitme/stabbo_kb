#include <Keyboard.h>

int rflag = 0;
int wkey = 0x83;
int tab = 0xB3;
int lalt = 0x82;
int fchar = 0;
int lchar = 0;

void setup() {
  Serial.begin(115200);
  while (!Serial);
  {
    // initialize keyboard:
    Keyboard.begin();
    Serial.println("Welcome to stabbo_kb\n");
    usage();
  }
}

void usage() {
  Serial.println("Tryin to stabbo some keycombos?\n:");
  Serial.println("w - check winkey + character combos defined in the range, stopping for alt tab to check background stuff");
  Serial.println("r - rapid mode, no stopping for alt + tab");
}

void fchar_range() {
  Serial.println("Enter starting character for range, in ASCII a:");
  int frchoice = -1;
  while (frchoice == -1) {
    frchoice = Serial.read();
    if (frchoice != -1) {
      fchar = int(frchoice); //store the value of frchoice into the fchar var as an int
      Serial.println("Starting character: " + String(char(fchar)));
      echar_range(); //call echar_range function to get the ending character of the range
      break;

    }
  }
}

void echar_range() {
  Serial.println("Enter ending character for range, in ASCII z:");
  int erchoice = -1;
  while (erchoice == -1) {
    erchoice = Serial.read();
    if (erchoice != -1) {
      lchar = int(erchoice);
      Serial.println("Ending character: " + String(char(lchar)));
      winkey_letter();
      break;
    }
  }

}

void alt_tab() {
  Keyboard.press(lalt);
  Keyboard.press(tab);
  delay(100);
  Keyboard.release(tab);
  Serial.println("see anything cool? if not, press c to continue or q to quit");

  int cont = -1;
  while (cont == -1) {
    cont = Serial.read();
    switch (char(cont)) {
      case 'c':
        Keyboard.releaseAll();
        break;
      case 'q':
        Keyboard.releaseAll();
        Serial.println("Quitting, reconnect to serial to restart");
        exit(0);

    }

  }
}

void winkey_letter() {
  Serial.println("checking winkey + defined combos.");
  for (fchar; fchar <= lchar; fchar++) { //loop over values of fchar, stored as an int from the f/echar_range functions
    if (fchar == 108 || fchar == 76) { //logic check to skip over the winkey + L combo, if it equals upper L or lower L, skip
      fchar++; // dont wanna lock the machine :) although it still skips 'm'
      continue;
    }
    delay(1000);
    Serial.println("Trying: Winkey " "+ " + String(char(fchar)));
    Keyboard.press(wkey);
    delay(400);
    Keyboard.press(fchar);
    delay(100);
    Keyboard.releaseAll();
    delay(2000);
    if (rflag == 0) { //check if rflag is 0 or 1, depending on which mode you selected
      alt_tab();
      continue;
    }
    else {
      continue;
    }
    delay(500);

  }
}

void loop() {
  int choice = -1;
  while (choice == -1) {
    choice = Serial.read();
    switch (char(choice)) {
      case 'w':
        fchar_range();
        break;
      case 'r':
        rflag = 1; //set rflag to 1, skips call to alt_tab() function
        fchar_range();
        break;

    }
  }
}
