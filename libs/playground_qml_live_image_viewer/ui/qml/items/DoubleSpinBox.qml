// Copyright (C) 2024 twyleg
import QtQuick 2.15
import QtQuick.Controls 2.15


SpinBox {
    id: doubleSpinBox

    property double doubleFrom: 0.0
    property double doubleTo: 1.0
    property double doubleValue: 0.0
    property double doubleStepSize: 0.1

    signal update(newDoubleValue: double)

    from: decimalToInt(doubleFrom)
    to: decimalToInt(doubleTo)
    value: decimalToInt(doubleValue)
    stepSize: decimalToInt(doubleStepSize)

    editable: true

    property int decimals: 2
    readonly property int decimalFactor: Math.pow(10, decimals)
    property real realValue: intToDecimal(value)

    function decimalToInt(decimal) {
        return decimal * decimalFactor
    }

    function intToDecimal(num) {
        return num / decimalFactor
    }

    onValueChanged: {
        var newDoubleValue = intToDecimal(value)
        if(Math.abs(newDoubleValue - doubleSpinBox.doubleValue) > Math.pow(10, -(decimals+1))) {
            doubleSpinBox.update(newDoubleValue)
        }
    }

    validator: DoubleValidator {
        bottom: Math.min(doubleSpinBox.from, doubleSpinBox.to)
        top:  Math.max(doubleSpinBox.from, doubleSpinBox.to)
        decimals: doubleSpinBox.decimals
        notation: DoubleValidator.StandardNotation
    }

    textFromValue: function(value, locale) {
        return Number(intToDecimal(value)).toLocaleString(locale, 'f', decimals)
    }

    valueFromText: function(text, locale) {
        return Math.round(decimalToInt(Number.fromLocaleString(locale, text)))
    }

}
