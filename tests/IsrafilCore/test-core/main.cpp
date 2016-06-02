#define CATCH_CONFIG_MAIN
#include "../test/catch.hpp"

#include <IsrafilCore/IsrafilCore.h>

TEST_CASE("Israfil::Core Basic Tests - Search", "Search Song") {
    Israfil::Core::IsrafilCore *ic = new Israfil::Core::IsrafilCore();
    auto res = ic->SearchSong("Soledad");
    for (int i=0; i<res.size(); i++){
        std::cout << res[i].sName << std::endl;
    }
}
