#include "stdio.h"
#include "qqmusic.h"
#include "rapidjson/document.h"

namespace Israfil{
namespace QQMusic{


QQMusic::QQMusic()
{
    hc = new Israfil::Network::HttpClient();
    hc->addHeader("User-Agent: Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/48.0.2564.103 Safari/537.36");
    hc->addHeader("Accept: */*");
//    hc->addHeader("Accept-Encoding: gzip,deflate,sdch");
    hc->addHeader("Accept-Language: en-us");
    hc->addHeader("Connection: keep-alive");
    hc->addHeader("Content-Type: application/x-www-form-urlencoded");
    hc->addHeader("Host: y.qq.com");
    hc->addHeader("Referer: y.qq.com");
}

vector<SongBase> QQMusic::SearchSong(string name)
{
    vector<SongBase> rVecSongBase;
    string rSongSearch = hc->HttpGet(Israfil::strfmt::Format(QMSearchURL, 20, name));
    dbg(rSongSearch);
    return rVecSongBase; //TODO: remove this;
}

}
}
