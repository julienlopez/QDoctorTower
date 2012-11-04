win32 {
    INCLUDEPATH += path_to_boost
    LIBS += -Lpath_to_boost\stage\lib
}

win32 {
    LIBS += -lboost_signals-mgw44-mt-1_51
}
unix {
    LIBS += -lboost_signals
}
