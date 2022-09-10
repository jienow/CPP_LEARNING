//
// Created by jienow on 2022/9/8.
//

//#include <algorithm>
//#include <iostream>
// using namespace std;
// typedef struct Node {
//    int elem;
//    struct Node *next;
//} node;
//
// class Iterator {
//  private:
//    node *p;
//
//  public:
//    Iterator() : p(0) {}
//    Iterator(node *ptr) : p(ptr) {}
//    int operator*() { return p->elem; }
//    Iterator &operator++() {
//        p = p->next;
//        return *this;
//    }
//    Iterator operator++(int) {
//        Iterator tmp = *this;
//        p = p->next;
//        return tmp;
//    }
//    int operator!=(int val){
//        return p->elem != val;
//    }
//
//};
//
// Iterator find_ll(Iterator head, const int &val) {
//    Iterator start;
//    for (start = head; start != 0; ++start)
//        if (*start == val)
//            return start;
//    return 0;
//}
// int main() {
//    Node a{1};
//    Node b{2};
//    a.next = &b;
//    Iterator c{&a};
//    Iterator d{&b};
//
//    Iterator g = find_ll(c,2);
//    cout << *g;
//    return 0;
//}

#include <iostream>
using namespace std;
template <class T> class List {
  private:
    T val;
    List *next;
    size_t size_ = 0;

  public:
    List() : val(0), next(nullptr) { size_++; }
    List(const T val) : val(val), next(nullptr) { size_++; }
    List(List &&n) : val(n.val), next(n.next) { size_++; }
    List(const T val, List *next) : val(val), next(next) { size_++; }
    ~List() { delete next; }
    size_t size() { return size_; }
    void push_back(T val) {
        List *p = this;
        while (p->next != nullptr) {
            p = p->next;
        };
        p->next = new List<T>{val};
        size_++;
    }
};
template <class T> class iterator {
  private:
    List<T> *p;

  public:
    iterator() : p(0) {}
    iterator(List<T> *p) : p(p) {}
    T operator*() { return p->val; }
    iterator &operator++() {
        p = p->next;
        return *this;
    }
    iterator operator++(int) {
        iterator tmp = *this;
        p = p->next;
        return *tmp;
    }
    bool operator!=(const T val) { return p->val != val; }
    void push_back(T val) {
        List *p = this;
        while (p->next != nullptr) {
            p = p->next;
        };
        p->next = new List<T>{val};
        size_++;
    }
};
int main() {
    cout << "hello world";
    iterator i;
    i.
    return 0;
}
