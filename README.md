# QT Charts Cmake app

Qt Charts app with `cmake` as build system for `linux` / `windows`.

The `app` uses Qt 5.15.2 and [Qt Charts](https://doc.qt.io/qt-5/qtcharts-index.html).

The `POST-BUILD` and `install` parts create a portable bundle with executable 
and libraries in a deployment folder (available currently for `linux` only). 
The portability of course is limited to the system where it is built (in this case `ubuntu`).

Building on windows with `cmake` (Qt should be installed) is also supported,
tested on `win10`. Installation bundle does not work on windows, although
the directory with the compiled executable is portable and can be used as is.

# Docker

The [`Dockerfile`](./Dockerfile) is used to build the CI docker image.

Create image from the `Dockerfile`: 
```
make build
```

Create the container with shared volumes and start the bash shell:
```
make shell
```

Start the GUI app from a docker container:
```
make run-with-docker
```


## Qt plugins output

In order to see the output of the plugins, run:
```
export QT_DEBUG_PLUGINS=1
```


## Maintainer

[Dr. Konstantin Selyunin](http://selyunin.com/), for
suggestions / questions / comments please contact: selyunin [dot] k [dot] v [at] gmail [dot] com