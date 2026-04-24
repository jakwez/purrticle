#include "ClientApp.h"

ClientApp::ClientApp(const QUrl& url, QObject* parent) : QObject(parent) {
    connect(&_webSocket, &QWebSocket::connected, this, &ClientApp::onConnected);
    connect(&_webSocket, &QWebSocket::textMessageReceived, this, &ClientApp::onTextMessageReceived);
    connect(&_webSocket, &QWebSocket::binaryMessageReceived, this, &ClientApp::onBinaryMessageReceived);
    _webSocket.open(url);
}

void ClientApp::onConnected() {
    qDebug() << "Connected to server!";
    _webSocket.sendTextMessage("Hello from distinct client class!");
}

void ClientApp::onTextMessageReceived(const QString& message) {
    //
    qDebug() << "Client received txt:" << message;
}

void ClientApp::onBinaryMessageReceived(const QByteArray& message) {
    // qDebug() << "Client received bin:" << message.size();
    float deltaTimeSec = 0;
    if (_elapsedTimer.isValid()) {
        qint64 deltaTimeMs = _elapsedTimer.restart();
        deltaTimeSec = static_cast<float>(deltaTimeMs) / 1000.f;
    } else {
        _elapsedTimer.start();
    }

    std::vector<uint8_t> data(reinterpret_cast<const uint8_t*>(message.constData()),
                              reinterpret_cast<const uint8_t*>(message.constData() + message.size()));
    _client.update(deltaTimeSec, data);
}