SHELL := /bin/bash

.DEFAULT_GOAL := help

include .env

.PHONY: help
help: ## Display this help
	@awk 'BEGIN {FS = ":.*?## "} /^[a-zA-Z0-9_-]+:.*?## / {printf "\033[36m%-30s\033[0m %s\n", $$1, $$2}' $(MAKEFILE_LIST)


.PHONY: build
build: ## Build the docker image for raspberry-pi OR PC (include RPi packages, e.g. GPIO)
	docker-compose build qt5-cpp-image

.PHONY: shell
shell:  ## Run shell inside a raspberry-pi container
	docker-compose run --rm qt5-cpp-image /bin/bash

.PHONY: compile-with-cmake
compile-with-cmake: ## Cross compile the qt application with cmake natively
	cmake -B build
	VERBOSE=1 cmake --build build -j8

.PHONY: compile-with-docker
compile-with-docker: ## Cross compile the firmware
	docker compose run compile-gui-application

.PHONY: run-with-docker
run-with-docker: compile-with-docker ## Cross compile the firmware
	xhost +
	docker compose run run-gui-application

