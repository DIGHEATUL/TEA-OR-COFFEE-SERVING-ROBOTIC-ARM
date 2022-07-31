#include <Servo.h>
#include <OLED_I2C.h>

//define the servos
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;

OLED  myOLED(SDA, SCL);
extern uint8_t SmallFont[];

//define the buttons
const int button1 = 10;
const int button2 = 11;

//define variable for values of the button
int button1Pressed = 0;
boolean button2Pressed = false;

//define potentiometers
const int pot1 = A0;
const int pot2 = A1;
const int pot3 = A2;
const int pot4 = A3;

//define variable for values of the potentiometers
int pot1Val;
int pot2Val;
int pot3Val;
int pot4Val;

//define variable for angles of the potentiometer
int pot1Angle;
int pot2Angle;
int pot3Angle;
int pot4Angle;

int s = 50;

int a1ngle = 0;
int a2ngle = 0;
int a3ngle = 0;
int a4ngle = 0;

int angle1 = 0;
int angle2 = 0;
int angle3 = 0;
int angle4 = 0;

int Saveangle1 = 0;
int Saveangle2 = 0;
int Saveangle3 = 0;
int Saveangle4 = 0;

//define variable for saved position of the servos
int servo1PosSave[] = {1, 1, 1, 1, 1, 1, 1, 1};
int servo2PosSave[] = {1, 1, 1, 1, 1, 1, 1, 1};
int servo3PosSave[] = {1, 1, 1, 1, 1, 1, 1, 1};
int servo4PosSave[] = {1, 1, 1, 1, 1, 1, 1, 1};

void setup() {

  myOLED.begin();
  myOLED.setFont(SmallFont);
  Serial.begin(9600);

  //define attached pins of the servos
  servo1.attach(5);
  servo2.attach(6);
  servo3.attach(7);
  servo4.attach(8);

  //define buttons as input units
  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);


  for (angle1 = 0; angle1 <= 90; angle1 += 1) {
    servo1.write(angle1);
    delay(15);
  }
  delay(700);

  for (angle2 = 0; angle2 <= 50; angle2 += 1) {
    servo2.write(angle2);
    delay(15);
  }
  delay(700);

  for (angle3 = 0; angle3 <= 40; angle3 += 1) {
    servo3.write(angle3);
    delay(15);
  }
  delay(700);

  for (angle4 = 0; angle4 <= 140; angle4 += 1) {
    servo4.write(angle4);
    delay(15);
  }
  delay(700);

  myOLED.clrScr();
  myOLED.print("PRESS TO SAVE BUTTON", CENTER, 42);
  myOLED.update();

}

void slow1 (int i) //function name
{

  if (i < 10) {
    i = 10; // 50 is the lower limit for the servo
  }
  if (i > 179) {
    i = 179; // 120 is the upper limit for the servo
  }
  a1ngle = servo1.read(); //reads the actual angle
  //Decides what direction to take
  if ( i >= a1ngle) {
    for (a1ngle = a1ngle; a1ngle <= i; a1ngle = a1ngle + 1)
    { servo1.write(a1ngle);
      delay(s);
    }
  }
  else
  { for (a1ngle = a1ngle; a1ngle >= i; a1ngle = a1ngle - 1)
    { servo1.write(a1ngle);
      delay(s);
    }
  }

}

void slow2 (int j) //function name
{

  if (j < 10) {
    j = 10; // 50 is the lower limit for the servo
  }
  if (j > 150) {
    j = 150; // 120 is the upper limit for the servo
  }
  a2ngle = servo2.read(); //reads the actual angle
  //Decides what direction to take
  if ( j >= a2ngle) {
    for (a2ngle = a2ngle; a2ngle <= j; a2ngle = a2ngle + 1)
    { servo2.write(a2ngle);
      delay(s);
    }
  }
  else
  { for (a2ngle = a2ngle; a2ngle >= j; a2ngle = a2ngle - 1)
    { servo2.write(a2ngle);
      delay(s);
    }
  }

}

void slow3 (int k) //function name
{

  if (k < 10) {
    k = 10; // 50 is the lower limit for the servo
  }
  if (k > 170) {
    k = 170; // 120 is the upper limit for the servo
  }
  a3ngle = servo3.read(); //reads the actual angle
  //Decides what direction to take
  if ( k >= a3ngle) {
    for (a3ngle = a3ngle; a3ngle <= k; a3ngle = a3ngle + 1)
    { servo3.write(a3ngle);
      delay(s);
    }
  }
  else
  { for (a3ngle = a3ngle; a3ngle >= k; a3ngle = a3ngle - 1)
    { servo3.write(a3ngle);
      delay(s);
    }
  }

}


void slow4 (int z) //function name
{

  if (z < 1) {
    z = 1; // 50 is the lower limit for the servo
  }
  if (z > 140) {
    z = 140; // 120 is the upper limit for the servo
  }
  a4ngle = servo4.read(); //reads the actual angle
  //Decides what direction to take
  if ( z >= a4ngle) {
    for (a4ngle = a4ngle; a4ngle <= z; a4ngle = a4ngle + 1)
    { servo4.write(a4ngle);
      delay(s);
    }
  }
  else
  { for (a4ngle = a4ngle; a4ngle >= z; a4ngle = a4ngle - 1)
    { servo4.write(a4ngle);
      delay(s);
    }
  }

}




