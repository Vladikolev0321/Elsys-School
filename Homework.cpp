#include <iostream>
#include <string>
#include <string.h>
#include <list>
#include <vector>
using namespace std;

class Package {
	char* content;
	int content_length;
	string ip_sent;
	string ip_to;
	int number_of_packet;
public:
	//static int created_packet_counter = 0;
	Package(char *content, int content_length, string ip_sent,string ip_to)
	{
		if (strlen(content) == 0) {
			throw "Content is empty";
		}
		if (ip_sent.compare("0.0.0.0") == 0 || ip_sent.compare("127.0.0.0") == 0 || ip_to.compare("0.0.0.0") == 0
			|| ip_to.compare("127.0.0.0") == 0)
		{
			throw "Not supported addresses";
		}
		static int created_packet_counter = 0;
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
	int validate()
	{	
		//int counter = 0;
		/*for(int i = 0;;i++)
		{
			counter++;
			if (this->content[i] == '\0')
			{
				break;
			}
		}
		*/
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

		string get_ip()
		{
			return this->ip;
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
		///hops is not used to ask!!!!!!!!!!!!!
			int i = 0;
			for (vector<Router>::iterator it = this->routers_connected_to.begin(); it != this->routers_connected_to.end(); it++,i++)
			{
				Router currRouter = *it;
				if (currRouter.query_route(address, hop_count - 1) == 1)
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
		//if(pa)
		if (this->ip_address == package.get_ip_to())
		{
			cout<<"Package received"<<endl;
			this->sent_packages++;
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
				return;
				//break;
			}
		}

		int resFromQueryRoute = this->query_route(package.get_ip_to(), max_hops);
		if(resFromQueryRoute == 1)
		{
			cout<<"Package sent!"<<endl;
			this->sent_packages++;
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

	

};
int main()
{
	return 0;
}
