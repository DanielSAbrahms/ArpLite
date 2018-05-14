//http://embed.plnkr.co/3VUsekP3jC5xwSIQDVHx/preview


#define ROW_1 2
#define ROW_2 3
#define ROW_3 4
#define ROW_4 5
#define ROW_5 6
#define ROW_6 7
#define ROW_7 8
#define ROW_8 9

#define COL_1 10
#define COL_2 11
#define COL_3 12
#define COL_4 13
#define COL_5 A0
#define COL_6 A1
#define COL_7 A2
#define COL_8 A3

#define ROW_DIM 25
#define COL_DIM 8

int bpm = 100;
int beats = 0;
float timeCount = 0;
byte array[ROW_DIM][COL_DIM] = {
{B10010000, B00000010, B00100000, B00000000, B00000000, B11111111, B00000000, B00000000},
{B00100100, B10000000, B00001000, B00000000, B10000000, B11111111, B00000000, B00000000},
{B00001001, B00100000, B00000010, B00000000, B01100000, B11111111, B00000000, B00000000},
{B00000010, B00001000, B10000000, B10000000, B00011000, B11111111, B00000000, B00000000},
{B10000000, B00000010, B11100000, B11100000, B11000110, B11111111, B00000000, B00000000},
{B00100000, B00000000, B01111000, B01111000, B00110001, B11111111, B00000000, B00000000},
{B00001000, B11000000, B11011110, B11011110, B11001100, B11111111, B10000000, B01000000},
{B00110000, B00110111, B01110111, B11110011, B00110011, B11111111, B11111111, B00011000},
{B00001101, B00011101, B11111101, B10011100, B10011100, B11111111, B11111111, B00000011},
{B10000011, B10000111, B10111111, B10100111, B11100111, B11111111, B11111111, B11111111},
{B11000011, B11111111, B11000011, B11000011, B11000011, B11000011, B11111111, B11111111},
{B11111111, B10000001, B10000001, B10000001, B10000001, B10000001, B10000001, B11111111},
{B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000},
{B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000},
{B00000000, B00000000, B00000000, B00011000, B00011000, B00000000, B00000000, B00000000},
{B00000000, B00000000, B00111100, B00111100, B00111100, B00000000, B00000000, B00000000},
{B00000000, B00000000, B00100100, B01011010, B01011010, B00100100, B00000000, B00000000},
{B00000000, B00000000, B01100110, B10011001, B10011001, B01100110, B00000000, B00000000},
{B00000000, B00000000, B01100110, B10011001, B10011001, B01100110, B00000000, B00000000},
{B11111111, B11111111, B10011001, B01100110, B01100110, B10011001, B11111111, B11111111},
{B00000000, B00000000, B01100110, B10011001, B10011001, B01100110, B00000000, B00000000},
{B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000},
{B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000},
{B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000}
};


const byte rows[] = {
    ROW_1, ROW_2, ROW_3, ROW_4, ROW_5, ROW_6, ROW_7, ROW_8
};


void  drawScreen(byte buffer2[]){
     
    
   // Turn on each row in series
    for (byte i = 0; i < 8; i++) {
        setColumns(buffer2[i], false); // Set columns for this specific row
        
        digitalWrite(rows[i], HIGH);
        delay(2); // Set this to 50 or 100 if you want to see the multiplexing effect!
        digitalWrite(rows[i], LOW);
        
    }
}


void setColumns(byte b, bool invert) {
  if (!invert) {
    digitalWrite(COL_1, (~b >> 0) & 0x01); // Get the 1st bit: 10000000
    digitalWrite(COL_2, (~b >> 1) & 0x01); // Get the 2nd bit: 01000000
    digitalWrite(COL_3, (~b >> 2) & 0x01); // Get the 3rd bit: 00100000
    digitalWrite(COL_4, (~b >> 3) & 0x01); // Get the 4th bit: 00010000
    digitalWrite(COL_5, (~b >> 4) & 0x01); // Get the 5th bit: 00001000
    digitalWrite(COL_6, (~b >> 5) & 0x01); // Get the 6th bit: 00000100
    digitalWrite(COL_7, (~b >> 6) & 0x01); // Get the 7th bit: 00000010
    digitalWrite(COL_8, (~b >> 7) & 0x01); // Get the 8th bit: 00000001
  } else {
    digitalWrite(COL_1, (b >> 0) & 0x01); // Get the 1st bit: 10000000
    digitalWrite(COL_2, (b >> 1) & 0x01); // Get the 2nd bit: 01000000
    digitalWrite(COL_3, (b >> 2) & 0x01); // Get the 3rd bit: 00100000
    digitalWrite(COL_4, (b >> 3) & 0x01); // Get the 4th bit: 00010000
    digitalWrite(COL_5, (b >> 4) & 0x01); // Get the 5th bit: 00001000
    digitalWrite(COL_6, (b >> 5) & 0x01); // Get the 6th bit: 00000100
    digitalWrite(COL_7, (b >> 6) & 0x01); // Get the 7th bit: 00000010
    digitalWrite(COL_8, (b >> 7) & 0x01); // Get the 8th bit: 00000001
    // If the polarity of your matrix is the opposite of mine
    // remove all the '~' above.
  }
}


void setup() {
    // Open serial port
    Serial.begin(9600);
    
    // Set all used pins to OUTPUT
    // This is very important! If the pins are set to input
    // the display will be very dim.
    for (byte i = 2; i <= 13; i++)
        pinMode(i, OUTPUT);
    pinMode(A0, OUTPUT);
    pinMode(A1, OUTPUT);
    pinMode(A2, OUTPUT);
    pinMode(A3, OUTPUT);
    Serial.begin(9600);


  
}

void loop() {
  // This could be rewritten to not use a delay, which would make it appear brighter
timeCount++;
if (timeCount >= 30) {
  beats++;
  timeCount=0;
}
if (beats >= ROW_DIM) beats=0;
byte* d =  {array[beats]};
drawScreen(d);
delay(5);



}


  



