

#include <ostream>
#include <stdexcept>
#include "List.h"

template <typename T>
class ListArray;

template <typename T>
std::ostream& operator<<(std::ostream& out, const ListArray<T>& list);

template <typename T>
class ListArray : public List<T> {
private:
    T*  arr;                     
    int max;                     
    int n;                       
    static const int MINSIZE = 2; 

    void resize(int new_size) {
        if (new_size < n) new_size = n;
        if (new_size < MINSIZE) new_size = MINSIZE;

        T* new_arr = new T[new_size];
        for (int i = 0; i < n; ++i) {
            new_arr[i] = arr[i];
        }
        delete[] arr;
        arr = new_arr;
        max = new_size;
    }

public:
    ListArray() : arr(new T[MINSIZE]), max(MINSIZE), n(0) {}


    ~ListArray() override {
        delete[] arr;
    }

    void insert(int pos, const T& e) override {
        if (pos < 0 || pos > n) {
            throw std::out_of_range("insert: pos fuera de rango");
        }
        if (n == max) {
            int new_cap = (max < MINSIZE) ? MINSIZE : max * 2;
            resize(new_cap);
        }

        for (int i = n - 1; i >= pos; --i) {
            arr[i + 1] = arr[i];
        }
        arr[pos] = e;
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
        T value = arr[pos];

        for (int i = pos; i < n - 1; ++i) {
            arr[i] = arr[i + 1];
        }
        --n;


        if (max > MINSIZE && n <= max / 4) {
            int new_cap = max / 2;
            if (new_cap < MINSIZE) new_cap = MINSIZE;
            resize(new_cap);
        }

        return value;
    }


    T get(int pos) const override {
        if (pos < 0 || pos >= n) {
            throw std::out_of_range("get: pos fuera de rango");
        }
        return arr[pos];
    }


    int search(const T& e) const override {
        for (int i = 0; i < n; ++i) {
            if (arr[i] == e) return i;
        }
        return -1;
    }


    bool empty() const override {
        return n == 0;
    }


    int size() const override {
        return n;
    }

    T operator[](int pos) {
        if (pos < 0 || pos >= n) {
            throw std::out_of_range("operator[]: pos fuera de rango");
        }
        return arr[pos];
    }


    T operator[](int pos) const {
        if (pos < 0 || pos >= n) {
            throw std::out_of_range("operator[] const: pos fuera de rango");
        }
        return arr[pos];
    }


    friend std::ostream& operator<< <T>(std::ostream& out, const ListArray<T>& list);
};


template <typename T>
std::ostream& operator<<(std::ostream& out, const ListArray<T>& list) {
    out << "[";
    for (int i = 0; i < list.n; ++i) {
        if (i) out << ", ";
        out << list.arr[i];
    }
    out << "]";
    return out;
}


