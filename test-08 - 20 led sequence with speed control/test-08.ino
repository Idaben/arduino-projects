int led[4] = {11, 10, 6};
int left = led[0], mid = led[1], right = led[2];
int brightness, sequence = 1, repeater;
int fastest = 50, repeat = 4, fade_speed = 50, potvalue;
int speedies;
//Analog pin Potentiometer = A5;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
pinMode(left, OUTPUT);
pinMode(mid, OUTPUT);
pinMode(right, OUTPUT);
pinMode(A5, INPUT);
}

int calculate_speed()
  {
    potvalue = analogRead(A5);
    speedies = map(potvalue, 0, 1023, fastest, 1000);
    return speedies;
  }

void loop() {
  // put your main code here, to run repeatedly:
switch (sequence)
  {
    case 1:{//scroll left to right
      for (repeat = 0; repeat <= 4; repeat++){
        for (int x = 0; x <= 2; x++){
            digitalWrite(led[x], HIGH);
            delay(calculate_speed());
            digitalWrite(led[x], LOW);
          }
      }
        sequence++; 
        }
        
    case 2:{//scroll right to left
      for (repeat = 0; repeat <= 4; repeat++){
        for (int x = 2; x >= 0; x--){
            digitalWrite(led[x], HIGH);
            delay(calculate_speed());
            digitalWrite(led[x], LOW);
        }
      }
        sequence++;
      }
      
    case 3:{//blink left 5 times
        for (int x = 0; x <= 4; x++){
            digitalWrite(left, HIGH);
            delay(calculate_speed());
            digitalWrite(left, LOW);
            delay(calculate_speed());
        }
        sequence++;
    }
    
    case 4:{//blink mid 5 times
         for (int x = 0; x <= 4; x++){
            digitalWrite(mid, HIGH);
            delay(calculate_speed());
            digitalWrite(mid, LOW);
            delay(calculate_speed());
        }
        sequence++;
    }
    
    case 5:{//blink right 5 times
         for (int x = 0; x <= 4; x++){
            digitalWrite(right, HIGH);
            delay(calculate_speed());
            digitalWrite(right, LOW);
            delay(calculate_speed());
        }
        sequence++;
    }

    case 6:{//alternate mid and side blink
        for (repeat = 0; repeat <= 4; repeat++)
          {
            digitalWrite(mid, HIGH);
            digitalWrite(left, LOW);
            digitalWrite(right, LOW);
            delay(calculate_speed());
            digitalWrite(left, HIGH);
            digitalWrite(right, HIGH);
            digitalWrite(mid, LOW);
            delay(calculate_speed());
          }
          sequence++;
    }

    case 7:{//blink left and right
         for (int x = 0; x <= 4; x++){
            digitalWrite(left, HIGH);
            digitalWrite(right, HIGH);
            delay(calculate_speed());
            digitalWrite(left, LOW);
            digitalWrite(right, LOW);
            delay(calculate_speed());
         }
         sequence++;
    }
    
    case 8:{//blink left and mid
        for (repeat = 0; repeat <= 4; repeat++)
          {
            digitalWrite(left,HIGH);
            digitalWrite(mid, HIGH);
            digitalWrite(right, LOW);
            delay(calculate_speed());
            digitalWrite(left, LOW);
            digitalWrite(mid, LOW);
            digitalWrite(right, LOW);
            delay(calculate_speed());
          }
          sequence++;
    }
    
    case 9:{//blink mid and right
         for (repeat = 0; repeat <= 4; repeat++)
          {
            digitalWrite(right,HIGH);
            digitalWrite(mid, HIGH);
            digitalWrite(left, LOW);
            delay(calculate_speed());
            digitalWrite(left, LOW);
            digitalWrite(mid, LOW);
            digitalWrite(right, LOW);
            delay(calculate_speed());
          }
          sequence++;
    }
    
    case 10:{//glowing everything
      brightness = 0;
      for (repeat = 0; repeat <= 2; repeat++)
        {
          while (brightness <= 255){
            analogWrite(left, brightness);
            analogWrite(mid, brightness);
            analogWrite(right, brightness);
            brightness++;
            delay(calculate_speed()/fade_speed);
          }
          
          while (brightness > 0){
            analogWrite(left, brightness);
            analogWrite(mid, brightness);
            analogWrite(right, brightness);
            brightness--;
            delay(calculate_speed()/fade_speed);
          }
        }

            sequence++;
    }
    
    case 11:{//blink everything
         for (repeat = 0; repeat <= 4; repeat++)
            {
              digitalWrite(left,HIGH);
              digitalWrite(mid, HIGH);
              digitalWrite(right, HIGH);
              delay(calculate_speed());
              digitalWrite(left,LOW);
              digitalWrite(mid, LOW);
              digitalWrite(right, LOW);
              delay(calculate_speed());
            }
         sequence++;
    }
    
    case 12:{//right to left fade cascade
          for (repeat = 0; repeat <= 2; repeat++)
            {
              for (int brightness = 255, brightness2 = 0; brightness > 0, brightness2 <= 255; brightness--, brightness2++)
                {
                  analogWrite(led[0], brightness);
                  analogWrite(led[1], brightness2);
                  delay(calculate_speed()/fade_speed); 
                }
                
              for (int brightness = 0, brightness2 = 255; brightness <= 255, brightness2 > 0; brightness++, brightness2--)
                {
                  analogWrite(led[1], brightness);
                  analogWrite(led[2], brightness2);
                  delay(calculate_speed()/fade_speed); 
                }
             
            }
            sequence++;
    }
    
    case 13:{//right to left fade jump
      digitalWrite(mid, LOW);
          for (repeat = 0; repeat <= 2; repeat++)
            {
               for (int brightness = 255, brightness2 = 0; brightness > 0, brightness2 <= 255; brightness--, brightness2++)
                {
                  analogWrite(led[2], brightness);
                  analogWrite(led[0], brightness2);
                  delay(calculate_speed()/fade_speed); 
                }
                
              for (int brightness = 0, brightness2 = 255; brightness <= 255, brightness2 > 0; brightness++, brightness2--)
                {
                  analogWrite(led[2], brightness);
                  analogWrite(led[0], brightness2);
                  delay(calculate_speed()/fade_speed); 
                }
            }
            sequence++;
    }

    case 14:{//crazy jumping led
        for (repeat = 0; repeat <= 4; repeat++){
            digitalWrite(led[0], HIGH);
            digitalWrite(led[1], LOW);
            digitalWrite(led[2], LOW);
            delay(calculate_speed());
            digitalWrite(led[0], LOW);
            digitalWrite(led[1], LOW);
            digitalWrite(led[2], HIGH);
            delay(calculate_speed());
            digitalWrite(led[0], LOW);
            digitalWrite(led[1], HIGH);
            digitalWrite(led[2], LOW);
            delay(calculate_speed());
            digitalWrite(led[0], LOW);
            digitalWrite(led[1], LOW);
            digitalWrite(led[2], HIGH);
            delay(calculate_speed());
            digitalWrite(led[0], HIGH);
            digitalWrite(led[1], LOW);
            digitalWrite(led[2], LOW);
            delay(calculate_speed());
            digitalWrite(led[0], LOW);
            digitalWrite(led[1], HIGH);
            digitalWrite(led[2], LOW);
            delay(calculate_speed());
        }
          
    }
    
    case 15:{//static mid and fading left and right
          for (repeat = 0; repeat <= 2; repeat++){
              for (int brightness = 0; brightness <= 255; brightness++)
                {
                  analogWrite(led[0], brightness);
                  analogWrite(led[2], brightness);
                  delay(calculate_speed()/fade_speed);
                }
              digitalWrite(mid, HIGH);
              delay(calculate_speed());
              digitalWrite(mid, LOW);
              delay(calculate_speed());
               for (int brightness = 255; brightness > 0; brightness--)
                {
                  analogWrite(led[0], brightness);
                  analogWrite(led[2], brightness);
                  delay(calculate_speed()/fade_speed);
                }
              digitalWrite(mid, HIGH);
              delay(calculate_speed());
              digitalWrite(mid, LOW);
              delay(calculate_speed());
          }
      sequence++;
    }
    
    case 16:{//mid fade
             digitalWrite(right, LOW);
       digitalWrite(left, LOW);
          for (repeat = 0; repeat <= 2; repeat++)
            {
               for (int brightness = 255, brightness2 = 0; brightness > 0, brightness2 <= 255; brightness--, brightness2++)
                {
                  analogWrite(led[1], brightness);
                  delay(calculate_speed()/fade_speed); 
                }
                
              for (int brightness = 0, brightness2 = 255; brightness <= 255, brightness2 > 0; brightness++, brightness2--)
                {
                  analogWrite(led[1], brightness);
                  delay(calculate_speed()/fade_speed); 
                }
            }
            sequence++;
    }

    case 17:{//static left and right while mid is fading
        for (repeat = 0; repeat <= 2; repeat++){
              for (int brightness = 0; brightness <= 255; brightness++)
                {
                  analogWrite(led[1], brightness);
                  delay(calculate_speed()/fade_speed);
                }
                
              digitalWrite(left, HIGH);
              digitalWrite(right, HIGH);
              delay(calculate_speed());
              digitalWrite(left, LOW);
              digitalWrite(right, LOW);
              delay(calculate_speed());
              
               for (int brightness = 255; brightness > 0; brightness--)
                {
                  analogWrite(led[1], brightness);
                  delay(calculate_speed()/fade_speed);
                }
                
              digitalWrite(left, HIGH);
              digitalWrite(right, HIGH);
              delay(calculate_speed());
              digitalWrite(left, LOW);
              digitalWrite(right, LOW);
              delay(calculate_speed());
          }
      sequence++;
      }

    case 18:{//pulse left, fade mid, pulse right
      for (repeat = 0; repeat <= 2; repeat++)
        {
          digitalWrite(led[0], HIGH);
          delay(calculate_speed());
          digitalWrite(led[0], LOW);
          delay(calculate_speed());
          digitalWrite(led[0], HIGH);
          delay(calculate_speed());
          digitalWrite(led[0], LOW);
          delay(calculate_speed());

          for (brightness = 0; brightness <= 255; brightness++){
            analogWrite(led[1], brightness);
            delay(calculate_speed()/fade_speed);
          }

          for (brightness = 255; brightness <= 0; brightness--){
            analogWrite(led[1], brightness);
            delay(calculate_speed()/fade_speed);
        }

          digitalWrite(led[2], HIGH);
          delay(calculate_speed());
          digitalWrite(led[2], LOW);
          delay(calculate_speed());
          digitalWrite(led[2], HIGH);
          delay(calculate_speed());
          digitalWrite(led[2], LOW);
          delay(calculate_speed());     
    }
    sequence++;
  }

  case 19:{//fade left and alternate mid and right
      for (repeat = 0; repeat <= 2; repeat++)
        {
          digitalWrite(led[1], HIGH);
          delay(calculate_speed());
          digitalWrite(led[1], LOW);
          delay(calculate_speed());
          digitalWrite(led[1], HIGH);
          delay(calculate_speed());
          digitalWrite(led[1], LOW);
          delay(calculate_speed());

          digitalWrite(led[2], HIGH);
          delay(calculate_speed());
          digitalWrite(led[2], LOW);
          delay(calculate_speed());
          digitalWrite(led[2], HIGH);
          delay(calculate_speed());
          digitalWrite(led[2], LOW);
          delay(calculate_speed());     

          for (brightness = 0; brightness <= 255; brightness++){
            analogWrite(led[0], brightness);
            delay(calculate_speed()/fade_speed);
          }

          for (brightness = 255; brightness <= 0; brightness--){
            analogWrite(led[0], brightness);
            delay(calculate_speed()/fade_speed);
        }
    }
    sequence++;
  }

  case 20:{//fading right and alternating left and mid
        for (repeat = 0; repeat <= 2; repeat++)
        {
          digitalWrite(led[0], HIGH);
          delay(calculate_speed());
          digitalWrite(led[0], LOW);
          delay(calculate_speed());
          digitalWrite(led[0], HIGH);
          delay(calculate_speed());
          digitalWrite(led[0], LOW);
          delay(calculate_speed());

          digitalWrite(led[1], HIGH);
          delay(calculate_speed());
          digitalWrite(led[1], LOW);
          delay(calculate_speed());
          digitalWrite(led[1], HIGH);
          delay(calculate_speed());
          digitalWrite(led[1], LOW);
          delay(calculate_speed());   

          for (brightness = 0; brightness <= 255; brightness++){
            analogWrite(led[2], brightness);
            delay(calculate_speed()/fade_speed);
          }

          for (brightness = 255; brightness <= 0; brightness--){
            analogWrite(led[2], brightness);
            delay(calculate_speed()/fade_speed);
        }  
    }
    sequence++;
  }
  
  }//switch end brace
sequence = 1;
}//end ng void loop
