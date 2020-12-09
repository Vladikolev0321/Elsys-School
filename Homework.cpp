#include <iostream>
#include <string>
#include <string.h>
#include <list>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;

class Package {
	char* content;
	int content_length;
	string ip_sent;
	string ip_to;
	int number_of_packet;
public:
	static int created_packet_counter;
	Package(char *content,string ip_sent,string ip_to)
	{
		if (strlen(content) == 0) {
			throw "Content is empty";
		}
		if (ip_sent.compare("0.0.0.0") == 0 || ip_sent.compare("127.0.0.0") == 0 || ip_to.compare("0.0.0.0") == 0
			|| ip_to.compare("127.0.0.0") == 0)
		{
			throw "Not supported addresses";
		}
		//static int created_packet_counter = 0;
		created_packet_counter++;
		this->content = content;
		this->content_length = content_length;
		this->ip_sent = ip_sent;
		this->ip_to = ip_to;
		this->number_of_packet = created_packet_counter;
	}
	string get_ip_to()const
	{
		return this->ip_to;
	}
	string get_ip()const
	{
		return this->ip_sent;
	}
	char* get_content()const
	{
		return this->content;
	}
	int validate()
	{	
		int counter = strlen(this->content);
		if (counter == this->content_length)
		{
			return 1;
		}
		return 0;
	}
	~Package()
	{
		delete[] this->content;
	}

};
int Package::created_packet_counter = 0;

class Router {
	string name;
	string ip_address;
	vector<Router*> routers_connected_to;/////To have pointer
	int sent_packages;

	class InformationForKnownRoutes {
		string ip;
		int index_in_routers;
	public:
		int count_sent_packets;
		InformationForKnownRoutes(string ip, int index)
		{
			this->ip = ip;
			this->index_in_routers = index;
			this->count_sent_packets = 0;
		}
		int get_index()const
		{
			return this->index_in_routers;
		}
		string get_ip()
		{
			return this->ip;
		}
		int get_info_count_sent_packages()
		{
			return this->count_sent_packets;
		}
		void increase_count_sent_packets()
		{
			this->count_sent_packets++;
		}
	};
	list<InformationForKnownRoutes> routing_table;
public:

	static const int max_count_elem_in_routing_table;
	static const int max_hops;

	Router(string name, string ip_address)
	{
		this->name = name;
		this->ip_address = ip_address;
		this->sent_packages = 0;
	}
	string get_ip()const
	{
		return this->ip_address;
	}
	string get_name()const
	{
		return this->name;
	}
	void add_router(/*const*/ Router* router)
	{
		if(router->ip_address == "127.0.0.0" || router->ip_address == "0.0.0.0")
		{
			throw "cannot add router with this ip adress";
		}
		routers_connected_to.push_back(router);
	}

	int query_route(const string address, const int hop_count)
	{
		if (address == this->ip_address)
		{
			return 1;
		}

		for (list<InformationForKnownRoutes>::iterator it = this->routing_table.begin(); it != this->routing_table.end(); it++)
		{
			InformationForKnownRoutes currInfo= *it;
			if (currInfo.get_ip() == address)
			{
				return 1;
			}
		}

		if (hop_count > 1)
		{/////is != or <

			for (int i = 0; i < routers_connected_to.size(); i++)
			{
				Router *currRouter = routers_connected_to.at(i);	
				if (currRouter->query_route(address, hop_count - 1) == 1)///---
				{
					if(routing_table.size() == max_count_elem_in_routing_table)
					{
						routing_table.pop_back();
					}
					routing_table.push_back(InformationForKnownRoutes(address, i));
					return 1;
				}
			}
			return 0;
		}

	}
	void send_package(const Package& package)
	{	
		if(package.get_ip() == "127.0.0.0" || package.get_ip() == "0.0.0.0")
		{
			throw "cannot send package with this ip adress";
		}
		if(strlen(package.get_content()) == 0)
		{
			throw "cannot send empty package";
		}
		if (this->ip_address == package.get_ip_to())
		{
			cout<<"Package received"<<endl;
			this->sent_packages++;
			check_if_count_sent_is_10();
			return;
		}
		/////to send_package to next router who is next?
		for (list<InformationForKnownRoutes>::iterator it = this->routing_table.begin(); it != this->routing_table.end(); it++)
		{
			InformationForKnownRoutes currInfo = *it;
			if (currInfo.get_ip() == package.get_ip_to())
			{
				cout<<"Package sent"<<endl;
				currInfo.increase_count_sent_packets();
				this->sent_packages++;
				routers_connected_to[currInfo.get_index()]->send_package(package);
				check_if_count_sent_is_10();
				return;
			}
		}

		int resFromQueryRoute = this->query_route(package.get_ip_to(), max_hops);
		if(resFromQueryRoute == 1)
		{
			cout<<"Package sent!"<<endl;
			this->sent_packages++;
			check_if_count_sent_is_10();
		}
		else
		{
			cout<<"Package dumped"<<endl;
		}

	}
	void check_if_count_sent_is_10()
	{
		if(this->sent_packages % 10 == 0)
		{

			vector<InformationForKnownRoutes> temp_routing_table;
			for (int i = 0; i < routing_table.size(); ++i)
			{
				temp_routing_table.push_back(routing_table.front());
				routing_table.pop_front();
			}
			///sorting routing table
			for (int i = 0; i < temp_routing_table.size(); i++)
			{
				for (int j = i + 1; j < temp_routing_table.size(); j++)
				{
					if(temp_routing_table[i].count_sent_packets < temp_routing_table[j].count_sent_packets)
					{
						InformationForKnownRoutes temp = temp_routing_table[i];
						temp_routing_table[i] = temp_routing_table[j];
						temp_routing_table[j] = temp;
					}
				}
			}
			for (int i = 0; i < temp_routing_table.size(); i++)
			{
				this->routing_table.push_back(temp_routing_table[i]);
			}
		}
	}

