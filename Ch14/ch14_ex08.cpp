/*
 * @Author: seenli
 * @Date: 2021-01-27 09:41:06
 * @LastEditors: seenli
 * @LastEditTime: 2021-01-27 11:27:47
 * @FilePath: \Ch14\ch14_ex08.cpp
 * @Description: Programming Principles and Practice Using C++ Second Edition
 */

// Chapter 14
// Exercise 08: implement an allocator (14.3.6) using malloc() and
// free() (B.10.4); get vector as defined by the end of 14.3 to work for a few
// simple test cases. Hint: look up "placement new" and "explicit call of
// destructor"

// Exercise 09: re-implement vector::operator=() using an allocator - well, that
// seems to be kind of part of "get vector to work", right?


#include "../includes/std_lib_facilities.h"

template<class T> struct S {
    S(): i(0), d(0), c(0), s(""), t(T()) {}
    S(int ii, double dd, char cc, const string& ss, const T& tt)
        : i(ii), d(dd), c(cc), s(ss), t(tt) { }
    int i;
    double d;
    char c;
    string s;
    T t;
};

template<class T> ostream& operator<<(ostream& os, S<T> s) {
    os << s.i << ' ' << s.d << ' ' << s.c << ' ' << s.s << ' ' << s.t;
}

template<class T> class allocatr {
    public:
        // Ϊn������T�Ķ������ռ�
        T* allocate(int n);

        // �ͷŴ�p��ʼ��n������T�Ķ���
        void deallocate(T* p) {free(p);}

        // ��p�й���һ��ֵΪv��T
        void construct(T* p, const T& v) { new(p) T(v);}

        // ��p�е�T�ͷ�
        void destroy(T* p) {p->~T();}
};

// Ϊn������T�Ķ������ռ�
template<class T> T* allocatr<T>::allocate(int n) {
    T* p = static_cast<T*>(malloc(n * sizeof(T)));
    if (p == 0) error("alloate: could not allocate memory");
    return p;
}

template<class T, class A = allocatr<T>> class vectr {
    A alloc;                                    // ���ڴ���Ԫ�ص��ڴ�
    int sz;                                     // the size
    T* elem;                                    // ָ��Ԫ�ص�ָ��
    int space;                                  // space + free �ռ�
public:
    vectr(): sz(0), elem(0), space(0) { }
    explicit vectr(int s);

    vectr(const vectr&);                        // �������캯��
    vectr& operator=(const vectr&);             // ������ֵ

    ~vectr();                                   // ��������
    
    T& operator[](int n) {return elem[n];}      // ����, ��������
    const T& operator[](int n) const {return elem[n];}

    T& at(int n);
    const T& at(int n) const;                   // ������

    int size() const {return sz;}               // ��ǰsize
    int capacity() const {return space;}

    void resize(int newsize, T val = T());      // growth
    void push_back(const T& d);
    void reserve(int newalloc);
};

template<class T, class A> vectr<T, A>::vectr(int s)
    : sz(s), elem(alloc.allocate(s)), space(s) {
    for (int i = 0; i < sz; ++i) {
        alloc.construct(&elem[i], T());
    }        
}

template<class T, class A> vectr<T, A>::vectr(const vectr& a)
    : sz(a.sz), elem(alloc.allocate(a.sz)), space(a.sz) {
    for (int i = 0; i < sz; ++i) {
        alloc.construct(&elem[i], a.elem[i]);
    }        
}

template<class T, class A>
vectr<T, A>& vectr<T, A>::operator=(const vectr<T, A>& a) {
    if (this == &a) return *this;                           // self-assignment, no work needed

    if (a.sz <= space) {                                    // �㹻�Ŀռ�, ����Ҫ�ٷ���ռ�
        for (int i = 0; i < a.sz; ++i) {
            alloc.construct(&elem[i], a.elem[i]);
        }
        sz = a.sz;
        return *this;
    }
    
    T* p = alloc.allocate(a.sz);                            // �����µĿռ�
    for (int i = 0; i < a.sz; ++i) {                        // ����elements
        alloc.construct(&p[i], a.elem[i]);
    }
    for (int i = 0; i < sz; ++i) {                          // �ͷžɶ���
        alloc.destroy(&elem[i]);
    }
    alloc.deallocate(elem);                                 // �ͷžɿռ�
    space = sz = a.sz;                                      // �����¿ռ�
    elem = p;                                               // ������Ԫ��
    return *this;
}

template<class T, class A> vectr<T, A>::~vectr() {
    for (int i = 0; i < sz; ++i) {
        alloc.destroy(&elem[i]);
    }
    alloc.deallocate(elem);
}

template<class T, class A> T& vectr<T, A>::at(int n) {
    if (n < 0 || sz <= n) throw Range_error(n);
    return elem[n];
}

template<class T, class A> void vectr<T, A>::resize(int newsize, T val) {
    reserve(newsize);
    for (int i = sz; i < newsize; ++i) {                    // ����
        alloc.construct(&elem[i], val);
    }
    for (int i = newsize; i < sz; ++i) {                    // ����
        alloc.destroy(&elem[i]);
    }
    sz = newsize;
}

template<class T, class A> void vectr<T, A>::push_back(const T& val) {
    if (space == 0) reserve(8);                             // start with space for 8 elements
    else if (sz == space) reserve(2 * space);               // get more space
    alloc.construct(&elem[sz], val);                        // add val at end
    ++sz;                                                   // ����size
}

