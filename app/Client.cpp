#include "Client.h"

ClientApp::ClientApp(const QUrl& url, QObject* parent) : QObject(parent) {
    connect(&_webSocket, &QWebSocket::connected, this, &ClientApp::onConnected);
    connect(&_webSocket, &QWebSocket::textMessageReceived, this, &ClientApp::onMessageReceived);
    _webSocket.open(url);
}

void ClientApp::onConnected() {
    qDebug() << "Connected to server!";
    _webSocket.sendTextMessage("Hello from distinct client class!");
}

void ClientApp::onMessageReceived(const QString& message) {
    //
    qDebug() << "Client received:" << message;
}