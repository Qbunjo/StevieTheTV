# 🌈 ESP8266 NeoPixel NTP LED Ambient Clock / Effect

A project based on **ESP8266** that controls a **WS2812B (NeoPixel) LED strip** and uses time from an **NTP server** to trigger lighting effects at specific hours.

The effect works like an ambient “TV on” simulation – randomly lighting and fading LED segments during a defined time window.

---

## ⚙️ Features

* 📡 NTP time synchronization (`europe.pool.ntp.org`)
* 🌐 WiFi connectivity (ESP8266)
* 💡 NeoPixel LED strip control (61 LEDs)
* 🎲 Random lighting effects (“twinkling” effect)
* ⏰ Time-based activation (HHMM format)
* 🌙 Night mode (LEDs turned off)

---

## 🧠 How it works

* ESP connects to WiFi
* Retrieves time from NTP server
* Converts time to `HHMM` format
* If current time is within:

```id="3h7g2k"
20:25 – 23:18
```

it runs the lighting effect.

Outside this time range:

* LEDs are turned off
* device enters “sleep mode” (simple delay loop)

---

## 💡 Lighting effect

The `mrygu()` function:

* randomly generates RGB colors
* selects a random LED segment
* lights up several LEDs
* clears the previous segment
* creates a “living light” effect

---

## 🔧 Required libraries

Install in Arduino IDE:

* `NTPClient`
* `ESP8266WiFi`
* `WiFiUdp`
* `Adafruit NeoPixel`

---

## 📌 Configuration

Set your WiFi credentials in the code:

```cpp id="k8d2qv"
const String ssid = "SSID";
const String password = "PASS";
```

---

## 🔌 LED wiring

| NeoPixel | ESP8266     |
| -------- | ----------- |
| DIN      | GPIO12 (D6) |
| VCC      | 5V          |
| GND      | GND         |

---

## ⏱️ Time settings

```cpp id="q1v9pm"
NTPClient timeClient(ntpUDP, "europe.pool.ntp.org", hour, 60000);
```

* timezone offset: `3600` (UTC+1)
* update interval: 60 seconds

---

## 🧩 Main functions

### `whatTime()`

Fetches current time and returns it in `HHMM` format.

### `mrygu()`

Generates a random LED lighting effect on the strip.

### `sweetDreams()`

Sleep mode function (currently a simple delay loop).

---

## 🚀 How to run

1. Upload the code to ESP8266
2. Set WiFi SSID and password
3. Connect LED strip to GPIO12
4. Power on the device
5. Enjoy the effect 🙂

---

## ⚠️ Notes

* Code assumes UTC+1 timezone (no daylight saving adjustment)
* `sweetDreams()` is currently inefficient and can be optimized
* Effects are fully random and non-deterministic

---

## 📷 Possible improvements

* Web configuration panel
* OTA firmware updates
* Schedule/calendar mode
* MQTT control
* Home Assistant integration

