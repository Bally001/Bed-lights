int LDR = A7;
int PIR1 = 5;
int PIR2 = 8;
int LED = 3;

bool pirState1;
bool pirState2;
int ldrValue;

unsigned long movtTime;
unsigned long currentTime;
const int onTime = 30000;


void setup() {
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
  pinMode(PIR1, INPUT);
  pinMode(PIR2, INPUT);
  digitalWrite(LED, LOW);
}

void loop(){
  ldrValue = analogRead(LDR);
  pirState1 = digitalRead(PIR1);
  pirState2 = digitalRead(PIR2);  
  /*Serial.print("Analog reading = ");
  Serial.println(ldrValue);
  Serial.print("PIR1 reading = ");
  Serial.println(pirState1);  
  Serial.print("PIR2 reading = ");
  Serial.println(pirState2);
  */

   if (pirState1 == HIGH | pirState2 == HIGH) {
    movtTime = millis();
   
     if ldrValue <= 10 {
     turnOn();
     }
   }

   if (pirState1 == LOW & pirState2 == LOW) & (currentTime - movtTime >= onTime) {
    turnOff();
   }

   else { // ldrValue > 4
     digitalWrite(LED, LOW);
   }


  // The processing in the Arduino occurs faster
  // than the response from the PIR, and adding this delay
  // eliminated a flickering on the LED
  delay(100);
  currentTime = millis();
}

void turnOn() {
  for (int i=0; i<=50; i+=5)
        {
          analogWrite(LED, i);
          delay(200);
        }
}

void turnOff() {
  for (int i=50; i>=0; i-=5)
        {
          analogWrite(LED, i);
          delay(200);
        }
}

