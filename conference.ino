/*****************************************************************************
Particle Maker Kit Tutorial #3: PIR Motion Sensor

This tutorial uses a Photon and the PIR motion sensor from the Particle Maker
Kit to determine whether a conference room is in use (you could also use it
for many other applications) and post the status to Slack.
******************************************************************************/

int ledPin = D7;                 // choose the pin for the LED
int inputPin = D2;               // choose the PIR sensor pin
String status = "available to start the day";          // string to hold "available" or "in use",
int pirState = 0;
int currentState = LOW; 

void setup() {
  pinMode(ledPin, OUTPUT);       // set LED as output
  pinMode(inputPin, INPUT);      // set sensor as input
  Particle.publish("conf_avail", status, PRIVATE); // send test publish
  Serial.begin(9600);
}


void loop() 
{
    pirState = digitalRead(inputPin);
    Serial.printlnf("PIR State %d", pirState);

    if (currentState == LOW && pirState == HIGH) {  // check if the input is HIGH
        digitalWrite(ledPin, HIGH);         // turn LED ON if high
        status = "in use";  
        Particle.publish("conf_avail", status, PRIVATE); //publish to conf_avail webhook
        currentState = HIGH;
    } 
    if (currentState == HIGH && pirState == LOW) {
        digitalWrite(ledPin, LOW);          // turn LED OFF if no input
        status = "available";
        Particle.publish("conf_avail", status, PRIVATE); //publish to conf_inuse webhook
        currentState = LOW; 
    }

    delay(2000);
}
