// SPDX-License-Identifier: WTFPL

#include <QtGlobal>
#include <QDebug>
#include <QtWidgets/QApplication>
#include <QtDBus/QDBusInterface>
#include <QtDBus/QDBusMetaType>

#include "receiver.hpp"

Receiver::Receiver(QObject *parent) : QObject(parent) { }

Receiver::~Receiver() { }

void Receiver::InterfacesAdded(QDBusObjectPath object_path,
			       QDBusVariantMapMap interfaces_and_properties)
{
	Q_UNUSED(interfaces_and_properties);

	qInfo() << "InterfacesAdded: " << object_path.path();
}

int main(int argc, char **argv)
{
	QApplication app(argc, argv);

	auto bus = QDBusConnection::sessionBus();
	Receiver receiver;

	qDBusRegisterMetaType<QDBusVariantMap>();
	qDBusRegisterMetaType<QDBusVariantMapMap>();

	qInfo() << "Before connection";
	qInfo() << "Is connected " << bus.isConnected();

	qInfo() << "Trying to connect";
	auto ret = bus.connect(
		"org.foobar.Provider1",
		"/org/foobar/Provider1",
		"org.freedesktop.DBus.ObjectManager",
		"InterfacesAdded",
		&receiver,
		SLOT(InterfacesAdded(QDBusObjectPath, QDBusVariantMapMap))
	);

	qInfo() << "connect() result: " << ret;
	if (!ret)
		qInfo() << "lastError: " << bus.lastError();

	return app.exec();
}
