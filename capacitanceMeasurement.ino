float R = 4700;
float C = 0;
volatile long tStart = 0;
volatile long tEnd = 0;
const int ledPin = 13;

long T = 0;

void setup(){
  Serial.begin(9600);
  attachInterrupt(0,startClock,RISING);
  attachInterrupt(1,stopClock,FALLING);
  pinMode(ledPin,OUTPUT);
}


void loop(){
  if(tEnd > 0){
    T = tEnd - tStart;
    C = (T*1000)/(1.1*R);
//    Serial.println(C);
    tStart = 0;
    tEnd = 0; 
  }
  Serial.println(analogRead(A3)*5.0/1024);
}


void startClock(){
  tStart = millis();
  digitalWrite(ledPin,HIGH);
}

void stopClock(){
  tEnd = millis();
  digitalWrite(ledPin,LOW);
}

