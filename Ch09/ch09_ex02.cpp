/*
 * @Author: seenli
 * @Date: 2021-01-06 16:20:09
 * @LastEditors: seenli
 * @LastEditTime: 2021-01-06 17:06:41
 * @FilePath: \Ch09\ch09_ex02.cpp
 * @Description: Programming Principles and Practice Using C++ Second Edition
 */


/*
    Section 9 Exercise 2
	Design and implement a Name_pairs class (name,age) pairs.
	- name is a vector<string>
	- age is a vector<double>
	- read_names() to read in a series of names
	- read_ages() to prompt user for an age for each name
	- print() to print name[i], age[i] pairs. One per line in the order determined by the name vector.
	- sort() to sort name vector is alphabetical order and reorganizes age vector to match.

	Implement all operations as members functions.
	Test the class.
*/

#include "ppp.h"

class Name_pairs {
    public:
        Name_pairs();
        void read_names();
        void read_ages();
        void print() const;
        void sort();

    private:
        std::vector<std::string> m_names;
        std::vector<double> m_ages;
};

Name_pairs::Name_pairs() 
{}

void Name_pairs::read_names() {
    std::cout << "Enter names separated by ',' or new line. EOF (ctrl + z) to exit .\n";
    // ¼�����ַ����ķ�ʽ
    char c{};
    std::string name;
    while(std::cin.get(c)) {
		if(c != ',' && c != '\n') {
			if(!name.empty()){
				name += c;
			} else if(c != ' ') {
				name += c;
			}
		} else if(!name.empty()) {
			m_names.push_back(name);
			name.clear();
		}
	}
    if (std::cin.eof()) {
        std::cin.clear();               // clear EOF
    }
}

void Name_pairs::read_ages() {
    for (auto n : m_names) {
        std::cout << "Enter age for " << n << ": ";
        double age{};
        for (;;) {
            if (!(std::cin >> age)) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<int>::max(), '\n');
            } else {
                char c{};
                std::cin.get(c);
                // ����������ʱ, '\n'���ڻ�������, cin����������ʣ�µĵ�һ����Ч����, 
                // ���Լ�����ֺ�����˻���֮��û����������
                if (c != '\n') {
                    std::cin.ignore(std::numeric_limits<int>::max(), '\n');
                    // �ѻس��������س���֮ǰ�������ַ������뻺�壨�����������ȥ
                } else {
                    m_ages.push_back(age);
                    break;
                }
            }
            std::cout << "Invalid age entered!\n Renter age for " << n << ": ";
        }
    }
}


void Name_pairs::print() const {
    std::cout << "\n\n";
    if (m_names.size() == m_ages.size()) {
        for (auto itr{m_names.begin()}; itr < m_names.cend(); ++itr) {
            std::size_t index = static_cast<std::size_t>(itr - m_names.begin());
            std::cout << m_names.at(index) << " is " << m_ages.at(index) << " years old. \n";
        }
    } else {
        ppp::error("vector sizes do not match!");
    }
}

void Name_pairs::sort() {
    using it_size = std::vector<std::string>::size_type;

    std::vector<std::string> copy_names = m_names;
    std::vector<double> copy_ages = m_ages;

    std::stable_sort(m_names.begin(), m_names.end());

    if (m_names.size() == m_ages.size()) {
        for (it_size i{}; i < m_names.size(); ++i) {
            const auto itr{std::find(copy_names.begin(), copy_names.end(), m_names.at(i))};
            if (itr == copy_names.cend()) ppp::error("Name not found");

            it_size index = static_cast<it_size>(itr - copy_names.begin());
            m_ages.at(i) = copy_ages.at(index);
        }
    } else {
        ppp::error("vector sizes do not match!");
    }
}

int main()
try {
    Name_pairs np;
    np.read_names();
    np.read_ages();
    np.print();
    np.sort();
    
    system("pause");
    return 0;
}
catch(std::exception& e){
	std::cerr << "exception: " << e.what() << std::endl;
	ppp::keep_window_open();
	return 1;
}
catch(...){
	std::cerr << "exception\n";
	ppp::keep_window_open();
	return 2;
}