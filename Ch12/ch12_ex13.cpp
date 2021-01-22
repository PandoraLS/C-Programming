/*
 * @Author: seenli
 * @Date: 2021-01-22 13:04:22
 * @LastEditors: seenli
 * @LastEditTime: 2021-01-22 14:05:21
 * @FilePath: \Ch12\ch12_ex13.cpp
 * @Description: Programming Principles and Practice Using C++ Second Edition
 */

// Chapter 12, exercise 13: modify Link class to hold a value of struct God with
// string members name, mythology, vehicle and weapon. Write print_all()
// function that lists gods with attributes one per line. Add member function
// add_ordered() that places its new element it its correct lexicographic
// position. Make list of gods from three mythologies, then move elements to
// three ordered lists, one per mythology.

#include "../includes/std_lib_facilities.h"

struct God {
    God(const string& n, const string& m, const string& v, const string& w)
        : name(n), mythology(m), vehicle(v), weapon(w) {}
    string name;
    string mythology;
    string vehicle;
    string weapon;
};

ostream& operator<<(ostream& os, const God& g) {
    os << g.name << ", " << g.mythology << ", ";
    os << g.vehicle << ", " << g.weapon;
    return os;
}

class Link {
    public:
        God value;
        
        Link(const string& n, const string& m, const string& v, const string& w, Link* p = 0, Link* s = 0)
            : value(n, m, v, w), prev(p), succ(s) {}

        Link* insert(Link* n);                      // 在this object前插入n
        Link* add(Link* n);                         // 在this object后插入n
        Link* add_ordered(Link* n);                 // 将节点n插入字典正确的位置
        Link* erase();                              // 将this object从list中删除
        Link* find(const string& s);                // find s in list
        const Link* find(const string& s) const;    // find s in const list
        Link* advance(int n);                 // 在list中移动n步
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

// 将n插入其字典正确的位置, 返回list的第一个元素
Link* Link::add_ordered(Link* n) {
    if (n == 0) return this;
    if (this == 0) {                                    // 新list
        n->succ = 0;
        n->prev = 0;
        return n;
    }
    if (n->value.name < value.name) {
        Link* p = insert(n);                            // 第一个element已经改变
        return p;
    }
    Link* p = this;
    while (n->value.name >= p->value.name) {
        if (p->succ == 0) {                              // last element reached
            p->add(n);                                  // attach to end of list
            return this;                                // first element has not changed
        }
        p = p->succ;
    }
    p->insert(n);
    return this;
}

// 删除该节点返回后继节点
Link* Link::erase() {
    if (this == 0) return 0;
    if (succ) {
        if (prev) succ->prev = prev;
        else succ->prev = 0;
    }
    if (prev) {
        if (succ) prev->succ = succ;
        else prev->succ = 0;
    }
    return succ;
}

// find s in list; return 0 for "not found"
Link* Link::find(const string& s) {
    Link* p = this;
    while (p) {
        if (p->value.name == s) return p;
        p = p->succ;
    }
    return 0;
}

// find s in const list; return 0 for "not found"
const Link* Link::find(const string& s) const{
    const Link* p = this;
    while (p) {
        if (p->value.name == s) return p;
        p = p->succ;
    }
    return 0;
}

// move n positions in list, return 0 for "not found"
// positive n moves forward, negative backward
Link* Link::advance(int n) {
    if (this == 0) return 0;
    Link* p = this;
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
    while (p) {
        cout << p->value;
        if (p=p->next()) cout << "\n";
    }
}

//查找l中名称为s的Link，从l中删除它，返回指向它的指针
//如果元素是列表中的最后一个元素，则l不设置为0
Link* extract(Link* l, string s) {
    Link* p = l->find(s);
    if (p) {
        if (p == l && p->next()) l = p->next();
        else l = 0;
        p->erase();
        return p;
    }
    return 0;                       // 未发现s
}

int main()
try {
    Link* all_gods = new Link("Thor","Norse","Pinzgauer","Hammer");
    all_gods = all_gods->insert(new Link("Odin","Norse","Eight-legged horse",""));
    all_gods = all_gods->insert(new Link("Zeus","Greek","","Lightning"));
    all_gods = all_gods->insert(new Link("Freia","Norse","F-transport","F-weapon"));
    all_gods = all_gods->insert(new Link("Hera","Greek","H-transport","Spear"));
    all_gods = all_gods->insert(new Link("Athena","Greek","A-transport","A-weapon"));
    all_gods = all_gods->insert(new Link("Mars","Roman","M-transport","M-weapon"));
    all_gods = all_gods->insert(new Link("Poseidon","Greek","Seahorse","Trident"));
    all_gods = all_gods->insert(new Link("Ares","Greek","A-transport","A-weapon"));
    all_gods = all_gods->insert(new Link("Vesuvius","Roman","V-transport","Volcano"));
    all_gods = all_gods->insert(new Link("Bacchus","Roman","Stretcher","Wine goblet"));

    print_all(all_gods);

    Link* norse_gods = 0;
    norse_gods = norse_gods->add_ordered(extract(all_gods,"Odin"));
    norse_gods = norse_gods->add_ordered(extract(all_gods,"Thor"));
    norse_gods = norse_gods->add_ordered(extract(all_gods,"Freia"));

    Link* greek_gods = 0;
    greek_gods = greek_gods->add_ordered(extract(all_gods,"Hera"));
    greek_gods = greek_gods->add_ordered(extract(all_gods,"Athena"));
    greek_gods = greek_gods->add_ordered(extract(all_gods,"Poseidon"));
    greek_gods = greek_gods->add_ordered(extract(all_gods,"Zeus"));
    greek_gods = greek_gods->add_ordered(extract(all_gods,"Ares"));

    Link* roman_gods = 0;
    roman_gods = roman_gods->add_ordered(extract(all_gods,"Mars"));
    roman_gods = roman_gods->add_ordered(extract(all_gods,"Vesuvus"));
    roman_gods = roman_gods->add_ordered(extract(all_gods,"Bacchus"));

    // could delete all_gods here, but that leads to a mess

    cout << "\n\nNorse gods:\n";
    print_all(norse_gods);
    cout << "\n\nGreek gods:\n";
    print_all(greek_gods);
    cout << "\n\nRoman gods:\n";
    print_all(roman_gods);
    cout << "\n";

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
