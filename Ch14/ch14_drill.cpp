/*
 * @Author: seenli
 * @Date: 2021-01-26 10:27:19
 * @LastEditors: seenli
 * @LastEditTime: 2021-01-26 12:10:01
 * @FilePath: \Ch14\ch14_drill.cpp
 * @Description: Programming Principles and Practice Using C++ Second Edition
 */

// Chapter 14, drill: templates

#include "../includes/std_lib_facilities.h"

template<typename T> struct S {
    S(): val(T()) {}
    S(T d): val(d) {}                                       // Drill 2
    T& get();                                               // Drill 5
    void set(const T& d);                                   // Drill 9
    T& operator=(const T&);                                 // Drill 10
    const T& get() const;                                   // Drill 11
    
    private:
        T val;
};

// Drill 6
template<typename T> T& S<T>::get() {return val;}

template<typename T> const T& S<T>::get() const {return val;}

// Drill 9
template<typename T> void S<T>::set(const T& d) {val = d;}

// Drill 10
template<typename T> T& S<T>::operator=(const T& d) {
    val = d;
    return val;
}

// Drill 12
template<typename T> istream& operator>>(istream& is, S<T>& ss) {
    T v;
    cin >> v;
    if (!is) return is;
    ss = v;
    return is;
}

template<typename T> void read_val(T& v) {
    cin >> v;
}


// Drill 14
template<typename T> ostream& operator<<(ostream& os, const vector<T>& d) {
    os << "{";
    for (int i = 0; i < d.size(); ++i) {
        os << d[i];
        if (i < d.size() - 1) os << ',';
        os << ' ';
    }
    os << "}";
    return os;
}

template<typename T> istream& operator>>(istream& is, vector<T>& d) {
    char ch1, ch2;
    T temp;
    vector<T> v_temp;
    is >> ch1;
    if (!is) return is;
    if (ch1 != '{') {
        is.clear(ios_base::failbit);
        return is;
    }
    while (cin >> temp >> ch2 && ch2 == ',') {
        v_temp.push_back(temp);
    }
    if (ch2 != '}') {
        is.clear(ios_base::failbit);
        return is;
    }
    v_temp.push_back(temp);                                             // ch2 == '}', read last value

    // 现在只复制临时向量，当输入失败的时候d不会被改变
    d = v_temp;
}

int main()
try {
    // Drill 3
    S<int> s_int(5);
    S<char> s_char('x');
    S<double> s_dbl(3.14);
    S<string> s_strg("lalalalala~");
    vector<int> vi;
    vi.push_back(1);
    vi.push_back(2);
    vi.push_back(3);
    S<vector<int>> s_v_int(vi);

    // Drill 4: 需要把S中的val的private注释掉
    // cout << "s_int: " << s_int.val << "\n";
    // cout << "s_char: " << s_char.val << endl;
    // cout << "s_dbl: " << s_dbl.val << endl;
    // cout << "s_strg: " << s_strg.val << endl;
    // for (int i = 0; i < s_v_int.val.size(); ++i) {
    //     cout << "s_v_int[" << i << "]: " << s_v_int.val[i] << endl;
    // }

    // Drill 8
    cout << "s_int: " << s_int.get() << "\n";
    cout << "s_char: " << s_char.get() << endl;
    cout << "s_dbl: " << s_dbl.get() << endl;
    cout << "s_strg: " << s_strg.get() << endl;
    for (int i = 0; i < s_v_int.get().size(); ++i) {
        cout << "s_v_int[" << i << "]: " << s_v_int.get()[i] << endl;
    }
    cout << s_v_int.get() << endl;

    // Drill 9
    s_int.set(55);
    s_char.set('y');
    s_dbl.set(4.14);
    s_strg.set("dududududu~");
    vi[1] = 22;
    s_v_int.set(vi);
    cout << "\ns_int: " << s_int.get() << "\n";
    cout << "s_char: " << s_char.get() << "\n";
    cout << "s_dbl: " << s_dbl.get() << "\n";
    cout << "s_strg: " << s_strg.get() << "\n";
    for (int i = 0; i<s_v_int.get().size(); ++i)
        cout << "s_v_int[" << i << "]: " << s_v_int.get()[i] << "\n";
    cout << s_v_int.get() << endl;

    // Drill 10
    s_int = 66;
    s_char = 'z';
    s_dbl = 5.14;
    s_strg = "String3";
    vi[1] = 33;
    s_v_int = vi;
    cout << "\ns_int: " << s_int.get() << "\n";
    cout << "s_char: " << s_char.get() << "\n";
    cout << "s_dbl: " << s_dbl.get() << "\n";
    cout << "s_strg: " << s_strg.get() << "\n";
    for (int i = 0; i<s_v_int.get().size(); ++i)
        cout << "s_v_int[" << i << "]: " << s_v_int.get()[i] << "\n";
    cout << s_v_int.get() << endl;

    // Drill 11
    const S<int> c_s_int(5);
    cout << "\nc_s_int: " << c_s_int.get() << endl;                     // requires const getter

    // Drill 13
    cout << "\ns_int: ";
    read_val(s_int);
    cout << "s_char: ";
    read_val(s_char);
    cout << "s_dbl: ";
    read_val(s_dbl);
    cout << "s_strg: ";
    read_val(s_strg);
    cout << "\ns_int: " << s_int.get() << "\n";
    cout << "s_char: " << s_char.get() << "\n";
    cout << "s_dbl: " << s_dbl.get() << "\n";
    cout << "s_strg: " << s_strg.get() << "\n\n";

    // Drill 14
    cout << "\ns_v_int: ";
    read_val(s_v_int);
    cout << "\ns_v_int: " << s_v_int.get() << "\n";
    
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
