#include "Graph.hpp"
using namespace std;

template<typename T>
class Graph {
public:
    vector<vector<Vertex<T> > > adjacList;
    vector<Vertex<T> > path_nodes;
    vector<Vertex<T> > src_nodes;

    // graph constructor takes list of edges and the number of nodes in DAG
    Graph<T>(vector<Edge<T> > const &edges, int nonodes) {
        adjacList.resize(nonodes);
        src_nodes.resize(nonodes/2);
        path_nodes.resize(nonodes/2);
        for (auto &edge: edges) {
            int i;;
            adjacList[edge.src.nodename].push_back(edge.path.nodename);

            src_nodes[i] = edge.src.nodename;
            path_nodes[i] = edge.path.nodename;
            i++;
        }
    }


    //default constructor of creation of graph
    Graph<T>() {

    }
};

// returning edges
template<typename T>
void returnEdges(Graph<T> const &graph, int n) {
    for (T i = 0; i < n; i++) {
        cout << "Vertex \t" << i << " --> ";

        for (Vertex<T> v: graph.adjacList[i]) {
            cout << v.nodename << "\t";
        }
        cout << endl;
    }
}

//destroy edges
void clearEdges(vector<Edge<int> > list){
    list.clear();
}


template<typename T>
//  Depth first traversal search algorithm applied to the DAG
int DFS(Graph<T> const &graph, int &time_comp, int n, vector<int> &leaving, vector<bool> & arrived) {

    arrived[n] = true; // mark currently on as marked

    for (Vertex<T> a: graph.adjacList[n]) {
        // enter if algorithm has not  yet reached node a
        if (!arrived[a.nodename]) { //
            DFS(graph, time_comp, a.nodename, leaving, arrived);
        }
    }

    leaving[n] = time_comp++; // set leaving time of vertex n

}



template<typename T>
// Returns true if given directed graph is DAG //checking for cycles
bool isgraphDAG(Graph<T> const &graph, int n) {
    vector<bool> arrived(n);
    vector<int> leaving(n);

    // Performing DFS traversal for all unvisited nodes in the graph

    int time_comp;
    int i;
    for (i = 0; i < n; i++) {
        if (!arrived[i]) {
            DFS(graph, time_comp, i, leaving, arrived);
        }
    }
    // check if the given directed graph is DAG or not
    for (int j = 0; j < n; j++) {
        // check if edge(j, v) forms a back-edge if true it would indicate a cycle in the DAG.
        for (Vertex<T> v: graph.adjacList[j]) {
            if (leaving[j] <= leaving[v.nodename]) {
                return (false); //return false if back edges are found
            }
        }
    }
    return true; //return true if no back edges are found
}
