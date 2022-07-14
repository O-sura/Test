#include <stdlib.h>
#include <stdio.h>
#define CIRCULAR
//define LINEAR

int queue[4];
int len = sizeof(queue)/sizeof(queue[0]);
int front = -1;
int rear = -1;

#ifdef LINEAR
void enqueue(int x){
    if(isFull())
        printf("Queue is full\n");
    else{
        if(rear == -1 && front == -1)
            front = rear = 0;
        else
            rear++;
        queue[rear] = x;
        printf("Enqueued: %d\n",x);
    }

}

void dequeue(){
    if(isEmpty())
        printf("Queue is Empty\n");
    else{
        printf("Dequeued: %d\n",queue[front]);
        front++;
        if(front > rear)
            front = rear = -1;
    }
}

int isFull(){
    if(rear == len - 1)
        return 1;
    else return 0;

}

int isEmpty(){
    if(front == -1 && rear == -1)
        return 1;
    else
        return 0;
}

#endif // LINEAR

#ifdef CIRCULAR
void enqueue(int x){
        if(isFull())
            printf("Queue is Full\n");
        else{
            if(rear == -1 && front == -1)
                front = rear = 0;
            else
                rear = (rear + 1)%len;
            queue[rear] = x;
            printf("Enqueued: %d\tFront: %d\tRear: %d\n",x,front,rear);
        }

}

void dequeue(){
        if(isEmpty())
            printf("Queue is Empty\n");
        else{
            printf("Dequeued: %d\tFront: %d\tRear: %d\n",queue[front],front,rear);
            front = (front + 1)%len;
            if(front > rear)
                front = rear = -1;
        }

}


void printQueue(){
        for(int i = front;i<len;i++){
            printf("%d\t",queue[i]);
        }
        for(int i = 0;i< rear+1;i++)
            printf("%d\t",queue[i]);
}

int isEmpty(){
    if(front == -1)
        return 1;
    else return 0;
}

int isFull(){
    if((front == rear+1) || (front == 0 && rear == len-1))
        return 1;
    else return 0;
}

#endif // CIRCULAR


int main(){
    enqueue(10);
    enqueue(21);
    enqueue(7);
    enqueue(22);
    dequeue();
    dequeue();
    dequeue();
    dequeue();
}
