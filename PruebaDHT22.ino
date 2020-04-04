#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

#include "DHT.h"

#define DHTPIN 8     // Pin donde está conectado el sensor

//#define DHTTYPE DHT11   // Descomentar si se usa el DHT 11
#define DHTTYPE DHT22   // Sensor DHT22

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  //lcd.begin(9600);
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.println("....Iniciando...");
  lcd.setCursor(0, 1);
  lcd.println(".... Sensor ....");
  dht.begin();
  pinMode(13, OUTPUT);
}
void loop() {
  delay(5000);
  float h = dht.readHumidity(); //Leemos la Humedad
  float t = dht.readTemperature(); //Leemos la temperatura en grados Celsius
  //float f = dht.readTemperature(true); //Leemos la temperatura en grados Fahrenheit
  //--------Enviamos las lecturas por el puerto serial-------------
  lcd.setCursor(0, 0);
  lcd.print("Tempera:");
  lcd.print(t);
  lcd.print(" *C ");
  //lcd.print(f);
  //lcd.println(" *F");
     
  lcd.setCursor(0, 1);
  lcd.print("Humedad:");
  lcd.print(h);
  lcd.print(" % ");

if (t >= 33)
   {
   digitalWrite(13, HIGH); // Enciende el Led 13.
   //lcd.write("ON"); // Envía por el puerto ON.

    }
else
   {
      digitalWrite(13, LOW); // Apaga el Led 13.
   //lcd.write("OFF"); // Envía por el puerto OFF.
   }
}
