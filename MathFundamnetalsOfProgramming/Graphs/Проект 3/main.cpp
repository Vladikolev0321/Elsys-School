#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <list>
using namespace std;

vector<vector<int>> G;
vector<vector<int>> connected_nodes;


void print(vector<vector<int>> v) {
    cout << v.size() << endl;
    for (int i = 0; i < v.size(); ++i) {
        cout << i /*+ 1*/ << ": ";
        for (int j = 0; j < v[i].size(); ++j) {
            cout << v[i][j] /*+ 1*/ << " ";
        }
        cout << endl;
    }
}

  
int main()
{
    string file_name = "graph1.txt";

  //  int count_vertexes;
   // cout<<"How much vertexes does this graph have?"<<endl;
   // cin>>count_vertexes;

    //G = vector<vector<int>>(count_vertexes);

    ifstream istream;
    istream.open(file_name);

    string line;
    int i = 0, j;
	while(getline(istream, line)){
        stringstream S(line);
        j = 0;
        vector<int> connected_n;
        vector<int> adj;

        while(S.peek() != '\n' && S.peek() != EOF) {
            string currVal;

		    getline(S, currVal, ' ');
            if(i != j){        
                adj.push_back(stoi(currVal));
                connected_n.push_back(j);
                //cout<<currVal<<endl;
            }
            j++;
        }
        G.push_back(adj);
        connected_nodes.push_back(connected_n);
        //cout<<endl;
        i++;
    }
    istream.close();

    int start_node;
    cout<<"Enter starting node:"<<endl;
    cin>>start_node;

    cout<<"Graph:"<<endl;
    print(G);
    print(connected_nodes);

}
/*
0 20 15 30
20 0 35 25
15 35 0 30
30 25 30 0
*/