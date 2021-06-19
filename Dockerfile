# Author: Dr. Konstantin Selyunin
# Date: 1 June 2021
# Version: v0.2

# start from official ubuntu image
FROM ubuntu
ARG DEBIAN_FRONTEND=noninteractive
ARG QT_VERSION=5.15.2
ENV LD_LIBRARY_PATH=/opt/Qt/${QT_VERSION}/gcc_64/lib/
RUN mkdir -p /opt/Qt/
RUN apt-get update && apt-get install python3-pip \
                                      mesa-common-dev \
                                      libglu1-mesa-dev \
                                      libxkbcommon-x11-dev \
                                      libfontconfig1-dev \
                                      libxcb-xinerama0 \
                                      fontconfig \
                                      file \
                                      -y
RUN pip install -U cmake aqtinstall
RUN aqt install --outputdir /opt/Qt ${QT_VERSION} linux desktop -m qtcharts
WORKDIR /code
