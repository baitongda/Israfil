#include <QString>
#include <QByteArray>
#include <QtTest>
#include <QDebug>
#include "icHttpClient/httpclient.hpp"
using namespace Israfil::Http;

class TstNetworkTest : public QObject
{
    Q_OBJECT

public:
    //tstHttpClient *ichc = new tstHttpClient();

private Q_SLOTS:
    void testHeader();
};

void TstNetworkTest::testHeader()
{
    QMap<QString, QString> headers;
    headers.insert("Accept", "text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,*/*;q=0.8");
    headers.insert("User-Agent","Mozilla/5.0 (X11; U; Linux i686; en-US) AppleWebKit/534.15 (KHTML, like Gecko) Ubuntu/10.10 Chromium/10.0.613.0 Chrome/10.0.613.0 Safari/534.15");
    HttpRequest *request = new HttpRequest();
    request->setMethod("GET");
    request->setUrl(QUrl("http://www.xhaus.com/headers"));
    request->setHeaders(headers);

    HttpClient *client = new HttpClient();
    HttpResponse *response = client->send(request);

    qDebug() << "Headers:" << response->headers();
    qDebug() << "HTTP Status:" << response->status();
    qDebug() << "Body:" << response->body()->toString();

    /*ichc->setUserAgent("Mozilla/5.0 (X11; U; Linux i686; en-US) AppleWebKit/534.15 (KHTML, like Gecko) Ubuntu/10.10 Chromium/10.0.613.0 Chrome/10.0.613.0 Safari/534.15");
    icHeaders ih = ichc->getHeader();
    icHeaders::iterator it;
    for (it = ih.begin(); it != ih.end(); it++){
        qDebug() << it.key().data() << ": " << it.value().data();
    }
    QByteArray res =
    ichc->HttpGet(QUrl("http://www.baidu.com"));
    qDebug() << ichc->result;
    //QByteArray res = ichc.HttpGet(QUrl("http://www.xhaus.com/headers"));
    if (ichc->result.contains(QByteArray("Mozilla/5.0 (X11; U; Linux i686; en-US) AppleWebKit/534.15 (KHTML, like Gecko) Ubuntu/10.10 Chromium/10.0.613.0 Chrome/10.0.613.0 Safari/534.15")))
    {
        QCOMPARE("right", "right");
    }
    else{
        QCOMPARE("right", "wrong");
    }
    */
}

QTEST_MAIN(TstNetworkTest)

#include "tst_tstnetworktest.moc"
