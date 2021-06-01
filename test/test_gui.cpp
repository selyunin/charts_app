
#include <QtWidgets>
#include <QtTest/QtTest>
#include "chartview.h"
#include <iostream>

class TestQtGui : public QObject
{
    Q_OBJECT

private slots:
    void toUpper();
    void toUpper_data();
    void testGui();
    void testChartView();
};

void TestQtGui::toUpper() {
    QFETCH(QString, string);
    QFETCH(QString, result);

    QCOMPARE(string.toUpper(), result);
}

void TestQtGui::toUpper_data() {
    QTest::addColumn<QString>("string");
    QTest::addColumn<QString>("result");
    QTest::newRow("all lower")<<"hello"<<"HELLO";
    QTest::newRow("mixed")<<"hEllo"<<"HELLO";
    QTest::newRow("all upper")<<"HELLO"<<"HELLO";
}

void TestQtGui::testGui() {
    QLineEdit lineEdit;
    QTest::keyClicks(&lineEdit, "hello world");
    QCOMPARE(lineEdit.text(), QString("hello world"));
}

void TestQtGui::testChartView() {
    ChartView chartView;
    auto chartType = chartView.chart()->chartType();
    QTest::keyEvent(QTest::Press, &chartView, Qt::Key_Space);
    auto newChartType = chartView.chart()->chartType();
    QVERIFY2(chartType != newChartType, "Expecting different type after space was pressed!");
}

QTEST_MAIN(TestQtGui)
#include "test_gui.moc"