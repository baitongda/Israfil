#ifndef CRYPTO_H
#define CRYPTO_H
#include <string>
#include <vector>
using std::string;
using std::vector;

namespace Israfil {
namespace crypto {
class crypto {
public:

  vector<unsigned char>md5enc(vector<unsigned char>);
  vector<unsigned char>b64enc(vector<unsigned char>);
  string               ByteArrayToStr(vector<unsigned char>);
  vector<unsigned char>StrToByteArray(string str);
  vector<unsigned char>ByteToByteArray(unsigned char* bt);

private:

  unsigned int left_rotate(unsigned int num,
                           int          r);
};
}
}
#endif // CRYPTO_H
