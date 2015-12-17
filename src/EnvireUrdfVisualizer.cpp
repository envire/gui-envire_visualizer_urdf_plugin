#include "EnvireUrdfVisualizer.h"
#include <iostream>
#include <typeinfo>
#include <envire_core/items/Item.hpp>
#include <osg/Shape>
#include <osg/ShapeDrawable>

namespace envire { namespace visualizer {
  
OSGVIZ_PLUGIN(EnvireUrdfVisualizer);

EnvireUrdfVisualizer::EnvireUrdfVisualizer(lib_manager::LibManager* pManager) :
  EnvireVizPlugin(pManager)
{
  supportedTypes.emplace_back(typeid(envire::core::StringItem::Ptr));
}
  
osg::ref_ptr<osgviz::Object> EnvireUrdfVisualizer::createItemVisualization(const std::type_index& type, const core::ItemBase::Ptr item)
{
  osg::ref_ptr<osg::Geode> geode = new osg::Geode();

  float coneheight = 0.3;
  float coneoffset = -0.07; //whyever the center po is not really the center
  float coneposz =  -(coneheight/2.0)+coneoffset;

  osg::ref_ptr<osg::Cone> cone = new osg::Cone(osg::Vec3(0,0,coneposz),0.1,coneheight);

  float arrowheight = 1;
  float cylinderheight=arrowheight-coneheight;
  float cylinderposz=-arrowheight/2.0  - coneheight/2.0;

  osg::ref_ptr<osg::Cylinder> cylinder = new osg::Cylinder(osg::Vec3(0,0,cylinderposz),0.05,cylinderheight);


  osg::ref_ptr<osg::ShapeDrawable> coneDrawable = new osg::ShapeDrawable(cone);
  osg::ref_ptr<osg::ShapeDrawable> cylinderDrawable = new osg::ShapeDrawable(cylinder);

  geode->addDrawable(coneDrawable);
  geode->addDrawable(cylinderDrawable);
  osg::ref_ptr<osgviz::Object> o(new osgviz::Object());
  o->addChild(geode);
  return o;
}

const std::vector<std::type_index>& EnvireUrdfVisualizer::getSupportedTypes()
{ 
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