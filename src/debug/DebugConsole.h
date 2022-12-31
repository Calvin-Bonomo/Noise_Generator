#include <stdio.h>
#include "windows.h"
#include <string>
#include <exception>
#include <iostream>

#ifndef DEBUGCONSOLE_H
#define DEBUGCONSOLE_H
class DebugConsole 
{
private:
    DebugConsole(HANDLE outputHandle): m_outputHandle(outputHandle), m_charsWritten(0) {}

    static DebugConsole* m_instance;
    HANDLE m_outputHandle;
    DWORD m_charsWritten;
public:
    static DebugConsole* Debug();
    void Kill();

    bool Log(std::string log);
};
#endif