#ifndef __JSON_CONFIG_H__
#define __JSON_CONFIG_H__

#include "config.h"
#include "typedefs.h"

#if defined(__cplusplus)
extern "C"
{
#endif

#if (__OS_LINUX__)
#include "config.h.linux"
#else if (__OS_WIN32__)
#include "config.h.win32"
#endif

#if defined(__cplusplus)
}
#endif

#endif/* __JSON_CONFIG_H__ */
