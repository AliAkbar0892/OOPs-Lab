#include <iostream>
#include <string>
using namespace std;

class Device {
protected:
    string deviceID;
    string deviceName;
    bool status; 

public:
    Device(string id, string name, bool stat) : deviceID(id), deviceName(name), status(stat) {}

    virtual void turnOn() {
        status = true;
        cout << deviceName << " is turned ON." << endl;
    }

    virtual void turnOff() {
        status = false;
        cout << deviceName << " is turned OFF." << endl;
    }

    virtual void getStatus() const {
        cout << deviceName << " is currently " << (status ? "ON" : "OFF")<< endl;
    }

    virtual void displayInfo() const {
        cout << "Device ID: " << deviceID << "\nDevice Name: " << deviceName<< "\nStatus: " << (status ? "ON" : "OFF")<< endl;
    }

    virtual ~Device() {}
};

class Light : public Device {
private:
    int brightnessLevel;
    string colorMode;

public:
    Light(string id, string name, bool stat, int brightness, string color): Device(id, name, stat), brightnessLevel(brightness), colorMode(color) {}

    void setBrightness(int level) {
        brightnessLevel = level;
        cout << deviceName << " brightness set to " << brightnessLevel<< endl;
    }

    void setColorMode(string mode) {
        colorMode = mode;
        cout << deviceName << " color mode set to " << colorMode<< endl;
    }

    void displayInfo() const override {
        Device::displayInfo();
        cout << "Brightness Level: " << brightnessLevel << "\nColor Mode: " << colorMode << endl;
    }
};

class Thermostat : public Device {
private:
    float currentTemperature;
    float targetTemperature;
    string mode; 

public:
    Thermostat(string id, string name, bool stat, float currTemp = 25.0, string m = "Cooling") : Device(id, name, stat), currentTemperature(currTemp), targetTemperature(currTemp), mode(m) {}

    void setTargetTemperature(float temp) {
        targetTemperature = temp;
        cout << deviceName << " target temperature set to " << targetTemperature << "°C." << endl;
    }

    void setMode(string newMode) {
        mode = newMode;
        cout << deviceName << " mode set to " << mode << "." << endl;
    }

    void getStatus() const override {
        cout << deviceName << " is " << (status ? "ON" : "OFF") << ". Current Temperature: " << currentTemperature << "°C, Target Temperature: " << targetTemperature << "°C." << endl;
    }
};

class SecurityCamera : public Device {
private:
    string resolution;
    bool recordingStatus;
    bool nightVisionEnabled;

public:
    SecurityCamera(string id, string name, bool stat, string res = "1080p", bool nightVision = false) : Device(id, name, stat), resolution(res), recordingStatus(false), nightVisionEnabled(nightVision) {}

    void enableNightVision() {
        nightVisionEnabled = true;
        cout << deviceName << " night vision enabled." << endl;
    }

    void turnOn() override {
        Device::turnOn();
        recordingStatus = true;
        cout << deviceName << " started recording automatically." << endl;
    }

    void turnOff() override {
        Device::turnOff();
        recordingStatus = false;
        cout << deviceName << " stopped recording." << endl;
    }

    void displayInfo() const override {
        Device::displayInfo();
        cout << "Resolution: " << resolution << "\nRecording: " << (recordingStatus ? "Yes" : "No") << "\nNight Vision: " << (nightVisionEnabled ? "Enabled" : "Disabled") << endl;
    }
};

class SmartPlug : public Device {
private:
    float powerConsumption;
    string timerSetting;

public:
    SmartPlug(string id, string name, bool stat, float power = 0.0, string timer = "Off") : Device(id, name, stat), powerConsumption(power), timerSetting(timer) {}

    void setTimer(string timer) {
        timerSetting = timer;
        cout << deviceName << " timer set to " << timerSetting<< endl;
    }

    void turnOff() override {
        Device::turnOff();
        cout << deviceName << " logged power usage: " << powerConsumption << " kWh." << endl;
    }

    void displayInfo() const override {
        Device::displayInfo();
        cout << "Power Consumption: " << powerConsumption << " kWh\nTimer Setting: " << timerSetting << endl;
    }
};

int main() {
    Light light1("L001", "Living Room Light", true, 75, "Warm White");
    Thermostat thermostat1("T001", "Home Thermostat", false, 22.5, "Heating");
    SecurityCamera camera1("C001", "Front Door Camera", true, "4K", true);
    SmartPlug plug1("P001", "Coffee Maker Plug", false, 1.2, "7:00 AM");

    light1.turnOn();
    light1.setBrightness(80);
    light1.displayInfo();

    thermostat1.turnOn();
    thermostat1.setTargetTemperature(24.0);
    thermostat1.getStatus();

    camera1.turnOn();
    camera1.enableNightVision();
    camera1.displayInfo();

    plug1.turnOn();
    plug1.setTimer("6:30 AM");
    plug1.turnOff();

    return 0;
}
