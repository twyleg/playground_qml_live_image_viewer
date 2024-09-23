// Copyright (C) 2024 twyleg
#include "image_processing.h"

#include <fmt/core.h>

#include <optional>

namespace playground_qml_live_image_viewer::core {

ImageProcessing::ImageProcessing(
		playground_qml_live_image_viewer::ui::ImageModel& imageModel,
		playground_qml_live_image_viewer::ui::ParameterModel& parameterModel,
		QObject* parent) :
	QThread(parent),
	mImageModel(imageModel),
	mParameterModel(parameterModel)
{
	QObject::connect(this, &playground_qml_live_image_viewer::core::ImageProcessing::imageReady,
					 &imageModel, &playground_qml_live_image_viewer::ui::ImageModel::setImage);

}

ImageProcessing::~ImageProcessing() {}

void ImageProcessing::run() {

	int count = 0;
	while(true) {
		fmt::println("{}", count++);

		int red = mParameterModel.getRed();
		int green = mParameterModel.getGreen();
		int blue = mParameterModel.getBlue();

		auto newImage = generate_test_image(red, green, blue);

		emit imageReady(newImage);

		msleep(1000);
	}



}


QPixmap ImageProcessing::generate_test_image(int red, int green, int blue) {

   int width = 1280;
   int height = 720;

   if (mColor == "red"){
	   mColor = "green";
   } else {
	   mColor = "red";
   }

   fmt::println("{}", mColor);

   QPixmap pixmap(width, height);
   // pixmap.fill(QColor(QString::fromStdString(mColor)).rgba());
   pixmap.fill(QColor(red, green, blue).rgba());
   return pixmap;

}

}
