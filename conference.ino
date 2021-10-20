/*****************************************************************************
Revised Particle Maker Kit Tutorial #3: PIR Motion Sensor

This tutorial uses a Particle Argon and PIR motion sensor
to determine whether a conference room is in use (you could also use it
for many other applications) and post the status to Slack.
******************************************************************************/

// Define your variables
int ledPin          =   D7;     // Choose the D7 pin for the LED
int inputPin        =   D2;     // Choose the D2 pin for the PIR sensor
int pirState        =   LOW;    // Create a variable to capture the PIR state when read from the D2 pin.
int currentState    =   LOW;    // This variable will be compared to the pirState varible to determine the status of the conference room. Set it LOW to start.

// Create a string to hold the status of the conference room. 
// This status will eventually switch between "available" or "in use" depending on the status of the PIR sensor
String status = "available to start the day";

// Setup loop
void setup() 
{
    pinMode(ledPin, OUTPUT);       // set LED as output
    pinMode(inputPin, INPUT);      // set PIR sensor as input
    
    // Use the particle publish function to send the initial status of the conference room to slack
    // If successful, this will tell you the conference room is "available to start the day" on slack
    Particle.publish("conf_avail", status, PRIVATE); 
    
    // Start the serial monitor for troubleshooting. 
    Serial.begin(9600); // This line is optional and can be deleted if not needed. 
}

// Start the loop
void loop() 
{
    //Read the PIR sensor and hold the value in the pirState variable. 
    pirState = digitalRead(inputPin);
    
    // Print the PIR State to serial for troubleshooting purposes.
    Serial.printlnf("PIR State %d", pirState);  // This line is optional and can be deleted if not needed

    // Compare the current State to the pirState.
    // If currentState is LOW and pirState is HIGH, this means someone entered a vacant conference room.
    if (currentState == LOW && pirState == HIGH) 
    {  
        digitalWrite(ledPin, HIGH); // turn LED ON to signify the room is in use
        status = "in use"; // Set the conference room status to "in use" 
        Particle.publish("conf_avail", status, PRIVATE); //publish to conf_avail webhook. This will send the new status to Slack
        currentState = HIGH; // Set the currentState to HIGH since the room is now in use.
    } 
    
    // Compare the current State to the pirState.
    // If currentState is HIGH and pirState is LOW, this means the conference room is empty again.
    if (currentState == HIGH && pirState == LOW) 
    {
        digitalWrite(ledPin, LOW);          // turn LED OFF to signify the room is empty
        status = "available"; // Set the conference room status to "available"
        Particle.publish("conf_avail", status, PRIVATE); //publish to conf_avail webhook. This will send the new status to Slack
        currentState = LOW; //Set the currentState to LOW since the room is now empty.
    }

    // 2 second delay in between PIR readings.
    delay(2000);
}
