[![Build status](https://github.com/twyleg/playground_qml_live_image_viewer/actions/workflows/unit_tests.yaml/badge.svg)]()
[![GitHub latest commit](https://badgen.net/github/last-commit/twyleg/playground_qml_live_image_viewer)](https://GitHub.com/twyleg/playground_qml_live_image_viewer/commit/)

# playground_qml_live_image_viewer

Simple CMake based template for a common C++ project.

## Dependencies

The template is based on the following components:

* CMake
* boost
* googletest
* fmt

See [scripts/](https://github.com/twyleg/playground_qml_live_image_viewer/tree/master/scripts) for dependency install scripts for multiple distributions.

GoogleTest is pulled in as a git submodule to avoid problems with missing cmake files in sub distributions.

## Usage

Clone, prepare and build with the following steps:

	git clone git@github.com:twyleg/playground_qml_live_image_viewer.git
	cd playground_qml_live_image_viewer

	git submodule update --init
	
	mkdir build/
	cd build/
	cmake ../
	make

