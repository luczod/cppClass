// C++ program to illustrate the begin and end iterator
#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
#include <deque>
#include <string>

using namespace std;

class Graph {
    // Adjacency matrix to store graph edges
    // vector<vector<int> > adj_matrix;
    // map<string, deque<string>> adj_matrix;
   unordered_map<string, deque<string>> adj_matrix;

public:
    // Constructor to initialize the graph with 'n' vertices
    Graph() {}

    // Function to add an edge between vertices 'u' and 'v'
    // of the graph
    void add_edge(string u, deque<string> v)
    {
        // Set edge
        adj_matrix[u]= v;
    }

    // Function to print the adjacency matrix representation
    // of the graph
    void display(){
        unordered_map<string, deque<string>>::iterator it = adj_matrix.begin();
        // Iterate through the map and print the elements it->second
        while (it != adj_matrix.end()) {
            cout << " " << it->first;

            cout << ": [";
            for (auto& x: it->second){
                cout << " " << x;
            }
            cout << " ]\n";

            ++it;
        }

    }

};


int main()
{
    // Create a map of strings to integers
    Graph graph;

    // Insert some values into the map
    graph.add_edge("you", {"alice", "claire", "bob"});
    graph.add_edge("bob", {"anuj", "peggy"});
    graph.add_edge("alice", {"peggy"});
    graph.add_edge("claire", {"thom", "jonny"});
    graph.add_edge("anuj", {});
    graph.add_edge("peggy", {});
    graph.add_edge("thom", {});
    graph.add_edge("jonny", {});
    // Get an iterator pointing to the first element in the
    // map
    graph.display();

    return 0;
}
