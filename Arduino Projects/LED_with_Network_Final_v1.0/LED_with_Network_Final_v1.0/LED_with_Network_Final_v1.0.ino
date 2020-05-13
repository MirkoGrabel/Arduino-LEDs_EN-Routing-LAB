#include <SPI.h>
#include <Ethernet.h>
#include <ICMPPing.h>
#include <Dns.h>
#include <Adafruit_NeoPixel.h>                     // Include Adafruit NeoPixel library


/* Dynamic setup of PIN assignment and LED strip length
const byte A01L_PIN = 0;                            // Digital output PIN the LED strip is connected to
const byte A01R_PIN = 1;                            // Digital output PIN the LED strip is connected to 
const byte A02L_PIN = 2;                            // Digital output PIN the LED strip is connected to 
const byte A02R_PIN = 3;                            // Digital output PIN the LED strip is connected to 
const byte A03L_PIN = 4;                            // Digital output PIN the LED strip is connected to 
const byte A03R_PIN = 5;                            // Digital output PIN the LED strip is connected to 
const byte A04L_PIN = 6;                            // Digital output PIN the LED strip is connected to 
const byte A04R_PIN = 7;                            // Digital output PIN the LED strip is connected to 
const byte A05L_PIN = 8;                            // Digital output PIN the LED strip is connected to 
const byte A05R_PIN = 9;                            // Digital output PIN the LED strip is connected to 
const byte A06L_PIN = 10;                            // Digital output PIN the LED strip is connected to
const byte A06R_PIN = 11;                            // Digital output PIN the LED strip is connected to 
*/
/*
const byte A01L_LEDS = 6;                           // Amount of LEDs in LED Strip
const byte A01R_LEDS = 6;                           // Amount of LEDs in LED Strip
const byte A02L_LEDS = 6;                           // Amount of LEDs in LED Strip
const byte A02R_LEDS = 6;                           // Amount of LEDs in LED Strip
const byte A03L_LEDS = 6;                           // Amount of LEDs in LED Strip
const byte A03R_LEDS = 6;                           // Amount of LEDs in LED Strip
const byte A04L_LEDS = 6;                           // Amount of LEDs in LED Strip
const byte A04R_LEDS = 6;                           // Amount of LEDs in LED Strip
const byte A05L_LEDS = 6;                           // Amount of LEDs in LED Strip
const byte A05R_LEDS = 6;                           // Amount of LEDs in LED Strip
const byte A06L_LEDS = 6;                           // Amount of LEDs in LED Strip
const byte A06R_LEDS = 7;                           // Amount of LEDs in LED Strip
*/

  // Definition of variables that will change through the rainbow.
  byte A01L_RED = 0;
  byte A01L_GREEN = 0;
  byte A01L_BLUE = 0;
  
  byte A01R_RED = 0;
  byte A01R_GREEN = 0;
  byte A01R_BLUE = 0;

  byte A02L_RED = 0;
  byte A02L_GREEN = 0;
  byte A02L_BLUE = 0;

  byte A02R_RED = 0;
  byte A02R_GREEN = 0;
  byte A02R_BLUE = 0;
  
  byte A03L_RED = 0;
  byte A03L_GREEN = 0;
  byte A03L_BLUE = 0;
  
  byte A03R_RED = 0;
  byte A03R_GREEN = 0;
  byte A03R_BLUE = 0;

  byte A04L_RED = 0;
  byte A04L_GREEN = 0;
  byte A04L_BLUE = 0;

  byte A04R_RED = 0;
  byte A04R_GREEN = 0;
  byte A04R_BLUE = 0;
  
  byte A05L_RED = 0;
  byte A05L_GREEN = 0;
  byte A05L_BLUE = 0;
  
  byte A05R_RED = 0;
  byte A05R_GREEN = 0;
  byte A05R_BLUE = 0;

const byte MAX_LEDS = 112;                             // Max LEDs in any strip

// Create objects to drive LEDs. First parameter is the maximum LEDs, second is the digital PIN they ar econnected to
Adafruit_NeoPixel A01L = Adafruit_NeoPixel(112, 2, NEO_RGBW + NEO_KHZ800);
Adafruit_NeoPixel A01R = Adafruit_NeoPixel(112, 3, NEO_RGBW + NEO_KHZ800);
Adafruit_NeoPixel A02L = Adafruit_NeoPixel(112, 4, NEO_RGBW + NEO_KHZ800);
Adafruit_NeoPixel A02R = Adafruit_NeoPixel(112, 5, NEO_RGBW + NEO_KHZ800);
Adafruit_NeoPixel A03L = Adafruit_NeoPixel(112, 6, NEO_RGBW + NEO_KHZ800);
Adafruit_NeoPixel A03R = Adafruit_NeoPixel(112, 7, NEO_RGBW + NEO_KHZ800);
Adafruit_NeoPixel A04L = Adafruit_NeoPixel(112, 8, NEO_RGBW + NEO_KHZ800);
Adafruit_NeoPixel A04R = Adafruit_NeoPixel(112, 9, NEO_RGBW + NEO_KHZ800);
Adafruit_NeoPixel A05L = Adafruit_NeoPixel(112, 14, NEO_RGBW + NEO_KHZ800);
Adafruit_NeoPixel A05R = Adafruit_NeoPixel(112, 15, NEO_RGBW + NEO_KHZ800);
//Adafruit_NeoPixel A06L = Adafruit_NeoPixel(A06L_LEDS, A06L_PIN, NEO_RGBW + NEO_KHZ800);
//Adafruit_NeoPixel A06R = Adafruit_NeoPixel(A06R_LEDS, A06R_PIN, NEO_RGBW + NEO_KHZ800);

