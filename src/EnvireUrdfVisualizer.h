#pragma once
#include <envire_visualizer/EnvireVizPlugin.h>

namespace envire { namespace visualizer {
  
class EnvireUrdfVisualizer : public EnvireVizPlugin
{
public:
  
  EnvireUrdfVisualizer(lib_manager::LibManager* pManager);
  virtual osg::ref_ptr<osgviz::Object> createItemVisualization(const std::type_index& type,
                                                               const envire::core::ItemBase::Ptr item) override;
    
  virtual const std::vector<std::type_index>& getSupportedTypes() override;
  
  
  virtual int getLibVersion() const override;
  virtual const std::string getLibName() const override;
  
private:
  std::vector<std::type_index> supportedTypes;
  
};

}}