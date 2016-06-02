
#pragma once


#include <string>

#include <IsrafilCore-api.h>
#include "songbase.h"
#include "strfmt.h"
#include "utils.h"

typedef std::vector<Israfil::SongBase::Song> SongList;

namespace Israfil{
namespace Base{


/**
*  @brief
*    Print information about the library to the console
*/
ISRAFILCORE_API void printInfo();


} // namespace baselib
} // namespace Israfil
