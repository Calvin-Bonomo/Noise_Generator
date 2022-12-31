#include "DebugConsole.h"

DebugConsole* DebugConsole::m_instance = nullptr;

DebugConsole* DebugConsole::Debug() 
{
    if (m_instance == nullptr) 
    {
        AllocConsole();
        m_instance = new DebugConsole(GetStdHandle(STD_OUTPUT_HANDLE));
        m_instance->Log("Console created successfully!");
    }
    return m_instance;
}

void DebugConsole::Kill() 
{
    FreeConsole();
    delete m_instance;
}

bool DebugConsole::Log(std::string log) 
{
    log = " > " + log.append("\n");
    if(WriteConsoleA(m_instance->m_outputHandle, log.c_str(), log.length(), &m_instance->m_charsWritten, NULL) == 0) 
    {
        throw "Unable to write to console!";
    }
    return m_instance->m_charsWritten < log.length();
}