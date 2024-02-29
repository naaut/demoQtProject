import QtQuick
import QtQuick.Controls

import injector
import presenters


QmlInjector {
    id: root

    sourceComponent: Page {
        id: page

        property QmlPresenter $presenter

        anchors.fill: parent
        background: Rectangle {
            color: "lightblue"
        }

        Text {
            id: thenswer
            anchors.centerIn: parent

            // here we can get access to data without any checks
            text: $presenter.answer
        }
    }
}
