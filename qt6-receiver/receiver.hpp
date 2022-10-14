/* SPDX-License-Identifier: WTFPL */

#include <QObject>
#include <QtDBus/QDBusObjectPath>
#include <QMap>
#include <QVariant>
#include <QString>

class Receiver : public QObject
{
	Q_OBJECT

public:
	Receiver(QObject *parent = nullptr);
	virtual ~Receiver();

private slots:
	void InterfacesAdded(QDBusObjectPath object_path,
			     QMap<QString, QVariantMap> interfaces_and_properties);
};