void loop() {
  //read the potentiometer values and define the servo angle to
  //the potentiometer value with the map function
  pot1Val = analogRead(pot1);
  pot1Angle = map (pot1Val, 0, 1023, 10, 179);
  pot2Val = analogRead(pot2);
  pot2Angle = map (pot2Val, 0, 1023, 10, 150);
  pot3Val = analogRead(pot3);
  pot3Angle = map (pot3Val, 0, 1023, 10, 170);
  pot4Val = analogRead(pot4);
  pot4Angle = map (pot4Val, 0, 1023, 1, 140);

  //servos move to mapped angles

  slow1(pot1Angle);


  slow2(pot2Angle);


  slow3(pot3Angle);


  slow4(pot4Angle);



  //if button1 is pressed (HIGH), save the potentiometers position
  //as long as button1 is pressed
  if (digitalRead(button1) == LOW) {
  
    button1Pressed++;
    switch (button1Pressed) {
      case 1:
        servo1PosSave[0] = pot1Angle;
        servo2PosSave[0] = pot2Angle;
        servo3PosSave[0] = pot3Angle;
        servo4PosSave[0] = pot4Angle;
        Serial.println("Position #1 Saved");
        myOLED.clrScr();

        myOLED.print("POSITION #1 SAVED", CENTER, 42);
        myOLED.update();
        delay(1500);
        break;
      case 2:
        servo1PosSave[1] = pot1Angle;
        servo2PosSave[1] = pot2Angle;
        servo3PosSave[1] = pot3Angle;
        servo4PosSave[1] = pot4Angle;
        Serial.println("Position #2 Saved");
        myOLED.clrScr();

        myOLED.print("POSITION #2 SAVED", CENTER, 42);
        myOLED.update();
        delay(1500);
        break;
      case 3:
        servo1PosSave[2] = pot1Angle;
        servo2PosSave[2] = pot2Angle;
        servo3PosSave[2] = pot3Angle;
        servo4PosSave[2] = pot4Angle;
        Serial.println("Position #3 Saved");
        myOLED.clrScr();

        myOLED.print("POSITION #3 SAVED", CENTER, 42);
        myOLED.update();
        delay(1500);
        break;
      case 4:
        servo1PosSave[3] = pot1Angle;
        servo2PosSave[3] = pot2Angle;
        servo3PosSave[3] = pot3Angle;
        servo4PosSave[3] = pot4Angle;
        Serial.println("Position #4 Saved");
        myOLED.clrScr();

        myOLED.print("POSITION #4 SAVED", CENTER, 42);
        myOLED.update();
        delay(1500);
        break;
      case 5:
        servo1PosSave[4] = pot1Angle;
        servo2PosSave[4] = pot2Angle;
        servo3PosSave[4] = pot3Angle;
        servo4PosSave[4] = pot4Angle;
        Serial.println("Position #5 Saved");
        myOLED.clrScr();

        myOLED.print("POSITION #5 SAVED", CENTER, 42);
        myOLED.update();
        delay(1500);
        break;
      case 6:
        servo1PosSave[5] = pot1Angle;
        servo2PosSave[5] = pot2Angle;
        servo3PosSave[5] = pot3Angle;
        servo4PosSave[5] = pot4Angle;
        Serial.println("Position #6 Saved");
        myOLED.clrScr();

        myOLED.print("POSITION #6 SAVED", CENTER, 42);
        myOLED.update();
        delay(1500);
        break;
      case 7:
        servo1PosSave[6] = pot1Angle;
        servo2PosSave[6] = pot2Angle;
        servo3PosSave[6] = pot3Angle;
        servo4PosSave[6] = pot4Angle;
        Serial.println("Position #7 Saved");
        myOLED.clrScr();

        myOLED.print("POSITION #7 SAVED", CENTER, 42);
        myOLED.update();
        delay(1500);
        break;
      case 8:
        servo1PosSave[7] = pot1Angle;
        servo2PosSave[7] = pot2Angle;
        servo3PosSave[7] = pot3Angle;
        servo4PosSave[7] = pot4Angle;
        Serial.println("Position #8 Saved");
        myOLED.clrScr();

        myOLED.print("POSITION #8 SAVED", CENTER, 28);
        myOLED.print("PRESS TO MOVE BUTTON", CENTER, 42);
        myOLED.update();
        delay(1500);
        break;

    }
  }
  
  //if button2 pressed (HIGH), the servos move saved position
  if (digitalRead(button2) == LOW) {
    button2Pressed = true;
  }

  if (button2Pressed) {

    Serial.println("MOVING");
    myOLED.clrScr();

    myOLED.print("MOVING...", CENTER, 42);
    myOLED.update();
    delay(2000);

    for (int i = 0; i < 8; i++) {

      slow1(servo1PosSave[i]);
      delay(15);



      slow2(servo2PosSave[i]);
      delay(15);

      slow3(servo3PosSave[i]);
      delay(15);

      slow4(servo4PosSave[i]);
      delay(15);


    }
    delay(100);
  }
}
