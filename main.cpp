#include "queueinterface.h"
#include "listqueue.h"
#include "arrayqueue.h"
#include "cqueue.h"
#include <iostream>
using namespace std;

int main(){
    queueinterface<int>* cq = new cqueue<int>(5);
    cq->push(10);
    cq->push(20);
    cq->dequeue();
    cq->display();
    cq->push(30);
    cq->push(40);
    cq->push(50);
    cq->push(60);
    cq->push(70);
    cq->display();
    cq->dequeue();
    cq->display();
    return 0;
    
}