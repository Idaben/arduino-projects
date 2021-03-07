int x = 5;
int led[3] = {5,6,7};

void setup() {
  // put your setup code here, to run once:
pinMode(5, OUTPUT);
pinMode(6, OUTPUT);
pinMode(7, OUTPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
int resistance = analogRead(A5);
Serial.println(resistance);

if (resistance == 0 && resistance <= 341)
  {
    digitalWrite(5, HIGH);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
  }
else if (resistance < 341 && resistance <= 512)
  {
    digitalWrite(5, LOW);
    digitalWrite(6, HIGH);
    digitalWrite(7, LOW);
  }
else if (resistance < 512 && resistance <= 1023)
  {
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, HIGH);
  }
}
