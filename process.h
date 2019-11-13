#ifndef PROCESS_H
#define PROCESS_H



class Process
{
    private :
    static int totPid;

    int pid;
    int pcb;
    int timeRequired;
    int priority;
    int status;
    int memorySize;
    int initialAddress;
    bool ifRandom;
    Process* nextProcess;


    public:
        Process(bool ifRandom);
        ~Process();

        int getPid();

        void setPcb(int i);
        int getPcb();

        void setTimeRequired(int i);
        int getTimeRequired();
        void SubTime();

        void setPriority(int i);
        int getPriority();
        void SubPriority();

        void setStatus(int i);

        void setMemorySize(int i);
        int getMemorySize();

        void setInitialAddress(int i);
        int getInitialAddress();

        bool getIfRandom();

        Process* getNextProcess();
        void setNextProcess(Process* nextProcess);



};

#endif // PROCESS_H
