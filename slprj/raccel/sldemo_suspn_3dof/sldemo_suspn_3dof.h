#include "__cf_sldemo_suspn_3dof.h"
#ifndef RTW_HEADER_sldemo_suspn_3dof_h_
#define RTW_HEADER_sldemo_suspn_3dof_h_
#include <stddef.h>
#include <float.h>
#include <string.h>
#include "rtw_modelmap.h"
#ifndef sldemo_suspn_3dof_COMMON_INCLUDES_
#define sldemo_suspn_3dof_COMMON_INCLUDES_
#include <stdlib.h>
#include "rtwtypes.h"
#include "sigstream_rtw.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "raccel.h"
#include "rt_logging.h"
#include "dt_info.h"
#include "ext_work.h"
#endif
#include "sldemo_suspn_3dof_types.h"
#include "multiword_types.h"
#include "mwmathutil.h"
#include "rt_defines.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"
#define MODEL_NAME sldemo_suspn_3dof
#define NSAMPLE_TIMES (2) 
#define NINPUTS (0)       
#define NOUTPUTS (0)     
#define NBLOCKIO (8) 
#define NUM_ZC_EVENTS (0) 
#ifndef NCSTATES
#define NCSTATES (6)   
#elif NCSTATES != 6
#error Invalid specification of NCSTATES defined in compiler command
#endif
#ifndef rtmGetDataMapInfo
#define rtmGetDataMapInfo(rtm) (*rt_dataMapInfoPtr)
#endif
#ifndef rtmSetDataMapInfo
#define rtmSetDataMapInfo(rtm, val) (rt_dataMapInfoPtr = &val)
#endif
#ifndef IN_RACCEL_MAIN
#endif
typedef struct { real_T kf3x2lfbm2 ; real_T athg3b0cpi [ 2 ] ; real_T
iwrzxexy4o ; real_T m2js5kfkdp ; real_T k5fo1npzjc ; real_T nh0ippmp3i ;
real_T mutpjnrc5z ; real_T ipdxefuu4f ; } B ; typedef struct { struct {
real_T modelTStart ; } npwmhg4hk3 ; struct { real_T modelTStart ; }
hr4o3k3rqn ; struct { void * SignalProbe ; } hu2pioagaa ; struct { void *
LoggedData ; } mvyeftsaxy ; struct { void * TimePtr ; void * DataPtr ; void *
RSimInfoPtr ; } jql45x2viu ; struct { void * TUbufferPtrs [ 2 ] ; }
borxbvmdf3 ; struct { void * TUbufferPtrs [ 2 ] ; } jwb3e3k5si ; int_T
e15wz5f0je [ 1023 ] ; int_T n4oo1gwbci ; struct { int_T PrevIndex ; }
g4xb0secad ; struct { int_T Tail ; int_T Head ; int_T Last ; int_T
CircularBufSize ; int_T MaxNewBufSize ; } i0jyyo5z4h ; struct { int_T Tail ;
int_T Head ; int_T Last ; int_T CircularBufSize ; int_T MaxNewBufSize ; }
e03x3yx1t1 ; } DW ; typedef struct { real_T jrfptyy1yx ; real_T mafixvydzh ;
real_T htcumeq1zs ; real_T f5csqhdetv ; real_T b1r5fw2cl1 ; real_T ovyxqe4p1r
; } X ; typedef struct { real_T jrfptyy1yx ; real_T mafixvydzh ; real_T
htcumeq1zs ; real_T f5csqhdetv ; real_T b1r5fw2cl1 ; real_T ovyxqe4p1r ; }
XDot ; typedef struct { boolean_T jrfptyy1yx ; boolean_T mafixvydzh ;
boolean_T htcumeq1zs ; boolean_T f5csqhdetv ; boolean_T b1r5fw2cl1 ;
boolean_T ovyxqe4p1r ; } XDis ; typedef struct { real_T jrfptyy1yx ; real_T
mafixvydzh ; real_T htcumeq1zs ; real_T f5csqhdetv ; real_T b1r5fw2cl1 ;
real_T ovyxqe4p1r ; } CStateAbsTol ; typedef struct { real_T mmci4w45az ; }
ZCV ; typedef struct { rtwCAPI_ModelMappingInfo mmi ; } DataMapInfo ; struct
P_ { real_T Ixx ; real_T Iyy ; real_T Kf ; real_T Kr ; real_T L ; real_T Mb ;
real_T W ; real_T g ; real_T Z_IC ; real_T THETA_IC ; real_T PHI_IC ; real_T
FromWs_Time0 [ 2046 ] ; real_T FromWs_Data0 [ 4092 ] ; real_T stiffness_Gain
; real_T THETAdot_IC ; real_T PHIdot_IC ; real_T Zdot_IC ; real_T
damping_Gain ; real_T TransportDelay_Delay ; real_T TransportDelay_InitOutput
; real_T stiffness_Gain_ejfmxf0ubt ; real_T damping_Gain_jmhajh5utx ; real_T
stiffness_Gain_oi4325ilzi ; real_T damping_Gain_kormbqmmae ; real_T
TransportDelay1_Delay ; real_T TransportDelay1_InitOutput ; real_T
stiffness_Gain_dkutidbsbf ; real_T damping_Gain_otuxh5svgn ; } ; extern const
char * RT_MEMORY_ALLOCATION_ERROR ; extern B rtB ; extern X rtX ; extern DW
rtDW ; extern P rtP ; extern const rtwCAPI_ModelMappingStaticInfo *
sldemo_suspn_3dof_GetCAPIStaticMap ( void ) ; extern SimStruct * const rtS ;
extern const int_T gblNumToFiles ; extern const int_T gblNumFrFiles ; extern
const int_T gblNumFrWksBlocks ; extern rtInportTUtable * gblInportTUtables ;
extern const char * gblInportFileName ; extern const int_T
gblNumRootInportBlks ; extern const int_T gblNumModelInputs ; extern const
int_T gblInportDataTypeIdx [ ] ; extern const int_T gblInportDims [ ] ;
extern const int_T gblInportComplex [ ] ; extern const int_T
gblInportInterpoFlag [ ] ; extern const int_T gblInportContinuous [ ] ;
extern const int_T gblParameterTuningTid ; extern DataMapInfo *
rt_dataMapInfoPtr ; extern rtwCAPI_ModelMappingInfo * rt_modelMapInfoPtr ;
void MdlOutputs ( int_T tid ) ; void MdlOutputsParameterSampleTime ( int_T
tid ) ; void MdlUpdate ( int_T tid ) ; void MdlTerminate ( void ) ; void
MdlInitializeSizes ( void ) ; void MdlInitializeSampleTimes ( void ) ;
SimStruct * raccel_register_model ( void ) ;
#endif
