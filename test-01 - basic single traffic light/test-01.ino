int GREEN = 8;
int ORANGE = 6;
int RED = 4;
int color = 1;

void setup() {
  // put your setup code here, to run once:
pinMode(GREEN, OUTPUT);
pinMode(ORANGE, OUTPUT);
pinMode(RED, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(GREEN, HIGH);
  digitalWrite(ORANGE, LOW);
  digitalWrite(RED, LOW);
  delay(3000);

  digitalWrite(GREEN, LOW);
  digitalWrite(ORANGE, HIGH);
  digitalWrite(RED, LOW);
  delay(1000);

   digitalWrite(GREEN, LOW);
  digitalWrite(ORANGE, LOW);
  digitalWrite(RED, HIGH);
  delay(2000);

}
