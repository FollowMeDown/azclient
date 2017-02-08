/*
 * Copyright (C) 2017 Nessla AB
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#ifndef CONNECTIONWINDOW_H
#define CONNECTIONWINDOW_H

#include "VpnApi.h"
#include "PowerNotifier.h"

#include <QDialog>
#include <QSettings>
#include <QApplication>

class QLineEdit;
class QComboBox;
class StatusIcon;
class QLabel;

class ConnectionWindow : public QDialog
{
	Q_OBJECT

public:
	ConnectionWindow(QWidget *parent = 0);

protected:
	void closeEvent(QCloseEvent *event);

private:
	void setStatusText(const QString &text = QString::null);
	void populateRegions();
	void regionsLoading();
	void startOpenVpn(const QByteArray &config);
	StatusIcon *m_statusIcon;
	QLabel *m_status;
	QLineEdit *m_username;
	QLineEdit *m_password;
	QComboBox *m_region;
	QComboBox *m_protocol;
	QPushButton *m_connect;
	VpnApi *m_api;
	QSettings m_settings;
	bool m_updateGuard;
	bool m_goingToSleepWhileConnected;
	QString m_lastUsername;
	QString m_lastPassword;
	PowerNotifier *m_powerNotifier;

private slots:
	void checkForUpdates();
	void validateFields();

public slots:
	void accept() { hide(); }
	void reject() { hide(); }
};

#endif // CONNECTIONWINDOW_H
