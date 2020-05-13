
#include <SPI.h>
#include <Ethernet.h>
#include <PubSubClient.h> 

// Enter a MAC address and IP address for your controller below.
byte mac[] = {0x90, 0xA2, 0xDA, 0x0D, 0x48, 0xD3 };

// The IP address will be dependent on your local network:
// assign an IP address for the controller:

IPAddress ip(192,168,1,20);
IPAddress gateway(192,168,1,1);
IPAddress subnet(255, 255, 255, 0);

// Initialize the Ethernet server library with the port you want to use.
EthernetServer server(80);
PubSubClient client(wifiClient);

#define THING_NAME "ameba"

char mqttServer[]           = "a5hf2nl3pzd0j.iot.us-east-1.amazonaws.com";
char clientId[]             = "amebaClient";
char publishUpdateTopic[]   = "$aws/things/" THING_NAME "/shadow/update";
char publishGetTopic[]      = "$aws/things/" THING_NAME "/shadow/get";
char publishPayload[MQTT_MAX_PACKET_SIZE];
char *subscribeTopic[5] = {
  "$aws/things/" THING_NAME "/shadow/update/accepted",
  "$aws/things/" THING_NAME "/shadow/update/rejected",
  "$aws/things/" THING_NAME "/shadow/update/delta",
  "$aws/things/" THING_NAME "/shadow/get/accepted",
  "$aws/things/" THING_NAME "/shadow/get/rejected"
};

/* root CA can be download here:
 *  https://www.symantec.com/content/en/us/enterprise/verisign/roots/VeriSign-Class%203-Public-Primary-Certification-Authority-G5.pem
 **/
char* rootCABuff = \
"-----BEGIN CERTIFICATE-----\n" \
"MIIE0zCCA7ugAwIBAgIQGNrRniZ96LtKIVjNzGs7SjANBgkqhkiG9w0BAQUFADCB\n" \
"yjELMAkGA1UEBhMCVVMxFzAVBgNVBAoTDlZlcmlTaWduLCBJbmMuMR8wHQYDVQQL\n" \
"ExZWZXJpU2lnbiBUcnVzdCBOZXR3b3JrMTowOAYDVQQLEzEoYykgMjAwNiBWZXJp\n" \
"U2lnbiwgSW5jLiAtIEZvciBhdXRob3JpemVkIHVzZSBvbmx5MUUwQwYDVQQDEzxW\n" \
"ZXJpU2lnbiBDbGFzcyAzIFB1YmxpYyBQcmltYXJ5IENlcnRpZmljYXRpb24gQXV0\n" \
"aG9yaXR5IC0gRzUwHhcNMDYxMTA4MDAwMDAwWhcNMzYwNzE2MjM1OTU5WjCByjEL\n" \
"MAkGA1UEBhMCVVMxFzAVBgNVBAoTDlZlcmlTaWduLCBJbmMuMR8wHQYDVQQLExZW\n" \
"ZXJpU2lnbiBUcnVzdCBOZXR3b3JrMTowOAYDVQQLEzEoYykgMjAwNiBWZXJpU2ln\n" \
"biwgSW5jLiAtIEZvciBhdXRob3JpemVkIHVzZSBvbmx5MUUwQwYDVQQDEzxWZXJp\n" \
"U2lnbiBDbGFzcyAzIFB1YmxpYyBQcmltYXJ5IENlcnRpZmljYXRpb24gQXV0aG9y\n" \
"aXR5IC0gRzUwggEiMA0GCSqGSIb3DQEBAQUAA4IBDwAwggEKAoIBAQCvJAgIKXo1\n" \
"nmAMqudLO07cfLw8RRy7K+D+KQL5VwijZIUVJ/XxrcgxiV0i6CqqpkKzj/i5Vbex\n" \
"t0uz/o9+B1fs70PbZmIVYc9gDaTY3vjgw2IIPVQT60nKWVSFJuUrjxuf6/WhkcIz\n" \
"SdhDY2pSS9KP6HBRTdGJaXvHcPaz3BJ023tdS1bTlr8Vd6Gw9KIl8q8ckmcY5fQG\n" \
"BO+QueQA5N06tRn/Arr0PO7gi+s3i+z016zy9vA9r911kTMZHRxAy3QkGSGT2RT+\n" \
"rCpSx4/VBEnkjWNHiDxpg8v+R70rfk/Fla4OndTRQ8Bnc+MUCH7lP59zuDMKz10/\n" \
"NIeWiu5T6CUVAgMBAAGjgbIwga8wDwYDVR0TAQH/BAUwAwEB/zAOBgNVHQ8BAf8E\n" \
"BAMCAQYwbQYIKwYBBQUHAQwEYTBfoV2gWzBZMFcwVRYJaW1hZ2UvZ2lmMCEwHzAH\n" \
"BgUrDgMCGgQUj+XTGoasjY5rw8+AatRIGCx7GS4wJRYjaHR0cDovL2xvZ28udmVy\n" \
"aXNpZ24uY29tL3ZzbG9nby5naWYwHQYDVR0OBBYEFH/TZafC3ey78DAJ80M5+gKv\n" \
"MzEzMA0GCSqGSIb3DQEBBQUAA4IBAQCTJEowX2LP2BqYLz3q3JktvXf2pXkiOOzE\n" \
"p6B4Eq1iDkVwZMXnl2YtmAl+X6/WzChl8gGqCBpH3vn5fJJaCGkgDdk+bW48DW7Y\n" \
"5gaRQBi5+MHt39tBquCWIMnNZBU4gcmU7qKEKQsTb47bDN0lAtukixlE0kF6BWlK\n" \
"WE9gyn6CagsCqiUXObXbf+eEZSqVir2G3l6BFoMtEMze/aiCKm0oHw0LxOXnGiYZ\n" \
"4fQRbxC1lfznQgUy286dUV4otp6F01vvpX1FQHKOtw5rDgb7MzVIcbidJ4vEZV8N\n" \
"hnacRHr2lVz2XTIIM6RUthg/aFzyQkqFOFSDX9HoLPKsEdao7WNq\n" \
"-----END CERTIFICATE-----\n";

