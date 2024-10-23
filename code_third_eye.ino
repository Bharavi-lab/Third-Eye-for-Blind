int trigPin = 9;      // trig pin of HC-SR04
int echoPin = 8;    // Echo pin of HC-SR04
int buzzer = 5;      
int motor = 4;      
long duration, distance;
void setup() {
 delay(random(500,2000));   // delay for random time
  Serial.begin(9600);
  pinMode(buzzer, OUTPUT);      // set Motor pins as output
  pinMode(motor, OUTPUT);
  pinMode(trigPin, OUTPUT);         // set trig pin as output
  pinMode(echoPin, INPUT);          //set echo pin as input to capture reflected waves
  digitalWrite(buzzer, LOW);                    // move forward
  digitalWrite(motor, LOW);
}
void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);   
  digitalWrite(trigPin, HIGH);     // send waves for 10 us
 delayMicroseconds(10);
 duration = pulseIn(echoPin, HIGH); // receive reflected waves
 distance = duration / 58.2;   // convert to distance
  delay(10);
    // If you dont get proper movements of your robot then alter the pin numbers
  if (distance < 70)      
{
    digitalWrite(buzzer, HIGH);            
    digitalWrite(motor, HIGH);
    delay(1000);
  }
  else {
    digitalWrite(buzzer, LOW);     
    digitalWrite(motor, LOW);
    delay(1000);
    }}
