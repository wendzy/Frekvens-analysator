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
int Reset = 13;
int Strobe = 12;
int AnalogPin = A0;
int val[7];


void setup()
{
  Serial.begin(9600); //open serial port
  pinMode(13,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(A0,INPUT);
  
digitalRead(13, LOW);
delayMicroseconds(72);
digitalRead(13, HIGH);
delayMicroseconds(72);
digitalRead(13, LOW);
  
digitalRead(12, LOW);
delayMicroseconds(72);
digitalRead(12, HIGH);
delayMicroseconds(72);

}


void loop()
{




int i;
for ( i = 0; i < 7; i++) {
 
  
  val[i] = analogRead(AnalogPin);
  Serial.println(val[i]);
  
  }
}
