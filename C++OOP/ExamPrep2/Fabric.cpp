#include <iostream>
#include <string>
using namespace std;

class Container;
class Set;
class Model
{
    string name;
    int quantity;
public:
    Model(){};
    Model(string name, int quantity)
    {
        this->name = name;
        this->quantity = quantity;
    }
    void print()
    {
        cout<<name<<":"<<quantity<<endl;
    }
    Container* produce(string type, int serial_num);
};
class Container
{
    Model *model;
    string type;
    int serial_num;
public:
    Container(){};
    Container(Model *model, string type, int serial_num)
    {
        this->model = model;
        this->type = type;
        this->serial_num = serial_num;
    }
    int get_serial_num()
    {
        return this->serial_num;
    }
    void print()
    {
        model->print();
        cout<<type<<endl;
        cout<<serial_num<<endl;

    }
    Set* operator+(Container* container);

};
class Set
{
    Container *sol;
    Container *piper;
    string serial_num;
public:
    Set(Container* sol, Container* piper)
    {
        this->sol = sol;
        this->piper = piper;
        this->serial_num = sol->get_serial_num()+":"+piper->get_serial_num();
    }
};

Container* Model::produce(string type, int serial_num)
{
    Container *new_cont = new Container(this, type, serial_num);
    return new_cont;
}
Set* Container::operator+(Container* container)
{
    //Container(this->model, this->type, serial_num);
    Set *new_set = new Set(this, container);
    return new_set;
}

int main()
{
    Model model = Model("Sol", 20);
    Container *sol_cont = model.produce("sol", 1);
    Container *piper_cont = model.produce("piper", 2);
    //Set *sol_i_piper = sol_cont+piper_cont;
    sol_cont->print();
    piper_cont->print();

    return 0;
}