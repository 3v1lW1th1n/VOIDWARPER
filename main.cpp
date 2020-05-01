#include <windows.h>
#include <iostream>
#include <tlhelp32.h>

//-----------------------------------------------------------
// Get process PID from provided name
//-----------------------------------------------------------

int getProcessPid(){

    HANDLE pidSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPALL, 0);
    PROCESSENTRY32 p32;
    p32.dwSize = sizeof(PROCESSENTRY32);

    if(pidSnapshot == INVALID_HANDLE_VALUE){
        std::cout << "[!] Failed to get process PID" << GetLastError() << std::endl;
    }

    int pid = 0;
    char targetProcess[] = "notepad.exe";

    while(Process32Next(pidSnapshot, &p32)){

        if(strcmp(p32.szExeFile, targetProcess) == 0) {
            pid = p32.th32ProcessID;
            std::cout << "[+] " << targetProcess << "- PID - " << pid;
        } else {
            std::cout << "[!] Failed to get associated PID\n";
        }
    }
    return pid;
    CloseHandle(pidSnapshot);
}

//-----------------------------------------------------------
// Inject DLL into target process with LoadLibrary technique
//-----------------------------------------------------------
void loadlibraryTechnique(){
    // loadLibrary (classic DLL injection technique)
    // provide PID to inject (for an update provide process snapshot walking)
    int dwProcessId = 4504;
    HANDLE procOpen;
    if(procOpen = OpenProcess(PROCESS_ALL_ACCESS, FALSE, dwProcessId)){
        std::cout << "[+] Opened access to the process : " << dwProcessId;
    } else {
        std::cout << "[!] Failed to open access to the process : " << dwProcessId << GetLastError();
    }
    LPVOID dllSize = sizeof();
    if(VirtualAllocEx(procOpen, NULL, dllSize ,MEM_COMMIT ,PAGE_READWRITE)){
        std::cout << "[+] Memory allocated : " << dwProcessId;
    } else {
        std::cout << "[!] Failed to allocate memory : " << GetLastError();
    }

    //WriteProcessMemory();
    //CreateRemoteThread();


}

void usage(){

    std::cout << "VOIDWARPER - DLL injection tool w/ support for multiple methods" << std::endl;
    std::cout << "[1] LoadLibrary DLL injection";
    std::cout << "Example : VOIDWARPER.exe <Process name> <DLL path to inject> <method>\n";

}

int main(int argc, char ** argv){

    loadlibraryTechnique();

    return 0;
}
