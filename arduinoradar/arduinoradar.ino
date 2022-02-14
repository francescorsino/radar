#define mindeg 0
#define maxdeg 90
#define stepdeg 1
int state = 1;
int deg = mindeg;
void setup() {
  Serial.begin(9600);
  Serial.println("radar");
}

void loop() {
  Serial.println(deg);
  deg = deg + state;
  if(deg == maxdeg){
      state = 0-stepdeg;
  }
  if(deg == mindeg){
      state = stepdeg;
  }

}
