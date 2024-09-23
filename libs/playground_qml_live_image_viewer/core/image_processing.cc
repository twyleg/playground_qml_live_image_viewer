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
{}

ImageProcessing::~ImageProcessing() {}

void ImageProcessing::run() {

	while(true) {
		int red = mParameterModel.getRed();
		int green = mParameterModel.getGreen();
		int blue = mParameterModel.getBlue();

		auto newImage = generate_test_image(red, green, blue);

		mImageModel.setImage(newImage);

		msleep(1000 / 60.0);
	}



}


QPixmap ImageProcessing::generate_test_image(int red, int green, int blue) {
   int width = 1280;
   int height = 720;

   QPixmap pixmap(width, height);
   pixmap.fill(QColor(red, green, blue).rgba());
   return pixmap;

}

}
