#include <ostream>
#include <stdexcept>
#include "List.h"
#include "Node.h"


template <typename T>
class ListLinked;

template <typename T>
std::ostream& operator<<(std::ostream& out, const ListLinked<T>& list);

template <typename T>
class ListLinked : public List<T> {
private:
    Node<T>* first;
    int      n;

    Node<T>* get_node(int pos) const {
        Node<T>* curr = first;
        for (int i = 0; i < pos; ++i) {
            curr = curr->next;
        }
        return curr;
    }

public:
    ListLinked() : first(nullptr), n(0) {}

    ~ListLinked() override {
        Node<T>* curr = first;
        while (curr != nullptr) {
            Node<T>* aux = curr->next;
            delete curr;
            curr = aux;
        }
        first = nullptr;
        n = 0;
    }

    void insert(int pos, const T& e) override {
        if (pos < 0 || pos > n) {
            throw std::out_of_range("insert: pos fuera de rango");
        }
        if (pos == 0) {
            first = new Node<T>(e, first);
               } else {
            Node<T>* prev = get_node(pos - 1);
            prev->next = new Node<T>(e, prev->next);
        }
        ++n;
    }

    void append(const T& e) override {
        insert(n, e);
    }

    void prepend(const T& e) override {
        insert(0, e);
    }

    T remove(int pos) override {
        if (pos < 0 || pos >= n) {
            throw std::out_of_range("remove: pos fuera de rango");
        }

        T value;
        if (pos == 0) {
            Node<T>* target = first;
            value = target->data;
            first = target->next;
            delete target;
        } else {
            Node<T>* prev   = get_node(pos - 1);
            Node<T>* target = prev->next;
            value = target->data;
            prev->next = target->next;
            delete target;
        }
        --n;
        return value;
    }


    T get(int pos) const override {
        if (pos < 0 || pos >= n) {
            throw std::out_of_range("get: pos fuera de rango");
        }
        return get_node(pos)->data;
    }

    int search(const T& e) const override {
        int idx = 0;
        for (Node<T>* curr = first; curr != nullptr; curr = curr->next, ++idx) {
            if (curr->data == e) {
                return idx;
            }
        }
        return -1;
    }
 
    bool empty() const override { return n == 0; }

    int size() const override { return n; }

    T operator[](int pos) {
        if (pos < 0 || pos >= n) {
            throw std::out_of_range("operator[]: pos fuera de rango");
        }
        return get_node(pos)->data;
    }

    T operator[](int pos) const {
        if (pos < 0 || pos >= n) {
            throw std::out_of_range("operator[] const: pos fuera de rango");
        }
        return get_node(pos)->data;
    }

    friend std::ostream& operator<< <T>(std::ostream& out, const ListLinked<T>& list);
};


template <typename T>
std::ostream& operator<<(std::ostream& out, const ListLinked<T>& list) {
    out << "[";
    int i = 0;
    for (Node<T>* curr = list.first; curr != nullptr; curr = curr->next, ++i) {
        if (i) out << ", ";
        out << curr->data;
    }
    out << "]";
    return out;
}


