#include <IsrafilBase/songbase.h>

#include <rapidjson/document.h>
#include <rapidjson/writer.h>
#include <rapidjson/stringbuffer.h>
#define RAPIDJSON_HAS_STDSTRING 1

namespace Israfil{
namespace SongBase{

string SongListToJson(SongList inSL)
{
    using namespace rapidjson;
#define SREF(x) StringRef(x.c_str())
    Document document;
    document.SetObject();
    Document::AllocatorType& allocator = document.GetAllocator();
    //auto& allocator = document.GetAllocator();

    Value arrSongs(kArrayType);

    for (int i=0; i<inSL.size(); i++){ // for SongItem
        Value SongItem(kObjectType);
        SongItem.AddMember("sName", SREF(inSL[i].sName), allocator);
        SongItem.AddMember("sID", SREF(inSL[i].sID), allocator);
        SongItem.AddMember("uID", SREF(inSL[i].uID), allocator);

        Value arrSingers(kArrayType);
        for (int j=0; j<inSL[i].sSingers.size(); j++){ // for SingerItem
            Value SingerItem(kObjectType);
            SingerItem.AddMember("mName", SREF(inSL[i].sSingers[j].mName), allocator);
            SingerItem.AddMember("mID", SREF(inSL[i].sSingers[j].mID), allocator);
            //SingerItem.AddMember("mNumOfAlbums", inSL[i].sSingers[j].mNumOfAlbums, allocator);
            //SingerItem.AddMember("mNumOfSongs", inSL[i].sSingers[j].mNumOfSongs, allocator);
            ///TODO: add the above two lines to support

            //SingerItem.SetInt(i);
            arrSingers.PushBack(SingerItem, allocator);
        }
        SongItem.AddMember("sSingers", arrSingers, allocator);

        Value AlbumItem(kObjectType);
        AlbumItem.AddMember("aName", SREF(inSL[i].sAlbum.aName), allocator);
        AlbumItem.AddMember("aID", SREF(inSL[i].sAlbum.aID), allocator);
        AlbumItem.AddMember("aPicURL", SREF(inSL[i].sAlbum.aPicURL), allocator);
        SongItem.AddMember("sAlbum", AlbumItem, allocator);

        SongItem.AddMember("sSource", inSL[i].sSource, allocator);
        SongItem.AddMember("sOnly", inSL[i].sOnly, allocator);
        SongItem.AddMember("sDevString", SREF(inSL[i].sDevString), allocator);

        Value arrMp3URLs(kArrayType);
        for (int j=0; j<inSL[i].sMp3URLs.size(); j++){
            Value Mp3URLItem(kObjectType);
            Mp3URLItem.AddMember("AudioURL", SREF(inSL[i].sMp3URLs[j]), allocator);
            arrMp3URLs.PushBack(Mp3URLItem, allocator);
        }
        SongItem.AddMember("sMp3URLs", arrMp3URLs, allocator);

        Value arrPicURLs(kArrayType);
        for (int j=0; j<inSL[i].sPicURLs.size(); j++){
            Value PicURLItem(kObjectType);
            PicURLItem.AddMember("PicURL", SREF(inSL[i].sPicURLs[j]), allocator);
            arrPicURLs.PushBack(PicURLItem, allocator);
        }
        SongItem.AddMember("sPicURLs", arrPicURLs, allocator);

        Value arrLyricsURLs(kArrayType);
        for (int j=0; j<inSL[i].sLyricsURLs.size(); j++){
            Value LyricsURLItem(kObjectType);
            LyricsURLItem.AddMember("LyricsURL", SREF(inSL[i].sLyricsURLs[j]), allocator);
            arrLyricsURLs.PushBack(LyricsURLItem, allocator);
        }
        SongItem.AddMember("sLyricsURLs", arrLyricsURLs, allocator);

        //SongItem.AddMember("")
        arrSongs.PushBack(SongItem, allocator);
    }

    document.AddMember("SongList", arrSongs, allocator);

    StringBuffer buffer;
    Writer<StringBuffer> writer(buffer);
    document.Accept(writer);
    return string(buffer.GetString());
}

}// namespace SongBase
}// namespace Israfil
