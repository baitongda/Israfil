#define CATCH_CONFIG_MAIN

#include "../test/catch.hpp"
#include <iostream>
#include <vector>
#include "qqmusic.h"
#include "IsrafilBase/IsrafilBase.h"

using namespace Israfil::QQMusic;
using std::vector;

TEST_CASE("Israfil::QQMusic Basic Tests - Search", "QQMusic") {
    vector<SongBase> ret;
    QQMusic *qm = new QQMusic();
    qm->SearchSong("uptown");
}
