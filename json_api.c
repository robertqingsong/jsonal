#include "json_api.h"

//json string.
void *json_parsing_open( const int8_t *pJsonStr )
{
	void *pRetCode = NULL;
	
	if ( pJsonStr )
	{
		pRetCode = (void *)json_tokener_parse( pJsonStr );
	}
	
	return pRetCode;
}

//get json field.
int32_t json_get_int_field( void *pJsonHandle, const int8_t *pFieldName )
{
	int32_t iRetCode = -1;
	
	if ( pJsonHandle && pFieldName )
	{
		struct json_object *o = json_object_object_get( pJsonHandle, pFieldName );
		
		if ( o )
		{
			iRetCode = json_object_get_int( o );
		}
	}
	
	return iRetCode;
}

int32_t json_get_string_field( void *pJsonHandle, const int8_t *pFieldName, int8_t *pFieldBuf, const int32_t iFieldBufLen )
{
	int32_t iRetCode = -1;
	
	if ( pJsonHandle && pFieldName && pFieldBuf && iFieldBufLen > 0 )
	{
		struct json_object *o = json_object_object_get( pJsonHandle, pFieldName );
		
		if ( o )
		{
			const int8_t *pFieldData = json_object_get_string( o );
			
			if ( pFieldData )
			{
				int32_t iLen = strlen( pFieldData );
				
				if ( iLen < iFieldBufLen )
				{
					memcpy( pFieldBuf, pFieldData, iLen + 1 );	
					
					iRetCode = iLen;
				}
			}
		}
	}
	
	return iRetCode;
}

//stop parsing json.
void json_parsing_close( void *pJsonHandle )
{
	if ( pJsonHandle )
	{
		json_object_put( pJsonHandle );
		pJsonHandle = NULL;
	}
}
