#include "iostream"
using namespace std;

class Vector2D{
    double x;
    double y;
public: 
    Vector2D(double x, double y){
        this-> x = x;
        this-> y = y;
    }
    Vector2D operator+(const Vector2D& other){
        return Vector2D(x + other.x , y + other.y);
    }

    Vector2D operator-(const Vector2D& other){
        return Vector2D(x - other.x , y - other.y);
    }    

    Vector2D operator*(const int n){
        return Vector2D(x * n, y * n);    // n stores constant
    }      
    
    friend double dotProuct(Vector2D& v1, Vector2D& v2);

    friend ostream& operator<<(ostream& print, const Vector2D& other){
        print << other.x << "i^";
        if (other.y >= 0)
        print << " + " << other.y << "j^";
        else
            print << " - " << -other.y << "j^"; 
        return print;
    }
};

double dotProuct(Vector2D& v1, Vector2D& v2){
    return ( (v1.x * v2.x) + (v1.y * v2.y) );
}

int main(){
    Vector2D vector1(48, 34.6);
    Vector2D vector2(34.3 , 43);

    Vector2D vector3 = vector1 + vector2; 
    Vector2D vector4 = vector1 - vector2; 

    Vector2D vector5 = vector3 * 5;

    cout << "Sum of vectors: " << vector3 << endl;
    cout << "Substract of vectors: " << vector4 << endl;
    cout << "Multiplication of vectors: " << vector5 << endl;
    cout << "Dot Product of vectors: " << dotProuct(vector4 , vector5) << endl;

    return 0;
}