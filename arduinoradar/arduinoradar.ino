#define mindeg 0
#define maxdeg 90
#define stepdeg 1
#define pinecho 3
#define pintrigger 4
int state = 1;
int deg = mindeg;
int dist;
String data = "data:";
void setup() {
  pinMode(pintrigger, OUTPUT);
  pinMode(pinecho,INPUT);
  Serial.begin(9600);
}
int mesuredistance(){
  digitalWrite(pintrigger, LOW);
  delayMicroseconds(2);
  digitalWrite(pintrigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(pintrigger, LOW);
  return pulseIn(pinecho, HIGH) * 0.034 / 2;
}

void loop() {
  deg = deg + state;
  data = data + ";" + deg + "," + 10;
  if(deg == maxdeg){
      state = 0-stepdeg;
      Serial.println(data);
      data = "data:";
  }
  if(deg == mindeg){
      state = stepdeg;
      Serial.println(data);
      data = "data:";
  }
  delay(10);

}
