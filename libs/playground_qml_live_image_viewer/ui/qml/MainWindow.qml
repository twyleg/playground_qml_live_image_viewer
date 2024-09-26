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

    Row {
        width: parent.width
        height: parent.height

        Column {
            width: 400
            spacing: 10

            AdvancedSlider {
                id: cameraSystemTranslationX
                width: parent.width
                name: "cameraSystemTranslationX"
                from: 0
                to: 20000
                value: parameterModel.cameraSystemTranslationX
                stepSize: 1
                onValueChanged: parameterModel.cameraSystemTranslationX = value
            }

            AdvancedSlider {
                id: cameraSystemTranslationY
                width: parent.width
                name: "cameraSystemTranslationY"
                from: 0
                to: 20000
                value: parameterModel.cameraSystemTranslationY
                stepSize: 1
                onValueChanged: parameterModel.cameraSystemTranslationY = value
            }

            AdvancedSlider {
                id: cameraSystemTranslationZ
                width: parent.width
                name: "cameraSystemTranslationZ"
                from: 0
                to: 20000
                value: parameterModel.cameraSystemTranslationZ
                stepSize: 1
                onValueChanged: parameterModel.cameraSystemTranslationZ = value
            }

            AdvancedSlider {
                id: cameraSystemRotationRoll
                width: parent.width
                name: "cameraSystemRotationRoll"
                from: 0
                to: 3600
                value: parameterModel.cameraSystemRotationRoll
                stepSize: 1
                onValueChanged: parameterModel.cameraSystemRotationRoll = value
            }

            AdvancedSlider {
                id: cameraSystemRotationPitch
                width: parent.width
                name: "cameraSystemRotationPitch"
                from: 0
                to: 3600
                value: parameterModel.cameraSystemRotationPitch
                stepSize: 1
                onValueChanged: parameterModel.cameraSystemRotationPitch = value
            }

            AdvancedSlider {
                id: cameraSystemRotationYaw
                width: parent.width
                name: "cameraSystemRotationYaw"
                from: 0
                to: 3600
                value: parameterModel.cameraSystemRotationYaw
                stepSize: 1
                onValueChanged: parameterModel.cameraSystemRotationYaw = value
            }

            AdvancedSlider {
                id: cubeSystemTranslationX
                width: parent.width
                name: "cubeSystemTranslationX"
                from: 0
                to: 20000
                value: parameterModel.cubeSystemTranslationX
                stepSize: 1
                onValueChanged: parameterModel.cubeSystemTranslationX = value
            }

            AdvancedSlider {
                id: cubeSystemTranslationY
                width: parent.width
                name: "cubeSystemTranslationY"
                from: 0
                to: 20000
                value: parameterModel.cubeSystemTranslationY
                stepSize: 1
                onValueChanged: parameterModel.cubeSystemTranslationY = value
            }

            AdvancedSlider {
                id: cubeSystemTranslationZ
                width: parent.width
                name: "cubeSystemTranslationZ"
                from: 0
                to: 20000
                value: parameterModel.cubeSystemTranslationZ
                stepSize: 1
                onValueChanged: parameterModel.cubeSystemTranslationZ = value
            }

            AdvancedSlider {
                id: cubeSystemRotationRoll
                width: parent.width
                name: "cubeSystemRotationRoll"
                from: 0
                to: 3600
                value: parameterModel.cubeSystemRotationRoll
                stepSize: 1
                onValueChanged: parameterModel.cubeSystemRotationRoll = value
            }

            AdvancedSlider {
                id: cubeSystemRotationPitch
                width: parent.width
                name: "cubeSystemRotationPitch"
                from: 0
                to: 3600
                value: parameterModel.cubeSystemRotationPitch
                stepSize: 1
                onValueChanged: parameterModel.cubeSystemRotationPitch = value
            }

            AdvancedSlider {
                id: cubeSystemRotationYaw
                width: parent.width
                name: "cubeSystemRotationYaw"
                from: 0
                to: 3600
                value: parameterModel.cubeSystemRotationYaw
                stepSize: 1
                onValueChanged: parameterModel.cubeSystemRotationYaw = value
            }

            AdvancedSlider {
                id: cubeSystemScale
                width: parent.width
                name: "cubeSystemScale"
                from: 0
                to: 5
                value: parameterModel.cubeSystemScale
                stepSize: 1
                onValueChanged: parameterModel.cubeSystemScale = value
            }


            Switch {
                text: "cubeSystemNormals"
                width: parent.width
                onPositionChanged: parameterModel.cubeSystemNormals = position
            }

            Switch {
                text: "cubeSystemPoints"
                width: parent.width
                onPositionChanged: parameterModel.cubeSystemPoints = position
            }

            Switch {
                text: "cubeSystemFaces"
                width: parent.width
                onPositionChanged: parameterModel.cubeSystemFaces = position
            }

        }

        Image {
            id: testImage
            width: 1280
            height: 720
            cache: false
            source: "image://stream/" + id
            property int id: 0

            function reload() {
                id++;
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

