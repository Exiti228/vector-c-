#include<iostream>
#include<vector>
#include<algorithm>

template <class T>
class Vector{
public:
    Vector();
    Vector(unsigned int size);
    Vector(unsigned int size, const T& init);
    Vector(const Vector<T> &V);
    ~Vector();

    T* begin();
    T* end();
    void push_back(const T& value);
    void pop_back();
    void resize(unsigned int size);
    void resize(unsigned int size, T value);
    unsigned int size() const;
    unsigned int capacity() const;
    void clear();
    T& operator[](unsigned int index);
    Vector<T> & operator=(const Vector<T> &);
    void swap(T& x, T& y);
private:
    unsigned int sz;
    unsigned int cp;
    T* buffer;

};
template <class T>
void swap(T& x, T& y) {
    T tmp { std::move(x) };
    x = std::move(y);
    y = std::move(tmp);
}

template <class T>
unsigned int Vector<T>::size() const {
    return sz;
}

template <class T>
unsigned int Vector<T>::capacity() const {
    return cp;
}

template <class T>
Vector<T>::~Vector() {
    delete[] buffer;
}
template <class T>
Vector<T>::Vector() {
    cp = 0;
    sz = 0;
    buffer = nullptr;
}

template <class T>
Vector<T>::Vector(unsigned int size) {
    sz = size;
    cp = size;
    buffer = new T[size];

}

template <class T>
Vector<T>::Vector(unsigned int size, const T& init) {
    sz = size;
    cp = size;
    buffer = new T[size];
    for (unsigned int i = 0; i < size; ++i)
        buffer[i] = init;
}
template <class T>
Vector<T>::Vector(const Vector<T> &V) {
    cp = V.cp;
    sz = V.sz;
    buffer = new T[cp];
    for (unsigned int i = 0; i < V.size(); ++i)
        buffer[i] = V.buffer[i];
}

template <class T>
Vector<T> & Vector<T>::operator = (const Vector<T> &V) {
    delete[] buffer;
    sz = V.sz;
    cp = V.cp;
    buffer = new T[V.cp];
    for (unsigned int i = 0; i < V.sz; ++i)
        buffer[i] = V.buffer[i];
    return *this;
}

template<class T>
T* Vector<T>::begin()
{
    return buffer;
}

template<class T>
T* Vector<T>::end()
{
    return buffer + size();
}

template <class T>
void Vector<T>::resize(unsigned int size, T value) {
    if (size > cp) {

        if (size > 2 * cp)
            cp = size;
        else
            cp = 2 * cp;

        T* buf = new T[cp];
        for (int i = 0; i < sz ; ++i)
            buf[i] = buffer[i];
        for (int i = sz; i < cp; ++i)
            buf[i] = value;
        delete[] buffer;
        buffer = buf;

        sz = size;

    }
    else {
        sz = size;
    }

}

template <class T>
void Vector<T>::resize(unsigned int size) {
    if (size > cp) {

        if (size > 2 * cp)
            cp = size;
        else
            cp = 2 * cp;

        T* buf = new T[cp];
        for (int i = 0; i < sz ; ++i)
            buf[i] = buffer[i];
        delete[] buffer;
        buffer = buf;
        sz = size;

    }
    else {
        sz = size;
    }
}
template <class T>
void Vector<T>::push_back(const T& value) {
    if (sz < cp) {
        buffer[sz++] = value;
    }
    else {
        cp = 2 * cp;
        T* buf = new T[cp];
        for (int i = 0; i < sz; ++i) {
            buf[i] = buffer[i];
        }
        buf[sz++] = value;
        delete[] buffer;
        buffer = buf;

    }
}

template <class T>
void Vector<T>::pop_back() {
    if (sz >= 1) {
        sz--;
    }
    else {
        std::cout << "Vector is empty!\n";

    }
}

template <class T>
void Vector<T>::clear() {
    sz = 0;
}

template<class T>
T& Vector<T>::operator[](unsigned int index)
{
    return buffer[index];
}
int main() {
    Vector<int> a = Vector<int>(5, 2);
    a.resize(7, 3);
    a.resize(3);
    a.push_back(4);
    a.push_back(54);
    a.pop_back();
    Vector<int> b = Vector<int>(3, -1);
    swap(a, b);
    for (int i = 0; i < a.size(); ++i)
        std::cout << a[i] << std::endl;
}
