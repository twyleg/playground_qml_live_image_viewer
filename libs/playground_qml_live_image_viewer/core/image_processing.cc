// Copyright (C) 2024 twyleg
#include "image_processing.h"

#include <playground_qml_live_image_viewer/engine/Engine.h>

#include <opencv2/opencv.hpp>
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

	int frame_width = 640;
	int frame_height = 480;

	cv::Mat camera_frame;
    cv::Mat engine_frame;

	Engine engine(frame_width, frame_height, mParameterModel);

    bool running = true;

    while(running) {

		// double relativ_x;
		// double relativ_y;

		camera_frame = cv::Mat(frame_height, frame_width, CV_8UC3, cv::Scalar(255,255,255));

		engine_frame = engine.run(camera_frame);

		QImage img((uchar*)engine_frame.data, engine_frame.cols, engine_frame.rows, QImage::Format_RGB888);
		mImageModel.setImage(QPixmap::fromImage(img));

		msleep(1000 / 60.0);

    }

}


}
