#include <NTPClient.h>
// change next line to use with another board/shield
#include <ESP8266WiFi.h>

#include <WiFiUdp.h>
#include <Adafruit_NeoPixel.h>

#define PIN    12
#define N_LEDS 61
int red = 0;
int blue = 0;
int green = 0;
int numpix = 0;
int prevpix = 0;
int maxint = 0;
int prevmaxint = 0;
const unsigned long SECOND = 1000;
uint32_t c;
uint32_t d;
Adafruit_NeoPixel strip = Adafruit_NeoPixel(N_LEDS, PIN, NEO_GRB + NEO_KHZ800);


const String ssid = "TurboKombi";
const String password = "Jakuboslaw";

int t = 0, tH = 0, tM = 0;
int hour = 3600; //hour in seconds



void sweetDreams() {
 for (int i=0;i>118;i++){
 delay (SECOND);
 }
}



void mrygu() {
  red = random(200);
  blue = random(200);
  green = random(200);
  c = strip.Color(red, green, blue);
  d = strip.Color(green, blue, red);
  numpix = random(61); //losowanie numeru piksela
  maxint = random(25); //liczba zapalanych pikseli
  strip.fill( c, numpix, numpix + maxint); // Draw new pixel
  strip.fill(d, prevpix, prevpix + prevmaxint); //gaszenie poprzedinch pikseli
  delay(random(1000));
  strip.show();
  prevpix = numpix;
  prevmaxint = maxint;
}
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "europe.pool.ntp.org", hour, 60000);

int whatTime() {
  timeClient.update();
  tH = (timeClient.getHours())+1;
  tM = timeClient.getMinutes();
  t = (tH * 100) + tM;
  return t;
}

void setup() {
  Serial.begin(115200);
    WiFi.begin(ssid, password);
  WiFi.mode(WIFI_STA);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
    // Print local IP address and start web server
  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  }

  timeClient.begin();
  strip.begin();
}

void loop() {
  //check on time

  t = whatTime();
  Serial.print("It's:");
    Serial.println(t);

  // check if it should be on or off
  if (t > 2025 and t < 2318) { //hours in format HHMM

    mrygu();
    strip.clear();
    delay(5);
    Serial.println("TV on");
  }
  else {
    strip.fill( 0, 0, 61);
    strip.show();
    Serial.println("I am going to sleep");
    sweetDreams();
  }
}
