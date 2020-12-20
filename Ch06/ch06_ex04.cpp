/*
 * @Author: seenli
 * @Date: 2020-12-20 16:24:51
 * @LastEditors: seenli
 * @LastEditTime: 2020-12-20 19:50:19
 * @FilePath: \Ch06\ch06_ex04.cpp
 * @Description: Programming Principles and Practice Using C++ Second Edition
 */

/*
    Section 6 exercise 4
    Rewrite Section 4 exercise 19 with a class Name_value with a string and value object.
    Use a vector<Name_value> instead of 2 vectors.
    A program where you first enter a set of name-and-value pairs, such as Joe 17 and Barbara 22.
    For each pair, add the name to a vector called names and the number to a vector called scores
    (in corresponding positions, so that if names[7]=="Joe" then scores[7]==17).
    Terminate input with NoName 0.
    Check that each name is unique and terminated with an error message if a name is entered twice.
    Write out all the (name, score) pairs, one per line.
*/


#include "std_lib_facilities.h"

class Name_value {
    public:
        string name;
        double score{};

        // ���캯��
        Name_value(string n = "", double val = 0): name{n}, score(val) {}
};

// TODO ����ʲô������ʽ
// ������ںͲ�����
bool operator==(const Name_value& nv1, const Name_value& nv2) {
    return (nv1.name == nv2.name && nv1.score == nv2.score); 
}

bool operator!=(const Name_value& nv1, const Name_value& nv2) {
    return !(nv1 == nv2);
}

const Name_value termination{"noname", 0};

int main()
try {
    vector<Name_value> ranks;
    cout << "Enter names and scores. Terminate input with noname 0\n";

    // �ռ���Ч����
    while (true) {
        Name_value nv;
        cin >> nv.name >> nv.score;
        
        if (cin.eof()) {
            break;                           // ������� noname ���� EOF���˳�
        } else if (cin.fail()) {
            cout << "�����name��score��Ч������������" << endl;
            cin.clear();                                                // ��������־λ
            cin.sync_with_stdio(false);                                 // ���ò�����stdio������cin��scanf���޷�������
            cin.ignore(cin.rdbuf()->in_avail());                        // ����������ʣ�ಿ��ȫ�����Ե�
            // cin.rdbuf()->in_avail() �������������������ж೤�Ķ���û�ж���

            continue;
        } else if (cin.bad()) {
            error("input data error \n");
        }

        // ������ȫ�����Сд
        transform(nv.name.begin(), nv.name.end(), nv.name.begin(),
            [](unsigned char c){return narrow_cast<unsigned char>(tolower(c)); });
        
        // ����Ƿ����ظ�
        if (ranks.cend() != find_if(ranks.cbegin(), ranks.cend(),
                [&nv](Name_value ns){return ns.name == nv.name;})) {
                    error("�����ظ�name");
        }

        if (nv == termination) {
            break;
        }

        ranks.push_back({nv.name, nv.score});
    }

    // �����������
    if (!ranks.empty()) {
        for (const auto i: ranks) {
            cout << "name: " << i.name << "\tscore: " << i.score << endl;
        }
    } else {
        cout << "û������or��������" << endl;
    }

    keep_window_open();
    return 0;
}

catch (exception& e) {
    cerr << "error: " << e.what() << endl;
    keep_window_open();
    return 1;
}

catch (...) {
    cerr << "Oops: unknown error" << endl;
    keep_window_open();
    return 2;
}

