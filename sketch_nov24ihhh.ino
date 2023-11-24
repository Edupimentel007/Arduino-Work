#include <SPI.h>
#include <Ethernet.h>
#include <DHT.h>
#define DHTPIN 2
#define DHTTYPE DHT11
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };  // Endereço MAC
DHT dht(DHTPIN, DHTTYPE);
EthernetServer server(80);
void setup() {
  Ethernet.begin(mac);
  server.begin();
  Serial.begin(9600);
  dht.begin();
}
void loop() {
  EthernetClient client = server.available();
  if (client) {
    Serial.println("Novo cliente conectado!");
    client.println("HTTP/1.1 200 OK");
    client.println("Content-Type: application/json");
    client.println();
    float temp = dht.readTemperature();
    float hum = dht.readHumidity();
    String jsonData = "{\"temperatura\":" + String(temp) + ",\"umidade\":" + String(hum) + "}";
    client.print(jsonData);
    client.stop();
    Serial.println("Cliente desconectado");
  }
}
