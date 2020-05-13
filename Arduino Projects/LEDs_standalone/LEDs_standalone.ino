#include <Adafruit_NeoPixel.h>                     // Include Adafruit NeoPixel library
const int A01L_PIN = 0;                            // Digital output PIN the LED strip is connected to
const int A01R_PIN = 1;                            // Digital output PIN the LED strip is connected to 
const int A02L_PIN = 2;                            // Digital output PIN the LED strip is connected to 
const int A02R_PIN = 3;                            // Digital output PIN the LED strip is connected to 
const int A03L_PIN = 4;                            // Digital output PIN the LED strip is connected to 
const int A03R_PIN = 5;                            // Digital output PIN the LED strip is connected to 
const int A04L_PIN = 6;                            // Digital output PIN the LED strip is connected to 
const int A04R_PIN = 7;                            // Digital output PIN the LED strip is connected to 
const int A05L_PIN = 8;                            // Digital output PIN the LED strip is connected to 
const int A05R_PIN = 9;                            // Digital output PIN the LED strip is connected to 
const int A06L_PIN = 10;                            // Digital output PIN the LED strip is connected to 
const int A06R_PIN = 11;                            // Digital output PIN the LED strip is connected to 

const int A01L_LEDS = 6;                           // Amount of LEDs in LED Strip
const int A01R_LEDS = 6;                           // Amount of LEDs in LED Strip
const int A02L_LEDS = 6;                           // Amount of LEDs in LED Strip
const int A02R_LEDS = 6;                           // Amount of LEDs in LED Strip
const int A03L_LEDS = 6;                           // Amount of LEDs in LED Strip
const int A03R_LEDS = 6;                           // Amount of LEDs in LED Strip
const int A04L_LEDS = 6;                           // Amount of LEDs in LED Strip
const int A04R_LEDS = 6;                           // Amount of LEDs in LED Strip
const int A05L_LEDS = 6;                           // Amount of LEDs in LED Strip
const int A05R_LEDS = 6;                           // Amount of LEDs in LED Strip
const int A06L_LEDS = 6;                           // Amount of LEDs in LED Strip
const int A06R_LEDS = 7;                           // Amount of LEDs in LED Strip

const int MAX_LEDS = 6;                             // Max LEDs in any strip

// Create objects to drive LEDs
Adafruit_NeoPixel A01L = Adafruit_NeoPixel(A01L_LEDS, A01L_PIN, NEO_RGBW + NEO_KHZ800);
Adafruit_NeoPixel A01R = Adafruit_NeoPixel(A01R_LEDS, A01R_PIN, NEO_RGBW + NEO_KHZ800);
Adafruit_NeoPixel A02L = Adafruit_NeoPixel(A02L_LEDS, A02L_PIN, NEO_RGBW + NEO_KHZ800);
Adafruit_NeoPixel A02R = Adafruit_NeoPixel(A02R_LEDS, A02R_PIN, NEO_RGBW + NEO_KHZ800);
Adafruit_NeoPixel A03L = Adafruit_NeoPixel(A03L_LEDS, A03L_PIN, NEO_RGBW + NEO_KHZ800);
Adafruit_NeoPixel A03R = Adafruit_NeoPixel(A03R_LEDS, A03R_PIN, NEO_RGBW + NEO_KHZ800);
Adafruit_NeoPixel A04L = Adafruit_NeoPixel(A04L_LEDS, A04L_PIN, NEO_RGBW + NEO_KHZ800);
Adafruit_NeoPixel A04R = Adafruit_NeoPixel(A04R_LEDS, A04R_PIN, NEO_RGBW + NEO_KHZ800);
Adafruit_NeoPixel A05L = Adafruit_NeoPixel(A05L_LEDS, A05L_PIN, NEO_RGBW + NEO_KHZ800);
Adafruit_NeoPixel A05R = Adafruit_NeoPixel(A05R_LEDS, A05R_PIN, NEO_RGBW + NEO_KHZ800);
Adafruit_NeoPixel A06L = Adafruit_NeoPixel(A06L_LEDS, A06L_PIN, NEO_RGBW + NEO_KHZ800);
Adafruit_NeoPixel A06R = Adafruit_NeoPixel(A06R_LEDS, A06R_PIN, NEO_RGBW + NEO_KHZ800);

int wait = 5;                                      // Standard wait delay used throughout demos 




void setup() 
{
  A01L.begin();                                     // Initialize object
  A01R.begin();                                     // Initialize object
  A02L.begin();                                     // Initialize object
  A02R.begin();                                     // Initialize object
  A03L.begin();                                     // Initialize object
  A03R.begin();                                     // Initialize object
  A04L.begin();                                     // Initialize object
  A04R.begin();                                     // Initialize object
  A05L.begin();                                     // Initialize object
  A05R.begin();                                     // Initialize object
  A06L.begin();                                     // Initialize object
  A06R.begin();                                     // Initialize object
   
  ALL_LEDS_OFF();
}


void loop() 
{
  CYCLE_ALL_COLORS();                               // This function cycles all LEDs at the same time through the main colors (Green, Red, Blue, White)
  ALL_LEDS_OFF();
  TERMINAL_SERVERS();                               // This function shows the location of the Termianl Servers
  ALL_LEDS_OFF();
  SYSLOG();                                         // This function simulates the integration of syslogs where a new syslog creates an error in red, fading into yellow and turning back to green eventually
  ALL_LEDS_OFF();
  RAINBOW();                                        // This function looks pretty
  ALL_LEDS_OFF();
}
  

void SHOW_ALL_LEDS()
{
  A01L.show();                                      // Push new values
  A01R.show();                                      // Push new values
  A02L.show();                                      // Push new values
  A02R.show();                                      // Push new values
  A03L.show();                                      // Push new values
  A03R.show();                                      // Push new values
  A04L.show();                                      // Push new values
  A04R.show();                                      // Push new values
  A05L.show();                                      // Push new values
  A05R.show();                                      // Push new values
  A06L.show();                                      // Push new values
  A06R.show();                                      // Push new values
}

void ALL_LEDS_OFF()
{


  for(int i=0; i<MAX_LEDS; i++) 
  {            
    A01L.setPixelColor(i, A01L.Color(0, 0, 0, 0));  // Switch off all LEDs
    A01R.setPixelColor(i, A01R.Color(0, 0, 0, 0));  // Switch off all LEDs          
    A02L.setPixelColor(i, A02L.Color(0, 0, 0, 0));  // Switch off all LEDs          
    A02R.setPixelColor(i, A02R.Color(0, 0, 0, 0));  // Switch off all LEDs
    A03L.setPixelColor(i, A03L.Color(0, 0, 0, 0));  // Switch off all LEDs
    A03R.setPixelColor(i, A03R.Color(0, 0, 0, 0));  // Switch off all LEDs
    A04L.setPixelColor(i, A04L.Color(0, 0, 0, 0));  // Switch off all LEDs
    A04R.setPixelColor(i, A04R.Color(0, 0, 0, 0));  // Switch off all LEDs
    A05L.setPixelColor(i, A05L.Color(0, 0, 0, 0));  // Switch off all LEDs
    A05R.setPixelColor(i, A05R.Color(0, 0, 0, 0));  // Switch off all LEDs
    A06L.setPixelColor(i, A06L.Color(0, 0, 0, 0));  // Switch off all LEDs
    A06R.setPixelColor(i, A06R.Color(0, 0, 0, 0));  // Switch off all LEDs
  }
  
  SHOW_ALL_LEDS();
  
  delay(2000); 
}

