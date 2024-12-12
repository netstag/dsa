#include <iostream>
#include <vector>
using namespace std;
class Queue {
    public:
    int f;
    int b;
    int s; //change all if-else b-f/size by s. (s is the curr size)
   int* arr ;
    Queue (int size){
        f=0;
        b=0;
        s=0;  
        
     arr = new int[size];

    }
    //push (we push from the rear side after pushing b++)
    void push (int val){
        if(b==5){
            cout<<"Queue is full";
        }
        arr[b] = val;
        b++;
        s++;
    }
    //pop (we pop from the front side)
    void pop(){
        if(s==0){
            cout<<"Queue is EMPTY";
            return;
        }
        f++;
        s--;
    }
    //front  retruning the front element
    int front(){
        if(s==0){
            cout<<"Queue is EMPTY";  
             
        }
        return arr[f];
    }

    //back retruning the back (we always b++ after pushing so the back postion  is at the b-1)
    int rear (){
         if(s==0){
            cout<<"Queue is EMPTY";  
                   
        }
       return arr[b-1];
    }
    //size
    int size(){
        return s;
    }
    //empty
    bool empty(){
       return s==0;
    }
    //display
    void display (){
        for(int i=f; i<b; i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};

int main (){
    Queue q(5);
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
     q.push(5);
    q.display();
    // q.pop();
    //  q.display();
    cout<<q.size();

    return 0;
}
