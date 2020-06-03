#ifndef PLUGIN_H
#define PLUGIN_H

// Local Includes
#include "vdj8Plugin.h"
#include "mainwindow.h"

// External Includes
#include <string>
#include <queue>
#include <iostream>
#include <fstream>
#include <list>
#include <QApplication>
#include <pthread.h>

using namespace std;

// Because we will be including the mainwindow.h file, need to state this to prevent
// the circular dependency issue
class MainWindow;

class Plugin : public IVdjPlugin8 {

    public:
        ~Plugin();
        HRESULT VDJ_API OnLoad();
        HRESULT VDJ_API OnGetPluginInfo(TVdjPluginInfo8 *infos);
        HRESULT VDJ_API OnParameter(int id);
        HRESULT VDJ_API OnGetParameterString(int id, char *outParam, int outParamSize);
        ULONG VDJ_API Release();
    private:
    
        // This will be used to launch the plugin's GUI in a separate thread so VDJ can
        // still launch and be used
        static void *startGuiThread(void*);

};

// This will be used when launching another thread for the plugin's GUI
struct InputArgs {
    int argc;
    char **argv;
    Plugin *vdjPlugin;
};

#endif // PLUGIN_H
