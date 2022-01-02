

#ifndef CUSTOM_DIALOGLINE_CHART_H
#define CUSTOM_DIALOGLINE_CHART_H

#include <QObject>

class QWidget;
class QLabel;

#include <QChart>
using namespace QT_CHARTS_NAMESPACE;

class CustomLineChart final : public QObject
{
    Q_OBJECT

public:

    CustomLineChart(QWidget* parent);

    QChart* createLineChart();

private slots:
    void slotPointHovered(const QPointF &point, bool state);

private:
    QLabel* m_pLabel = nullptr;
    QWidget* m_pWidget = nullptr;

};


#endif // !CUSTOM_DIALOGLINE_CHART_H
