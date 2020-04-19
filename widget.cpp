#include "widget.h"
#include <QtCharts/QChartView>
#include <QtCharts/QChart>
#include <QtCharts/QLegend>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QtCore/QRandomGenerator>
#include <QtWidgets/QGridLayout>
#include <QtCore/QTimer>
#include <QCursor>
#include <QDebug>

#include "scorerview.h"


QT_CHARTS_USE_NAMESPACE

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle("Dartboard");
    setCursor(Qt::CrossCursor);
    //! [1]
    QChartView *chartView = new QChartView;
    chartView->setRenderHint(QPainter::Antialiasing);
    QChart *chart = chartView->chart();
    chart->legend()->setVisible(false);
    chart->setAnimationOptions(QChart::AllAnimations);
    QString scoreString = "Score:           ";
    scoreDisplayer = new QLabel(scoreString, chartView);
    Widget::scoreDisplayer->setVisible(false);
    validateState = true;
    //! [1]

    //
    dartNumber = 0;

    this->theParent = parent;


    //! [2]
    qreal minSize = 0.10;
    qreal maxSize = 0.80;
    int donutCount = 5;
    //! [2]

    //! [3]
    for (int i = 0; i < donutCount; i++) {
        QPieSeries *donut = new QPieSeries;
        //This will rotate the dartboard sectors clockwise by the given angle measures
        //0 and 360 degrees are defined as 12 o'clock and angle measures increase clockwise
        donut->setPieStartAngle(9);
        donut->setPieEndAngle(369);
        int sliceCount = 20;
        for (int j = 0; j < sliceCount; j++) {
            qreal value = 5;
            QPieSlice *slice = new QPieSlice(QString("%1").arg(value), value);
            m_slices.append(slice);
            slice->setLabelVisible(false);
            slice->setLabelColor(Qt::black);
            slice->setLabelPosition(QPieSlice::LabelInsideTangential);
            connect(slice, &QPieSlice::clicked, this, &Widget::addScore);
            donut->append(slice);
            donut->setHoleSize(minSize + i * (maxSize - minSize) / donutCount);
            donut->setPieSize(minSize + (i + 1) * (maxSize - minSize) / donutCount);
            slice->setBorderColor(Qt::black);
            slice->setBorderWidth(2);
            //Color the slices and the borders
            if(i == 4)
            {
                slice->setLabelVisible(true);
                //This is the outermost ring, so we need to disconnect it from the slot to make it unclickable
                disconnect(slice, &QPieSlice::clicked, this, &Widget::addScore);
                outerSlices.append(slice);
                slice->setColor(Qt::white);
                slice->setBorderWidth(3);
                donut->setPieSize(donut->pieSize() * 0.93);
                donut->setHoleSize(donut->holeSize() * 0.90);
            }
            else
            {
                slice->setBorderColor(Qt::gray);
            }

            if(j % 2 == 0 && i % 2 == 0 && i != 4)
            {
                slice->setColor(Qt::red);
                slice->setLabelColor(Qt::black);
            }
            else
            {
                if(i != 4)
                {
                    slice->setColor(Qt::black);
                    slice->setLabelColor(Qt::white);
                }
            }
            if(j % 2 != 0  && i % 2 == 1 && i != 4)
            {
                slice->setColor(Qt::red);
            }
            //Set all of the sector point values on outer ring (just labels)
            if(j == 0)
            {
                slice->setLabel("1");
            }
            else if(j == 1)
            {
                slice->setLabel("18");
            }
            else if(j == 2)
            {
                slice->setLabel("4");
            }
            else if(j == 3)
            {
                slice->setLabel("13");
            }
            else if(j == 4)
            {
                slice->setLabel("6");
            }
            else if(j == 5)
            {
                slice->setLabel("10");
            }
            else if(j == 6)
            {
                slice->setLabel("15");
            }
            else if(j == 7)
            {
                slice->setLabel("2");
            }
            else if(j == 8)
            {
                slice->setLabel("17");
            }
            else if(j == 9)
            {
                slice->setLabel("3");
            }
            else if(j == 10)
            {
                slice->setLabel("19");
            }
            else if(j == 11)
            {
                slice->setLabel("7");
            }
            else if(j == 12)
            {
                slice->setLabel("16");
            }
            else if(j == 13)
            {
                slice->setLabel("8");
            }
            else if(j == 14)
            {
                slice->setLabel("11");
            }
            else if(j == 15)
            {
                slice->setLabel("14");
            }
            else if(j == 16)
            {
                slice->setLabel("9");
            }
            else if(j == 17)
            {
                slice->setLabel("12");
            }
            else if(j == 18)
            {
                slice->setLabel("5");
            }
            else if(j == 19)
            {
                slice->setLabel("20");
            }
            if(i == 0)
            {
                donut->setPieSize(donut->pieSize() * 1.15);
                donut->setHoleSize(donut->holeSize() * 0.95);
            }
            if(i == 1)
            {
                slice->setLabel(QString::number(slice->label().toInt() * 3));
                donut->setHoleSize(donut->holeSize() * 1.15);
                donut->setPieSize(donut->pieSize() * 0.85);
            }
            if(i == 2)
            {
                donut->setHoleSize(donut->holeSize() * 0.85);
                donut->setPieSize(donut->pieSize() * 1.15);
            }
            if(i == 3)
            {
                slice->setLabel(QString::number(slice->label().toInt() * 2));
                donut->setHoleSize(donut->holeSize() * 1.05);
                donut->setPieSize(donut->pieSize() * 0.9);
            }
            //End set all of the sector point values on outer ring
        }
        m_donuts.append(donut);
        chartView->chart()->addSeries(donut);
    }
    //! [3]

    //create inner bullseye
    QPieSeries *innerBullseye = new QPieSeries;
    int value = 50;
    innerBullseye->setPieSize(minSize * (maxSize - minSize) / donutCount);
    QPieSlice *slice = new QPieSlice(QString("%1").arg(value), value);
    m_slices.append(slice);
    slice->setLabelVisible(false);
    slice->setLabelColor(Qt::white);
    slice->setLabelPosition(QPieSlice::LabelInsideHorizontal);
    connect(slice, &QPieSlice::clicked, this, &Widget::addScore);
    slice->setColor(Qt::black);
    slice->setBorderColor(Qt::black);
    slice->setBorderWidth(5);
    innerBullseye->setHoleSize(0);
    innerBullseye->setPieSize(0.025);
    innerBullseye->append(slice);

    //create outer bullseye
    QPieSeries *outerBullseye = new QPieSeries;
    int outerValue = 25;
    QPieSlice *slice2 = new QPieSlice(QString("%1").arg(outerValue), outerValue);
    m_slices.append(slice2);
    slice2->setLabelVisible(false);
    slice2->setLabelColor(Qt::black);
    slice2->setLabelPosition(QPieSlice::LabelInsideHorizontal);
    connect(slice2, &QPieSlice::clicked, this, &Widget::addScore);
    slice2->setColor(Qt::red);
    outerBullseye->setHoleSize(0.025);
    outerBullseye->setPieSize(0.08);
    outerBullseye->append(slice2);
    slice2->setBorderColor(Qt::red);
    slice2->setBorderWidth(5);

    //add outer bullseye
    m_donuts.append(outerBullseye);
    chartView->chart()->addSeries(outerBullseye);
    //add inner bullseye
    m_donuts.append(innerBullseye);
    chartView->chart()->addSeries(innerBullseye);

    // create main layout
    //! [4]
    QGridLayout *mainLayout = new QGridLayout;
    mainLayout->addWidget(chartView, 1, 1);
    setLayout(mainLayout);
    //! [4]

    // Connect the score validation blocker and unblocker
    connect(this, SIGNAL(needsValidation(bool)), this, SLOT(validationBlocker(bool)));
    connect(parent, SIGNAL(sendValidateTrue(bool)), this, SLOT(validationBlocker(bool)));
    // Connect the dart score labels to the dart board widget
    connect(this, SIGNAL(scoreSignalOne(int)), parent, SLOT(set_SlingOneText(int)));
    connect(this, SIGNAL(scoreSignalTwo(int)), parent, SLOT(set_SlingTwoText(int)));
    connect(this, SIGNAL(scoreSignalThree(int)), parent, SLOT(set_SlingThreeText(int)));

}

