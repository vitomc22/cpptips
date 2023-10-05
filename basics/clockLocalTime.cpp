/* localtime example */
#include <cstddef>
#include <cstdlib>
#include <ostream>
#include <stdio.h>      /* puts, printf */
#include <time.h>       /* time_t, struct tm, time, localtime */
#include <unistd.h>
#include <iostream>
#include <string>
int main ()
{  
  while (true) {
  time_t rawtime;
  struct tm * timeinfo; //struct
  time (&rawtime);
  timeinfo = localtime (&rawtime);
  std::cout << asctime(timeinfo) << std::endl;  
  sleep(1);
  std::system("clear");  
  timeinfo = nullptr;
  }

  return 0;
}