//MOTOR PINS
int enA = 9;
int in1 = 7;
int in2 = 6;

//SWITCH PINS
int switchpin = 13;
int switchpin2 = 3;

//LED SETUP PINS
int ledpin = 12;
int state = 0;
int state2 = 0;

//TEMPERATURE SETUP PINS
int maxtemp = 978; //38 degrees
int mintemp = 974; //35 degrees
int temppin = A1;
int currenttemp = 0;

//Door state
int open = 0;

//Ultrasonic PINS
int echopin = 4;
int trigpin = 5;
int potlimit = 351; //potmin = 0, potmax = 439; 

//LED PINS
int led_buzzer = 12;
int green_led = 13;

void setup() { // put your setup code here, to run once: //MGA DECLARE LANG NG MGA PIN OUTPUT AND INPUT
Serial.begin(9600);
pinMode(switchpin,INPUT);
pinMode(switchpin2,INPUT);
pinMode(ledpin, OUTPUT);
 
pinMode(enA, OUTPUT);
pinMode(in1, OUTPUT);
pinMode(in2, OUTPUT);

pinMode(trigpin, OUTPUT);
pinMode(echopin, INPUT); 

pinMode(led_buzzer, OUTPUT);
pinMode(green_led, OUTPUT);
}


//MGA SARILING FUNCTION NA GAWA GAWA NAMIN
void spinclockwise(){ //IKOT MOTOR CLOCKWISE
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
}

void spincounterclockwise(){ //IKOT MOTOR COUNTERCLOCKWISE
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
}

void nospin(){ //FUNCTION NA NAGPAPATIGIL NG IKOT NG MGA MOTOR
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
}

void measuredata(){ //FUNCTION NA MGA NAGRE-READ NG MGA DATA
    state = digitalRead(switchpin);
    state2 = digitalRead(switchpin2);
    currenttemp = analogRead(temppin);
}


long microsecondsToInches(long microseconds) // CONVERT MICROSECONDS TO INCHES 
{
 return microseconds / 74 / 2;
}


void loop() {//START BRACKET // put your main code here, to run repeatedly:
measuredata();

analogWrite(enA,200); //MOTOR SPEED SOMETHING
delay(50);

///PRINT DISTANCE
long duration, inches;
digitalWrite(trigpin, LOW);
delayMicroseconds(2);

digitalWrite(trigpin, HIGH);
delayMicroseconds(10);

digitalWrite(trigpin, LOW);

duration = pulseIn(echopin, HIGH);
inches = microsecondsToInches(duration); 
Serial.println(inches);

//DOOR MECHANICS
if (inches >= potlimit) {
  if (currenttemp >= mintemp && currenttemp <= maxtemp){ //PAG PASOK TEMP ITO GAGAWIN
      digitalWrite(green_led, HIGH);
      delay(500);
      digitalWrite(green_led, LOW);
      Serial.println("Opening");
      spinclockwise();
      delay(1000);
      Serial.println("Door is Open");
      nospin();
      delay(2500); //Gaano katagal nakabukas yung pinto   
      Serial.println("Closing");
      spincounterclockwise();
      delay(1000);
      nospin();
      delay(50);
      state = 0;
  }
  else { //PAG DI PASOK YUNG TEMP ITO YUNG MANGYAYARI
      digitalWrite(led_buzzer, HIGH);
      delay(1000);
      digitalWrite(led_buzzer, LOW);
      nospin();
      delay(50);
      digitalWrite(trigpin, LOW);
      delayMicroseconds(2);
      
      digitalWrite(trigpin, HIGH);
      delayMicroseconds(10);
      
      digitalWrite(trigpin, LOW);
      
      duration = pulseIn(echopin, HIGH);
      inches = microsecondsToInches(duration); 
      Serial.println(inches);
      delay(1500);
  }
}


}//END BRACKET