int led;
int oras = 10;
int brightness = 0;
void setup() {
  // put your setup code here, to run once:
  for (led = 13; led >= 5; led--) {
    pinMode(led, OUTPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
//fade blue 9 to green 10 to red 11
for (int brightness1 = 255, brightness2 = 0; brightness1 >= 0, brightness2 <= 255; brightness1--, brightness2++)  {
  analogWrite(10, brightness1);//green
  analogWrite(9, brightness2);//blue
  delay(oras);
}

for (int brightness2 = 255, brightness1 = 0; brightness2 >= 0, brightness1 <= 255; brightness2--, brightness1++)  {
  analogWrite(11, brightness1);//red
  analogWrite(9, brightness2);//blue
  delay(oras);
}

for (int brightness1 = 255, brightness2 = 0; brightness1 >= 0, brightness2 <= 255; brightness1--, brightness2++)  {
  analogWrite(11, brightness1);//red
  analogWrite(10, brightness2);//green
  delay(oras);
}


}//end brace ng void loop
