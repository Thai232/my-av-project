/*++

Copyright (c) Microsoft Corporation.  All rights reserved.

Module Name:

    avscan.h

Abstract:

    Header file which contains the structures, type definitions,
    constants, global variables and function prototypes that are
    shared between kernel and user mode.

Environment:

    Kernel & user mode

--*/

#ifndef __AVSCAN_H__
#define __AVSCAN_H__

#define AVSCAN_PORT_NAME                    L"\\AvScanPort"

#define AVSCAN_SCAN_THREAD_POOL_SIZE        2

#define AVSCAN_MAX_NAME_LENGTH              256

typedef enum _AVSCAN_COMMAND {

    AvCmdScanFile

} AVSCAN_COMMAND;

typedef struct _AVSCAN_MESSAGE {

    AVSCAN_COMMAND Command;

} AVSCAN_MESSAGE, *PAVSCAN_MESSAGE;

typedef struct _AVSCAN_NOTIFICATION {

    ULONG BytesToScan;
    ULONG Reserved;

} AVSCAN_NOTIFICATION, *PAVSCAN_NOTIFICATION;

typedef struct _AVSCAN_REPLY {

    BOOLEAN SafeToOpen;

} AVSCAN_REPLY, *PAVSCAN_REPLY;

typedef struct _AVSCAN_CREATE_PARAMS {

    WCHAR FileName[AVSCAN_MAX_NAME_LENGTH];

} AVSCAN_CREATE_PARAMS, *PAVSCAN_CREATE_PARAMS;

#endif /* __AVSCAN_H__ */
