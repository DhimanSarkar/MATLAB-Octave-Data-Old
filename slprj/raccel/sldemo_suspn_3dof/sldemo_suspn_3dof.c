#include "__cf_sldemo_suspn_3dof.h"
#include "rt_logging_mmi.h"
#include "sldemo_suspn_3dof_capi.h"
#include <math.h>
#include "sldemo_suspn_3dof.h"
#include "sldemo_suspn_3dof_private.h"
#include "sldemo_suspn_3dof_dt.h"
const int_T gblNumToFiles = 0 ; const int_T gblNumFrFiles = 0 ; const int_T
gblNumFrWksBlocks = 1 ;
#ifdef RSIM_WITH_SOLVER_MULTITASKING
boolean_T gbl_raccel_isMultitasking = 1 ;
#else
boolean_T gbl_raccel_isMultitasking = 0 ;
#endif
boolean_T gbl_raccel_tid01eq = 0 ; int_T gbl_raccel_NumST = 2 ; const char_T
* gbl_raccel_Version = "8.11 (R2016b) 25-Aug-2016" ; void
raccel_setup_MMIStateLog ( SimStruct * S ) {
#ifdef UseMMIDataLogging
rt_FillStateSigInfoFromMMI ( ssGetRTWLogInfo ( S ) , & ssGetErrorStatus ( S )
) ;
#endif
} static DataMapInfo rt_dataMapInfo ; DataMapInfo * rt_dataMapInfoPtr = &
rt_dataMapInfo ; rtwCAPI_ModelMappingInfo * rt_modelMapInfoPtr = & (
rt_dataMapInfo . mmi ) ; const char * gblSlvrJacPatternFileName =
"slprj\\raccel\\sldemo_suspn_3dof\\sldemo_suspn_3dof_Jpattern.mat" ; const
int_T gblNumRootInportBlks = 0 ; const int_T gblNumModelInputs = 0 ; extern
rtInportTUtable * gblInportTUtables ; extern const char * gblInportFileName ;
const int_T gblInportDataTypeIdx [ ] = { - 1 } ; const int_T gblInportDims [
] = { - 1 } ; const int_T gblInportComplex [ ] = { - 1 } ; const int_T
gblInportInterpoFlag [ ] = { - 1 } ; const int_T gblInportContinuous [ ] = {
- 1 } ;
#include "simstruc.h"
#include "fixedpoint.h"
B rtB ; X rtX ; DW rtDW ; static SimStruct model_S ; SimStruct * const rtS =
& model_S ;
#ifndef __RTW_UTFREE__  
extern void * utMalloc ( size_t ) ;
#endif
void * rt_TDelayCreateBuf ( int_T numBuffer , int_T bufSz , int_T elemSz ) {
return ( ( void * ) utMalloc ( numBuffer * bufSz * elemSz ) ) ; }
#ifndef __RTW_UTFREE__  
extern void * utMalloc ( size_t ) ; extern void utFree ( void * ) ;
#endif
boolean_T rt_TDelayUpdateTailOrGrowBuf ( int_T * bufSzPtr , int_T * tailPtr ,
int_T * headPtr , int_T * lastPtr , real_T tMinusDelay , real_T * * tBufPtr ,
real_T * * uBufPtr , real_T * * xBufPtr , boolean_T isfixedbuf , boolean_T
istransportdelay , int_T * maxNewBufSzPtr ) { int_T testIdx ; int_T tail = *
tailPtr ; int_T bufSz = * bufSzPtr ; real_T * tBuf = * tBufPtr ; real_T *
xBuf = ( NULL ) ; int_T numBuffer = 2 ; if ( istransportdelay ) { numBuffer =
3 ; xBuf = * xBufPtr ; } testIdx = ( tail < ( bufSz - 1 ) ) ? ( tail + 1 ) :
0 ; if ( ( tMinusDelay <= tBuf [ testIdx ] ) && ! isfixedbuf ) { int_T j ;
real_T * tempT ; real_T * tempU ; real_T * tempX = ( NULL ) ; real_T * uBuf =
* uBufPtr ; int_T newBufSz = bufSz + 1024 ; if ( newBufSz > * maxNewBufSzPtr
) { * maxNewBufSzPtr = newBufSz ; } tempU = ( real_T * ) utMalloc ( numBuffer
* newBufSz * sizeof ( real_T ) ) ; if ( tempU == ( NULL ) ) { return ( false
) ; } tempT = tempU + newBufSz ; if ( istransportdelay ) tempX = tempT +
newBufSz ; for ( j = tail ; j < bufSz ; j ++ ) { tempT [ j - tail ] = tBuf [
j ] ; tempU [ j - tail ] = uBuf [ j ] ; if ( istransportdelay ) tempX [ j -
tail ] = xBuf [ j ] ; } for ( j = 0 ; j < tail ; j ++ ) { tempT [ j + bufSz -
tail ] = tBuf [ j ] ; tempU [ j + bufSz - tail ] = uBuf [ j ] ; if (
istransportdelay ) tempX [ j + bufSz - tail ] = xBuf [ j ] ; } if ( * lastPtr
> tail ) { * lastPtr -= tail ; } else { * lastPtr += ( bufSz - tail ) ; } *
tailPtr = 0 ; * headPtr = bufSz ; utFree ( uBuf ) ; * bufSzPtr = newBufSz ; *
tBufPtr = tempT ; * uBufPtr = tempU ; if ( istransportdelay ) * xBufPtr =
tempX ; } else { * tailPtr = testIdx ; } return ( true ) ; } real_T
rt_TDelayInterpolate ( real_T tMinusDelay , real_T tStart , real_T * tBuf ,
real_T * uBuf , int_T bufSz , int_T * lastIdx , int_T oldestIdx , int_T
newIdx , real_T initOutput , boolean_T discrete , boolean_T
minorStepAndTAtLastMajorOutput ) { int_T i ; real_T yout , t1 , t2 , u1 , u2
; if ( ( newIdx == 0 ) && ( oldestIdx == 0 ) && ( tMinusDelay > tStart ) )
return initOutput ; if ( tMinusDelay <= tStart ) return initOutput ; if ( (
tMinusDelay <= tBuf [ oldestIdx ] ) ) { if ( discrete ) { return ( uBuf [
oldestIdx ] ) ; } else { int_T tempIdx = oldestIdx + 1 ; if ( oldestIdx ==
bufSz - 1 ) tempIdx = 0 ; t1 = tBuf [ oldestIdx ] ; t2 = tBuf [ tempIdx ] ;
u1 = uBuf [ oldestIdx ] ; u2 = uBuf [ tempIdx ] ; if ( t2 == t1 ) { if (
tMinusDelay >= t2 ) { yout = u2 ; } else { yout = u1 ; } } else { real_T f1 =
( t2 - tMinusDelay ) / ( t2 - t1 ) ; real_T f2 = 1.0 - f1 ; yout = f1 * u1 +
f2 * u2 ; } return yout ; } } if ( minorStepAndTAtLastMajorOutput ) { if (
newIdx != 0 ) { if ( * lastIdx == newIdx ) { ( * lastIdx ) -- ; } newIdx -- ;
} else { if ( * lastIdx == newIdx ) { * lastIdx = bufSz - 1 ; } newIdx =
bufSz - 1 ; } } i = * lastIdx ; if ( tBuf [ i ] < tMinusDelay ) { while (
tBuf [ i ] < tMinusDelay ) { if ( i == newIdx ) break ; i = ( i < ( bufSz - 1
) ) ? ( i + 1 ) : 0 ; } } else { while ( tBuf [ i ] >= tMinusDelay ) { i = (
i > 0 ) ? i - 1 : ( bufSz - 1 ) ; } i = ( i < ( bufSz - 1 ) ) ? ( i + 1 ) : 0
; } * lastIdx = i ; if ( discrete ) { double tempEps = ( DBL_EPSILON ) *
128.0 ; double localEps = tempEps * muDoubleScalarAbs ( tBuf [ i ] ) ; if (
tempEps > localEps ) { localEps = tempEps ; } localEps = localEps / 2.0 ; if
( tMinusDelay >= ( tBuf [ i ] - localEps ) ) { yout = uBuf [ i ] ; } else {
if ( i == 0 ) { yout = uBuf [ bufSz - 1 ] ; } else { yout = uBuf [ i - 1 ] ;
} } } else { if ( i == 0 ) { t1 = tBuf [ bufSz - 1 ] ; u1 = uBuf [ bufSz - 1
] ; } else { t1 = tBuf [ i - 1 ] ; u1 = uBuf [ i - 1 ] ; } t2 = tBuf [ i ] ;
u2 = uBuf [ i ] ; if ( t2 == t1 ) { if ( tMinusDelay >= t2 ) { yout = u2 ; }
else { yout = u1 ; } } else { real_T f1 = ( t2 - tMinusDelay ) / ( t2 - t1 )
; real_T f2 = 1.0 - f1 ; yout = f1 * u1 + f2 * u2 ; } } return ( yout ) ; }
#ifndef __RTW_UTFREE__  
extern void utFree ( void * ) ;
#endif
void rt_TDelayFreeBuf ( void * buf ) { utFree ( buf ) ; } void MdlInitialize
( void ) { rtX . jrfptyy1yx = rtP . Z_IC ; rtX . mafixvydzh = rtP . THETA_IC
; rtX . htcumeq1zs = rtP . PHI_IC ; rtX . f5csqhdetv = rtP . THETAdot_IC ;
rtX . b1r5fw2cl1 = rtP . PHIdot_IC ; rtX . ovyxqe4p1r = rtP . Zdot_IC ; }
void MdlStart ( void ) { { void * * pOSigstreamManagerAddr =
rt_GetOSigstreamManagerAddr ( ) ; const char * errorCreatingOSigstreamManager
= rtwOSigstreamManagerCreateInstance ( rt_GetMatSigLogSelectorFileName ( ) ,
pOSigstreamManagerAddr ) ; if ( errorCreatingOSigstreamManager != ( NULL ) )
{ * pOSigstreamManagerAddr = ( NULL ) ; ssSetErrorStatus ( rtS ,
errorCreatingOSigstreamManager ) ; return ; } } if ( rt_GetOSigstreamManager
( ) != ( NULL ) ) { uint_T numForEachLevels = 0 ; { void * pAobHierarchyNode0
= ( NULL ) ; { char * pathToTopModel = "" ; void * pSignalProbeCollection = (
NULL ) ; void * pOSigstreamManager = ( NULL ) ; uint_T signalDimensions0 [ 1
] = { 1 } ; rtwAobHierarchyCreateRootNode ( & pAobHierarchyNode0 ) ;
rtwAobHierarchyVerifyNNodes ( pAobHierarchyNode0 , 1 ) ; pOSigstreamManager =
rt_GetOSigstreamManager ( ) ; rtwSignalProbeCollectionCreateInstance (
"DATASET_SIGNAL_LOGGING" , "tmp_raccel_logsout" , "vertical_disp" , "" ,
pathToTopModel , "sldemo_suspn_3dof/Body Dynamics" , 1 , pOSigstreamManager ,
& pSignalProbeCollection ) ; rtwSignalProbeCollectionAddElement (
pSignalProbeCollection , "" , "linear" , 1 , 0 , 1 , signalDimensions0 , 0 ,
"" , "double" , "" ) ; rtwSignalProbeCollectionVerifyNLeaves (
pSignalProbeCollection , 1 ) ; rtwSignalProbeCollectionSetAobHierarchy (
pSignalProbeCollection , pAobHierarchyNode0 ) ;
rtwSignalProbeCollectionFinalizeMetaData ( pSignalProbeCollection ) ; rtDW .
hu2pioagaa . SignalProbe = pSignalProbeCollection ; } } } { RTWLogSignalInfo
rt_ScopeSignalInfo ; static int_T rt_ScopeSignalWidths [ ] = { 1 } ; static
int_T rt_ScopeSignalNumDimensions [ ] = { 1 } ; static int_T
rt_ScopeSignalDimensions [ ] = { 1 } ; static void * rt_ScopeCurrSigDims [ ]
= { ( NULL ) } ; static int_T rt_ScopeCurrSigDimsSize [ ] = { 4 } ; static
const char_T * rt_ScopeSignalLabels [ ] = { "" } ; static char_T
rt_ScopeSignalTitles [ ] = "" ; static int_T rt_ScopeSignalTitleLengths [ ] =
{ 0 } ; static boolean_T rt_ScopeSignalIsVarDims [ ] = { 0 } ; static int_T
rt_ScopeSignalPlotStyles [ ] = { 0 } ; BuiltInDTypeId dTypes [ 1 ] = {
SS_DOUBLE } ; static char_T rt_ScopeBlockName [ ] = "sldemo_suspn_3dof/Scope"
; static int_T rt_ScopeFrameData [ ] = { 0 } ; rt_ScopeSignalInfo .
numSignals = 1 ; rt_ScopeSignalInfo . numCols = rt_ScopeSignalWidths ;
rt_ScopeSignalInfo . numDims = rt_ScopeSignalNumDimensions ;
rt_ScopeSignalInfo . dims = rt_ScopeSignalDimensions ; rt_ScopeSignalInfo .
isVarDims = rt_ScopeSignalIsVarDims ; rt_ScopeSignalInfo . currSigDims =
rt_ScopeCurrSigDims ; rt_ScopeSignalInfo . currSigDimsSize =
rt_ScopeCurrSigDimsSize ; rt_ScopeSignalInfo . dataTypes = dTypes ;
rt_ScopeSignalInfo . complexSignals = ( NULL ) ; rt_ScopeSignalInfo .
frameData = rt_ScopeFrameData ; rt_ScopeSignalInfo . labels . cptr =
rt_ScopeSignalLabels ; rt_ScopeSignalInfo . titles = rt_ScopeSignalTitles ;
rt_ScopeSignalInfo . titleLengths = rt_ScopeSignalTitleLengths ;
rt_ScopeSignalInfo . plotStyles = rt_ScopeSignalPlotStyles ;
rt_ScopeSignalInfo . blockNames . cptr = ( NULL ) ; rt_ScopeSignalInfo .
stateNames . cptr = ( NULL ) ; rt_ScopeSignalInfo . crossMdlRef = ( NULL ) ;
rt_ScopeSignalInfo . dataTypeConvert = ( NULL ) ; rtDW . mvyeftsaxy .
LoggedData = rt_CreateStructLogVar ( ssGetRTWLogInfo ( rtS ) , ssGetTStart (
rtS ) , ssGetTFinal ( rtS ) , 0.0 , ( & ssGetErrorStatus ( rtS ) ) ,
"ScopeData" , 1 , 0 , 1 , 0.0 , & rt_ScopeSignalInfo , rt_ScopeBlockName ) ;
if ( rtDW . mvyeftsaxy . LoggedData == ( NULL ) ) return ; } { FWksInfo *
fromwksInfo ; if ( ( fromwksInfo = ( FWksInfo * ) calloc ( 1 , sizeof (
FWksInfo ) ) ) == ( NULL ) ) { ssSetErrorStatus ( rtS ,
"from workspace STRING(Name) memory allocation error" ) ; } else {
fromwksInfo -> origWorkspaceVarName = "tuvar" ; fromwksInfo -> origDataTypeId
= 0 ; fromwksInfo -> origIsComplex = 0 ; fromwksInfo -> origWidth = 2 ;
fromwksInfo -> origElSize = sizeof ( real_T ) ; fromwksInfo -> data = ( void
* ) rtP . FromWs_Data0 ; fromwksInfo -> nDataPoints = 2046 ; fromwksInfo ->
time = ( double * ) rtP . FromWs_Time0 ; rtDW . jql45x2viu . TimePtr =
fromwksInfo -> time ; rtDW . jql45x2viu . DataPtr = fromwksInfo -> data ;
rtDW . jql45x2viu . RSimInfoPtr = fromwksInfo ; } rtDW . g4xb0secad .
PrevIndex = 0 ; { int_T * zcTimeIndices = & rtDW . e15wz5f0je [ 0 ] ; const
double * timePoints = ( double * ) rtDW . jql45x2viu . TimePtr ; boolean_T
justHadZcTime = false ; int_T zcIdx = 0 ; int_T i ; for ( i = 0 ; i < 2046 -
1 ; i ++ ) { if ( ! justHadZcTime && timePoints [ i ] == timePoints [ i + 1 ]
) { zcTimeIndices [ zcIdx ++ ] = i ; justHadZcTime = true ; } else {
justHadZcTime = false ; } } if ( justHadZcTime == false ) { zcTimeIndices [
zcIdx ++ ] = 2046 - 1 ; } rtDW . n4oo1gwbci = 0 ; } } { { real_T * pBuffer =
( real_T * ) rt_TDelayCreateBuf ( 2 , 1024 , sizeof ( real_T ) ) ; if (
pBuffer == ( NULL ) ) { ssSetErrorStatus ( rtS ,
"tdelay memory allocation error" ) ; return ; } rtDW . i0jyyo5z4h . Tail = 0
; rtDW . i0jyyo5z4h . Head = 0 ; rtDW . i0jyyo5z4h . Last = 0 ; rtDW .
i0jyyo5z4h . CircularBufSize = 1024 ; pBuffer [ 0 ] = rtP .
TransportDelay_InitOutput ; pBuffer [ 1024 ] = ssGetT ( rtS ) ; rtDW .
borxbvmdf3 . TUbufferPtrs [ 0 ] = ( void * ) & pBuffer [ 0 ] ; rtDW .
borxbvmdf3 . TUbufferPtrs [ 1 ] = ( void * ) & pBuffer [ 1024 ] ; } } { {
real_T * pBuffer = ( real_T * ) rt_TDelayCreateBuf ( 2 , 1024 , sizeof (
real_T ) ) ; if ( pBuffer == ( NULL ) ) { ssSetErrorStatus ( rtS ,
"tdelay memory allocation error" ) ; return ; } rtDW . e03x3yx1t1 . Tail = 0
; rtDW . e03x3yx1t1 . Head = 0 ; rtDW . e03x3yx1t1 . Last = 0 ; rtDW .
e03x3yx1t1 . CircularBufSize = 1024 ; pBuffer [ 0 ] = rtP .
TransportDelay1_InitOutput ; pBuffer [ 1024 ] = ssGetT ( rtS ) ; rtDW .
jwb3e3k5si . TUbufferPtrs [ 0 ] = ( void * ) & pBuffer [ 0 ] ; rtDW .
jwb3e3k5si . TUbufferPtrs [ 1 ] = ( void * ) & pBuffer [ 1024 ] ; } }
MdlInitialize ( ) ; { bool externalInputIsInDatasetFormat = false ; void *
pISigstreamManager = rt_GetISigstreamManager ( ) ;
rtwISigstreamManagerGetInputIsInDatasetFormat ( pISigstreamManager , &
externalInputIsInDatasetFormat ) ; if ( externalInputIsInDatasetFormat ) { }
} } void MdlOutputs ( int_T tid ) { real_T eqxcmpo254 ; real_T prl5i1irp0 ;
real_T lcogoujg1n ; real_T cqbhyqtge0 ; real_T akyikpogd5 ; real_T mn0eyhqb1a
; real_T ofr0vc5j3a ; rtB . kf3x2lfbm2 = rtX . jrfptyy1yx ; if (
ssGetLogOutput ( rtS ) ) { { if ( rtwTimeInLoggingInterval (
rtliGetLoggingInterval ( ssGetRootSS ( rtS ) -> mdlInfo -> rtwLogInfo ) ,
ssGetTaskTime ( rtS , 0 ) ) ) { if ( rt_GetOSigstreamManager ( ) != ( NULL )
) { void * pSignalProbeCollection = ( void * ) rtDW . hu2pioagaa .
SignalProbe ; if ( rtwSignalProbeCollectionGetLoggingIsOn (
pSignalProbeCollection ) ) { { real_T t ; void * pData ; t = ssGetTaskTime (
rtS , 0 ) ; pData = ( void * ) & rtB . kf3x2lfbm2 ;
rtwSignalProbeCollectionAppendSample ( pSignalProbeCollection , 0 , t , pData
) ; } } } } } } if ( ssGetLogOutput ( rtS ) ) { StructLogVar * svar = (
StructLogVar * ) rtDW . mvyeftsaxy . LoggedData ; LogVar * var = svar ->
signals . values ; { double locTime = ssGetTaskTime ( rtS , 0 ) ; ;
rt_UpdateLogVar ( ( LogVar * ) svar -> time , & locTime , 0 ) ; } { real_T
up0 [ 1 ] ; up0 [ 0 ] = rtB . kf3x2lfbm2 ; rt_UpdateLogVar ( ( LogVar * ) var
, up0 , 0 ) ; } } lcogoujg1n = rtX . mafixvydzh ; cqbhyqtge0 = rtP . L * rtX
. mafixvydzh ; akyikpogd5 = rtX . htcumeq1zs ; mn0eyhqb1a = rtP . W * rtX .
htcumeq1zs ; { real_T * pDataValues = ( real_T * ) rtDW . jql45x2viu .
DataPtr ; real_T * pTimeValues = ( real_T * ) rtDW . jql45x2viu . TimePtr ;
int_T currTimeIndex = rtDW . g4xb0secad . PrevIndex ; real_T t =
ssGetTaskTime ( rtS , 0 ) ; if ( t > pTimeValues [ 2045 ] ) { { int_T elIdx ;
for ( elIdx = 0 ; elIdx < 2 ; ++ elIdx ) { ( & rtB . athg3b0cpi [ 0 ] ) [
elIdx ] = 0.0 ; } } } else { int numPoints , lastPoint ; FWksInfo *
fromwksInfo = ( FWksInfo * ) rtDW . jql45x2viu . RSimInfoPtr ; numPoints =
fromwksInfo -> nDataPoints ; lastPoint = numPoints - 1 ; if ( t <=
pTimeValues [ 0 ] ) { currTimeIndex = 0 ; } else if ( t >= pTimeValues [
lastPoint ] ) { currTimeIndex = lastPoint - 1 ; } else { if ( t < pTimeValues
[ currTimeIndex ] ) { while ( t < pTimeValues [ currTimeIndex ] ) {
currTimeIndex -- ; } } else { while ( t >= pTimeValues [ currTimeIndex + 1 ]
) { currTimeIndex ++ ; } } } rtDW . g4xb0secad . PrevIndex = currTimeIndex ;
{ real_T t1 = pTimeValues [ currTimeIndex ] ; real_T t2 = pTimeValues [
currTimeIndex + 1 ] ; if ( t1 == t2 ) { if ( t < t1 ) { { int_T elIdx ; for (
elIdx = 0 ; elIdx < 2 ; ++ elIdx ) { ( & rtB . athg3b0cpi [ 0 ] ) [ elIdx ] =
pDataValues [ currTimeIndex ] ; pDataValues += numPoints ; } } } else { {
int_T elIdx ; for ( elIdx = 0 ; elIdx < 2 ; ++ elIdx ) { ( & rtB . athg3b0cpi
[ 0 ] ) [ elIdx ] = pDataValues [ currTimeIndex + 1 ] ; pDataValues +=
numPoints ; } } } } else { real_T f1 = ( t2 - t ) / ( t2 - t1 ) ; real_T f2 =
1.0 - f1 ; real_T d1 ; real_T d2 ; int_T TimeIndex = currTimeIndex ; int_T *
zcTimeIndices = & rtDW . e15wz5f0je [ 0 ] ; int_T * zcTimeIndicesIdx = & rtDW
. n4oo1gwbci ; int_T zcIdx = zcTimeIndices [ * zcTimeIndicesIdx ] ; int_T
numZcTimes = 1023 ; if ( * zcTimeIndicesIdx < numZcTimes ) { if (
ssIsMajorTimeStep ( rtS ) ) { if ( t > pTimeValues [ zcIdx ] ) { while ( *
zcTimeIndicesIdx < ( numZcTimes - 1 ) && ( t > pTimeValues [ zcIdx ] ) ) { (
* zcTimeIndicesIdx ) ++ ; zcIdx = zcTimeIndices [ * zcTimeIndicesIdx ] ; } }
} else { if ( t >= pTimeValues [ zcIdx ] && ( ssGetTimeOfLastOutput ( rtS ) <
pTimeValues [ zcIdx ] ) ) { t2 = pTimeValues [ zcIdx ] ; if ( zcIdx == 0 ) {
TimeIndex = 0 ; t1 = t2 - 1 ; } else { t1 = pTimeValues [ zcIdx - 1 ] ;
TimeIndex = zcIdx - 1 ; } f1 = ( t2 - t ) / ( t2 - t1 ) ; f2 = 1.0 - f1 ; } }
} { int_T elIdx ; for ( elIdx = 0 ; elIdx < 2 ; ++ elIdx ) { d1 = pDataValues
[ TimeIndex ] ; d2 = pDataValues [ TimeIndex + 1 ] ; if ( zcIdx == 0 ) { d2 =
d1 ; } ( & rtB . athg3b0cpi [ 0 ] ) [ elIdx ] = ( real_T ) rtInterpolate ( d1
, d2 , f1 , f2 ) ; pDataValues += numPoints ; } } } } } } rtB . iwrzxexy4o =
rtX . f5csqhdetv ; rtB . m2js5kfkdp = rtX . b1r5fw2cl1 ; rtB . k5fo1npzjc =
rtX . ovyxqe4p1r ; cqbhyqtge0 = ( 0.0 - ( ( ( ( cqbhyqtge0 + mn0eyhqb1a ) +
rtB . kf3x2lfbm2 ) - rtB . athg3b0cpi [ 0 ] ) - rtP . Mb * rtP . g / ( 2.0 *
rtP . Kf + 2.0 * rtP . Kr ) ) * rtP . stiffness_Gain ) - ( ( rtP . L * rtB .
iwrzxexy4o + rtP . W * rtB . m2js5kfkdp ) + rtB . k5fo1npzjc ) * rtP .
damping_Gain ; mn0eyhqb1a = rtP . L * lcogoujg1n ; ofr0vc5j3a = rtP . W *
akyikpogd5 ; { real_T * * uBuffer = ( real_T * * ) & rtDW . borxbvmdf3 .
TUbufferPtrs [ 0 ] ; real_T * * tBuffer = ( real_T * * ) & rtDW . borxbvmdf3
. TUbufferPtrs [ 1 ] ; real_T simTime = ssGetT ( rtS ) ; real_T tMinusDelay =
simTime - rtP . TransportDelay_Delay ; eqxcmpo254 = rt_TDelayInterpolate (
tMinusDelay , 0.0 , * tBuffer , * uBuffer , rtDW . i0jyyo5z4h .
CircularBufSize , & rtDW . i0jyyo5z4h . Last , rtDW . i0jyyo5z4h . Tail ,
rtDW . i0jyyo5z4h . Head , rtP . TransportDelay_InitOutput , 0 , ( boolean_T
) ( ssIsMinorTimeStep ( rtS ) && ( ssGetTimeOfLastOutput ( rtS ) == ssGetT (
rtS ) ) ) ) ; } mn0eyhqb1a = ( 0.0 - ( ( ( ( ofr0vc5j3a - mn0eyhqb1a ) + rtB
. kf3x2lfbm2 ) - eqxcmpo254 ) - rtP . Mb * rtP . g / ( 2.0 * rtP . Kf + 2.0 *
rtP . Kr ) ) * rtP . stiffness_Gain_ejfmxf0ubt ) - ( ( rtP . W * rtB .
m2js5kfkdp - rtP . L * rtB . iwrzxexy4o ) + rtB . k5fo1npzjc ) * rtP .
damping_Gain_jmhajh5utx ; ofr0vc5j3a = ( 0.0 - ( ( ( ( rtP . L * lcogoujg1n -
rtP . W * akyikpogd5 ) + rtB . kf3x2lfbm2 ) - rtB . athg3b0cpi [ 1 ] ) - rtP
. Mb * rtP . g / ( 2.0 * rtP . Kf + 2.0 * rtP . Kr ) ) * rtP .
stiffness_Gain_oi4325ilzi ) - ( ( rtP . L * rtB . iwrzxexy4o - rtP . W * rtB
. m2js5kfkdp ) + rtB . k5fo1npzjc ) * rtP . damping_Gain_kormbqmmae ;
lcogoujg1n *= rtP . L ; akyikpogd5 *= rtP . W ; { real_T * * uBuffer = (
real_T * * ) & rtDW . jwb3e3k5si . TUbufferPtrs [ 0 ] ; real_T * * tBuffer =
( real_T * * ) & rtDW . jwb3e3k5si . TUbufferPtrs [ 1 ] ; real_T simTime =
ssGetT ( rtS ) ; real_T tMinusDelay = simTime - rtP . TransportDelay1_Delay ;
prl5i1irp0 = rt_TDelayInterpolate ( tMinusDelay , 0.0 , * tBuffer , * uBuffer
, rtDW . e03x3yx1t1 . CircularBufSize , & rtDW . e03x3yx1t1 . Last , rtDW .
e03x3yx1t1 . Tail , rtDW . e03x3yx1t1 . Head , rtP .
TransportDelay1_InitOutput , 0 , ( boolean_T ) ( ssIsMinorTimeStep ( rtS ) &&
( ssGetTimeOfLastOutput ( rtS ) == ssGetT ( rtS ) ) ) ) ; } akyikpogd5 = (
0.0 - ( ( ( ( rtB . kf3x2lfbm2 - lcogoujg1n ) - akyikpogd5 ) - prl5i1irp0 ) -
rtP . Mb * rtP . g / ( 2.0 * rtP . Kf + 2.0 * rtP . Kr ) ) * rtP .
stiffness_Gain_dkutidbsbf ) - ( ( rtB . k5fo1npzjc - rtP . L * rtB .
iwrzxexy4o ) - rtP . W * rtB . m2js5kfkdp ) * rtP . damping_Gain_otuxh5svgn ;
rtB . nh0ippmp3i = ( ( ( rtP . L * cqbhyqtge0 - rtP . L * mn0eyhqb1a ) + rtP
. L * ofr0vc5j3a ) - rtP . L * akyikpogd5 ) / rtP . Iyy ; rtB . mutpjnrc5z =
( ( ( rtP . W * cqbhyqtge0 + rtP . W * mn0eyhqb1a ) - rtP . W * ofr0vc5j3a )
- rtP . W * akyikpogd5 ) / rtP . Ixx ; rtB . ipdxefuu4f = ( ( ( cqbhyqtge0 +
mn0eyhqb1a ) + ofr0vc5j3a ) + akyikpogd5 ) / rtP . Mb - rtP . g ;
UNUSED_PARAMETER ( tid ) ; } void MdlUpdate ( int_T tid ) { { real_T * *
uBuffer = ( real_T * * ) & rtDW . borxbvmdf3 . TUbufferPtrs [ 0 ] ; real_T *
* tBuffer = ( real_T * * ) & rtDW . borxbvmdf3 . TUbufferPtrs [ 1 ] ; real_T
simTime = ssGetT ( rtS ) ; rtDW . i0jyyo5z4h . Head = ( ( rtDW . i0jyyo5z4h .
Head < ( rtDW . i0jyyo5z4h . CircularBufSize - 1 ) ) ? ( rtDW . i0jyyo5z4h .
Head + 1 ) : 0 ) ; if ( rtDW . i0jyyo5z4h . Head == rtDW . i0jyyo5z4h . Tail
) { if ( ! rt_TDelayUpdateTailOrGrowBuf ( & rtDW . i0jyyo5z4h .
CircularBufSize , & rtDW . i0jyyo5z4h . Tail , & rtDW . i0jyyo5z4h . Head , &
rtDW . i0jyyo5z4h . Last , simTime - rtP . TransportDelay_Delay , tBuffer ,
uBuffer , ( NULL ) , ( boolean_T ) 0 , false , & rtDW . i0jyyo5z4h .
MaxNewBufSize ) ) { ssSetErrorStatus ( rtS , "tdelay memory allocation error"
) ; return ; } } ( * tBuffer ) [ rtDW . i0jyyo5z4h . Head ] = simTime ; ( *
uBuffer ) [ rtDW . i0jyyo5z4h . Head ] = rtB . athg3b0cpi [ 0 ] ; } { real_T
* * uBuffer = ( real_T * * ) & rtDW . jwb3e3k5si . TUbufferPtrs [ 0 ] ;
real_T * * tBuffer = ( real_T * * ) & rtDW . jwb3e3k5si . TUbufferPtrs [ 1 ]
; real_T simTime = ssGetT ( rtS ) ; rtDW . e03x3yx1t1 . Head = ( ( rtDW .
e03x3yx1t1 . Head < ( rtDW . e03x3yx1t1 . CircularBufSize - 1 ) ) ? ( rtDW .
e03x3yx1t1 . Head + 1 ) : 0 ) ; if ( rtDW . e03x3yx1t1 . Head == rtDW .
e03x3yx1t1 . Tail ) { if ( ! rt_TDelayUpdateTailOrGrowBuf ( & rtDW .
e03x3yx1t1 . CircularBufSize , & rtDW . e03x3yx1t1 . Tail , & rtDW .
e03x3yx1t1 . Head , & rtDW . e03x3yx1t1 . Last , simTime - rtP .
TransportDelay1_Delay , tBuffer , uBuffer , ( NULL ) , ( boolean_T ) 0 ,
false , & rtDW . e03x3yx1t1 . MaxNewBufSize ) ) { ssSetErrorStatus ( rtS ,
"tdelay memory allocation error" ) ; return ; } } ( * tBuffer ) [ rtDW .
e03x3yx1t1 . Head ] = simTime ; ( * uBuffer ) [ rtDW . e03x3yx1t1 . Head ] =
rtB . athg3b0cpi [ 1 ] ; } UNUSED_PARAMETER ( tid ) ; } void MdlUpdateTID1 (
int_T tid ) { UNUSED_PARAMETER ( tid ) ; } void MdlDerivatives ( void ) {
XDot * _rtXdot ; _rtXdot = ( ( XDot * ) ssGetdX ( rtS ) ) ; _rtXdot ->
jrfptyy1yx = rtB . k5fo1npzjc ; _rtXdot -> mafixvydzh = rtB . iwrzxexy4o ;
_rtXdot -> htcumeq1zs = rtB . m2js5kfkdp ; _rtXdot -> f5csqhdetv = rtB .
nh0ippmp3i ; _rtXdot -> b1r5fw2cl1 = rtB . mutpjnrc5z ; _rtXdot -> ovyxqe4p1r
= rtB . ipdxefuu4f ; } void MdlProjection ( void ) { } void MdlZeroCrossings
( void ) { { const double * timePtr = ( double * ) rtDW . jql45x2viu .
TimePtr ; int_T * zcTimeIndices = & rtDW . e15wz5f0je [ 0 ] ; int_T
zcTimeIndicesIdx = rtDW . n4oo1gwbci ; ( ( ZCV * ) ssGetSolverZcSignalVector
( rtS ) ) -> mmci4w45az = ssGetT ( rtS ) - timePtr [ zcTimeIndices [
zcTimeIndicesIdx ] ] ; } } void MdlTerminate ( void ) { if (
rt_GetOSigstreamManager ( ) != ( NULL ) ) { void * pSignalProbeCollection = (
void * ) rtDW . hu2pioagaa . SignalProbe ;
rtwSignalProbeCollectionDestroyInstance ( pSignalProbeCollection ) ; }
rt_FREE ( rtDW . jql45x2viu . RSimInfoPtr ) ; rt_TDelayFreeBuf ( rtDW .
borxbvmdf3 . TUbufferPtrs [ 0 ] ) ; rt_TDelayFreeBuf ( rtDW . jwb3e3k5si .
TUbufferPtrs [ 0 ] ) ; rtwOSigstreamManagerSaveDatasetsToMatFile (
rt_GetOSigstreamManager ( ) , rt_GetMatSigstreamLoggingFileName ( ) ) ;
rtwOSigstreamManagerDestroyInstance ( rt_GetOSigstreamManager ( ) ) ; } void
MdlInitializeSizes ( void ) { ssSetNumContStates ( rtS , 6 ) ;
ssSetNumPeriodicContStates ( rtS , 0 ) ; ssSetNumY ( rtS , 0 ) ; ssSetNumU (
rtS , 0 ) ; ssSetDirectFeedThrough ( rtS , 0 ) ; ssSetNumSampleTimes ( rtS ,
1 ) ; ssSetNumBlocks ( rtS , 65 ) ; ssSetNumBlockIO ( rtS , 8 ) ;
ssSetNumBlockParams ( rtS , 6164 ) ; } void MdlInitializeSampleTimes ( void )
{ ssSetSampleTime ( rtS , 0 , 0.0 ) ; ssSetOffsetTime ( rtS , 0 , 0.0 ) ; }
void raccel_set_checksum ( SimStruct * rtS ) { ssSetChecksumVal ( rtS , 0 ,
2766936934U ) ; ssSetChecksumVal ( rtS , 1 , 2617085270U ) ; ssSetChecksumVal
( rtS , 2 , 296463808U ) ; ssSetChecksumVal ( rtS , 3 , 1505035899U ) ; }
SimStruct * raccel_register_model ( void ) { static struct _ssMdlInfo mdlInfo
; ( void ) memset ( ( char * ) rtS , 0 , sizeof ( SimStruct ) ) ; ( void )
memset ( ( char * ) & mdlInfo , 0 , sizeof ( struct _ssMdlInfo ) ) ;
ssSetMdlInfoPtr ( rtS , & mdlInfo ) ; { static time_T mdlPeriod [
NSAMPLE_TIMES ] ; static time_T mdlOffset [ NSAMPLE_TIMES ] ; static time_T
mdlTaskTimes [ NSAMPLE_TIMES ] ; static int_T mdlTsMap [ NSAMPLE_TIMES ] ;
static int_T mdlSampleHits [ NSAMPLE_TIMES ] ; static boolean_T
mdlTNextWasAdjustedPtr [ NSAMPLE_TIMES ] ; static int_T mdlPerTaskSampleHits
[ NSAMPLE_TIMES * NSAMPLE_TIMES ] ; static time_T mdlTimeOfNextSampleHit [
NSAMPLE_TIMES ] ; { int_T i ; for ( i = 0 ; i < NSAMPLE_TIMES ; i ++ ) {
mdlPeriod [ i ] = 0.0 ; mdlOffset [ i ] = 0.0 ; mdlTaskTimes [ i ] = 0.0 ;
mdlTsMap [ i ] = i ; mdlSampleHits [ i ] = 1 ; } } ssSetSampleTimePtr ( rtS ,
& mdlPeriod [ 0 ] ) ; ssSetOffsetTimePtr ( rtS , & mdlOffset [ 0 ] ) ;
ssSetSampleTimeTaskIDPtr ( rtS , & mdlTsMap [ 0 ] ) ; ssSetTPtr ( rtS , &
mdlTaskTimes [ 0 ] ) ; ssSetSampleHitPtr ( rtS , & mdlSampleHits [ 0 ] ) ;
ssSetTNextWasAdjustedPtr ( rtS , & mdlTNextWasAdjustedPtr [ 0 ] ) ;
ssSetPerTaskSampleHitsPtr ( rtS , & mdlPerTaskSampleHits [ 0 ] ) ;
ssSetTimeOfNextSampleHitPtr ( rtS , & mdlTimeOfNextSampleHit [ 0 ] ) ; }
ssSetSolverMode ( rtS , SOLVER_MODE_SINGLETASKING ) ; { ssSetBlockIO ( rtS ,
( ( void * ) & rtB ) ) ; { rtB . kf3x2lfbm2 = 0.0 ; rtB . athg3b0cpi [ 0 ] =
0.0 ; rtB . athg3b0cpi [ 1 ] = 0.0 ; rtB . iwrzxexy4o = 0.0 ; rtB .
m2js5kfkdp = 0.0 ; rtB . k5fo1npzjc = 0.0 ; rtB . nh0ippmp3i = 0.0 ; rtB .
mutpjnrc5z = 0.0 ; rtB . ipdxefuu4f = 0.0 ; } } ssSetDefaultParam ( rtS , (
real_T * ) & rtP ) ; { real_T * x = ( real_T * ) & rtX ; ssSetContStates (
rtS , x ) ; ( void ) memset ( ( void * ) x , 0 , sizeof ( X ) ) ; } { void *
dwork = ( void * ) & rtDW ; ssSetRootDWork ( rtS , dwork ) ; ( void ) memset
( dwork , 0 , sizeof ( DW ) ) ; rtDW . npwmhg4hk3 . modelTStart = 0.0 ; rtDW
. hr4o3k3rqn . modelTStart = 0.0 ; } { static DataTypeTransInfo dtInfo ; (
void ) memset ( ( char_T * ) & dtInfo , 0 , sizeof ( dtInfo ) ) ;
ssSetModelMappingInfo ( rtS , & dtInfo ) ; dtInfo . numDataTypes = 14 ;
dtInfo . dataTypeSizes = & rtDataTypeSizes [ 0 ] ; dtInfo . dataTypeNames = &
rtDataTypeNames [ 0 ] ; dtInfo . BTransTable = & rtBTransTable ; dtInfo .
PTransTable = & rtPTransTable ; } sldemo_suspn_3dof_InitializeDataMapInfo (
rtS ) ; ssSetIsRapidAcceleratorActive ( rtS , true ) ; ssSetRootSS ( rtS ,
rtS ) ; ssSetVersion ( rtS , SIMSTRUCT_VERSION_LEVEL2 ) ; ssSetModelName (
rtS , "sldemo_suspn_3dof" ) ; ssSetPath ( rtS , "sldemo_suspn_3dof" ) ;
ssSetTStart ( rtS , 0.0 ) ; ssSetTFinal ( rtS , 100.0 ) ; { static RTWLogInfo
rt_DataLoggingInfo ; rt_DataLoggingInfo . loggingInterval = NULL ;
ssSetRTWLogInfo ( rtS , & rt_DataLoggingInfo ) ; } { { static int_T
rt_LoggedStateWidths [ ] = { 1 , 1 , 1 , 1 , 1 , 1 } ; static int_T
rt_LoggedStateNumDimensions [ ] = { 1 , 1 , 1 , 1 , 1 , 1 } ; static int_T
rt_LoggedStateDimensions [ ] = { 1 , 1 , 1 , 1 , 1 , 1 } ; static boolean_T
rt_LoggedStateIsVarDims [ ] = { 0 , 0 , 0 , 0 , 0 , 0 } ; static
BuiltInDTypeId rt_LoggedStateDataTypeIds [ ] = { SS_DOUBLE , SS_DOUBLE ,
SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE } ; static int_T
rt_LoggedStateComplexSignals [ ] = { 0 , 0 , 0 , 0 , 0 , 0 } ; static const
char_T * rt_LoggedStateLabels [ ] = { "CSTATE" , "CSTATE" , "CSTATE" ,
"CSTATE" , "CSTATE" , "CSTATE" } ; static const char_T *
rt_LoggedStateBlockNames [ ] = {
"sldemo_suspn_3dof/Body Dynamics/Vertical (Z) dynamics/Z" ,
"sldemo_suspn_3dof/Body Dynamics/Pitch (THETA) dynamics/THETA" ,
"sldemo_suspn_3dof/Body Dynamics/Roll (PHI) dynamics/PHI" ,
"sldemo_suspn_3dof/Body Dynamics/Pitch (THETA) dynamics/THETAdot" ,
"sldemo_suspn_3dof/Body Dynamics/Roll (PHI) dynamics/PHIdot" ,
"sldemo_suspn_3dof/Body Dynamics/Vertical (Z) dynamics/Zdot" } ; static const
char_T * rt_LoggedStateNames [ ] = { "" , "" , "" , "" , "" , "" } ; static
boolean_T rt_LoggedStateCrossMdlRef [ ] = { 0 , 0 , 0 , 0 , 0 , 0 } ; static
RTWLogDataTypeConvert rt_RTWLogDataTypeConvert [ ] = { { 0 , SS_DOUBLE ,
SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0
, 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 ,
0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 ,
SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE ,
SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } } ; static RTWLogSignalInfo
rt_LoggedStateSignalInfo = { 6 , rt_LoggedStateWidths ,
rt_LoggedStateNumDimensions , rt_LoggedStateDimensions ,
rt_LoggedStateIsVarDims , ( NULL ) , ( NULL ) , rt_LoggedStateDataTypeIds ,
rt_LoggedStateComplexSignals , ( NULL ) , { rt_LoggedStateLabels } , ( NULL )
, ( NULL ) , ( NULL ) , { rt_LoggedStateBlockNames } , { rt_LoggedStateNames
} , rt_LoggedStateCrossMdlRef , rt_RTWLogDataTypeConvert } ; static void *
rt_LoggedStateSignalPtrs [ 6 ] ; rtliSetLogXSignalPtrs ( ssGetRTWLogInfo (
rtS ) , ( LogSignalPtrsType ) rt_LoggedStateSignalPtrs ) ;
rtliSetLogXSignalInfo ( ssGetRTWLogInfo ( rtS ) , & rt_LoggedStateSignalInfo
) ; rt_LoggedStateSignalPtrs [ 0 ] = ( void * ) & rtX . jrfptyy1yx ;
rt_LoggedStateSignalPtrs [ 1 ] = ( void * ) & rtX . mafixvydzh ;
rt_LoggedStateSignalPtrs [ 2 ] = ( void * ) & rtX . htcumeq1zs ;
rt_LoggedStateSignalPtrs [ 3 ] = ( void * ) & rtX . f5csqhdetv ;
rt_LoggedStateSignalPtrs [ 4 ] = ( void * ) & rtX . b1r5fw2cl1 ;
rt_LoggedStateSignalPtrs [ 5 ] = ( void * ) & rtX . ovyxqe4p1r ; }
rtliSetLogT ( ssGetRTWLogInfo ( rtS ) , "tout" ) ; rtliSetLogX (
ssGetRTWLogInfo ( rtS ) , "tmp_raccel_xout" ) ; rtliSetLogXFinal (
ssGetRTWLogInfo ( rtS ) , "xFinal" ) ; rtliSetLogVarNameModifier (
ssGetRTWLogInfo ( rtS ) , "none" ) ; rtliSetLogFormat ( ssGetRTWLogInfo ( rtS
) , 2 ) ; rtliSetLogMaxRows ( ssGetRTWLogInfo ( rtS ) , 0 ) ;
rtliSetLogDecimation ( ssGetRTWLogInfo ( rtS ) , 1 ) ; rtliSetLogY (
ssGetRTWLogInfo ( rtS ) , "" ) ; rtliSetLogYSignalInfo ( ssGetRTWLogInfo (
rtS ) , ( NULL ) ) ; rtliSetLogYSignalPtrs ( ssGetRTWLogInfo ( rtS ) , ( NULL
) ) ; } { static struct _ssStatesInfo2 statesInfo2 ; ssSetStatesInfo2 ( rtS ,
& statesInfo2 ) ; } { static ssPeriodicStatesInfo periodicStatesInfo ;
ssSetPeriodicStatesInfo ( rtS , & periodicStatesInfo ) ; } { static
ssSolverInfo slvrInfo ; static boolean_T contStatesDisabled [ 6 ] ; static
real_T absTol [ 6 ] = { 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 }
; static uint8_T absTolControl [ 6 ] = { 2U , 2U , 2U , 2U , 2U , 2U } ;
static uint8_T zcAttributes [ 1 ] = { ( ZC_EVENT_ALL_UP ) } ;
ssSetSolverRelTol ( rtS , 0.001 ) ; ssSetStepSize ( rtS , 0.0 ) ;
ssSetMinStepSize ( rtS , 0.0 ) ; ssSetMaxNumMinSteps ( rtS , - 1 ) ;
ssSetMinStepViolatedError ( rtS , 0 ) ; ssSetMaxStepSize ( rtS , 0.001 ) ;
ssSetSolverMaxOrder ( rtS , - 1 ) ; ssSetSolverRefineFactor ( rtS , 1 ) ;
ssSetOutputTimes ( rtS , ( NULL ) ) ; ssSetNumOutputTimes ( rtS , 0 ) ;
ssSetOutputTimesOnly ( rtS , 0 ) ; ssSetOutputTimesIndex ( rtS , 0 ) ;
ssSetZCCacheNeedsReset ( rtS , 0 ) ; ssSetDerivCacheNeedsReset ( rtS , 0 ) ;
ssSetNumNonContDerivSigInfos ( rtS , 0 ) ; ssSetNonContDerivSigInfos ( rtS ,
( NULL ) ) ; ssSetSolverInfo ( rtS , & slvrInfo ) ; ssSetSolverName ( rtS ,
"ode45" ) ; ssSetVariableStepSolver ( rtS , 1 ) ;
ssSetSolverConsistencyChecking ( rtS , 0 ) ; ssSetSolverAdaptiveZcDetection (
rtS , 0 ) ; ssSetSolverRobustResetMethod ( rtS , 0 ) ; ssSetAbsTolVector (
rtS , absTol ) ; ssSetAbsTolControlVector ( rtS , absTolControl ) ;
ssSetSolverAbsTol_Obsolete ( rtS , absTol ) ;
ssSetSolverAbsTolControl_Obsolete ( rtS , absTolControl ) ;
ssSetSolverStateProjection ( rtS , 0 ) ; ssSetSolverMassMatrixType ( rtS , (
ssMatrixType ) 0 ) ; ssSetSolverMassMatrixNzMax ( rtS , 0 ) ;
ssSetModelOutputs ( rtS , MdlOutputs ) ; ssSetModelLogData ( rtS ,
rt_UpdateTXYLogVars ) ; ssSetModelLogDataIfInInterval ( rtS ,
rt_UpdateTXXFYLogVars ) ; ssSetModelUpdate ( rtS , MdlUpdate ) ;
ssSetModelDerivatives ( rtS , MdlDerivatives ) ; ssSetSolverZcSignalAttrib (
rtS , zcAttributes ) ; ssSetSolverNumZcSignals ( rtS , 1 ) ;
ssSetModelZeroCrossings ( rtS , MdlZeroCrossings ) ;
ssSetSolverConsecutiveZCsStepRelTol ( rtS , 2.8421709430404007E-13 ) ;
ssSetSolverMaxConsecutiveZCs ( rtS , 1000 ) ; ssSetSolverConsecutiveZCsError
( rtS , 2 ) ; ssSetSolverMaskedZcDiagnostic ( rtS , 1 ) ;
ssSetSolverIgnoredZcDiagnostic ( rtS , 1 ) ; ssSetSolverMaxConsecutiveMinStep
( rtS , 1 ) ; ssSetSolverShapePreserveControl ( rtS , 2 ) ; ssSetTNextTid (
rtS , INT_MIN ) ; ssSetTNext ( rtS , rtMinusInf ) ; ssSetSolverNeedsReset (
rtS ) ; ssSetNumNonsampledZCs ( rtS , 1 ) ; ssSetContStateDisabled ( rtS ,
contStatesDisabled ) ; ssSetSolverMaxConsecutiveMinStep ( rtS , 1 ) ; }
ssSetChecksumVal ( rtS , 0 , 2766936934U ) ; ssSetChecksumVal ( rtS , 1 ,
2617085270U ) ; ssSetChecksumVal ( rtS , 2 , 296463808U ) ; ssSetChecksumVal
( rtS , 3 , 1505035899U ) ; { static const sysRanDType rtAlwaysEnabled =
SUBSYS_RAN_BC_ENABLE ; static RTWExtModeInfo rt_ExtModeInfo ; static const
sysRanDType * systemRan [ 1 ] ; ssSetRTWExtModeInfo ( rtS , & rt_ExtModeInfo
) ; rteiSetSubSystemActiveVectorAddresses ( & rt_ExtModeInfo , systemRan ) ;
systemRan [ 0 ] = & rtAlwaysEnabled ; rteiSetModelMappingInfoPtr (
ssGetRTWExtModeInfo ( rtS ) , & ssGetModelMappingInfo ( rtS ) ) ;
rteiSetChecksumsPtr ( ssGetRTWExtModeInfo ( rtS ) , ssGetChecksums ( rtS ) )
; rteiSetTPtr ( ssGetRTWExtModeInfo ( rtS ) , ssGetTPtr ( rtS ) ) ; } return
rtS ; } const int_T gblParameterTuningTid = 1 ; void
MdlOutputsParameterSampleTime ( int_T tid ) { UNUSED_PARAMETER ( tid ) ; }
