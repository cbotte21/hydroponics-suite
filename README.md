# hydroponics-suite
An automated hydroponics microcontroller.

# What is this project?
At first this project started as a variable water emitter for multiple crops. With the plans of controlling each crop with a solenoid. Once I realized that this was far from economically viable, the plans shifted a little.

For some insight on the state of commercial irrigation, a huge factor is risk mitigation. Since the loss of all crops would be devistating, why not reduce the chances of loosing a full yield? For this, we will containerize our crops in clusters (Similar to kubernetes patterns). Each cluster will have its own water controls and light controls, but will contain multiple plants. This reduces the chances of a fatal clog, while allowing for decompartmentalized servicing. We do not need to turn off the water and light to all plants to fix one.

The first part of this project is the irrigation controller. I advice you to look up an Octa-Bubbler. It's essentially a regulator, that when supplied sufficient water, distributes it evenly throughout eight tubes. There are inserts to change the water flow from 2gph, 6gph, etc. The irrigation control for this project will be a solenoid before every octo-bubbler. With the input of the bubbler's flowrate and desired gph we can calculate the time needed for every cluster's solenoid to be open. Along with when the motor should run.

The second part of this project is the light controller. Basically allowing lights at every pod to have a variable on and off cycle.

Lastly, future plans for this project include a disaster notification unit. This is not fully planned out yet, but it will notify users in the event of a water leak, or clog.

# Project setup
 - Clone github repository
 - Open folder in CLion
- Add cmake options:
   - DPICO_BOARD=pico_w
- Add enviroment variables:
   - PICO_SDK_PATH={directory of sdk}

# Diagrams
I have not yet uploaded the diagrams, but I have drawn them.
