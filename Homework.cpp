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
	vector<Router> routers_connected_to;
	class InformationForKnownRoutes {
		string ip;
		int index_in_routers;
		int count_sent_packets;
	public:

		InformationForKnownRoutes(string ip, int index)
		{
			this->ip = ip;
			this->index_in_routers = index;
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

	Router(string name, string ip_address)
	{
		const static int max_count_elem_in_routing_table;
		const static int max_hops;
		this->name = name;
		this->ip_address = ip_address;
	}

	void add_router(const Router& router)
	{
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
					routing_table.push_back(InformationForKnownRoutes(address, i));
					return 1;
				}
			}
			return 0;
		}

	}
	void send_package(const Package& package)
	{
		if (this->ip_address != package.get_ip_to())
		{
			for (list<InformationForKnownRoutes>::iterator it = this->routing_table.begin(); it != this->routing_table.end(); it++)
			{
				InformationForKnownRoutes currInfo = *it;
				if (currInfo.get_ip() == package.get_ip_to())
				{
					currInfo.increase_count_sent_packets();
					break;
				}
			}
		}
	}
	

};
int main()
{
	return 0;
}