void CYCLE_ALL_COLORS()
{
  for(int GREEN=0; GREEN<255; GREEN++)                          // First for loop cycles through the color brightness
  {
      for(int LED_NUMBER=0; LED_NUMBER<MAX_LEDS; LED_NUMBER++) // Second for loop cycles through the LEDs in the strip and updates the color brightness per LED
      {
        A01L.setPixelColor(LED_NUMBER, A01L.Color(GREEN, 0, 0, 0)); 
        A01R.setPixelColor(LED_NUMBER, A01R.Color(GREEN, 0, 0, 0)); 
        A02L.setPixelColor(LED_NUMBER, A02L.Color(GREEN, 0, 0, 0)); 
        A02R.setPixelColor(LED_NUMBER, A02R.Color(GREEN, 0, 0, 0)); 
        A03L.setPixelColor(LED_NUMBER, A03L.Color(GREEN, 0, 0, 0)); 
        A03R.setPixelColor(LED_NUMBER, A03R.Color(GREEN, 0, 0, 0)); 
        A04L.setPixelColor(LED_NUMBER, A04L.Color(GREEN, 0, 0, 0)); 
        A04R.setPixelColor(LED_NUMBER, A04R.Color(GREEN, 0, 0, 0)); 
        A05L.setPixelColor(LED_NUMBER, A05L.Color(GREEN, 0, 0, 0)); 
        A05R.setPixelColor(LED_NUMBER, A05R.Color(GREEN, 0, 0, 0)); 
        A06L.setPixelColor(LED_NUMBER, A06L.Color(GREEN, 0, 0, 0)); 
        A06R.setPixelColor(LED_NUMBER, A06R.Color(GREEN, 0, 0, 0)); 


      }
      SHOW_ALL_LEDS();
      delay(wait);                        // Delay for visual effect
  }
  
  for(int RED=0; RED<255; RED++) 
  {
      for(int LED_NUMBER=0; LED_NUMBER<MAX_LEDS; LED_NUMBER++) // Second for loop cycles through the LEDs in the strip and updates the color brightness per LED
      {
        A01L.setPixelColor(LED_NUMBER, A01L.Color(0, RED, 0, 0));
        A01R.setPixelColor(LED_NUMBER, A01R.Color(0, RED, 0, 0)); 
        A02L.setPixelColor(LED_NUMBER, A02L.Color(0, RED, 0, 0)); 
        A02R.setPixelColor(LED_NUMBER, A02R.Color(0, RED, 0, 0));
        A03L.setPixelColor(LED_NUMBER, A03L.Color(0, RED, 0, 0));
        A03R.setPixelColor(LED_NUMBER, A03R.Color(0, RED, 0, 0));
        A04L.setPixelColor(LED_NUMBER, A04L.Color(0, RED, 0, 0));
        A04R.setPixelColor(LED_NUMBER, A04R.Color(0, RED, 0, 0));
        A05L.setPixelColor(LED_NUMBER, A05L.Color(0, RED, 0, 0));
        A05R.setPixelColor(LED_NUMBER, A05R.Color(0, RED, 0, 0));
        A06L.setPixelColor(LED_NUMBER, A06L.Color(0, RED, 0, 0));
        A06R.setPixelColor(LED_NUMBER, A06R.Color(0, RED, 0, 0));
      }
      SHOW_ALL_LEDS();
      delay(wait); 
  }
  for(int BLUE=0; BLUE<255; BLUE++) 
  {
      for(int LED_NUMBER=0; LED_NUMBER<MAX_LEDS; LED_NUMBER++) // Second for loop cycles through the LEDs in the strip and updates the color brightness per LED
      {
        A01L.setPixelColor(LED_NUMBER, A01L.Color(0, 0, BLUE, 0));
        A01R.setPixelColor(LED_NUMBER, A01R.Color(0, 0, BLUE, 0));
        A02L.setPixelColor(LED_NUMBER, A02L.Color(0, 0, BLUE, 0));
        A02R.setPixelColor(LED_NUMBER, A02R.Color(0, 0, BLUE, 0));
        A03L.setPixelColor(LED_NUMBER, A03L.Color(0, 0, BLUE, 0));
        A03R.setPixelColor(LED_NUMBER, A03R.Color(0, 0, BLUE, 0));
        A04L.setPixelColor(LED_NUMBER, A04L.Color(0, 0, BLUE, 0));
        A04R.setPixelColor(LED_NUMBER, A04R.Color(0, 0, BLUE, 0));
        A05L.setPixelColor(LED_NUMBER, A05L.Color(0, 0, BLUE, 0));
        A05R.setPixelColor(LED_NUMBER, A05R.Color(0, 0, BLUE, 0));
        A06L.setPixelColor(LED_NUMBER, A06L.Color(0, 0, BLUE, 0));
        A06R.setPixelColor(LED_NUMBER, A06R.Color(0, 0, BLUE, 0));
      }
      SHOW_ALL_LEDS();
      delay(wait);
  }
  for(int WHITE=0; WHITE<255; WHITE++) 
  {
      for(int LED_NUMBER=0; LED_NUMBER<MAX_LEDS; LED_NUMBER++) // Second for loop cycles through the LEDs in the strip and updates the color brightness per LED
      {
        A01L.setPixelColor(LED_NUMBER, A01L.Color(0, 0, 0, WHITE)); 
        A01R.setPixelColor(LED_NUMBER, A01R.Color(0, 0, 0, WHITE));
        A02L.setPixelColor(LED_NUMBER, A02L.Color(0, 0, 0, WHITE));
        A02R.setPixelColor(LED_NUMBER, A02R.Color(0, 0, 0, WHITE));
        A03L.setPixelColor(LED_NUMBER, A03L.Color(0, 0, 0, WHITE));
        A03R.setPixelColor(LED_NUMBER, A03R.Color(0, 0, 0, WHITE));
        A04L.setPixelColor(LED_NUMBER, A04L.Color(0, 0, 0, WHITE));
        A04R.setPixelColor(LED_NUMBER, A04R.Color(0, 0, 0, WHITE));
        A05L.setPixelColor(LED_NUMBER, A05L.Color(0, 0, 0, WHITE));
        A05R.setPixelColor(LED_NUMBER, A05R.Color(0, 0, 0, WHITE));
        A06L.setPixelColor(LED_NUMBER, A06L.Color(0, 0, 0, WHITE));
        A06R.setPixelColor(LED_NUMBER, A06R.Color(0, 0, 0, WHITE));
      }
      SHOW_ALL_LEDS();
      delay(wait);
  }
}

void TERMINAL_SERVERS()
{
                                                             // First we set all LEDs to green
   for(int LED_NUMBER=0; LED_NUMBER<MAX_LEDS; LED_NUMBER++) // cycles through the LEDs in the strip and updates the color brightness per LED
   {
     A01L.setPixelColor(LED_NUMBER, A01L.Color(255, 0, 0, 0)); 
     A01R.setPixelColor(LED_NUMBER, A01R.Color(255, 0, 0, 0)); 
     A02L.setPixelColor(LED_NUMBER, A02L.Color(255, 0, 0, 0)); 
     A02R.setPixelColor(LED_NUMBER, A02R.Color(255, 0, 0, 0)); 
     A03L.setPixelColor(LED_NUMBER, A03L.Color(255, 0, 0, 0)); 
     A03R.setPixelColor(LED_NUMBER, A03R.Color(255, 0, 0, 0)); 
     A04L.setPixelColor(LED_NUMBER, A04L.Color(255, 0, 0, 0)); 
     A04R.setPixelColor(LED_NUMBER, A04R.Color(255, 0, 0, 0)); 
     A05L.setPixelColor(LED_NUMBER, A05L.Color(255, 0, 0, 0)); 
     A05R.setPixelColor(LED_NUMBER, A05R.Color(255, 0, 0, 0)); 
     A06L.setPixelColor(LED_NUMBER, A06L.Color(255, 0, 0, 0)); 
     A06R.setPixelColor(LED_NUMBER, A06R.Color(255, 0, 0, 0)); 

   }
   SHOW_ALL_LEDS();


   delay(wait);                       
   
   for(int BLINK=0; BLINK<10; BLINK++) // Show the Terminal Server LED 10 times
   {
    A01L.setPixelColor(A01L_LEDS-2, A01L.Color(0, 255, 0, 0));
    A01L.setPixelColor(A01L_LEDS-3, A01L.Color(0, 255, 0, 0));
    A01R.setPixelColor(A01R_LEDS-2, A01R.Color(0, 255, 0, 0));
    A01R.setPixelColor(A01R_LEDS-3, A01R.Color(0, 255, 0, 0));
    A02L.setPixelColor(A02L_LEDS-2, A02L.Color(0, 255, 0, 0));
    A02L.setPixelColor(A02L_LEDS-3, A02L.Color(0, 255, 0, 0));
    A02R.setPixelColor(A02R_LEDS-2, A02R.Color(0, 255, 0, 0));
    A02R.setPixelColor(A02R_LEDS-3, A02R.Color(0, 255, 0, 0));
    A03L.setPixelColor(A03L_LEDS-2, A03L.Color(0, 255, 0, 0));
    A03L.setPixelColor(A03L_LEDS-3, A03L.Color(0, 255, 0, 0));
    A03R.setPixelColor(A03R_LEDS-2, A03R.Color(0, 255, 0, 0));
    A03R.setPixelColor(A03R_LEDS-3, A03R.Color(0, 255, 0, 0));
    A04L.setPixelColor(A04L_LEDS-2, A04L.Color(0, 255, 0, 0));
    A04L.setPixelColor(A04L_LEDS-3, A04L.Color(0, 255, 0, 0));
    A04R.setPixelColor(A04R_LEDS-2, A04R.Color(0, 255, 0, 0));
    A04R.setPixelColor(A04R_LEDS-3, A04R.Color(0, 255, 0, 0));
    A05L.setPixelColor(A05L_LEDS-2, A05L.Color(0, 255, 0, 0));
    A05L.setPixelColor(A05L_LEDS-3, A05L.Color(0, 255, 0, 0));
    A05R.setPixelColor(A05R_LEDS-2, A05R.Color(0, 255, 0, 0));
    A05R.setPixelColor(A05R_LEDS-3, A05R.Color(0, 255, 0, 0));    
    A06L.setPixelColor(A06L_LEDS-2, A06L.Color(0, 255, 0, 0));
    A06L.setPixelColor(A06L_LEDS-3, A06L.Color(0, 255, 0, 0));
    A06R.setPixelColor(A06R_LEDS-2, A06R.Color(0, 255, 0, 0));
    A06R.setPixelColor(A06R_LEDS-3, A06R.Color(0, 255, 0, 0));


        
    SHOW_ALL_LEDS();                   // Show terminal server LEDs in red
    
    delay(500);                       // Wait
    A01L.setPixelColor(A01L_LEDS-2, A01L.Color(255, 0, 0, 0));
    A01L.setPixelColor(A01L_LEDS-3, A01L.Color(255, 0, 0, 0));
    A01R.setPixelColor(A01R_LEDS-2, A01R.Color(255, 0, 0, 0));
    A01R.setPixelColor(A01R_LEDS-3, A01R.Color(255, 0, 0, 0));
    A02L.setPixelColor(A02L_LEDS-2, A02L.Color(255, 0, 0, 0));
    A02L.setPixelColor(A02L_LEDS-3, A02L.Color(255, 0, 0, 0));
    A02R.setPixelColor(A02R_LEDS-2, A02R.Color(255, 0, 0, 0));
    A02R.setPixelColor(A02R_LEDS-3, A02R.Color(255, 0, 0, 0));
    A03L.setPixelColor(A03L_LEDS-2, A03L.Color(255, 0, 0, 0));
    A03L.setPixelColor(A03L_LEDS-3, A03L.Color(255, 0, 0, 0));
    A03R.setPixelColor(A03R_LEDS-2, A03R.Color(255, 0, 0, 0));
    A03R.setPixelColor(A03R_LEDS-3, A03R.Color(255, 0, 0, 0));
    A04L.setPixelColor(A04L_LEDS-2, A04L.Color(255, 0, 0, 0));
    A04L.setPixelColor(A04L_LEDS-3, A04L.Color(255, 0, 0, 0));
    A04R.setPixelColor(A04R_LEDS-2, A04R.Color(255, 0, 0, 0));
    A04R.setPixelColor(A04R_LEDS-3, A04R.Color(255, 0, 0, 0));
    A05L.setPixelColor(A05L_LEDS-2, A05L.Color(255, 0, 0, 0));
    A05L.setPixelColor(A05L_LEDS-3, A05L.Color(255, 0, 0, 0));
    A05R.setPixelColor(A05R_LEDS-2, A05R.Color(255, 0, 0, 0));
    A05R.setPixelColor(A05R_LEDS-3, A05R.Color(255, 0, 0, 0));
    A06L.setPixelColor(A06L_LEDS-2, A06L.Color(255, 0, 0, 0));
    A06L.setPixelColor(A06L_LEDS-3, A06L.Color(255, 0, 0, 0));
    A06R.setPixelColor(A06R_LEDS-2, A06R.Color(255, 0, 0, 0));
    A06R.setPixelColor(A06R_LEDS-3, A06R.Color(255, 0, 0, 0));
    
    SHOW_ALL_LEDS();                   // Show terminal server LEDs in green

    delay(500);                        // Wait
   }
}


