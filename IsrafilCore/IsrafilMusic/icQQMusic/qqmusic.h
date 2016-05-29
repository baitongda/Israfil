#ifndef QQMUSIC_H
#define QQMUSIC_H
#include "base.h"
#include "IsrafilNetwork/IsrafilNetwork.h"
#include "IsrafilBase/IsrafilBase.h"

//using namespace Israfil::SongBase;

namespace Israfil{
namespace QQMusic{

using Israfil::SongBase::SongBase;

class QQMusic
{
public:
    QQMusic();
    vector<SongBase> SearchSong(string name);
private:
    Israfil::Network::HttpClient *hc;

};


}
}
#endif // QQMUSIC_H
