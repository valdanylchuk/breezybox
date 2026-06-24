# BreezyBox demo for the Tanmatsu cyberdeck (ESP32-P4)
cmake_minimum_required(VERSION 3.16)

# Pull in the local breezybox component (repo root is two levels up),
# same trick the other breezybox examples use for in-tree development.
# When installed from the component registry instead, drop this line and add
# valdanylchuk/breezybox to main/idf_component.yml.
set(EXTRA_COMPONENT_DIRS "../..")

include($ENV{IDF_PATH}/tools/cmake/project.cmake)
project(breezy_tanmatsu)
