#include <QtWidgets>
#include <QtTest/QtTest>
#include <iostream>

class TestQtChart : public QObject
{
    Q_OBJECT

private slots:
    void createChart();
};

#include <QChart>
#include <QChartView>
#include <QLineSeries>
#include <QValueAxis>
#include <unistd.h>

QT_BEGIN_NAMESPACE
class QComboBox;
class QCheckBox;
class Ui_ThemeWidgetForm;
QT_END_NAMESPACE

//QT_CHARTS_BEGIN_NAMESPACE
//class QChartView;
//class QChart;
//QT_CHARTS_END_NAMESPACE

typedef QPair<QPointF, QString> Data;
typedef QList<Data> DataList;
typedef QList<DataList> DataTable;

QT_CHARTS_USE_NAMESPACE


QChart *createLineChart()
{
    //![1]
    QChart *chart = new QChart();
    chart->setTitle("Line chart");
    //![1]

    //![2]
    QString name("Series ");
    int nameIndex = 0;
    Data data(QPointF(1.0, 1.0), QString("1"));
//    for (const DataList &list : m_dataTable) {
        QLineSeries *series = new QLineSeries(chart);
//        for (const Data &data : list)
            series->append(data.first);
//        series->setName(name + QString::number(nameIndex));
//        nameIndex++;
        chart->addSeries(series);
//    }
    //![2]

    //![3]
    chart->createDefaultAxes();
//    chart->axes(Qt::Horizontal).first()->setRange(0, m_valueMax);
//    chart->axes(Qt::Vertical).first()->setRange(0, m_valueCount);
    //![3]
    //![4]
    // Add space to label to add space between labels and axis
    QValueAxis *axisY = qobject_cast<QValueAxis*>(chart->axes(Qt::Vertical).first());
    Q_ASSERT(axisY);
    axisY->setLabelFormat("%.1f  ");
    //![4]

    return chart;
}


void TestQtChart::createChart() {
    QMainWindow window;
    QChartView *chartview = new QChartView(createLineChart());
    window.setCentralWidget(chartview);
    window.resize(900, 600);
    window.show();
}


QTEST_MAIN(TestQtChart)
#include "test_chart.moc"