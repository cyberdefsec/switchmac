#include"application.h"

Application::Application(int &argc, char **argv) : QApplication(argc, argv){
    setApplicationDisplayName(tr("switchmac-GUI"));
    setApplicationName(tr("switchmac-GUI"));
    setWindowIcon(QIcon(":/ico/mac.ico"));
}

Application::~Application(){

}

