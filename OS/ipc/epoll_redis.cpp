/*balisyin 20200225 for kobe*/
void initServer() {
    int j;
    signal(SIG_HUP, SIG_IGN);
    signal(SIG_PIPE, SIGIGN);
    setupSignalHandlers();

    if(server.syslog_enalbed) {

    }
}


 
#include "stdafx.h"
#include <stdio.h>
