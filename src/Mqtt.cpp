#include "Credentials.h"
#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include <Callmebot_ESP8266.h>



WiFiClient espClient;
PubSubClient mqttClient(espClient);
bool messageSent = false;

void callback(char* topic, byte* payload, unsigned int length);

void setupWiFi() {
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println();
  Serial.println("Connected to Wi-Fi");
}

void setupMQTT() {
  mqttClient.setServer(MQTT_HOST, MQTT_PORT);
  mqttClient.setCallback(callback);

  while (!mqttClient.connected()) {
    if (mqttClient.connect(MQTT_CLIENT_ID, MQTT_USER, MQTT_PASSWORD)) {
      Serial.println("Connected to MQTT broker");
    } else {
      delay(500);
    }
  }

  mqttClient.subscribe(TOPIC);
}

void setup() {
  Serial.begin(9600);
  setupWiFi();
  setupMQTT();
}

void loop() {
  mqttClient.loop();
}

void callback(char* topic, byte* payload, unsigned int length) {
  payload[length] = '\0';
  String value = String((char*)payload);
  Serial.println(topic);

  if (length == value.length()) {

    Serial.println(value);
  }

  if (!messageSent) {
    whatsappMessage(PHONE_NUMBER, API_KEY, value);
    messageSent = true;
  }
}
