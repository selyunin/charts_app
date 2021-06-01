# QT Charts Cmake app

Qt Charts app with `cmake` as build system for `linux` / `windows`.

The `app` uses Qt 5.15.2 and [Qt Charts](https://doc.qt.io/qt-5/qtcharts-index.html).

The `POST-BUILD` and `install` parts create a portable bundle with executable 
and libraries in a deployment folder (available currently for `linux` only). 
The portability of course is limited to the system where it is built (in this case `ubuntu`).

Building on windows with `cmake` (Qt should be installed) is also supported,
tested on `win10`. Installation bundle does not work on windows, although
the directory with the compiled executable is portable and can be used as is.

# Docker CI 

The [`Dockerfile`](./Dockerfile) is used to build the CI docker image.

Create image from the `Dockerfile`: 
```
docker build -t qt_image .
```

Create the container with shared volumes:
```
docker create -t -i -v /host/directory:/container/directory qt_image bash
```

Start the container:
```
docker start -a -i **container_hash_from_previous_step**
```


## Maintainer

[Dr. Konstantin Selyunin](http://selyunin.com/), for
suggestions / questions / comments please contact: selyunin [dot] k [dot] v [at] gmail [dot] com