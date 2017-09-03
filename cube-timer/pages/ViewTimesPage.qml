import QtQuick 2.7

ViewTimesPageForm {
    objectName: "ViewTimesPage"
    property string title: "View Times"

    function clearAll(){
        console.log("Clearing times page")
        runListModel.clear()
    }

    function addTime(id, time, date){
        console.log("Adding time", time, "with date", date, "with id", id)
        runListModel.append({
                                "runId": id,
                                "runTime": time,
                                "dateTime": date
                            })
    }


}
