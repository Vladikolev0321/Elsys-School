#include <iostream>
#include <string>
#include <list>
#include <vector>
using namespace std;


class Airport;
class Plane
{
protected:
    int size;
    int flight_number;
    string model;
    string type;
    int speed;
    int quantity_fuel;
    int lost_per_km;
    int position;
public:
    Plane(){};
    Plane(int size, int flight_number, string model, string type, int speed, int quantity_fuel, int lost_per_km, int position)
    {
        if(size < 1 || size > 10)
        {
            throw("Size of plane should be between 1 and 10");
        }
        this->size = size;
        this->flight_number = flight_number;
        this->model = model;
        this->type = type;
        this->speed = speed;
        this->quantity_fuel = quantity_fuel;
        this->lost_per_km = lost_per_km;
        this->position = position;
    }
    int get_size() const
    {
        return this->size;
    }
    string get_type() const
    {
        return this->type;
    }
    float distance_to_airport(Airport& airport);
    int can_reach(Airport& airport);
    void land_in_nearest_airport(list<Airport> airports);

};

class PassengerPlane : public Plane
{
    int count_passengers;
    int count_places;
    int count_exits;
public:
    PassengerPlane(){};
    PassengerPlane(int count_passengers, int count_places, int count_exits)
    {
        this->count_passengers = count_passengers;
        this->count_places = count_places;
        this->count_exits = count_exits;
    }

};

class CargoPlane : public Plane
{
    int curr_load;
    int max_load;
public:
    CargoPlane(){};
    CargoPlane(int curr_load, int max_load)
    {
        this->curr_load = curr_load;
        this->max_load = max_load;
    }
};

class WarPlane : public Plane
{
    int weapon_power;
public:
    WarPlane(){};
    WarPlane(int weapon_power)
    {
        this->weapon_power = weapon_power;
    }
};

class Airport
{
    int max_count_planes;
    int max_size_plane;
    string type;
    list<Plane> planes;
    int postition;
public:
    Airport(){};
    Airport(int max_count_planes, int max_size_plane, string type, int position)
    {
        this->max_count_planes = max_count_planes;
        this->max_size_plane = max_size_plane;
        this->type = type;
        this->postition = postition;
    }
    int can_fit_plane(const Plane& plane)
    {
        if(this->max_count_planes == this->planes.size())
        {
            cout<<"The airport is full"<<endl;
            return 0;
        }
        if(plane.get_size() > this->max_size_plane)
        {
            cout<<"The airplane is too big for this airport"<<endl;
            return 0;
        }
        if(plane.get_type() != this->type)
        {
            cout<<"This airport doesn't support this type airplane"<<endl;
            return 0;
        }

        return 1;
    }
    
    void land_plane(const Plane& plane)
    {
        this->planes.push_back(plane);
    }

    int get_pos()
    {
        return this->postition;
    }
};


float Plane::distance_to_airport(Airport& airport)
{
    return abs(airport.get_pos() - this->position);
}
int Plane::can_reach(Airport& airport)
{
    int needed_fuel = this->distance_to_airport(airport) * this->lost_per_km;
    if( this->quantity_fuel >= needed_fuel )
    {
        return 1;
    }
    return 0;
}
void Plane::land_in_nearest_airport(list<Airport> airports)
{
    int min_length = 20000;
    int index_of_el;
    int i=0;
    for(list<Airport>::iterator it = airports.begin(); it != airports.end(); it++,i++)
    {
        Airport curr_airport = *it;
        if(this->can_reach(curr_airport))
        {
            if(this->distance_to_airport(curr_airport) < min_length)
            {
                min_length = this->distance_to_airport(curr_airport);
                index_of_el = i;
            }
        }
    }
    list<Airport>::iterator it = airports.begin();
    advance(it, index_of_el);

    (*it).land_plane(*this);

}




int main()
{
    return 0;
}