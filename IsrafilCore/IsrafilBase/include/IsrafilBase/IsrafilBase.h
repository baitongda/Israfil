
#pragma once


#include <string>

#include <IsrafilCore-api.h>
#include "songbase.h"
#include "strfmt.h"

#define dbg(x) std::cout << #x " = " << (x) << std::endl


namespace Israfil{
namespace Base{


/**
*  @brief
*    Print information about the library to the console
*/
ISRAFILCORE_API void printInfo();


} // namespace baselib
} // namespace Israfil
