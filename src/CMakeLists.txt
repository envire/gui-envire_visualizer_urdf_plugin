rock_library(envire_visualizer_urdf_plugin
    SOURCES
    EnvireUrdfVisualizer.cpp
    HEADERS
    EnvireUrdfVisualizer.h
    DEPS_PKGCONFIG osgVizPlugin
    DEPS_PKGCONFIG envire_core
    DEPS_PLAIN envire_visualizer)

