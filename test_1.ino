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

int Reset = 13;
int Strobe = 12;
int AnalogPin = A0;
int val[7];

void setupRGB()
{
  strip.begin();
  strip.show();
  strip.setPixelColor(n, red, green, blue);
  
  //n = antal pixel 
}

void setup()
{
  Serial.begin(9600); //open serial port
  
  //define port
  pinMode(Reset,OUTPUT);
  pinMode(Strobe,OUTPUT);
  pinMode(A0,INPUT);
  
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

void button()
{

}

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

