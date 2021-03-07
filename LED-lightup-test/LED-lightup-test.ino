int led;
void setup() {
  // put your setup code here, to run once:
  for (led = 13; led >= 5; led--){
pinMode(led, OUTPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  for (led = 13; led >= 5; led--){
digitalWrite(led, HIGH);
delay(100);

  }
}
