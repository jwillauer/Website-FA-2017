//load libraries
#include <Wire.h>
#include <LCD.h>
#include <LiquidCrystal_I2C.h>

//Define variables for the LCD

#define I2C_ADDR          0x03F        //Define I2C Address where the PCF8574A is
#define BACKLIGHT_PIN      3
#define En_pin             2
#define Rw_pin             1
#define Rs_pin             0
#define D4_pin             4
#define D5_pin             5
#define D6_pin             6
#define D7_pin             7

//define variables for the LM34 temperature sensor

float temp;        //Define the temp float variable
float tempf;       //Define the Fahrenheit float variable
int sensor = 0;     // sensor middle pin on analog pin 0

//Initialise the LCD
LiquidCrystal_I2C      lcd(I2C_ADDR, En_pin,Rw_pin,Rs_pin,D4_pin,D5_pin,D6_pin,D7_pin);

void setup()
 {
    //Define the LCD as 16 column by 2 rows 
    lcd.begin (16,2);
    
    //Switch on the backlight
    lcd.setBacklightPin(BACKLIGHT_PIN,POSITIVE);
    lcd.setBacklight(HIGH);
    
    //goto first column (column 0) and first line (Line 0)
    lcd.setCursor(0,0);
    
    //Print at cursor Location
    lcd.print("Temp F = ");
    
    //goto first column (column 0) and second line (line 1)
    lcd.setCursor(2,1);
    
    //Print at cursor Location
    lcd.print("Hot Box Temp");
    
 }
 
 
void loop()
{
  
  temp = analogRead(sensor);        //assigning the analog output to temp
  temp = (temp * 0.5556-17);         //converting volts to degrees celsius ----- 0.48828125 = [(5V*1000)/1024]10

  
  lcd.setCursor(8,0);               //move the cursor to position 8 on row 1
  lcd.print(temp);                  //print the temperature in Celsius
  
  
  //wait 5 seconds
  delay(1000);
}
