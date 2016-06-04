import QtQuick 2.0
import QtQuick.Controls 1.0
import IsrafilCore 1.0

ApplicationWindow {
    visible: true;
    width: 400;
    height: 400;

    Text {
        font.family: 'Droid Sans';
        font.pointSize: 32;
        lineHeight: 2;
        horizontalAlignment: Text.AlignHCenter;
        verticalAlignment: Text.AlignVCenter;
        text: 'Stay Tuned!';
        anchors.centerIn: parent;
    }

    IsrafilCoreQt {
        id: israfilqt
    }

    Text {
        text: israfilqt.searchSong("晴天");
    }

}
