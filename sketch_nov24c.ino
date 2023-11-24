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
client.println("HTTP/1.1 200 OK");
client.println("Content-Type: text/html");
client.println();
client.println("<html><body><h1>Hello, World!</h1></body></html>");
client.stop();
}
}
