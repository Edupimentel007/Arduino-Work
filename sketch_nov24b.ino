#include <SPI.h>
#include <Ethernet.h>
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
EthernetServer server(80);
void setup() {
  Ethernet.begin(mac);
  server.begin();
  Serial.begin(9600);
  Serial.println("Servidor inicializado");
}
void loop() {
  EthernetClient client = server.available();
  if (client) {
    Serial.println("Novo cliente!");
    while (client.connected()) {
      if (client.available()) {
        char c = client.read();  // Lê o caracter da requisição
        Serial.write(c);         // Imprime o caracter no monitor serial
      }
    }
    client.stop();  // Encerra a conexão
  }
}