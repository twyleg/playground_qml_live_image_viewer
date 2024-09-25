// Copyright (C) 2024 twyleg
#include "image_processing.h"
#include "Engine.h"
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


    cv::Mat frame = cv::Scalar(255, 255, 255);;
    cv::Mat engine_frame;

    int frame_width = 640;
    int frame_height = 480;

    Engine* engine = new Engine(frame_width, frame_height, mParameterModel);

    bool running = true;

    while(running) {

        double relativ_x;
        double relativ_y;

        if (!ret) {
            break;
        }

        engine_frame = engine->run(key, frame);

        int red = mParameterModel.getCameraSystemTranslationX();
        int green = mParameterModel.getCameraSystemTranslationY();
        int blue = mParameterModel.getCameraSystemTranslationZ();

		auto newImage = generate_test_image(red, green, blue);

		mImageModel.setImage(newImage);

		msleep(1000 / 60.0);

    }

    cap.release();
    cv::destroyAllWindows();

    delete engine;
}


QPixmap ImageProcessing::generate_test_image(int red, int green, int blue) {
   int width = 1280;
   int height = 720;

   QPixmap pixmap(width, height);

   //QPixmap foo()

   pixmap.fill(QColor(red, green, blue).rgba());
   return pixmap;

}

}
