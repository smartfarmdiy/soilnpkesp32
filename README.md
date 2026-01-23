# soilnpkesp32

ESP32 Smart Agriculture: Interfacing 7-in-1 Soil TH EC PH NPK Sensors
soilnpkesp32-7in1sensor


![clean_Smart_Agriculture_Sensor_Interfacing_Guide_Page_01](https://github.com/user-attachments/assets/b50b4ee0-f4bd-4a3a-88a4-c90f2a909f8a)



วิธีการเชื่อมต่อ เซนเซอร์วัดดินแบบ 7-in-1 เข้ากับ บอร์ด ESP32 เพื่อใช้ในงานด้าน เกษตรอัจฉริยะ โดยเซนเซอร์ชนิดนี้มีความสามารถในการตรวจวัดค่าสำคัญต่าง ๆ เช่น ความชื้น อุณหภูมิ ค่า pH ค่าการนำไฟฟ้า รวมถึงธาตุอาหารหลักอย่าง ไนโตรเจน ฟอสฟอรัส และโพแทสเซียม ในขั้นตอนการติดตั้งจำเป็นต้องใช้ โมดูลแปลงสัญญาณ RS485 เป็น TTL เพื่อช่วยในการสื่อสารข้อมูลระหว่างตัวเซนเซอร์และไมโครคอนโทรลเลอร์ ข้อมูลที่วัดได้ทั้งหมดจะถูกนำไปประมวลผลและ แสดงผลผ่านหน้าจอ LCD ขนาด 20x4 และบนจอภาพคอมพิวเตอร์แบบเรียลไทม์ การสาธิตนี้มุ่งเน้นไปที่การ จัดวางระบบสายไฟ และการกำหนดพินต่าง ๆ อย่างถูกต้องเพื่อให้ระบบทำงานได้อย่างมีประสิทธิภาพ ทั้งนี้โปรเจกต์ดังกล่าวถือเป็นแนวทางที่เป็นประโยชน์สำหรับผู้ที่ต้องการ พัฒนาเทคโนโลยีการตรวจสอบคุณภาพดิน ด้วยตนเอง โดยมีอุปกรณ์และรหัสโปรแกรมรองรับสำหรับการใช้งานจริง

This demonstration shows how to connect a 7-in-1 soil sensor to an ESP32 board for smart agriculture applications. This sensor measures various important parameters such as moisture, temperature, pH, conductivity, and essential nutrients like nitrogen, phosphorus, and potassium. An RS485-to-TTL converter module is required for data communication between the sensor and the microcontroller. All measured data is processed and displayed in real-time on a 20x4 LCD screen and a computer monitor. This demonstration focuses on correct wiring and pin assignments for efficient system operation. This project provides a useful guide for those who wish to develop their own soil quality monitoring technology, with supporting equipment and software for practical application.

![clean_Smart_Agriculture_Sensor_Interfacing_Guide_Page_02](https://github.com/user-attachments/assets/d55acaa9-4d1e-4a62-bb66-b002c94447d0)

The 7-in-1 Soil Sensor is a soil parameter measuring device that can simultaneously measure seven important physical and chemical parameters. These are detailed as follows:


![clean_Smart_Agriculture_Sensor_Interfacing_Guide_Page_03](https://github.com/user-attachments/assets/a0b4bdda-7909-402a-9130-04e3acd3db1f)


The main parameters that the sensor can measure are:
1. Moisture: Measures the amount of water present in the soil.
2. Temperature: Measures the current soil temperature.
3. pH: Measures the concentration of hydrogen ions in the soil.
4. Electrical Conductivity (EC): Used to check the concentration of salts or solutions in the soil.
5. Nitrogen (N): A major nutrient essential for plant growth.
6. Phosphorus (P): An important nutrient for root and flower development.
7. Potassium (K): A nutrient that helps strengthen plants and improve their disease resistance.
This type of sensor is a multiparameter soil sensor that provides users with comprehensive information for smart agriculture simply by inserting the sensor into the soil.

![clean_Smart_Agriculture_Sensor_Interfacing_Guide_Page_04](https://github.com/user-attachments/assets/9868b2b8-013f-4d52-b5db-7718361845a9)


Connecting a 7-in-1 NPK sensor to an ESP32 board for smart agriculture applications involves the following main components and steps, as outlined in the resources:
Main Components Required:
1. 7-in-1 NPK Sensor: This sensor can measure various parameters including moisture, temperature, pH, conductivity (EC), and NPK (Nitrogen, Phosphorus, Potassium) in the soil.
2. ESP32 Control Board: This uses a 30-pin ESP32 DevKit because it has multiple Serial (Hardware Serial) ports.
3. RS485 to TTL Converter Module: Since the sensor transmits signals via RS485, a converter is needed to communicate with the ESP32.
4. External Power Supply: A 12V power supply to power the sensor (supports 4.5V to 30V).
5. 20x4 LCD Display (Optional): For displaying measured values.

Key Connection Steps:
1. Connecting the Sensor Signal Wires to the RS485 Module
• The sensor has 4 wires: brown and black (for power supply), and yellow and blue (for signals A and B).
• Connect the yellow and blue wires of the sensor to ports A and B of the RS485 module.
2. Powering the System
• Connect the brown wire of the sensor to the positive terminal of the external power supply (e.g., 12V) and the black wire to the negative terminal (Ground).
• Important: Common ground must be established by connecting the sensor's ground wire to the ground of both the RS485 module and the ESP32.
3. Connecting the RS485 Module to the ESP32 (This section describes the connection process.) The source specifies the use of the Hardware Serial 2 pins as follows:
• VCC (module's black wire): Connect to the 3.3V of the ESP32.
• GND (module's yellow wire): Connect to the ESP32's Ground.
• TXD: Connect to the TX2 pin (pin 17) of the ESP32.
• RXD: Connect to the RX2 pin (pin 16) of the ESP32.
• Note: For this module model, the source specifies connecting TX to TX and RX to RX without swapping the wires normally.
4. Connecting an LCD (if applicable)
• Use an I2C connection by connecting the SDA wire to pin 21 and SCL to pin 22 of the ESP32.

--------------------------------------------------------------------------------
Operation and Testing Procedure
Once the hardware is connected, power the sensor first (e.g., from a 12V source), then power the ESP32 board. Then, configure the settings... The results will be displayed via the Serial Monitor or LCD screen, showing all seven values: humidity, temperature, EC value, pH value, and N, P, K values ​​of the soil when the sensor is inserted into the soil.
The system works like having a "language interpreter," where the NPK sensor speaks RS485 language, which the ESP32 board doesn't understand. The RS485 to TTL module acts as an interpreter, translating that language into Serial (TTL) so that the ESP32 can process the data and display it in a way that is easy for us to understand.
