// Copyright (C) 2023 twyleg
import QtQuick 2.0
import QtQuick.Controls 2.0
import QtQuick.Layouts

ApplicationWindow
{
    id: app

    visible: true
    width: 1920
    height: 1080
    title: qsTr("Minimal Qml")

    Column {

        Image {

            id: testImage

            property int id: 0

            width: 1280
            height: 720

            cache: false
            source: "image://stream/" + id

            function reload() {
                id++;
            }
        }

        Slider {
            id: sliderRed

            width: parent.width

            from: 0
            to: 1
            value: parameterModel.red
            stepSize: 0.01
        }

        Slider {
            id: sliderGreen

            width: parent.width

            from: 0
            to: 1
            value: parameterModel.green
            stepSize: 0.01
        }

        Slider {
            id: sliderBlue

            width: parent.width

            from: 0
            to: 1
            value: parameterModel.blue
            stepSize: 0.01
        }

    }


    Connections {
        target: imageModel

        function onImageChanged() {
            testImage.reload()
        }
    }

}

