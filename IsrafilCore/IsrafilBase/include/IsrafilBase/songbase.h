#ifndef SONGBASE_H
#define SONGBASE_H

#include <string>
#include <vector>
using std::string;
using std::vector;

namespace Israfil{
namespace SongBase{

#define srcNetease 1
#define srcQQMusic 2
#define srcXiami 3
#define srcKugou 4

struct Musician{ //Artists
    string mName;
    string mID;
    string mNumOfAlbums;
    string mNumOfSongs;
};

struct Album{
    string aName;
    string aID;
    string aPicURL;
    Musician aSinger;
};

struct Song{
    string sName;
    string sID;
    vector<Musician> sSingers;
    Album sAlbum;
    int sSource;
    bool sOnly;
    vector<string> Mp3URL; //Mp3URL[0] is the highest bitrate
    vector<string> PicURL;
    vector<string> LyricsURL;
    string DevString;
};

}
}

#endif // SONGBASE_H
