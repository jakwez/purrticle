#include "Client.h"

Client::Client(const QUrl& url, QObject* parent) : QObject(parent) {
    connect(&_webSocket, &QWebSocket::connected, this, &Client::onConnected);
    connect(&_webSocket, &QWebSocket::textMessageReceived, this, &Client::onMessageReceived);
    _webSocket.open(url);
}

void Client::onConnected() {
    qDebug() << "Connected to server!";
    _webSocket.sendTextMessage("Hello from distinct client class!");
}

void Client::onMessageReceived(const QString& message) {
    //
    qDebug() << "Client received:" << message;
}