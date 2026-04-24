#pragma once

#include <QObject>
#include <QTimer>
#include <QtWebSockets/QWebSocket>
#include <QtWebSockets/QWebSocketServer>

#include "Server.h"

class ServerApp : public QObject {
    Q_OBJECT

   public:
    ServerApp(quint16 port, QObject* parent = nullptr);
    ~ServerApp();
    Core::Server& server() { return _server; }

   private slots:
    void onTimerTimeout();
    void onNewConnection();
    void onTextMessageReceived(QString message);
    void onDisconnected();

   private:
    QElapsedTimer _elapsedTimer;
    QTimer _timer;
    Core::Server _server;
    QWebSocketServer* _socketServer;
    std::vector<QWebSocket*> _sockets;
};