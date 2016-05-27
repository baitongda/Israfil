#include <string>

namespace Israfil{
namespace QQMusic{
using std::string;

const string QMBase          = "music.qq.com";
const string QMSearchBase    = "http://s." + QMBase;
const string QMSearchURL     = QMSearchBase + "/fcgi-bin/music_search_new_platform?t=0&n=%d&aggr=1&cr=1&loginUin=0&format=json&inCharset=GB2312&outCharset=utf-8&notice=0&platform=jqminiframe.json&needNewCode=0&p=1&catZhida=0&remoteplace=sizer.newclient.next_song&w=%s";
const string QMStreamURL     = "http://stream.qqmusic.tc.qq.com";
const string QMM4aURL        = QMStreamURL + "/%d.m4a";      //sid
const string QMLowMp3URL     = QMStreamURL + "/%d.mp3";      //sid + 30000000
const string QMHighMp3URL    = QMStreamURL + "/%d.mp3";      //sid
const string QMFlacURL       = QMStreamURL + "/F000%d.flac"; //mid
const string QMApeURL        = QMStreamURL + "/A000%d.ape";  //mid
const string QMSongURL       = "http://y.qq.com/#type=song&mid=%d&tpl=yqq_song_detail";
const string QMSongDetailURL = "http://s.plcloud.music.qq.com/fcgi-bin/fcg_list_songinfo.fcg?idlist=%d&callback=jsonCallback&url=1";
const string QMAlbumPicURL   = "http://i.gtimg.cn/music/photo/mid_album_300/%d/%d/%d.jpg";
const string QMLyricsURL     = "http://music.qq.com/miniportal/static/lyric/<0>/<1>.xml"; //TODO: replace params

#define FSongID 0
#define FSongName 1
#define FSingerID 2
#define FAlbumID 4
#define FAlbumName 5
#define FMusicID 20
#define FAlbumPicID 22
#define DEBUG 1

}
}
