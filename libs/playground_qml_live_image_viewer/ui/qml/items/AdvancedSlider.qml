// Copyright (C) 2024 twyleg
import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15


RowLayout {
    id: advancedSlider

    property alias name: nameText.text

    property double from: 0.0
    property double to: 10.0
    property double value: 0.0
    property double stepSize: 0.1

    Text {
        id: nameText

        Layout.preferredWidth: parent.width *0.1

        clip: true
    }

    Slider {
        id: slider

        Layout.fillWidth: true

        from: advancedSlider.from
        to: advancedSlider.to
        value: advancedSlider.value
        stepSize: advancedSlider.stepSize

        onPositionChanged: {
            advancedSlider.value = value
        }


    }

    DoubleSpinBox {
        id: doubleSpinBox

        doubleFrom: advancedSlider.from
        doubleTo: advancedSlider.to
        doubleValue: advancedSlider.value
        doubleStepSize: advancedSlider.stepSize

        editable: true

        onUpdate: (newDoubleValue) => {
            advancedSlider.value = newDoubleValue
        }
    }

}
