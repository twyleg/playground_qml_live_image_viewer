// Copyright (C) 2024 twyleg
#include "image_processing.h"
#include "Engine.h"

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

    std::string video_path = "http://192.168.30.142:8443/normal.py";
    cv::VideoCapture cap(video_path);

    cv::Mat frame;

    if (!cap.isOpened()) {
        std::cerr << "Error: Could not open video file!" << std::endl;
        return -1;
    }

    int frame_width = static_cast<int>(cap.get(cv::CAP_PROP_FRAME_WIDTH));
    int frame_height = static_cast<int>(cap.get(cv::CAP_PROP_FRAME_HEIGHT));

    Engine* engine = new Engine(frame_width, frame_height);

    bool running = true;

    while(running) {


        double relativ_x;
        double relativ_y;

        bool ret = cap.read(frame);

        if (!ret) {
            break;
        }

        int key = cv::waitKey(10);

        engine->run(key, frame);

        if (key == 27) {
            running = false;
        }

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
