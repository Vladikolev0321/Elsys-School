#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

vector<vector<int>> G;


void print() {
    cout << G.size() << endl;
    for (int i = 0; i < G.size(); ++i) {
        cout << i /*+ 1*/ << ": ";
        for (int j = 0; j < G[i].size(); ++j) {
            cout << G[i][j] /*+ 1*/ << " ";
        }
        cout << endl;
    }
}

int main()
{
    string file_name = "graph1.txt";

    int count_vertexes;
    cout<<"How much vertexes does this graph have?"<<endl;
    cin>>count_vertexes;

    G = vector<vector<int>>(count_vertexes);

    ifstream istream;
    istream.open(file_name);

    string line;
    int i = 0, j;
	while(getline(istream, line)){
        stringstream S(line);
        j = 0;
        while(S.peek() != '\n' && S.peek() != EOF) {
            string currVal;

		    getline(S, currVal, ' ');
            if(i != j){        
                G[i].push_back(stoi(currVal));
                cout<<currVal<<endl;
            }
            j++;
        }
        cout<<endl;
        i++;
    }
    istream.close();

    print();
}
/*
0 20 15 30
20 0 35 25
15 35 0 30
30 25 30 0
*/