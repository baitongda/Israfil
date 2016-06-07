#include <netease.h>
#include <sstream>
#include <cstring>
#include <iostream>
using std::ostringstream;

namespace Israfil {
namespace Netease {
Netease::Netease()
{}


string Netease::encryptID(string dfsID)
{
  Israfil::crypto::crypto *crt = new Israfil::crypto::crypto();

  int  magiclength = NEMagicKey.length();
  int  idlength    = dfsID.length();
  auto dfsArray    = crt->StrToByteArray(dfsID);

  vector<unsigned char> strans;

  for (int i = 0; i < idlength; i++) strans.push_back(dfsArray[i] ^ NEMagicKey[i % magiclength]);
  auto res = crt->b64enc(crt->md5enc(strans));

  ostringstream out_stream;

  for (vector<unsigned char>::iterator it = res.begin(); it !=
       res.end(); ++it) {
    if (*it == '/') out_stream.put('_');
    else if (*it == '+') out_stream.put('-');
    else out_stream.put(*it);
  }
  return out_stream.str();
}
}
}
