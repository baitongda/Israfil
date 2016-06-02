#include "stdio.h"
#include "qqmusic.h"
#include "rapidjson/document.h"

namespace Israfil{
namespace QQMusic{
namespace json = rapidjson;

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

bool QQMusic::SearchSong(std::string name, std::vector<SongBase>& rVecSongBase)
{
    //vector<SongBase> rVecSongBase;
    std::string rSongSearch = hc->HttpGet(Israfil::strfmt::Format(QMSearchURL, 20, name));
    dbg(rSongSearch);

    json::Document doc;
    doc.Parse<0>(rSongSearch.c_str());
    if (doc.HasParseError()){
        json::ParseErrorCode code = doc.GetParseError();
        dbgerr(code);
        return false;
    }
    json::Value& qCode = doc["code"];
    if (qCode.IsInt() == false || qCode.GetInt() != 0){ dbgerr(qCode.GetInt());return false;}
    dbg(qCode.GetInt());
    json::Value& qData = doc["data"];
    if (qData.IsObject() == false){ dbgerr(qData.GetType());return false;}

    json::Value& qSong = qData["song"];
    if (qSong.IsObject() == false){ dbgerr(qSong.GetType());return false;}
    json::Value& qList = qSong["list"];
    if (qList.IsArray() == false){ dbgerr(qList.GetType());return false;}
    dbg(qList.Size());
    for (int i=0; i<qList.Size(); i++){
        dbg(i);
        //iteration for songs in search result
        json::Value& qlSong = qList[i];
        if (qlSong.IsObject() == false) {dbgerr(qlSong.GetType());return false;}
        dbg(qlSong["fsong"].GetString());
        json::Value& qlsGrp = qlSong["grp"];
        dbg(qlsGrp.IsArray());
        dbg(qlsGrp.Size());
        std::string FString;
        //if (qlsGrp.Size() == 0) FString = qlSong["f"].GetString();
        //else FString = qlsGrp[0]["f"].GetString();

        FString = qlSong["f"].GetString();
        if (isAtString(FString) == true) continue; // it this is at string, then we dont use it
        dbg(FString);



        std::vector<std::string> FArray;
        SplitF(FString, FArray);
        dbg(FArray[FSongName]);


        SongBase tmpSB;
        tmpSB.sName = FArray[FSongName];
        tmpSB.sID = FArray[FSongID];
        tmpSB.DevString = FString;
        tmpSB.Mp3URL.push_back(Israfil::strfmt::Format(QMHighMp3URL, tmpSB.sID));
        tmpSB.LyricsURL.push_back(Israfil::strfmt::Format(QMLyricsURL, StringToInt(tmpSB.sID)%100, tmpSB.sID));
        tmpSB.PicURL.push_back(Israfil::strfmt::Format(QMSongPicURL, FArray[FSongPicID].at(FArray[FSongPicID].length()-2),FArray[FSongPicID].at(FArray[FSongPicID].length()-1), FArray[FSongPicID]));

        tmpSB.sAlbum.aID = FArray[FAlbumID];
        tmpSB.sAlbum.aName = FArray[FAlbumName];
        tmpSB.sAlbum.aPicURL = Israfil::strfmt::Format(QMAlbumPicURL, StringToInt(tmpSB.sAlbum.aID)%100, tmpSB.sAlbum.aID);

        Musician tmpMSC;
        tmpMSC.mID = FArray[FSingerID];
        tmpMSC.mName = FArray[FSingerName];
        tmpSB.sSingers.push_back(tmpMSC);

        rVecSongBase.push_back(tmpSB);
    }

    return true;
}

bool QQMusic::isAtString(std::string FAtString){
    std::string FeatString = "@@@@";
    std::string::size_type pos;
    pos = FAtString.find(FeatString);
    if (pos != FAtString.npos) return true;
    else return false;
}

void QQMusic::SplitF(std::string FString, std::vector<std::string> &FArray){
    std::stringstream ss(FString);
    std::string item;
    while (std::getline(ss, item, '|')) {
        FArray.push_back(std::move(item));
    }
}

int QQMusic::StringToInt(std::string Str) {
    std::stringstream ss;
    int num;
    ss<<Str;
    ss>>num;
    return num;
}

}
}
