#include "json_api.h"

int main( int argc, char **argv )
{
	const int8_t *pTestJsonStr = "{ \"test\":\"hello\", \"test2\":100 }";
	void *pJsonHandle = json_parsing_open( pTestJsonStr );
	
	if ( pJsonHandle )
	{
		int32_t test2 = json_get_int_field( pJsonHandle, "test2" );
		int8_t test1Buf[32] = { 0x00, };
		
		if ( json_get_string_field( pJsonHandle, "test", test1Buf, 32 ) >= 0 )
		{
			printf( "testBuf-->%s\r\n", test1Buf );	
		}
		
		printf( "test2-->%d.\r\n", test2 );	
	
		json_parsing_close( pJsonHandle );
		pJsonHandle = NULL;	
	}

	return 0;	
}
