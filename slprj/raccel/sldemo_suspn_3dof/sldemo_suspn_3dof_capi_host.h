#include "__cf_sldemo_suspn_3dof.h"
#ifndef RTW_HEADER_sldemo_suspn_3dof_cap_host_h_
#define RTW_HEADER_sldemo_suspn_3dof_cap_host_h_
#ifdef HOST_CAPI_BUILD
#include "rtw_capi.h"
#include "rtw_modelmap.h"
typedef struct { rtwCAPI_ModelMappingInfo mmi ; }
sldemo_suspn_3dof_host_DataMapInfo_T ;
#ifdef __cplusplus
extern "C" {
#endif
void sldemo_suspn_3dof_host_InitializeDataMapInfo (
sldemo_suspn_3dof_host_DataMapInfo_T * dataMap , const char * path ) ;
#ifdef __cplusplus
}
#endif
#endif
#endif
