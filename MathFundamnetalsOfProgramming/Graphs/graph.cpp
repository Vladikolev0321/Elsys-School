#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <fstream>
using namespace std;

vector<vector<int>> G; // adjacency list graph

/*void print() {
    cout<< G.size()<< endl;
    for(int i = 0; i< G.size(); ++i) {
        cout<< i+1<< ": ";
        for(int j = 0; j< G[i].size(); ++j) {
            cout<< G[i][j]+1<< " ";
        }
        cout<< endl;
    }
}*/

bool dfs(int s, int e) {
    stack<int> dfsStack;
    vector<bool> visited(G.size(), false);

    visited[s] = true;
    dfsStack.push(s);

    while(!dfsStack.empty()) {
        int t = dfsStack.top();
        dfsStack.pop();

        for(auto it = G[t].begin(); it != G[t].end(); ++it) {

            if(t == e) {
                return true;
            }

            if (!visited[*it]) {
                //cout<< "vis "<< *it<< endl;
                //continue;
                visited[*it] = true;
                dfsStack.push(*it);
            }
            
            
        }
    }

    return false;
}

/*bool dfsS(int s, int e) {
    stack<int> dfsStack;
    vector<bool> visited(G.size(), false);

    dfsStack.push(s);
    visited[s] = true;

    cout<< "path: ";
    while(!dfsStack.empty()) {
        int c = dfsStack.top();
        cout<< c+1<< " ";
        dfsStack.pop();
        for(int i = 0; i< G[c].size(); ++i) {
            int next = G[c][i];
            if(next == e) {
                cout<< e+1<< endl;
                return true;
            }

            if(!visited[next]) {
                dfsStack.push(next);
                visited[next] = true;
            }
        }
    }

    cout<< endl;
    return false;
}*/

int main() {
    fstream file("graph1.txt");

    int n;
    file>> n;

    G = vector<vector<int>>(n);

    for(int i = 0; i< n; ++i) {
        int mi;
        file>> mi;
        for(int j = 0; j< mi; ++j) {
            int eij;
            file>> eij;
            G[i].push_back(eij-1);
        }
    }

    file.close();

    //print();
    int s = 1;
    int e = 6;
    cout<< "G has path between "<< s << " and "<< e<< "?: " << (dfsS(s-1, e-1) ? "yes" : "no")<< endl;

    return 0;
}