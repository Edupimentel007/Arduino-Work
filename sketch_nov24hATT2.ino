#include <SPI.h>
#include <Ethernet.h>
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED }; // Endereço MAC
EthernetServer server(80);
void setup() {
// Inicia a comunicação Ethernet e o servidor na porta 80
Ethernet.begin(mac);
server.begin();
Serial.begin(9600);
}
void loop() {
// Verifica se há clientes conectados
EthernetClient client = server.available();
if (client) {
Serial.println("Novo cliente conectado!");
// Envia um cabeçalho HTTP padrão
client.println("HTTP/1.1 200 OK");
client.println("Content-Type: application/json");
client.println();
// Cria um JSON simples como resposta do servidor
String jsonData = "{\"mensagem\":\"Bem-vindo ao WebServer Arduino!\"}";
// Envia o JSON para o cliente
client.print(jsonData);
// Encerra a conexão com o cliente
client.stop();
Serial.println("Cliente desconectado");
}
}