

//******************************************************************************
//DHT temperature & humidity with I2C LCD
//author: Microchips team
//This code is open source, you can use it as you wish in any of your projects :)
//IMPORTANT INFO:
//   - you have to install LCD I2C and DHT 11 library.
//   - I2C address of the LCD [File -> Examples -> Wire -> I2C scanner]
//******************************************************************************

#include <dht11.h>
#include <LiquidCrystal_I2C.h>
#include<Wire.h>

LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);
 
dht11 DHT11;
#define DHT11PIN 2

int ledpin = 6;

void setup()
{ 
     lcd.begin(16, 2);     
     lcd.clear();         
     digitalWrite(ledpin, HIGH);
     delay(1000); 
}
 
void loop()
{
    int chk = DHT11.read(DHT11PIN);

    //print humidity
    lcd.setCursor(0, 0); 
    lcd.print("Humidity:");
    lcd.print((float)DHT11.humidity, 2);// Print humidity value
    lcd.print(" % ");

    //print temperature
    lcd.setCursor(0, 1); 
    lcd.print("Temp:    ");
    lcd.print((float)DHT11.temperature, 2);
    lcd.print(" C "); 
    delay(1000);     
}
