#pragma once

#include <QObject>
#include <QtWebSockets/QWebSocket>
#include <QtWebSockets/QWebSocketServer>

class ServerApp : public QObject {
    Q_OBJECT

   public:
    ServerApp(quint16 port, QObject* parent = nullptr);
    ~ServerApp();

   private slots:
    void onNewConnection();
    void onTextMessageReceived(QString message);
    void onDisconnected();

   private:
    // Core::Server _server;
    QWebSocketServer* _socketServer;
    std::vector<QWebSocket*> _sockets;
};