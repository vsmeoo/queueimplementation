#pragma once
#include "queueinterface.h"
#include <iostream>
using namespace std;

template <typename T>
class arrayqueue: public queueinterface<T>{
    T* arr;
    int first=0,rear=-1;
    int capacity;

    public:
    arrayqueue(int size){
        capacity=size;
        rear = -1;
        first = 0;
        arr = new T[capacity];
    }

    bool isempty() const override{
        return first>rear;
    }
    
    void push(const T& element) override{
        if(rear==capacity-1){
            cout<<"queue full";
            return;
        }
        arr[++rear] = element;
    }

    void dequeue() override{
        if(isempty()){
            cout<<"queue empty";
            return;
        }
        first++;

    }

    int size() const override{
        return rear+1;
    }

    T front() const override{
        if(isempty()){
            cout<<"queue empty";
        }
        return first;
    }

    void display() const override{
        if(isempty()){
            cout<<"queue empty";
            return;
        }

        for(int i=first;i<=rear;i++){
            cout<<arr[i]<<" ";
        }
    }
};
