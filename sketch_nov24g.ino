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
String request = client.readStringUntil('\r');
Serial.println(request);
if (request.indexOf("GET /endpoint1") != -1) {
// Responde ao endpoint1 com uma mensagem
client.println("HTTP/1.1 200 OK");
client.println("Content-Type: text/plain");
client.println();
client.println("Resposta do Endpoint1");
} else if (request.indexOf("POST /endpoint2") != -1) {
// Processa dados enviados para o endpoint2
// Aqui você poderia analisar dados enviados por POST e realizar ações
client.println("HTTP/1.1 200 OK");
client.println("Content-Type: text/plain");
client.println();
client.println("Ação realizada no Endpoint2");
}
}
}
client.stop();
}
}