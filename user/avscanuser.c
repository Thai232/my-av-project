/*++

Copyright (c) Microsoft Corporation.  All rights reserved.

Module Name:

    avscanuser.c

Abstract:

    This is the user application that communicates with the avscan
    minifilter driver.

Environment:

    User mode

--*/

#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <fltUser.h>
#include "..\filter\avscan.h"

#pragma comment(lib, "fltlib.lib")

HANDLE gPort = INVALID_HANDLE_VALUE;

HRESULT
AvConnectCommunicationPort (
    VOID
    );

VOID
AvCloseCommunicationPort (
    VOID
    );

int __cdecl
wmain (
    _In_ int argc,
    _In_reads_(argc) PWCHAR *argv
    )
/*++

Routine Description:

    The main user mode program.  This program talks to the AvScan filter

Arguments:

    argc - Number of parameters

    argv - Array of parameters

Return Value:

    0 - Success
    Otherwise - Error

--*/
{
    HRESULT hr;

    UNREFERENCED_PARAMETER( argc );
    UNREFERENCED_PARAMETER( argv );

    printf("AvScan: User mode application started\n");

    //
    //  Connect to the minifilter
    //

    hr = AvConnectCommunicationPort();

    if (FAILED(hr)) {

        printf("AvScan: Failed to connect to minifilter (0x%08x)\n", hr);
        return 1;
    }

    printf("AvScan: Connected to minifilter\n");

    //
    //  Wait for user to exit
    //

    printf("AvScan: Press Enter to exit...\n");
    getchar();

    //
    //  Close the connection
    //

    AvCloseCommunicationPort();

    printf("AvScan: Disconnected from minifilter\n");

    return 0;
}

HRESULT
AvConnectCommunicationPort (
    VOID
    )
/*++

Routine Description:

    Open a connection to the AvScan minifilter.

Arguments:

    None

Return Value:

    S_OK - Success
    Otherwise - Error

--*/
{
    HRESULT hr;

    hr = FilterConnectCommunicationPort( AVSCAN_PORT_NAME,
                                         0,
                                         NULL,
                                         0,
                                         NULL,
                                         &gPort );

    return hr;
}

VOID
AvCloseCommunicationPort (
    VOID
    )
/*++

Routine Description:

    Close the connection to the AvScan minifilter.

Arguments:

    None

Return Value:

    None

--*/
{
    if (gPort != INVALID_HANDLE_VALUE) {

        CloseHandle( gPort );
        gPort = INVALID_HANDLE_VALUE;
    }
}
