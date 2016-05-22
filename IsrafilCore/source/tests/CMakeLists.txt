
# 
# Setup test environment
# 

# Check if tests are enabled
if(NOT OPTION_BUILD_TESTS)
    return()
endif()

# DISABLE CMP0037: Target names should not be reserved and should match a validity pattern.
set_policy(CMP0037 OLD)

include_directories(test)
add_subdirectory(network-test)
