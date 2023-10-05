#include <chrono>
#include <ctime>
#include <fmt/core.h>
#include <fmt/format.h>
#include <iostream>
#include <string>
auto main(int argc, char **argv) -> int {

  auto timeNow = []() {
    auto now = std::chrono::system_clock::now();
    auto time = std::chrono::system_clock::to_time_t(now);
    return std::ctime(&time);
  };
  std::cout << timeNow();
}

//Using a lambda function and chrono namespace to return the current date