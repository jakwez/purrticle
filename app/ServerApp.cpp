#include "ServerApp.h"

#include <algorithm>

ServerApp::ServerApp(quint16 port, QObject* parent) : QObject(parent) {
    _socketServer = new QWebSocketServer("QtServer", QWebSocketServer::NonSecureMode, this);
    if (_socketServer->listen(QHostAddress::Any, port)) {
        qDebug() << "Server started on port" << port;
        connect(_socketServer, &QWebSocketServer::newConnection, this, &ServerApp::onNewConnection);
    } else {
        qFatal("Failed to start server!");
    }
}

ServerApp::~ServerApp() {
    _socketServer->close();
    for (auto socket : _sockets) {
        delete socket;
    }
    _sockets.clear();  // does closing the server
}

void ServerApp::onNewConnection() {
    QWebSocket* socket = _socketServer->nextPendingConnection();
    if (std::find(_sockets.begin(), _sockets.end(), socket) != _sockets.end()) {
        qFatal() << "Socket already connected";
        return;
    }
    _sockets.push_back(socket);
    qDebug() << "New socket connected:" << socket->peerAddress().toString();
    connect(socket, &QWebSocket::textMessageReceived, this, &ServerApp::onTextMessageReceived);
    connect(socket, &QWebSocket::disconnected, this, &ServerApp::onDisconnected);

    socket->sendTextMessage("Welcome to the WebSocket Server!");
}

void ServerApp::onTextMessageReceived(QString message) {
    QWebSocket* socket = qobject_cast<QWebSocket*>(sender());
    if (std::find(_sockets.begin(), _sockets.end(), socket) == _sockets.end()) {
        qFatal() << "Unknown socket";
        return;
    }
    qDebug() << "Server received:" << message;
    socket->sendTextMessage("Echo: " + message);
}

void ServerApp::onDisconnected() {
    QWebSocket* socket = qobject_cast<QWebSocket*>(sender());
    auto it = std::find(_sockets.begin(), _sockets.end(), socket);
    if (it == _sockets.end()) {
        qFatal() << "Unknown socket";
        return;
    }
    _sockets.erase(it);
    delete socket;
}