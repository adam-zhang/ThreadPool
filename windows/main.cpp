// Test.cpp : Defines the entry point for the console application.
//

#include "StdAfx.h"
#include "ThreadPool.h"

CRITICAL_SECTION cs;

using namespace std;

DWORD WINAPI ThreadProc(LPVOID lpParameter)
{
    EnterCriticalSection(&cs);
    cout << LPCSTR(lpParameter) << endl;
    LeaveCriticalSection(&cs);
    return 0;
}

int _tmain(int argc, TCHAR* argv[], TCHAR* envp[])
{
    InitializeCriticalSection(&cs);
        
    CThreadPool *pThrealPool = new CThreadPool(2);
    pThrealPool->Run(ThreadProc, "001");
    pThrealPool->Run(ThreadProc, "002");
    pThrealPool->Run(ThreadProc, "003");
    pThrealPool->Run(ThreadProc, "004");
    pThrealPool->Run(ThreadProc, "005");
    pThrealPool->Run(ThreadProc, "006");
    pThrealPool->Run(ThreadProc, "007");
        
    pThrealPool->Wait(INFINIE);
    delete pThrealPool;
        
    DeleteCriticalSection(&cs);

    return nRetCode;
}
