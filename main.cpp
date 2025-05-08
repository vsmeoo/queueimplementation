#include "queueinterface.h"
#include "listqueue.h"
#include "arrayqueue.h"
#include <iostream>
using namespace std;

int main(){
    queueinterface<int>* aq = new arrayqueue<int>(5);
    aq->push(10);
    aq->push(20);
    aq->dequeue();
    aq->display();
    return 0;
    
}