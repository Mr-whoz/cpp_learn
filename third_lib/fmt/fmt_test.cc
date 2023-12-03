#include <map>
#include <string>

#include <fmt/core.h>
#include "fmt/ranges.h"

int main() {
  fmt::println("The answer is {}", 42);
  std::map<std::string, int> students = {
      {"lisa", 20},
      {"john", 10},
  };
  fmt::println("The answer is {}", students);
}