/* SPDX-License-Identifier: MIT */

#include <QObject>
#include <QtDBus/QDBusObjectPath>
#include <QMap>
#include <QVariant>
#include <QString>

typedef QMap<QString, QDBusVariant> QDBusVariantMap;
Q_DECLARE_METATYPE(QDBusVariantMap);
typedef QMap<QString, QDBusVariantMap> QDBusVariantMapMap;
Q_DECLARE_METATYPE(QDBusVariantMapMap);

class Receiver : public QObject
{
	Q_OBJECT

public:
	Receiver(QObject *parent = nullptr);
	virtual ~Receiver();

private slots:
	void InterfacesAdded(QDBusObjectPath object_path,
			     QDBusVariantMapMap interfaces_and_properties);
};

