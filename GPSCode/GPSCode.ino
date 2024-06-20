#include <SoftwareSerial.h>
#include <TinyGPS.h>

TinyGPS gps;
SoftwareSerial ss(4, 3); // RX, TX

void setup()
{
  Serial.begin(115200);
  ss.begin(9600); // Ajusta esta velocidad si es necesario
  Serial.println("GPS6MU2 Test");
}

void loop()
{
  while (ss.available() > 0)
  {
    char c = ss.read();
    Serial.write(c); // Imprimir los datos en bruto
    if (gps.encode(c)) {
      float flat, flon;
      unsigned long age;
      gps.f_get_position(&flat, &flon, &age);
      Serial.print("LAT=");
      Serial.print(flat == TinyGPS::GPS_INVALID_F_ANGLE ? 0.0 : flat, 6);
      Serial.print(" LON=");
      Serial.print(flon == TinyGPS::GPS_INVALID_F_ANGLE ? 0.0 : flon, 6);
      Serial.print(" SAT=");
      Serial.print(gps.satellites() == TinyGPS::GPS_INVALID_SATELLITES ? 0 : gps.satellites());
      Serial.print(" PREC=");
      Serial.print(gps.hdop() == TinyGPS::GPS_INVALID_HDOP ? 0 : gps.hdop());
      Serial.println();
    }
  }

  // Optional: print statistics
  unsigned long chars;
  unsigned short sentences, failed;
  gps.stats(&chars, &sentences, &failed);
  
  Serial.print("CHARS=");
  Serial.print(chars);
  Serial.print(" SENTENCES=");
  Serial.print(sentences);
  Serial.print(" CSUM ERR=");
  Serial.println(failed);

  delay(1000); // Añadir un pequeño retraso para evitar saturar el buffer serie
}