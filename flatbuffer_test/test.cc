#include <iostream>
#include "test_generated.h"

int main() {
  flatbuffers::FlatBufferBuilder builder_data;
  auto name = builder_data.CreateString("string");
  int num = 11;
  auto test = Createtest(builder_data, num, name);
  builder_data.Finish(test);

  char* ptr = (char*)builder_data.GetBufferPointer();
  auto test_out = Gettest((uint8_t*)ptr);
  std::cout << test_out->id() << std::endl;
  std::cout << test_out->str()->c_str() << std::endl;
}
