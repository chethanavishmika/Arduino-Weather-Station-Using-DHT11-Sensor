# Arduino Weather Station using DHT11 Sensor & Nokia 5110 Display

A compact, DIY indoor weather station built using an **Arduino Uno** , a **DHT11 temperature & humidity sensor** , and a classic **Nokia 5110 LCD** display (PCD8544 controller) .

This project continuously reads environmental temperature and relative humidity levels and presents them on a clear monochrome graphical UI .

---

## 📸 Overview & Features

* **Temperature & Humidity Monitoring:** Real-time environmental readings via the DHT11 digital sensor .
* **Graphical UI:** High-contrast 84x48 pixel LCD layout powered by the efficient `LCD5110_Graph` library.
* **Simple Breadboard Setup:** Easy-to-follow pin mapping designed for beginners and hobbyists .

---

## 🛠 Hardware Required

| Component | Quantity | Description |
| :--- | :--- | :--- |
| **Arduino Uno** | 1 | Microcontroller board  |
| **Nokia 5110 LCD** | 1 | 84x48 PCD8544 Graphic Display  |
| **DHT11 Sensor** | 1 | Digital Temperature & Humidity Sensor  |
| **10kΩ Resistor** | 1 | Pull-up resistor for DHT11 data line (if using raw sensor) |
| **Breadboard & Wires** | - | Jumper cables for connections  |

---

## 🔌 Wiring & Pin Mapping

### 1. Nokia 5110 LCD Breakout (Pins 1–8)

| Pin No. | Pin Label | Arduino Uno Pin | Description |
| :---: | :--- | :--- | :--- |
| **1** | **RST** | Digital Pin 8 | Reset  |
| **2** | **CE / CS** | Digital Pin 9 | Chip Enable  |
| **3** | **DC** | Digital Pin 10 | Data / Command Select  |
| **4** | **DIN / MOSI**| Digital Pin 11 | Serial Data Line  |
| **5** | **CLK / SCK** | Digital Pin 12 | Serial Clock Line  |
| **6** | **VCC** | 5V | Power Supply (check breakout board spec)  |
| **7** | **BL / LIGHT**| GND | Backlight Ground  |
| **8** | **GND** | GND | Common Ground  |

### 2. DHT11 Sensor Pinout

| DHT11 Pin | Arduino Pin / Power Rail | Description |
| :--- | :--- | :--- |
| **DATA** | Digital Pin 2 | Signal Data Line (Add 10k pull-up to VCC if required) |
| **VCC** | 5V Rail | Power Supply |
| **GND** | GND Rail | Common Ground |

---

## 📚 Required Libraries

Install these libraries via the **Arduino IDE Library Manager** (*Sketch > Include Library > Manage Libraries*):

1. **`LCD5110_Graph`** by Henning Karlsen
2. **`DHT sensor library`** by Adafruit
3. **`Adafruit Unified Sensor`** by Adafruit

---

## 🚀 How to Build & Run

1. Connect all hardware components following the **Wiring & Pin Mapping** tables above .
2. Open the **Arduino IDE**, navigate to *Library Manager*, and install `LCD5110_Graph`, `DHT sensor library`, and `Adafruit Unified Sensor`.
3. Select your board as **Arduino Uno** and choose the active COM port .
4. Copy the code into your sketch and upload it.
5. The Nokia 5110 display will initialize and start updating live temperature and humidity values every 2 seconds !

---

## 📜 License
This project is open-source and available under the **MIT License**.
