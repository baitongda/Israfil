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
    std::string SearchNameInput;
    std::cout<< "Don\'t run inside Qt Creator!"<< std::endl << "Input the name you wonna search" << std::endl;
    std::cin >> SearchNameInput;
    qm->SearchSong(SearchNameInput, ret);
    dbg(ret.size());
    for (int i=0;i<ret.size();i++){
        std::cout << ret[i].sName << " :: " << ret[i].sSingers[0].mName << " :: " << ret[i].Mp3URL[0] \
                  << " :: " << ret[i].LyricsURL[0] << " : " \
                  << ret[i].PicURL[0] << " vs " << ret[i].sAlbum.aPicURL <<std::endl;
    }

}
