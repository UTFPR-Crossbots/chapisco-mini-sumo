

void setup()
{
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial)
  {
    ; // wait for serial port to connect. Needed for native USB port only
  }
}

void loop()
{

  Serial.println("Data from port one:");
  // while there is data coming in, read it
  // and send to the hardware serial port:
  while (Serial.available() > 0)
  {
    char inByte = Serial.read();
    Serial.write(inByte);
  }

  // blank line to separate data from the two ports:
  Serial.println();
}
