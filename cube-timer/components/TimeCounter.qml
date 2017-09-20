
import QtQuick 2.0


Item {

    property alias fontPointSize: textItem.font.pointSize
    property int minutes: 0
    property int seconds: 0
    property int miliSeconds: 0
    property alias running: msTimer.running

    property bool countUp: true // set to false to count down

    signal timeout()
    signal timeElapsed(real seconds)

    property var startTime
    function start(){ msTimer.start(); startTime = new Date().getTime() }
    function stop(){ msTimer.stop() }
    function reset(){ minutes = seconds = miliSeconds = 0 }
    function setTime(min, sec, ms){
        minutes = min
        seconds = sec
        miliSeconds = ms
    }

    height: textItem.height
    width: textItem.width

    onSecondsChanged: {
        if(seconds >= 60){
            seconds -= 60
            minutes += 1
        }
        else if(seconds < 0){
            seconds += 60
            minutes -= 1
        }
    }

    onMiliSecondsChanged: {
        if(miliSeconds >= 1000){
            miliSeconds -= 1000
            seconds += 1
        }
        else if(miliSeconds < 0 ){
            if(seconds === 0 && minutes == 0)
                miliSeconds = 0
            else{
                miliSeconds += 1000
                seconds -= 1
            }
        }
    }

    Text {
        id: textItem
        color: "white"
        anchors.centerIn: parent
        text: "<pre>" + padZero(minutes) + ":" + padZero(seconds) + "." + padZero(parseInt(miliSeconds/10)) + "</pre>"
    }

    Timer{
        id: msTimer
        interval: 20
        repeat: true

        onTriggered: {
            var currentTime = new Date().getTime()
            var elapsed = currentTime - startTime
            startTime = currentTime

            timeElapsed(elapsed/1000)

            if(countUp)
                miliSeconds += elapsed
            else{
                miliSeconds -= elapsed
                if(minutes === 0 && seconds === 0 && miliSeconds === 0){
                    minutes = seconds = miliSeconds = 0
                    msTimer.stop()
                    timeout()
                }
            }
        }

    }

    function padZero(number){
        if(number < 10)
            return "0" + number
        return number
    }
}
