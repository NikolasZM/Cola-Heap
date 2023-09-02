#include <iostream>
using namespace std;

template<class T>
class Nodo {
public:
    T valor;
    Nodo<T>* next;

    Nodo(T v, Nodo<T>* n = nullptr);
};

template<class T>
Nodo<T>::Nodo(T v, Nodo<T>* n) {
    valor = v;
    next = n;
}

template<class T>
class Cola {
public:
    Nodo<T>* head;
    Nodo<T>* tail;
    Cola();
    void push(T v);
    bool pop(T& v);
};

template<class T>
Cola<T>::Cola() {
    head = nullptr;
    tail = nullptr;
}

template<class T>
void Cola<T>::push(T v) {
    if (!tail) {
        tail = new Nodo<T>(v, tail);
    }
    else {
        tail->next = new Nodo<T>(v, tail->next);
        tail = tail->next;
    }

    if (!head) {
        head = tail;
    }
}

template<class T>
bool Cola<T>::pop(T& v) {
    if (head) {
        Nodo<T>* tmp;
        tmp = head;
        v = head->valor;
        head = head->next;
        delete tmp;
        if (!head) {
            tail = head;
        }
        return true;
    }
    else {
        cout << "Lista vacia.\n";
        return false;
    }

}

int main()
{
    Cola<int> Lista1;

    Lista1.push(54);
    Lista1.push(55);
    Lista1.push(56);
    int v;
    if (Lista1.pop(v)) {
        cout << v;
    }

    if (Lista1.pop(v)) {
        cout << v;
    }
    if (Lista1.pop(v)) {
        cout << v;
    }
    if (Lista1.pop(v)) {
        cout << v;
    }

    Lista1.push(7);
    Lista1.push(8);
    Lista1.push(53);
    
    if (Lista1.pop(v)) {
        cout << v;
    }
    
    if (Lista1.pop(v)) {
        cout << v;
    }
    
    if (Lista1.pop(v)) {
        cout << v;
    }
    
    if (Lista1.pop(v)) {
        cout << v;
    }
}