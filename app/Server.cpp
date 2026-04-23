#include "Server.h"

#include <algorithm>

Server::Server(quint16 port, QObject* parent) : QObject(parent) {
    _server = new QWebSocketServer("QtServer", QWebSocketServer::NonSecureMode, this);
    if (_server->listen(QHostAddress::Any, port)) {
        qDebug() << "Server started on port" << port;
        connect(_server, &QWebSocketServer::newConnection, this, &Server::onNewConnection);
    } else {
        qFatal("Failed to start server!");
    }
}

Server::~Server() {
    _server->close();
    for (auto socket : _sockets) {
        delete socket;
    }
    _sockets.clear();  // does closing the server
}

void Server::onNewConnection() {
    QWebSocket* socket = _server->nextPendingConnection();
    if (std::find(_sockets.begin(), _sockets.end(), socket) != _sockets.end()) {
        qFatal() << "Socket already connected";
        return;
    }
    _sockets.push_back(socket);
    qDebug() << "New socket connected:" << socket->peerAddress().toString();
    connect(socket, &QWebSocket::textMessageReceived, this, &Server::onTextMessageReceived);
    connect(socket, &QWebSocket::disconnected, this, &Server::onDisconnected);

    socket->sendTextMessage("Welcome to the WebSocket Server!");
}

void Server::onTextMessageReceived(QString message) {
    QWebSocket* socket = qobject_cast<QWebSocket*>(sender());
    if (std::find(_sockets.begin(), _sockets.end(), socket) == _sockets.end()) {
        qFatal() << "Unknown socket";
        return;
    }
    qDebug() << "Server received:" << message;
    socket->sendTextMessage("Echo: " + message);
}

void Server::onDisconnected() {
    QWebSocket* socket = qobject_cast<QWebSocket*>(sender());
    auto it = std::find(_sockets.begin(), _sockets.end(), socket);
    if (it == _sockets.end()) {
        qFatal() << "Unknown socket";
        return;
    }
    _sockets.erase(it);
    delete socket;
}