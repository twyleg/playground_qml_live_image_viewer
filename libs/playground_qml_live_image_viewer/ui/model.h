// Copyright (C) 2024 twyleg
#pragma once

#include <fmt/core.h>

#include <QObject>
#include <QPixmap>
#include <QMutex>
#include <QMutexLocker>

namespace playground_qml_live_image_viewer::ui {

#define ADD_PROPERTY(datatype, name, funcName, initial_value) \
private: \
	datatype name = initial_value; \
	Q_PROPERTY(datatype name READ get##funcName WRITE set##funcName NOTIFY  name##Changed) \
public: \
	datatype& get##funcName() { \
		QMutexLocker locker(&mMutex); \
		return name; \
	} \
	void set##funcName(const datatype& value) \
	{ \
		if (name != value) {\
			mMutex.lock(); \
			name = value; \
			mMutex.unlock(); \
			emit name##Changed(); \
			emit parameterChanged(); \
		}\
	} \
Q_SIGNALS: \
	void name##Changed(); \
private: \



class ParameterModel : public QObject
{
	Q_OBJECT

private:

	QMutex mMutex;

public:

	ADD_PROPERTY(int, red, Red, 0)
	ADD_PROPERTY(int, green, Green, 0)
	ADD_PROPERTY(int, blue, Blue, 0)

	// ParameterModel getCopy() const {
	// 	QMutexLocker<QMutex>(&mMutex);
	// 	return ParameterModel(this);
	// }

Q_SIGNALS:

	void parameterChanged();

};

class ImageModel : public QObject
{
	Q_OBJECT

private:
	QPixmap image;
	Q_PROPERTY(QPixmap image READ getImage WRITE setImage NOTIFY imageChanged)


public:

	const QPixmap& getImage() const {
		return image;
	}
	void setImage(const QPixmap& image) {
		this->image = image;
		emit imageChanged();
	}

Q_SIGNALS:

	void imageChanged();

};

}
