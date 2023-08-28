int x=2;
int LED1=4;
int LED2=5;

void setup() {
   pinMode (LED1, OUTPUT);
   pinMode(LED2, OUTPUT);
}
void loop() {
if(x == 2){
  digitalWrite(LED2, HIGH);
  digitalWrite(LED1, LOW);
}
else{
  digitalWrite(LED1, HIGH);
  digitalWrite(LED2, LOW);
} 
}
