#include <LiquidCrystal.h>  
int Contrast=90;
 LiquidCrystal lcd(12, 11, 5, 4, 3, 2);   
#define echoPin 7 // attach pin D2 Arduino to pin Echo of HC-SR04
#define trigPin 13 //attach pin D3 Arduino to pin Trig of HC-SR04

// defines variables
long duration; // variable for the duration of sound wave travel
int distance; // variable for the distance measurement

int button = 0;

int t1 = 1;

 void setup()
 { 
     pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
     pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT
     pinMode(8,INPUT);
     pinMode(10,OUTPUT);
     Serial.begin(9600); // // Serial Communication is starting with 9600 of baudrate speed
     Serial.println("Ultrasonic Sensor HC-SR04 Test"); // print some text in Serial Monitor
     Serial.println("with Arduino UNO R3");
    analogWrite(6,Contrast);
     lcd.begin(16, 2);
  }  
     void loop()
 {  
   
    button = digitalRead(8);
    
    digitalWrite(10,HIGH);
    
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    // Reads the echoPin, returns the sound wave travel time in microseconds
    duration = pulseIn(echoPin, HIGH);
    // Calculating the distance
    distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
    // Displays the distance on the Serial Monitor
    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm");
    
   
     lcd.setCursor(0, 0);
     lcd.print("");
     lcd.print(distance);
     
     if (distance < 10){
       lcd.setCursor(1, 0);
       lcd.print("    ");
     }
     else if (distance < 100){
       lcd.setCursor(2, 0);
       lcd.print("    ");
     }
     else if (distance > 1000){
       lcd.setCursor(0, 0);
       lcd.print("err    ");
     }
     if (button == 0){
       delay(500);
       lcd.setCursor(6,0);
       lcd.print("Locked");
       digitalWrite(10,LOW);
       while (t1 == 1){
         Serial.print("hi");
         
         button = digitalRead(8);
         
         if (button == 0){
           break;
         }
       }
       lcd.setCursor(6,0);
       lcd.print("         ");
       delay(500);
       
     
     }
     
     
     

    
    lcd.setCursor(0, 1);
    lcd.print("                                    ");
    lcd.setCursor(0, 1);
     lcd.print("spiff.co");
     
     
}
