#include <iostream>
#include <thread>
#include <chrono>

#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QFormLayout>
#include <QTimer>

class MainWindow : public QWidget {
    public:
    MainWindow(QWidget *parent = nullptr);

    private:
    QLabel *m_label;
    QPushButton *m_button;
    QTimer *m_timer;

    int m_counter;
};

MainWindow::MainWindow(QWidget *parent) : QWidget(parent) {
    
    //window property
    setWindowTitle("Class");
    resize(800, 800);

    //widgets
    m_label = new QLabel("Click the button bastard");
    m_button = new QPushButton("Start a timer bastard");

    m_counter = 0;
    m_timer = new QTimer(this);

    //signal
    connect(m_timer, &QTimer::timeout, [=]() {
        
        m_counter++;

        m_label->setText(QString("Counter: %1").arg(m_counter) );

        if (m_counter >= 10) {
            m_timer->stop();
            m_label->setText("Done");
        }
    });

    //layout
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(m_label);
    layout->addWidget(m_button);

    //connecting signal to slot
    connect(m_button, &QPushButton::clicked, [=]() {
        
        m_label->setText("Starting...");
        m_timer->start(1000);

    });
}

int main(int argc, char *argv []) {
    QApplication app(argc, argv);

    //Window
    MainWindow window;

    window.show();

    return app.exec();
}
