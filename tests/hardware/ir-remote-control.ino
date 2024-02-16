/**
 * IR Remote Control Test
 *
 * This code sets up an IR receiver to capture remote control commands.
 * It prints the received command values to the Serial Monitor.
 *
 * Important: Connect the IR receiver to a pin that supports interrupt (e.g., D2 or D3).
 * Check your Arduino model's documentation to ensure the chosen pin supports interrupt.
 * https://www.arduino.cc/reference/en/language/functions/external-interrupts/attachinterrupt/
 *
 * ---
 *
 * Teste de controle remoto IR
 *
 * Este código configura um receptor IR para capturar comandos de controle remoto.
 * Ele imprime os valores dos comandos recebidos no Monitor Serial.
 *
 * Importante: Conecte o receptor IR a um pino que suporte interrupção (por exemplo, D2 ou D3).
 * Verifique a documentação do seu modelo de Arduino para garantir que o pino escolhido suporte interrupção.
 * https://www.arduino.cc/reference/en/language/functions/external-interrupts/attachinterrupt/
 *
 */

#include <IRremote.h> // IRremote by shirriff Version 4.2.1

const int IR_RECEIVER_PIN = 2;

IRrecv irReceiver(IR_RECEIVER_PIN);
decode_results receivedIRCommand;

void setup()
{
  Serial.begin(9600);
  irReceiver.enableIRIn();
}

void loop()
{
  if (irReceiver.decode(&receivedIRCommand))
  {
    Serial.print("Received command: ");
    Serial.println(receivedIRCommand.value);
    irReceiver.resume();
    delay(200); // Add a delay to avoid repeated readings
  }
}
