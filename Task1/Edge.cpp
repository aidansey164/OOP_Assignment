using namespace std;

template<typename T>
class Edge {
public:
    Vertex<T> src, path;

    Edge<T>(Vertex<T> src, Vertex<T> path) {  // paramterised constructor
        this->src = Vertex<T>(src);
        this->path = Vertex<T>(path);
    }

    Edge<T>() {  // default constructor

    }
};