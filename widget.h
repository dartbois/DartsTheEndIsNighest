#ifndef WIDGET_H
#define WIDGET_H
#pragma once
#include <QtWidgets/QWidget>
#include <QtCharts/QPieSeries>
#include <QLabel>

//This is a UI class.
//This class is solely for the resizeable dartboard.
//Handles some aspects of scoring.

QT_CHARTS_USE_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    //Constructor/destructor
    Widget(QWidget *parent = 0);
    ~Widget();
    //Variables for use with the dartboard
    int score = 0;
    int counter;
    int dartNumber;
    bool validateState;
    QList<QPieSlice *> doubleSlices; //lists which slices are doubles
    bool slingIsDouble;

public slots:
    //Activates when a slice is clicked.
    void addScore();
    //prevents validation
    void validationBlocker(bool blockForValidation);
    //makes dart 'visible' on the board
    void mirrorDart(int i);

 signals: //these all send data, generally to scorerview
    void scoreSignalOne(int i);
    void scoreSignalTwo(int i);
    void scoreSignalThree(int i);
    void needsValidation(bool run);

private:
    //all relating to construction of the dartboard.
    QList<QPieSeries *> m_donuts;
    QList<QPieSlice *> m_slices;
    QList<QPieSlice *> outerSlices;
    QWidget* theParent;
    QLabel *scoreDisplayer;
};

#endif // WIDGET_H
