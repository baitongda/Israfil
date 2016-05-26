#include <QString>
#include <QByteArray>
#include <QtTest>
#include <QDebug>
#include "Netease/neteaseapi.h"


class TstNeteaseTest : public QObject
{
    Q_OBJECT

public:
    //tstHttpClient *ichc = new tstHttpClient();

private Q_SLOTS:
    void testSearch();
};

void TstNeteaseTest::testSearch()
{
    Israfil::Netease::NeteaseAPI *neapi = new Israfil::Netease::NeteaseAPI();
    qDebug() << neapi->testSearch();
}

QTEST_MAIN(TstNeteaseTest)

#include "tst_tstneteasetest.moc"
