

//******************************************************************************
//DHT temperature & humidity with I2C LCD
//author: Josip Prpić
//This code is open source, you can use it as you wish in any of your projects :)
//IMPORTANT INFO:
//   - you have to install LCD I2C and DHT 11 library.
//   - I2C address of the LCD [File -> Examples -> Wire -> I2C scanner]
//******************************************************************************

#include <dht.h>
#include <LiquidCrystal_I2C.h>
#include<Wire.h>

LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);
dht DHT;

#define BACKLIGHT_PIN 13

//connect DHT11 sensor to digital pin 7
#define DHT11_PIN 7

//connect led to digital pin 6
int ledpin = 6;

void setup() {
   // switch backlight on
   pinMode(BACKLIGHT_PIN, OUTPUT);
   digitalWrite(BACKLIGHT_PIN, HIGH);

   //switch led indicator on
   digitalWrite(ledpin, HIGH);

   //initialize lcd
   lcd.begin(16,2);
   lcd.home();
   lcd.print("Reading...");
   for(int i = 0; i < 5; i++){
       digitalWrite(ledpin, HIGH);
       delay(200);
       digitalWrite(ledpin, LOW);
   }
}


//function to write results on lcd
void write_lcd(){
  //initialize lcd
  lcd.home();
  //do an infinite loop
  
    //set cursor to 14th position in first line, wirte "*" character and wait 1000 ms
    int chk = DHT.read11(DHT11_PIN);
    lcd.setCursor(0,0); 
    lcd.print("Temp: ");
    lcd.print(DHT.temperature);
    lcd.setCursor(0,1);
    lcd.print("Humidity: ");
    lcd.print(DHT.humidity);
    lcd.print("%");
    //set cursor to 14th position in first line and write nothing to create blinking animation and wait 1000 ms
    
 
}

void loop() {
  
  
  write_lcd();

}
