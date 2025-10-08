#include <windows.h>
#include <stdio.h>

int main() {
    STARTUPINFO si;
    PROCESS_INFORMATION pi;
    DWORD parentPID = GetCurrentProcessId();

    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    ZeroMemory(&pi, sizeof(pi));

    if (!CreateProcess(
        "C:\Users\S1ck13oy\Downloads\Project\Child1.exe", 
        NULL,   
        NULL,   
        NULL,   
        FALSE,  
        0,     
        NULL,   
        NULL,    
        &si,  
        &pi)     
    ) {
        printf("CreateProcess failed (%lu).\n", GetLastError());
        return 1;
    }

    printf("Parent PID: %lu\n", parentPID);
    printf("Childddd PID: %lu\n", pi.dwProcessId);

    
    WaitForSingleObject(pi.hProcess, INFINITE);

    
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);

    return 0;
}
