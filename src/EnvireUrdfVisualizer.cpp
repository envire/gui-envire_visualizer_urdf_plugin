#include "EnvireUrdfVisualizer.h"
#include <iostream>
#include <typeinfo>
#include <envire_core/items/Item.hpp>
//OSGVIZ_PLUGIN(EnvireUrdfVisualizer);

namespace envire { namespace visualizer {
  
OSGVIZ_PLUGIN(EnvireUrdfVisualizer);

EnvireUrdfVisualizer::EnvireUrdfVisualizer(lib_manager::LibManager* pManager) :
  EnvireVizPlugin(pManager)
{
  supportedTypes.emplace_back(typeid(envire::core::Item<std::string>));
}
  
osg::ref_ptr<osgviz::Object> EnvireUrdfVisualizer::createItemVisualization(const std::type_index& type, const core::ItemBase::Ptr item)
{
  std::cout << "CREATE" << std::endl;
  return osg::ref_ptr<osgviz::Object>(nullptr);
}

const std::vector<std::type_index>& EnvireUrdfVisualizer::getSupportedTypes()
{
  std::cout << "GET" << std::endl;
  return supportedTypes;
}

const std::string EnvireUrdfVisualizer::getLibName() const
{
  return "envire_visualizer_urdf_plugin";
}

int EnvireUrdfVisualizer::getLibVersion() const
{
  return 0;
}


  
}}