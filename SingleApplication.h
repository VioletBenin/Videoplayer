#ifndef SINGLEAPPLICATION_H
#define SINGLEAPPLICATION_H

#include <QObject>
#include <QApplication>
#include <QtNetwork/QLocalServer>
#include <QWidget>

class SingleApplication : public QApplication {
        Q_OBJECT
    public:
        SingleApplication(int argc, char *argv[]);

        bool isRunning();                
        QWidget *w;                       

    private slots:

        void _newLocalConnection();

    private:

        void _initLocalConnection();

        void _newLocalServer();

        void _activateWindow();

        bool _isRunning;               
        QLocalServer *_localServer;     
        QString _serverName;            
};

#endif // SINGLEAPPLICATION_H
