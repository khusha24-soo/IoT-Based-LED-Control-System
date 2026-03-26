Subscriber:
#include <ESP8266WiFi.h>
#include <PubSubClient.h>

const char* ssid = "S23";
const char* password = "fvaf0350";
const char* mqtt_server = "broker.hivemq.com"; // Same broker

WiFiClient espClient;
PubSubClient client(espClient);

const int ledPin = D1; // GPIO5

void callback(char* topic, byte* payload, unsigned int length) {
  String msg;
  for (unsigned int i = 0; i < length; i++) {
    msg += (char)payload[i];
  }

  if (msg == "ON") {
    digitalWrite(ledPin, HIGH);
  } else if (msg == "OFF") {
    digitalWrite(ledPin, LOW);
  }
}

void reconnect() {
  while (!client.connected()) {
    if (client.connect("LEDSubscriber")) {
      client.subscribe("/led/control");
    } else {
      delay(5000);
    }
  }
}

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(115200);
  setup_wifi();
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);
}

void setup_wifi() {
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();
}

