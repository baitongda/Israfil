#ifndef SONGBASE_H
#define SONGBASE_H

#include <string>
#include <vector>
using std::string;
using std::vector;

namespace Israfil{
namespace SongBase{

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

struct SongBase{
    string sName;
    string sID;
    vector<Musician> sSingers;
    Album sAlbum;
    vector<string> Mp3URL; //Mp3URL[0] is the highest bitrate
    vector<string> PicURL;

};

}
}

#endif // SONGBASE_H
