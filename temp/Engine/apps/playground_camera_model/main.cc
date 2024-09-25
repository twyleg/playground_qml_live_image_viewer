#include "Engine.h"
#include <opencv2/opencv.hpp>


int main() {
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

    while (running) {


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
    }


    cap.release();
    cv::destroyAllWindows();

    delete engine;


    return 0;
}
