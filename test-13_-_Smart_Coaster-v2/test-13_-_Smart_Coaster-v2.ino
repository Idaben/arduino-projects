int red = 11, green = 10, blue = 9;
int temp;
int low= 110, high = 135;
int ave_tempy, per_temp;
int brr, brg,brb;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(red, OUTPUT);
pinMode(green, OUTPUT);
pinMode(blue, OUTPUT);
}

int rTemp() {
  temp = analogRead(A0);
  delay(3000);
//LOW THRESHOLD GATE
if (temp < low) {
      temp = low;
}
//HIGH THRESHOLD GATE
if (temp > high) {
     temp = high;
  }
  return temp;
}

//Average Temperature
int ave_temp(){
  ave_tempy = ( (high - (((high - low)*2)/6))  );
  return ave_tempy;
}

//Led Checks
void led_check() {
  if (per_temp < ave_temp()) {
  brr = 0;
}
  if (per_temp > ave_temp()) {
  brb = 0;
}
}

void loop() {
  // put your main code here, to run repeatedly:
per_temp = rTemp();
Serial.print(per_temp);
Serial.print("   |   ");
Serial.print(brr);
Serial.print("   |   ");
Serial.print(brg);
Serial.print("   |   ");
Serial.println(brb);
//LOW TO MID TEMPERATURE
if (per_temp >= low && per_temp <= ave_temp()) {
  brb = map(per_temp, low, ave_temp(), 255, 0);
  brg = map(per_temp, low, ave_temp(), 0, 255);
  led_check();
  analogWrite(blue, brb);
  analogWrite(green, brg);
  
  }
//MID TO HIGH TEMPERATURE
else if (per_temp > ave_temp() && per_temp <= high) {
  brg = map(per_temp, ave_temp(), high, 255, 0);
  brr = map(per_temp, ave_temp(), high, 0, 255);
  led_check();
  analogWrite(green, brg);
  analogWrite(red, brr);
  }
}
