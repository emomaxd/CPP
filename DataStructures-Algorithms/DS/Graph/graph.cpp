#include <iostream>
#include <vector>
#include <stack>
#include <queue>

void addEdge(std::vector<int> adj[],int u,int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}
void printGraph(std::vector<int> adj[],int v){
    for(int i=0;i<v;i++){
        std::cout<<"adjacency list of vertex "<<i<<"\n head";
        for(auto x:adj[i]){
            std::cout<<"-> "<<x;
        }
        printf("\n");
    }
}

void DFS(std::vector<std::vector<int>>& g, int index){
    std::vector<bool> visited(g.size(), false);
    std::stack<int> st;
    st.push(index);
    visited[index] = true;

    while(!st.empty()){
        int node = st.top(); st.pop();
        visited[node] = true;

        for(auto& a : g[node]){
            if(!visited[a]){
                std::cout << a << std::endl;
                visited[a] = true;
                st.push(a);
            }
        }
    }
}


void recDFS(std::vector<std::vector<int>>& g, int index, std::vector<bool>& visited){
    visited[index] = true;
    std::cout << index << std::endl;

    for(auto& a : g[index]){
        if(!visited[a]){
            recDFS(g, a, visited);
        }
    }
}

void BFS(std::vector<std::vector<int>>& g, int index){
    std::vector<bool> visited(g.size(), false);
    std::queue<int> q;

    q.push(index);
    visited[index] = true;

    while(!q.empty()){
        int node = q.front(); q.pop();
        std::cout<<node<<std::endl;

        for(auto& a : g[node]){
            if(!visited[a]){
                visited[a] = true;
                q.push(a);
            }
        }

    }
    

}


int main(){

    
    std::vector<int> adj[5];
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 4);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 4);
    printGraph(adj, 5);


    return 0;
}
