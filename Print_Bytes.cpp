#include <iostream>
using namespace std;
template <typename T>
void printBytes(const T& input, std::ostream& op = std::cout)
{
  const unsigned char* p = reinterpret_cast<const unsigned char*>(&input);
  op << std::hex << std::showbase;
  op << "(";
  for (unsigned int i=0; i<sizeof(T); ++i)
    op << static_cast<int>(*(p++)) << " ";
  op << ")" << std::endl;
}

int main()
{
  string i = "mohit";
  printBytes(i);
  float x = 7.34f;
  printBytes(x);
}
