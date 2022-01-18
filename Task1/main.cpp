using namespace std;
#include "Graph.hpp"
#include "Graph.cpp"

int main() {


    Vertex<int> *vertex1 = new Vertex<int>(0);
    Vertex<int> *vertex2 = new Vertex<int>(1);
    Vertex<int> *vertex3 = new Vertex<int>(2);


    Edge<int> *e1 = new Edge<int>(*vertex1, *vertex2);
    Edge<int> *e2 = new Edge<int>(*vertex2, *vertex3);
    Edge<int> *e3 = new Edge<int>(*vertex3, *vertex1);

    vector<Edge<int> > edgeList;
    edgeList.push_back(*e1);
    edgeList.push_back(*e2);
    edgeList.push_back(*e3);
    int n = 3;
    Graph<int> g(edgeList, n);

    if(!isgraphDAG(g, n)){
        cout << "It's not an acyclic graph" << endl;
        return 0;
    }


    return 0;
}