void SYSLOG()
{
                                                             // First we set all LEDs to green
   for(int LED_NUMBER=0; LED_NUMBER<MAX_LEDS; LED_NUMBER++) // cycles through the LEDs in the strip and updates the color brightness per LED
   {
     A01L.setPixelColor(LED_NUMBER, A01L.Color(50, 0, 0, 0)); 
     A01R.setPixelColor(LED_NUMBER, A01R.Color(50, 0, 0, 0)); 
     A02L.setPixelColor(LED_NUMBER, A02L.Color(50, 0, 0, 0)); 
     A02R.setPixelColor(LED_NUMBER, A02R.Color(50, 0, 0, 0)); 
     A03L.setPixelColor(LED_NUMBER, A03L.Color(50, 0, 0, 0)); 
     A03R.setPixelColor(LED_NUMBER, A03R.Color(50, 0, 0, 0)); 
     A04L.setPixelColor(LED_NUMBER, A04L.Color(50, 0, 0, 0)); 
     A04R.setPixelColor(LED_NUMBER, A04R.Color(50, 0, 0, 0)); 
     A05L.setPixelColor(LED_NUMBER, A05L.Color(50, 0, 0, 0)); 
     A05R.setPixelColor(LED_NUMBER, A05R.Color(50, 0, 0, 0)); 
     A06L.setPixelColor(LED_NUMBER, A06L.Color(50, 0, 0, 0)); 
     A06R.setPixelColor(LED_NUMBER, A06R.Color(50, 0, 0, 0)); 
   }
   SHOW_ALL_LEDS();                     // show all colors green

 delay(2000);                       
                                        //create 3 random numbers
   int SYSLOG_A01_1=random(0-A01L_LEDS);
   int SYSLOG_A01_2=random(0-A01L_LEDS);
   while (SYSLOG_A01_1 == SYSLOG_A01_2)
    {
      SYSLOG_A01_2=random(0-A01L_LEDS);
    }
   int SYSLOG_A01_3=random(0-A01L_LEDS);
   while (SYSLOG_A01_3 == SYSLOG_A01_2 || SYSLOG_A01_3 == SYSLOG_A01_1)
    {
      SYSLOG_A01_3=random(0-A01L_LEDS);
    }  
  
  
   int SYSLOG_A02_1=random(0-A02L_LEDS);
   int SYSLOG_A02_2=random(0-A02L_LEDS);
   while (SYSLOG_A02_1 == SYSLOG_A02_2)
    {
      SYSLOG_A02_2=random(0-A02L_LEDS);
    }
   int SYSLOG_A02_3=random(0-A02L_LEDS);
   while (SYSLOG_A02_3 == SYSLOG_A02_2 || SYSLOG_A02_3 == SYSLOG_A02_1)
    {
      SYSLOG_A02_3=random(0-A02L_LEDS);
    }  
  
  
   int SYSLOG_A03_1=random(0-A03L_LEDS);
   int SYSLOG_A03_2=random(0-A03L_LEDS);
   while (SYSLOG_A03_1 == SYSLOG_A03_2)
    {
      SYSLOG_A03_2=random(0-A03L_LEDS);
    }
   int SYSLOG_A03_3=random(0-A03L_LEDS);
   while (SYSLOG_A03_3 == SYSLOG_A03_2 || SYSLOG_A03_3 == SYSLOG_A03_1)
    {
      SYSLOG_A03_3=random(0-A03L_LEDS);
    }  
  
  
   int SYSLOG_A04_1=random(0-A04L_LEDS);
   int SYSLOG_A04_2=random(0-A04L_LEDS);
   while (SYSLOG_A04_1 == SYSLOG_A04_2)
    {
      SYSLOG_A04_2=random(0-A04L_LEDS);
    }
   int SYSLOG_A04_3=random(0-A04L_LEDS);
   while (SYSLOG_A04_3 == SYSLOG_A04_2 || SYSLOG_A04_3 == SYSLOG_A04_1)
    {
      SYSLOG_A04_3=random(0-A04L_LEDS);
    }  
  
  
   int SYSLOG_A05_1=random(0-A05L_LEDS);
   int SYSLOG_A05_2=random(0-A05L_LEDS);
   while (SYSLOG_A05_1 == SYSLOG_A05_2)
    {
      SYSLOG_A05_2=random(0-A05L_LEDS);
    }
   int SYSLOG_A05_3=random(0-A05L_LEDS);
   while (SYSLOG_A05_3 == SYSLOG_A05_2 || SYSLOG_A05_3 == SYSLOG_A05_1)
    {
      SYSLOG_A05_3=random(0-A05L_LEDS);
    }  
  
  
   int SYSLOG_A06_1=random(0-A06L_LEDS);
   int SYSLOG_A06_2=random(0-A06L_LEDS);
   while (SYSLOG_A06_1 == SYSLOG_A06_2)
    {
      SYSLOG_A06_2=random(0-A06L_LEDS);
    }
   int SYSLOG_A06_3=random(0-A06L_LEDS);
   while (SYSLOG_A06_3 == SYSLOG_A06_2 || SYSLOG_A06_3 == SYSLOG_A06_1)
    {
      SYSLOG_A06_3=random(0-A06L_LEDS);
    }  
  
  

   
  A01L.setPixelColor(SYSLOG_A01_1, A01L.Color(0, 255, 0, 0));      // Turn first SYSLOG LED red
  A01R.setPixelColor(SYSLOG_A01_1, A01R.Color(0, 255, 0, 0));      // Turn first SYSLOG LED red
  A02L.setPixelColor(SYSLOG_A02_1, A02L.Color(0, 255, 0, 0));      // Turn first SYSLOG LED red
  A02R.setPixelColor(SYSLOG_A02_1, A02R.Color(0, 255, 0, 0));      // Turn first SYSLOG LED red
  A03L.setPixelColor(SYSLOG_A03_1, A03L.Color(0, 255, 0, 0));      // Turn first SYSLOG LED red
  A03R.setPixelColor(SYSLOG_A03_1, A03R.Color(0, 255, 0, 0));      // Turn first SYSLOG LED red
  A04L.setPixelColor(SYSLOG_A04_1, A04L.Color(0, 255, 0, 0));      // Turn first SYSLOG LED red
  A04R.setPixelColor(SYSLOG_A04_1, A04R.Color(0, 255, 0, 0));      // Turn first SYSLOG LED red
  A05L.setPixelColor(SYSLOG_A05_1, A05L.Color(0, 255, 0, 0));      // Turn first SYSLOG LED red
  A05R.setPixelColor(SYSLOG_A05_1, A05R.Color(0, 255, 0, 0));      // Turn first SYSLOG LED red
  A06L.setPixelColor(SYSLOG_A06_1, A06L.Color(0, 255, 0, 0));      // Turn first SYSLOG LED red
  A06R.setPixelColor(SYSLOG_A06_1, A06R.Color(0, 255, 0, 0));      // Turn first SYSLOG LED red
  SHOW_ALL_LEDS();
  delay(2000);                                                 // Wait 
 
  A01L.setPixelColor(SYSLOG_A01_1, A01L.Color(255, 255, 0, 0));      // Turn first SYSLOG LED orange
  A01R.setPixelColor(SYSLOG_A01_1, A01R.Color(255, 255, 0, 0));      // Turn first SYSLOG LED orange
  A02L.setPixelColor(SYSLOG_A02_1, A02L.Color(255, 255, 0, 0));      // Turn first SYSLOG LED orange
  A02R.setPixelColor(SYSLOG_A02_1, A02R.Color(255, 255, 0, 0));      // Turn first SYSLOG LED orange
  A03L.setPixelColor(SYSLOG_A03_1, A03L.Color(255, 255, 0, 0));      // Turn first SYSLOG LED orange
  A03R.setPixelColor(SYSLOG_A03_1, A03R.Color(255, 255, 0, 0));      // Turn first SYSLOG LED orange
  A04L.setPixelColor(SYSLOG_A04_1, A04L.Color(255, 255, 0, 0));      // Turn first SYSLOG LED orange
  A04R.setPixelColor(SYSLOG_A04_1, A04R.Color(255, 255, 0, 0));      // Turn first SYSLOG LED orange
  A05L.setPixelColor(SYSLOG_A05_1, A05L.Color(255, 255, 0, 0));      // Turn first SYSLOG LED orange
  A05R.setPixelColor(SYSLOG_A05_1, A05R.Color(255, 255, 0, 0));      // Turn first SYSLOG LED orange
  A06L.setPixelColor(SYSLOG_A06_1, A06L.Color(255, 255, 0, 0));      // Turn first SYSLOG LED orange
  A06R.setPixelColor(SYSLOG_A06_1, A06R.Color(255, 255, 0, 0));      // Turn first SYSLOG LED orange
  SHOW_ALL_LEDS();
  delay(2000);                                                 

  A01L.setPixelColor(SYSLOG_A01_2, A01L.Color(0, 255, 0, 0));      // Turn second SYSLOG LED red
  A01R.setPixelColor(SYSLOG_A01_2, A01R.Color(0, 255, 0, 0));      // Turn second SYSLOG LED red
  A02L.setPixelColor(SYSLOG_A02_2, A02L.Color(0, 255, 0, 0));      // Turn second SYSLOG LED red
  A02R.setPixelColor(SYSLOG_A02_2, A02R.Color(0, 255, 0, 0));      // Turn second SYSLOG LED red
  A03L.setPixelColor(SYSLOG_A03_2, A03L.Color(0, 255, 0, 0));      // Turn second SYSLOG LED red
  A03R.setPixelColor(SYSLOG_A03_2, A03R.Color(0, 255, 0, 0));      // Turn second SYSLOG LED red
  A04L.setPixelColor(SYSLOG_A04_2, A04L.Color(0, 255, 0, 0));      // Turn second SYSLOG LED red
  A04R.setPixelColor(SYSLOG_A04_2, A04R.Color(0, 255, 0, 0));      // Turn second SYSLOG LED red
  A05L.setPixelColor(SYSLOG_A05_2, A05L.Color(0, 255, 0, 0));      // Turn second SYSLOG LED red
  A05R.setPixelColor(SYSLOG_A05_2, A05R.Color(0, 255, 0, 0));      // Turn second SYSLOG LED red
  A06L.setPixelColor(SYSLOG_A06_2, A06L.Color(0, 255, 0, 0));      // Turn second SYSLOG LED red
  A06R.setPixelColor(SYSLOG_A06_2, A06R.Color(0, 255, 0, 0));      // Turn second SYSLOG LED red
  SHOW_ALL_LEDS();
  delay(500);
   
  A01L.setPixelColor(SYSLOG_A01_3, A01L.Color(0, 255, 0, 0));      // Turn third SYSLOG LED red
  A01R.setPixelColor(SYSLOG_A01_3, A01R.Color(0, 255, 0, 0));      // Turn third SYSLOG LED red
  A02L.setPixelColor(SYSLOG_A02_3, A02L.Color(0, 255, 0, 0));      // Turn third SYSLOG LED red
  A02R.setPixelColor(SYSLOG_A02_3, A02R.Color(0, 255, 0, 0));      // Turn third SYSLOG LED red
  A03L.setPixelColor(SYSLOG_A03_3, A03L.Color(0, 255, 0, 0));      // Turn third SYSLOG LED red
  A03R.setPixelColor(SYSLOG_A03_3, A03R.Color(0, 255, 0, 0));      // Turn third SYSLOG LED red
  A04L.setPixelColor(SYSLOG_A04_3, A04L.Color(0, 255, 0, 0));      // Turn third SYSLOG LED red
  A04R.setPixelColor(SYSLOG_A04_3, A04R.Color(0, 255, 0, 0));      // Turn third SYSLOG LED red
  A05L.setPixelColor(SYSLOG_A05_3, A05L.Color(0, 255, 0, 0));      // Turn third SYSLOG LED red
  A05R.setPixelColor(SYSLOG_A05_3, A05R.Color(0, 255, 0, 0));      // Turn third SYSLOG LED red
  A06L.setPixelColor(SYSLOG_A06_3, A06L.Color(0, 255, 0, 0));      // Turn third SYSLOG LED red
  A06R.setPixelColor(SYSLOG_A06_3, A06R.Color(0, 255, 0, 0));      // Turn third SYSLOG LED red
  SHOW_ALL_LEDS();
  delay(1500);
   
  A01L.setPixelColor(SYSLOG_A01_2, A01L.Color(255, 255, 0, 0));      // Turn second SYSLOG LED orange
  A01R.setPixelColor(SYSLOG_A01_2, A01R.Color(255, 255, 0, 0));      // Turn second SYSLOG LED orange
  A02L.setPixelColor(SYSLOG_A02_2, A02L.Color(255, 255, 0, 0));      // Turn second SYSLOG LED orange
  A02R.setPixelColor(SYSLOG_A02_2, A02R.Color(255, 255, 0, 0));      // Turn second SYSLOG LED orange
  A03L.setPixelColor(SYSLOG_A03_2, A03L.Color(255, 255, 0, 0));      // Turn second SYSLOG LED orange
  A03R.setPixelColor(SYSLOG_A03_2, A03R.Color(255, 255, 0, 0));      // Turn second SYSLOG LED orange
  A04L.setPixelColor(SYSLOG_A04_2, A04L.Color(255, 255, 0, 0));      // Turn second SYSLOG LED orange
  A04R.setPixelColor(SYSLOG_A04_2, A04R.Color(255, 255, 0, 0));      // Turn second SYSLOG LED orange
  A05L.setPixelColor(SYSLOG_A05_2, A05L.Color(255, 255, 0, 0));      // Turn second SYSLOG LED orange
  A05R.setPixelColor(SYSLOG_A05_2, A05R.Color(255, 255, 0, 0));      // Turn second SYSLOG LED orange
  A06L.setPixelColor(SYSLOG_A06_2, A06L.Color(255, 255, 0, 0));      // Turn second SYSLOG LED orange
  A06R.setPixelColor(SYSLOG_A06_2, A06R.Color(255, 255, 0, 0));      // Turn second SYSLOG LED orange
  SHOW_ALL_LEDS();
  delay(500);
   
  A01L.setPixelColor(SYSLOG_A01_3, A01L.Color(255, 255, 0, 0));      // Turn third SYSLOG LED orange
  A01R.setPixelColor(SYSLOG_A01_3, A01R.Color(255, 255, 0, 0));      // Turn third SYSLOG LED orange
  A02L.setPixelColor(SYSLOG_A02_3, A02L.Color(255, 255, 0, 0));      // Turn third SYSLOG LED orange
  A02R.setPixelColor(SYSLOG_A02_3, A02R.Color(255, 255, 0, 0));      // Turn third SYSLOG LED orange
  A03L.setPixelColor(SYSLOG_A03_3, A03L.Color(255, 255, 0, 0));      // Turn third SYSLOG LED orange
  A03R.setPixelColor(SYSLOG_A03_3, A03R.Color(255, 255, 0, 0));      // Turn third SYSLOG LED orange
  A04L.setPixelColor(SYSLOG_A04_3, A04L.Color(255, 255, 0, 0));      // Turn third SYSLOG LED orange
  A04R.setPixelColor(SYSLOG_A04_3, A04R.Color(255, 255, 0, 0));      // Turn third SYSLOG LED orange
  A05L.setPixelColor(SYSLOG_A05_3, A05L.Color(255, 255, 0, 0));      // Turn third SYSLOG LED orange
  A05R.setPixelColor(SYSLOG_A05_3, A05R.Color(255, 255, 0, 0));      // Turn third SYSLOG LED orange
  A06L.setPixelColor(SYSLOG_A06_3, A06L.Color(255, 255, 0, 0));      // Turn third SYSLOG LED orange
  A06R.setPixelColor(SYSLOG_A06_3, A06R.Color(255, 255, 0, 0));      // Turn third SYSLOG LED orange
  SHOW_ALL_LEDS();
  delay(1500);   
                                                 
  A01L.setPixelColor(SYSLOG_A01_1, A01L.Color(50, 0, 0, 0));      // Turn first SYSLOG LED back to dimmed green
  A01R.setPixelColor(SYSLOG_A01_1, A01R.Color(50, 0, 0, 0));      // Turn first SYSLOG LED back to dimmed green
  A02L.setPixelColor(SYSLOG_A02_1, A02L.Color(50, 0, 0, 0));      // Turn first SYSLOG LED back to dimmed green
  A02R.setPixelColor(SYSLOG_A02_1, A02R.Color(50, 0, 0, 0));      // Turn first SYSLOG LED back to dimmed green
  A03L.setPixelColor(SYSLOG_A03_1, A03L.Color(50, 0, 0, 0));      // Turn first SYSLOG LED back to dimmed green
  A03R.setPixelColor(SYSLOG_A03_1, A03R.Color(50, 0, 0, 0));      // Turn first SYSLOG LED back to dimmed green
  A04L.setPixelColor(SYSLOG_A04_1, A04L.Color(50, 0, 0, 0));      // Turn first SYSLOG LED back to dimmed green
  A04R.setPixelColor(SYSLOG_A04_1, A04R.Color(50, 0, 0, 0));      // Turn first SYSLOG LED back to dimmed green
  A05L.setPixelColor(SYSLOG_A05_1, A05L.Color(50, 0, 0, 0));      // Turn first SYSLOG LED back to dimmed green
  A05R.setPixelColor(SYSLOG_A05_1, A05R.Color(50, 0, 0, 0));      // Turn first SYSLOG LED back to dimmed green
  A06L.setPixelColor(SYSLOG_A06_1, A06L.Color(50, 0, 0, 0));      // Turn first SYSLOG LED back to dimmed green
  A06R.setPixelColor(SYSLOG_A06_1, A06R.Color(50, 0, 0, 0));      // Turn first SYSLOG LED back to dimmed green
  SHOW_ALL_LEDS();
  delay(2000);
   
  A01L.setPixelColor(SYSLOG_A01_2, A01L.Color(50, 0, 0, 0));      // Turn second SYSLOG LED back to dimmed green
  A01R.setPixelColor(SYSLOG_A01_2, A01R.Color(50, 0, 0, 0));      // Turn second SYSLOG LED back to dimmed green
  A02L.setPixelColor(SYSLOG_A02_2, A02L.Color(50, 0, 0, 0));      // Turn second SYSLOG LED back to dimmed green
  A02R.setPixelColor(SYSLOG_A02_2, A02R.Color(50, 0, 0, 0));      // Turn second SYSLOG LED back to dimmed green
  A03L.setPixelColor(SYSLOG_A03_2, A03L.Color(50, 0, 0, 0));      // Turn second SYSLOG LED back to dimmed green
  A03R.setPixelColor(SYSLOG_A03_2, A03R.Color(50, 0, 0, 0));      // Turn second SYSLOG LED back to dimmed green
  A04L.setPixelColor(SYSLOG_A04_2, A04L.Color(50, 0, 0, 0));      // Turn second SYSLOG LED back to dimmed green
  A04R.setPixelColor(SYSLOG_A04_2, A04R.Color(50, 0, 0, 0));      // Turn second SYSLOG LED back to dimmed green
  A05L.setPixelColor(SYSLOG_A05_2, A05L.Color(50, 0, 0, 0));      // Turn second SYSLOG LED back to dimmed green
  A05R.setPixelColor(SYSLOG_A05_2, A05R.Color(50, 0, 0, 0));      // Turn second SYSLOG LED back to dimmed green
  A06L.setPixelColor(SYSLOG_A06_2, A06L.Color(50, 0, 0, 0));      // Turn second SYSLOG LED back to dimmed green
  A06R.setPixelColor(SYSLOG_A06_2, A06R.Color(50, 0, 0, 0));      // Turn second SYSLOG LED back to dimmed green
  SHOW_ALL_LEDS();
  delay(500);
   
  A01L.setPixelColor(SYSLOG_A01_3, A01L.Color(50, 0, 0, 0));      // Turn third SYSLOG LED back to dimmed green
  A01R.setPixelColor(SYSLOG_A01_3, A01R.Color(50, 0, 0, 0));      // Turn third SYSLOG LED back to dimmed green
  A02L.setPixelColor(SYSLOG_A02_3, A02L.Color(50, 0, 0, 0));      // Turn third SYSLOG LED back to dimmed green
  A02R.setPixelColor(SYSLOG_A02_3, A02R.Color(50, 0, 0, 0));      // Turn third SYSLOG LED back to dimmed green
  A03L.setPixelColor(SYSLOG_A03_3, A03L.Color(50, 0, 0, 0));      // Turn third SYSLOG LED back to dimmed green
  A03R.setPixelColor(SYSLOG_A03_3, A03R.Color(50, 0, 0, 0));      // Turn third SYSLOG LED back to dimmed green
  A04L.setPixelColor(SYSLOG_A04_3, A04L.Color(50, 0, 0, 0));      // Turn third SYSLOG LED back to dimmed green
  A04R.setPixelColor(SYSLOG_A04_3, A04R.Color(50, 0, 0, 0));      // Turn third SYSLOG LED back to dimmed green
  A05L.setPixelColor(SYSLOG_A05_3, A05L.Color(50, 0, 0, 0));      // Turn third SYSLOG LED back to dimmed green
  A05R.setPixelColor(SYSLOG_A05_3, A05R.Color(50, 0, 0, 0));      // Turn third SYSLOG LED back to dimmed green
  A06L.setPixelColor(SYSLOG_A06_3, A06L.Color(50, 0, 0, 0));      // Turn third SYSLOG LED back to dimmed green
  A06R.setPixelColor(SYSLOG_A06_3, A06R.Color(50, 0, 0, 0));      // Turn third SYSLOG LED back to dimmed green
  SHOW_ALL_LEDS();
  delay(2000);
}

