//LED Labels, led1 = red, led2 = orange, led3 = green
int L_led[3] = {0, 1, 2};
int D_led[3] = {3, 4, 5};
int U_led[3] = {6, 7, 8};
int R_led[3] = {9, 10, 11};
int led_direction[4] = {L_led, D_led, U_led, R_led};
int red_time = 1000, green_time = 2000, orange_time = 500, everytime = 2000;
int cycle = 1;

void setup() {
  // put your setup code here, to run once:
for (int i; i <= 11; i++)
  {
    pinMode(i, OUTPUT);
  }
}

void loop() {
// put your main code here, to run repeatedly:
digitalWrite(L_led[0], HIGH);
digitalWrite(R_led[0], HIGH);
digitalWrite(U_led[0], HIGH);
digitalWrite(D_led[0], HIGH);

for (cycle = 1; cycle <= 4; cycle++)
  {
    if (cycle == 1)
      {
        digitalWrite(L_led[2], HIGH);
        digitalWrite(L_led[0], LOW);
        delay(green_time);
      }
    if (cycle == 2)
      {
        digitalWrite(U_led[2], HIGH);
        digitalWrite(U_led[0], LOW);
        delay(green_time);
      }
    if (cycle == 3)
      {
        digitalWrite(R_led[2], HIGH);
        digitalWrite(R_led[0], LOW);
        delay(green_time);
      }
    if (cycle == 4)
      {
        digitalWrite(D_led[2], HIGH);
        digitalWrite(D_led[0], LOW);
        delay(green_time);
      }      
  }
  cycle = 1;
}//void loop end brace
