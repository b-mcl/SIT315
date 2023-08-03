// C++ code
//Set up pins
int led = 13;
int motion = 2;

void setup()
{
  //Set up pins
  pinMode(led, OUTPUT);
  pinMode(motion, INPUT);
  
  //attach interrupt to motion pin, trigger on change
  attachInterrupt(digitalPinToInterrupt(motion), changeInMotion, CHANGE);
  
  //Baud rate
  Serial.begin(9600);
}

void loop()
{
  //Nothing here
}

//function to handle interrupt
void changeInMotion(){
  //if motion is detected, print the message that theres motion
  //and switch the LED on
  if(digitalRead(motion) == 1){
  	digitalWrite(led, digitalRead(motion));
  	Serial.println("MOTION DETECTED, LED ON");
  }
   //if no motion detected, print this message
     else{
     	Serial.println("NO MOTION DETECTED, LED OFF");
     }
}