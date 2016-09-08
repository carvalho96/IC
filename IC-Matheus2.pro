QT += core
QT -= gui

TARGET = IC-Matheus2
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    Vertex.cpp \
    VertexCaracAltura.cpp \
    VertexCaracLargura.cpp \
    VertexCaracPeso.cpp \
    VertexCaract.cpp \
    VertexPerson.cpp \
    Edge.cpp \
    pprob.cpp \
    vecd.cpp \
    no.cpp

HEADERS += \
    Vertex.h \
    VertexCaracAltura.h \
    VertexCaracLargura.h \
    VertexCaracPeso.h \
    VertexCaract.h \
    VertexPerson.h \
    Edge.h \
    pprob.h \
    vecd.h \
    no.h

