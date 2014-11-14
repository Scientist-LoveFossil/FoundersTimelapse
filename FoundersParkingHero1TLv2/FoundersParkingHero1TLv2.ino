
//GoPro Hero 1 Timelaspe Sketch for Advance Packaging
// by K. Cole 2014
//

const int chargeGoPro = 8;
const int CtrlGoPro = 9;
const int LedPwr = 13;
const int LedStat = 11;

int ledState = LOW;
long previousMillis =0;
long interval = 1000;
#define TWOmin 120000
#define OFF 3800
#define ON 1400


void setup(){

  Serial.begin(9600);
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
  //digitalWrite(8, LOW);
  pinMode(10, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(11, OUTPUT);
  charge45();
} 


void loop() {
 for (int totalloops = 1; totalloops < 4; totalloops++){
    for (int x = 1; x < 60; x++){
    startup();
    Serial.println("out of Startup");
    delay(1000);
    charge();
    delay(30000);
    Serial.println("out of charge");
  }
     charge45();
 }
  off();
}




 void startup() {
  Serial.println("Turning on GoPro");
  
  delay(2000); 
  
  digitalWrite(LedStat, HIGH);  //start sequence to make sure gopro is off before charge sequence
  digitalWrite(CtrlGoPro, HIGH);
  delay(ON);
  digitalWrite(LedStat, LOW);
  
  digitalWrite(CtrlGoPro, LOW);
   for (int i = 1; i < 75; i++){
   //delay(6000);
          digitalWrite(LedPwr, HIGH); //30 second warning blink- 30 seconds until Pic is taken.
          delay(250);
          digitalWrite(LedPwr, LOW);
         delay(250);
       }
  Serial.println("Turning Off GP");
  digitalWrite(CtrlGoPro, HIGH);
  delay(OFF);
  digitalWrite(CtrlGoPro, LOW); 
 }
 
 
 void charge(){
  
Serial.println("Charging two minutes");
digitalWrite(chargeGoPro, HIGH); //turn on 5v bus

  for (int i = 1; i < 100; i++){  // Keep LED on steady for 1.5 minutes
        digitalWrite(LedPwr, HIGH);
        delay(1000);
       }
      
  for (int i = 1; i < 30; i++){
   //delay(6000);
          digitalWrite(LedPwr, HIGH); //30 second warning blink- 30 seconds until Pic is taken.
          delay(500);
          digitalWrite(LedPwr, LOW);
         delay(500);
       }
 
  digitalWrite(chargeGoPro, LOW);
  delay(2000); 
  Serial.println("two minutes charged");
  
 }
  void charge45(){
  
Serial.println("Charging 45 minutes");
digitalWrite(chargeGoPro, HIGH); //turn on 5v bus

  for (long i = 1; i < 5400; i++){
   //delay(6000);
          digitalWrite(LedPwr, HIGH); //30 second warning blink- 30 seconds until Pic is taken.
          delay(250);
          digitalWrite(LedPwr, LOW);
         delay(250);
       }
 
  digitalWrite(chargeGoPro, LOW);
  delay(2000); 
  Serial.println("two minutes charged");
  
 }
 
   void off(){
  
 digitalWrite(CtrlGoPro, HIGH);
  delay(OFF);
  digitalWrite(CtrlGoPro, LOW); 
  
  delay(2500000);
 }
