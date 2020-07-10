#include "fstream"
#include "test.pb.h"

int main() {
  lm::test msg1;
  msg1.set_id(10);
  msg1.set_str("test");

  std::fstream output;
  output.open("config", std::ios::out | std::ios::trunc | std::ios::binary);
  if (!msg1.SerializeToOstream(&output)) {
    std::cerr << "Fail to write" << std::endl;
    return -1;
  }
  output.close();

  std::fstream input("config", std::ios::in | std::ios::binary);
  if (!msg1.ParseFromIstream(&input)) {
    std::cerr << "Fail read" << std::endl;
    return -1;
  }
  std::cout << msg1.id();
  std::cout << msg1.str();
  input.close();
  return 0;
}
