#ifndef __JSON_API_H__
#define __JSON_API_H__

#include "typedefs.h"

#if defined(__cplusplus)
extern "C" {
#endif

//json string.
void *json_parsing_open( const int8_t *pJsonStr );

//get json field.
int32_t json_get_int_field( void *pJsonHandle, const int8_t *pFieldName );

int32_t json_get_string_field( void *pJsonHandle, const int8_t *pFieldName, int8_t *pFieldBuf, const int32_t iFieldBufLen );

//stop parsing json.
void json_parsing_close( void *pJsonHandle );

#if defined(__cplusplus)
}
#endif


#endif/* __JSON_API_H__ */
