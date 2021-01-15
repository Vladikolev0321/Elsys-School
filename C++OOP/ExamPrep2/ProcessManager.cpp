#include <iostream>
using namespace std;

class Process
{
    int priority;
    int needed_time;
public:
    Process(int priority, int needed_time)
    {
        this->priority = priority;
        this->needed_time = needed_time;
    }
    int get_priority()
    {
        return priority;
    }
    int get_needed_time()
    {
        return needed_time;
    }   
};
class ProcessManager
{
    int 
};