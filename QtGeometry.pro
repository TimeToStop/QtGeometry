QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Files/Line/createlinedialog.cpp \
    Files/Line/line.cpp \
    Files/Line/propertieslinedialog.cpp \
    Files/Object/object.cpp \
    Files/Object/propertiesobjectdialog.cpp \
    Files/PointUI/choosepointuidialog.cpp \
    Files/PointUI/createpointdialog.cpp \
    Files/PointUI/openpointuidialog.cpp \
    Files/PointUI/pointui.cpp \
    Files/PointUI/propertiespointuidialog.cpp \
    Files/Shape/chooseshapedialog.cpp \
    Files/Shape/createabstractshapedialog.cpp \
    Files/Shape/createshapedialog.cpp \
    Files/Shape/shape.cpp \
    Files/double.cpp \
    Files/field.cpp \
    main.cpp \
    widget.cpp

HEADERS += \
    Files/Line/createlinedialog.h \
    Files/Line/line.h \
    Files/Line/propertieslinedialog.h \
    Files/Object/object.h \
    Files/Object/propertiesobjectdialog.h \
    Files/PointUI/choosepointuidialog.h \
    Files/PointUI/createpointdialog.h \
    Files/PointUI/openpointuidialog.h \
    Files/PointUI/pointui.h \
    Files/PointUI/propertiespointuidialog.h \
    Files/Shape/chooseshapedialog.h \
    Files/Shape/createabstractshapedialog.h \
    Files/Shape/createshapedialog.h \
    Files/Shape/shape.h \
    Files/double.h \
    Files/field.h \
    widget.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
