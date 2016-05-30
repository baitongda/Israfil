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
    bool SearchSong(std::string name, std::vector<SongBase>& rVecSongBase);
private:
    bool SplitF(std::string FString, std::vector<std::string>& FArray);
    bool isAtString(std::string FAtString); //isAtString
    Israfil::Network::HttpClient *hc;

};


}
}
#endif // QQMUSIC_H