byte wait = 10;                                      // Standard wait delay used throughout demos 

// Standard IP addressing stuff, could be done via DHCP but static is easier. 
byte MAC[] = {0xDE, 0xA4, 0x25, 0xA7, 0xD1, 0xED}; // mac address for ethernet shield
IPAddress IP(10, 29, 43, 9);
IPAddress GATEWAY(10,29,43,1);
IPAddress SUBNET(255, 255, 255, 0);
IPAddress DNS(10,29,43,1);

// Define the URL used for the MQTT Broker hosted by AWS
//char AWSURL [45] = "a3575go64bfs8h.iot.us-west-2.amazonaws.com";

// Create an instance of ICMPPing and call it "ping". It uses the constructor "ICMPPing".  Required parameters are a socket number (always 0) and a random ID
ICMPPing ping(0, (uint16_t)random(0, 255));

// Next we create a DNS Client to use for DNS queries. We can't name it "dns" for unknown reason"
DNSClient dnClient;

// Start web server on port 80
EthernetServer server(80);
// create global string for web client response
String readString;

// The setup is executed only once at program start and runs all diags for troubleshooting  
void setup()
{
  // Initialize LEDs and switch off all LEDs
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
  SET_ALL_COLORS(0, 255, 0, 0);
  
  // start Ethernet
  Ethernet.begin(MAC, IP, DNS, GATEWAY, SUBNET);
  // Start web server
  server.begin();
  // Start DNS client
  dnClient.begin(Ethernet.dnsServerIP());
  // Start serial connection for debug output, disables PIN 0 & 1!!!!
  Serial.begin(9600);

  // Show debug information
  Serial.println("Setup is starting. Below are some debug information: " );
  Serial.print("My IP Address is:      ");
  Serial.println(Ethernet.localIP());
  Serial.print("My Subnet Mask is:     ");
  Serial.println(Ethernet.subnetMask()); 
  Serial.print("My Default Gateway is: ");
  Serial.println(Ethernet.gatewayIP());
//  Serial.print("My DNS Server is:      ");
//  Serial.println(Ethernet.dnsServerIP()); 
//  Serial.print("The AWS IOT ID is:     ");
//  Serial.println(AWSURL);
  Serial.println();
  
 
  Serial.println("Testing Gateway IP via Ping");
  PingTest(GATEWAY);
  Serial.println();
  delay(1000); 
       
//  Serial.println("Testing DNS Server IP via Ping");
//  PingTest(DNS);
//  Serial.println();
//  delay(10); 

//  Serial.println("Testing DNS Service");
//  char DNSTESTURL[12] = "google.com";
//  IPAddress IPofDNSTESTURL = ResolveDNS(DNSTESTURL);
//  Serial.println();
//  delay(1000);

//  Serial.println("Testing resolved IP address via Ping");
//  PingTest(IPofDNSTESTURL);
//  Serial.println();
//  delay(10); 

/*  Serial.println("Resolving AWS IOT Gateway");
  IPAddress IPofAWSIOT = ResolveDNS(AWSURL);
  Serial.println();
  delay(2000);
  
  Serial.println("Testing AWS IOT Gateway IP address via Ping");
  PingTest(IPofAWSIOT);
  Serial.println();
  delay(2000); 
*/    
  Serial.println("Setup is complete, handing over to LOOP" );
  Serial.println();

  // Stop serial debugging to be able to use PIN 0 and 1  
  // display all green test pattern for a few seconds
  SET_ALL_COLORS(1, 0, 0, 0);
  delay (1000);
}


 
void loop()
{
// listen for incoming clients
  EthernetClient client = server.available();
  if (client)

  {
    //Serial.println("new client");

    while (client.connected())
    {
      if (client.available())

      {
        char c = client.read();

        //read char by char HTTP request
        if (readString.length() < 100)

        {

          //store characters to string
          readString += c;
          Serial.print(c);


          //Serial.write(c);
          // if you've gotten to the end of the line (received a newline
          // character) and the line is blank, the http request has ended,
          // so you can send a reply
          //if HTTP request has ended
          if (c == '\n') {
            Serial.println(readString); //prbyte to serial monitor for debuging
//--------------------------------------------------------------------------------------------------------
// Needed to Display Site:
client.println("HTTP/1.1 200 OK"); //send new page
            client.println("Content-Type: text/html");
            client.println();
            client.println("<HTML>");
            client.println("<HEAD>");

//--------------------------------------------------------------------------------------------------------
//-------------------------------------------------
// what is being Displayed :     
        
            client.println("<TITLE>SJC24-2 TME Lab LED Lights Control Page</TITLE>");
            client.println("<center>");
            client.println("</HEAD>");
            client.println("<BODY>");
            client.println("<H1>SJC24-2 TME Lab LED Lights Control Page</H1>");
            client.println("<hr />");
            client.println("<center>");
            client.println("<br />");
            
            client.println("<a href=\"/?ledtest\"\">Test All LEDs</a>");
            client.println("<br />");
            client.println("<br />");
            client.println("<a href=\"/?terminalserver\"\">Show the Terminal Servers</a><br />");     
            client.println("<br />");
            client.println("<br />");
            client.println("<a href=\"/?syslog\"\">Show a Syslog use-case</a><br />");     
            client.println("<br />");
            client.println("<br />");
            client.println("<a href=\"/?rainbow\"\">Show me the rainbow</a><br />");     

            client.println("</BODY>");
            client.println("</HTML>");

            delay(1);
            //stopping client
            client.stop();

            //-------------------------------------------------
            // Code which needs to be Implemented:
            if(readString.indexOf("?ledtest") >0)
            {
              Serial.println("ledtest");
              CYCLE_ALL_COLORS();
              SET_ALL_COLORS(1, 0, 0, 0);
            }
            if(readString.indexOf("?terminalserver") >0)
            {
              Serial.println("terminalserver");
              TERMINAL_SERVERS();
              SET_ALL_COLORS(1, 0, 0, 0);
            }
            if(readString.indexOf("?syslog") >0)
            {
              Serial.println("syslog");
              SYSLOG(); 
              SET_ALL_COLORS(1, 0, 0, 0);
            }
            if(readString.indexOf("?rainbow") >0)
            {
              Serial.println("rainbow");
              RAINBOW(); 
              SET_ALL_COLORS(1, 0, 0, 0);
            }
            
            //clearing string for next read
            readString="";

            // give the web browser time to receive the data
            delay(1);
            // close the connection:
            client.stop();
            Serial.println("client disonnected");

      }
     }
    }
   }
 }
}



