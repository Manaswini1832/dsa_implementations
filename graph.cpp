#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <stack>
using namespace std;

//GRAPHS ARE EZZZZZZZZZZ
//bfs and dfs same code only queue, stack difference
//recursive bfs and dfs just replace the while loop of adding children of a node to the queue/stack with recursion

class Graph{
    unordered_map<int, vector<int>> adjList;
    
    public :
        //insert
        void insertEdge(int u, int v){
            adjList[u].push_back(v);
            adjList[v].push_back(u);//since undirected graph
        }
        
        //read
        void printGraph(){
            for(auto item: adjList){
                cout << item.first << " -> ";
                for(auto num: item.second){
                    cout << num << "  ";
                }
                cout << "\n";
            }
            
        }
        
        //bfs
        void bfs(int start){
            queue<int> nodes;
            unordered_map<int, bool> visited;
            if(!adjList.empty()){
                nodes.push(start);
                visited[start] = true;
            }else{
                cout << "Can't bfs an empty graph" << endl;
                return;
            }
            
            while(!nodes.empty()){
                int top = nodes.front();
                nodes.pop();
                cout << top << "\n";
                for(auto num:adjList[top]){
                    if(!visited[num]){
                        nodes.push(num);
                        visited[num] = true;
                    }
                }
            }
        }
        
        void bfsHelper(queue<int>& nodes, unordered_map<int, bool>& visited){
            if(nodes.empty()) return;
            
            int top = nodes.front();
            nodes.pop();
            
            cout << top << "\n";
            
            for(auto num: adjList[top]){
                if(!visited[num]){
                    nodes.push(num);
                    visited[num] = true;
                }
            }
            
            bfsHelper(nodes, visited);
        }
        
        void recursiveBFS(int start){
            if(adjList.empty()){
                cout << "Can't bfs an empty graph" << endl;
                return;
            }
            
            queue<int> nodes;
            unordered_map<int, bool> visited;
            nodes.push(start);
            visited[start] = true;
            
            bfsHelper(nodes, visited);
        }
        
        void dfsHelper(stack<int>& nodes, unordered_map<int, bool>& visited){
            if(nodes.empty()) return;
            
            int top = nodes.top();
            nodes.pop();
            
            cout << top << "\n";
            
            for(auto num:adjList[top]){
                if(!visited[num]){
                    nodes.push(num);
                    visited[num] = true;
                }
            }
            
            dfsHelper(nodes, visited);
        }
        
        void recursiveDFS(int start){
            if(adjList.empty()){
                cout << "Can't dfs an empty graph" << endl;
                return;
            }
            
            stack<int> nodes;
            unordered_map<int, bool> visited;
            nodes.push(start);
            visited[start] = true;
            
            dfsHelper(nodes, visited);
        }
        
        //dfs
        void dfs(int start){
            stack<int> nodes;
            unordered_map<int, bool> visited;
            if(!adjList.empty()){
                visited[start] = true;
                nodes.push(start);
                
            }else{
                cout << "Can't dfs an empty graph" << endl;
                return;
            }
            
             while(!nodes.empty()){
                    int top = nodes.top();
                    nodes.pop();
                    
                    cout << top << "\n";
                    
                    for(auto num: adjList[top]){
                        if(!visited[num]){
                            nodes.push(num);
                            visited[num] = true;
                        }
                    }
                        
                }
        }
        
};

int main()
{
    Graph g;
    g.insertEdge(10,2);
    g.insertEdge(5,2);
    g.insertEdge(2,3);
    g.insertEdge(3,1);
    g.insertEdge(1,11);
    g.insertEdge(11,8);
    
    g.recursiveDFS(1);

    return 0;
}
