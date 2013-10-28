#include <Adafruit_NeoPixel.h>

#define PIN 6

Adafruit_NeoPixel ring = Adafruit_NeoPixel(16, PIN, NEO_GRB + NEO_KHZ800);
int current_brightness = 0;
int current_temperature = 0;

void setup(){
  ring.begin();
  ring.show();
  Serial.begin(9600);
}

void loop(){
  
  while(Serial.available() > 0){
    int in_brightness = Serial.parseInt();
    int in_temperature = Serial.parseInt();
    
    if(Serial.read() == '\n'){
      current_brightness = in_brightness;
      current_temperature = in_temperature;
    }
  }
  
  ring.setBrightness(current_brightness);
  colorAll(tempToRGB(current_temperature));
}


void colorAll(uint32_t c) {
  for(uint16_t i=0; i<ring.numPixels(); i++) {
      ring.setPixelColor(i, c);
      ring.show();
  }
}


float tempToRGB(int t){
 
  float temp = t / 100;
  float red = 0;
  float green = 0;
  float blue = 0;
 
 
  if(temp <= 66){
    red = 255;
  } else {
    red = temp - 60;
    red = 329.698727446 * pow(red, -0.1332047592);
   
    if(red < 0)
      red = 0;   
   
    if(red > 255)
      red = 255;   
  }
 
  // calc green
 
  if(temp <= 66){
    green = temp;
    green = 99.4708025861 * log(green) - 161.1195681661;
  }else{
    green = temp - 60;
    green = 288.1221695283 * pow(green, -0.0755148492);
  }
 
    if(green < 0)
      green = 0;
     
    if(green > 255)
      green = 255;
     
  // calc blue
  if(temp >= 66){
    blue = 255;
  } else {
    if(temp <= 19){
      blue = 0;
    } else {
      blue = temp - 10;
      blue = 138.5177312231 * log(blue) - 305.0447927307;
     
      if(blue < 0)
        blue = 0;
       
      if(blue > 255)
        blue = 255;
    }
  }
 
  return ring.Color(red, green, blue);
} 
