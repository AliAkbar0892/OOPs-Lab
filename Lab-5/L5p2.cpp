#include "iostream"
using namespace std;

class Students{
public:
    string name;
    int id;
    int* examScores;
    Students(string n, int d, int* scores) : name(n) , id(d){
        examScores = new int [10];
        for (int i = 0; i < 10; i++)
        {
            examScores[i] = scores[i];
        }
        
    }
    Students(Students& other): name(other.name) , id(other.id){
        examScores = new int [10];
        for (int i = 0; i < 10; i++)
        {
            this -> examScores[i] = other.examScores[i];
        }
    }    
    ~Students() {
        delete[] examScores;
    }      
};

int main(){
    int scores[10] = {700, 85, 90, 78, 88, 92, 76, 80, 85, 89};
    Students s1("ZulfiqarBhutto" , 1221 , scores);
    Students s2 = s1;

}