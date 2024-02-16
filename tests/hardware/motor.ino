/**
 * Motor Shield Hardware Test
 *
 * This code demonstrates basic motor operations using a motor shield.
 * It configures control pins for two motors, allowing forward, backward, and stop actions.
 * Corresponding messages are printed to the Serial Monitor.
 *
 * Important: Ensure correct motor wiring to the shield and provide sufficient power.
 *
 * Note: Connect an external power source (e.g., battery) to the motor shield.
 * Use a motor driver (H-bridge) to interface motors with the Arduino for higher current.
 * Incorrect wiring or inadequate power may lead to unreliable performance or Arduino damage.
 *
 * ---
 * 
 * Teste de hardware da blindagem do motor
 *
 * Este código demonstra as operações básicas do motor usando uma blindagem do motor.
 * Configura pinos de controle para dois motores, permitindo ações de avanço, retrocesso e parada.
 * As mensagens correspondentes são impressas no Monitor Serial.
 *
 * Importante: Garanta a fiação correta do motor na blindagem e forneça energia suficiente.
 *
 * Nota: Conecte uma fonte de alimentação externa (por exemplo, bateria) à blindagem do motor.
 * Use um driver de motor (ponte H) para fazer a interface dos motores com o Arduino para obter corrente mais alta.
 * Fiação incorreta ou alimentação inadequada pode levar a um desempenho não confiável ou danos ao Arduino.
 */

// Motor Shield pins (Motor 1)
const int PIN_IN1_MOTOR1 = 5;
const int PIN_IN2_MOTOR1 = 6;

// Motor Shield pins (Motor 2)
const int PIN_IN1_MOTOR2 = 10;
const int PIN_IN2_MOTOR2 = 11;

void setup()
{
  Serial.begin(9600);
  Serial.println("Motor hardware test");

  // Configure motor control pins
  pinMode(PIN_IN1_MOTOR1, OUTPUT);
  pinMode(PIN_IN2_MOTOR1, OUTPUT);
  pinMode(PIN_IN1_MOTOR2, OUTPUT);
  pinMode(PIN_IN2_MOTOR2, OUTPUT);
}

void loop()
{
  Serial.println("Motor 1 frente");
  digitalWrite(PIN_IN1_MOTOR1, HIGH);
  digitalWrite(PIN_IN2_MOTOR1, LOW);
  delay(2000);

  Serial.println("Motor 1 trás");
  digitalWrite(PIN_IN1_MOTOR1, LOW);
  digitalWrite(PIN_IN2_MOTOR1, HIGH);
  delay(2000);

  Serial.println("Motor 1 parada");
  digitalWrite(PIN_IN1_MOTOR1, LOW);
  digitalWrite(PIN_IN2_MOTOR1, LOW);
  delay(100);

  Serial.println("Motor 2 frente");
  digitalWrite(PIN_IN1_MOTOR2, HIGH);
  digitalWrite(PIN_IN2_MOTOR2, LOW);
  delay(2000);

  Serial.println("Motor 2 trás");
  digitalWrite(PIN_IN1_MOTOR2, LOW);
  digitalWrite(PIN_IN2_MOTOR2, HIGH);
  delay(2000);

  Serial.println("Motor 2 parada");
  digitalWrite(PIN_IN1_MOTOR2, LOW);
  digitalWrite(PIN_IN2_MOTOR2, LOW);
  delay(100);
}
