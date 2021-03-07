int green = 3, blue = 5, red = 6;
int brightness1, brightness2, brightness3;
int oras = 1;
void setup() {
  // put your setup code here, to run once:
pinMode(green, OUTPUT);
pinMode(blue, OUTPUT);
pinMode(red, OUTPUT);
brightness1 = 10;
brightness2 = 255;
brightness3 = 10;
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
//brightness1 = 255;
//brightness2 = 10;
//brightness3 = 10;
for (brightness1, brightness2, brightness3; brightness1 <= 255, brightness2 >= 10, brightness3 <= 255; brightness1++, brightness2--, brightness3++)
  {
    analogWrite(green, brightness1);
    analogWrite(blue, brightness2);
    analogWrite(red, brightness3);
    Serial.println(brightness1);
    Serial.println(brightness2);
    Serial.println(brightness3);
    delay(oras);
  }

for (brightness1, brightness2, brightness3; brightness1 >= 10, brightness2 <= 255, brightness3 >= 10; brightness1--, brightness2++, brightness3--)
  {
    analogWrite(green, brightness1);
    analogWrite(blue, brightness2);
    analogWrite(red, brightness3);
    Serial.println(brightness1);
    Serial.println(brightness2);
    Serial.println(brightness3);
    delay(oras);
  }

}//void loop end brace
