#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Mine;
class Worker;
class Worker
{
protected:
    string name;
    unsigned int number;
    int quantity_material_can_get;
public:
    Worker(string name, unsigned int number)
    {
        this->name = name;
        this->number = number;
        this->quantity_material_can_get = 20;
    }
    string get_name()const
    {
        return name;
    }
    unsigned int get_number()const
    {
        return number;
    }
    int get_quantity()const
    {
        return quantity_material_can_get;
    }
    Worker(const Worker &worker)
    {
        this->name = worker.get_name();
        this->number = worker.get_number();
        this->quantity_material_can_get = worker.get_quantity();
    }
    virtual void print()
    {
        cout<<"Name:"<<name<<endl;
        cout<<"Number:"<<number<<endl;
        cout<<"QuantityMaterial:"<<quantity_material_can_get<<endl;
    }
    virtual unsigned int choose_mine(vector<Mine*> mines);
};
class Mine
{
    int id;
    int curr_quantity_material;
    vector<Worker*> workers;
public:
    Mine(int id, int curr_quantity)
    {
        this->id = id;
        this->curr_quantity_material = curr_quantity;    
    }
    int get_curr_quant()
    {
        return curr_quantity_material;
    }
    int set_curr_quant(int value)
    {
        this->curr_quantity_material = value;
    }
    void add_worker(Worker* worker)
    {
        workers.push_back(worker);
    }
    int get_how_much_workers()
    {
        return workers.size();
    }
    int get_material()
    {
        int sum;
        for (int i = 0; i < workers.size()||this->get_curr_quant()<=0; i++)
        {
            sum += workers[i]->get_quantity();
            this->set_curr_quant(this->get_curr_quant()-workers[i]->get_quantity());
        }
        return sum;
    }
};

class Selfish : public Worker
{
    Selfish(string name, unsigned int number):Worker(name, number)
    {
        this->quantity_material_can_get = 25;
    }
    unsigned int choose_mine(vector<Mine*> mines)override;

};
class Antisocial : public Worker
{
    Antisocial(string name, unsigned int number):Worker(name, number)
    {
        this->quantity_material_can_get = 30;
    }
    unsigned int choose_mine(vector<Mine*> mines)override;

};


unsigned int Worker::choose_mine(vector<Mine*> mines)
{
        if(mines.size() == 0)
        {
            throw "No mines";
        }
        for (int i = 0; i < mines.size(); i++)
        {
            if(mines[i]->get_curr_quant() >= this->get_quantity())
            {
                //mines[i]->set_curr_quant(mines[i]->get_curr_quant()-this->get_quantity());
                mines[i]->add_worker(this);
                return i;
            }
        }
        return -1;
}
unsigned int Selfish::choose_mine(vector<Mine*> mines)
{
        if(mines.size() == 0)
        {
            throw "No mines";
        }
        int index_of_max_mat= -1;
        int max = 0;
        for (int i = 0; i < mines.size(); i++)
        {
            if(mines[i]->get_curr_quant() > max)
            {
                max = mines[i]->get_curr_quant();
                index_of_max_mat = i;
            }
        }
        if(mines[index_of_max_mat]->get_curr_quant() >= this->get_quantity())
        {
            //mines[index_of_max_mat]->set_curr_quant(mines[index_of_max_mat]->get_curr_quant()-this->get_quantity());
            mines[index_of_max_mat]->add_worker(this);
            return index_of_max_mat;
        }
        return -1;
}
unsigned int Antisocial::choose_mine(vector<Mine*> mines)
{
    if(mines.size() == 0)
    {
        throw "No mines";
    }
    for (int i = 0; i < mines.size(); i++)
    {
        if(mines[i]->get_how_much_workers() == 0)
        {
            if(mines[i]->get_curr_quant() >= this->get_quantity())
            {
               // mines[i]->set_curr_quant(mines[i]->get_curr_quant()-this->get_quantity());
                mines[i]->add_worker(this);
                return i;
            }
        }
        
    }
    return -1;
}

class MineCompany
{
    string name;
    unsigned int all_material;
    vector<Worker*> workers;
    vector<Mine*> mines;
public:
    MineCompany(string name)
    {
        this->name = name;
        this->all_material = 0;
    }
    void inicialise_mines(vector<Mine*> mines)
    {
        if(mines.size() == 0)
        {
            throw "No mines in the collection";
        }
        for (int i = 0; i < mines.size(); i++)
        {
            this->mines.push_back(mines[i]);
        }
        
    }
    void mine()
    {
        cout<<"All workers went to mines:"<<endl;
        for (int i = 0; i < workers.size(); i++)
        {
            workers[i]->choose_mine(mines);
        }
        
        for (int i = 0; i < mines.size(); i++)
        {
            all_material += mines[i]->get_material();
        }
        
        
    }
};



int main()
{
    return 0;
}