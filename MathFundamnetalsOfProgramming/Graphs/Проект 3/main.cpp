#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <list>
using namespace std;
#define INFINITY 9999
#define max 4

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


void dijkstra(vector<vector<int>> G,int n,int startnode) {
   int cost[max][max],distance[max],pred[max];
   int visited[max],count,mindistance,nextnode,i,j;
   for(i=0;i<n;i++)
      for(j=0;j<n;j++)
   if(G[i][j]==0)
      cost[i][j]=INFINITY;
   else
      cost[i][j]=G[i][j];
   for(i=0;i<n;i++) {
      distance[i]=cost[startnode][i];
      pred[i]=startnode;
      visited[i]=0;
   }
   distance[startnode]=0;
   visited[startnode]=1;
   count=1;
   while(count<n-1) {
      mindistance=INFINITY;
      for(i=0;i<n;i++)
         if(distance[i]<mindistance&&!visited[i]) {
         mindistance=distance[i];
         nextnode=i;
      }
      visited[nextnode]=1;
      for(i=0;i<n;i++)
         if(!visited[i])
      if(mindistance+cost[nextnode][i]<distance[i]) {
         distance[i]=mindistance+cost[nextnode][i];
         pred[i]=nextnode;
      }
      count++;
   }
   for(i=0;i<n;i++)
   if(i!=startnode) {
      cout<<"\nDistance of node"<<i<<"="<<distance[i];
      cout<<"\nPath="<<i;
      j=i;
      do {
         j=pred[j];
         cout<<"<-"<<j;
      }while(j!=startnode);
   }
}

/*
int printShortestPath(int parent[], int s, int d)
{
    static int level = 0;
    //
    int V = 4;
    // If we reached root of shortest path tree
    if (parent[s] == -1)
    {
        cout << "Shortest Path between " << s << " and "
             << d << " is "  << s << " ";
        return level;
    }
  
    printShortestPath(parent, parent[s], d);
  
    level++;
    if (s < V)
        cout << s << " ";
  
    return level;
}
int findShortestPath(int src, int dest)
{
    // Mark all the vertices as not visited
    //
    int V = 4;
    bool *visited = new bool[2*V];
    int *parent = new int[2*V];
  
    // Initialize parent[] and visited[]
    for (int i = 0; i < 2*V; i++)
    {
        visited[i] = false;
        parent[i] = -1;
    }
  
    // Create a queue for BFS
    list<int> queue;
  
    // Mark the current node as visited and enqueue it
    visited[src] = true;
    queue.push_back(src);
  
    // 'i' will be used to get all adjacent vertices of a vertex
    //list<int>::iterator i;
  
    while (!queue.empty())
    {
        // Dequeue a vertex from queue and print it
        int s = queue.front();
  
        if (s == dest)
            return printShortestPath(parent, s, dest);
  
        queue.pop_front();
  
        // Get all adjacent vertices of the dequeued vertex s
        // If a adjacent has not been visited, then mark it
        // visited and enqueue it
        for (auto i = G[s].begin(); i != G[s].end(); ++i)
        {
            if (!visited[*i])
            {
                visited[*i] = true;
                queue.push_back(*i);
                parent[*i] = s;
            }
        }
        
    }
    return -1;
}*/
  
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
                //cout<<currVal<<endl;
            }
            j++;
        }
        cout<<endl;
        i++;
    }
    istream.close();

    cout<<"Graph:"<<endl;
    print();

    dijkstra(G, 4, 0);
}
/*
0 20 15 30
20 0 35 25
15 35 0 30
30 25 30 0
*/