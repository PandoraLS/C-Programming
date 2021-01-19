/*
 * @Author: seenli
 * @Date: 2021-01-19 10:22:27
 * @LastEditors: seenli
 * @LastEditTime: 2021-01-19 14:57:46
 * @FilePath: \Ch11\ch11_ex08.cpp
 * @Description: Programming Principles and Practice Using C++ Second Edition
 */

// Chapter 11, exercise 06: read text file, replace punctuation with
// whitespace, replace "don't" with "do not", "can't" with "cannot" etc.
// Leave hyphens within words intact
// Convert all characters to lower case
// Exercise 08: build dictionary from resulting file
// Use ex08_in.txt for input


#include "../includes/std_lib_facilities.h"

// 将所有string变成小写
void to_lowercase(string& s) {
    if (s.size() == 0) return;              // 跳过空行
    for (int i{}; i < s.size(); ++i) {
        s[i] = tolower(s[i]);
    }
}

// 移除标点符号(除了'和-)
void remove_punct(string& s) {
    if (s.size() == 0) return;              // 跳过空行
    for (int i{}; i < s.size(); ++i) {
        if (ispunct(s[i]) && s[i] != '\'' && s[i] != '-') {
            s[i] = ' ';
        }
    }
}

// 删除'-'(当'-'不在单词中或'--'出现的时候)
void remove_hyphen(string& s) {
    if (s.size() == 0) return;              // 跳过空行
    // 检查行首或行尾有空格的连字符
    if (s[0] == '-' && s[1] == ' ') s[0] == ' ';
    if (s[s.size() - 1] == '-' && s[s.size() - 2] == ' ') s[s.size() - 1] = ' ';
    for (int i{1}; i < s.size() -1; ++i) {
        if (s[i] == '-' && s[i-1] == ' ' && s[i+1] == ' ') s[i] = ' ';
        if (s[i] == '-' && s[i+1] == '-') {
            s[i] = ' ';
            s[i+1] = ' ';
            ++i;
        }
    }
}

// replace "don't" with "do not", "can't" with "cannot" etc.
// removes extra spaces between words
void expand_aux(string& s) {
    if (s.size() == 0) return;                  // 跳过空行
    istringstream is(s);
    string word;
    string s_exp;
    ostringstream os(s_exp);
    while (is >> word) {
        if (word == "can't") os << "cannot";
        else if (word.size() >= 3
                && word[word.size() - 3] == 'n'
                && word[word.size() - 2] == '\''
                && word[word.size() - 1] == 't') {
                for (int i{}; i < word.size() - 3; ++i) {
                    os << word[i];
            }
                os << " not";
        } else {
            os << word;
        }
        os << ' ';
    }
    s = os.str();
}

// 转换文件
void convert_file(const string& iname, const string& oname) {
    ifstream ifs(iname.c_str());
    if (!ifs) error("cannot open input file ", iname);
    ofstream ofs(oname.c_str());
    if (!ofs) error("cannot open output file ", oname);

    string s;
    while (getline(ifs, s)) {
        to_lowercase(s);
        remove_punct(s);
        remove_hyphen(s);
        expand_aux(s);
        ofs << s << endl;
    }
}


// 构建字典文件
void build_dict(const string& iname, const string& oname) {
    ifstream ifs(iname.c_str());
    if (!ifs) error("cannot open input file ", iname);
    ofstream ofs(oname.c_str());
    if (!ofs) error("cannot open output file ", oname);

    vector<string> vs;
    string word;
    while (ifs >> word) {
        vs.push_back(word);
    }

    sort(vs.begin(), vs.end());
    for (int i{}; i < vs.size(); ++i) {
        if (i == 0 || vs[i] != vs[i-1]) ofs << vs[i] << endl;
    }
}

int main()
try {
    string iname{"ex08_in.txt"};
    ifstream ifs(iname.c_str());
    if (!ifs) error("cannot open input file ", iname);

    string oname{"ex08_out.txt"};
    ofstream ofs(oname.c_str());
    if (!ofs) error("cannot open output file ", oname);

    convert_file(iname, oname);

    string dname{"ex08_dict.txt"};
    build_dict(oname, dname);

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