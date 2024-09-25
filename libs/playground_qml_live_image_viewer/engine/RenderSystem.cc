// Copyright (C) 2024 Marvin-VW
#include "RenderSystem.h"
#include "Shape.h"
#include "iostream"
#include "HomogenousTransformationMatrix.h"
#include "CameraModel.h"
#include "FPSCounter.h"
#include "ClippingSpace.h"
#include "Color.h"
#include "Vectors.h"
#include <exception>

#define DEG_TO_RAD(x) ((x) * (M_PI / 180.0))

RenderSystem::RenderSystem(playground_qml_live_image_viewer::ui::ParameterModel& parameterModel) {

    /*

    // Initialize transformation parameters
    window.cameraSystemTranslationX = 10000; //10000mm //1000cm // 10m
    window.cameraSystemTranslationY = 10130;
    window.cameraSystemTranslationZ = 10150;

    window.cameraSystemRotationRoll = 2700;
    window.cameraSystemRotationPitch = 0;
    window.cameraSystemRotationYaw = 2700;

    window.cubeSystemTranslationX = 10330;
    window.cubeSystemTranslationY = 10130;
    window.cubeSystemTranslationZ = 10080;

    window.cubeSystemRotationRoll = 0;
    window.cubeSystemRotationPitch = 0;
    window.cubeSystemRotationYaw = 0;

    window.cubeSystemScale = 0;

    window.cubeSystemNormals = 0;
    window.cubeSystemPoints = 0;
    window.cubeSystemFaces = 0;

    */

    this->parameterModel = parameterModel;
   
    fc = new FpsCounter(60);

}

HomogenousTransformationMatrix* RenderSystem::init_matrices()
{
    ht = new HomogenousTransformationMatrix();

    cm->V_T_C = ht->createHomogeneousTransformationMatrix(0, 0, 0, 0, 0, 0, 0);
    cm->C_T_V = cm->V_T_C.inv();
    cm->V_T_Cube = ht->createHomogeneousTransformationMatrix(2, 0, 1, 0, 0, 0, 0);

    return ht;
}

Color *RenderSystem::init_color()
{
    c = new Color();
    return c;
}

ClippingSpace *RenderSystem::init_clipping()
{
    cs = new ClippingSpace();
    return cs;
}

Vectors* RenderSystem::init_vector()
{
    v = new Vectors();
    return v;
}


CameraModel* RenderSystem::create_matrices()
{

    // Create camera to world matrix
    cm->V_T_C = ht->createHomogeneousTransformationMatrix(
        (mParameterModel.getCameraSystemTranslationX - 10000) / 1000.0,
        (mParameterModel.getCameraSystemTranslationY - 10000) / 1000.0,
        (mParameterModel.getCameraSystemTranslationZ - 10000) / 1000.0,
        DEG_TO_RAD(mParameterModel.getCameraSystemRotationRoll / 10.0),
        DEG_TO_RAD(mParameterModel.getCameraSystemRotationPitch / 10.0),
        DEG_TO_RAD(mParameterModel.getCameraSystemRotationYaw / 10.0),
        1.0f);

    // Compute inverse (world to camera matrix)
    cm->C_T_V = cm->V_T_C.inv();

    // Create cube to world matrix
    cm->V_T_Cube = ht->createHomogeneousTransformationMatrix(
        (mParameterModel.getCubeSystemTranslationX - 10000) / 1000.0,
        (mParameterModel.getCubeSystemTranslationY - 10000) / 1000.0,
        (mParameterModel.getCubeSystemTranslationZ - 10000) / 1000.0,
        DEG_TO_RAD(mParameterModel.getCubeSystemRotationRoll / 10.0),
        DEG_TO_RAD(mParameterModel.getCubeSystemRotationPitch / 10.0),
        DEG_TO_RAD(mParameterModel.getCubeSystemRotationYaw / 10.0),
        mParameterModel.getCubeSystemScale);

    return cm;

}

Shape* RenderSystem::createCube() {

    Shape* sp = new Shape();
    return sp;

}

CameraModel* RenderSystem::createCamera(  double sensorWidth,
                                            double sensorHeight,
                                            double focalLength,
                                            uint32_t resolutionX,
                                            uint32_t resolutionY,
                                            uint32_t u0,
                                            uint32_t v0) 
{

    cm = new CameraModel(sensorWidth, sensorHeight, focalLength, resolutionX, resolutionY, u0, v0);

    renderFrame();

    return cm;

}


FpsCounter* RenderSystem::update_fps()
{
    fc->update();
    std::string fps_text = "FPS: " + std::to_string(static_cast<int>(fc->get_fps_filtered()));
    cv::putText(cm->getCameraImage(), fps_text, cv::Point(10, 30), cv::FONT_HERSHEY_SIMPLEX, 1, cv::Scalar(0, 255, 0), 2);

    return fc;
}


cv::Mat RenderSystem::renderFrame() {
    return cm->getCameraImage();
}

void RenderSystem::shutdown() {
    std::cout << "Shutting down Graphics Engine" << std::endl;
    delete cm;
    delete ht;
    delete cs;
    delete v;
    delete c;
    delete fc;
}
