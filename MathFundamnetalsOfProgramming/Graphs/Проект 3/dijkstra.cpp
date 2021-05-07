#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <fstream>
using namespace std;

vector<vector<pair<int, int>>> G; // adjacency list graph

void print() {
    cout<< G.size()<< endl;
    for(unsigned int i = 0; i< G.size(); ++i) {
        cout<< i+1<< ": ";
        for(unsigned int j = 0; j< G[i].size(); ++j) {
            cout<< "("<< G[i][j].first+1<< ", "<< G[i][j].second+1<< ") ";
        }
        cout<< endl;
    }
}

int dijkstra(int s, int e) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> dijkstraQueue;
    vector<int> shortestPath(G.size(), std::numeric_limits<int>::max());

    shortestPath[s] = 0;
    dijkstraQueue.push(pair<int, int>(0, s));

    while(!dijkstraQueue.empty()) {
        pair<int, int> nextNode = dijkstraQueue.top();
        int cW = nextNode.first;
        int c = nextNode.second;
        dijkstraQueue.pop();

        for(int i = 0; i< G[c].neighbours.size(); ++i) {
            pair<int, int> nextNeighbour = G[c].neighbours[i];
            int n = nextNeighbour.first;
            int nW = nextNeighbour.second;

            if(cW + nW < shortest[n]) {
                dijkstraQueue.push(pair<int, int>(cW + nW, n));
                shortest[n] = cW + nW;
            }
        }
    }

    cout<< endl;
    return shortest[e];
}

int main() {
    fstream file("graphDij.txt");

    int n;
    file>> n;

    G = vector<vector<pair<int, int>>>(n);

    for(int i = 0; i< n; ++i) {
        int mi;
        file>> mi;
        for(int j = 0; j< mi; ++j) {
            int eij;
            int wij;
            file>> eij>> wij;
            G[i].push_back( pair<int, int>(wij-1, eij-1));
        }
    }

    file.close();

    print();
    int s = 1;
    int e = 6;
    //cout<< "G has path between "<< s << " and "<< e<< "?: " << (bfs(s-1, e-1) ? "yes" : "no")<< endl;

    return 0;
}