# FRProject-Hardware
 
The embedded code for the smart lighting system is implemented on an ESP32 microcontroller, which is controlled via Wi-Fi by the main FRProject application. This code is responsible for handling the lighting settings based on the data received from the server and adjusts the lighting (color and intensity) accordingly.

Key Features of the Embedded Code:

ESP32 & Wi-Fi Communication: The ESP32 is connected to the Wi-Fi network and listens for periodic HTTP requests from the Flask backend (running on the server). These requests contain RGB color values that dictate the lighting settings.

LED Control with WS2812b: The system is connected to a WS2812b 12V LED strip, which is controlled based on the RGB values received. The ESP32 uses these values to adjust the LED strip's color and brightness according to the user's preferences, as determined by the facial recognition process.

Data Transmission with JSON: Data between the server and the embedded system is transmitted in JSON format, which is parsed using the ArduinoJson library. This allows easy encoding and decoding of data, such as the RGB values, ensuring efficient communication between the microcontroller and the Flask backend.

Real-Time Updates: The ESP32 periodically checks for new data from the server, ensuring that the lighting configuration is updated in real-time based on the facial recognition results. As a user is identified, the corresponding lighting profile (color and intensity) is immediately applied.

Efficient and Lightweight Operation: The embedded code is optimized for the limited resources of the ESP32, ensuring low power consumption and efficient performance, suitable for continuous operation in a smart home environment.

The embedded system, through its seamless integration with the Flask-based server and facial recognition data, ensures that the lighting environment is dynamically adjusted based on user identification, creating a personalized and interactive experience.
