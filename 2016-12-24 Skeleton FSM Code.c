/*****************************************
Example - State Machine Case Statement

This is a basic skeleton program for a
Finite State Machine.  

IMPORTANT!  NEVER use delay() or any delay
creating code in the state case loop.  If
you need a timing reference, increase or
decrease the state machine clock frequency
and handle delays by adding extra states
or count the number of state cycles to delay.

All I/O except very simple digitalWrite()
output should be done in functions called
from loop().  This allows us to get the basic
functionality of our program working in loop()
then make changes only to external functions.
If the program stops working we know it is
not the loop() at fault.  This is particularly
important when switching between programmed
I/O and interrupt driven I/O (which is hard
to debug in the limited Arduino environment).

NOTES:

There is one difference between a FSM created 
using this template and the generic FMS we 
discussed in class.  In the interest of 
simplicity, here the inputs are only evaluated
at the beginning of the state cycle rather
than at the end.  If the inputs are asynchronous
external events (like humans pressing
buttons) this should not cause a problem but
you should be aware of the difference.

This FSM has a short cycle every 50 days when
the millis() counter overflows.

The FSM cycle time is only accurate to 
about one millisecond.  You can use the 
micros() function to get tighter timing
resolution but you will probably also 
have to deal with timer overflow.

by: David Abrams
ES-52

date: November 19, 2014
mru: 2015-05-14 replace millis() with delay()
     2015-11-10 use fsmFreq directly
     2016-11-14 clean up
     2016-12-24 update for more accurate timing
*****************************************/

// Constant variables set by the user before compiling to control program behavior
const boolean debug = true;   // when set to true, debugging statements sent to the PC
const int FSM_FREQ = 20;      // set to frequency of state machine clock in Hz (max 500Hz)

// Program Variables

const int FSM_TIME = 1000/FSM_FREQ; // milliseconds per state cycle (do not change this variable)
unsigned long CycleStart;
int CurState;                 // holds current/next state

     


void setup()
{
   CurState = 1;              // initialize for first state in the program loop
   
   /* Set up serial port for debugging if enabled */
   if (debug)
   {
     Serial.begin(9600);               // This pipes serial print data to the serial monitor
     Serial.println("Initialization complete.");
   }
}


// FINITE STATE MACHINE LOOP
// We use the switch/case statement to execute only the code for the current state.
// Then we figure out what the next state is and continue the main program loop.

void loop()
{
   CycleStart = millis();           // get time we started this FSM cycle
   // first do anything we need to do before every state cycle
   if (debug)
   {
      Serial.print("Current State = ");
      Serial.println(CurState);      
   }

  switch (CurState)
   {
      case 1:
         /* do whatever we do in state 1 here */
         /* for example set an output pin */
         if (<something>)   // see what state we go to next
            CurState = 1;   // perhaps we stay in this one
         else
            CurState = 2;   // or go to the next one
         break;

      case 2:
         break;
         
      default:
         {
         }
   } // end of switch statement


   // Here we can add anything that needs to get done after every FSM cycle
   

   // Finally we need to wait one cycle before entering the next state (this simulates the FSM clock)
   while (millis() < (CycleStart + FSM_TIME)) {
   }                                                // wait one FSM cycle     
}