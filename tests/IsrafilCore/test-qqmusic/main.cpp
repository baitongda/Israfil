#define CATCH_CONFIG_MAIN

#include "../test/catch.hpp"
#include <iostream>
#include <vector>
#include "qqmusic.h"
#include "IsrafilBase/IsrafilBase.h"

using namespace Israfil::QQMusic;
using namespace Israfil::SongBase;
using std::vector;


TEST_CASE("Israfil::QQMusic Basic Tests - Search", "QQMusic") {
    vector<SongBase> ret;
    QQMusic *qm = new QQMusic();
    qm->SearchSong("七里香", ret);
    dbg(ret.size());
    for (int i=0;i<ret.size();i++){
        std::cout << ret[i].sName << " :: " << ret[i].sSingers[0].mName << " :: " << ret[i].Mp3URL[0] << std::endl;
    }

}