/* Fill your certificate.pem.crt wiht LINE ENDING */
char* certificateBuff = \
"-----BEGIN CERTIFICATE-----\n" \
"MIIDWjCCAkKgAwIBAgIVAKTirJo7z28/jsXVzJrNwmqZ6GiPMA0GCSqGSIb3DQEB\n" \
"CwUAME0xSzBJBgNVBAsMQkFtYXpvbiBXZWIgU2VydmljZXMgTz1BbWF6b24uY29t\n" \
"IEluYy4gTD1TZWF0dGxlIFNUPVdhc2hpbmd0b24gQz1VUzAeFw0xNjExMDIyMTM5\n" \
"NDhaFw00OTEyMzEyMzU5NTlaMB4xHDAaBgNVBAMME0FXUyBJb1QgQ2VydGlmaWNh\n" \
"dGUwggEiMA0GCSqGSIb3DQEBAQUAA4IBDwAwggEKAoIBAQCO6j+3R2XUlqSYZS3u\n" \
"fIiucZl+00lkGcxwr6MQE3thIeRAby3Wx2uBFHusQ2qXJCoxfVi56hr5mXnV4YOA\n" \
"xg+RX/PIOpK9WKQNaK7lPLQmW5vXVTznRXcwMJVQ0hq0IA9WnWsoZKsCwbwviPiG\n" \
"b/YqgSUyzDoTmWZC8YlSi3jdIbPrkkh3x/zZGEk8v7C0l/ZGXx+YzimOskbJ644o\n" \
"5YJPq4nA5A6y2TgGwgQKtD3d3SbTHYhODl/IkrB+5kCD/2rwZJJ+2m41pzgOKSEV\n" \
"3/ovoZty5RSJE6oQNyA/MkUjnqh0DQKX+xgc/SWovMX6NuG6VywNtvv948k7Rgz1\n" \
"vV3FAgMBAAGjYDBeMB8GA1UdIwQYMBaAFM8sMXvGVg3iqaNXqIcoUVP3dMFPMB0G\n" \
"A1UdDgQWBBR4N3G1NLSNYpd5Qss/xCN2Kz/5TjAMBgNVHRMBAf8EAjAAMA4GA1Ud\n" \
"DwEB/wQEAwIHgDANBgkqhkiG9w0BAQsFAAOCAQEAhYxw2REowkD+m9Co3Z0kzIoo\n" \
"2evr8WhJh+kBMBIEFaf8eBZG8RXx+vTKIokGSGS5u57sFBlJZ4M6GWFLlD+S4T8r\n" \
"VdAccRQTWMUnaJR8BWNr3Zo3AKRi5mzYk2C0Z3i7Ypomme21+dwOZGUiwpMYh5qg\n" \
"JbpmfAFcpW9KxUEVCxKvzZZ++k/rfmhN1i4Y/SaW+aHimwV0E8DrICntRu2lyRzX\n" \
"SZoB3LgfDoHvszTCJCLltDtZ3rCfxHZdMHnZLbZZ/kE4O5pYokJBbxKIQ7zxc6e6\n" \
"jw3zDSD28yM2COCBaavp0gXvjxMiNUSxfulP1gykJp0nVmOrOqE9LTn0XRnS3A==\n" \
"-----END CERTIFICATE-----\n";

