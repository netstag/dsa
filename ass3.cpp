#include <iostream>
using namespace std;
class CircularQueue
{
public:
    int front;
    int back;
    int size;     // current size
    int capacity; // max size
    int *arr;

    CircularQueue(int capacity)
    {
        this->capacity = capacity;
        arr = new int[capacity];
        front = -1;
        back = -1;
        size = 0;
    }

    void enQueue(int val)//FIFO
    {
        if (size == capacity)
        {
            cout << "Queue is full!" << endl;
            return;
        }
        if (back == capacity)
        {
            back = 0;
        }
        arr[back] = val;
        back++;
        size++;
    }
    void deQueue()//POP
    {
        if (size == 0)
        {
            cout << "Cannot pop queue is empty!" << endl;
            return;
        }
        front++;
        if (front == capacity)
        {
            front = 0;
        }
        size--;
    }
    void Display()
    {
         if (size == 0)
        {
            cout << "Queue is empty!" << endl;
            return;
        }
        int i = front;
        for (int count = 0; count < size; count++)
        {
            cout << arr[i] << " ";
            i++;
            if (i == capacity)
                i = 0;
        }
        cout << endl;
    
    }
};
int main()
{
    CircularQueue q(5);
    q.enQueue(1);
    q.enQueue(2);
    q.enQueue(3);
    q.enQueue(4);
    q.enQueue(5);
    q.enQueue(66);
    q.Display();
    q.deQueue();
    q.enQueue(66);
    q.Display();

}
