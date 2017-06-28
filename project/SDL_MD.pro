        TEMPLATE = app
    CONFIG += console c++11
    CONFIG -= app_bundle
    CONFIG -= qt

    SOURCES += main.cpp

    QT += core gui opengl
    QT   += opengl
    LIBS += -lOpengl32



    LIBS += C:\DEVELOPMENT\glut-glew\freeglut\lib\freeglut.lib
    INCLUDEPATH += C:\DEVELOPMENT\glut-glew\freeglut\include

    LIBS += C:\DEVELOPMENT\glut-glew\glew-1.11.0\lib\glew32.lib
    LIBS += C:\DEVELOPMENT\glut-glew\glew-1.11.0\lib\glew32s.lib
    INCLUDEPATH += C:\DEVELOPMENT\glut-glew\glew-1.11.0\include

    LIBS += C:\DEVELOPMENT\OPENGL\lib\Glaux.lib
    LIBS += C:\DEVELOPMENT\OPENGL\lib\GLU32.LIB
    LIBS += C:\DEVELOPMENT\OPENGL\lib\glui32.lib
    LIBS += C:\DEVELOPMENT\OPENGL\lib\glut32.lib
    LIBS += C:\DEVELOPMENT\OPENGL\lib\OPENGL32.LIB
    INCLUDEPATH += C:\DEVELOPMENT\OPENGL\include




    HEADERS += \
        aditionals.h
