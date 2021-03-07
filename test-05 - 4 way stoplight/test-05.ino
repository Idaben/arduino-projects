//LED Labels, led1 = red, led2 = orange, led3 = green
int L_led[3] = {0, 1, 2};
int D_led[3] = {3, 4, 5};
int U_led[3] = {6, 7, 8};
int R_led[3] = {9, 10, 11};
int led_direction[4] = {L_led, D_led, U_led, R_led};
int red_time = 1000, green_time = 2000, orange_time = 500;
int cycle = 1;

void setup() {
  // put your setup code here, to run once:
pinMode(0, OUTPUT);
pinMode(1, OUTPUT);
pinMode(2, OUTPUT);
pinMode(3, OUTPUT);
pinMode(4, OUTPUT);
pinMode(5, OUTPUT);
pinMode(6, OUTPUT);
pinMode(7, OUTPUT);
pinMode(8, OUTPUT);
pinMode(9, OUTPUT);
pinMode(10, OUTPUT);
pinMode(11, OUTPUT);
}

void loop() {
// put your main code here, to run repeatedly:
while (cycle <= 4)
{
      
    if (cycle == 1)
      {
        digitalWrite(L_led[2], HIGH); 
        digitalWrite(D_led[0], HIGH); 
        digitalWrite(U_led[0], HIGH); 
        digitalWrite(R_led[0], HIGH);
        delay(green_time);
        cycle++;
      }

    else if (cycle == 2)
      {
        digitalWrite(L_led[0], HIGH); 
        digitalWrite(D_led[0], HIGH); 
        digitalWrite(U_led[2], HIGH); 
        digitalWrite(R_led[0], HIGH); 
        delay(green_time);
        cycle++;
      }
    
    
    else if (cycle == 3)
      {
        digitalWrite(L_led[0], HIGH); 
        digitalWrite(D_led[0], HIGH); 
        digitalWrite(U_led[0], HIGH); 
        digitalWrite(R_led[2], HIGH); 
        delay(green_time);
        cycle++;
      }
    
    
    else if (cycle == 4)
      {
        digitalWrite(L_led[0], HIGH); 
        digitalWrite(D_led[2], HIGH); 
        digitalWrite(U_led[0], HIGH); 
        digitalWrite(R_led[0], HIGH); 
        delay(green_time);
        cycle++;
      }

}//while loop end brace

cycle = 1;
}//void loop end brace
