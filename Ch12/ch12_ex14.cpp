/*
 * @Author: seenli
 * @Date: 2021-01-22 14:15:56
 * @LastEditors: seenli
 * @LastEditTime: 2021-01-22 14:53:03
 * @FilePath: \Ch12\ch12_ex14.cpp
 * @Description: Programming Principles and Practice Using C++ Second Edition
 */

// Chapter 12, exercise 14: complete the "list of gods" example from 12.10.1,
// but this time as a singly-linked list


#include "../includes/std_lib_facilities.h"

struct List;

class Link {
    public:
        string value;
        
        Link(const string& v, Link* s = 0)
            : value(v), succ(s) {}

        Link* insert(List& l, Link* n);                                 // 在this object前插入n
        Link* add(Link* n);                                             // 在this object后插入n
        Link* erase(List& l);                                           // 将this object从list中删除
        Link* find(const List& l, const string& s);                     // find s in list
        const Link* find(const List& l, const string& s) const;         // find s in list
        Link* advance(int n) const;                                     // 在list中移动n步
        Link* next() const {return succ;}
    private:
        Link* succ;
};

struct List {
    List(): first_link(0) {}
    List(Link* l): first_link(l) {}
    Link* first_link;
};

// 在this object前插入n
Link* Link::insert(List& l, Link* n) {
    if (n == 0) return this;
    if (this == 0) return n;
    n->succ = this;
    if (l.first_link == this) {
        l.first_link = n;
        return n;
    }
    Link* p = l.first_link;
    while (p->succ != this) {
        p = p->succ;
    }
    p->succ = n;
    return n;
}

// 在this object后插入n
Link* Link::add(Link* n) {
    if (n == 0) return this;
    if (this == 0) return n;
    n->succ = succ;
    succ = n;
    return n;
}

// 删除该节点返回后继节点
Link* Link::erase(List& l) {
    if (this == 0) return 0;
    if (l.first_link == this) {
        l.first_link = succ;
    }
    Link* p = l.first_link;
    while (p->succ != this) {
        p = p->succ;
    }
    p->succ = succ;
    return succ;
}

// find s in list; return 0 for "not found"
Link* Link::find(const List& l, const string& s) {
    Link* p = l.first_link;
    while (p) {
        if (p->value == s) return p;
        p = p->succ;
    }
    return 0;
}

// find s in const list; return 0 for "not found"
const Link* Link::find(const List& l, const string& s) const{
    const Link* p = l.first_link;
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
    if (n >= 0) {
        while (n--) {
            if (p->succ == 0) return 0;
            p = p->succ;
        }
    } else {
        error("must advance by a positive number");
    }
    return p;
}

void print_all(const List& l) {
    cout << "{ ";
    Link* p = l.first_link;
    while (p) {
        cout << p->value;
        if (p = p->next()) cout << ", ";
    }
    cout << "} ";
}

int main()
try {
    Link* norse_gods = new Link("Thor");
    List n_gods(norse_gods);
    norse_gods = norse_gods->insert(n_gods, new Link("Odin"));
    norse_gods = norse_gods->insert(n_gods, new Link("Zeus"));
    norse_gods = norse_gods->insert(n_gods, new Link("Freia"));

    Link* greek_gods = new Link("Hera");
    List g_gods(greek_gods);
    greek_gods = greek_gods->insert(g_gods, new Link("Athena"));
    greek_gods = greek_gods->insert(g_gods, new Link("Mars"));
    greek_gods = greek_gods->insert(g_gods, new Link("Poseidon"));
    
    Link* p = norse_gods->find(n_gods, "Zeus");
    if (p) {
        if (p == norse_gods) norse_gods = p->next();
        p->erase(n_gods);
        greek_gods = greek_gods->add(p);
        greek_gods = g_gods.first_link;
    }

    Link* p2 = greek_gods->find(g_gods, "Mars");
    if (p2) p2->value = "Ares";

    print_all(n_gods);
    cout << endl;

    print_all(g_gods);
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
