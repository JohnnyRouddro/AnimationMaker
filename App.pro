#-------------------------------------------------
#
#    Project created by QtCreator 2016-12-19T11:03:34
#
#-------------------------------------------------
#    Copyright (C) 2016 Olaf Japp
#    https://facebook.com/artanidos
#
#    This file is part of AnimationMaker.
#
#    AnimationMaker is free software: you can redistribute it and/or modify
#    it under the terms of the GNU General Public License as published by
#    the Free Software Foundation, either version 3 of the License, or
#    (at your option) any later version.
#
#    AnimationMaker is distributed in the hope that it will be useful,
#    but WITHOUT ANY WARRANTY; without even the implied warranty of
#    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#    GNU General Public License for more details.
#
#    You should have received a copy of the GNU General Public License
#    along with AnimationMaker.  If not, see <http://www.gnu.org/licenses/>.

QT += core gui svg
QT += testlib xml network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

debug {
    DEFINES += DEBUG
}

TARGET = AnimationMaker
TEMPLATE = app
target.path += /bin
INSTALLS += target

SOURCES += main.cpp

linux-g++ {
    LIBS += -L$$PWD/lib/
    LIBS += -lm
    LIBS += -ldl
}

DISTFILES += \
    todo.txt \
    changelog.txt \
    build.txt \
    default.desktop \
    default.svg \
    AppRun \
    README.md

LIBS += -L$$OUT_PWD/Widgets/ -lWidgets
INCLUDEPATH += $$PWD/Widgets
DEPENDPATH += $$PWD/Widgets
