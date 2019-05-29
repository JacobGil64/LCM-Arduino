/*****************************************************************************************
SEE COMMENTS NEAR BOTTOM OF DOCUMENT TO CHANGE TIMING OF THE RGB LED BLINKS 
******************************************************************************************/

class rgbLedFlasher
{
  // Pin Numbers
  int ledPinRed;     
  int ledPinGreen;
  int ledPinBlue;

  // On / Off Times (Milliseconds)
  long onTimeRed;
  long offTimeRed;
  long onTimeGreen;
  long offTimeGreen;
  long onTimeBlue;
  long offTimeBlue;

  // On / Off state of LED
  int ledStateRed;
  int ledStateGreen;
  int ledStateBlue;

  // Time since last activation
  unsigned long previousMillisRed;
  unsigned long previousMillisGreen;
  unsigned long previousMillisBlue;
  
  public:
  
  // Sets input order for calling class
  rgbLedFlasher(int pinRed, long onRed, long offRed, int pinGreen, long onGreen, long offGreen, int pinBlue, long onBlue, long offBlue)
  {  
    // Input values for pins to variables and pins numbers
    ledPinRed = pinRed;
    pinMode(ledPinRed, OUTPUT);     
    ledPinGreen = pinGreen;
    pinMode(ledPinGreen, OUTPUT);
    ledPinBlue = pinBlue;
    pinMode(ledPinBlue, OUTPUT);

    // Input values for on / off times to variables
    onTimeRed = onRed;
    offTimeRed = offRed;
    onTimeGreen = onGreen;
    offTimeGreen = offGreen;
    onTimeBlue = onBlue;
    offTimeBlue = offBlue;

    // Initial led state off
    ledStateRed = LOW;
    ledStateGreen = LOW;
    ledStateBlue = LOW;

    // Previous time = 0 at intitialization 
    previousMillisRed = 0;
    previousMillisGreen = 0;
    previousMillisBlue = 0;
  }
 
  void Update()
  {
    // Length of led on-time
    unsigned long currentMillisRed = millis();
    unsigned long currentMillisGreen = millis();
    unsigned long currentMillisBlue = millis();

    // Using declared on / off times to check if state of red led should change
    if ((ledStateRed == HIGH) && (currentMillisRed - previousMillisRed >= onTimeRed))
    {
      ledStateRed = LOW;
      previousMillisRed = currentMillisRed;  // Remember the time
      digitalWrite(ledPinRed, ledStateRed);  // Update the actual LED
    }
    else if ((ledStateRed == LOW) && (currentMillisRed - previousMillisRed >= offTimeRed))
    {
      ledStateRed = HIGH;
      previousMillisRed = currentMillisRed;   // Remember the time
      digitalWrite(ledPinRed, ledStateRed);   // Update the actual LED
    }

    // Using declared on / off times to check if state of green led should change
    if ((ledStateGreen == HIGH) && (currentMillisGreen - previousMillisGreen >= onTimeGreen))
    {
      ledStateGreen = LOW;
      previousMillisGreen = currentMillisGreen;  // Remember the time
      digitalWrite(ledPinGreen, ledStateGreen);  // Update the actual LED
    }
    else if ((ledStateGreen == LOW) && (currentMillisGreen - previousMillisGreen >= offTimeGreen))
    {
      ledStateGreen = HIGH;
      previousMillisGreen = currentMillisGreen;   // Remember the time
      digitalWrite(ledPinGreen, ledStateGreen);   // Update the actual LED
    }

    // Using declared on / off times to check if state of blue led should change
    if ((ledStateBlue == HIGH) && (currentMillisBlue - previousMillisBlue >= onTimeBlue))
    {
      ledStateBlue = LOW; 
      previousMillisBlue = currentMillisBlue;  // Remember the time
      digitalWrite(ledPinBlue, ledStateBlue);  // Update the actual LED
    }
    else if ((ledStateBlue == LOW) && (currentMillisBlue - previousMillisBlue >= offTimeBlue))
    {
      ledStateBlue = HIGH;
      previousMillisBlue = currentMillisBlue;   // Remember the time
      digitalWrite(ledPinBlue, ledStateBlue);   // Update the actual LED
    }
  }
};





/* EDIT THIS TO CHANGE TIMING OF BLINKS*/

rgbLedFlasher rgb(11, 100, 100, 12, 100, 100, 13, 100, 100);
/*parameter number 1   2    3    4   5    6    7   8    9
 * 
 *  dont change parameters 1, 4, or 7 (they are the pin numbers)
 *  change the other parameters to adjust timing of blinks
 *  parameters 2, 5, 8 are TIME ON for the LED(in milliseconds)
 *  parameters 3, 6, 9 are TIME OFF for the LED (in milliseconds)
 *  
 *  going lower than 50 milliseconds is not reccomended
 *  
 *  have fun adjusting the colors to make different colors, sequences
 */






void setup() 
{ 
} 
 
void loop() 
{ 
  rgb.Update();
} 
