#include "neteaseapi.h"
#include <QJsonObject>
#include <QJsonDocument>

using namespace Israfil::Http;

namespace Israfil{
namespace Netease{

NeteaseAPI::NeteaseAPI()
{
    request = new HttpRequest();
    headers.insert("Accept", "*/*");//"text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8");
    headers.insert("Accept-Encoding", "gzip,deflate,sdch");
    headers.insert("Accept-Language", "zh-CN,zh;q=0.8,en-US;q=0.5,en;q=0.3");
    headers.insert("Connection", "keep-alive");
    headers.insert("Content-Type", "application/x-www-form-urlencoded; charset=UTF-8");
    headers.insert("Host", "music.163.com");
    headers.insert("Referer", "http://music.163.com/");
    headers.insert("Cache-Control", "no-cache");
    headers.insert("User-Agent", "Mozilla/5.0 (Macintosh; Intel Mac OS X 10_9_2) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/33.0.1750.152 Safari/537.36");
    request->setHeaders(headers);

}

QString NeteaseAPI::testSearch()
{
    request->setMethod("POST");
    //request->setUrl(QUrl("http://music.163.com/api/search/get/"));
    QJsonObject object;
    QString pswd = "12345678";
    object["password"] = QJsonValue(QString(pswd.toUtf8().toBase64()));

    QJsonDocument doc;
    doc.setObject(object);
    request->setUrl(QUrl("http://localhost:9001"));
    //HttpBody *body = new HttpBody(doc.toJson());
    //HttpBody *body = new HttpBody(QString("s=回忆里的疯狂&limit=20&type=1&offset=0"));
    request->setBody(new HttpBody(doc.toJson()));
    HttpClient *client = new HttpClient();
    HttpResponse *response = client->send(request);//client->send(request);
    return response->body()->toString();
}

} //End Netease
} //End Israfil
