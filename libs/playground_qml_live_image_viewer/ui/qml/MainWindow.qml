// Copyright (C) 2023 twyleg
import QtQuick 2.0
import QtQuick.Controls 2.0
import QtQuick.Layouts

import "./items"

ApplicationWindow
{
    id: app

    visible: true
    width: 1920
    height: 1080
    title: qsTr("Minimal Qml Live Image Viewer")

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

        AdvancedSlider {
            id: sliderRed

            width: parent.width

            name: "red"
            from: 0
            to: 255
            value: parameterModel.red
            stepSize: 0.1

            onValueChanged: {
                parameterModel.red = value
            }
        }

        AdvancedSlider {
            id: sliderGreen

            width: parent.width

            name: "green"
            from: 0
            to: 255
            value: parameterModel.green
            stepSize: 0.1

            onValueChanged: {
                parameterModel.green = value
            }
        }

        AdvancedSlider {
            id: sliderBlue

            width: parent.width

            name: "blue"
            from: 0
            to: 255
            value: parameterModel.blue
            stepSize: 0.1

            onValueChanged: {
                parameterModel.blue = value
            }
        }

    }


    Connections {
        target: imageModel

        function onImageChanged() {
            testImage.reload()
        }
    }

}

