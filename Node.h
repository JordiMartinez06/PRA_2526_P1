#include <ostream>

template <typename T>
class Node;

template <typename T>
std::ostream& operator<<(std::ostream& out, const Node<T>& node);

template <typename T>
class Node {
public:
    T data;
    Node<T>* next;

    explicit Node(T data, Node<T>* next = nullptr)
        : data(data), next(next) {}

    friend std::ostream& operator<< <T>(std::ostream& out, const Node<T>& node);
};

template <typename T>
std::ostream& operator<<(std::ostream& out, const Node<T>& node) {
    out << node.data;
    return out;
}

