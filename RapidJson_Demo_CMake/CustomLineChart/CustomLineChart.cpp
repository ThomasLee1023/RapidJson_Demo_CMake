
#include "CustomLineChart.h"

#include <QWidget>
#include <QLabel>

#include <QLineSeries>
#include <QValueAxis>

#include <QScatterSeries>

#include <QDateTimeAxis>
#include <QDateTime>

#pragma execution_character_set("utf-8")


CustomLineChart::CustomLineChart(QWidget* parent)
{
    m_pWidget = parent;
}

// 先添加Series再设置坐标，否则会出现坐标不准问题
QChart* CustomLineChart::createLineChart()
{
    //![1]
    QChart* chart = new QChart();
    chart->setTitle("病例数增长曲线");
    //![1]

    //![2]
    QString name("Series ");
    int nameIndex = 0;
    QLineSeries *series = new QLineSeries(chart);
    series->setColor(QColor(255, 0, 0, 255));
    QPen pen;
    pen.setWidth(3);
    pen.setColor(QColor(255, 0, 0, 255));
    series->setPen(pen);

    QList<QPointF> points;
    
    for (int i = 23; i <= 31; ++i)
    {
        QDateTime ddd(QDate(2021, 12, i));
        ddd.toMSecsSinceEpoch();

        int count = 0;
        switch (i)
        {
        case 23: count = 49; break;
        case 24: count = 75; break;
        case 25: count = 155; break;
        case 26: count = 150; break;
        case 27: count = 175; break;
        case 28: count = 151; break;
        case 29: count = 155; break;
        case 30: count = 161; break;
        case 31: count = 174; break;
        default: break;

        }

        points.push_back(QPointF(ddd.toMSecsSinceEpoch(), count));
    }

    int endDay = 16;
    for (int i = 1; i <= endDay; ++i)
    {
        QDateTime ddd(QDate(2022, 1, i));
        ddd.toMSecsSinceEpoch();

        int count = 0;
        switch (i)
        {
        case 1: count = 122; break;
        case 2: count = 90; break;
        case 3: count = 95; break;
        case 4: count = 35; break;
        case 5: count = 63; break;
        case 6: count = 57; break;
        case 7: count = 46; break;
        case 8: count = 30; break;
        case 9: count = 15; break;
        case 10: count = 13; break;
        case 11: count = 8; break;
        case 12: count = 6; break;
        case 13: count = 8; break;
        case 14: count = 4; break;
        case 15: count = 1; break;
        case 16: count = 0; break;
        default: break;
        }

        points.push_back(QPointF(ddd.toMSecsSinceEpoch(), count));
    }

#if 0
    points.push_back(QPointF(18, 10));
    points.push_back(QPointF(19, 21));
    points.push_back(QPointF(20, 42));
    points.push_back(QPointF(21, 52));
    points.push_back(QPointF(22, 63));
    points.push_back(QPointF(23, 49));
    points.push_back(QPointF(24, 75));
    points.push_back(QPointF(25, 155));
    points.push_back(QPointF(26, 150));
    points.push_back(QPointF(27, 175));
    points.push_back(QPointF(28, 151));
    points.push_back(QPointF(29, 155));
    points.push_back(QPointF(30, 161));
    points.push_back(QPointF(31, 174));
    points.push_back(QPointF(1, 174));
#endif
    //series->append(points);
    series->replace(points);

    series->setName(name + QString::number(nameIndex));
    nameIndex++;
    chart->addSeries(series);
    //![2]

    QScatterSeries* scaSeries = new QScatterSeries(chart);
    scaSeries->setName("background");
    scaSeries->setMarkerShape(QScatterSeries::MarkerShapeCircle); // 圆点
    scaSeries->setBorderColor(QColor(21, 100, 255));
    scaSeries->setBrush(QBrush(QColor(21, 100, 255)));
    scaSeries->setMarkerSize(12); // 离散点大小

    //scaSeries->append(points);
    scaSeries->replace(points);

    bool ret = connect(scaSeries, &QScatterSeries::hovered, this, &CustomLineChart::slotPointHovered);

    chart->addSeries(scaSeries);

    QScatterSeries* scaSeries1 = new QScatterSeries(chart);
    scaSeries1->setName("forgeground");
    scaSeries1->setMarkerShape(QScatterSeries::MarkerShapeCircle); // 圆点
    scaSeries1->setBorderColor(Qt::white);
    scaSeries1->setBrush(QBrush(Qt::white));
    scaSeries1->setMarkerSize(6); // 离散点大小

    //scaSeries1->append(points);
    scaSeries1->replace(points);


    scaSeries1->setPointLabelsFormat("@yPoint"); // 设置label格式
    scaSeries1->setPointLabelsVisible(); //设置显示label

    ret = connect(scaSeries1, &QScatterSeries::hovered, this, &CustomLineChart::slotPointHovered);

    chart->addSeries(scaSeries1);

    // chart->removeSeries(series);

    chart->createDefaultAxes();
    //chart->axes(Qt::Horizontal).first()->setRange(18, 31);
    chart->axes(Qt::Vertical).first()->setRange(0, 190);

    // Add space to label to add space between labels and axis
    QValueAxis *axisY = qobject_cast<QValueAxis*>(chart->axes(Qt::Vertical).first());
    //axisY->setLabelFormat("%.1f  ");
    axisY->setLabelFormat("%g");
    axisY->setTickCount(20);

    QPen linePen;
    linePen.setColor(QColor(24, 111, 167));
    linePen.setWidth(2);
    axisY->setLinePen(linePen);
    axisY->setLabelsColor(QColor(0, 0, 0));
    axisY->setGridLineColor(QColor(24, 111, 167));

    QValueAxis *axisX = qobject_cast<QValueAxis*>(chart->axes(Qt::Horizontal).first());
    chart->removeAxis(axisX);

    QDateTimeAxis* dateAxisX = new QDateTimeAxis(chart);
    dateAxisX->setFormat("yyyy/MM/dd");
    dateAxisX->setTickCount(points.size());

    QDateTime min;
    min.setDate(QDate(2021, 12, 23));
    QDateTime max;
    max.setDate(QDate(2022, 1, endDay));

    dateAxisX->setRange(min, max);
    dateAxisX->setLabelsAngle(90);

    dateAxisX->setLinePen(linePen);
    dateAxisX->setLabelsColor(QColor(0, 0, 0));
    dateAxisX->setGridLineColor(QColor(24, 111, 167));

    chart->setAxisX(dateAxisX, series);
    chart->setAxisX(dateAxisX, scaSeries);
    chart->setAxisX(dateAxisX, scaSeries1);

   // 设置主题，默认主题是:QChart::ChartThemeLight
    chart->setTheme(QChart::ChartThemeLight);

    // 设置图例
    chart->legend()->setAlignment(Qt::AlignTop);
    //chart->legend()->seri

    return chart;
}

void CustomLineChart::slotPointHovered(const QPointF &point, bool state)
{
    if (state)
    {
        if (!m_pLabel)
        {
            m_pLabel = new QLabel(m_pWidget);
        }

#if 0
        QDateTime date = QDateTime::fromTime_t(point.x());
        QString xString = date.toString("yyyy/MM/dd");
        m_pLabel->setText(xString + "," + QString::number(point.y()));
#endif

        m_pLabel->setText(QString::number(point.y()));

        QPoint curPos = m_pWidget->mapFromGlobal(QCursor::pos());
        m_pLabel->move(curPos.x() - m_pLabel->width() / 2, curPos.y() - m_pLabel->height() * 1.5);//移动数值

        m_pLabel->show();//显示出来
    }
    else
    {
        m_pLabel->hide(); // 隐藏
    }
}
