#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <list>
using namespace std;

vector<vector<int>> G;
vector<vector<int>> connected_nodes;
vector<vector<int>> all_paths;


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

void find_all_paths_from_starting_point(int start_pos, int curr_pos,  vector<int> curr_path){
    curr_path.push_back(curr_pos);
    
    vector<bool> is_visited;

    for (int i = 0; i < G.size(); i++){
        is_visited.push_back(false);
    }
    for (int j = 0; j < curr_path.size(); j++){
        is_visited[curr_path[j]] = true;
    }

    /// check if all nodes in the graph are visited
    bool are_all_visited = true;
    for (int i = 0; i < G.size(); i++){
        if(!is_visited[i]){
            are_all_visited = false;
        }
    }

    if(are_all_visited){
        if(G[curr_pos][start_pos] != 0){
            all_paths.push_back(curr_path);
        }
    }else{
        for (int i = 0; i < connected_nodes[curr_pos].size(); i++){
            if(!is_visited[connected_nodes[curr_pos][i]]){
                find_all_paths_from_starting_point(start_pos, connected_nodes[curr_pos][i], curr_path);
            }
        }
        
    }
}
// void find_all_paths_from_starting_point2(int start_pos, int curr_pos,  vector<int> curr_path){
    
//     for (int i = 0; i < connected_nodes[curr_pos].size(); i++){
        
//             vector<bool> is_visited;
//             if(!is_visited[connected_nodes[curr_pos][i]]){
//                 find_all_paths_from_starting_point(start_pos, connected_nodes[curr_pos][i], curr_path);
//             }
//         }
//     curr_path.push_back(curr_pos);
    





//     for (int i = 0; i < G.size(); i++){
//         is_visited.push_back(false);
//     }
//     for (int j = 0; j < curr_path.size(); j++){
//         is_visited[curr_path[j]] = true;
//     }

//     /// check if all nodes in the graph are visited
//     bool are_all_visited = true;
//     for (int i = 0; i < G.size(); i++){
//         if(!is_visited[i]){
//             are_all_visited = false;
//         }
//     }

//     if(are_all_visited){
//         ///if
//         if(G[curr_pos][start_pos] != 0){
//             all_paths.push_back(curr_path);
//         }
//     }else{
        
        
//     }
// }
void calculate_shortest_path(){
    vector<int> all_paths_sum;
    for (int i = 0; i < all_paths.size(); i++){
        all_paths_sum.push_back(0);
    }

    for (int i = 0; i < all_paths.size(); i++){

        vector<int> curr_path = all_paths[i];
        for (int j = 0; j < curr_path.size()-1; j++){
            all_paths_sum[i] += G[curr_path[j]][curr_path[j+1]];
        }
        all_paths_sum[i] += G[curr_path[curr_path.size()-1]][curr_path[0]];
    }

    // finding the minimal path
    int min = all_paths_sum[0];
    int min_index = 0;
    for (int i = 0; i < all_paths_sum.size(); i++){
        if(min > all_paths_sum[i]){
            min = all_paths_sum[i];
            min_index = i;
        }
    }
    
    vector<int> shortest_path = all_paths[min_index];
    
    
    cout<<"Path: ";
    for (int i = 0; i < shortest_path.size(); i++){
        cout<<shortest_path[i]<<" ";
    }
    cout<<"Time: "<<min<<endl;

}

  //fix argc and argv
int main(int argc, char *argv[])
{
    string file_name = argv[1];

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
            adj.push_back(stoi(currVal));
            if(i != j){        
                //adj.push_back(stoi(currVal));
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


    vector<int> curr_path;
    find_all_paths_from_starting_point(start_node, start_node, curr_path);
    print(all_paths);

    calculate_shortest_path();
    

    
    
}
/*
0 20 15 30
20 0 35 25
15 35 0 30
30 25 30 0
*/