// The following function tries to ping the default gateway.
void PingTest(IPAddress PINGTHISIP)
{
  // Create an array of characters that will be used a s buffer for text input and output
  //char buffer [80];
  Serial.print("Trying to ping: ");
  Serial.println(PINGTHISIP);
  // Creates structure (called echoReply) that is returned by the ICMPPing function. It includes a few parameters. 
  for (byte i=1; i<6; i++)
  {
    ICMPEchoReply echoReply = ping(PINGTHISIP, 1);
    if (echoReply.status == SUCCESS)
    {
      Serial.print("Reply[");
      Serial.print(i);
      Serial.print("] from: ");
      Serial.print(echoReply.addr[0]);
      Serial.print(".");      
      Serial.print(echoReply.addr[1]);
      Serial.print("."); 
      Serial.print(echoReply.addr[2]);
      Serial.print("."); 
      Serial.print(echoReply.addr[3]);
      Serial.print(": bytes=");
      Serial.print(REQ_DATASIZE);
      Serial.print("time=");
      Serial.print(millis() - echoReply.data.time);
      Serial.print("ms TTL=");
      Serial.println(echoReply.ttl);
   }
   else
   {
      Serial.print("Echo request failed. Error Code: ");
      Serial.println(echoReply.status);
   }

   delay(500);
   }
}




IPAddress ResolveDNS(char URL [80])
{
  IPAddress dnsIP1;
  dnClient.begin(Ethernet.dnsServerIP());
  Serial.print("Trying to resolve DNS for:  ");
  Serial.println(URL);
  Serial.print("Resolved to: ");
  dnClient.getHostByName(URL, dnsIP1);
  Serial.println(dnsIP1);
  return dnsIP1;
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
}

void SET_ALL_COLORS(byte GREEN, byte RED, byte BLUE, byte WHITE)
{
  for(byte i=0; i<MAX_LEDS; i++) 
  {            
    A01L.setPixelColor(i, A01L.Color(GREEN, RED, BLUE, WHITE));
    A01R.setPixelColor(i, A01R.Color(GREEN, RED, BLUE, WHITE));          
    A02L.setPixelColor(i, A02L.Color(GREEN, RED, BLUE, WHITE));          
    A02R.setPixelColor(i, A02R.Color(GREEN, RED, BLUE, WHITE));
    A03L.setPixelColor(i, A03L.Color(GREEN, RED, BLUE, WHITE));
    A03R.setPixelColor(i, A03R.Color(GREEN, RED, BLUE, WHITE));
    A04L.setPixelColor(i, A04L.Color(GREEN, RED, BLUE, WHITE));
    A04R.setPixelColor(i, A04R.Color(GREEN, RED, BLUE, WHITE));
    A05L.setPixelColor(i, A05L.Color(GREEN, RED, BLUE, WHITE));
    A05R.setPixelColor(i, A05R.Color(GREEN, RED, BLUE, WHITE));
 }
  SHOW_ALL_LEDS();
}


void CYCLE_ALL_COLORS()
{
  for(byte GREEN=0; GREEN<58; GREEN++)                          // For loop cycles through the color brightness
  {
      SET_ALL_COLORS(pow(1.1,GREEN),0,0,0);
      delay(wait);                        // Delay for visual effect
  }
  
  for(byte RED=0; RED<58; RED++) 
  {
      SET_ALL_COLORS(0,pow(1.1,RED),0,0);
      delay(wait); 
  }
  for(byte BLUE=0; BLUE<58; BLUE++) 
  {
      SET_ALL_COLORS(0,0,pow(1.1,BLUE),0);
      delay(wait);
  }
  for(byte WHITE=0; WHITE<58; WHITE++) 
  {
      SET_ALL_COLORS(0,0,0,pow(1.1,WHITE));
      delay(wait);
  }
}

