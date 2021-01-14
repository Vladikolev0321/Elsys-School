#include <iostream>
#include <string>
#include <vector>
#include <stdbool.h>

using namespace std;

class Action
{
protected:
    int serial_number;
public:
    vector<string> names;
    Action(vector<string> names, int serial_number)
    {
        this->names = names;
        this->serial_number = serial_number;
    }
    virtual void print() const
    {
        cout<<serial_number<<endl;
        for (int i = 0; i < names.size(); i++)
        {
            if(i != names.size()-1)
            {
                cout<<names[i]<<", ";
            }
            else
            {
                cout<<names[i];
            }
        }
    }
    int get_serial_number()
    {
        return this->serial_number;
    }
};

class MusicalAction : public Action
{
    string song_name;
public:
    MusicalAction(string song_name, vector<string> names, int serial_number) : Action(names, serial_number)
    {
        this->song_name = song_name;
    }
    void print() const override
    {
        cout<<serial_number<<endl;
        for (int i = 0; i < names.size(); i++)
        {
            if(i == names.size()-1)
            {
                cout<<names[i]<<" ";
            }
            else
            {
                cout<<names[i]<<", ";
            }
        }
        cout<<endl;
        cout<<song_name<<endl;
    }
};

class Musical
{
    string name;
    vector<Action> actions;
public:
    Musical(string name, vector<Action> actions)
    {
        this->name = name;
        this->actions = actions;
    }
    Musical(string name)
    {
        this->name = name;
    }
    void add_action(Action action)
    {
        bool is_there = false;
        for (int i = 0; i < this->actions.size(); i++)
        {
            if(this->actions[i].get_serial_number() == action.get_serial_number())
            {
                is_there = true;
            }
        }
        if(!is_there)
        {
            this->actions.push_back(action);
        }
    }
    void print() const 
    {
        cout<<this->name<<endl;
        for (int i = 0; i < this->actions.size(); i++)
        {
            this->actions[i].print();
        }
    }
    Action most_crowded_action() const
    {
        if(this->actions.size() == 0)
        {
            throw "No actions in the musichal";
        }
        int index_of_action = 0;
        int max_actors = 0;
        for (int i = 0; i < actions.size(); i++)
        {
            if(this->actions[i].names.size() > max_actors)
            {
                max_actors = this->actions[i].names.size();
                index_of_action = i;
            }
        }
        return this->actions[index_of_action];
    }

};

int main()
{
    Musical musical("Vladi's");

    vector<string> names = {"Vladi ", "Gosho"};
    vector<string> names2 = {"Vladi2 ", "Gosho2"};  

    musical.add_action(Action(names, 1));
    musical.add_action(MusicalAction("Neshto", names2, 2));
    musical.print();

}