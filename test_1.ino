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
#define LED_PIN    

// How many NeoPixels are attached to the Arduino?
#define LED_COUNT 10

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
//int RGB = ;
int val[7];

void setupRGB()
{
  strip.begin();
  strip.show();
  strip.setPixelColor(9, red, green, blue);
  
  //n = antal pixel 
}

void setup()
{
  Serial.begin(9600); //open serial port
  
  //define port
  pinMode(Reset,OUTPUT);
  pinMode(Strobe,OUTPUT);
  pinMode(AnalogPin,INPUT);
  pinMode(RGB, INPUT);
  
  //Skapa tillstånd för pin
digitalWrite(Reset, LOW);
delayMicroseconds(72);
digitalWrite(Strobe, LOW);
delayMicroseconds(72);
  
 //Reset OP-AMP
digitalWrite(Reset, LOW);
delayMicroseconds(72);
digitalWrite(Reset, HIGH);
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

void loop()
{

for ( int i = 0; i < 7; i++) {
 
  digitalWrite(Strobe, LOW);
  delayMicroseconds(72);
  
  val[i] = analogRead(Analogpin);
  Serial.println(val[i]);
  
 digitalWrite(Strobe, HIGH);
 delayMicroseconds(72);
  
  }
}

