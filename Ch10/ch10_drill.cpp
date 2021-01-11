/*
 * @Author: seenli
 * @Date: 2021-01-11 19:26:07
 * @LastEditors: seenli
 * @LastEditTime: 2021-01-11 23:15:15
 * @FilePath: \Ch10\ch10_drill.cpp
 * @Description: Programming Principles and Practice Using C++ Second Edition
 */


#include "../includes/std_lib_facilities.h"

// type for points
struct Point {
    int x;
    int y;
    Point(): x(0), y(0) {}
    Point(int xx, int yy): x(xx), y(yy) {}
};

bool operator==(const Point& p1, const Point& p2) {
    return p1.x == p2.x && p1.y == p2.y;
}

bool operator!=(const Point& p1, const Point& p2) {
    return !(p1 == p2);
}

istream& operator>>(istream& is, Point& p) {
    int x{}, y{};
    char ch1{}, ch2{}, ch3{};
    is >> ch1 >> x >> ch2 >> y >> ch3;
    if (!is) {
        return is;
    }
    if (ch1 != '(' || ch2 != ',' || ch3 != ')') {
        is.clear(ios_base::failbit);        // 将流状态设置为fail()
        return is;
    }
    p = Point(x, y);
    return is;
}

ostream& operator<<(ostream& os, const Point& p) {
    return os << '(' << p.x << ',' << p.y << ')';
}

/**
 * @description: 打印vector
 * @param {const} vector Point组成的vector
 */
void print_vector(const vector<Point>& points) {
    for (int i{0}; i < points.size(); ++i) {
        cout << points[i] << endl;
    }
}

/**
 * @description: 将points写入到文件
 * @param {const} vector points 坐标点数
 * @param {const} string name 文件名
 */
void write_to_file(const vector<Point>& points, const string& name) {
    ofstream ost(name.c_str());
    if (!ost) {
        error("cannot open output file ", name);
    }
    for (int i = 0; i < points.size(); ++i) {
        ost << points[i] << endl;
    }
}

/**
 * @description: 从文件读取points
 * @param {const} string
 */
void fill_from_file(vector<Point>& points, const string& name) {
    ifstream ist(name.c_str());
    if (!ist) {
        error("cannot open input file, ", name);
        Point pp;
        while (ist >> pp) {
            points.push_back(pp);
        }
    }
}

/**
 * @description: 对比两个vector是否相同
 * @param {const} vector
 * @param {const} vector
 */
void compare_vectors(const vector<Point>& points1, const vector<Point>& points2) {
    if (points1.size() != points2.size()) {
        error("Something's wrong!");
    }
    for (int i{0}; i < points1.size(); ++i) {
        if (points1[i] != points2[i]) {
            error("Something's wrong!");
        }
    }
}


int main()
try {
    // 输入points
    vector<Point> original_points;
    cout << "输入 3 个 (x,y) 坐标, 括号也需要输入\n";
    for (int i{}; i < 3; ++i) {
        Point p;
        cin >> p;
        original_points.push_back(p);
    }

    // 输出points
    cout << "\nOriginal points: \n";
    print_vector(original_points);

    // // 将points写入文件
    string filename = "drill_out.txt";
    write_to_file(original_points, filename);

    // 从文件中读取points
    vector<Point> processed_points;
    fill_from_file(processed_points, filename);

    // 输出两个vector的数据
    cout << "\nData from ifstream:\n";
    print_vector(processed_points);
    cout << "\nOriginal data:\n";
    print_vector(original_points);

    // 比较两个vector
    compare_vectors(original_points, processed_points);

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