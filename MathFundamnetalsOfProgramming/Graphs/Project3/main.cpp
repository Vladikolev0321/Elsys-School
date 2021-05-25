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
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[i].size(); j++) {
            cout << v[i][j] << " ";
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
                    curr_path.clear();
                    return;
                }
            }
            
            all_paths.push_back(curr_path);
            curr_path.clear();
        }
        
    }
}
void calculate_shortest_path(vector<vector<int>> paths){

    vector<int> all_paths_sum;

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
    int min = INT_MAX;
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
    all_paths.clear();
    return true;

}

void shortest_distance_between_2_nodes(int start, int end_pos)
{
    vector<int> distance;
    vector<bool> is_visited;

    for (int i = 0; i < G.size(); i++){
        distance.push_back(INT_MAX);
        is_visited.push_back(false);
    }
    distance[start] = 0;
  
    // Find shortest path for all nodes
    for (int count = 0; count < G.size() - 1; count++) {
   
        int min = INT_MAX;
        int min_index;
  
        for (int j = 0; j < G.size(); j++){
            if (distance[j] <= min && is_visited[j] == false){
                min = distance[j];
                min_index = j;
            }
        }
        is_visited[min_index] = true;
        for (int i = 0; i < G.size(); i++){
            if (is_visited[i] == false && distance[min_index] + G[min_index][i] < distance[i] && G[min_index][i] > 0){
                    distance[i] = distance[min_index] + G[min_index][i];
            }
        }
    }
    
    cout<<"Distance from:"<<start<<" to "<<end_pos<<" is "<<distance[end_pos]<<" minutes"<<endl;
    
}

int main(int argc, char *argv[])
{
    if(argc != 2){
        cout<<"You didn't provide a file";
        return 0;
    }
    string file_name = argv[1];

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
                connected_n.push_back(j);
            }
            j++;
        }
        G.push_back(adj);
        connected_nodes.push_back(connected_n);
        i++;
    }
    istream.close();

    int start_node;
    cout<<"Enter starting node:"<<endl;
    cin>>start_node;

    cout<<"Graph's weights on each connection:"<<endl;
    print(G);
    cout<<"Each node's connected nodes"<<endl;
    print(connected_nodes);

    
    
    cout<<"Is there full path with this starting node:"<<is_there_full_path_with_this_starting_point(start_node)<<endl;


    vector<int> curr_path;
    find_all_paths_from_starting_point(start_node, start_node, curr_path);
    cout<<"All paths:"<<endl;
    print(all_paths);

    calculate_shortest_path(all_paths);
    
    shortest_distance_between_2_nodes(0, 3);
    
}
/*
0 20 15 30
20 0 35 25
15 35 0 30
30 25 30 0
*/