void TERMINAL_SERVERS()
{
   SET_ALL_COLORS(255,0,0,0); // First we set all LEDs to green
   delay(wait);                       
   for(byte BLINK=0; BLINK<10; BLINK++) // Show the Terminal Server LED 10 times
   {
    A01L.setPixelColor(MAX_LEDS-6, A01L.Color(0, 255, 0, 0));
    A01L.setPixelColor(MAX_LEDS-7, A01L.Color(0, 255, 0, 0));
    A01L.setPixelColor(MAX_LEDS-8, A01L.Color(0, 255, 0, 0));
    A01R.setPixelColor(MAX_LEDS-6, A01R.Color(0, 255, 0, 0));
    A01R.setPixelColor(MAX_LEDS-7, A01R.Color(0, 255, 0, 0));
    A01R.setPixelColor(MAX_LEDS-8, A01R.Color(0, 255, 0, 0));
    A02L.setPixelColor(MAX_LEDS-6, A02L.Color(0, 255, 0, 0));
    A02L.setPixelColor(MAX_LEDS-7, A02L.Color(0, 255, 0, 0));
    A02L.setPixelColor(MAX_LEDS-8, A02L.Color(0, 255, 0, 0));
    A02R.setPixelColor(MAX_LEDS-6, A02R.Color(0, 255, 0, 0));
    A02R.setPixelColor(MAX_LEDS-7, A02R.Color(0, 255, 0, 0));
    A02R.setPixelColor(MAX_LEDS-8, A02R.Color(0, 255, 0, 0));
    A03L.setPixelColor(MAX_LEDS-6, A03L.Color(0, 255, 0, 0));
    A03L.setPixelColor(MAX_LEDS-7, A03L.Color(0, 255, 0, 0));
    A03L.setPixelColor(MAX_LEDS-8, A03L.Color(0, 255, 0, 0));
    A03R.setPixelColor(MAX_LEDS-6, A03R.Color(0, 255, 0, 0));
    A03R.setPixelColor(MAX_LEDS-7, A03R.Color(0, 255, 0, 0));
    A03R.setPixelColor(MAX_LEDS-8, A03R.Color(0, 255, 0, 0));
    A04L.setPixelColor(MAX_LEDS-6, A04L.Color(0, 255, 0, 0));
    A04L.setPixelColor(MAX_LEDS-7, A04L.Color(0, 255, 0, 0));
    A04L.setPixelColor(MAX_LEDS-8, A04L.Color(0, 255, 0, 0));
    A04R.setPixelColor(MAX_LEDS-6, A04R.Color(0, 255, 0, 0));
    A04R.setPixelColor(MAX_LEDS-7, A04R.Color(0, 255, 0, 0));
    A04R.setPixelColor(MAX_LEDS-8, A04R.Color(0, 255, 0, 0));
    A05L.setPixelColor(MAX_LEDS-6, A05L.Color(0, 255, 0, 0));
    A05L.setPixelColor(MAX_LEDS-7, A05L.Color(0, 255, 0, 0));
    A05L.setPixelColor(MAX_LEDS-8, A05L.Color(0, 255, 0, 0));
    A05R.setPixelColor(MAX_LEDS-6, A05R.Color(0, 255, 0, 0));
    A05R.setPixelColor(MAX_LEDS-7, A05R.Color(0, 255, 0, 0));   
    A05R.setPixelColor(MAX_LEDS-8, A05R.Color(0, 255, 0, 0));

    SHOW_ALL_LEDS();                   // Show terminal server LEDs in red
    
    delay(500);                       // Wait
    SET_ALL_COLORS(255,0,0,0);
    SHOW_ALL_LEDS();                   // Show terminal server LEDs in green

    delay(500);                        // Wait
   }
}

void SET_COLORS_RU (byte RACK, byte LED, byte GREEN, byte RED, byte BLUE, byte WHITE)
{
 if (RACK == 1)
 { 
    A01L.setPixelColor(LED, A01L.Color(GREEN, RED, BLUE, WHITE));
    A01R.setPixelColor(LED, A01R.Color(GREEN, RED, BLUE, WHITE));
    A01L.setPixelColor(LED+1, A01L.Color(GREEN, RED, BLUE, WHITE));
    A01R.setPixelColor(LED+1, A01R.Color(GREEN, RED, BLUE, WHITE));
    A01L.setPixelColor(LED+2, A01L.Color(GREEN, RED, BLUE, WHITE));
    A01R.setPixelColor(LED+2, A01R.Color(GREEN, RED, BLUE, WHITE));  
 }
 if (RACK == 2)
 { 
    A02L.setPixelColor(LED, A02L.Color(GREEN, RED, BLUE, WHITE));
    A02R.setPixelColor(LED, A02R.Color(GREEN, RED, BLUE, WHITE));
    A02L.setPixelColor(LED+1, A02L.Color(GREEN, RED, BLUE, WHITE));
    A02R.setPixelColor(LED+1, A02R.Color(GREEN, RED, BLUE, WHITE));
    A02L.setPixelColor(LED+2, A02L.Color(GREEN, RED, BLUE, WHITE));
    A02R.setPixelColor(LED+2, A02R.Color(GREEN, RED, BLUE, WHITE)); 
 }
  if (RACK == 3)
 { 
    A03L.setPixelColor(LED, A03L.Color(GREEN, RED, BLUE, WHITE));
    A03R.setPixelColor(LED, A03R.Color(GREEN, RED, BLUE, WHITE));
    A03L.setPixelColor(LED+1, A03L.Color(GREEN, RED, BLUE, WHITE));
    A03R.setPixelColor(LED+1, A03R.Color(GREEN, RED, BLUE, WHITE));
    A03L.setPixelColor(LED+2, A03L.Color(GREEN, RED, BLUE, WHITE));
    A03R.setPixelColor(LED+2, A03R.Color(GREEN, RED, BLUE, WHITE)); 
 }
  if (RACK == 4)
 { 
    A04L.setPixelColor(LED, A04L.Color(GREEN, RED, BLUE, WHITE));
    A04R.setPixelColor(LED, A04R.Color(GREEN, RED, BLUE, WHITE));
    A04L.setPixelColor(LED+1, A04L.Color(GREEN, RED, BLUE, WHITE));
    A04R.setPixelColor(LED+1, A04R.Color(GREEN, RED, BLUE, WHITE));
    A04L.setPixelColor(LED+2, A04L.Color(GREEN, RED, BLUE, WHITE));
    A04R.setPixelColor(LED+2, A04R.Color(GREEN, RED, BLUE, WHITE)); 
 }
  if (RACK == 5)
 { 
    A05L.setPixelColor(LED, A05L.Color(GREEN, RED, BLUE, WHITE));
    A05R.setPixelColor(LED, A05R.Color(GREEN, RED, BLUE, WHITE));
    A05L.setPixelColor(LED+1, A05L.Color(GREEN, RED, BLUE, WHITE));
    A05R.setPixelColor(LED+1, A05R.Color(GREEN, RED, BLUE, WHITE));
    A05L.setPixelColor(LED+2, A05L.Color(GREEN, RED, BLUE, WHITE));
    A05R.setPixelColor(LED+2, A05R.Color(GREEN, RED, BLUE, WHITE)); 
 }
 
}

