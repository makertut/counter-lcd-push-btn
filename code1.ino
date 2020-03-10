//YWROBOT

//Compatible with the Arduino IDE 1.0

//Library version:1.1

#include <Wire.h>

#include <LiquidCrystal_I2C.h>



LiquidCrystal_I2C lcd(0x3F,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display





// this constant won't change:

const int  Up_buttonPin   = 2;    // the pin that the pushbutton is attached to

const int  Down_buttonPin = 3;



// Variables will change:

int buttonPushCounter = 0;   // counter for the number of button presses

int up_buttonState = 0;         // current state of the up button

int up_lastButtonState = 0;     // previous state of the up button



int down_buttonState = 0;         // current state of the up button

int down_lastButtonState = 0;     // previous state of the up button

bool bPress = false;



void setup()

{

  Serial.begin(9600);

  pinMode( Up_buttonPin , INPUT_PULLUP);

  pinMode( Down_buttonPin , INPUT_PULLUP);

 

  lcd.init();                      // initialize the lcd

 

  // Print a message to the LCD.

  lcd.backlight();

  lcd.setCursor(0,0);

  lcd.print("Please Select:");

  lcd.setCursor(2,1);

  lcd.print(buttonPushCounter);

 

}





void loop()

{

   checkUp();

   checkDown();



   if( bPress){

       bPress = false;

      lcd.setCursor(2,1);

      lcd.print("               ");

      lcd.setCursor(2,1);

      lcd.print(buttonPushCounter);

   }

 

}



void checkUp()

{

  up_buttonState = digitalRead(Up_buttonPin);



  // compare the buttonState to its previous state

  if (up_buttonState != up_lastButtonState) {

    // if the state has changed, increment the counter

    if (up_buttonState == LOW) {

        bPress = true;

      // if the current state is HIGH then the button went from off to on:

      buttonPushCounter++;

      Serial.println("on");

      Serial.print("number of button pushes: ");

      Serial.println(buttonPushCounter);

    } else {

      // if the current state is LOW then the button went from on to off:

      Serial.println("off");

    }

    // Delay a little bit to avoid bouncing

    delay(50);

  }

  // save the current state as the last state, for next time through the loop

  up_lastButtonState = up_buttonState;

}

void checkDown()

{

  down_buttonState = digitalRead(Down_buttonPin);



  // compare the buttonState to its previous state

  if (down_buttonState != down_lastButtonState) {

    // if the state has changed, increment the counter

    if (down_buttonState == LOW) {

        bPress = true;

      // if the current state is HIGH then the button went from off to on:

      buttonPushCounter--;

     

      Serial.println("on");

      Serial.print("number of button pushes: ");

      Serial.println(buttonPushCounter);

    } else {

      // if the current state is LOW then the button went from on to off:

      Serial.println("off");

    }

    // Delay a little bit to avoid bouncing

    delay(50);

  }

  // save the current state as the last state, for next time through the loop

  down_lastButtonState = down_buttonState;

}

