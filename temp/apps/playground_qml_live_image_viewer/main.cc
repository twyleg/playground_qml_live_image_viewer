// Copyright (C) 2024 twyleg
#include <playground_qml_live_image_viewer/ui/ui.h>
#include <playground_qml_live_image_viewer/ui/model.h>
#include <playground_qml_live_image_viewer/core/image_processing.h>

int main(int argc, char *argv[]) {

	Q_INIT_RESOURCE(ui);

	playground_qml_live_image_viewer::ui::UI ui(argc, argv);

	auto& imageModel = ui.getImageModel();
	auto& parameterModel = ui.getParameterModel();

	playground_qml_live_image_viewer::core::ImageProcessing imageProcessing(imageModel, parameterModel);


	imageProcessing.start();
    return ui.run();
}
