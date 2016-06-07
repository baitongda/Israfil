#include <cstring>
#include <cmath>
#include <IsrafilBase/crypto.h>
#include <IsrafilBase/md5.h>

namespace Israfil {
namespace crypto {
vector<unsigned char>crypto::StrToByteArray(string str)
{
  vector<unsigned char> arr;

  for (int i = 0; i < str.length(); i++) arr.push_back(str[i]);
  return arr;
}

string crypto::ByteArrayToStr(vector<unsigned char>arr) {
  string res;

  for (int i = 0; i < arr.size(); i++) {
    res.push_back(arr[i]);
  }
  return res;
}

vector<unsigned char>crypto::ByteToByteArray(unsigned char *bt) {
  vector<unsigned char> ret;

  for (int i = 0; i < 16; i++) {
    ret.push_back(bt[i]);
  }
  return ret;
}

unsigned int crypto::left_rotate(unsigned int num, int r) {
  unsigned int temp = num;

  num  <<= r;
  temp >>= 32 - r;
  return num + temp;
}

vector<unsigned char>crypto::md5enc(vector<unsigned char>in_arr)
{
  auto md5enc = MD5(ByteArrayToStr(in_arr));
  return ByteToByteArray((unsigned char *)md5enc.getDigest());
}

vector<unsigned char>crypto::b64enc(vector<unsigned char>in_arr)
{
  unsigned int   len        = in_arr.size();
  unsigned int   byte_n     = len + (len % 3 == 0 ? 0 : (len % 3 == 2 ? 1 : 2));
  unsigned char *byte_array = new unsigned char[byte_n];

  memset(byte_array, 0, sizeof(unsigned char) * byte_n);

  for (vector<unsigned char>::const_iterator it = in_arr.begin(); it != in_arr.end(); ++it) byte_array[it - in_arr.begin()] = *it;

  const char   code_map[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/=\n";
  unsigned int out_len    = byte_n * 8 / 6 - (len % 3 == 0 ? 0 : (len % 3 == 2 ? 1 : 2));
  out_len += out_len / 76;
  out_len += (len % 3 == 0 ? 0 : (len % 3 == 2 ? 1 : 2));
  vector<unsigned char> out_arr;

  int offset = 0;

  for (int i = 0; i < out_len; ++i) {
    if (i % 77 == 76) {
      out_arr.push_back(65);
    } else if (offset < len * 8) {
      char v = 0;
      v += (unsigned char)(byte_array[offset / 8] << (offset % 8)) >> 2;

      if (offset % 8 > 2) v += (unsigned char)(byte_array[offset / 8 + 1]) >> (10 - offset % 8);
      out_arr.push_back(v);
      offset += 6;
    } else {
      out_arr.push_back(64);
    }
  }

  for (vector<unsigned char>::iterator it = out_arr.begin(); it != out_arr.end(); ++it) {
    int index = *it;
    *it = code_map[index];
  }
  delete[] byte_array;
  return out_arr;
}
}
}
