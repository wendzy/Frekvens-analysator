/*
  setup: Input varibler samt dess inkopplade pin värde på arduino

  D1: Läs/ta emot data från MSGEQ7 och spara data i en lista
  -Ge en puls med hjälp av RESET och STROBE som skickas till MSGEQ7
  -Vi matar in värdena i lista 7 index
  [63Hz, 160Hz, 400Hz, 1kHz, 2.5kHz, 6.25kHz, 16kHz]

  D2: Bearbeta datan MSGEQ7 och programmera LED matris
  - Ta värden från listan som kommer att vara mellan 0-1023
  - Dela upp värdet till x beroende på LED matrisen
  -Neopixel för att programmera om den ska vara på eller av

  D# Extra:
  - Lägg in extra funktioner med hjälp av Neopixel
  - Regnbåge
  - Våg
  -
  
*/

#include <Adafruit_NeoPixel.h>

// Which pin on the Arduino is connected to the NeoPixels?
// On a Trinket or Gemma we suggest changing this to 1:
#define LED_PIN    6

// How many NeoPixels are attached to the Arduino?
#define LED_COUNT 7

// Declare our NeoPixel strip object:
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_RGB + NEO_KHZ800);
// Argument 1 = Number of pixels in NeoPixel strip
// Argument 2 = Arduino pin number (most are valid)
// Argument 3 = Pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
//   NEO_RGBW    Pixels are wired for RGBW bitstream (NeoPixel RGBW products)

int Reset = 13;
int Strobe = 12;
int AnalogPin = A0;
int Freq_val[7] = {63, 160, 400, 1000, 2500, 6250, 16000};
int Freq_val1;
//int RGB = ;
int LED = 6;

void setup()
{
  Serial.begin(9600); //open serial port
  
  //define port
  pinMode(Reset,OUTPUT);
  pinMode(Strobe,OUTPUT);
  pinMode(AnalogPin,INPUT);
  pinMode(LED, OUTPUT);
  
  //Skapa tillstånd för pin
digitalWrite(Reset, LOW);
digitalWrite(Strobe, HIGH);
delayMicroseconds(72);
  
}

//void button()
//{
  
  //int knapp = digitalRead();
  
  
  //while( knapp = 1 && knapp = 0 )
  //{
    
  //}
//}

void loop(){
  
  int i;
    
  strip.begin(); 
  
  
   //Reset OP-AMP;
  digitalWrite(Reset, HIGH);
  digitalWrite(Reset, LOW);
  delayMicroseconds(72);

  for ( i = 0; i < 7; i++) {
 
    digitalWrite(Strobe, LOW);
    delayMicroseconds(36);
  
    Freq_val[i] = analogRead(AnalogPin);
  
  
    if (Freq_val[i] < 45) Freq_val[i] = 0; // remove low-level noise
    
  //Serial.print(Freq_val[i]);
  //Serial.print("  ");
  
    Freq_val1 =((Freq_val[i])/(350/7));
    Serial.print(Freq_val1);
    Serial.print("  ");
    digitalWrite(Strobe, HIGH);
    delayMicroseconds(36);

}


 for ( i = 0; i < Freq_val1; i++) {
 
 strip.setPixelColor(i, 51, 0, 51);
 strip.show();
 delay(1);
    
  }
  
  Serial.println();
}
//for ( i = 0; i < 7; i++) {
 
//  digitalWrite(Strobe, LOW);
  //delayMicroseconds(72);
  
  //val[i] = analogRead(Analogpin);
  //Serial.println(val[i]);
  
 //analogRead(Analogpin) = 
  
  
 // digitalWrite(Strobe, HIGH);
 // delayMicroseconds(72);
  
