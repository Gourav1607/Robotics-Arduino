/*
  Electronics_Thermometer_n_Hygrometer
  Calculates Humidity and Temperature using dht11 sensor module.

  Reads data from the sensing device and displays it on a lcd.

  modified 11 December 2014
  by Harpreet Singh(A-SET Institutes)
 */

#include <LiquidCrystal.h>
#include <dht.h>

LiquidCrystal disp(2,3,4,5,6,7,8);

#define dhtPin A1 //no ; here. Set equal to channel sensor is on
int tem = 0;
int hue = 0;

byte degree[8] = {0b01110,
                  0b01010,
                  0b01110,
                  0b00000,
                  0b00000,
                  0b00000,
                  0b00000,
                  0b00000};

dht DHT;

void setup(){
    disp.createChar(1, degree);
    disp.begin(16, 2);
    disp.print("Temperature=");
    disp.setCursor(14, 0);
    disp.write(1);
    disp.print('C');
    disp.setCursor(0, 1);
    disp.print("Humidity=");
    disp.setCursor(11, 1);
    disp.print('%');
    delay(1000);//Let system settle
}   //end "setup()"

void loop() {
  //This is the "heart" of the program.
    DHT.val(dhtPin);
    tem = DHT.temperature;
    disp.setCursor(12, 0);
    disp.print(tem);
    hue = DHT.humidity;
    disp.setCursor(9, 1);
    disp.print(hue);
    delay(800);
    //Don't try to access too frequently... in theory
    //should be once per two seconds, fastest,
    //but seems to work after 0.8 second.
}   // end loop()
