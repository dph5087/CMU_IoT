// -----------------------------------
// Controlling LEDs over the Internet
// -----------------------------------

// First, let's create our "shorthand" for the pins
// Same as in the Blink an LED example:
// led1 is D0, led2 is D7

int led1 = D0;
int led2 = D7;

// Introducting a boolean variable here. Booleans can either be HIGH or LOW (1 or 0).
// This variable will help tell the program if we should go in or out of the loop.
// Let's set it to LOW or 0 to start. 
bool led_loop = LOW;

// Last time, we only needed to declare pins in the setup function.
// This time, we are also going to register our Particle function

void setup()
{

   // Here's the pin configuration, same as last time
   pinMode(led1, OUTPUT);
   pinMode(led2, OUTPUT);

   // We are also going to declare a Particle.function so that we can turn the LED on and off from the cloud.
   Particle.function("led",ledToggle);
   // This is saying that when we ask the cloud for the function "led", it will employ the function ledToggle() from this app.

   // For good measure, let's also make sure both LEDs are off when we start:
   digitalWrite(led1, LOW);
   digitalWrite(led2, LOW);

}


// We are adding a while loop inside the loop function.
// The while loop says "while the boolean led_loop is equal to 1 (or HIGH), toggle the LED on and off
// If the boolean led_loop becomes 0 (or LOW), the program will exit the loop

void loop()
{
    while (led_loop == HIGH)
       {
            digitalWrite(led1,HIGH);
            digitalWrite(led2,HIGH);
            
            delay(1000);
            
            digitalWrite(led1,LOW);
            digitalWrite(led2,LOW);
            
            delay(1000);
       }
}

// We're going to have a super cool function now that gets called when a matching API request is sent
// This is the ledToggle function we registered to the "led" Particle.function earlier.


int ledToggle(String command) {
    /* Particle.functions always take a string as an argument and return an integer.
    Since we can pass a string, it means that we can give the program commands on how the function should be used.
    In this case, telling the function "on" will initiate the activateLoop function, turning the LED on and telling it "off" will activate the deactivateLoop function to turn the LED off.
    Then, the function returns a value to us to let us know what happened.
    In this case, it will return 1 for the LEDs turning on, 0 for the LEDs turning off,
    and -1 if we received a totally bogus command that didn't do anything to the LEDs.
    */

    if (command=="on") {
        // When the command == on, trigger the activateLoop function. See below in the code.
        activateLoop();
        return 1;
    }
    else if (command=="off") {
        // When the command == off, trigger the deactivateLoop function See below in the code.
        deactivateLoop();
        return 0;
    }
    else {
        return -1;
    }
}

// This function sets the boolean to 1 (or HIGH), which will activate the while loop inside the loop function above and start blinking the LEDs
// See the additional comments at the end for more information.
void activateLoop()
{
    led_loop = HIGH;

}

// This function will set the boolean to 0 (or LOW), which will kick the program out of the loop function and turn off the LEDs
// See the additional comments at the end for more information.
void deactivateLoop()
{
    led_loop = LOW;
    digitalWrite(led1,LOW);
    digitalWrite(led2,LOW);
}

// Additional comments
// While the code inside the "activateLoop" and "deactivateLoop" functions could have simply been entered inside the ledToggle Particle function,
// it can be helpful to separate out specific actions into their own functions. This becomes increasingly more important as your code becomes more complex.
// For example, if you had multiple commands in your program that could cause LEDs to blink and you wanted to modify the timing of the LEDs or add an additional LED,
// you would only need to modify the contents of the single function rather than every instance of setting the LED pins to HIGH and LOW. 
