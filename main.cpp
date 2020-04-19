#include <windows.h>
#include <iostream.h>

void loadlibraryTechnique(){
    // loadLibrary (classic DLL injection technique)
    // provide PID to inject (for an update provide process snapshot walking)
    int dwProcessId = 4504;
    if(OpenProcess(PROCESS_ALL_ACCESS, FALSE, dwProcessId)){
        std::cout << "[+] Opened access to the process : " << dwProcessId;
    } else {
        std::cout << "[!] Failed to open access to the process : " << dwProcessId << GetLastError();
    }
    if(VirtualAllocEx(oProc, NULL, <soemthing> ,VIRTUAL_MEM ,PAGE_READWRITE)){
        std::cout << "[+] Memory allocated : " << dwProcessId;
    } else {
        std::cout << "[!] Failed to allocate memory : " << GetLastError();
    }

    //WriteProcessMemory();
    //CreateRemoteThread();


}

int main(int argc, char ** argv){

    loadlibraryTechnique();

    return 0;
}
