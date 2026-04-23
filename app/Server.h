#pragma once

#include <QObject>
#include <QtWebSockets/QWebSocket>
#include <QtWebSockets/QWebSocketServer>

class Server : public QObject {
    Q_OBJECT

   public:
    Server(quint16 port, QObject* parent = nullptr);
    ~Server();

   private slots:
    void onNewConnection();
    void onTextMessageReceived(QString message);
    void onDisconnected();

   private:
    QWebSocketServer* _server;
    std::vector<QWebSocket*> _sockets;
};