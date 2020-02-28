/*************************************************************************
	> File Name: LeetCode232.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月28日 星期五 17时33分16秒
 ************************************************************************/
typedef struct MyStack {
    int *data;
    int top;
} MyStack;

MyStack *MyStackCreate(int size) {
    MyStack *s = (MyStack *)malloc(sizeof(MyStack));
    s->data = (int *)malloc(sizeof(int) * size);
    s->top = -1;
    return s;
}
void MyStackPush(MyStack *obj, int x) {
    obj->data[++obj->top] = x;
}

int MyStackPop(MyStack *obj) {
    return obj->data[obj->top--];
}

int MyStackTop(MyStack *obj) {
    return obj->data[obj->top];
}

int MyStackEmpty(MyStack *obj) {
    return obj->top == -1;
}

void MyStackFree(MyStack *obj) {
    if (obj == NULL) return ;
    free(obj->data);
    free(obj);
    return ;
}

typedef struct {
    MyStack *s1, *s2;
} MyQueue;

MyQueue *myQueueCreate() {
    int size = 1024;
    MyQueue *q = (MyQueue *)malloc(sizeof(MyQueue));
    q->s1 = MyStackCreate(size);
    q->s2 = MyStackCreate(size);
    return q;
}

void myQueuePush(MyQueue *obj, int x) {
    MyStackPush(obj->s1, x);
}
int myQueuePop(MyQueue *obj) {
    if (MyStackEmpty(obj->s2)) {
        while (!MyStackEmpty(obj->s1)){ 
        	MyStackPush(obj->s2, MyStackPop(obj->s1));
        }
    }
    return MyStackPop(obj->s2);
}

int myQueuePeek(MyQueue *obj) {
    if (MyStackEmpty(obj->s2)) {
        while (!MyStackEmpty(obj->s1)) {
            MyStackPush(obj->s2, MyStackPop(obj->s1));
        }
    }
    return MyStackTop(obj->s2);
}

bool myQueueEmpty(MyQueue *obj) {
    return MyStackEmpty(obj->s1) && MyStackEmpty(obj->s2);
}

void myQueueFree(MyQueue *obj) {
    if (obj == NULL) return ;
    MyStackFree(obj->s1);
    MyStackFree(obj->s2);
    return ;
}
