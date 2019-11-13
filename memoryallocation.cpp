#include "memoryallocation.h"

MemoryAllocation::MemoryAllocation()
{
    process = nullptr;
    initialAddress = -1;
    lastMemoryAllocation = nullptr;
    nextMemoryAllocation = nullptr;
}
MemoryAllocation::~MemoryAllocation()
{

}

Process *MemoryAllocation:: getProcess()
{
    return process;
}
void MemoryAllocation::setProcess(Process* process)
{
    this->process = process;
}

int MemoryAllocation::getInitialAddress()
{
    return initialAddress;
}

void MemoryAllocation::setInitialAddress(int initialAddress)
{
    this->initialAddress = initialAddress;
}

int MemoryAllocation::getMemorySize()
{
    return memorySize;
}

void MemoryAllocation::setMemorySize(int memorySize)
{
    this->memorySize = memorySize;
}

MemoryAllocation * MemoryAllocation::getLastMemoryAllocation()
{
    return lastMemoryAllocation;
}

void MemoryAllocation::setLastMemoryAllocation(MemoryAllocation * lastMemoryAllocation)
{
    this->lastMemoryAllocation = lastMemoryAllocation;
}

MemoryAllocation* MemoryAllocation::getNextMemoryAllocation()
{
    return nextMemoryAllocation;
}

void MemoryAllocation::setNextMemoryAllocation(MemoryAllocation* nextMemoryAllocation)
{
    this->nextMemoryAllocation = nextMemoryAllocation;
}
