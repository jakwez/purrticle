#pragma once

#include <QObject>
#include <QtWebSockets/QWebSocket>

class ClientApp : public QObject {
    Q_OBJECT

   public:
    Client(const QUrl& url, QObject* parent = nullptr);

   private slots:
    void onConnected();
    void onMessageReceived(const QString& message);

   private:
    QWebSocket _webSocket;
};