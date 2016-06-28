const int GSR = A2;
int threshold = 0;
int sensorValue;
int resistance_voltage;
int conductance_voltage;
int conductanceMS;

void setup() {
  long sum = 0; //extended size variable for number storage
  Serial.begin(9600); //setting baud rate

  for (int i = 0; i < 500; i++) //for loop that adds the sensorValue to sum 500 times
  {
    sensorValue = analogRead(GSR);
    sum += sensorValue;
    delay(5);
  }
  float threshold = 3.32 - (sum / 500 * (5.0 / 1023.0)); //average conductance threshold calculated by subtracting max value by sum divided by 500 multiplied by the converted analog to voltage value
  float thresholdMS = threshold * 1000000; //average threshold in micro-Siemens calculated by multipling threshold above by micro-Siemen conversion rate
  Serial.print("threshold = ");
  Serial.println(threshold);
  Serial.print('\n'); //carriage return for easier display
  Serial.print("thresholdMS = ");
  Serial.println(thresholdMS);
}

void loop() {
  int temp; //establishing temp variable
  sensorValue = analogRead(GSR); //reading analog sensor value
  float resistance_voltage = sensorValue * (5.0 / 1023.0); //conversion arduino analog range to voltage
  Serial.print('\n'); //carriage return for easier display
  Serial.print("resistance_voltage = ");
  Serial.print(resistance_voltage);
  Serial.print('\n'); //carriage return for easier display
  float resistanceMS = resistance_voltage * 1000000; //converting resistance to micro-Siemens
  Serial.print("resistanceMS = ");
  Serial.print(resistanceMS);
  Serial.print('\n'); //carriage return for easier display
  Serial.print('\n'); //carriage return for easier display
  float conductance_voltage = 3.32 - resistance_voltage; //subtract the max voltage value from the measured loss to get the amount of electrcity being conducted. Inverting the value so it reads conductance as opposed to resistance.
  Serial.print("conductance_voltage = ");
  Serial.print(conductance_voltage); //print the conductance value to serial
  Serial.print('\n'); //carriage return for easier display
  float conductanceMS = conductance_voltage * 1000000; //conversion to micro-Siemens (measure of electric conductance)
  Serial.print("conductanceMS = ");//***this is the value you need to refer to for GSR mapping***
  Serial.print(conductanceMS); //serial printing conductance in micro-Siemens
  Serial.print('\n'); //carriage return for easier display
  delay(1000); //delay serial prints by 1 second
}
