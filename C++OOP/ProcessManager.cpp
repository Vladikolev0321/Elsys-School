#include <iostream>
#include <queue>
#include <list>
using namespace std;
class Process
{
	int priority;
	int needed_time;
public:
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
	int count_threads;
	vector<list<Process>> coll;
public:
	ProcessManager(int count_threads)
	{
		this->count_threads = count_threads;
		for (int i = 0; i < count_threads; ++i)
		{
			list<Process> readyQueue;
			coll.push_back(readyQueue);
		}
	}
	void addProcesses(list<Process> processes)
	{

		for (int i = 0; i < count_threads; i++)
		{
			for (int i = 0; i < coll[i].size(); i++)
			{
				
			}
		}
	}
	void print_manager()
	{
		for (int i = 0; i < count_threads; ++i)
		{
			cout<<"Queue:"<<i<<endl;
			for (list<Process>::iterator it = coll[i].begin(); it != coll[i].end(); it++)
			{
				Process currProcess = *it;
				cout<<"Priority:"<<currProcess.get_priority()<<" Needed_time:"<<currProcess.get_needed_time()<<endl;
			}
		}
	}
};

class FileCopy : public Process
{
	int count_files;
	int speed_of_copying;
	const int priority = 4;
	int needed_time;
	int get_needed_time()
	{
		needed_time = count_files / speed_of_copying;
	}
	int get_priority()
	{
		return needed_time * priority;
	}

};
class AllocateMemory : 


int main()
{
	return 0;
}