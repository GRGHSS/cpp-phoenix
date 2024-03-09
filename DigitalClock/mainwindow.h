#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDateTime>
#include <QTime>
#include <QString>
#include <QDebug>
#include <QTimer>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QFontDatabase>
#include <QDebug>




QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void Date_Time_Display_Slot();
    void updateTime();
    void changeTimeFormat();

private:
    Ui::MainWindow *ui;
    QTimer *DateTime;
    QString DateTimeFormat;
    QLabel *timeLabel;
    QLabel *lcdNumber;
    QPushButton *formatButton;
};
#endif // MAINWINDOW_H
