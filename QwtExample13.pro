win32 {
  # Windows only
  message("Desktop application, no effc++, built for Windows")
  greaterThan(QT_MAJOR_VERSION, 4): QT += svg
  QMAKE_CXXFLAGS += -std=c++1y -Wall -Wextra #-Weffc++
}

unix:!macx{
  # Linux only
  message("Console application, built for Linux")
  message(Host name: $$QMAKE_HOST.name)
  contains(QMAKE_HOST.name,pc-157-103) {
    message("Host is student computer")
    QMAKE_CXX = g++-4.9
    QMAKE_LINK = g++-4.9
    QMAKE_CC = gcc-4.9
    # -Weffc++ does not go well with Qwt
    QMAKE_CXXFLAGS += -Wall -Wextra -Werror -std=c++1y
  }
  !contains(QMAKE_HOST.name,pc-157-103) {
    message("Host is not student computer")
    QMAKE_CXX = g++-5
    QMAKE_LINK = g++-5
    QMAKE_CC = gcc-5
    # -Weffc++ does not go well with Qwt
    QMAKE_CXXFLAGS += -Wall -Wextra -Werror -std=c++14

    # gcov
    QMAKE_CXXFLAGS += -fprofile-arcs -ftest-coverage
    LIBS += -lgcov
  }
}


macx {
  # Mac only
  message("Desktop application, no effc++, built for Mac")
  CONFIG += c++11
  QMAKE_CXXFLAGS += -std=c++11
}

QT       += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TEMPLATE = app

CONFIG(release, debug|release) {
  message(Release mode)
  DEFINES += NDEBUG NTRACE_BILDERBIKKEL
}

SOURCES += main.cpp \
    qtdialog.cpp \
    simulation.cpp

# Qwt
#LIBS += -lqwt
include(../RibiLibraries/Qwt_6_1.pri)
#DEFINES += QT_NO_PRINTER

HEADERS += \
    qtdialog.h \
    simulation.h

FORMS += \
    qtdialog.ui
