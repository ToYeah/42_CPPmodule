#include "Serialize.hpp"

uintptr_t serialize(Data* ptr) { return reinterpret_cast<uintptr_t>(ptr); }

Data* deserialize(uintptr_t raw) { return reinterpret_cast<Data*>(raw); }

int main() {
  Data data;
  data.name = "Taro";
  data.age = 10;

  uintptr_t a = serialize(&data);
  Data* b = deserialize(a);

  std::cout << "&Data     : " << std::hex << &data << std::endl;
  std::cout << "uintptr_t : "
            << "0x" << std::hex << a << std::endl;
  std::cout << "Data*     : " << b << std::endl;
}
