QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Menu/mainwindow.cpp \
    main.cpp \
    ingame.cpp \
    movement/Bishop.cpp \
    movement/ChessBoard.cpp \
    movement/ChessPiece.cpp \
    movement/DiagonalScan.cpp \
    movement/King.cpp \
    movement/KingScan.cpp \
    movement/Knight.cpp \
    movement/KnightScan.cpp \
    movement/Pawn.cpp \
    movement/PawnScan.cpp \
    movement/Queen.cpp \
    movement/Rook.cpp \
    movement/StraightScan.cpp

HEADERS += \
    Menu/mainwindow.h \
    ingame.h \
    movement/Bishop.h \
    movement/ChessBoard.h \
    movement/ChessPiece.h \
    movement/DiagonalScan.h \
    movement/King.h \
    movement/KingScan.h \
    movement/Knight.h \
    movement/KnightScan.h \
    movement/Pawn.h \
    movement/PawnScan.h \
    movement/Queen.h \
    movement/Rook.h \
    movement/ScanAlg.h \
    movement/Square.h \
    movement/StraightScan.h

FORMS += \
    Menu/mainwindow.ui \
    ingame.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    images.qrc

SUBDIRS += \
    Menu/Menu.pro
