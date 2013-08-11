// color temp to rgb based on http://www.tannerhelland.com/4435/convert-temperature-rgb-algorithm-code/

#include <Adafruit_NeoPixel.h>

#define PIN 0

Adafruit_NeoPixel strip = Adafruit_NeoPixel(16,PIN,NEO_GRB + NEO_KHZ800);

int brightness = 0;

void setup(){
  strip.begin();
  strip.show();
}

void loop(){
  
  colorAll(strip.Color(0,0,0));
  strip.show();
  
  delay(10000);
  
  colorQuad(tempToRGB(2000),1);
  strip.show();
  
  delay(10000);
  
  //colorAll(tempToRGB(2000));
  colorQuad(tempToRGB(2000),2);
  strip.show();
  
  delay(10000);
  
  colorQuad(tempToRGB(2000),3);
  strip.show();
  
  delay(10000);
  
  /*
  if(brightness > 254){
    brightness = 0;
  }
  
  strip.setBrightness(brightness);
  colorAll(strip.Color(128,128,128));
  
  //strip.setPixelColor(1,strip.Color(255,0,0));
  //strip.setPixelColor(1,(255,0,0));
  //strip.setBrightness(brightness);
  //strip.show();
  
  brightness++;
  */
}

void colorAll(uint32_t c) {
  for(uint16_t i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, c);
      strip.show();
      //delay(wait);
  }
}

void colorQuad(uint32_t c, int q) {
  
  colorAll(strip.Color(0,0,0));
  
  for(uint16_t i=0; i<(strip.numPixels()/q); i++) {
      strip.setPixelColor(i, c);
      strip.show();
      //delay(wait);
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
  
  return strip.Color(red, green, blue);
}

