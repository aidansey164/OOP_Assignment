template<typename T>
class Vertex {
public:
    T nodename;

    /* constructor with parameters */
    Vertex<T>(T nodename) {
        this->node_id = nodename;
    }
    /* default constructor for vertex construction */
    Vertex<T>() {

    }
};