Widget::~Widget()
{

}

void Widget::addScore()
{
    QPieSlice *slice = qobject_cast<QPieSlice *>(sender());
    Widget::scoreDisplayer->clear();
//    QString scoreString = "Score: ";
//    scoreString.append(QString::number(this->score));
//    Widget::scoreDisplayer->setText(scoreString);
    if(validateState == true)
    {
        this->score = slice->label().toInt();
        slice->setLabelVisible(true);
        slice->setLabelPosition(slice->LabelInsideHorizontal);
        dartNumber++;
        if(dartNumber == 1)
        {
            emit scoreSignalOne(score);
        }
        if(dartNumber == 2)
        {
            emit scoreSignalTwo(score);
        }
        if(dartNumber == 3)
        {
            emit scoreSignalThree(score);
            dartNumber = 0;
            emit needsValidation(true);
        }
    }
}
void Widget::validationBlocker(bool blockForValidation)
{
    if (blockForValidation == true)
    {
        disconnect(this, SIGNAL(scoreSignalOne(int)), theParent, SLOT(set_SlingOneText(int)));
        disconnect(this, SIGNAL(scoreSignalTwo(int)), theParent, SLOT(set_SlingTwoText(int)));
        disconnect(this, SIGNAL(scoreSignalThree(int)), theParent, SLOT(set_SlingThreeText(int)));
        validateState = false;
    }
    if (blockForValidation == false)
    {
        connect(this, SIGNAL(scoreSignalOne(int)), theParent, SLOT(set_SlingOneText(int)));
        connect(this, SIGNAL(scoreSignalTwo(int)), theParent, SLOT(set_SlingTwoText(int)));
        connect(this, SIGNAL(scoreSignalThree(int)), theParent, SLOT(set_SlingThreeText(int)));
        validateState = true;
        for(int i = 0; i < m_slices.size(); i++)
        {
            m_slices[i]->setLabelVisible(false);
        }
        for(int i = 0; i < outerSlices.size(); i++)
        {
            outerSlices[i]->setLabelVisible(true);
        }
    }
}

//This slot will take in the dart score int and reverse-engineer the slice it came from, then make its label visible
void Widget::mirrorDart(int i)
{
    Widget *dartboard = qobject_cast<Widget *>(sender());

    for(int j = 0; j < dartboard->m_slices.size(); j++)
    {
        if(dartboard->m_slices[j]->isLabelVisible())
        {
            this->m_slices[j]->setLabelVisible(true);
        }
        else
        {
            this->m_slices[j]->setLabelVisible(false);
        }
    }
}
