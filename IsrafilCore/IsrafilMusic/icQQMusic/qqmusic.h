#ifndef QQMUSIC_H
#define QQMUSIC_H
#include "base.h"
#include "IsrafilNetwork/IsrafilNetwork.h"

namespace Israfil{
namespace QQMusic{

class QQMusic
{
public:
    QQMusic();

private:
    Israfil::Network::HttpClient *hc;

};


}
}
#endif // QQMUSIC_H
