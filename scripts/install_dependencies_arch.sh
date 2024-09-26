#!/bin/bash

if [ "$(id -u)" -ne 0 ]; then
	echo "Please run as root"
	exit -1
fi

pacman -Suy --noconfirm \
	make \
	cmake \
	gcc \
	fmt \
	boost \
        boost-libs \
        qt6-3d \
        qt6-5compat \
        qt6-base \
        qt6-charts \
        qt6-connectivity \
        qt6-datavis3d \
        qt6-declarative \
        qt6-doc \
        qt6-examples \
        qt6-graphs \
        qt6-grpc \
        qt6-httpserver \
        qt6-imageformats \
        qt6-languageserver \
        qt6-location \
        qt6-lottie \
        qt6-multimedia \
        qt6-multimedia-ffmpeg \
        qt6-multimedia-gstreamer \
        qt6-networkauth \
        qt6-positioning \
        qt6-quick3d \
        qt6-quick3dphysics \
        qt6-quickeffectmaker \
        qt6-quicktimeline \
        qt6-remoteobjects \
        qt6-scxml \
        qt6-sensors \
        qt6-serialbus \
        qt6-serialport \
        qt6-shadertools \
        qt6-speech \
        qt6-svg \
        qt6-tools \
        qt6-translations \
        qt6-virtualkeyboard \
        qt6-wayland \
        qt6-webchannel \
        qt6-webengine \
        qt6-websockets \
        qt6-webview \
        qt6-xcb-private-headers \
        opencv \
        vtk \
        hdf5 \
        glew
