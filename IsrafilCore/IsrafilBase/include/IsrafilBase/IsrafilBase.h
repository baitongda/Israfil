
#pragma once


#include <string>

#include <IsrafilCore-api.h>
#include "songbase.h"
#include "strfmt.h"

#define dbg(x) std::cout \
    << "IsrafilDBG::" \
    << __FUNCTION__ \
    << "() " \
    << "@ "\
    << __TIMESTAMP__ \
    << "\n"\
    << __FILE__ \
    << " L" \
    << __LINE__ \
    << " \n" \
    << #x " = " \
    << (x) \
    << std::endl \
    << std::endl

#define dbgerr(x) std::cout \
    << "IsrafilDBG::ERROR::" \
    << __FUNCTION__ \
    << "() " \
    << "@ "\
    << __TIMESTAMP__ \
    << "\n"\
    << __FILE__ \
    << " L" \
    << __LINE__ \
    << " \n" \
    << #x " = " \
    << (x) \
    << std::endl \
    << std::endl

namespace Israfil{
namespace Base{


/**
*  @brief
*    Print information about the library to the console
*/
ISRAFILCORE_API void printInfo();


} // namespace baselib
} // namespace Israfil
