#ifndef WIDGET_H
#define WIDGET_H
#pragma once
#include <QtWidgets/QWidget>
#include <QtCharts/QPieSeries>
#include <QLabel>

QT_CHARTS_USE_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();
    int score = 0;
    int dartNumber;
    bool validateState;

public slots:
    void addScore();

    void validationBlocker(bool blockForValidation);

    void mirrorDart(int i);

 signals:
    void scoreSignalOne(int i);
    void scoreSignalTwo(int i);
    void scoreSignalThree(int i);
    void needsValidation(bool run);

private:
    QList<QPieSeries *> m_donuts;
    QList<QPieSlice *> m_slices;
    QList<QPieSlice *> outerSlices;
    QWidget* theParent;
    QLabel *scoreDisplayer;
};

#endif // WIDGET_H
