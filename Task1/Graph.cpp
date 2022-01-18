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

