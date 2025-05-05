#include <LiquidCrystal_I2C.h>
#include <DFRobot_DHT11.h>

DFRobot_DHT11 DHT;
LiquidCrystal_I2C lcd(0x27,16,2);

#define DHT11_PIN 7
int Hum;
int Temp;

#define CO2_Sensor A2
int CO2;

#define obstaclepin 3
int hasObstacle = HIGH;
#define LEDpin 4

#define SoilSensor A0
int SoilSensorValue;

#define Water_Sensor A1
int water_val;
#define Buzzer_Pin 2

#define LDR_PIN 10
int LDR_val = 0;
#define LDR_Lamp 9

void setup() {
  // put your setup code here, to run once:
  lcd.init();
  lcd.clear();
  lcd.backlight();
  Serial.begin(9600);

  pinMode(SoilSensor, INPUT);
  pinMode(CO2_Sensor,INPUT);
  pinMode(LDR_PIN, INPUT);
  pinMode(LDR_Lamp, OUTPUT);
  pinMode(Water_Sensor, INPUT);
  pinMode(Buzzer_Pin, OUTPUT);
  pinMode(obstaclepin, INPUT);
  pinMode(LEDpin,OUTPUT);
  
}

void loop() {
  DHT.read(DHT11_PIN);
  Temp = DHT.temperature;
  Hum = DHT.humidity;
  CO2 = analogRead(CO2_Sensor);
  SoilSensorValue = analogRead(SoilSensor);
  water_val = analogRead(Water_Sensor);
  LDR_val = digitalRead(LDR_PIN);
  hasObstacle= digitalRead(obstaclepin);

  if(hasObstacle==LOW){
  digitalWrite(LEDpin,HIGH);
    delay(100);
  }
  else{
  digitalWrite(LEDpin,LOW);
  }
  if (LDR_val==1){
  digitalWrite(LDR_Lamp, HIGH) ;
  delay (100) ;
  }
  else{
  digitalWrite (LDR_Lamp, LOW) ;
  }
  if (water_val > 400){
    digitalWrite(Buzzer_Pin, HIGH) ;
    delay (200) ;
  }
  else{
    digitalWrite(Buzzer_Pin, LOW) ;
  }
  Serial.print("Temperature: ");
  Serial.println(Temp);
  Serial.print("Humidity: ");
  Serial.println(Hum);
  Serial.print("CO2: ");
  Serial.println(CO2);
  Serial.print("Moisture Sensor Value: ");
  Serial.println(SoilSensorValue);
  Serial.print("Water Level: ");
  Serial.println(water_val);
  Serial.print("LDR Sensor: ");
  Serial.println(LDR_val);
  Serial.print("Motion Sensor: ");
  Serial.println(hasObstacle);
  Serial.println("**************************************************");
  
lcd.setCursor(0, 0);
lcd.print("Temp: ");
lcd.print(Temp);
lcd.setCursor(0, 1);
lcd.print("Hum: ");
lcd.print(Hum);
lcd.setCursor(9, 1);
lcd.print("CO2: ");
lcd.setCursor(13, 1);
lcd.print(CO2);
delay(2000);
lcd.clear();

lcd.setCursor(0, 0);
lcd.print("Moisture: ");

lcd.print(SoilSensorValue);
lcd.setCursor (0, 1);
lcd.print("Water Level: ");
lcd.print(water_val) ;
delay(2000);
lcd.clear();

lcd.setCursor(0, 0);
lcd.print("LDR Sensor ");
lcd.setCursor (12, 0);
lcd.print(LDR_val);
lcd.setCursor(0, 1);
lcd.print("Motion_Sensor ");
lcd.print(hasObstacle);
delay(2000);
lcd.clear();
}
