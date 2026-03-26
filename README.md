# IoT-Based-LED-Control-System


# 🌐 Automatic LED Glow System using NodeMCU (ESP8266)

An IoT-based automation project that uses **NodeMCU (ESP8266)**, **DHT11 sensor**, and **LDR sensor** to control LEDs automatically based on environmental conditions, with real-time monitoring and control via **Node-RED** and **MQTT**.

## 📌 Project Overview

This project demonstrates a smart automation system where:

* 🌡️ Temperature controls an LED (ON when > 20°C)
* 🌙 Light intensity controls another LED (ON in darkness)
* 📡 Data is transmitted using MQTT protocol
* 📊 Real-time visualization and control are handled using Node-RED

## 🎯 Objectives

* To build an IoT-based environmental monitoring system
* To automate LED control based on sensor inputs
* To implement MQTT communication between devices
* To visualize and control data using Node-RED dashboard

## 🧰 Components Required

### 🔌 Hardware

* NodeMCU ESP8266
* DHT11 Temperature & Humidity Sensor
* LDR (Light Dependent Resistor)
* 10kΩ Resistor (for LDR voltage divider)
* 2 × LEDs
* 2 × 220Ω Resistors
* Breadboard
* Jumper Wires
* USB Cable

### 💻 Software

* Arduino IDE (with ESP8266 board support)
* Required Libraries:

  * `DHT.h`
  * `ESP8266WiFi.h`
  * `PubSubClient.h`
* MQTT Broker:

  * Public: `broker.hivemq.com`
  * OR Local: Mosquitto
* Node-RED
* Node-RED Dashboard (optional)

---

## ⚙️ Working Principle

* The **DHT11 sensor** measures temperature.
* The **LDR sensor** detects light intensity.
* The **NodeMCU**:

  * Reads sensor data
  * Controls LEDs based on thresholds
  * Publishes data to MQTT broker
* **Node-RED**:

  * Subscribes to sensor data
  * Displays real-time values
  * Sends control commands back via MQTT

## 🔁 MQTT Topics Used

| Topic          | Description                 |
| -------------- | --------------------------- |
| `/sensor/temp` | Temperature data            |
| `/led/control` | LED ON/OFF control commands |


## 💡 Logic Used

### Temperature-based LED

```javascript
let temp = msg.payload.temperature;

if (temp > 20) {
    msg.payload = "ON";
} else {
    msg.payload = "OFF";
}
return msg;
```

---

### LDR-based LED

```javascript
let ldr = msg.payload.ldr;

if (ldr > 600) {
    msg.payload = "ON";
} else {
    msg.payload = "OFF";
}
return msg;
```

---

## 🔌 Hardware Setup

### (A) Sensor Connections

* DHT11 → Digital pin (D2)
* LDR → Analog pin (A0) via voltage divider

### (B) LED Connections

* LEDs connected to GPIO pins (e.g., D1) via 220Ω resistors

---

## 🚀 How to Run

1. Install Arduino IDE and required libraries
2. Connect NodeMCU and upload the Publisher code
3. Set up MQTT broker (HiveMQ or Mosquitto)
4. Run Node-RED:

   * Add MQTT nodes
   * Add dashboard nodes (gauge, chart, switch)
5. Deploy flow and monitor real-time data

---

## 📊 Observations

* LED turns ON when:

  * Temperature > 20°C
  * Environment is dark
* LED turns OFF otherwise
* Real-time sensor data successfully displayed on dashboard
* MQTT communication is stable and responsive

---

## ✅ Result

The system successfully:

* Automated LED control based on environmental conditions
* Enabled real-time monitoring using Node-RED
* Demonstrated reliable IoT communication using MQTT

---

## 🧠 Conclusion

This project validates the effectiveness of IoT in:

* Smart home automation
* Environmental monitoring
* Energy-efficient systems

By integrating sensors, microcontrollers, and cloud communication, a scalable and interactive automation system was achieved.

---

## 📌 Future Improvements

* Add mobile app control
* Use more accurate sensors (DHT22, BH1750)
* Add data logging (Firebase / Thingspeak)
* Implement voice control (Google Assistant / Alexa)

---



