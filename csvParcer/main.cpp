#include <array>
#include <cstddef>
#include <cstdio>
#include <cstring>
#include <fmt/core.h>
#include <fmt/format.h>
#include <fstream>
#include <string>

auto main(int argc, char **argv) -> int {
  std::ifstream file(argv[1]);
  if (argc > 1) {
    if (file.is_open()) {
      std::string line{};
      const char *delim = ",";
      std::array<std::string, 3> fields{"NAME", "EMAIL", "OBS"};
      int i{};
      while (std::getline(file, line)) {      // save content file in line
        char *buffer = &line[0];              // pointer buffer to line
        char *pline = strsep(&buffer, delim); // pointer token with delimiter
                                              // ","
        while (pline != NULL) {
          fmt::print("{}: {}\n", fields[i],
                     pline); // fields -> "NAME", "EMAIL", "OBS"
          pline = strsep(&buffer, delim);
          ++i;
          if (i > 2) {
            fmt::print("--------------------\n");
            i = 0;
          }
        }
      }
    }
    file.close();
  } else {
    fmt::print(stderr, "Use: {} file.csv\n", argv[0]);
  }
}