template<class T, class A> void vectr<T, A>::reserve(int newalloc) {
    if (newalloc <= space) return;                          // �����ٷ���
    T* p = alloc.allocate(newalloc);                        // �����¿ռ�
    for (int i = 0; i < sz; ++i) {                          // ����
        alloc.construct(&p[i], elem[i]);
    }
    for (int i = 0; i < sz; ++i) {                          // ����
        alloc.destroy(&elem[i]);
    }
    alloc.deallocate(elem);                                 // ����old space
    elem = p;
    space = newalloc;
}

// vector ���
template<class T> void diag_vec(const vectr<T>& v, const string& desc) {
    cout << desc << endl;
    cout << "\tsize: " << v.size() << endl;
    cout << "\tcapacity: " << v.capacity() << "\n\t";
    for (int i = 0; i < v.size(); ++i) {
        cout << v[i] << ' ';
    }
    cout << "\n";
}

int main()
try {
    // test integer
    // default constructor
    vectr<int> v;
    diag_vec(v,"constructed with v");

    // constructor with int argument
    vectr<int> v1(5);
    diag_vec(v1,"constructed with v1(5)");

    // copy constructor
    for (int i = 0; i<v1.size(); ++i) v1[i] = i;
    vectr<int> v2 = v1;
    diag_vec(v2,"copy constructed from modified v1");

    // copy assignment
    vectr<int> v3(1);   // shorter than v2
    diag_vec(v3,"v3 after initialisation");
    v2 = v2;    // self-assignment
    v1 = v2;    // copy assignment without need to allocate new memory
    v3 = v2;    // copy assignment with new allocation required
    diag_vec(v3,"v3 after copy assignment from v2");

    // range checked access
//    cout << v1.at(5) << "\n";   // runtime error

    // growth
    v3.reserve(5);  // nothing should happen
    diag_vec(v3,"v3 after reserve(5)");
    v3.reserve(10); // adding space
    diag_vec(v3,"v3 after reserve(10)");
    v3.resize(3);
    diag_vec(v3,"v3 after resize(3)");
    v3.resize(10);
    diag_vec(v3,"v3 after resize(10)");
    v3.push_back(99);
    v3.push_back(100);
    diag_vec(v3,"v3 after two push_back()");

    // test string
    // default constructor
    vectr<string> vs;
    diag_vec(vs,"constructed with vs");

    // constructor with int argument
    vectr<string> vs1(5);
    diag_vec(vs1,"constructed with vs1(5)");

    // copy constructor
    vs1[0] = "zero";
    vs1[1] = "one";
    vs1[2] = "two";
    vs1[3] = "three";
    vs1[4] = "four";
    vectr<string> vs2 = vs1;
    diag_vec(vs2,"copy constructed from modified vs1");

    // copy assignment
    vectr<string> vs3(1);   // shorter than vs2
    diag_vec(vs3,"vs3 after initialisation");
    vs2 = vs2;    // self-assignment
    vs1 = vs2;    // copy assignment without need to allocate new memory
    vs3 = vs2;    // copy assignment with new allocation required
    diag_vec(vs3,"vs3 after copy assignment from vs2");

    // range checked access
//    cout << vs1.at(5) << "\n";   // runtime error

    // growth
    vs3.reserve(5);  // nothing should happen
    diag_vec(vs3,"vs3 after reserve(5)");
    vs3.reserve(10); // adding space
    diag_vec(vs3,"vs3 after reserve(10)");
    vs3.resize(3);
    diag_vec(vs3,"vs3 after resize(3)");
    vs3.resize(10);
    diag_vec(vs3,"vs3 after resize(10)");
    vs3.push_back("ninety-nine");
    vs3.push_back("one hundred");
    diag_vec(vs3,"vs3 after two push_back()");

    // test user defined type
    // default constructor
    vectr<S<bool> > vudt;
    diag_vec(vudt,"constructed with vudt");

    // constructor with int argument
    vectr<S<bool> > vudt1(5);
    diag_vec(vudt1,"constructed with vudt1(5)");

    // copy constructor
    for (int i = 0; i<vudt1.size(); ++i) {
        vudt1[i].i = i;
        vudt1[i].d = 1.1*i;
        vudt1[i].c = 'a'+i;
        ostringstream oss;
        oss << "string" << vudt1[i].c;
        vudt1[i].s = oss.str();
        vudt1[i].t = i%2==0;
    }
    vectr<S<bool> > vudt2 = vudt1;
    diag_vec(vudt2,"copy constructed from modified vudt1");

    // copy assignment
    vectr<S<bool> > vudt3(1);   // shorter than vs2
    diag_vec(vudt3,"vudt3 after initialisation");
    vudt2 = vudt2;    // self-assignment
    vudt1 = vudt2;    // copy assignment without need to allocate new memory
    vudt3 = vudt2;    // copy assignment with new allocation required
    diag_vec(vudt3,"vudt3 after copy assignment from vudt2");

    // range checked access
//    cout << vudt1.at(5) << "\n";   // runtime error

    // growth
    vudt3.reserve(5);  // nothing should happen
    diag_vec(vudt3,"vudt3 after reserve(5)");
    vudt3.reserve(10); // adding space
    diag_vec(vudt3,"vudt3 after reserve(10)");
    vudt3.resize(3);
    diag_vec(vudt3,"vudt3 after resize(3)");
    vudt3.resize(10,vudt2[4]);
    diag_vec(vudt3,"vudt3 after resize(10,vudt2[4])");
    vudt3.push_back(vudt2[2]);
    vudt3.push_back(vudt2[3]);
    diag_vec(vudt3,"vudt3 after two push_back()");

    // all destructors are called here
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
