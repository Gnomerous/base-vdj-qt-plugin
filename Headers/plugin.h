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
        static void *startGuiThread(void*);

};

struct InputArgs {
    int argc;
    char **argv;
    Plugin *vdjPlugin;
};

#endif // PLUGIN_H
