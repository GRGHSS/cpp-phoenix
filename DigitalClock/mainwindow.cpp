#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QWidget *centralWidget = new QWidget(this);
    centralWidget->setStyleSheet("background-color: black;");
    QVBoxLayout *layout = new QVBoxLayout(centralWidget);

    lcdNumber = new QLabel(this);
    lcdNumber->setAlignment(Qt::AlignCenter);
    lcdNumber->setStyleSheet("QLabel { color: white; font: 11pt Ani; font-size: 45px; }");
    layout->addWidget(lcdNumber);

    setCentralWidget(centralWidget);

    DateTime = new QTimer(this);
    connect(DateTime, &QTimer::timeout, this, &MainWindow::Date_Time_Display_Slot);
    DateTime->start(1000);

    DateTimeFormat = "hh:mm:ss";

    formatButton = new QPushButton("AM/PM", this);
    formatButton->setStyleSheet("QPushButton { background-color: blue; color: white; font-size: 16px; }"
                                "QPushButton:hover { background-color: yellow; color: black}");
    formatButton->setCursor(Qt::PointingHandCursor);
    formatButton->setGeometry(0, 0, 60, 30); // x, y, width, height


    layout->addWidget(formatButton, 0, Qt::AlignBottom | Qt::AlignLeft);

    connect(formatButton, &QPushButton::clicked, this, &MainWindow::changeTimeFormat);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::updateTime() {
        QString currentTime = QDateTime::currentDateTime().toString(DateTimeFormat);
        lcdNumber->setText(currentTime);
        lcdNumber->setAlignment(Qt::AlignCenter);
}
void MainWindow::Date_Time_Display_Slot()
{
    updateTime();
}

void MainWindow::changeTimeFormat() {
    if (DateTimeFormat == "hh:mm:ss") {
        DateTimeFormat = "hh:mm:ss AP";
    } else {
        DateTimeFormat = "hh:mm:ss";
    }
    updateTime();
}


