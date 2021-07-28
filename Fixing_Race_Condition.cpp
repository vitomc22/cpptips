#include<string>
#include<sstream>
#include<iostream>
#include<thread>
#include<mutex>


std::mutex task_lock;

//shared object that the thread function will both read an write
int counter = 0;

//this function will be executed in the new thread
 void task()
{
    task_lock.lock();    
    counter += 1;
    std::ostringstream msg;
    msg << "counter = " << counter << std::endl;
    std::cout << msg.str();
    task_lock.unlock();    
}

int main()
{
    //Constructs three threads and runs them. Does not block execution.
    std::thread t1(task);
    std::thread t2(task);
    std::thread t3(task);

//Makes the main thread wait for the new threads to finish execution, therefore bloking its own execution
    t1.join();
    t2.join();
    t3.join();

} 