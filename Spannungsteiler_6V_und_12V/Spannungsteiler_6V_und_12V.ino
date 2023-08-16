#include <MCP3008.h>

//define pin connections
#define CS_PIN D8
#define CLOCK_PIN D5
#define MOSI_PIN D7
#define MISO_PIN D6

MCP3008 adc(CLOCK_PIN, MOSI_PIN, MISO_PIN, CS_PIN);

void setup() 
{
 // open serial port
 Serial.begin(115200); 
}

void loop() 
{

  // MAX 13,45 V
  // Spannungteiler Vin -> R1 1200 Ohm -> Messpunkt -> R2 390 Ohm -> Gnd 
  // 3,3 V bei 13,45 V 
  // 1 Bit => 13,45 / 1023 => 0,0131476
  float val = adc.readADC(0); // read Channel 0 from MCP3008 ADC (pin 1)
  Serial.print("Channel 0: ");
  Serial.println(val * 0.0131476);

  // MAX 6V 
  // Spannungteiler Vin -> R1 2700 Ohm -> Messpunkt -> R2 3300 Ohm -> Gnd 
  // 3,3 V bei 6 V  
  // 1 Bit => 13,45 / 1023 => 0,0131476
  val = adc.readADC(1); // read Channel 0 from MCP3008 ADC (pin 2)
  Serial.print("Channel 1: ");
  Serial.println(val * 0.0058651);

  Serial.println();
  delay(1000); 

}