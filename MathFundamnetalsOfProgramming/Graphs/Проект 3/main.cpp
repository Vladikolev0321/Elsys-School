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

vector<vector<int>> from_start_to_end;

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
    //pushes the current node in the path
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

    /* if all nodes are not visited we are going through other connected nodes to the current node and checking if they are visited
       if they are not we invoke the function recurcively from the next connected unvisited node 
    */
    /*
       if all nodes in the graph are visited we check if there is path back to the start and if there is we add it as a valid path
    */
    if(!are_all_visited){
        for (int i = 0; i < connected_nodes[curr_pos].size(); i++){
            if(!is_visited[connected_nodes[curr_pos][i]]){
                find_all_paths_from_starting_point(start_pos, connected_nodes[curr_pos][i], curr_path);
            }
        }
    }else{
        
        if(G[curr_pos][start_pos] > 0){ // if it is -1 or 0 to not count as path because it has no path back to the start node

            // checking if some of the graphs path has -1 as path and if so doesn't add it to the valid paths
            for (int j = 0; j < curr_path.size()-1; j++){ 

                if(G[curr_path[j]][curr_path[j+1]] == -1){
                    for (int i = 0; i < curr_path.size(); i++){
                        curr_path[i] = 0;
                    }
                return;
                }
            }
            
            all_paths.push_back(curr_path);
            for (int i = 0; i < curr_path.size(); i++){
                curr_path[i] = 0;
            }
        }
        
    }
}

// void find_shortest_path_from_start_to_end(int start_pos, int end_pos, int curr_pos,  vector<int> curr_path){
//     // if(curr_pos == end_pos){
//     //     return;
//     // }
//     curr_path.push_back(curr_pos);
    
//     vector<bool> is_visited;

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
//         if(G[curr_pos][start_pos] > 0){ // if it is -1 or 0 to not count as path
//             from_start_to_end.push_back(curr_path);
            
            
//         }
//     }else{
//         for (int i = 0; i < connected_nodes[curr_pos].size(); i++){
//             cout<<"in"<<endl;
//             if(!is_visited[connected_nodes[curr_pos][i]] && connected_nodes[curr_pos][i] != end_pos){
//                 find_shortest_path_from_start_to_end(start_pos, end_pos, connected_nodes[curr_pos][i], curr_path);
//              }else if(connected_nodes[curr_pos][i] == end_pos){
//                  curr_path.push_back(connected_nodes[curr_pos][i]);
//                  return;
//              }
//         }
        
//     }
// }

void calculate_shortest_path(vector<vector<int>> paths){
    vector<int> all_paths_sum;
    // for (int i = 0; i < paths.size(); i++){
    //     all_paths_sum.push_back(0);
    // }

    for (int i = 0; i < paths.size(); i++){
        vector<int> curr_path = paths[i];
        all_paths_sum.push_back(0);
        for (int j = 0; j < curr_path.size()-1; j++){ // adding the sum of the path between curr node and next node in path
            all_paths_sum[i] += G[curr_path[j]][curr_path[j+1]];
        }
        // finally adding the last 
        all_paths_sum[i] += G[curr_path[curr_path.size()-1]][curr_path[0]];
    }

    // finding the minimal path and min index
    int min = all_paths_sum[0];
    int min_index = 0;
    for (int i = 0; i < all_paths_sum.size(); i++){
        if(min > all_paths_sum[i]){
            min = all_paths_sum[i];
            min_index = i;
        }
    }
    
    vector<int> shortest_path = paths[min_index];
    
    
    cout<<"Path: ";
    for (int i = 0; i < shortest_path.size(); i++){
        cout<<shortest_path[i]<<" ";
    }
    cout<<"Time: "<<min<<endl;

}
bool is_there_full_path_with_this_starting_point(int start_pos){
    all_paths.clear();
    vector<int> curr_path;
    find_all_paths_from_starting_point(start_pos, start_pos, curr_path);
    if(all_paths.size() == 0){
        return false;
    }
    return true;

}
  //fix argc and argv
int main(int argc, char *argv[])
{
    if(argc != 2){
        cout<<"You didn't provide a file";
        return 0;
    }
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

    calculate_shortest_path(all_paths);
    
    for (int i = 0; i < curr_path.size(); i++)
    {
        cout<<curr_path[i]<<endl;
    }
    
    vector<int> curr_path2;
    cout<<"here"<<endl;
    //find_shortest_path_from_start_to_end(start_node, 3, start_node, curr_path2);
    //print(from_start_to_end);
    cout<<"Is there full path with this starting node:"<<is_there_full_path_with_this_starting_point(start_node)<<endl;
    
    
}
/*
0 20 15 30
20 0 35 25
15 35 0 30
30 25 30 0
*/