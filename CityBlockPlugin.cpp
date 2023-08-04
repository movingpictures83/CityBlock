#include "PluginManager.h"
#include <stdio.h>
#include <stdlib.h>
#include "CityBlockPlugin.h"

void CityBlockPlugin::input(std::string file) {
 inputfile = file;
}

void CityBlockPlugin::run() {

}

void CityBlockPlugin::output(std::string file) {
   std::string command = "export OLDPATH=${PATH}; ";
   command += "export PATH=${CONDA_HOME}/bin/:${PATH}; ";
   command += "eval \"$(conda shell.bash hook)\"; ";
   command += "conda activate qiime2-2021.4; ";
   command += "qiime diversity beta --i-table "+inputfile+" --p-metric cityblock --o-distance-matrix "+file+"; unzip -jo "+file+" -d "+PluginManager::prefix()+"; ";
   command += "conda deactivate; ";
   command += "export PATH=${OLDPATH}";
 std::cout << command << std::endl;

 system(command.c_str());
}

PluginProxy<CityBlockPlugin> CityBlockPluginProxy = PluginProxy<CityBlockPlugin>("CityBlock", PluginManager::getInstance());
