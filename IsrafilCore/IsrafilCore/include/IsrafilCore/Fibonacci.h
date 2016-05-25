
#pragma once


#include <IsrafilCore-api.h>


namespace fiblib
{


/**
*  @brief
*    Calculator of fibonacci numbers
*/
class ISRAFILCORE_API Fibonacci
{
public:
    /**
    *  @brief
    *    Constructor
    */
    Fibonacci();

    /**
    *  @brief
    *    Destructor
    */
    virtual ~Fibonacci();

    /**
    *  @brief
    *    Calculate fibonacci number
    *
    *  @param[in] i
    *    Index
    *
    *  @return
    *    Value of the i'th fibonacci number
    */
    unsigned int operator()(unsigned int i);
};


} // namespace fiblib
