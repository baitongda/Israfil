#ifndef NETEASE_H
#define NETEASE_H

#include "base.h"
#include "IsrafilNetwork/IsrafilNetwork.h"
#include "IsrafilBase/IsrafilBase.h"

using namespace Israfil::SongBase;
using namespace Israfil::Base;

namespace Israfil {
namespace Netease {
class ISRAFILCORE_API Netease {
public:

  Netease();
  std::string encryptID(std::string id);
  bool        SearchSong(std::string        name,
                         std::vector<Song>& rVecSongBase);

private:
  Israfil::Network::HttpClient *hc;
};
}
}

#endif // NETEASE_H
