#include "controller.h"

/*
 * Author: Cody Botte
 *
 * TODO:
 *  - Light controller should be on a seperate thread
 *  - Connect to a wireless programmer
 *
 * Notes:
 *  - Program will depend on water restriction for calculating water output.
 *  - Can OR all valve controller output for a water pump enable.
 *
 *  main() Explanation:
 *      - Save external plantdata to file if present
 *      - Load plantdata from file
 *      - Register LAMP/LIGHT output: HIGH time intervals
 *      - Register ValveControllers with plants
 *      - Set valve open intervals
 *      - Endless loop
 *          - Cycle all plant's valves
 *          - Check light state (tick())
 *          - Sleep
 */

const uint cyclesHourly = 20;
const double hourlyFlowrate = 10;

int main() {
    stdio_init_all();

    //Initialize I/O controllers
    ValveManager valveManager(hourlyFlowrate, cyclesHourly);
    LightController lightController;

    //TODO: Write data from programming if could connect.
    //TODO: Populate data from files, if exists.
    //valvedata >> valveManager;
    //lightdata >> lightController; set pin valveCount+1

    //Main Loop
    while (true) {
        //Handle controllers
        printf("Water cycle started!\n");
        valveManager.cycle();
        printf("Water cycle ended!\n");

        //Handle lights
        lightController.tick();  // TODO: Should be moved to a second thread

        sleep_ms(valveManager.getSleepSeconds()*1000);
    }
}