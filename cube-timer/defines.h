#ifndef DEFINES_H
#define DEFINES_H

/*
 * These will represent parameter names
 * the suffix will indicate the type
 * _I -> Int
 * _T -> QTime
 * _DT -> QDateTime
 */
/*******MainPageView*********/
#define LOGTIME_RUNID_I "logtimeRunId"
#define LOGTIME_RUNTIME_T "logtimeRunTime"
#define LOGTIME_DATETIME_DT "logtimeDateTime"

/*******DBHandle Tables******/
#define TABLE_EVENTS "events"
#define TABLE_EVENTS_TITLE "eventTitle"
#define TABLE_EVENTS_DESC "eventDescription"

#define TABLE_RUNS "runs"
#define TABLE_RUNS_TIME "runTime"
#define TABLE_RUNS_DATETIME "runDateTime"
#define TABLE_RUNS_EVENT "runEvent" // Foreign key to eventTitle in Events
#define TABLE_RUNS_NOTES "runNotes"

#endif // DEFINES_H