	void print_routers_connected_to()
	{
		cout<<"Router named:"<<this->name<<" has "<<routers_connected_to.size()<<" routers with names:"<<endl;
		for (int i = 0; i < this->routers_connected_to.size(); i++)
		{
			Router *router = this->routers_connected_to[i];
			cout<<router->name<<endl;
		}
	}

	

};
const int Router::max_count_elem_in_routing_table = 10;
const int Router::max_hops = 5;
vector<Router*> read_from_routers_txt()
{
	vector<Router*> routers;

	ifstream istream;
	istream.open("routers.txt");

	string line;
	while(getline(istream, line))
	{
		//cout<<line<<endl;
		stringstream S(line);
		string currName;
		string currIp;

		getline(S, currName, ' ');
		getline(S, currIp, ' ');

		Router *router = new Router(currName, currIp);
		routers.push_back(router);


	}
	istream.close();

	return routers;
}
void connect_routers_from_network_txt(vector<Router*> routers)//&
{
	ifstream istream;
	istream.open("networks.txt");

	string line;
	while(getline(istream, line))
	{
		//cout<<line<<endl;
		stringstream S(line);
		string firstName;
		string secondName;
		Router *firstRouter;
		Router *secondRouter;

		getline(S, firstName, ' ');
		getline(S, secondName, ' ');

		for (int i = 0; i < routers.size(); i++)
		{
			if(routers[i]->get_name() == firstName)
			{
				firstRouter = routers[i];
			}
			else if(routers[i]->get_name() == secondName)
			{
				secondRouter = routers[i];	
			}
		}
		firstRouter->add_router(secondRouter);
		secondRouter->add_router(firstRouter);


	}
	istream.close();

}
void packages_to_sent_from_packages_txt(vector<Router*> routers)
{
	vector<Package*> packages;

	ifstream istream;
	istream.open("packages.txt");

	string line;
	while(getline(istream, line))
	{
		stringstream S(line);
		string sourceAddress;
		string targetAddress;
		string cont;

		getline(S, sourceAddress, ' ');
		getline(S, targetAddress, ' ');
		//getline(S, content, ' ');
		char separator;
		S >> separator;
		//cout<<separator<<endl;
		getline(S, cont, '"');


		char content[cont.size()+1];

		strcpy(content, cont.c_str());
		//cout<<content<<endl;
		try{
			Package *currPackage = new Package(content, sourceAddress, targetAddress);

			for (int i = 0; i < routers.size(); ++i)
			{
				if(routers[i]->get_ip() == sourceAddress)
				{
					cout<<"From router's name:"<<routers[i]->get_name()<<endl;
					routers[i]->send_package(*currPackage);
				}
			}
		}
		catch(const char *ex)
		{
			cout<<ex<<endl;
		}
	}
	istream.close();


}
int main()
{
	vector<Router*> routers;
	vector<Package*> packages;

	routers = read_from_routers_txt();

	cout<<"Routers info:"<<endl;
	cout<<"Routers count:"<<routers.size()<<endl;
	for (int i = 0; i < routers.size(); i++)
	{
		Router *currRouter = routers.at(i);
		cout<<currRouter->get_name()<<" "<<currRouter->get_ip()<<endl;
	}
	
	cout<<endl;
	connect_routers_from_network_txt(routers);

	for (int i = 0; i < routers.size(); i++)
	{
		Router *currRouter = routers.at(i);
		currRouter->print_routers_connected_to();
	}

	cout<<endl;
	cout<<"Sending packages:"<<endl;
	packages_to_sent_from_packages_txt(routers);

	cout<<Package::created_packet_counter<<endl;
}
