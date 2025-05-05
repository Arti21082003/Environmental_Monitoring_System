Environmental Monitoring System

This Arduino-based project monitors environmental parameters using various sensors, displaying data on a 16x2 I2C LCD and the Serial Monitor. It measures temperature and humidity (DHT11), CO2 levels (analog CO2 sensor), soil moisture, water level, light intensity (LDR), and motion (PIR sensor). Outputs include an LED for motion detection, a buzzer for high water levels, and a lamp for low light conditions. The system is ideal for applications like greenhouse monitoring, home automation, or environmental studies.

Features
- Multi-Sensor Monitoring:
  - Temperature and humidity via DHT11.
  - CO2 levels via an analog CO2 sensor.
  - Soil moisture and water level via analog sensors.
  - Light intensity via LDR.
  - Motion detection via PIR sensor.
- Display: Shows sensor readings on a 16x2 I2C LCD, cycling through data every 2 seconds.
- Outputs:
  - LED lights up when motion is detected.
  - Buzzer activates when water level exceeds 400.
  - Lamp turns on when LDR detects low light.
- Serial Output: Prints all sensor readings to the Serial Monitor for debugging.

Hardware Requirements
- Arduino Board: Arduino Uno or compatible microcontroller.
- Sensors:
  - DHT11 (temperature and humidity).
  - Analog CO2 sensor (e.g., MQ-135).
  - Soil moisture sensor (analog).
  - Water level sensor (analog).
  - LDR (light-dependent resistor).
  - PIR motion sensor.
- Display: 16x2 I2C LCD (address 0x27).
- Outputs:
  - LED (for motion detection).
  - Buzzer (for water level alerts).
  - Lamp or LED (for low light conditions).
- Power Supply: 5V via USB or external source; ensure sufficient current for sensors and outputs.
- Miscellaneous: Jumper wires, breadboard, resistors (if needed for LDR or LED), and a stable power source.

Software Requirements
- Arduino IDE: Version 1.8.x or later.
- Libraries:
  - 'LiquidCrystal_I2C': For controlling the I2C LCD.
  - 'DFRobot_DHT11': For reading DHT11 sensor data.

Install the libraries via the Arduino IDE Library Manager:
1. Go to 'Sketch' > 'Include Library' > 'Manage Libraries...'.
2. Search for and install:
   - 'LiquidCrystal I2C' by Frank de Brabander.
   - 'DFRobot DHT11' by DFRobot.

Wiring
| Component             | Pin Connection                    |
|-----------------------|-----------------------------------|
| DHT11 Data            | Pin 7 on Arduino                  |
| CO2 Sensor            | A2 on Arduino                     |
| Soil Moisture Sensor  | A0 on Arduino                     |
| Water Level Sensor    | A1 on Arduino                     |
| LDR                   | Pin 10 on Arduino                 |
| PIR Motion Sensor     | Pin 3 on Arduino                  |
| LED (Motion)          | Pin 4 on Arduino                  |
| Buzzer                | Pin 2 on Arduino                  |
| Lamp/LED (LDR)        | Pin 9 on Arduino                  |
| LCD SDA               | SDA (A4 on Uno)                   |
| LCD SCL               | SCL (A5 on Uno)                   |
| LCD VCC/GND           | 5V/GND on Arduino                 |
| Sensor VCC/GND        | 5V/GND (common with Arduino)      |

Note: Use appropriate resistors (e.g., 220Ω for LED, 10kΩ pull-down for LDR if needed). Ensure a common ground for all components. Power sensors and outputs via a breadboard or external 5V rail if Arduino’s 5V pin is overloaded.

Installation
1. Clone the Repository:
   bash
   git clone https://github.com/Arti21082003/environmental-monitor.git

2. Open the Arduino Sketch:
   - Open 'Environmental_Monitor.ino' in the Arduino IDE.

3. Install Libraries:
   - Follow the Software Requirements section to install 'LiquidCrystal_I2C' and 'DFRobot_DHT11' libraries.

4. Connect Hardware:
   - Wire the components as per the Wiring section.
   - Verify connections to avoid short circuits.

5. Upload the Code:
   - Connect the Arduino to your computer via USB.
   - In the Arduino IDE, select your board (e.g., 'Arduino Uno') and port under 'Tools'.
   - Click 'Upload' to flash the code to the Arduino.

Usage
1. Power On:
   - Connect the Arduino via USB or an external 5V power source.
   - Ensure sensors and outputs are powered (use a breadboard or power rail if needed).

2. Monitor Data:
   - The LCD cycles through displays every 2 seconds:
     - Temperature, humidity, and CO2.
     - Soil moisture and water level.
     - LDR and motion sensor status.
   - The Serial Monitor (9600 baud) prints all sensor readings continuously.

3. Outputs:
   - LED: Lights up when the PIR sensor detects motion ('hasObstacle == LOW').
   - Buzzer: Activates when the water level sensor reading exceeds 400.
   - Lamp: Turns on when the LDR detects low light ('LDR_val == 1').

4. Debugging:
   - Open the Serial Monitor ('Tools' > 'Serial Monitor') at 9600 baud.
   - Check sensor readings to verify functionality and troubleshoot issues.

Customization
- Thresholds:
  - Adjust 'water_val > 400' in the code to change the buzzer trigger for water level.
  - Modify delays (e.g., 'delay(2000)' for LCD updates) to change display timing.
- LCD Display:
  - Change 'lcd.setCursor' positions or text to customize the display layout.
  - Add more sensor data or shorten the display cycle.
- Sensor Pins:
  - Update '#define' statements (e.g., 'DHT11_PIN', 'CO2_Sensor') if using different pins.
- CO2 Calibration:
  - The CO2 sensor (e.g., MQ-135) may require calibration; add mapping to convert analog readings to ppm if needed.

Troubleshooting
- Library Errors:
  - Ensure 'LiquidCrystal_I2C' and 'DFRobot_DHT11' are installed correctly.
  - Reinstall via Library Manager or download from GitHub if issues persist.
- LCD Not Displaying:
  - Verify I2C address (0x27); use an I2C scanner sketch if unsure.
  - Check SDA/SCL connections (A4/A5 on Uno).
- Sensor Issues:
  - Confirm sensor wiring and power supply.
  - Test individual sensors with simple sketches to isolate faults.
  - For CO2, ensure proper calibration for accurate readings.
- Outputs Not Working:
  - Check LED, buzzer, and lamp connections and polarity.
  - Verify pin assignments (e.g., 'LEDpin', 'Buzzer_Pin').
- Serial Monitor Issues:
  - Ensure the baud rate is 9600 in both the code and Serial Monitor.

Acknowledgments
- DFRobot for the DHT11 library and sensor support.
- Arduino community for LCD and sensor tutorials.
- Contributors to the LiquidCrystal_I2C library.
