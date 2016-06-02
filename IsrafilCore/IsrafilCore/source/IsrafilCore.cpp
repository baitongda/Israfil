#include <IsrafilCore/IsrafilCore.h>

namespace Israfil{
namespace Core{

IsrafilCore::IsrafilCore()
{
    pQM = new Israfil::QQMusic::QQMusic();
}

SongList IsrafilCore::SearchSong(std::string strName)
{
    //currently just return the qm search result
    SongList retSL;
    bool bSS = pQM->SearchSong(strName, retSL);
    //if (bSS == false) return;
    dbg(bSS);
    return retSL;
}


}
}
