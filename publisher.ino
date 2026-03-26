#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include <DHT.h>

#define DHTPIN D2        // GPIO4
#define DHTTYPE DHT11

const char* ssid = "S23";
const char* password = "fvaf0350";
const char* mqtt_server = “broker.hivemq.com”; // Or your local broker

WiFiClient espClient;
PubSubClient client(espClient);
DHT dht(DHTPIN, DHTTYPE);

void setup_wifi() {
  delay(10);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }
}

void reconnect() {
  while (!client.connected()) {
    if (client.connect("DHT11Publisher")) {
      // Connected
    } else {
      delay(5000);
    }
  }
}

void setup() {
  Serial.begin(115200);
  setup_wifi();
  client.setServer(mqtt_server, 1883);
  dht.begin();
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();

  float temp = dht.readTemperature();
  if (!isnan(temp)) {
    Serial.print("Temperature: ");
    Serial.println(temp);

    // Publish to topic
    char tempStr[10];
    dtostrf(temp, 1, 2, tempStr);
    client.publish("/sensor/temp", tempStr);
  }

  delay(5000); // Publish every 5 sec
}

