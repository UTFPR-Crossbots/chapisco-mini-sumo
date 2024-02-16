/**
 * VL53L0X Three-Sensor Distance Sensor Test
 *
 * This code continuously reads three VL53L0X distance sensors.
 * Make sure you power the sensors and connect them correctly to the Arduino Nano's SDA and SCL pins.
 *
 * ---
 *
 * Teste do Sensor de Distância com Três Sensores VL53L0X
 *
 * Este código realiza a leitura contínua de três sensores de distância VL53L0X.
 * Certifique-se de alimentar os sensores e conectá-los corretamente aos pinos SDA e SCL do Arduino Nano.
 */

#include <Wire.h> // Wire Built-In by Arduino Version 1.0.0
#include <VL53L0X.h> // VL53L0X by Pololu Version 1.3.1

VL53L0X sensor_01;
VL53L0X sensor_02;
VL53L0X sensor_03;

const int sensor_01_shutdown_pin = 6;
const int sensor_02_shutdown_pin = 5;
const int sensor_03_shutdown_pin = 7;

void setup()
{
  pinMode(sensor_01_shutdown_pin, OUTPUT);
  pinMode(sensor_02_shutdown_pin, OUTPUT);
  pinMode(sensor_03_shutdown_pin, OUTPUT);

  digitalWrite(sensor_01_shutdown_pin, LOW);
  digitalWrite(sensor_02_shutdown_pin, LOW);
  digitalWrite(sensor_03_shutdown_pin, LOW);

  delay(500);

  Wire.begin();
  Serial.begin(9600);

  // Initialising Sensor 01
  digitalWrite(sensor_01_shutdown_pin, HIGH);
  delay(150);
  Serial.println("Inicializando sensor_01");
  sensor_01.init(true);
  sensor_01.setAddress(0x01);
  digitalWrite(sensor_01_shutdown_pin, LOW);

  // Initialising Sensor 02
  digitalWrite(sensor_02_shutdown_pin, HIGH);
  delay(150);
  Serial.println("Inicializando sensor_02");
  sensor_02.init(true);
  sensor_02.setAddress(0x02);
  digitalWrite(sensor_02_shutdown_pin, LOW);

  // Initialising Sensor 03
  digitalWrite(sensor_03_shutdown_pin, HIGH);
  delay(150);
  Serial.println("Inicializando sensor_03");
  sensor_03.init(true);
  sensor_03.setAddress(0x03);
  digitalWrite(sensor_03_shutdown_pin, LOW);

  Serial.println("Endereços dos sensores definidos");

  // Starting continuous readings
  sensor_01.startContinuous();
  sensor_02.startContinuous();
  sensor_03.startContinuous();
}

void loop()
{
  int distance_01 = sensor_01.readRangeContinuousMillimeters();
  int distance_02 = sensor_02.readRangeContinuousMillimeters();
  int distance_03 = sensor_03.readRangeContinuousMillimeters();

  // 01: 00000 mm | 02: 00000 mm | 03: 00000 mm
  
  Serial.print("01: ");
  Serial.print(String(distance_01, 5));
  Serial.print(" mm | 02: ");
  Serial.print(String(distance_02, 5));
  Serial.print(" mm | 03: ");
  Serial.print(String(distance_03, 5));
  Serial.println(" mm");

  delay(1000);
}
