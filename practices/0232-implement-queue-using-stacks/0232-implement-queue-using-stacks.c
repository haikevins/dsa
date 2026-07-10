#include <stdbool.h>
#include <stdlib.h>

typedef struct 
{
    int* inStack;
    int* outStack;

    int inTop;
    int outTop;

    int capacity;
} MyQueue;


MyQueue* myQueueCreate() 
{
    MyQueue* obj = (MyQueue*)malloc(sizeof(MyQueue));

    obj->capacity = 100;

    obj->inStack = (int*)malloc(obj->capacity * sizeof(int));
    obj->outStack = (int*)malloc(obj->capacity * sizeof(int));

    obj->inTop = -1;
    obj->outTop = -1;

    return obj;
}

void myQueuePush(MyQueue* obj, int x) 
{
    obj->inTop++;
    obj->inStack[obj->inTop] = x;
}

int myQueuePop(MyQueue* obj) 
{
    /*
        If outStack is empty, move all elements
        from inStack to outStack.
    */
    if (obj->outTop == -1) 
    {
        while (obj->inTop >= 0) 
        {
            obj->outTop++;
            obj->outStack[obj->outTop] = obj->inStack[obj->inTop];
            obj->inTop--;
        }
    }

    int value = obj->outStack[obj->outTop];
    obj->outTop--;

    return value;
}

int myQueuePeek(MyQueue* obj) 
{
    if (obj->outTop == -1) 
    {
        while (obj->inTop >= 0) 
        {
            obj->outTop++;
            obj->outStack[obj->outTop] = obj->inStack[obj->inTop];
            obj->inTop--;
        }
    }

    return obj->outStack[obj->outTop];
}

bool myQueueEmpty(MyQueue* obj) 
{
    return (obj->inTop == -1) && (obj->outTop == -1);
}

void myQueueFree(MyQueue* obj) 
{
    free(obj->inStack);
    free(obj->outStack);
    free(obj);
}