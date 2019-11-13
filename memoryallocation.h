#ifndef MEMORYALLOCATION_H
#define MEMORYALLOCATION_H

#include "process.h"
class MemoryAllocation
{
    
private:
    Process * process;
    int initialAddress;
    int memorySize;
    MemoryAllocation * lastMemoryAllocation;
    MemoryAllocation* nextMemoryAllocation;
public:
    MemoryAllocation();
    ~MemoryAllocation();
    Process * getProcess();
    void setProcess(Process* process);
    int getInitialAddress();
    void setInitialAddress(int initialAdress);
    int getMemorySize();
    void setMemorySize(int memorySize);
    MemoryAllocation * getLastMemoryAllocation();
    void setLastMemoryAllocation(MemoryAllocation * lastMemoryAllocation);
    MemoryAllocation* getNextMemoryAllocation();
    void setNextMemoryAllocation(MemoryAllocation* nextMemoryAllocation);
};

#endif // MEMORYALLOCATION_H
