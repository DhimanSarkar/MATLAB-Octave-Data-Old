#include "__cf_sldemo_suspn_3dof.h"
#include "ext_types.h"
static uint_T rtDataTypeSizes [ ] = { sizeof ( real_T ) , sizeof ( real32_T )
, sizeof ( int8_T ) , sizeof ( uint8_T ) , sizeof ( int16_T ) , sizeof (
uint16_T ) , sizeof ( int32_T ) , sizeof ( uint32_T ) , sizeof ( boolean_T )
, sizeof ( fcn_call_T ) , sizeof ( int_T ) , sizeof ( pointer_T ) , sizeof (
action_T ) , 2 * sizeof ( uint32_T ) } ; static const char_T *
rtDataTypeNames [ ] = { "real_T" , "real32_T" , "int8_T" , "uint8_T" ,
"int16_T" , "uint16_T" , "int32_T" , "uint32_T" , "boolean_T" , "fcn_call_T"
, "int_T" , "pointer_T" , "action_T" , "timer_uint32_pair_T" } ; static
DataTypeTransition rtBTransitions [ ] = { { ( char_T * ) ( & rtB . kf3x2lfbm2
) , 0 , 0 , 9 } , { ( char_T * ) ( & rtDW . npwmhg4hk3 . modelTStart ) , 0 ,
0 , 2 } , { ( char_T * ) ( & rtDW . hu2pioagaa . SignalProbe ) , 11 , 0 , 7 }
, { ( char_T * ) ( & rtDW . e15wz5f0je [ 0 ] ) , 10 , 0 , 1027 } } ; static
DataTypeTransitionTable rtBTransTable = { 4U , rtBTransitions } ; static
DataTypeTransition rtPTransitions [ ] = { { ( char_T * ) ( & rtP . Ixx ) , 0
, 0 , 6164 } } ; static DataTypeTransitionTable rtPTransTable = { 1U ,
rtPTransitions } ;
