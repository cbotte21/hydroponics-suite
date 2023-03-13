# hydroponics-suite
An automated hydroponics microcontroller.
# Project setup
 - Clone github repository
 - Open folder in CLion
- Add cmake enviroment variebles:
   - DPICO_BOARD=pico_w
   - PICO_SDK_PATH={directory of sdk}
# Plans
 - Create a programmer application. Runs off tcp and can transmit config options to PICO.
 - Implement LightController.
 - Upload build photos
 # Key points
 - To maintain steady water pressure, and accurate water deployments, valves are open sequantually.
 - Uses water pressure, tubing size, and time to calculate watering of plants.
