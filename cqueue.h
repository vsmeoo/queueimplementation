#pragma once
#include <iostream>
#include "queueinterface.h"
using namespace std;

template <typename T>
class cqueue: public queueinterface<T>{
    int first;
    int rear;
    T *arr;
    int max;
    int count;

    public:

    cqueue(int size){
        max = size;
        arr = new T[max];
        first = rear = -1;
        count = 0;
    }

    bool isempty() const override{
        return first==-1;
    }

    void push(const T& element) override{
        if(first == (rear+1)%max){
            cout<<"queue full"<< endl;
            return;
        }
        
        if(isempty()){
            first = 0;
        }
        

        rear = (rear+1)%max;
        arr[rear] = element;
        count++;
    }

    void dequeue() override{
        if(isempty()){
            cout<<"queue empty"<< endl;
            return;
        }

        if(first==rear){
            first = rear = -1;
            return;
        }

        first = (first+1)%max;
        count--;

    }

    T front() const override{
        if(isempty()){
            cout<<"queue empty";
            return T();
        }

        return arr[first];
        
    }

    int size() const override{
        return count;
    }

    void display() const override{
        if(isempty()){
            cout<<"queue empty";
            return;
        }
        int i = first;
        for (int c = 0; c < count; c++) {
            cout << arr[i] << " ";
            i = (i + 1) % max;
        }
        cout << endl;
    }

};