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

void SingleApplication::_initLocalConnection() {
    _isRunning = false;    

    QLocalSocket socket;
    socket.connectToServer(_serverName);
	//Qt assistant:Waits until the socket is connected, up to msecs milliseconds. If the connection has been established, this function returns true; otherwise it returns false.
    if(socket.waitForConnected(TIME_OUT)) {//连接建立
        _isRunning = true;

        return;
    }

    //连接不上服务器，就创建一个
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

void SingleApplication::_newLocalConnection() {
	//Qt assistant:0 is returned if this function is called when there are no pending connections.
    QLocalSocket *socket = _localServer->nextPendingConnection();
    if(socket!=nullptr) {
        socket->waitForReadyRead(2*TIME_OUT);
        delete socket;
        _activateWindow();
    }
}

bool SingleApplication::isRunning() {
    return _isRunning;
}

void SingleApplication::_activateWindow() {
    if(w) {
        w->show();
        w->raise();
        w->activateWindow();
    }
}
