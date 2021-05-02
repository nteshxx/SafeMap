#include<iostream>
//#include "header.h"
#include <list>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

class SafeMap
{
    int V; // No. of vertices
    list<int> *adj; // Pointer to an array containing adjacency lists
public:
    SafeMap(int V); // Constructor
    void addSafeRoute(int v, int w); // function to add an edge to graph
    int isReachable(int s, int d); // returns true if there is a path from s to d
};

SafeMap::SafeMap(int V)
{
    this->V = V;
    adj = new list<int> [V];
}

void SafeMap::addSafeRoute(int v, int w)
{
    adj[v].push_back(w); // Add w to v's list.
}

// Function to check if S is safely reachable from D
int SafeMap::isReachable(int s, int d)
{
    vector<int> path;
    vector<int> adj;
    int dist[V],pred[V];
    // Mark all the vertices as not visited
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
    {
        visited[i] = false;
        dist[i] = INT_MAX;
        pred[i] = -1;
    }
    list<int> queue;

    // Mark the current node as visited and enqueue it
    visited[s] = true;
    dist[s] = 0;
    queue.push_back(s);

    // it will be used to get all adjacent vertices of a vertex accesible thru
    // a safe route
    list<int>::iterator i;

    //Write your code below this line

    //standard bfs algorithm
    while (!queue.empty())
    {
        // Dequeue a vertex from queue and print it
        s = queue.front();
        queue.pop_front();

        // Get all adjacent vertices of the dequeued vertex s
        // If a adjacent has not been visited, then mark it visited
        // and enqueue it
        for (i = adj[s].begin(); i != adj[s].end(); i++) {
            // If this adjacent node is the destination node, then return true
            if (*i == d) {
                //vector path stores the shortest path

                int crawl = d;
                path.push_back(crawl);
                while (pred[crawl] != -1) {
                    path.push_back(pred[crawl]);
                    crawl = pred[crawl];
                    int z = path.size();
                    return z;
                }

                // Else, continue to do BFS
                if (!visited[*i])
                {
                    visited[*i] = true;
                    queue.push_back(*i);
                }

            }
        }

    return false;


}
int main() {
    // Create a graph given in the above diagram
    SafeMap g(10);
    g.addSafeRoute(7,4);
    g.addSafeRoute(6,8);
    g.addSafeRoute(0,2);
    g.addSafeRoute(2,5);
    g.addSafeRoute(7,5);
    g.addSafeRoute(9,6);
    g.addSafeRoute(8,7);
    g.addSafeRoute(6,6);
    g.addSafeRoute(8,5);
    g.addSafeRoute(7,7);
    cout << "Enter the source and destination vertices:";
    int u, v;
    cin >> u >> v;
    /*if (g.isReachable(u, v))
        cout << "\nThere is a path from " << u << " to " << v;
    else
        cout << "\nThere is no path from " << u << " to " << v;
    i=g.isReachable(u, v);
    cout<<"length -> "<<i;

    int temp;
    temp = u;
    u = v;
    v = temp;
    if (g.isReachable(u, v))
        cout << "\nThere is a path from " << u << " to " << v;
    else
        cout << "\nThere is no path from " << u << " to " << v;
    i=g.isReachable(u, v);
    cout<<"length -> "<<i;*/

    // distance from source is in distance array
    cout << "Shortest path length is : "
         << dist[d];

    // printing path from source to destination
    cout << "\nPath is::\n";
    for (int i = path.size() - 1; i >= 0; i--)
        cout << path[i] << " ";
    return 0;
}