/* Fill your private.pem.key wiht LINE ENDING */
char* privateKeyBuff = \
"-----BEGIN RSA PRIVATE KEY-----\n" \
"MIIEowIBAAKCAQEAjuo/t0dl1JakmGUt7nyIrnGZftNJZBnMcK+jEBN7YSHkQG8t\n" \
"1sdrgRR7rENqlyQqMX1Yueoa+Zl51eGDgMYPkV/zyDqSvVikDWiu5Ty0Jlub11U8\n" \
"50V3MDCVUNIatCAPVp1rKGSrAsG8L4j4hm/2KoElMsw6E5lmQvGJUot43SGz65JI\n" \
"d8f82RhJPL+wtJf2Rl8fmM4pjrJGyeuOKOWCT6uJwOQOstk4BsIECrQ93d0m0x2I\n" \
"Tg5fyJKwfuZAg/9q8GSSftpuNac4DikhFd/6L6GbcuUUiROqEDcgPzJFI56odA0C\n" \
"l/sYHP0lqLzF+jbhulcsDbb7/ePJO0YM9b1dxQIDAQABAoIBAEQGJ5G7QDLyCSIo\n" \
"drZfPEeb9q2xL+ufg/nW/8x1GXLgSN6KjM0AWqEz+LHD3QZXxmWL/iFv1qsbbCxr\n" \
"jMZMf7h4bXbOum25tUxUmXqvbCgdzo2uGrESFWswlMHFX8SAxgw6HXk6gVNsl4Ag\n" \
"t/p1bDxLAEOvha0yhMQ0Z2KM1FicLPpMKZohTKQNwuWKKFacpIOUooGsnsog28oO\n" \
"vHlaXTSUKyXPuG4zwXnrRJ27gYCyLSkO6vuwgI6G1CCPCTvIUfbkXtsKCIlZE31g\n" \
"ejzgaa8LrGMalFgnmTI9zwh5A/HT4MyaKGo43HDf6M1ESq234fZzkFKak2GwvKXl\n" \
"1GNiv8ECgYEA1R0sXBpGzYdmdfL4IyFyi7ZlHEwXBCmDVOhzLc04WgrVfuhcmHlO\n" \
"cnpd+pPIRDelukCRWlvnD8KxcSNhFjtQoclQCEfxSHAt2pNAYwkoJXFW8wbYt3PX\n" \
"YSDPkzZFB2Iq6P++N8fgk5vsQIuLYNMO6dpNna5Uyy47ibexpOQ/4b0CgYEAq6yx\n" \
"Kcgmzmc5yUghJ6QkdH2d8wgMgihf4+v8pdGmLVEFHkeK10tZXrRiV40lAG0mUpA/\n" \
"wh8INQfnXUSMWx+evEp/ZK6OpcB4nqM8t3C8cEgBZKDXocAqTRbOCs78qpo98IbI\n" \
"C9LEvFQOuybVxqHTS0kN4gfHHerJoVUs0bHwOKkCgYAiszhY2tJyfrx5MhGjLrwG\n" \
"8bDu9Zi9zcCbn6m5aHPnfWIb4tvI29+hFjmdJljyepkahY7lRpeN4magBGG3i/rq\n" \
"DOxiHMy1vcZJk7ZlKcWGqzi8I35ACLWmFACYeLqupBZWj+W6EWqIvleufso3/sWr\n" \
"4CbJKOyXlLSPDQD4101rhQKBgQCCpIOZyTAG6LUoANUCRr5bS/D0Lo7eSf1XBJIa\n" \
"WiW83Kgpd8YnuraDBIDGIaoj3exI7m8mudjUCnS+HFk3SyPQJF038EKrzoG8L3sY\n" \
"Ghm81H8C5gfSlttaGN2pigTriz9RmDAKF1YR/2HKeG48n4+c/jYraUHU+YSBWsEl\n" \
"vuSRKQKBgEQ5pKPX8Bc0Bkoc/sL8LzhSZmU7yxpxQF082J03OOeJhoEXKJoAmJ8c\n" \
"/S9lGZs6elX/Y1Ar6saeqpD2sRjr35iMo5IM/wVSBeL6HIjBQkhnY5YzFXEc2hfe\n" \
"DhrCpIRp59qK08lXhHjdgX3hy9goPMKsSZsX0lWbQ6QI/eCpiRYy\n" \
"-----END RSA PRIVATE KEY-----\n";

