/*
 * @Author: seenli
 * @Date: 2021-01-22 11:19:39
 * @LastEditors: seenli
 * @LastEditTime: 2021-01-22 12:56:34
 * @FilePath: \Ch12\ch12_ex11.cpp
 * @Description: Programming Principles and Practice Using C++ Second Edition
 */

// Chapter 12, exercise 11: complete the "list of gods" example from 12.10.1
// (doubly-linked list)

#include "../includes/std_lib_facilities.h"

class Link {
    public:
        string value;
        
        Link(const string& v, Link* p = 0, Link* s = 0)
            : value(v), prev(p), succ(s) {}

        Link* insert(Link* n);                      // 在this object前插入n
        Link* add(Link* n);                         // 在this object后插入n
        Link* erase();                              // 将this object从list中删除
        Link* find(const string& s);                // find s in list
        const Link* find(const string& s) const;    // find s in const list
        Link* advance(int n) const;                 // 在list中移动n步
        Link* next() const {return succ;}
        Link* previous() const {return prev;}
    private:
        Link* prev;
        Link* succ;
};

// 在this object前插入n
Link* Link::insert(Link* n) {
    if (n == 0) return this;
    if (this == 0) return n;
    n->succ = this;
    if (prev) prev->succ = n;
    n->prev = prev;
    prev = n;
    return n;
}

// 在this object后插入n
Link* Link::add(Link* n) {
    if (n == 0) return this;
    if (this == 0) return n;
    n->prev = this;
    if (succ) succ->prev = n;
    n->succ = succ;
    succ = n;
    return n;
}

// 删除该节点返回后继节点
Link* Link::erase() {
    if (this == 0) return 0;
    if (succ) succ->prev = prev;
    if (prev) prev->succ = succ;
    return succ;
}

// find s in list; return 0 for "not found"
Link* Link::find(const string& s) {
    Link* p = this;
    while (p) {
        if (p->value==s) return p;
        p = p->succ;
    }
    return 0;
}

// find s in const list; return 0 for "not found"
const Link* Link::find(const string& s) const{
    const Link* p = this;
    while (p) {
        if (p->value == s) return p;
        p = p->succ;
    }
    return 0;
}

// move n positions in list, return 0 for "not found"
// positive n moves forward, negative backward
Link* Link::advance(int n) const {
    if (this == 0) return 0;
    Link* p = const_cast<Link*>(this);
    if (n > 0) {
        while (n--) {
            if (p->succ == 0) return 0;
            p = p->succ;
        }
    } else if (n < 0) {
        while (n++) {
            if (p->prev == 0) return 0;
            p = p->prev;
        }
    }
    return p;
}

void print_all(Link* p) {
    cout << "{ ";
    while (p) {
        cout << p->value;
        if (p = p->next()) cout << ", ";
    }
    cout << "} ";
}

int main()
try {
    Link* norse_gods = new Link("Thor");
    norse_gods = norse_gods->insert(new Link("Odin"));
    norse_gods = norse_gods->insert(new Link("Zeus"));
    norse_gods = norse_gods->insert(new Link("Freia"));

    Link* greek_gods = new Link("Hera");
    greek_gods = greek_gods->insert(new Link("Athena"));
    greek_gods = greek_gods->insert(new Link("Mars"));
    greek_gods = greek_gods->insert(new Link("Poseidon"));
    
    Link* p = greek_gods->find("Mars");
    if (p) p->value = "Ares";

    Link* p2 = norse_gods->find("Zeus");
    if (p2) {
        if (p2 == norse_gods) norse_gods = p2->next();
        p2->erase();
        greek_gods = greek_gods->add(p2)->advance(-1);
    }

    print_all(norse_gods);
    cout << endl;

    print_all(greek_gods);
    cout << endl;
    system("pause");
    return 0;
}
catch (exception& e) {
	cerr << "exception: " << e.what() << endl;
	keep_window_open();
	return 1;
}
catch (...) {
	cerr << "exception\n";
	keep_window_open();
	return 2;
}
