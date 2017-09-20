import QtQuick 2.7

ViewTimesPageForm {
    objectName: "ViewTimesPage"
    property string title: "View Times"

    function clearAll(){
        runListModel.clear()
    }

    function addTime(id, runTime, date){
        runListModel.append({
                                "runId": id,
                                "runTime": runTime,
                                "dateTime": date
                            })
    }


}
