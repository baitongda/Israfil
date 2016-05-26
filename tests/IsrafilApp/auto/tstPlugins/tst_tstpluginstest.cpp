#include <QString>
#include <QtTest>
#include "pluginmgr.h"

class TstPluginsTest : public QObject
{
    Q_OBJECT

public:
    TstPluginsTest();

private Q_SLOTS:
    void tstPluginList();
};

TstPluginsTest::TstPluginsTest()
{
}

void TstPluginsTest::tstPluginList()
{
    PluginMgr plmgr;// = new PluginMgr();
    plmgr.LoadAllPlugins();
    QStringList templist;
    templist.append("example");
    QCOMPARE(plmgr.GetPluginList(), templist);
    QVERIFY2(true, "Failure");
}

QTEST_APPLESS_MAIN(TstPluginsTest)

#include "tst_tstpluginstest.moc"
