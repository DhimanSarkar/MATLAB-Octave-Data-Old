#include "__cf_sldemo_suspn_3dof.h"
#include "rtw_capi.h"
#ifdef HOST_CAPI_BUILD
#include "sldemo_suspn_3dof_capi_host.h"
#define sizeof(s) ((size_t)(0xFFFF))
#undef rt_offsetof
#define rt_offsetof(s,el) ((uint16_T)(0xFFFF))
#define TARGET_CONST
#define TARGET_STRING(s) (s)    
#else
#include "builtin_typeid_types.h"
#include "sldemo_suspn_3dof.h"
#include "sldemo_suspn_3dof_capi.h"
#include "sldemo_suspn_3dof_private.h"
#ifdef LIGHT_WEIGHT_CAPI
#define TARGET_CONST                  
#define TARGET_STRING(s)               (NULL)                    
#else
#define TARGET_CONST                   const
#define TARGET_STRING(s)               (s)
#endif
#endif
static const rtwCAPI_Signals rtBlockSignals [ ] = { { 0 , 0 , TARGET_STRING (
"sldemo_suspn_3dof/Road Profiles/FromWs" ) , TARGET_STRING ( "" ) , 0 , 0 , 0
, 0 , 0 } , { 1 , 0 , TARGET_STRING (
"sldemo_suspn_3dof/Body Dynamics/Pitch (THETA) dynamics/THETAdot" ) ,
TARGET_STRING ( "Thetadot" ) , 0 , 0 , 1 , 0 , 0 } , { 2 , 0 , TARGET_STRING
( "sldemo_suspn_3dof/Body Dynamics/Pitch (THETA) dynamics/Divide" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 0 } , { 3 , 0 , TARGET_STRING (
"sldemo_suspn_3dof/Body Dynamics/Roll (PHI) dynamics/PHIdot" ) ,
TARGET_STRING ( "Phidot" ) , 0 , 0 , 1 , 0 , 0 } , { 4 , 0 , TARGET_STRING (
"sldemo_suspn_3dof/Body Dynamics/Roll (PHI) dynamics/Divide" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 0 } , { 5 , 0 , TARGET_STRING (
"sldemo_suspn_3dof/Body Dynamics/Vertical (Z) dynamics/Z" ) , TARGET_STRING (
"Z" ) , 0 , 0 , 1 , 0 , 0 } , { 6 , 0 , TARGET_STRING (
"sldemo_suspn_3dof/Body Dynamics/Vertical (Z) dynamics/Zdot" ) ,
TARGET_STRING ( "Zdot" ) , 0 , 0 , 1 , 0 , 0 } , { 7 , 0 , TARGET_STRING (
"sldemo_suspn_3dof/Body Dynamics/Vertical (Z) dynamics/Sum5" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 0 } , { 0 , 0 , ( NULL ) , ( NULL ) ,
0 , 0 , 0 , 0 , 0 } } ; static const rtwCAPI_BlockParameters
rtBlockParameters [ ] = { { 8 , TARGET_STRING (
"sldemo_suspn_3dof/Road Profiles/FromWs" ) , TARGET_STRING ( "Time0" ) , 0 ,
2 , 0 } , { 9 , TARGET_STRING ( "sldemo_suspn_3dof/Road Profiles/FromWs" ) ,
TARGET_STRING ( "Data0" ) , 0 , 3 , 0 } , { 10 , TARGET_STRING (
"sldemo_suspn_3dof/Road-Suspension Interaction/Transport Delay" ) ,
TARGET_STRING ( "DelayTime" ) , 0 , 1 , 0 } , { 11 , TARGET_STRING (
"sldemo_suspn_3dof/Road-Suspension Interaction/Transport Delay" ) ,
TARGET_STRING ( "InitialOutput" ) , 0 , 1 , 0 } , { 12 , TARGET_STRING (
"sldemo_suspn_3dof/Road-Suspension Interaction/Transport Delay1" ) ,
TARGET_STRING ( "DelayTime" ) , 0 , 1 , 0 } , { 13 , TARGET_STRING (
"sldemo_suspn_3dof/Road-Suspension Interaction/Transport Delay1" ) ,
TARGET_STRING ( "InitialOutput" ) , 0 , 1 , 0 } , { 14 , TARGET_STRING (
"sldemo_suspn_3dof/Body Dynamics/Pitch (THETA) dynamics/THETA" ) ,
TARGET_STRING ( "InitialCondition" ) , 0 , 1 , 0 } , { 15 , TARGET_STRING (
"sldemo_suspn_3dof/Body Dynamics/Pitch (THETA) dynamics/THETAdot" ) ,
TARGET_STRING ( "InitialCondition" ) , 0 , 1 , 0 } , { 16 , TARGET_STRING (
"sldemo_suspn_3dof/Body Dynamics/Roll (PHI) dynamics/PHI" ) , TARGET_STRING (
"InitialCondition" ) , 0 , 1 , 0 } , { 17 , TARGET_STRING (
"sldemo_suspn_3dof/Body Dynamics/Roll (PHI) dynamics/PHIdot" ) ,
TARGET_STRING ( "InitialCondition" ) , 0 , 1 , 0 } , { 18 , TARGET_STRING (
"sldemo_suspn_3dof/Body Dynamics/Vertical (Z) dynamics/Z" ) , TARGET_STRING (
"InitialCondition" ) , 0 , 1 , 0 } , { 19 , TARGET_STRING (
"sldemo_suspn_3dof/Body Dynamics/Vertical (Z) dynamics/Zdot" ) ,
TARGET_STRING ( "InitialCondition" ) , 0 , 1 , 0 } , { 20 , TARGET_STRING (
"sldemo_suspn_3dof/Road-Suspension Interaction/Front Left Suspension/damping"
) , TARGET_STRING ( "Gain" ) , 0 , 1 , 0 } , { 21 , TARGET_STRING (
"sldemo_suspn_3dof/Road-Suspension Interaction/Front Left Suspension/stiffness"
) , TARGET_STRING ( "Gain" ) , 0 , 1 , 0 } , { 22 , TARGET_STRING (
"sldemo_suspn_3dof/Road-Suspension Interaction/Front Right Suspension/damping"
) , TARGET_STRING ( "Gain" ) , 0 , 1 , 0 } , { 23 , TARGET_STRING (
"sldemo_suspn_3dof/Road-Suspension Interaction/Front Right Suspension/stiffness"
) , TARGET_STRING ( "Gain" ) , 0 , 1 , 0 } , { 24 , TARGET_STRING (
"sldemo_suspn_3dof/Road-Suspension Interaction/Rear Left Suspension/damping"
) , TARGET_STRING ( "Gain" ) , 0 , 1 , 0 } , { 25 , TARGET_STRING (
"sldemo_suspn_3dof/Road-Suspension Interaction/Rear Left Suspension/stiffness"
) , TARGET_STRING ( "Gain" ) , 0 , 1 , 0 } , { 26 , TARGET_STRING (
"sldemo_suspn_3dof/Road-Suspension Interaction/Rear Right Suspension/damping"
) , TARGET_STRING ( "Gain" ) , 0 , 1 , 0 } , { 27 , TARGET_STRING (
"sldemo_suspn_3dof/Road-Suspension Interaction/Rear Right Suspension/stiffness"
) , TARGET_STRING ( "Gain" ) , 0 , 1 , 0 } , { 0 , ( NULL ) , ( NULL ) , 0 ,
0 , 0 } } ; static const rtwCAPI_ModelParameters rtModelParameters [ ] = { {
28 , TARGET_STRING ( "Ixx" ) , 0 , 1 , 0 } , { 29 , TARGET_STRING ( "Iyy" ) ,
0 , 1 , 0 } , { 30 , TARGET_STRING ( "Kf" ) , 0 , 1 , 0 } , { 31 ,
TARGET_STRING ( "Kr" ) , 0 , 1 , 0 } , { 32 , TARGET_STRING ( "L" ) , 0 , 1 ,
0 } , { 33 , TARGET_STRING ( "Mb" ) , 0 , 1 , 0 } , { 34 , TARGET_STRING (
"W" ) , 0 , 1 , 0 } , { 35 , TARGET_STRING ( "g" ) , 0 , 1 , 0 } , { 0 , (
NULL ) , 0 , 0 , 0 } } ;
#ifndef HOST_CAPI_BUILD
static void * rtDataAddrMap [ ] = { & rtB . athg3b0cpi [ 0 ] , & rtB .
iwrzxexy4o , & rtB . nh0ippmp3i , & rtB . m2js5kfkdp , & rtB . mutpjnrc5z , &
rtB . kf3x2lfbm2 , & rtB . k5fo1npzjc , & rtB . ipdxefuu4f , & rtP .
FromWs_Time0 [ 0 ] , & rtP . FromWs_Data0 [ 0 ] , & rtP .
TransportDelay_Delay , & rtP . TransportDelay_InitOutput , & rtP .
TransportDelay1_Delay , & rtP . TransportDelay1_InitOutput , & rtP . THETA_IC
, & rtP . THETAdot_IC , & rtP . PHI_IC , & rtP . PHIdot_IC , & rtP . Z_IC , &
rtP . Zdot_IC , & rtP . damping_Gain , & rtP . stiffness_Gain , & rtP .
damping_Gain_kormbqmmae , & rtP . stiffness_Gain_oi4325ilzi , & rtP .
damping_Gain_jmhajh5utx , & rtP . stiffness_Gain_ejfmxf0ubt , & rtP .
damping_Gain_otuxh5svgn , & rtP . stiffness_Gain_dkutidbsbf , & rtP . Ixx , &
rtP . Iyy , & rtP . Kf , & rtP . Kr , & rtP . L , & rtP . Mb , & rtP . W , &
rtP . g , } ; static int32_T * rtVarDimsAddrMap [ ] = { ( NULL ) } ;
#endif
static TARGET_CONST rtwCAPI_DataTypeMap rtDataTypeMap [ ] = { { "double" ,
"real_T" , 0 , 0 , sizeof ( real_T ) , SS_DOUBLE , 0 , 0 } } ;
#ifdef HOST_CAPI_BUILD
#undef sizeof
#endif
static TARGET_CONST rtwCAPI_ElementMap rtElementMap [ ] = { { ( NULL ) , 0 ,
0 , 0 , 0 } , } ; static const rtwCAPI_DimensionMap rtDimensionMap [ ] = { {
rtwCAPI_VECTOR , 0 , 2 , 0 } , { rtwCAPI_SCALAR , 2 , 2 , 0 } , {
rtwCAPI_VECTOR , 4 , 2 , 0 } , { rtwCAPI_VECTOR , 6 , 2 , 0 } } ; static
const uint_T rtDimensionArray [ ] = { 2 , 1 , 1 , 1 , 2046 , 1 , 4092 , 1 } ;
static const real_T rtcapiStoredFloats [ ] = { 0.0 } ; static const
rtwCAPI_FixPtMap rtFixPtMap [ ] = { { ( NULL ) , ( NULL ) ,
rtwCAPI_FIX_RESERVED , 0 , 0 , 0 } , } ; static const rtwCAPI_SampleTimeMap
rtSampleTimeMap [ ] = { { ( const void * ) & rtcapiStoredFloats [ 0 ] , (
const void * ) & rtcapiStoredFloats [ 0 ] , 0 , 0 } } ; static
rtwCAPI_ModelMappingStaticInfo mmiStatic = { { rtBlockSignals , 8 , ( NULL )
, 0 , ( NULL ) , 0 } , { rtBlockParameters , 20 , rtModelParameters , 8 } , {
( NULL ) , 0 } , { rtDataTypeMap , rtDimensionMap , rtFixPtMap , rtElementMap
, rtSampleTimeMap , rtDimensionArray } , "float" , { 2766936934U ,
2617085270U , 296463808U , 1505035899U } , ( NULL ) , 0 , 0 } ; const
rtwCAPI_ModelMappingStaticInfo * sldemo_suspn_3dof_GetCAPIStaticMap ( ) {
return & mmiStatic ; }
#ifndef HOST_CAPI_BUILD
void sldemo_suspn_3dof_InitializeDataMapInfo ( SimStruct * const rtS ) {
rtwCAPI_SetVersion ( ( * rt_dataMapInfoPtr ) . mmi , 1 ) ;
rtwCAPI_SetStaticMap ( ( * rt_dataMapInfoPtr ) . mmi , & mmiStatic ) ;
rtwCAPI_SetLoggingStaticMap ( ( * rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ;
rtwCAPI_SetDataAddressMap ( ( * rt_dataMapInfoPtr ) . mmi , rtDataAddrMap ) ;
rtwCAPI_SetVarDimsAddressMap ( ( * rt_dataMapInfoPtr ) . mmi ,
rtVarDimsAddrMap ) ; rtwCAPI_SetInstanceLoggingInfo ( ( * rt_dataMapInfoPtr )
. mmi , ( NULL ) ) ; rtwCAPI_SetChildMMIArray ( ( * rt_dataMapInfoPtr ) . mmi
, ( NULL ) ) ; rtwCAPI_SetChildMMIArrayLen ( ( * rt_dataMapInfoPtr ) . mmi ,
0 ) ; }
#else
#ifdef __cplusplus
extern "C" {
#endif
void sldemo_suspn_3dof_host_InitializeDataMapInfo (
sldemo_suspn_3dof_host_DataMapInfo_T * dataMap , const char * path ) {
rtwCAPI_SetVersion ( dataMap -> mmi , 1 ) ; rtwCAPI_SetStaticMap ( dataMap ->
mmi , & mmiStatic ) ; rtwCAPI_SetDataAddressMap ( dataMap -> mmi , NULL ) ;
rtwCAPI_SetVarDimsAddressMap ( dataMap -> mmi , NULL ) ; rtwCAPI_SetPath (
dataMap -> mmi , path ) ; rtwCAPI_SetFullPath ( dataMap -> mmi , NULL ) ;
rtwCAPI_SetChildMMIArray ( dataMap -> mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArrayLen ( dataMap -> mmi , 0 ) ; }
#ifdef __cplusplus
}
#endif
#endif
