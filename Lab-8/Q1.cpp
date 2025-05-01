#include "iostream"
#include "cmath"
using namespace std; 

class Complex{
private: 
    double realDec;
    double imgDec;
public: 
    Complex(double rDec, double iDec) : realDec(rDec) , imgDec(iDec) {};
    
    Complex operator+(const Complex& other){
        return Complex(realDec + other.realDec , imgDec + other.imgDec);
    }

    Complex operator-(const Complex& other){
        return Complex(realDec - other.realDec , imgDec - other.imgDec);
    }    

// Complex multiplication
Complex operator*(const Complex& other) {
    double realPart = (realDec * other.realDec) - (imgDec * other.imgDec);
    double imgPart = (realDec * other.imgDec) + (imgDec * other.realDec);
    return Complex(realPart, imgPart);
}

// Complex division
Complex operator/(const Complex& other) {
    double denominator = (other.realDec * other.realDec) + (other.imgDec * other.imgDec);
    double realPart = ((realDec * other.realDec) + (imgDec * other.imgDec)) / denominator;
    double imgPart = ((imgDec * other.realDec) - (realDec * other.imgDec)) / denominator;
    return Complex(realPart, imgPart);
}

    friend ostream& operator<<(ostream& print, const Complex& other);
    friend double magnitude(Complex& obj);
};

ostream& operator<<(ostream& print, const Complex& other){
    print << other.realDec; 
    if (other.imgDec >= 0)
        print << " + " << other.imgDec << "i";
    else
        print << " - " << -other.imgDec << "i";
    return print;
}

double magnitude(Complex& obj){
    return sqrt(obj.realDec* obj.realDec + obj.imgDec * obj.imgDec);
}

int main(){
    Complex c1(18.6,17);
    Complex c2(6.72,56);

    Complex addingc3 = c1 + c2;
    Complex substractingc4 = c1 - c2;
    Complex multipliyingc5 = c1 * c2;
    Complex dividingc6 = c1 / c2;

    cout << "Addition: " << addingc3 << endl;
    cout << "Subtraction: " << substractingc4 << endl;
    cout << "Multiplication: " << multipliyingc5 << endl;
    cout << "Division: " << dividingc6 << endl;

    cout << "Absolute value of complex number c1: " << magnitude(c1) << endl;
    cout << "Absolute value of complex number c2: " << magnitude(c2) << endl;

}