/*==========================================================
                DAC Demonstration Program
============================================================
Description:
  This program demonstrates the conversion of a discrete digital
  signal into a continuous analog signal, wherein the discrete
  signal is converted from binary logic to its sinusoidal voltage
  wave form. The discrete digital signal is converted by utilizing
  the DAC GPIO pin, GPIO25. The provided input signal is produced
  with the use of a potentiometer.

Programmer:
  Hans Noe D. Baldomer

Date:
  14 Oct 2026
*/

// GPIO Pins
const byte POTENTIO_PIN = 36;
const byte DAC_PIN = 25;

// Variables
int adc_value = 0;        // Stores 3102
float voltage_input = 0;  // Stores the voltage input of 2.5

void setup() {
  // ADC Pin
  pinMode(POTENTIO_PIN, INPUT);
  analogReadResolution(8);    // 8-bit

  // DAC Pin
  pinMode(DAC_PIN, OUTPUT);

  Serial.begin(9600);   // Baud Rate Bit-Per-Second
}

void loop() {
  // 8-Bit ADC Numerical Value
  adc_value = analogRead(POTENTIO_PIN);
  Serial.printf("ADC Numeric Value: %d \n", adc_value);
  delay(500);

  // Converts 8-Bit ADC to actual voltage
  // For monitoring only
  voltage_input = (adc_value/255.0)*3.3;
  Serial.printf("Input Voltage Value: %.2f \n", voltage_input);
  delay(500);

  // Use a multimeter to verify the actual voltage
  dacWrite(DAC_PIN, adc_value);
}
