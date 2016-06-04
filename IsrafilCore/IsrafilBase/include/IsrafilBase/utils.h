#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <IsrafilCore-api.h>


namespace Israfil{
namespace Base{


#define ISRAFILDBGSILENT

#ifdef ISRAFILDBG
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
#endif
#ifdef ISRAFILDBGSILENT
#define dbg(x)
#define dbgerr(x)
#endif



//#define dbg(x) std::cout<< #x "= " << (x) <<std::endl;
//#define dbgerr(x) std::cout<< "ERROR: " #x "= " << (x) <<std::endl;
//#endif
//#endif



ISRAFILCORE_API int StringToInt(std::string Str);

}
}

#endif // UTILS_H
