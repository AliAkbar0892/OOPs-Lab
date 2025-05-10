#include "iostream"
#include "stdexcept"

using namespace std;

class InvalidTemperatureException : public std::exception {
};


template <typename T>
T convertToFahrenheit(T celsius) {
    if (celsius < -273.15) {
        throw InvalidTemperatureException(); 
    }
    return (celsius * 9.0 / 5.0) + 32; 
}

int main() {
    try {
        double tempCelsius = -300.0;
        cout << "Attempting to convert " << tempCelsius << "C..." << endl;
        double tempFahrenheit = convertToFahrenheit(tempCelsius);
        cout << tempCelsius << "C is " << tempFahrenheit << "F" << endl;
    } catch (const InvalidTemperatureException& e) {
        cout << "Caught InvalidTemperatureException - " << e.what() << endl;
    }

    return 0;
}
