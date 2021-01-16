#include <iostream>
#include <stdlib.h>
#include <vector>
#include <queue>
#include <list>
using namespace std;

class Process
{
protected:
    int priority;
    int needed_time;
public:
    Process(int priority, int needed_time)
    {
        this->priority = priority;
        this->needed_time = needed_time;
    }
    Process(int priority)
    {
        this->priority = priority;
    }
    virtual int get_priority()
    {
        return priority;
    }
    virtual int get_needed_time()
    {
        return needed_time;
    }   
    virtual void print()
    {
        cout<<"Priority: "<< priority << "Needed time: "<< needed_time<<endl;
    }

};
class FileCopy : public Process
{
    int count_files;
    int speed_of_copy;
    FileCopy(int count_files, int speed_of_copy) : Process(4)
    {
        this->count_files = count_files;
        this->speed_of_copy = speed_of_copy;
        this->needed_time = count_files / speed_of_copy;
    }
    int get_priority()
    {
        return speed_of_copy * this->priority;
    }
    int get_needed_time()
    {
        return count_files / speed_of_copy;
    }
};
class AllocateMemory : public Process
{
    int wanted_size;
    int full_size;
    AllocateMemory(int wanted_size, int full_size) : Process(7)
    {
        this->wanted_size = wanted_size;
        this->full_size = full_size;
    }
    int get_needed_time()
    {
        int random = (rand() % 1000) + 100;
        return (wanted_size / full_size) * random;
    }
    int get_priority()
    {
        int random = (rand() % 20) + 10;
        return get_needed_time() * priority * random; 

    }
};
class ProcessManager
{
    int count_threads;
    list<queue<Process*>> threads;

public:
    ProcessManager(int count_threads)
    {
        this->count_threads = count_threads;
        threads = list<queue<Process*>>();
        for (int i = 0; i < count_threads; i++)
        {
            threads.push_back(queue<Process*>());
        }
    }
    void addProcesses(list<Process> processes)
    {
        
    }
    void print()
    {
        int thread_num = 0;
        for(auto it = threads.begin(); it != threads.end(); it++)
        {
            cout<<"Thread: "<<thread_num++<<endl;
            queue<Process*> currThread = *it;

            int process_num = 0;
            while(currThread.size())
            {
                Process *pr = currThread.front();
                currThread.pop();
                cout<<"\tProcess: "<<process_num++<<endl;
                pr->print();
            }
        }
    }

};