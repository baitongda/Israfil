#include "israfilcoreqt.h"

IsrafilCoreQt::IsrafilCoreQt(QObject *parent) : QObject(parent)
{
    pIC = new Israfil::Core::IsrafilCore();
}

SongList IsrafilCoreQt::SearchSong(QString Name)
{
    return pIC->SearchSong(Name.toStdString());
}

