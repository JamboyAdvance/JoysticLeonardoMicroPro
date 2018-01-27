#include <Joystick.h>

int VRX = A2;    
int VRY = A3;

int VRX_VAL = 0;
int VRY_VAL = 0;

int pinButtonA = 9;
int buttonA = 0;

int pinButtonB = 8;
int buttonB = 1;

int pinButtonC = 7;
int buttonC = 2;

int pinButtonD = 6;
int buttonD = 3;

int pinButtonStart = 5;
int buttonStart = 5;

int pinButtonSelect = 4;
int buttonSelect = 6;

int pinButtonR3 = 3;
int buttonR3 = 4;


Joystick_ Joystick(JOYSTICK_DEFAULT_BUTTON_COUNT,JOYSTICK_TYPE_GAMEPAD,
  7, 0,                  // Button Count, Hat Switch Count
  true, true, false,     // X and Y, but no Z Axis
  false, false, false,   // No Rx, Ry, or Rz
  false, false,          // No rudder or throttle
  false, false, false);  // No accelerator, brake, or steering

void setup() {

  pinMode(pinButtonA, INPUT_PULLUP);
  pinMode(pinButtonB, INPUT_PULLUP);
  pinMode(pinButtonC, INPUT_PULLUP);
  pinMode(pinButtonD, INPUT_PULLUP);


  pinMode(pinButtonStart, INPUT_PULLUP);
  pinMode(pinButtonSelect, INPUT_PULLUP);
  pinMode(pinButtonR3, INPUT_PULLUP);
  
  Joystick.begin();
  Joystick.setXAxisRange(1024, 0);
  Joystick.setYAxisRange(0, 1024);
}

void loop() {

  int currentButtonState;
  VRX_VAL = analogRead(VRX);
  VRY_VAL = analogRead(VRY);
  Joystick.setYAxis(VRY_VAL);
  Joystick.setXAxis(VRX_VAL);

  currentButtonState = !digitalRead(pinButtonA);
  Joystick.setButton(buttonA, currentButtonState);
  
  currentButtonState = !digitalRead(pinButtonB);  
  Joystick.setButton(buttonB, currentButtonState);

  currentButtonState = !digitalRead(pinButtonC);  
  Joystick.setButton(buttonC, currentButtonState);

  currentButtonState = !digitalRead(pinButtonD);  
  Joystick.setButton(buttonD, currentButtonState);

  currentButtonState = !digitalRead(pinButtonR3);  
  Joystick.setButton(buttonR3, currentButtonState);

  currentButtonState = !digitalRead(pinButtonSelect);  
  Joystick.setButton(buttonSelect, currentButtonState);

  currentButtonState = !digitalRead(pinButtonStart);  
  Joystick.setButton(buttonStart, currentButtonState);
      
  delay(10);
}



