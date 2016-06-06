#include <string>
#include <sstream>

#include <IsrafilBase/utils.h>


namespace Israfil {
namespace Base {
int StringToInt(std::string Str) {
  std::stringstream ss;
  int num;

  ss << Str;
  ss >> num;
  return num;
}
}
}
