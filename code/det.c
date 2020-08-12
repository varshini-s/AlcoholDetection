#include <MotorDriver.h>


#include <LiquidCrystal.h>
int val=0;
const int ledred=8;
const int ledgreen=7;
const int motorpin=6;
const int buzzer=9;
const int motorPin1  = 10;  // Pin Conected to Ia1
const int motorPin2  = 13;  // Pin Conected to Ia2
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup()
            {
              Serial.begin(9600);
            pinMode(ledred,OUTPUT);
            pinMode(ledgreen,OUTPUT);
            pinMode(motorpin,OUTPUT);
            pinMode(buzzer,OUTPUT);
            pinMode(motorPin1, OUTPUT);
            pinMode(motorPin2, OUTPUT);
             // set up the LCD's number of columns and rows: 
            lcd.begin(16, 2);
             // Print a message to the LCD.
             lcd.print("alcohol content");
            

}

void loop()
{  

      val=analogRead(A0);
      Serial.println(val);
       lcd.setCursor(0, 1);
       lcd.print(val);
      if(val>600)
      {
      digitalWrite(ledgreen,LOW);
      digitalWrite(ledred,LOW);
      digitalWrite(ledred,HIGH);
      digitalWrite(motorPin1,LOW);
 
       digitalWrite(motorpin,LOW);
       digitalWrite(buzzer,HIGH);
  }
else
  { 
      digitalWrite(ledred,LOW);
      
      digitalWrite(ledgreen,LOW);
      
      digitalWrite(ledgreen,HIGH);
      digitalWrite(buzzer,LOW);
      digitalWrite(motorpin,HIGH);
     
    digitalWrite(motorPin1, HIGH);  
    digitalWrite(motorPin2, LOW);   
    delay(1);
        
  }


    delay(100); 
}