void SYSLOG()
{
                                                             // First we set all LEDs to a dimm green
  SET_ALL_COLORS(20,0,0,0);
  delay(2000);                       
                                        //create 3 random numbers
   byte SYSLOG_A01_1=random(0-MAX_LEDS);
   byte SYSLOG_A01_2=random(0-MAX_LEDS);
   while (SYSLOG_A01_1 == SYSLOG_A01_2)
    {
      SYSLOG_A01_2=random(0-MAX_LEDS);
    }
   byte SYSLOG_A01_3=random(0-MAX_LEDS);
   while (SYSLOG_A01_3 == SYSLOG_A01_2 || SYSLOG_A01_3 == SYSLOG_A01_1)
    {
      SYSLOG_A01_3=random(0-MAX_LEDS);
    }  
  
  
   byte SYSLOG_A02_1=random(0-MAX_LEDS);
   byte SYSLOG_A02_2=random(0-MAX_LEDS);
   while (SYSLOG_A02_1 == SYSLOG_A02_2)
    {
      SYSLOG_A02_2=random(0-MAX_LEDS);
    }
   byte SYSLOG_A02_3=random(0-MAX_LEDS);
   while (SYSLOG_A02_3 == SYSLOG_A02_2 || SYSLOG_A02_3 == SYSLOG_A02_1)
    {
      SYSLOG_A02_3=random(0-MAX_LEDS);
    }  
  
  
   byte SYSLOG_A03_1=random(0-MAX_LEDS);
   byte SYSLOG_A03_2=random(0-MAX_LEDS);
   while (SYSLOG_A03_1 == SYSLOG_A03_2)
    {
      SYSLOG_A03_2=random(0-MAX_LEDS);
    }
   byte SYSLOG_A03_3=random(0-MAX_LEDS);
   while (SYSLOG_A03_3 == SYSLOG_A03_2 || SYSLOG_A03_3 == SYSLOG_A03_1)
    {
      SYSLOG_A03_3=random(0-MAX_LEDS);
    }  
  
  
   byte SYSLOG_A04_1=random(0-MAX_LEDS);
   byte SYSLOG_A04_2=random(0-MAX_LEDS);
   while (SYSLOG_A04_1 == SYSLOG_A04_2)
    {
      SYSLOG_A04_2=random(0-MAX_LEDS);
    }
   byte SYSLOG_A04_3=random(0-MAX_LEDS);
   while (SYSLOG_A04_3 == SYSLOG_A04_2 || SYSLOG_A04_3 == SYSLOG_A04_1)
    {
      SYSLOG_A04_3=random(0-MAX_LEDS);
    }  
  
  
   byte SYSLOG_A05_1=random(0-MAX_LEDS);
   byte SYSLOG_A05_2=random(0-MAX_LEDS);
   while (SYSLOG_A05_1 == SYSLOG_A05_2)
    {
      SYSLOG_A05_2=random(0-MAX_LEDS);
    }
   byte SYSLOG_A05_3=random(0-MAX_LEDS);
   while (SYSLOG_A05_3 == SYSLOG_A05_2 || SYSLOG_A05_3 == SYSLOG_A05_1)
    {
      SYSLOG_A05_3=random(0-MAX_LEDS);
    }  
  
  SET_COLORS_RU(1,SYSLOG_A01_1, 0, 255, 0, 0); //Turn first syslog RU RED
  SET_COLORS_RU(2,SYSLOG_A02_1, 0, 255, 0, 0);
  SET_COLORS_RU(3,SYSLOG_A03_1, 0, 255, 0, 0);
  SET_COLORS_RU(4,SYSLOG_A04_1, 0, 255, 0, 0);
  SET_COLORS_RU(5,SYSLOG_A05_1, 0, 255, 0, 0);
  SHOW_ALL_LEDS();
  delay(2000);                                                 // Wait 
 
  SET_COLORS_RU(1,SYSLOG_A01_1, 255, 255, 0, 0); //Turn first syslog RU Orange
  SET_COLORS_RU(2,SYSLOG_A02_1, 255, 255, 0, 0);
  SET_COLORS_RU(3,SYSLOG_A03_1, 255, 255, 0, 0);
  SET_COLORS_RU(4,SYSLOG_A04_1, 255, 255, 0, 0);
  SET_COLORS_RU(5,SYSLOG_A05_1, 255, 255, 0, 0);
  SHOW_ALL_LEDS();
  delay(2000);                                                 

  SET_COLORS_RU(1,SYSLOG_A01_2, 0, 255, 0, 0); //Turn second SYSLOG RU red
  SET_COLORS_RU(2,SYSLOG_A02_2, 0, 255, 0, 0);
  SET_COLORS_RU(3,SYSLOG_A03_2, 0, 255, 0, 0);
  SET_COLORS_RU(4,SYSLOG_A04_2, 0, 255, 0, 0);
  SET_COLORS_RU(5,SYSLOG_A05_2, 0, 255, 0, 0);
  SHOW_ALL_LEDS();
  delay(500);
   
  SET_COLORS_RU(1,SYSLOG_A01_3, 0, 255, 0, 0); //Turn third SYSLOG RU red
  SET_COLORS_RU(2,SYSLOG_A02_3, 0, 255, 0, 0);
  SET_COLORS_RU(3,SYSLOG_A03_3, 0, 255, 0, 0);
  SET_COLORS_RU(4,SYSLOG_A04_3, 0, 255, 0, 0);
  SET_COLORS_RU(5,SYSLOG_A05_3, 0, 255, 0, 0);
  SHOW_ALL_LEDS();
  delay(1500);
   
  SET_COLORS_RU(1,SYSLOG_A01_2, 255, 255, 0, 0); //Turn second syslog RU Orange
  SET_COLORS_RU(2,SYSLOG_A02_2, 255, 255, 0, 0);
  SET_COLORS_RU(3,SYSLOG_A03_2, 255, 255, 0, 0);
  SET_COLORS_RU(4,SYSLOG_A04_2, 255, 255, 0, 0);
  SET_COLORS_RU(5,SYSLOG_A05_2, 255, 255, 0, 0);
  SHOW_ALL_LEDS();
  delay(500);
   
  SET_COLORS_RU(1,SYSLOG_A01_3, 255, 255, 0, 0); //Turn third syslog RU Orange
  SET_COLORS_RU(2,SYSLOG_A02_3, 255, 255, 0, 0);
  SET_COLORS_RU(3,SYSLOG_A03_3, 255, 255, 0, 0);
  SET_COLORS_RU(4,SYSLOG_A04_3, 255, 255, 0, 0);
  SET_COLORS_RU(5,SYSLOG_A05_3, 255, 255, 0, 0);
  SHOW_ALL_LEDS();
  delay(1500);   
                                                 
  SET_COLORS_RU(1,SYSLOG_A01_1, 20, 0, 0, 0); // Turn first SYSLOG RU back to dimmed green
  SET_COLORS_RU(2,SYSLOG_A02_1, 20, 0, 0, 0);
  SET_COLORS_RU(3,SYSLOG_A03_1, 20, 0, 0, 0);
  SET_COLORS_RU(4,SYSLOG_A04_1, 20, 0, 0, 0);
  SET_COLORS_RU(5,SYSLOG_A05_1, 20, 0, 0, 0);    
   SHOW_ALL_LEDS();
  delay(2000);
   
  SET_COLORS_RU(1,SYSLOG_A01_2, 20, 0, 0, 0); // Turn second SYSLOG RY back to dimmed green
  SET_COLORS_RU(2,SYSLOG_A02_2, 20, 0, 0, 0);
  SET_COLORS_RU(3,SYSLOG_A03_2, 20, 0, 0, 0);
  SET_COLORS_RU(4,SYSLOG_A04_2, 20, 0, 0, 0);
  SET_COLORS_RU(5,SYSLOG_A05_2, 20, 0, 0, 0); 
  SHOW_ALL_LEDS();
  delay(500);
   
  SET_COLORS_RU(1,SYSLOG_A01_3, 20, 0, 0, 0); // Turn third SYSLOG RU back to dimmed green
  SET_COLORS_RU(2,SYSLOG_A02_3, 20, 0, 0, 0);
  SET_COLORS_RU(3,SYSLOG_A03_3, 20, 0, 0, 0);
  SET_COLORS_RU(4,SYSLOG_A04_3, 20, 0, 0, 0);
  SET_COLORS_RU(5,SYSLOG_A05_3, 20, 0, 0, 0); 
  SHOW_ALL_LEDS();
  delay(2000);
}

