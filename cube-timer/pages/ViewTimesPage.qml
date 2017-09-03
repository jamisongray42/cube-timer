import QtQuick 2.7

ViewTimesPageForm {
    objectName: "ViewTimesPage"
    property string title: "View Times"

    function clearAll(){
        console.log("Clearing times page")
    }

    function addTime(id, time){
        console.log("Adding time", time, "with id", id)
    }
}
