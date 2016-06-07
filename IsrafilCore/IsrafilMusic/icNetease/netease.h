#ifndef NETEASE_H
#define NETEASE_H

#include "base.h"
#include "IsrafilNetwork/IsrafilNetwork.h"
#include "IsrafilBase/IsrafilBase.h"

namespace Israfil {
namespace Netease {
class ISRAFILCORE_API Netease {
public:

  Netease();
  string encryptID(string id);
};
}
}

#endif // NETEASE_H
