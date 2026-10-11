#include <DHT.h>
#include <ESP32Servo.h>
  const int DHTPIN = 4; 
  const int DHTTYPE = DHT11;
  const int soilPin = 33;
  const int dry = 3100;
  const int wet = 1750; 

  DHT dht(DHTPIN, DHT11);
  Servo myservo;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  dht.begin();
  myservo.attach(18);
  myservo.write(0);

}

void loop() {
  // put your main code here, to run repeatedly:
  //detect air 
  float humidity =dht.readHumidity();
  float temperature = dht.readTemperature();
  
  Serial.println(String("air humidity: ") + humidity);
  //Serial.println(String("temperature: ") + temperature);

  //detect soil
  int moisture = analogRead(soilPin);
  Serial.println(String("soil humidity: ") + moisture);
  float percent = map(moisture, dry, wet, 0, 100);

  Serial.println(percent + String("% moisture"));

  if(humidity<50){
    Serial.println(String("humid!"));
    myservo.write(90);
    delay(1000);
    myservo.write(0);
  }

  delay(2000);
}
