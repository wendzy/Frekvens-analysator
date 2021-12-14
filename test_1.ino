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
//#define LED_PIN    6

// How many NeoPixels are attached to the Arduino?
#define LED_COUNT 8

// Declare our NeoPixel strip object:

Adafruit_NeoPixel strip(LED_COUNT, 2, NEO_RGB + NEO_KHZ800);
Adafruit_NeoPixel strip1(LED_COUNT, 3, NEO_RGB + NEO_KHZ800);
Adafruit_NeoPixel strip2(LED_COUNT, 4, NEO_RGB + NEO_KHZ800);
Adafruit_NeoPixel strip3(LED_COUNT, 5, NEO_RGB + NEO_KHZ800);
Adafruit_NeoPixel strip4(LED_COUNT, 6, NEO_RGB + NEO_KHZ800);
Adafruit_NeoPixel strip5(LED_COUNT, 7, NEO_RGB + NEO_KHZ800);
Adafruit_NeoPixel strip6(LED_COUNT, 8, NEO_RGB + NEO_KHZ800);

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


void setup()
{
  Serial.begin(9600); //open serial port
  
  //define port
  pinMode(Reset,OUTPUT);
  pinMode(Strobe,OUTPUT);
  pinMode(AnalogPin,INPUT);
  for (int i = 2; i < 8; i++)
  {
  pinMode(i, OUTPUT);
  }
  
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
  strip1.begin();
  strip2.begin();
  strip3.begin();
  strip4.begin();
  strip5.begin();
  strip6.begin();

  
   //Reset OP-AMP;
  digitalWrite(Reset, HIGH);
  digitalWrite(Reset, LOW);
  delayMicroseconds(72);

  for ( i = 0; i < 7; i++) {
 
    digitalWrite(Strobe, LOW);
    delayMicroseconds(3600);
  
    Freq_val[i] = analogRead(AnalogPin);
  
  
    if (Freq_val[i] < 55)
    {
      
      Freq_val[i] = 0; // remove low-level noise
      
    }

  
    Freq_val[i] =((Freq_val[i]*2)/128);
    Serial.print(Freq_val[i]);
    //Serial.print(Freq_val2);
    Serial.print("  ");
    digitalWrite(Strobe, HIGH);
    delayMicroseconds(36);
    
}
  strip.clear();
  strip1.clear();
  strip2.clear();
  strip3.clear();
  strip4.clear();
  strip5.clear();
  strip6.clear();

 for ( i = 0; i < Freq_val[0]; i++) {
 strip.setPixelColor(i, 0, 50, 50);
 strip.show();
 delay(1);
    
  }

 for ( i = 0; i < Freq_val[1]; i++) {
 strip1.setPixelColor(i, 0, 20, 20);
 strip1.show();
 delay(1);
    
  }

 for ( i = 0; i < Freq_val[2]; i++) {
 strip2.setPixelColor(i, 0, 50, 50);
 strip2.show();
 delay(1);
    
  }

 for ( i = 0; i < Freq_val[3]; i++) {
 strip3.setPixelColor(i, 0, 30+25*i, 50-5*i);
 strip3.show();
 delay(1);
    
  }


 for ( i = 0; i < Freq_val[4]; i++) {
 strip4.setPixelColor(i, 40*i, 50-10*i, 50-10*i);
 strip4.show();
 delay(1);
    
  }

 for ( i = 0; i < Freq_val[5]; i++) {
 strip5.setPixelColor(i, 0, 50, 50);
 strip5.show();
 delay(1);
    
  }

 for ( i = 0; i < Freq_val[6]; i++) {
 strip6.setPixelColor(i, 0, 50, 50);
 strip6.show();
 delay(1);
    
  }
  Serial.println();
  delay(50);
}
//for ( i = 0; i < 7; i++) {
 
//  digitalWrite(Strobe, LOW);
  //delayMicroseconds(72);
  
  //val[i] = analogRead(Analogpin);
  //Serial.println(val[i]);
  
 //analogRead(Analogpin) = 
  
  
 // digitalWrite(Strobe, HIGH);
 // delayMicroseconds(72);
  
