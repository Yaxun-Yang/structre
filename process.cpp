#include "process.h"

int Process::totPid = 0;
Process::Process(bool ifRandom)
{
    pid=totPid++;
    this->ifRandom = ifRandom;
    nextProcess = nullptr;
}

Process::~Process()
{

}

int Process::getPid()
{
    return pid;
}

void Process::setPcb(int i)
{
    pcb=i;
}
int Process::getPcb()
{
    return pcb;
}

void Process::setTimeRequired(int i)
{
    timeRequired = i*10;
}

int Process::getTimeRequired()
{
    return timeRequired;
}

void Process::SubTime()
{
    timeRequired--;
}

void Process::setPriority(int i)
{
    priority = i;
}

int Process::getPriority()
{
    return priority;
}
void Process::SubPriority()
{
    priority--;
}

void Process::setStatus(int i)
{
    status = i;
}
void Process::setMemorySize(int i)
{
    memorySize = i;
}
int Process::getMemorySize()
{
    return memorySize;
}
void Process::setInitialAddress(int i)
{
    initialAddress = i;
}
int Process::getInitialAddress()
{
    return initialAddress;
}

bool Process::getIfRandom()
{
    return ifRandom;
}

Process* Process::getNextProcess()
{
    return nextProcess;
}

void Process::setNextProcess(Process* nextProcess )
{
    this->nextProcess = nextProcess;
}


