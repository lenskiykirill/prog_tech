//
// Created by Pavel Akhtyamov on 02.05.2020.
//

#pragma once

#include <gmock/gmock.h>
#include <Weather.h>

class WeatherMock : public Weather {
      public:
            float GetTemperature(const std::string& city);
            float GetTomorrowTemperature(const std::string& city);
            json hook;
};

float WeatherMock::GetTemperature (const std::string& city) {
      return 
}



