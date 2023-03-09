//
// Created by cbotte21 on 3/9/23.
//

#ifndef HYDROPONIC_SUITE_PLANT_H
#define HYDROPONIC_SUITE_PLANT_H

#include <string>
#include <vector>
#include <utility>

class Plant {
public:
    std::string uuid;
    std::string name;
    uint started; //Timestamp
    uint watering_duration; //Seconds to set pin to HIGH.
};




#endif //HYDROPONIC_SUITE_PLANT_H
