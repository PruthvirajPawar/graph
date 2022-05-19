

#include<iostream>
#include<queue>

#define SIZE 10

using namespace std;

class Graph {
        int g[SIZE][SIZE];
        int nv, ne;
        int visited[SIZE];
    public:
        Graph() {
            ne = nv = 0;
            cout << endl << "Enter no. of vertices: ";
            cin >> nv;
            
            for(int i = 0; i < nv; i++) {
                visited[i] = 0;
                for(int j = 0; j < nv; j++) {
                    g[i][j] = 0;
                }
            }
        }
        void display();
        void input();
        void DFS(int);              
        void BFS(int);              
};

void Graph::display() {
    for(int i = 0; i < nv; i++) {
        for(int j = 0; j < nv; j++) {
            cout << " " << g[i][j];       
        }
        cout << endl;
    }
}

void Graph::input() {
    int u,v;
    cout << endl << "Enter no. of edges: ";    
    cin >> ne;

    for(int i = 0; i < ne; i++) {
        cout << endl << "Enter an edge (u,v): ";
        cin >> u >> v;
        g[u][v] = 1;
        g[v][u] = 1;
    }
}

void Graph::DFS(int start ) {
    cout << "\t" << start;
    visited[start] = 1;
    
    for(int i = 0; i < nv; i++) {    
        if (!visited[i] && g[start][i] != 0) { 
            DFS(i);
        }
    }
}

void Graph::BFS(int start) {
    for (int i = 0; i < nv; i++)
        visited[i]=0;        
    queue<int>q;
    visited[start] = 1;
    q.push(start);

    while(!q.empty()) {
        start = q.front();
        cout << "\t" << start;
        q.pop();

        for(int i = 0; i < nv; i++) {
            if(!visited[i] && g[start][i] != 0) {
                visited[i]=1;
                q.push(i);
            }
        }    
    }   
}

int main() {
    Graph obj;
    int start;
    obj.display();
    obj.input();
    obj.display();
    
    cout << endl << "DFS Traversal ";
    cout << endl << "Enter start vertex:";
    cin >> start;
    obj.DFS(start);
    cout << endl << "BFS Traversal ";
    cout << endl << "Enter start vertex: ";
    cin >> start;
    obj.BFS(start);
    cout << endl;
    return 0;
}
