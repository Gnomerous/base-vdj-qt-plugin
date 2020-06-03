#include "plugin.h"

using namespace std;

// Thread for the Bop Selector GUI
pthread_t guiThread;

// Used to create the DLLObject for VDJ that we can use to interact with VDJ
VDJ_EXPORT HRESULT VDJ_API DllGetClassObject(const GUID &rclsid,const GUID &riid,void** ppObject) {

    // Make sure everything is good before we create the object for the plugin
    if (memcmp(&rclsid, &CLSID_VdjPlugin8, sizeof(GUID)) == 0 && memcmp(&riid, &IID_IVdjPluginBasic8, sizeof(GUID)) == 0) {
        // Create a new Plugin for VDJ to interact with
        *ppObject = new Plugin();
    }

    else {
        // Whoops... something went wrong!
        return CLASS_E_CLASSNOTAVAILABLE;
    }

    // EZ PZ
    return NO_ERROR;
}

// Whenever the Plugin Loads in VDJ, this will run...
HRESULT VDJ_API Plugin::OnLoad(){

    // Create our own argv and argc
    char *argv[] = {(char *)"Bop Selector", NULL};
    int argc = sizeof(argv) / sizeof(char*) - 1;

    InputArgs *args;
    args = (InputArgs *)malloc(sizeof(InputArgs));
    args->argc = argc;
    args->argv = argv;
    args->vdjPlugin = this;

    // Create the GUI thread
    pthread_create(&guiThread, NULL, Plugin::startGuiThread, (void *) args);

    // Return Okay because we're done
    return S_OK;
}

// Whenever VDJ requests the PluginInfo, this will run...
HRESULT VDJ_API Plugin::OnGetPluginInfo(TVdjPluginInfo8 *infos) {

    // Set the appropriate info
    infos->PluginName = "Bop Selector (VDJ)";
    infos->Author = "Gn0mer0us";
    infos->Description = "VDJ Plugin for interactive DJ streams!";
    infos->Version = "1.0";
    infos->Flags = 0x00;
    infos->Bitmap = NULL;

    // Return that we're okay and ther are no issues
    return S_OK;
}

// This won't be used
HRESULT VDJ_API Plugin::OnParameter(int id) {
    // Just return that everything is Okay
    return S_OK;
}

// This won't be used
HRESULT VDJ_API Plugin::OnGetParameterString(int id, char *outParam, int outParamSize) {
    // Just return that everything is Okay
    return S_OK;
}

// This will be used to deconstruct our plugin once VDJ is ready to shutdown...
ULONG VDJ_API Plugin::Release() {
    delete this;
    return 0;
}

void *Plugin::startGuiThread(void* args) {

    // Get the Input Arguments
    InputArgs *input;
    input=(InputArgs *)args;

    // Startup the GUI
    QApplication a(input->argc, input->argv);
    MainWindow w(nullptr, input->vdjPlugin);
    w.show();
    a.exec();

    return NULL;
}

Plugin::~Plugin() {
    pthread_join(guiThread, NULL);
}