int led_pin = 10;
int led_state = 1;

void updateLedState(int desired_led_state) {
  printf("change led_state to %d\r\n", desired_led_state);
  led_state = desired_led_state;
  digitalWrite(led_pin, led_state);

  sprintf(publishPayload, "{\"state\":{\"reported\":{\"led\":%d}},\"clientToken\":\"%s\"}",
    led_state,
    clientId
  );
  printf("Publish [%s] %s\r\n", publishUpdateTopic, publishPayload);
  client.publish(publishUpdateTopic, publishPayload);
}

void checkLedState() {
  printf("try to get led_state\r\n");
  
  sprintf(publishPayload, "{\"state\":{\"reported\":{\"led\":%d}},\"clientToken\":\"%s\"}",
    led_state,
    clientId
  );
  printf("Publish [%s] %s\r\n", publishGetTopic, publishPayload);
  client.publish(publishGetTopic, publishPayload);

  // After publish "get" command AWS IoT would send "get/accepted" message and we can check led state in callback
}

void callback(char* topic, byte* payload, unsigned int length) {
  char buf[MQTT_MAX_PACKET_SIZE];
  char *pch;
  int desired_led_state;

  strncpy(buf, (const char *)payload, length);
  buf[length] = '\0';
  printf("Message arrived [%s] %s\r\n", topic, buf);

  if ((strstr(topic, "/shadow/update/accepted") != NULL) || (strstr(topic, "/shadow/get/accepted") != NULL)) {
    // payload format: {"state":{"reported":{"led":1},"desired":{"led":0}},"metadata":{"reported":{"led":{"timestamp":1466996558}},"desired":{"led":{"timestamp":1466996558}}},"version":7,"timestamp":1466996558}
    pch = strstr(buf, "\"desired\":{\"led\":");
    if (pch != NULL) {
      pch += strlen("\"desired\":{\"led\":");
      desired_led_state = *pch - '0';
      if (desired_led_state != led_state) {
        updateLedState(desired_led_state);
      }
    }
  }
}

void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    // Attempt to connect
    if (client.connect(clientId)) {
      Serial.println("connected");

      for (int i=0; i<5; i++) {
        printf("subscribe [%s]\r\n", subscribeTopic[i]);
        client.subscribe(subscribeTopic[i]);
      }

      checkLedState();
      updateLedState(led_state);

    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}

void setup()
{
  pinMode(led_pin, OUTPUT);
  digitalWrite(led_pin, led_state);

  while (status != WL_CONNECTED) {
    Serial.print("Attempting to connect to SSID: ");
    Serial.println(ssid);
    // Connect to WPA/WPA2 network. Change this line if using open or WEP network:
    status = WiFi.begin(ssid, pass);
    if (status == WL_CONNECTED) break;
    // retry after 1 second
    delay(1000);
  }

  wifiClient.setRootCA((unsigned char*)rootCABuff);
  wifiClient.setClientCertificate((unsigned char*)certificateBuff, (unsigned char*)privateKeyBuff);

  client.setServer(mqttServer, 8883);
  client.setCallback(callback);

  // For publish qos1 that server will send ack
  client.setPublishQos(MQTTQOS1);

  // For subscribe or publish, wait ack can keep command sequence in order
  client.waitForAck(true);

  // Allow the hardware to sort itself out
  delay(1500);
}

void loop()
{
  if (!client.connected()) {
    reconnect();
  }
  client.loop();
}