void RAINBOW_SHOW_COLORS()
{
     for(byte LED_NUMBER=0; LED_NUMBER<MAX_LEDS; LED_NUMBER++)       //loop cycles through the LEDs in the strip and updates the colors per LED
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
*/

// Reset of rainbow colors in case the rainbos is shown twice
A01L_RED = 0;
A01L_GREEN = 0;
A01L_BLUE = 0;

A01R_RED = 0;
A01R_GREEN = 0;
A01R_BLUE = 0;

A02L_RED = 0;
A02L_GREEN = 0;
A02L_BLUE = 0;

A02R_RED = 0;
A02R_GREEN = 0;
A02R_BLUE = 0;

A03L_RED = 0;
A03L_GREEN = 0;
A03L_BLUE = 0;

A03R_RED = 0;
A03R_GREEN = 0;
A03R_BLUE = 0;

A04L_RED = 0;
A04L_GREEN = 0;
A04L_BLUE = 0;

A04R_RED = 0;
A04R_GREEN = 0;
A04R_BLUE = 0;

A05L_RED = 0;
A05L_GREEN = 0;
A05L_BLUE = 0;

A05R_RED = 0;
A05R_GREEN = 0;
A05R_BLUE = 0;

  byte RAINBOW_WAIT = 0;

  // RUN UP 1
  for(byte INCREASE=0; INCREASE<58; INCREASE++)
  {
    A01L_RED = pow(1.1,INCREASE);
    RAINBOW_SHOW_COLORS();
    delay(RAINBOW_WAIT);
  }

  // RUN UP 2  
  for(byte INCREASE=0; INCREASE<58; INCREASE++)
  {
    A01L_GREEN = pow(1.1,INCREASE);
    A01R_RED = pow(1.1,INCREASE);
    
    RAINBOW_SHOW_COLORS();
    delay(RAINBOW_WAIT);
  }

  //RUN UP 3
  for(byte INCREASE=0; INCREASE<58; INCREASE++)
  {
    A01L_RED = 255-pow(1.1,INCREASE);
    A01R_GREEN = pow(1.1,INCREASE);
    A02L_RED = pow(1.1,INCREASE);
    
    RAINBOW_SHOW_COLORS();
    delay(RAINBOW_WAIT);
  }

  //RUN UP 4
  for(byte INCREASE=0; INCREASE<58; INCREASE++)
  {
    A01L_BLUE = pow(1.1,INCREASE);
    A01R_RED = 255-pow(1.1,INCREASE);
    A02L_GREEN = pow(1.1,INCREASE);
    A02R_RED = pow(1.1,INCREASE);
    
    RAINBOW_SHOW_COLORS();
    delay(RAINBOW_WAIT);
  }

  //RUN UP 5
  for(byte INCREASE=0; INCREASE<58; INCREASE++)
  {
    A01L_GREEN = 255-pow(1.1,INCREASE);
    A01R_BLUE = pow(1.1,INCREASE);
    A02L_RED = 255-pow(1.1,INCREASE);
    A02R_GREEN = pow(1.1,INCREASE);
    A03L_RED = pow(1.1,INCREASE);
    
    RAINBOW_SHOW_COLORS();
    delay(RAINBOW_WAIT);
  }


  //RUN UP 6
  for(byte INCREASE=0; INCREASE<58; INCREASE++)
  {
    A01L_RED = pow(1.1,INCREASE);
    A01R_GREEN = 255-pow(1.1,INCREASE);
    A02L_BLUE = pow(1.1,INCREASE);
    A02R_RED = 255-pow(1.1,INCREASE);
    A03L_GREEN = pow(1.1,INCREASE);
    A03R_RED = pow(1.1,INCREASE);
    
    RAINBOW_SHOW_COLORS();
    delay(RAINBOW_WAIT);
  }

  //RUN UP 7
  for(byte INCREASE=0; INCREASE<58; INCREASE++)
  {
    A01L_BLUE = 255-pow(1.1,INCREASE);
    A01R_RED = pow(1.1,INCREASE);
    A02L_GREEN = 255-pow(1.1,INCREASE);
    A02R_BLUE = pow(1.1,INCREASE);
    A03L_RED = 255-pow(1.1,INCREASE);
    A03R_GREEN = pow(1.1,INCREASE);
    A04L_RED = pow(1.1,INCREASE);
    
    RAINBOW_SHOW_COLORS();
    delay(RAINBOW_WAIT);
  }


  //RUN UP 8
  for(byte INCREASE=0; INCREASE<58; INCREASE++)
  {
    A01L_GREEN = pow(1.1,INCREASE);
    A01R_BLUE = 255-pow(1.1,INCREASE);
    A02L_RED = pow(1.1,INCREASE);
    A02R_GREEN = 255-pow(1.1,INCREASE);
    A03L_BLUE = pow(1.1,INCREASE);
    A03R_RED = 255-pow(1.1,INCREASE);
    A04L_GREEN = pow(1.1,INCREASE);
    A04R_RED = pow(1.1,INCREASE);
    
    RAINBOW_SHOW_COLORS();
    delay(RAINBOW_WAIT);
  }


  //RUN UP 9
  for(byte INCREASE=0; INCREASE<58; INCREASE++)
  {
    A01L_RED = 255-pow(1.1,INCREASE);
    A01R_GREEN = pow(1.1,INCREASE);
    A02L_BLUE = 255-pow(1.1,INCREASE);
    A02R_RED = pow(1.1,INCREASE);
    A03L_GREEN = 255-pow(1.1,INCREASE);
    A03R_BLUE = pow(1.1,INCREASE);
    A04L_RED = 255-pow(1.1,INCREASE);
    A04R_GREEN = pow(1.1,INCREASE);
    A05L_RED = pow(1.1,INCREASE);
    
    RAINBOW_SHOW_COLORS();
    delay(RAINBOW_WAIT);
  }


  //RUN UP 10
  for(byte INCREASE=0; INCREASE<58; INCREASE++)
  {
    A01L_BLUE = pow(1.1,INCREASE);
    A01R_RED = 255-pow(1.1,INCREASE);
    A02L_GREEN = pow(1.1,INCREASE);
    A02R_BLUE = 255-pow(1.1,INCREASE);
    A03L_RED = pow(1.1,INCREASE);
    A03R_GREEN = 255-pow(1.1,INCREASE);
    A04L_BLUE = pow(1.1,INCREASE);
    A04R_RED = 255-pow(1.1,INCREASE);
    A05L_GREEN = pow(1.1,INCREASE);
    A05R_RED = pow(1.1,INCREASE);
    
    RAINBOW_SHOW_COLORS();
    delay(RAINBOW_WAIT);
  }

  //RUN UP 11
  for(byte INCREASE=0; INCREASE<58; INCREASE++)
  {
    A01L_GREEN = 255-pow(1.1,INCREASE);
    A01R_BLUE = pow(1.1,INCREASE);
    A02L_RED = 255-pow(1.1,INCREASE);
    A02R_GREEN = pow(1.1,INCREASE);
    A03L_BLUE = 255-pow(1.1,INCREASE);
    A03R_RED = pow(1.1,INCREASE);
    A04L_GREEN = 255-pow(1.1,INCREASE);
    A04R_BLUE = pow(1.1,INCREASE);
    A05L_RED = 255-pow(1.1,INCREASE);
    A05R_GREEN = pow(1.1,INCREASE);
    
    RAINBOW_SHOW_COLORS();
    delay(RAINBOW_WAIT);
  }

  //RUN UP 12
  for(byte INCREASE=0; INCREASE<58; INCREASE++)
  {
    A01L_RED = pow(1.1,INCREASE);
    A01R_GREEN = 255-pow(1.1,INCREASE);
    A02L_BLUE = pow(1.1,INCREASE);
    A02R_RED = 255-pow(1.1,INCREASE);
    A03L_GREEN = pow(1.1,INCREASE);
    A03R_BLUE = 255-pow(1.1,INCREASE);
    A04L_RED = pow(1.1,INCREASE);
    A04R_GREEN = 255-pow(1.1,INCREASE);
    A05L_BLUE = pow(1.1,INCREASE);
    A05R_RED = 255-pow(1.1,INCREASE);
    
    RAINBOW_SHOW_COLORS();
    delay(RAINBOW_WAIT);
  }
/*
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
  
    delay(1000);
    
    SHOW_ALL_LEDS();
 */   
  // START OF RAINBOW LOOP
  for(byte LOOP=0; LOOP<5; LOOP++)
  {
   //LOOP part 1
    for(byte INCREASE=0; INCREASE<58; INCREASE++)
    {
      A01L_BLUE = 255-pow(1.1,INCREASE);
      A01R_RED = pow(1.1,INCREASE);
      A02L_GREEN = 255-pow(1.1,INCREASE);
      A02R_BLUE = pow(1.1,INCREASE);
      A03L_RED = 255-pow(1.1,INCREASE);
      A03R_GREEN = pow(1.1,INCREASE);
      A04L_BLUE = 255-pow(1.1,INCREASE);
      A04R_RED = pow(1.1,INCREASE);
      A05L_GREEN = 255-pow(1.1,INCREASE);
      A05R_BLUE = pow(1.1,INCREASE);
      
      RAINBOW_SHOW_COLORS();
      delay(RAINBOW_WAIT);
    }


    //LOOP part 2
    for(byte INCREASE=0; INCREASE<58; INCREASE++)
    {
    A01L_GREEN = pow(1.1,INCREASE);
    A01R_BLUE = 255-pow(1.1,INCREASE);
    A02L_RED = pow(1.1,INCREASE);
    A02R_GREEN = 255-pow(1.1,INCREASE);
    A03L_BLUE = pow(1.1,INCREASE);
    A03R_RED = 255-pow(1.1,INCREASE);
    A04L_GREEN = pow(1.1,INCREASE);
    A04R_BLUE = 255-pow(1.1,INCREASE);
    A05L_RED = pow(1.1,INCREASE);
    A05R_GREEN = 255-pow(1.1,INCREASE);
      
      RAINBOW_SHOW_COLORS();
      delay(RAINBOW_WAIT);
    }

   //LOOP part 3
    for(byte INCREASE=0; INCREASE<58; INCREASE++)
    {
    A01L_RED = 255-pow(1.1,INCREASE);
    A01R_GREEN = pow(1.1,INCREASE);
    A02L_BLUE = 255-pow(1.1,INCREASE);
    A02R_RED = pow(1.1,INCREASE);
    A03L_GREEN = 255-pow(1.1,INCREASE);
    A03R_BLUE = pow(1.1,INCREASE);
    A04L_RED = 255-pow(1.1,INCREASE);
    A04R_GREEN = pow(1.1,INCREASE);
    A05L_BLUE = 255-pow(1.1,INCREASE);
    A05R_RED = pow(1.1,INCREASE);
      
      RAINBOW_SHOW_COLORS();
      delay(RAINBOW_WAIT);
    }
  
    //LOOP part 4
    for(byte INCREASE=0; INCREASE<58; INCREASE++)
    {
    A01L_BLUE = pow(1.1,INCREASE);
    A01R_RED = 255-pow(1.1,INCREASE);
    A02L_GREEN = pow(1.1,INCREASE);
    A02R_BLUE = 255-pow(1.1,INCREASE);
    A03L_RED = pow(1.1,INCREASE);
    A03R_GREEN = 255-pow(1.1,INCREASE);
    A04L_BLUE = pow(1.1,INCREASE);
    A04R_RED = 255-pow(1.1,INCREASE);
    A05L_GREEN = pow(1.1,INCREASE);
    A05R_BLUE = 255-pow(1.1,INCREASE);
      
      RAINBOW_SHOW_COLORS();
      delay(RAINBOW_WAIT);
    }


    //LOOP part 5
    for(byte INCREASE=0; INCREASE<58; INCREASE++)
    {
    A01L_GREEN = 255-pow(1.1,INCREASE);
    A01R_BLUE = pow(1.1,INCREASE);
    A02L_RED = 255-pow(1.1,INCREASE);
    A02R_GREEN = pow(1.1,INCREASE);
    A03L_BLUE = 255-pow(1.1,INCREASE);
    A03R_RED = pow(1.1,INCREASE);
    A04L_GREEN = 255-pow(1.1,INCREASE);
    A04R_BLUE = pow(1.1,INCREASE);
    A05L_RED = 255-pow(1.1,INCREASE);
    A05R_GREEN = pow(1.1,INCREASE);
      
      RAINBOW_SHOW_COLORS();
      delay(RAINBOW_WAIT);
    }

    //LOOP part 6
    for(byte INCREASE=0; INCREASE<58; INCREASE++)
    {
      A01L_RED = pow(1.1,INCREASE);
      A01R_GREEN = 255-pow(1.1,INCREASE);
      A02L_BLUE = pow(1.1,INCREASE);
      A02R_RED = 255-pow(1.1,INCREASE);
      A03L_GREEN = pow(1.1,INCREASE);
      A03R_BLUE = 255-pow(1.1,INCREASE);
      A04L_RED = pow(1.1,INCREASE);
      A04R_GREEN = 255-pow(1.1,INCREASE);
      A05L_BLUE = pow(1.1,INCREASE);
      A05R_RED = 255-pow(1.1,INCREASE);
      
      RAINBOW_SHOW_COLORS();
      delay(RAINBOW_WAIT);
    }
  }

}
