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
if (request.indexOf("/endpoint") != -1) {
// Encontrou uma requisição para o endpoint
client.println("HTTP/1.1 200 OK");
client.println("Content-Type: text/plain");
client.println();
// Analisa os parâmetros passados no endpoint
int paramIndex = request.indexOf("param=");
if (paramIndex != -1) {
String parametro = request.substring(paramIndex + 6);
client.println("Parâmetro recebido: " + parametro);
} else {
client.println("Nenhum parâmetro fornecido");
}
}
}
}
client.stop();
}
}