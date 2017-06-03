import QtQuick 2.7

MainPageForm {
    objectName: "MainPage"

    signal logTime(int minutes, int seconds, int miliseconds)

    property int touchCount: 0
    multiArea.onPressed: { touchCount += touchPoints.length; evaluateTouches() }
    multiArea.onReleased: { touchCount -= touchPoints.length; evaluateTouches() }

    function evaluateTouches(touches){

        switch(state){
        case "base":{
            if(touchCount >= 2){
                holdTimer.start()
            }
            else{
                if(progressBar.value >= 1){
                    actionButton.checked = true
                    timeCounter.start()
                    state = "started"
                }
                holdTimer.stop()
                progressBar.value = 0
            }
            break;
        }

        case "started":{
            if(touchCount >= 2){
                timeCounter.stop()
                logTime(timeCounter.minutes, timeCounter.seconds, timeCounter.miliSeconds)
                actionButton.checked = false
            }
            else if(touchCount == 0 && !timeCounter.running){
                state = "stopped"
            }
            break;
        }

        case "stopped":{
            if(touchCount >= 1){
                timeCounter.reset()
            }
            else if(touchCount == 0){
                state = "base"
            }
            break;
        }
        }
    }

    property double holdTime: 10
    property double curTime: 0

    Timer{
        id: holdTimer
        interval: 10
        repeat: true
        onTriggered: {
            progressBar.value += 1.0 * interval / 1000
        }
    }
}
