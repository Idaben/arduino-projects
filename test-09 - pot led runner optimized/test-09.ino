int led;
void setup() {
  // put your setup code here, to run once:
for (led = 13; led >= 5; led--){
pinMode(led, OUTPUT); }
Serial.begin(9600);
}

int pot_position() {
int potvalue = analogRead(A5);
int valueings = map(potvalue, 0, 1020, 13, 5);
return valueings;
}

void loop() {
// put your main code here, to run repeatedly:
Serial.println(pot_position());
Serial.println(analogRead(A5));
digitalWrite(pot_position(), HIGH);
digitalWrite(pot_position()+1, LOW);
digitalWrite(pot_position()-1, LOW);
}
