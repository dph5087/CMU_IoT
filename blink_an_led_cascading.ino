// ------------
// Blink an LED Cascading
// ------------

/*-------------

We've heavily commented this code for you. If you're a pro, feel free to ignore it.

Comments start with two slashes or are blocked off by a slash and a star.
You can read them, but your device can't.
It's like a secret message just for you.

Every program based on Wiring (programming language used by Arduino, and Particle devices) has two essential parts:
setup - runs once at the beginning of your program
loop - runs continuously over and over

You'll see how we use these in a second.

This program will blink an led on and off every second.
It blinks the D7 LED on your Particle device. If you have an LED wired to D0, it will blink that LED as well.

-------------*/


// First, we're going to make some variables.
// In this example, we'll use integer type varibles or "int" for short
// This is our "shorthand" that we'll use throughout the program:

int led1 = D0; // Instead of writing D0 over and over again, we'll write led1
//D0 is the pin on the bottom right of the Argon labeled SDA.
// You'll need to wire an LED to this one to see it blink.

int led2 = D7; // Instead of writing D7 over and over again, we'll write led2
// D7 is one of the available pins on the board, but it is also the little blue LED on your board located in the upper right hand corner.

int led3 = D2;
// This will be our third LED

// Having declared these variables, let's move on to the setup function.
// The setup function is a standard part of any microcontroller program.
// It runs only once when the device boots up or is reset.

void setup() {

 // We are going to tell our device that D0 and D7 (which we named led1 and led2 respectively) are going to be output
 // (That means that we will be sending voltage to them, rather than monitoring voltage that comes from them)

 // It's important you do this here, inside the setup() function rather than outside it or in the loop function.

 pinMode(led1, OUTPUT);
 pinMode(led2, OUTPUT);
 pinMode(led3, OUTPUT);

}

// Next we have the loop function, the other essential part of a microcontroller program.
// This routine gets repeated over and over, as quickly as possible and as many times as possible, after the setup function is called.
// Note: Code that blocks for too long (like more than 5 seconds), can make weird things happen (like dropping the network connection).  The built-in delay function shown below safely interleaves required background activity, so arbitrarily long delays can safely be done if you need them.

void loop() {
 // Turn on the first LED
 digitalWrite(led1, HIGH);
 digitalWrite(led2, LOW);
 digitalWrite(led3, LOW);

 // We'll wait for 1 second...
 delay(1000);

 // Turn off the first LED and turn on the second
 digitalWrite(led1, LOW);
 digitalWrite(led2, HIGH);
 digitalWrite(led3, LOW);
 
 // Wait 1 second...
 delay(1000);
 
  // Turn off the second LED and turn on the third
 digitalWrite(led1, LOW);
 digitalWrite(led2, LOW);
 digitalWrite(led3, HIGH);
 
  // Wait 1 second...
 delay(1000);
 
  // Turn off the third LED and turn on the second
 digitalWrite(led1, LOW);
 digitalWrite(led2, HIGH);
 digitalWrite(led3, LOW);
 
 // Wait 1 second...
 delay(1000);

 // And repeat!
}
