#include "sldemo_suspn_3dof_capi_host.h"
static sldemo_suspn_3dof_host_DataMapInfo_T root;
static int initialized = 0;
__declspec( dllexport ) rtwCAPI_ModelMappingInfo *getRootMappingInfo()
{
    if (initialized == 0) {
        initialized = 1;
        sldemo_suspn_3dof_host_InitializeDataMapInfo(&(root), "sldemo_suspn_3dof");
    }
    return &root.mmi;
}

rtwCAPI_ModelMappingInfo *mexFunction() {return(getRootMappingInfo());}
