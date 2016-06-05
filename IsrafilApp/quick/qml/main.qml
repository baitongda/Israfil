import QtQuick 2.0
import QtQuick.Controls 1.0
import IsrafilCore 1.0

ApplicationWindow {
    visible: true;
    width: 800;
    height: 500;

    Text {
        font.family: 'Droid Sans';
        font.pointSize: 12;
        lineHeight: 1;
        horizontalAlignment: Text.AlignHCenter;
        verticalAlignment: Text.AlignVCenter;
        wrapMode: Text.WrapAnywhere;
        text: israfilqt.searchSong("晴天");
        anchors.centerIn: parent;
        height: parent.height;
        width: parent.width;
    }

    IsrafilCoreQt {
        id: israfilqt
    }


}
