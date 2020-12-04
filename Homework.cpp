#include <iostream>
#include <string>
#include <string.h>
using namespace std;

class NetworkPackage {
	char* content;
	int content_length;
	string ip_sent;
	string ip_to;
	int number_of_packet;
public:
	//static int created_packet_counter = 0;
	NetworkPackage(char *content, int content_length, string ip_sent,string ip_to)
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
	~NetworkPackage()
	{
		delete[] this->content;
	}

};
int main()
{
	return 0;
}