#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QChartView>
#include <QChart>
#include <QValueAxis>
#include <QLineSeries>
#include <QTimer>
#include <QThreadPool>
#include <QRunnable>
#include <iostream>
#include <functional>
#include <queue>

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
    auto data = QPointF(1.0, 1.0);
    QLineSeries *series = new QLineSeries(chart);
    series->append(data);
    series->setName(name + QString::number(nameIndex));
    chart->addSeries(series);
    //![2]

    //![3]
    chart->createDefaultAxes();
    chart->axes(Qt::Horizontal).first()->setRange(0, 2);
    chart->axes(Qt::Vertical).first()->setRange(0, 2);
    //![3]
    //![4]
    // Add space to label to add space between labels and axis
    QValueAxis *axisY = qobject_cast<QValueAxis*>(chart->axes(Qt::Vertical).first());
    Q_ASSERT(axisY);
    axisY->setLabelFormat("%.1f  ");
    //![4]

    return chart;
}

class DataGenerator : public QObject
{
public:
    DataGenerator(){
        sample_timer.setInterval(200);
        QObject::connect(&sample_timer, &QTimer::timeout, this, &DataGenerator::add_sample);

    }

    void add_sample(){
        auto time_stamp = idx * time_resolution;
        auto value = (idx % 2 == 0) ? 0.0 : 1.0;
        idx++;
        data.append(QPointF(time_stamp, value));
        if (data.size() > 10){
            data.pop_front();
        }
    }

    void start(){
        sample_timer.start();
    }

    QList<QPointF> data;
    float time_resolution = 0.1;
    int idx = 0;
    QTimer sample_timer;
};


class ChartUpdateJob : public QRunnable
{
public:
    ChartUpdateJob(std::function<void(QChart*, DataGenerator*)> func, QChart* p_chart, DataGenerator* p_generator)
        :m_func(func), m_p_chart(p_chart), m_p_generator(p_generator)
    { }
    void run() override { m_func(m_p_chart, m_p_generator); }
private:
    std::function<void(QChart*, DataGenerator*)> m_func;
    QChart* m_p_chart;
    DataGenerator* m_p_generator;
};



class ChartUpdater : public QObject
{
public:
    ChartUpdater(QChart* p_chart, DataGenerator* p_generator):
        m_ptr_chart(p_chart), m_p_generator(p_generator) { }
    static void updateRunnable(QChart* p_chart, DataGenerator* p_generator)
    {
        if (!p_chart){
            std::cout<<"Pointer is invalid, exit \n";
            return;
        }
        std::cout<<"Updating from another thread \n";
        QList<QPointF> data_points = p_generator->data;
        std::cout<<"Length of data points = "<<data_points.size()<<"\n";
        auto chart_series = p_chart->series();
        std::cout<<"Length of chart series = "<<chart_series.size()<<"\n";
        auto existing_series = (QLineSeries*)chart_series.at(0);
        existing_series->replace(data_points);
        auto y_axis = p_chart->axisY();
        QList<qreal> x_values;
        QList<qreal> y_values;
        for (auto& el : data_points){
            x_values.push_back(el.x());
            y_values.push_back(el.y());
        }
        y_axis->setRange(0.0, 1.1);
        auto x_axis = p_chart->axisX();
        auto first_time_stamp = data_points[0].x();
        auto last_time_stamp = data_points[data_points.size() - 1].x();
        x_axis->setRange(first_time_stamp, last_time_stamp);
    }

    void updateChart()
    {
        auto runnable = new ChartUpdateJob(&ChartUpdater::updateRunnable, m_ptr_chart, m_p_generator);
        m_threadPool.start(runnable);
        std::cout<<"Updating chart \n";
    }
    QThreadPool m_threadPool;
    QChart* m_ptr_chart;
    DataGenerator* m_p_generator;
};


int main(int argc, char** argv)
{
    QApplication app(argc, argv);

    QMainWindow mainWindow;

    QChart* chart = createLineChart();

    DataGenerator generator;
    generator.start();

    auto chartView = new QChartView(chart);
    QTimer timer;
    timer.setInterval(1000);
    ChartUpdater updater(chart, &generator);
    QObject::connect(&timer, &QTimer::timeout, &updater, &ChartUpdater::updateChart);

    mainWindow.setCentralWidget(chartView);

    mainWindow.show();

    mainWindow.resize(600, 600);

    mainWindow.move(200, 200);

    QPalette pal = mainWindow.palette();
    pal.setColor(QPalette::Window, QRgb(0x121218));
    pal.setColor(QPalette::WindowText, QRgb(0xd6d6d6));
    mainWindow.setPalette(pal);

    chartView->chart()->setTheme(QtCharts::QChart::ChartThemeDark);

    timer.start();

    return app.exec();
}
