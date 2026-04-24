#pragma once

#include <QElapsedTimer>
#include <QObject>
#include <QtWebSockets/QWebSocket>

#include "Client.h"

class ClientApp : public QObject {
    Q_OBJECT

   public:
    ClientApp(const QUrl& url, QObject* parent = nullptr);
    Core::Client& client() { return _client; }

   private slots:
    void onConnected();
    void onTextMessageReceived(const QString& message);
    void onBinaryMessageReceived(const QByteArray& message);

   private:
    QElapsedTimer _elapsedTimer;
    Core::Client _client;
    QWebSocket _webSocket;
};