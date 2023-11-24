#include <SPI.h>
#include <Ethernet.h>
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
EthernetServer server(80);
void setup() {
Ethernet.begin(mac);
server.begin();
Serial.begin(9600);
pinMode(9, OUTPUT); // Configura o pino 9 como saída
digitalWrite(9, LOW); // Inicialmente desliga o pino 9
Serial.println("Servidor inicializado");
}
void loop() {
EthernetClient client = server.available();
if (client) {
Serial.println("Novo cliente!");
while (client.connected()) {
if (client.available()) {
char c = client.read();
Serial.write(c);
if (c == '1') {
digitalWrite(9, HIGH); // Liga o pino 9
} else if (c == '0') {
digitalWrite(9, LOW); // Desliga o pino 9
}
}
}
client.stop();
}
}