void RAINBOW()
{
/*  Following order cycles through the rainbow:
 *   1. Add RED 
 *   2. Add GREEN
 *   3. Remove RED
 *   4. Add BLUE
 *   5. Remove GREEN
 *   6. Add RED
 *   7. Remove BLUE 
 *   
 */
 
  // Definition of variables that will change through the rainbow.
  int A01L_RED = 0;
  int A01L_GREEN = 0;
  int A01L_BLUE = 0;
  
  int A01R_RED = 0;
  int A01R_GREEN = 0;
  int A01R_BLUE = 0;

  int A02L_RED = 0;
  int A02L_GREEN = 0;
  int A02L_BLUE = 0;

  int A02R_RED = 0;
  int A02R_GREEN = 0;
  int A02R_BLUE = 0;
  
  int A03L_RED = 0;
  int A03L_GREEN = 0;
  int A03L_BLUE = 0;
  
  int A03R_RED = 0;
  int A03R_GREEN = 0;
  int A03R_BLUE = 0;

  int A04L_RED = 0;
  int A04L_GREEN = 0;
  int A04L_BLUE = 0;

  int A04R_RED = 0;
  int A04R_GREEN = 0;
  int A04R_BLUE = 0;
  
  int A05L_RED = 0;
  int A05L_GREEN = 0;
  int A05L_BLUE = 0;
  
  int A05R_RED = 0;
  int A05R_GREEN = 0;
  int A05R_BLUE = 0;

  int A06L_RED = 0;
  int A06L_GREEN = 0;
  int A06L_BLUE = 0;

  int A06R_RED = 0;
  int A06R_GREEN = 0;
  int A06R_BLUE = 0;
  
  int RAINBOW_WAIT = 2;

  // RUN UP 1
  for(int INCREASE=0; INCREASE<255; INCREASE++)
  {
    A01L_RED = INCREASE;
    
    for(int LED_NUMBER=0; LED_NUMBER<MAX_LEDS; LED_NUMBER++)       //loop cycles through the LEDs in the strip and updates the colors per LED
    {
      A01L.setPixelColor(LED_NUMBER, A01L.Color(A01L_GREEN, A01L_RED, A01L_BLUE, 0)); 
    }
    SHOW_ALL_LEDS();
    delay(RAINBOW_WAIT);
  }



  // RUN UP 2  
  for(int INCREASE=0; INCREASE<255; INCREASE++)
  {
    A01L_GREEN = INCREASE;
    A01R_RED = INCREASE;
    
    for(int LED_NUMBER=0; LED_NUMBER<MAX_LEDS; LED_NUMBER++)       //loop cycles through the LEDs in the strip and updates the colors per LED
    {
      A01L.setPixelColor(LED_NUMBER, A01L.Color(A01L_GREEN, A01L_RED, A01L_BLUE, 0)); 
      A01R.setPixelColor(LED_NUMBER, A01R.Color(A01R_GREEN, A01R_RED, A01R_BLUE, 0)); 
    }
    SHOW_ALL_LEDS();
    delay(RAINBOW_WAIT);
  }

  //RUN UP 3
  for(int INCREASE=0; INCREASE<255; INCREASE++)
  {
    A01L_RED = 255-INCREASE;
    A01R_GREEN = INCREASE;
    A02L_RED = INCREASE;
    
    for(int LED_NUMBER=0; LED_NUMBER<MAX_LEDS; LED_NUMBER++)       //loop cycles through the LEDs in the strip and updates the colors per LED
    {
      A01L.setPixelColor(LED_NUMBER, A01L.Color(A01L_GREEN, A01L_RED, A01L_BLUE, 0)); 
      A01R.setPixelColor(LED_NUMBER, A01R.Color(A01R_GREEN, A01R_RED, A01R_BLUE, 0)); 
      A02L.setPixelColor(LED_NUMBER, A02L.Color(A02L_GREEN, A02L_RED, A02L_BLUE, 0)); 
    }
    SHOW_ALL_LEDS();
    delay(RAINBOW_WAIT);
  }

  //RUN UP 4
  for(int INCREASE=0; INCREASE<255; INCREASE++)
  {
    A01L_BLUE = INCREASE;
    A01R_RED = 255-INCREASE;
    A02L_GREEN = INCREASE;
    A02R_RED = INCREASE;
    
    for(int LED_NUMBER=0; LED_NUMBER<MAX_LEDS; LED_NUMBER++)       //loop cycles through the LEDs in the strip and updates the colors per LED
    {
      A01L.setPixelColor(LED_NUMBER, A01L.Color(A01L_GREEN, A01L_RED, A01L_BLUE, 0)); 
      A01R.setPixelColor(LED_NUMBER, A01R.Color(A01R_GREEN, A01R_RED, A01R_BLUE, 0)); 
      A02L.setPixelColor(LED_NUMBER, A02L.Color(A02L_GREEN, A02L_RED, A02L_BLUE, 0)); 
      A02R.setPixelColor(LED_NUMBER, A02R.Color(A02R_GREEN, A02R_RED, A02R_BLUE, 0)); 
    }
    SHOW_ALL_LEDS();
    delay(RAINBOW_WAIT);
  }

  //RUN UP 5
  for(int INCREASE=0; INCREASE<255; INCREASE++)
  {
    A01L_GREEN = 255-INCREASE;
    A01R_BLUE = INCREASE;
    A02L_RED = 255-INCREASE;
    A02R_GREEN = INCREASE;
    A03L_RED = INCREASE;
    
    for(int LED_NUMBER=0; LED_NUMBER<MAX_LEDS; LED_NUMBER++)       //loop cycles through the LEDs in the strip and updates the colors per LED
    {
      A01L.setPixelColor(LED_NUMBER, A01L.Color(A01L_GREEN, A01L_RED, A01L_BLUE, 0)); 
      A01R.setPixelColor(LED_NUMBER, A01R.Color(A01R_GREEN, A01R_RED, A01R_BLUE, 0)); 
      A02L.setPixelColor(LED_NUMBER, A02L.Color(A02L_GREEN, A02L_RED, A02L_BLUE, 0)); 
      A02R.setPixelColor(LED_NUMBER, A02R.Color(A02R_GREEN, A02R_RED, A02R_BLUE, 0)); 
      A03L.setPixelColor(LED_NUMBER, A03L.Color(A03L_GREEN, A03L_RED, A03L_BLUE, 0)); 
    }
    SHOW_ALL_LEDS();
    delay(RAINBOW_WAIT);
  }


  //RUN UP 6
  for(int INCREASE=0; INCREASE<255; INCREASE++)
  {
    A01L_RED = INCREASE;
    A01R_GREEN = 255-INCREASE;
    A02L_BLUE = INCREASE;
    A02R_RED = 255-INCREASE;
    A03L_GREEN = INCREASE;
    A03R_RED = INCREASE;
    
    for(int LED_NUMBER=0; LED_NUMBER<MAX_LEDS; LED_NUMBER++)       //loop cycles through the LEDs in the strip and updates the colors per LED
    {
      A01L.setPixelColor(LED_NUMBER, A01L.Color(A01L_GREEN, A01L_RED, A01L_BLUE, 0)); 
      A01R.setPixelColor(LED_NUMBER, A01R.Color(A01R_GREEN, A01R_RED, A01R_BLUE, 0)); 
      A02L.setPixelColor(LED_NUMBER, A02L.Color(A02L_GREEN, A02L_RED, A02L_BLUE, 0)); 
      A02R.setPixelColor(LED_NUMBER, A02R.Color(A02R_GREEN, A02R_RED, A02R_BLUE, 0)); 
      A03L.setPixelColor(LED_NUMBER, A03L.Color(A03L_GREEN, A03L_RED, A03L_BLUE, 0)); 
      A03R.setPixelColor(LED_NUMBER, A03R.Color(A03R_GREEN, A03R_RED, A03R_BLUE, 0)); 
    }
    SHOW_ALL_LEDS();
    delay(RAINBOW_WAIT);
  }

  //RUN UP 7
  for(int INCREASE=0; INCREASE<255; INCREASE++)
  {
    A01L_BLUE = 255-INCREASE;
    A01R_RED = INCREASE;
    A02L_GREEN = 255-INCREASE;
    A02R_BLUE = INCREASE;
    A03L_RED = 255-INCREASE;
    A03R_GREEN = INCREASE;
    A04L_RED = INCREASE;
    
    for(int LED_NUMBER=0; LED_NUMBER<MAX_LEDS; LED_NUMBER++)       //loop cycles through the LEDs in the strip and updates the colors per LED
    {
      A01L.setPixelColor(LED_NUMBER, A01L.Color(A01L_GREEN, A01L_RED, A01L_BLUE, 0)); 
      A01R.setPixelColor(LED_NUMBER, A01R.Color(A01R_GREEN, A01R_RED, A01R_BLUE, 0)); 
      A02L.setPixelColor(LED_NUMBER, A02L.Color(A02L_GREEN, A02L_RED, A02L_BLUE, 0)); 
      A02R.setPixelColor(LED_NUMBER, A02R.Color(A02R_GREEN, A02R_RED, A02R_BLUE, 0)); 
      A03L.setPixelColor(LED_NUMBER, A03L.Color(A03L_GREEN, A03L_RED, A03L_BLUE, 0)); 
      A03R.setPixelColor(LED_NUMBER, A03R.Color(A03R_GREEN, A03R_RED, A03R_BLUE, 0)); 
      A04L.setPixelColor(LED_NUMBER, A04L.Color(A04L_GREEN, A04L_RED, A04L_BLUE, 0)); 
    }
    SHOW_ALL_LEDS();
    delay(RAINBOW_WAIT);
  }


  //RUN UP 8
  for(int INCREASE=0; INCREASE<255; INCREASE++)
  {
    A01L_GREEN = INCREASE;
    A01R_BLUE = 255-INCREASE;
    A02L_RED = INCREASE;
    A02R_GREEN = 255-INCREASE;
    A03L_BLUE = INCREASE;
    A03R_RED = 255-INCREASE;
    A04L_GREEN = INCREASE;
    A04R_RED = INCREASE;
    
    for(int LED_NUMBER=0; LED_NUMBER<MAX_LEDS; LED_NUMBER++)       //loop cycles through the LEDs in the strip and updates the colors per LED
    {
      A01L.setPixelColor(LED_NUMBER, A01L.Color(A01L_GREEN, A01L_RED, A01L_BLUE, 0)); 
      A01R.setPixelColor(LED_NUMBER, A01R.Color(A01R_GREEN, A01R_RED, A01R_BLUE, 0)); 
      A02L.setPixelColor(LED_NUMBER, A02L.Color(A02L_GREEN, A02L_RED, A02L_BLUE, 0)); 
      A02R.setPixelColor(LED_NUMBER, A02R.Color(A02R_GREEN, A02R_RED, A02R_BLUE, 0)); 
      A03L.setPixelColor(LED_NUMBER, A03L.Color(A03L_GREEN, A03L_RED, A03L_BLUE, 0)); 
      A03R.setPixelColor(LED_NUMBER, A03R.Color(A03R_GREEN, A03R_RED, A03R_BLUE, 0)); 
      A04L.setPixelColor(LED_NUMBER, A04L.Color(A04L_GREEN, A04L_RED, A04L_BLUE, 0)); 
      A04R.setPixelColor(LED_NUMBER, A04R.Color(A04R_GREEN, A04R_RED, A04R_BLUE, 0)); 
    }
    SHOW_ALL_LEDS();
    delay(RAINBOW_WAIT);
  }


  //RUN UP 9
  for(int INCREASE=0; INCREASE<255; INCREASE++)
  {
    A01L_RED = 255-INCREASE;
    A01R_GREEN = INCREASE;
    A02L_BLUE = 255-INCREASE;
    A02R_RED = INCREASE;
    A03L_GREEN = 255-INCREASE;
    A03R_BLUE = INCREASE;
    A04L_RED = 255-INCREASE;
    A04R_GREEN = INCREASE;
    A05L_RED = INCREASE;
    
    for(int LED_NUMBER=0; LED_NUMBER<MAX_LEDS; LED_NUMBER++)       //loop cycles through the LEDs in the strip and updates the colors per LED
    {
      A01L.setPixelColor(LED_NUMBER, A01L.Color(A01L_GREEN, A01L_RED, A01L_BLUE, 0)); 
      A01R.setPixelColor(LED_NUMBER, A01R.Color(A01R_GREEN, A01R_RED, A01R_BLUE, 0)); 
      A02L.setPixelColor(LED_NUMBER, A02L.Color(A02L_GREEN, A02L_RED, A02L_BLUE, 0)); 
      A02R.setPixelColor(LED_NUMBER, A02R.Color(A02R_GREEN, A02R_RED, A02R_BLUE, 0)); 
      A03L.setPixelColor(LED_NUMBER, A03L.Color(A03L_GREEN, A03L_RED, A03L_BLUE, 0)); 
      A03R.setPixelColor(LED_NUMBER, A03R.Color(A03R_GREEN, A03R_RED, A03R_BLUE, 0)); 
      A04L.setPixelColor(LED_NUMBER, A04L.Color(A04L_GREEN, A04L_RED, A04L_BLUE, 0)); 
      A04R.setPixelColor(LED_NUMBER, A04R.Color(A04R_GREEN, A04R_RED, A04R_BLUE, 0)); 
      A05L.setPixelColor(LED_NUMBER, A05L.Color(A05L_GREEN, A05L_RED, A05L_BLUE, 0)); 
    }
    SHOW_ALL_LEDS();
    delay(RAINBOW_WAIT);
  }


  //RUN UP 10
  for(int INCREASE=0; INCREASE<255; INCREASE++)
  {
    A01L_BLUE = INCREASE;
    A01R_RED = 255-INCREASE;
    A02L_GREEN = INCREASE;
    A02R_BLUE = 255-INCREASE;
    A03L_RED = INCREASE;
    A03R_GREEN = 255-INCREASE;
    A04L_BLUE = INCREASE;
    A04R_RED = 255-INCREASE;
    A05L_GREEN = INCREASE;
    A05R_RED = INCREASE;
    
    for(int LED_NUMBER=0; LED_NUMBER<MAX_LEDS; LED_NUMBER++)       //loop cycles through the LEDs in the strip and updates the colors per LED
    {
      A01L.setPixelColor(LED_NUMBER, A01L.Color(A01L_GREEN, A01L_RED, A01L_BLUE, 0)); 
      A01R.setPixelColor(LED_NUMBER, A01R.Color(A01R_GREEN, A01R_RED, A01R_BLUE, 0)); 
      A02L.setPixelColor(LED_NUMBER, A02L.Color(A02L_GREEN, A02L_RED, A02L_BLUE, 0)); 
      A02R.setPixelColor(LED_NUMBER, A02R.Color(A02R_GREEN, A02R_RED, A02R_BLUE, 0)); 
      A03L.setPixelColor(LED_NUMBER, A03L.Color(A03L_GREEN, A03L_RED, A03L_BLUE, 0)); 
      A03R.setPixelColor(LED_NUMBER, A03R.Color(A03R_GREEN, A03R_RED, A03R_BLUE, 0)); 
      A04L.setPixelColor(LED_NUMBER, A04L.Color(A04L_GREEN, A04L_RED, A04L_BLUE, 0)); 
      A04R.setPixelColor(LED_NUMBER, A04R.Color(A04R_GREEN, A04R_RED, A04R_BLUE, 0)); 
      A05L.setPixelColor(LED_NUMBER, A05L.Color(A05L_GREEN, A05L_RED, A05L_BLUE, 0)); 
      A05R.setPixelColor(LED_NUMBER, A05R.Color(A05R_GREEN, A05R_RED, A05R_BLUE, 0)); 
    }
    SHOW_ALL_LEDS();
    delay(RAINBOW_WAIT);
  }

  //RUN UP 11
  for(int INCREASE=0; INCREASE<255; INCREASE++)
  {
    A01L_GREEN = 255-INCREASE;
    A01R_BLUE = INCREASE;
    A02L_RED = 255-INCREASE;
    A02R_GREEN = INCREASE;
    A03L_BLUE = 255-INCREASE;
    A03R_RED = INCREASE;
    A04L_GREEN = 255-INCREASE;
    A04R_BLUE = INCREASE;
    A05L_RED = 255-INCREASE;
    A05R_GREEN = INCREASE;
    A06L_RED = INCREASE;
    
    for(int LED_NUMBER=0; LED_NUMBER<MAX_LEDS; LED_NUMBER++)       //loop cycles through the LEDs in the strip and updates the colors per LED
    {
      A01L.setPixelColor(LED_NUMBER, A01L.Color(A01L_GREEN, A01L_RED, A01L_BLUE, 0)); 
      A01R.setPixelColor(LED_NUMBER, A01R.Color(A01R_GREEN, A01R_RED, A01R_BLUE, 0)); 
      A02L.setPixelColor(LED_NUMBER, A02L.Color(A02L_GREEN, A02L_RED, A02L_BLUE, 0)); 
      A02R.setPixelColor(LED_NUMBER, A02R.Color(A02R_GREEN, A02R_RED, A02R_BLUE, 0)); 
      A03L.setPixelColor(LED_NUMBER, A03L.Color(A03L_GREEN, A03L_RED, A03L_BLUE, 0)); 
      A03R.setPixelColor(LED_NUMBER, A03R.Color(A03R_GREEN, A03R_RED, A03R_BLUE, 0)); 
      A04L.setPixelColor(LED_NUMBER, A04L.Color(A04L_GREEN, A04L_RED, A04L_BLUE, 0)); 
      A04R.setPixelColor(LED_NUMBER, A04R.Color(A04R_GREEN, A04R_RED, A04R_BLUE, 0)); 
      A05L.setPixelColor(LED_NUMBER, A05L.Color(A05L_GREEN, A05L_RED, A05L_BLUE, 0)); 
      A05R.setPixelColor(LED_NUMBER, A05R.Color(A05R_GREEN, A05R_RED, A05R_BLUE, 0)); 
      A06L.setPixelColor(LED_NUMBER, A06L.Color(A06L_GREEN, A06L_RED, A06L_BLUE, 0)); 
    }
    SHOW_ALL_LEDS();
    delay(RAINBOW_WAIT);
  }

  //RUN UP 12
  for(int INCREASE=0; INCREASE<255; INCREASE++)
  {
    A01L_RED = INCREASE;
    A01R_GREEN = 255-INCREASE;
    A02L_BLUE = INCREASE;
    A02R_RED = 255-INCREASE;
    A03L_GREEN = INCREASE;
    A03R_BLUE = 255-INCREASE;
    A04L_RED = INCREASE;
    A04R_GREEN = 255-INCREASE;
    A05L_BLUE = INCREASE;
    A05R_RED = 255-INCREASE;
    A06L_GREEN = INCREASE;
    A06R_RED = INCREASE;
    
    for(int LED_NUMBER=0; LED_NUMBER<MAX_LEDS; LED_NUMBER++)       //loop cycles through the LEDs in the strip and updates the colors per LED
    {
      A01L.setPixelColor(LED_NUMBER, A01L.Color(A01L_GREEN, A01L_RED, A01L_BLUE, 0)); 
      A01R.setPixelColor(LED_NUMBER, A01R.Color(A01R_GREEN, A01R_RED, A01R_BLUE, 0)); 
      A02L.setPixelColor(LED_NUMBER, A02L.Color(A02L_GREEN, A02L_RED, A02L_BLUE, 0)); 
      A02R.setPixelColor(LED_NUMBER, A02R.Color(A02R_GREEN, A02R_RED, A02R_BLUE, 0)); 
      A03L.setPixelColor(LED_NUMBER, A03L.Color(A03L_GREEN, A03L_RED, A03L_BLUE, 0)); 
      A03R.setPixelColor(LED_NUMBER, A03R.Color(A03R_GREEN, A03R_RED, A03R_BLUE, 0)); 
      A04L.setPixelColor(LED_NUMBER, A04L.Color(A04L_GREEN, A04L_RED, A04L_BLUE, 0)); 
      A04R.setPixelColor(LED_NUMBER, A04R.Color(A04R_GREEN, A04R_RED, A04R_BLUE, 0)); 
      A05L.setPixelColor(LED_NUMBER, A05L.Color(A05L_GREEN, A05L_RED, A05L_BLUE, 0)); 
      A05R.setPixelColor(LED_NUMBER, A05R.Color(A05R_GREEN, A05R_RED, A05R_BLUE, 0)); 
      A06L.setPixelColor(LED_NUMBER, A06L.Color(A06L_GREEN, A06L_RED, A06L_BLUE, 0)); 
      A06R.setPixelColor(LED_NUMBER, A06R.Color(A06R_GREEN, A06R_RED, A06R_BLUE, 0)); 
    }
    SHOW_ALL_LEDS();
    delay(RAINBOW_WAIT);
  }

    // Reapply states
    A01L_RED = 255;
    A01L_GREEN = 0;
    A01L_BLUE = 255;
    
    A01R_RED = 0;
    A01R_GREEN = 0;
    A01R_BLUE = 255;
  
    A02L_RED = 0;
    A02L_GREEN = 255;
    A02L_BLUE = 255;
  
    A02R_RED = 0;
    A02R_GREEN = 255;
    A02R_BLUE = 0;
    
    A03L_RED = 255;
    A03L_GREEN = 255;
    A03L_BLUE = 0;
    
    A03R_RED = 255;
    A03R_GREEN = 0;
    A03R_BLUE = 0;
  
    A04L_RED = 255;
    A04L_GREEN = 0;
    A04L_BLUE = 255;
  
    A04R_RED = 0;
    A04R_GREEN = 0;
    A04R_BLUE = 255;
    
    A05L_RED = 0;
    A05L_GREEN = 255;
    A05L_BLUE = 255;
    
    A05R_RED = 0;
    A05R_GREEN = 255;
    A05R_BLUE = 0;
  
    A06L_RED = 255;
    A06L_GREEN = 255;
    A06L_BLUE = 0;
  
    A06R_RED = 255;
    A06R_GREEN = 0;
    A06R_BLUE = 0;

    delay(1000);
    
    SHOW_ALL_LEDS();
    
  // START OF RAINBOW LOOP
  for(int LOOP=0; LOOP<5; LOOP++)
  {
   //LOOP part 1
    for(int INCREASE=0; INCREASE<255; INCREASE++)
    {
      A01L_BLUE = 255-INCREASE;
      A01R_RED = INCREASE;
      A02L_GREEN = 255-INCREASE;
      A02R_BLUE = INCREASE;
      A03L_RED = 255-INCREASE;
      A03R_GREEN = INCREASE;
      A04L_BLUE = 255-INCREASE;
      A04R_RED = INCREASE;
      A05L_GREEN = 255-INCREASE;
      A05R_BLUE = INCREASE;
      A06L_RED = 255-INCREASE;
      A06R_GREEN = INCREASE;
      
      for(int LED_NUMBER=0; LED_NUMBER<MAX_LEDS; LED_NUMBER++)       //loop cycles through the LEDs in the strip and updates the colors per LED
      {
        A01L.setPixelColor(LED_NUMBER, A01L.Color(A01L_GREEN, A01L_RED, A01L_BLUE, 0)); 
        A01R.setPixelColor(LED_NUMBER, A01R.Color(A01R_GREEN, A01R_RED, A01R_BLUE, 0)); 
        A02L.setPixelColor(LED_NUMBER, A02L.Color(A02L_GREEN, A02L_RED, A02L_BLUE, 0)); 
        A02R.setPixelColor(LED_NUMBER, A02R.Color(A02R_GREEN, A02R_RED, A02R_BLUE, 0)); 
        A03L.setPixelColor(LED_NUMBER, A03L.Color(A03L_GREEN, A03L_RED, A03L_BLUE, 0)); 
        A03R.setPixelColor(LED_NUMBER, A03R.Color(A03R_GREEN, A03R_RED, A03R_BLUE, 0)); 
        A04L.setPixelColor(LED_NUMBER, A04L.Color(A04L_GREEN, A04L_RED, A04L_BLUE, 0)); 
        A04R.setPixelColor(LED_NUMBER, A04R.Color(A04R_GREEN, A04R_RED, A04R_BLUE, 0)); 
        A05L.setPixelColor(LED_NUMBER, A05L.Color(A05L_GREEN, A05L_RED, A05L_BLUE, 0)); 
        A05R.setPixelColor(LED_NUMBER, A05R.Color(A05R_GREEN, A05R_RED, A05R_BLUE, 0)); 
        A06L.setPixelColor(LED_NUMBER, A06L.Color(A06L_GREEN, A06L_RED, A06L_BLUE, 0)); 
        A06R.setPixelColor(LED_NUMBER, A06R.Color(A06R_GREEN, A06R_RED, A06R_BLUE, 0)); 
      }
      SHOW_ALL_LEDS();
      delay(RAINBOW_WAIT);
    }


    //LOOP part 2
    for(int INCREASE=0; INCREASE<255; INCREASE++)
    {
    A01L_GREEN = INCREASE;
    A01R_BLUE = 255-INCREASE;
    A02L_RED = INCREASE;
    A02R_GREEN = 255-INCREASE;
    A03L_BLUE = INCREASE;
    A03R_RED = 255-INCREASE;
    A04L_GREEN = INCREASE;
    A04R_BLUE = 255-INCREASE;
    A05L_RED = INCREASE;
    A05R_GREEN = 255-INCREASE;
    A06L_BLUE = INCREASE;
    A06R_RED = 255-INCREASE;
      
      for(int LED_NUMBER=0; LED_NUMBER<MAX_LEDS; LED_NUMBER++)       //loop cycles through the LEDs in the strip and updates the colors per LED
      {
        A01L.setPixelColor(LED_NUMBER, A01L.Color(A01L_GREEN, A01L_RED, A01L_BLUE, 0)); 
        A01R.setPixelColor(LED_NUMBER, A01R.Color(A01R_GREEN, A01R_RED, A01R_BLUE, 0)); 
        A02L.setPixelColor(LED_NUMBER, A02L.Color(A02L_GREEN, A02L_RED, A02L_BLUE, 0)); 
        A02R.setPixelColor(LED_NUMBER, A02R.Color(A02R_GREEN, A02R_RED, A02R_BLUE, 0)); 
        A03L.setPixelColor(LED_NUMBER, A03L.Color(A03L_GREEN, A03L_RED, A03L_BLUE, 0)); 
        A03R.setPixelColor(LED_NUMBER, A03R.Color(A03R_GREEN, A03R_RED, A03R_BLUE, 0)); 
        A04L.setPixelColor(LED_NUMBER, A04L.Color(A04L_GREEN, A04L_RED, A04L_BLUE, 0)); 
        A04R.setPixelColor(LED_NUMBER, A04R.Color(A04R_GREEN, A04R_RED, A04R_BLUE, 0)); 
        A05L.setPixelColor(LED_NUMBER, A05L.Color(A05L_GREEN, A05L_RED, A05L_BLUE, 0)); 
        A05R.setPixelColor(LED_NUMBER, A05R.Color(A05R_GREEN, A05R_RED, A05R_BLUE, 0)); 
        A06L.setPixelColor(LED_NUMBER, A06L.Color(A06L_GREEN, A06L_RED, A06L_BLUE, 0)); 
        A06R.setPixelColor(LED_NUMBER, A06R.Color(A06R_GREEN, A06R_RED, A06R_BLUE, 0)); 
      }
      SHOW_ALL_LEDS();
      delay(RAINBOW_WAIT);
    }

   //LOOP part 3
    for(int INCREASE=0; INCREASE<255; INCREASE++)
    {
    A01L_RED = 255-INCREASE;
    A01R_GREEN = INCREASE;
    A02L_BLUE = 255-INCREASE;
    A02R_RED = INCREASE;
    A03L_GREEN = 255-INCREASE;
    A03R_BLUE = INCREASE;
    A04L_RED = 255-INCREASE;
    A04R_GREEN = INCREASE;
    A05L_BLUE = 255-INCREASE;
    A05R_RED = INCREASE;
    A06L_GREEN = 255-INCREASE;
    A06R_BLUE = INCREASE;;
      
      for(int LED_NUMBER=0; LED_NUMBER<MAX_LEDS; LED_NUMBER++)       //loop cycles through the LEDs in the strip and updates the colors per LED
      {
        A01L.setPixelColor(LED_NUMBER, A01L.Color(A01L_GREEN, A01L_RED, A01L_BLUE, 0)); 
        A01R.setPixelColor(LED_NUMBER, A01R.Color(A01R_GREEN, A01R_RED, A01R_BLUE, 0)); 
        A02L.setPixelColor(LED_NUMBER, A02L.Color(A02L_GREEN, A02L_RED, A02L_BLUE, 0)); 
        A02R.setPixelColor(LED_NUMBER, A02R.Color(A02R_GREEN, A02R_RED, A02R_BLUE, 0)); 
        A03L.setPixelColor(LED_NUMBER, A03L.Color(A03L_GREEN, A03L_RED, A03L_BLUE, 0)); 
        A03R.setPixelColor(LED_NUMBER, A03R.Color(A03R_GREEN, A03R_RED, A03R_BLUE, 0)); 
        A04L.setPixelColor(LED_NUMBER, A04L.Color(A04L_GREEN, A04L_RED, A04L_BLUE, 0)); 
        A04R.setPixelColor(LED_NUMBER, A04R.Color(A04R_GREEN, A04R_RED, A04R_BLUE, 0)); 
        A05L.setPixelColor(LED_NUMBER, A05L.Color(A05L_GREEN, A05L_RED, A05L_BLUE, 0)); 
        A05R.setPixelColor(LED_NUMBER, A05R.Color(A05R_GREEN, A05R_RED, A05R_BLUE, 0)); 
        A06L.setPixelColor(LED_NUMBER, A06L.Color(A06L_GREEN, A06L_RED, A06L_BLUE, 0)); 
        A06R.setPixelColor(LED_NUMBER, A06R.Color(A06R_GREEN, A06R_RED, A06R_BLUE, 0)); 
      }
      SHOW_ALL_LEDS();
      delay(RAINBOW_WAIT);
    }
  
    //LOOP part 4
    for(int INCREASE=0; INCREASE<255; INCREASE++)
    {
    A01L_BLUE = INCREASE;
    A01R_RED = 255-INCREASE;
    A02L_GREEN = INCREASE;
    A02R_BLUE = 255-INCREASE;
    A03L_RED = INCREASE;
    A03R_GREEN = 255-INCREASE;
    A04L_BLUE = INCREASE;
    A04R_RED = 255-INCREASE;
    A05L_GREEN = INCREASE;
    A05R_BLUE = 255-INCREASE;
    A06L_RED = INCREASE;
    A06R_GREEN = 255-INCREASE;
      
      for(int LED_NUMBER=0; LED_NUMBER<MAX_LEDS; LED_NUMBER++)       //loop cycles through the LEDs in the strip and updates the colors per LED
      {
        A01L.setPixelColor(LED_NUMBER, A01L.Color(A01L_GREEN, A01L_RED, A01L_BLUE, 0)); 
        A01R.setPixelColor(LED_NUMBER, A01R.Color(A01R_GREEN, A01R_RED, A01R_BLUE, 0)); 
        A02L.setPixelColor(LED_NUMBER, A02L.Color(A02L_GREEN, A02L_RED, A02L_BLUE, 0)); 
        A02R.setPixelColor(LED_NUMBER, A02R.Color(A02R_GREEN, A02R_RED, A02R_BLUE, 0)); 
        A03L.setPixelColor(LED_NUMBER, A03L.Color(A03L_GREEN, A03L_RED, A03L_BLUE, 0)); 
        A03R.setPixelColor(LED_NUMBER, A03R.Color(A03R_GREEN, A03R_RED, A03R_BLUE, 0)); 
        A04L.setPixelColor(LED_NUMBER, A04L.Color(A04L_GREEN, A04L_RED, A04L_BLUE, 0)); 
        A04R.setPixelColor(LED_NUMBER, A04R.Color(A04R_GREEN, A04R_RED, A04R_BLUE, 0)); 
        A05L.setPixelColor(LED_NUMBER, A05L.Color(A05L_GREEN, A05L_RED, A05L_BLUE, 0)); 
        A05R.setPixelColor(LED_NUMBER, A05R.Color(A05R_GREEN, A05R_RED, A05R_BLUE, 0)); 
        A06L.setPixelColor(LED_NUMBER, A06L.Color(A06L_GREEN, A06L_RED, A06L_BLUE, 0)); 
        A06R.setPixelColor(LED_NUMBER, A06R.Color(A06R_GREEN, A06R_RED, A06R_BLUE, 0)); 
      }
      SHOW_ALL_LEDS();
      delay(RAINBOW_WAIT);
    }


    //LOOP part 5
    for(int INCREASE=0; INCREASE<255; INCREASE++)
    {
    A01L_GREEN = 255-INCREASE;
    A01R_BLUE = INCREASE;
    A02L_RED = 255-INCREASE;
    A02R_GREEN = INCREASE;
    A03L_BLUE = 255-INCREASE;
    A03R_RED = INCREASE;
    A04L_GREEN = 255-INCREASE;
    A04R_BLUE = INCREASE;
    A05L_RED = 255-INCREASE;
    A05R_GREEN = INCREASE;
    A06L_BLUE = 255-INCREASE;
    A06R_RED = INCREASE;
      
      for(int LED_NUMBER=0; LED_NUMBER<MAX_LEDS; LED_NUMBER++)       //loop cycles through the LEDs in the strip and updates the colors per LED
      {
        A01L.setPixelColor(LED_NUMBER, A01L.Color(A01L_GREEN, A01L_RED, A01L_BLUE, 0)); 
        A01R.setPixelColor(LED_NUMBER, A01R.Color(A01R_GREEN, A01R_RED, A01R_BLUE, 0)); 
        A02L.setPixelColor(LED_NUMBER, A02L.Color(A02L_GREEN, A02L_RED, A02L_BLUE, 0)); 
        A02R.setPixelColor(LED_NUMBER, A02R.Color(A02R_GREEN, A02R_RED, A02R_BLUE, 0)); 
        A03L.setPixelColor(LED_NUMBER, A03L.Color(A03L_GREEN, A03L_RED, A03L_BLUE, 0)); 
        A03R.setPixelColor(LED_NUMBER, A03R.Color(A03R_GREEN, A03R_RED, A03R_BLUE, 0)); 
        A04L.setPixelColor(LED_NUMBER, A04L.Color(A04L_GREEN, A04L_RED, A04L_BLUE, 0)); 
        A04R.setPixelColor(LED_NUMBER, A04R.Color(A04R_GREEN, A04R_RED, A04R_BLUE, 0)); 
        A05L.setPixelColor(LED_NUMBER, A05L.Color(A05L_GREEN, A05L_RED, A05L_BLUE, 0)); 
        A05R.setPixelColor(LED_NUMBER, A05R.Color(A05R_GREEN, A05R_RED, A05R_BLUE, 0)); 
        A06L.setPixelColor(LED_NUMBER, A06L.Color(A06L_GREEN, A06L_RED, A06L_BLUE, 0)); 
        A06R.setPixelColor(LED_NUMBER, A06R.Color(A06R_GREEN, A06R_RED, A06R_BLUE, 0)); 
      }
      SHOW_ALL_LEDS();
      delay(RAINBOW_WAIT);
    }

    //LOOP part 6
    for(int INCREASE=0; INCREASE<255; INCREASE++)
    {
      A01L_RED = INCREASE;
      A01R_GREEN = 255-INCREASE;
      A02L_BLUE = INCREASE;
      A02R_RED = 255-INCREASE;
      A03L_GREEN = INCREASE;
      A03R_BLUE = 255-INCREASE;
      A04L_RED = INCREASE;
      A04R_GREEN = 255-INCREASE;
      A05L_BLUE = INCREASE;
      A05R_RED = 255-INCREASE;
      A06L_GREEN = INCREASE;
      A06R_BLUE = 255-INCREASE;
      
      for(int LED_NUMBER=0; LED_NUMBER<MAX_LEDS; LED_NUMBER++)       //loop cycles through the LEDs in the strip and updates the colors per LED
      {
        A01L.setPixelColor(LED_NUMBER, A01L.Color(A01L_GREEN, A01L_RED, A01L_BLUE, 0)); 
        A01R.setPixelColor(LED_NUMBER, A01R.Color(A01R_GREEN, A01R_RED, A01R_BLUE, 0)); 
        A02L.setPixelColor(LED_NUMBER, A02L.Color(A02L_GREEN, A02L_RED, A02L_BLUE, 0)); 
        A02R.setPixelColor(LED_NUMBER, A02R.Color(A02R_GREEN, A02R_RED, A02R_BLUE, 0)); 
        A03L.setPixelColor(LED_NUMBER, A03L.Color(A03L_GREEN, A03L_RED, A03L_BLUE, 0)); 
        A03R.setPixelColor(LED_NUMBER, A03R.Color(A03R_GREEN, A03R_RED, A03R_BLUE, 0)); 
        A04L.setPixelColor(LED_NUMBER, A04L.Color(A04L_GREEN, A04L_RED, A04L_BLUE, 0)); 
        A04R.setPixelColor(LED_NUMBER, A04R.Color(A04R_GREEN, A04R_RED, A04R_BLUE, 0)); 
        A05L.setPixelColor(LED_NUMBER, A05L.Color(A05L_GREEN, A05L_RED, A05L_BLUE, 0)); 
        A05R.setPixelColor(LED_NUMBER, A05R.Color(A05R_GREEN, A05R_RED, A05R_BLUE, 0)); 
        A06L.setPixelColor(LED_NUMBER, A06L.Color(A06L_GREEN, A06L_RED, A06L_BLUE, 0)); 
        A06R.setPixelColor(LED_NUMBER, A06R.Color(A06R_GREEN, A06R_RED, A06R_BLUE, 0)); 
      }
      SHOW_ALL_LEDS();
      delay(RAINBOW_WAIT);
    }
  }
}

