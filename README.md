# MQTT Messages to WhatsApp Notifier with ESP8266

This project enables you to receive MQTT messages and send them as WhatsApp messages using the CallMeBot API. It is designed to work with an ESP8266 board and Arduino framework.

## Setup

1. Open the `Credentials.h` file and update the following constants with your Wi-Fi and MQTT broker credentials:
   - `WIFI_SSID` - your Wi-Fi network name
   - `WIFI_PASSWORD` - your Wi-Fi password
   - `MQTT_HOST` - your MQTT broker address
   - `MQTT_PORT` - your MQTT broker port
   - `MQTT_CLIENT_ID` - a unique ID for your MQTT client
   - `MQTT_USER` - your MQTT broker username (if required)
   - `MQTT_PASSWORD` - your MQTT broker password (if required)
   - `TOPIC` - the MQTT topic to subscribe to for receiving messages

2. Replace `PHONE_NUMBER` and `API_KEY` in the `callback` function with your own phone number and CallMeBot API key respectively.

3. Upload the sketch to your ESP8266 board.

4. Open the serial monitor to view the MQTT messages received.

## How It Works

1. The ESP8266 connects to the Wi-Fi network using the provided credentials.

2. It connects to the MQTT broker and subscribes to the specified topic.

3. When a new MQTT message is received on the subscribed topic, the callback function is triggered.

4. The payload of the message is extracted and sent as a WhatsApp message using the CallMeBot API.


