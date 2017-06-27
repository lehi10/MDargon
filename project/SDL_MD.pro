TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp


QT   += opengl
LIBS += -lOpengl32


LIBS += C:\DEVELOPMENT\glut-glew\freeglut\lib\freeglut.lib
INCLUDEPATH += C:\DEVELOPMENT\glut-glew\freeglut\include

LIBS += C:\DEVELOPMENT\glut-glew\glew-1.11.0\lib\glew32.lib
LIBS += C:\DEVELOPMENT\glut-glew\glew-1.11.0\lib\glew32s.lib
INCLUDEPATH += C:\DEVELOPMENT\glut-glew\glew-1.11.0\include

HEADERS += \
    aditionals.h
