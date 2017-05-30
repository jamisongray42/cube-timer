import QtQuick 2.7

Page1Form {
    actionButton.onClicked: {
        if(state === "start"){
            state = "stop"
            timeCounter.start()
        }
        else if(state === "stop"){
            state = "reset"
            timeCounter.stop()
        }
        else if(state === "reset"){
            state = "start"
            timeCounter.reset()
        }
    }
}
