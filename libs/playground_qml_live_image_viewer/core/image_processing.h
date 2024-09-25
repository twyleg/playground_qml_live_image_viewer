// Copyright (C) 2024 twyleg
#pragma once
#include <QThread>
#include <QPixmap>

#include <playground_qml_live_image_viewer/ui/model.h>

namespace playground_qml_live_image_viewer::core {

class ImageProcessing: public QThread {

	Q_OBJECT

public:

	ImageProcessing(
		playground_qml_live_image_viewer::ui::ImageModel& imageModel,
		playground_qml_live_image_viewer::ui::ParameterModel& parameterModel,
		QObject* parent=nullptr
	);
	virtual ~ImageProcessing();

	void run() override;

	playground_qml_live_image_viewer::ui::ImageModel& mImageModel;
	playground_qml_live_image_viewer::ui::ParameterModel& mParameterModel;


private:

	QPixmap generate_test_image(int red, int green, int blue);

};

}
