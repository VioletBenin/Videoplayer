#include "SingleApplication.h"
#include <QtNetwork/QLocalSocket>
#include <QFileInfo>

#define TIME_OUT                (500)    // 500ms

SingleApplication::SingleApplication(int argc, char *argv[])
    : QApplication(argc, argv)
    , w(NULL)
    , _isRunning(false)
    , _localServer(NULL) {

    
    _serverName = QFileInfo(QCoreApplication::applicationFilePath()).fileName();

    _initLocalConnection();
}



bool SingleApplication::isRunning() {
    return _isRunning;
}


void SingleApplication::_newLocalConnection() {
    QLocalSocket *socket = _localServer->nextPendingConnection();
    if(socket) {
        socket->waitForReadyRead(2*TIME_OUT);
        delete socket;


        _activateWindow();
    }
}


void SingleApplication::_initLocalConnection() {
    _isRunning = false;    

    QLocalSocket socket;
    socket.connectToServer(_serverName);
    if(socket.waitForConnected(TIME_OUT)) {

        _isRunning = true;

        return;
    }


    _newLocalServer();
}

void SingleApplication::_newLocalServer() {
    _localServer = new QLocalServer(this);
    connect(_localServer, SIGNAL(newConnection()), this, SLOT(_newLocalConnection()));
	
    if(!_localServer->listen(_serverName)) {

        if(_localServer->serverError() == QAbstractSocket::AddressInUseError) {
            QLocalServer::removeServer(_serverName); 
            _localServer->listen(_serverName); 
        }
    }
}


void SingleApplication::_activateWindow() {
    if(w) {
        w->show();
        w->raise();
        w->activateWindow(); 
    }
}
