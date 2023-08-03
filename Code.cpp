// C++ code
//First set pins for quality of life
int led = 13;
int temperature = A0;

void setup()
{
  pinMode(led, OUTPUT);
  pinMode(temperature, INPUT);
  Serial.begin(9600);//set baud rate
}

void loop()
{//converting reading into degrees celcius
  //https://lastminuteengineers.com/tmp36-temperature-sensor-arduino-tutorial/
  float voltage = analogRead(temperature) *( 5.0 / 1024.0);
  
  float celcius = (voltage - 0.5) *100;
  
  //if its hot turn on LED
  if (celcius >= 30){
  	digitalWrite(led, HIGH); 
  }
  
  else{
  	digitalWrite(led, LOW);
  }
  
  //print results
  Serial.println("TEMPERATURE:");
  Serial.println(celcius);
  Serial.println("LED:");
  Serial.println(digitalRead(led));
  
  delay(1000);
}