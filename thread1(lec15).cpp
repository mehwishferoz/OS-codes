#include<iostream>
#include<thread>
#include<unistd.h>

using namespace std;

void taskA(){
    for (int i = 0; i < 10; i++)
    {
        sleep(1);
        printf("Task A: %d\n", i+1);
        fflush(stdout);
    }
}

void taskB(){
    for (int i = 0; i < 10; i++)
    {
        sleep(1);
        printf("Task B: %d\n", i+1);
        fflush(stdout);
    }
}

int main(){
    thread t1(taskA), t2(taskB);
    t1.join();
    t2.join();
    // join() because w/o it the main will exit and process aborted error is thrown 

    return 0;
}