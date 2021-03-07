//#include <Arduino_HTS221.h>



float temp;
int br2;
int br1;
int st = 0;
int Received;

void setup() {
  Serial.begin(9600);
  //while (!Serial);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);


  /*if (!HTS.begin()) {
    Serial.println("starting HTS failed!");
    while (1);
  }*/
  
 
}


void loop() {
      //float temperature = HTS.readTemperature();
      //float humidity    = HTS.readHumidity();
      temp = analogRead(A0);
      temp = ( temp / 1024.0) * 5000;
      temp = temp / 10;
      temp = temp - 13;
      if (temp <= 50) {
        br1 = map(temp, 0, 50, 0, 255);
        br2 = map(temp, 50, 0, 0, 255);
        analogWrite(10, br1);
        analogWrite(9, br2);
      }
      if (temp > 50) {
        br1 = map(temp, 50, 110, 0, 255);
        br2 = map(temp, 110, 50, 0, 255);
        analogWrite(11, br1);
        analogWrite(10, br2);
      }
      Serial.print((int)temp);
      Serial.print(" C");
      Serial.print(" | ");
      /*Serial.print((int)temperature);
      //Serial.print(" C");
      //Serial.print(" | ");
      //Serial.print((int)humidity);
      //Serial.print(" % ");
      Serial.print(" | ");*/
    }
