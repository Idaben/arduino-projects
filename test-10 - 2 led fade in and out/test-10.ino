int led1 = 9, led2 = 11;
int brightness1, brightness2;
void setup() {
  // put your setup code here, to run once:
pinMode(9, OUTPUT);
pinMode(11, OUTPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
for (brightness1 = 255, brightness2 = 0; brightness1 >= 0, brightness2 <= 255; brightness1--, brightness2++)  {
    analogWrite(led1, brightness1);
    analogWrite(led2,brightness2);
    Serial.println(brightness1);
    Serial.println(brightness2);
    delay(200/50);
}

for (brightness1 = 0, brightness2 = 255; brightness1 <= 255, brightness2 >= 0; brightness1++, brightness2--)  {
    analogWrite(led1, brightness1);
    analogWrite(led2,brightness2);
    Serial.println(brightness1);
    Serial.println(brightness2);
    delay(200/50);
}
brightness1 = 255;
brightness2 = 0;
}
