int brightness;
void setup() {
  // put your setup code here, to run once:
pinMode(9, OUTPUT);
pinMode(A5, INPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
int potvalue = analogRead(A5);
Serial.println("Potentionmeter value");
Serial.println(potvalue);
int brightness = map(potvalue, 0, 1023, 0, 255);
analogWrite(9, brightness);
Serial.println("Brightness value");
Serial.println(brightness);
delay(2);
}
