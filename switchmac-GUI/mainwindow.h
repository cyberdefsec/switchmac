#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QComboBox>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QCheckBox>
#include <QVBoxLayout>
#include <QHBoxLayout>

#define MIN_HEIGHT 0
#define MAX_HEIGHT 660
#define MAX_WIDTH 350
#define MAX_LEN 2

class MainWindow : public QMainWindow{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QWidget *centerWidget = nullptr;
    QVBoxLayout *vlayout = nullptr;
    QHBoxLayout *hlayout = nullptr;
    QHBoxLayout *hlayMac = nullptr;
    QLabel *nameInterface = nullptr;
    QComboBox *listInterface = nullptr;
    QPushButton *btnReload = nullptr;
    QCheckBox *onRandom = nullptr;
    QLineEdit *oneOctet = nullptr;
    QLabel *oneSeparator = nullptr;
    QLineEdit *twoOctet = nullptr;
    QLabel *twoSeparator = nullptr;
    QLineEdit *threeOctet = nullptr;
    QLabel *threeSeparator = nullptr;
    QLineEdit *fourOctet = nullptr;
    QLabel *fourSeparator = nullptr;
    QLineEdit *fiveOctet = nullptr;
    QLabel *fiveSeparator = nullptr;
    QLineEdit *sixOctet = nullptr;
    QPushButton *btnRandMac = nullptr;
    QPushButton *btnChangeMac = nullptr;

    void setOctetEnabled(bool state);

public slots:
    void onRandMac();
};

#endif // MAINWINDOW_H
