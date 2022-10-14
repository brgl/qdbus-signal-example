QT += core widgets dbus

CONFIG += c++17

SOURCES += main.cpp

HEADERS += receiver.hpp

LIBS += -lQt6DBus
