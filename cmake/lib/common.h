#ifdef WINDOWS_DEFINITION
// Windows下的代码
#include <winsock2.h> // Please include winsock2.h before windows.h
#include <windows.h>
#include <ws2tcpip.h>

#endif

#ifdef LINUX_DEFINITION
// Linux下的代码
#include <sys/socket.h>
#include <netinet/in.h>

#endif

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <strings.h>
#include <sys/types.h>
#include <pthread.h>
#include "config.h"

// linux下：  #include <sys/socket.h>
//           #include <netinet/in.h>

// windows下：
//          #include <windows.h>
//          #include <winsock2.h>
//          #include <ws2tcpip.h>


