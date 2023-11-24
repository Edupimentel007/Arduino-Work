#include <SPI.h>
#include <Ethernet.h>
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };  // Endereço MAC do Shield
EthernetServer server(80);                            // Porta para o servidor
void setup() {
  Ethernet.begin(mac);  // Inicialização da conexão Ethernet
  // Inicialização do servidor na porta 80
  server.begin();
  Serial.begin(9600);
  Serial.println("Servidor inicializado");
}
void loop() {
  EthernetClient client = server.available();  // Verifica a chegada de clientes
  if (client) {
    Serial.println("Novo cliente!");  // Mensagem ao detectar um cliente
    client.stop();                    // Encerra a conexão
  }
}