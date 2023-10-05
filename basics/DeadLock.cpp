#include <iostream>
#include <thread>
#include <mutex>
 
void task1(std::mutex& m1, std::mutex& m2)
{
  std::cout << "Thread 1 acquiring lock for mutex 1.." << std::endl;
  m1.lock();
  std::this_thread::sleep_for(std::chrono::milliseconds(10));
 
  std::cout << "Thread 1 acquiring lock for mutex 2.." << std::endl;
  m2.lock();
  std::this_thread::sleep_for(std::chrono::milliseconds(10));
}
 
void task2(std::mutex& m1, std::mutex& m2)
{
  std::cout << "Thread 2 acquiring lock for mutex 2.." << std::endl;
  m2.lock();
  std::this_thread::sleep_for(std::chrono::milliseconds(10));
  std::cout << "Thread 2 releasing lock for mutex 2.." << std::endl;
  m2.unlock();
 
  std::cout << "Thread 2 acquiring lock for mutex 1.." << std::endl;
  m1.lock();
  std::this_thread::sleep_for(std::chrono::milliseconds(10));
  std::cout << "Thread 2 releasing lock for mutex 1.." << std::endl;
  m1.unlock();
}
 
int main() {
  std::mutex m1;
  std::mutex m2;
 
  // Create and execute two threads
  std::thread t1(task1, ref(m1), ref(m2));
  std::thread t2(task2, ref(m1), ref(m2));
 
  // Stop main thread from executing until the other threads end.
  // This will never happen though, since the threads are obtaining locks
  // on two different mutexes in different orders and at different times.
  // Since the first thread doesn't release the locks correctly, the second thread
  // will block, creating a deadlock.
  t1.join();
  t2.join();
}

