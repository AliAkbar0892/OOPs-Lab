#include "iostream"
#include "stdexcept"

using namespace std;

class QueueOverflowException : public std::exception {
    // Inheriting from std::exception without overriding the what() function
};

class QueueUnderflowException : public std::exception {
    // Inheriting from std::exception without overriding the what() function
};

template <typename T>
class Queue {
private:
    T* data;          
    int front, rear;  
    int capacity;     
    int size;         

public:

    Queue(int cap) : capacity(cap), front(0), rear(-1), size(0) {
        data = new T[capacity];
    }


    ~Queue() {
        delete[] data;
    }


    void enqueue(T item) {
        if (size == capacity) {
            throw QueueOverflowException(); 
        }
        rear = (rear + 1) % capacity;
        data[rear] = item;
        size++;
    }

    
    T dequeue() {
        if (size == 0) {
            throw QueueUnderflowException(); 
        }
        T item = data[front];
        front = (front + 1) % capacity;
        size--;
        return item;
    }

    
    int getSize() const {
        return size;
    }

    
    bool isEmpty() const {
        return size == 0;
    }

    
    bool isFull() const {
        return size == capacity;
    }
};

int main() {
    try {
        Queue<int> q(2); 

        cout << "Enqueueing 1" << endl;
        q.enqueue(1);
        cout << "Enqueueing 2" << endl;
        q.enqueue(2);

        cout << "Attempting to enqueue to a full queue ..." << endl;
        q.enqueue(3);
    } catch (const QueueOverflowException& e) {
        cout << "Caught QueueOverflowException - " << e.what() << endl;
    }

    try {
        Queue<int> q(2);

        cout << "Attempting to dequeue from an empty queue ..." << endl;
        q.dequeue();  
    } catch (const QueueUnderflowException& e) {
        cout << "Caught QueueUnderflowException - " << e.what() << endl;
    }

    return 0;
}
