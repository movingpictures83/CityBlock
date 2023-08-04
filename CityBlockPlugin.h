#ifndef CITYBLOCKPLUGIN_H
#define CITYBLOCKPLUGIN_H

#include "Plugin.h"
#include "PluginProxy.h"
#include <string>
#include <vector>

class CityBlockPlugin : public Plugin
{
public: 
 std::string toString() {return "CityBlock";}
 void input(std::string file);
 void run();
 void output(std::string file);

private: 
 std::string inputfile;
 std::string outputfile;

};

#endif
