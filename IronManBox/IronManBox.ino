// Dependencies LiquidCrystal
// https://github.com/fdebrabander/Arduino-LiquidCrystal-I2C-library

//Includes LiquidCrystal
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

//Set the LCD address to 0x3F for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x3F, 16, 2);



// Dependencies DHT-22 Temperature and humidity sensor
// Libraries

//Includes DHT-22
#include <DHT.h>;

//Constants
#define DHTPIN 7     // Digital Pin 7 
#define DHTTYPE DHT22   // DHT 22  (AM2302)
DHT dht(DHTPIN, DHTTYPE); //// Initialize DHT sensor 

//Variables
int chk;
float hum;  //Stores humidity value
float temp; //Stores temperature value



void setup()
{
  //Inicializando Jarvis System
 
  //Inicializando LCD
  lcd.begin();
  lcd.backlight();

  //Inicializando Jarvis
  lcd.print("Starting Jarvis");
  delay(3000);  
  for( int i = 1; i<11 ; i++ ){
    lcd.clear();
    lcd.print(i);
    delay(1000);  
  }
  lcd.clear();
  lcd.print("Hello Madeira");
  delay(3000);
  lcd.clear();
  
  //Starting system dht temperature and humidity
  Serial.begin(9600);
  dht.begin();

  //Print on CrystalLiquid the temperature and humidity 
  lcd.print("Temperature:");
  lcd.print(dht.readTemperature());
  delay(5000);
  lcd.clear();
  lcd.print("Humidity:");
  lcd.print(dht.readHumidity());
  delay(5000);
  lcd.clear();
  lcd.noBacklight();
}

void loop()
{
  
  //Turn on mask and reactor ARC for 60 seconds and turn off for 30 minutes
  analogWrite(9,255);  // Mask on
  analogWrite(11,255); // Reactor ARC on
  delay(60000); // 60 seconds
  analogWrite(9,0);  // Mask off
  analogWrite(11,0); // Reactor ARC off
  delay(180000); // 30 minutes

  //Print again on CrystalLiquid the temperature and umidity 
  lcd.backlight();
  lcd.print("Temperature:");
  lcd.print(dht.readTemperature());
  delay(5000);
  lcd.clear();
  lcd.print("Humidity:");
  lcd.print(dht.readHumidity());
  delay(5000);
  lcd.clear();
  lcd.noBacklight();

  
}
