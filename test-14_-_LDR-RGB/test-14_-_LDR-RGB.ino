int red_led = 11, green_led = 10, blue_led = 9;
int raw_red, raw_green, raw_blue;
int fin_red, fin_green, fin_blue;
int low_red = 100, low_green = 50, low_blue = 100;
int high_red = 140, high_green = 100, high_blue = 110;


//A0 = red, A1 = green , A2 = blue 

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(9, OUTPUT);
pinMode(10, OUTPUT);
pinMode(11, OUTPUT);
}

void data_log() {
  Serial.print(analogRead(A0));
  Serial.print("   |   ");
  Serial.print(analogRead(A1));
  Serial.print("   |   ");
  Serial.println(analogRead(A2));
}

void data_read() {
  raw_red = analogRead(A0);
    if (raw_red <= low_red) {
      raw_red = low_red;
    }
    if (raw_red >= high_red) {
    raw_red = high_red;
  }
  
  raw_green = analogRead(A1);
    if (raw_green <= low_green) {
    raw_green = low_green;
    }
    if (raw_green >= high_green) {
    raw_green = high_green;
  }
  
  raw_blue = analogRead(A2);
    if (raw_blue <= low_blue) {
    raw_blue = low_blue;
    }
    if (raw_blue >= high_blue) {
    raw_blue = high_blue;
  }
  
  delay(10);
}

void loop() {
  // put your main code here, to run repeatedly:
data_log();
data_read();

fin_red = map(raw_red, low_red, high_red, 255, 0);
fin_green = map(raw_green, low_green, high_green, 255, 00);
fin_blue = map(raw_blue, low_blue, high_blue, 255, 0);

analogWrite(red_led, fin_red);
analogWrite(green_led, fin_green);
analogWrite(blue_led, fin_blue);
}
