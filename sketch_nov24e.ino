#include <SPI.h>
#include <Ethernet.h>
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
EthernetServer server(80);
void setup() {
Ethernet.begin(mac);
server.begin();
Serial.begin(9600);
pinMode(9, OUTPUT);
pinMode(10, OUTPUT);
digitalWrite(9, LOW);
digitalWrite(10, LOW);
Serial.println("Servidor inicializado");
}
void loop() {
EthernetClient client = server.available();
if (client) {
Serial.println("Novo cliente!");
while (client.connected()) {
if (client.available()) {
String request = client.readStringUntil('\r');
Serial.println(request);
if (request.indexOf("/ligar1") != -1) {
digitalWrite(9, HIGH);
} else if (request.indexOf("/desligar1") != -1) {
digitalWrite(9, LOW);
} else if (request.indexOf("/ligar2") != -1) {
digitalWrite(10, HIGH);
} else if (request.indexOf("/desligar2") != -1) {
digitalWrite(10, LOW);
}
}
}
client.stop();
}
}