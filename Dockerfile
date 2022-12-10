# Author: Dr. Konstantin Selyunin
# Date: 1 June 2021
# Version: v0.2

# start from official ubuntu image
FROM ubuntu:latest as base-image

ARG DEBIAN_FRONTEND=noninteractive

ARG QT_VERSION=5.15.2

ENV LD_LIBRARY_PATH=/opt/Qt/${QT_VERSION}/gcc_64/lib/

RUN mkdir -p /opt/Qt/

RUN apt-get update && apt-get install \
    file \
    fontconfig \
    libdbus-1-3 \
    libfontconfig1-dev \
    libglu1-mesa-dev \
    libxcb-icccm4 \
    libxcb-image0 \
    libxcb-keysyms1 \
    libxcb-render-util0 \
    libxcb-shape0 \
    libxcb-xinerama0 \
    libxkbcommon-x11-dev \
    mesa-common-dev \
    python3-pip \
    -y

RUN pip install -U cmake aqtinstall

RUN aqt install --outputdir /opt/Qt ${QT_VERSION} linux desktop -m qtcharts

FROM base-image as qt5-cpp-image