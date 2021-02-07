#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent){
    setMaximumSize(MAX_WIDTH, MIN_HEIGHT);
    setMinimumSize(MAX_WIDTH, MIN_HEIGHT);

    centerWidget = new QWidget(this);
    setCentralWidget(centerWidget);

    vlayout = new QVBoxLayout;
    centerWidget->setLayout(vlayout);

    hlayout = new QHBoxLayout;

    nameInterface = new QLabel(tr("Interfaces"), this);
    vlayout->addWidget(nameInterface);

    vlayout->addLayout(hlayout);

    listInterface = new QComboBox(this);
    listInterface->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Maximum);
    hlayout->addWidget(listInterface);

    btnReload = new QPushButton(this);
    btnReload->setIcon(QIcon(":/ico/reload.ico"));
    hlayout->addWidget(btnReload);

    onRandom = new QCheckBox(tr("Random mac"), this);
    onRandom->setCheckState(Qt::Checked);
    vlayout->addWidget(onRandom);

    hlayMac = new QHBoxLayout;
    vlayout->addLayout(hlayMac);

    oneOctet = new QLineEdit(this);
    oneOctet->setMaxLength(MAX_LEN);
    oneOctet->setAlignment(Qt::AlignCenter);
    oneOctet->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
    hlayMac->addWidget(oneOctet);

    oneSeparator = new QLabel(":", this);
    oneSeparator->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
    hlayMac->addWidget(oneSeparator);

    twoOctet = new QLineEdit(this);
    twoOctet->setMaxLength(MAX_LEN);
    twoOctet->setAlignment(Qt::AlignCenter);
    twoOctet->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
    hlayMac->addWidget(twoOctet);

    twoSeparator = new QLabel(":", this);
    twoSeparator->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
    hlayMac->addWidget(twoSeparator);

    threeOctet = new QLineEdit(this);
    threeOctet->setMaxLength(MAX_LEN);
    threeOctet->setAlignment(Qt::AlignCenter);
    threeOctet->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
    hlayMac->addWidget(threeOctet);

    threeSeparator = new QLabel(":", this);
    threeSeparator->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
    hlayMac->addWidget(threeSeparator);

    fourOctet = new QLineEdit(this);
    fourOctet->setMaxLength(MAX_LEN);
    fourOctet->setAlignment(Qt::AlignCenter);
    fourOctet->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
    hlayMac->addWidget(fourOctet);

    fourSeparator = new QLabel(":", this);
    fourSeparator->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
    hlayMac->addWidget(fourSeparator);

    fiveOctet = new QLineEdit(this);
    fiveOctet->setMaxLength(MAX_LEN);
    fiveOctet->setAlignment(Qt::AlignCenter);
    fiveOctet->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
    hlayMac->addWidget(fiveOctet);

    fiveSeparator = new QLabel(":", this);
    fiveSeparator->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
    hlayMac->addWidget(fiveSeparator);

    sixOctet = new QLineEdit(this);
    sixOctet->setMaxLength(MAX_LEN);
    sixOctet->setAlignment(Qt::AlignCenter);
    sixOctet->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
    hlayMac->addWidget(sixOctet);
    setOctetEnabled(false);

    btnRandMac = new QPushButton(tr("Generation"), this);
    btnRandMac->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
    hlayMac->addWidget(btnRandMac);

    hlayInfo = new QHBoxLayout;
    vlayout->addLayout(hlayInfo);

    infoMsg = new QLabel(this);
    infoMsg->setStyleSheet("color: green");
    infoMsg->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Maximum);
    hlayInfo->addWidget(infoMsg);

    btnChangeMac = new QPushButton(tr("Change"), this);
    btnChangeMac->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
    hlayInfo->addWidget(btnChangeMac);
    hlayInfo->addSpacing(1);

    setInterfaces();

    mac = new Mac(this);

    connect(onRandom, SIGNAL(stateChanged(int)), this, SLOT(onRandMac()));
    connect(btnReload, SIGNAL(clicked()), this, SLOT(setInterfaces()));
    connect(listInterface, SIGNAL(currentTextChanged(const QString &)), this, SLOT(currentMac(const QString &)));
    connect(btnChangeMac, SIGNAL(clicked()), this, SLOT(setMac()));
}

MainWindow::~MainWindow(){

}

void MainWindow::setOctetEnabled(bool state){
    oneOctet->setEnabled(state);
    twoOctet->setEnabled(state);
    threeOctet->setEnabled(state);
    fourOctet->setEnabled(state);
    fiveOctet->setEnabled(state);
    sixOctet->setEnabled(state);

}

QList<QNetworkInterface> MainWindow::getInterfaces(){
    QList<QNetworkInterface> interface;
    interface = QNetworkInterface::allInterfaces();
    for(int count = 0; count < interface.size(); ++count){
        if(!(interface.at(count).flags() & QNetworkInterface::IsUp) || (interface.at(count).flags() & QNetworkInterface::IsLoopBack))
            interface.removeAt(count);
    }
    return interface;
}

void MainWindow::setInterfaces(){
    listInterface->clear();
    foreach(QNetworkInterface interface, getInterfaces()){
        listInterface->addItem(interface.name());
        if(QNetworkInterface::IsRunning & interface.flags()){
            listInterface->setCurrentText(interface.name());
            listInterface->setToolTip(mac->getMacAddress(interface.name()));
        }
    }
}

void MainWindow::currentMac(const QString &name){
    listInterface->setToolTip(mac->getMacAddress(name));
}

void MainWindow::setMac(){
    QString macAddr;
    if(!(oneOctet->text().isEmpty() && twoOctet->text().isEmpty() && threeOctet->text().isEmpty() && fourOctet->text().isEmpty() && fiveOctet->text().isEmpty() && sixOctet->text().isEmpty()))
        macAddr.append(QString("%1:%2:%3:%4:%5:%6").arg(oneOctet->text()).arg(twoOctet->text()).arg(threeOctet->text()).arg(fourOctet->text()).arg(fiveOctet->text()).arg(sixOctet->text()));
    else
        infoMsg->setText(tr("Enter mac address!"));
}

void MainWindow::onRandMac(){
    if(onRandom->isChecked() == false){
        setOctetEnabled(true);
        btnRandMac->setEnabled(false);
    }
    else{
        setOctetEnabled(false);
        btnRandMac->setEnabled(true);
    }
}
