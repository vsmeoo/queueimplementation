#pragma once
#include <iostream>
using namespace std;

template <typename T>
class queueinterface
{
    public:
        virtual ~queueinterface(){}
        virtual void push(const T& element ) = 0;
        virtual void dequeue() =0;
        virtual int size() const = 0;
        virtual T front() const = 0;
        virtual bool isempty() const = 0;
        virtual void display() const = 0;
};
