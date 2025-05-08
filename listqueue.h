#pragma once
#include <iostream>
#include "queueinterface.h"
using namespace std;

template <typename T>
class listqueue;
template <typename T>
class Node{
    private:
    T data;
    Node<T> *next;

    public:
    Node(T val){
        data = val;
        next = nullptr;
    }

    friend class listqueue<T>;
    
};

template <typename T>
class listqueue: public queueinterface<T>{
    
    Node<T> *head;
    Node<T> *tail;
    int count;

    public:
    listqueue(){
        head = tail = nullptr;
        count = 0;
    }

    bool isempty() const override{
        return head==nullptr;
    }
    void push(const T& element) override{
        Node<T> *newnode = new Node(element);
        if(isempty()){
            head=tail=newnode;
            newnode->next = nullptr;
            count++;
            return;
        }
        tail->next = newnode;
        tail = newnode;
        count++;
    }

    void dequeue() override{
        if(isempty()){
            cout<<"empty queue"<< endl;
            return;
        }
        Node<T> *temp = head;
        head= temp->next;
        temp->next = nullptr;
        delete temp;
        count--;

    }

    int size() const override{
        return count;
    }

    T front() const override{
        return head->data;
    }

    void display() const{
        Node<T> *temp = head;
        while(temp->next != nullptr){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<temp->data;
    }
};