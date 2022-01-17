using namespace std;

template<typename T>
class Graph {
public:
    vector<vector<Vertex<T> > > adjacList;
    vector<Vertex<T> > src_nodes;
    vector<Vertex<T> > path_nodes;

    // param constructor for graph that takes a list of edges and the number of nodes in the DAG
    Graph<T>(vector<Edge<T> > const &edges, int no_of_nodes) {

    }

    Graph<T>() {  // default constructor

    }
};


