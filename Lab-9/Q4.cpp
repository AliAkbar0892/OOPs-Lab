#include <iostream>
using namespace std;

class WeatherSensor {
public:
    virtual void readData() = 0;  
    virtual void displayReport() = 0;  
    virtual ~WeatherSensor() {}  
};

class Thermometer : public WeatherSensor {
public:
    void readData() override {
        cout << "Reading temperature data from Thermometer...\n";
        temperature = 22.5; // random value
    }

    void displayReport() override {
        cout << "Temperature: " << temperature << "°C\n";
    }

private:
    float temperature;
};

class Barometer : public WeatherSensor {
public:
    void readData() override {
        cout << "Reading pressure data from Barometer...\n";
        pressure = 1013.25; // Random value
    }

    void displayReport() override {
        cout << "Pressure: " << pressure << " hPa\n";
    }

private:
    float pressure;
};

int main() {
    WeatherSensor* sensor1 = new Thermometer();
    WeatherSensor* sensor2 = new Barometer();

    sensor1->readData();
    sensor1->displayReport();

    sensor2->readData();
    sensor2->displayReport();

    delete sensor1;
    delete sensor2;

    return 0;
}
