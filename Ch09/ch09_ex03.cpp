/*
 * @Author: seenli
 * @Date: 2021-01-06 17:07:26
 * @LastEditors: seenli
 * @LastEditTime: 2021-01-06 18:37:44
 * @FilePath: \Ch09\ch09_ex03.cpp
 * @Description: Programming Principles and Practice Using C++ Second Edition
 */


/*
    Section 9 Exercise 3
	Design and implement a Name_pairs class (name,age) pairs.
	- name is a vector<string>
	- age is a vector<double>
	- read_names() to read in a series of names
	- read_ages() to prompt user for an age for each name
	- operator<< to print name[i], age[i] pairs. One per line in the order determined by the name vector.
	- sort() to sort name vector is alphabetical order and reorganizes age vector to match.
	- operator==
	- operator!=

	Implement all operations as members functions.
	Test the class.
*/


#include "ppp.h"

class Name_pairs {
    public:
        Name_pairs();
        void read_names();
        void read_ages();
        void sort();
        friend std::ostream& operator<<(std::ostream& os, const Name_pairs& np);
        friend bool operator==(const Name_pairs& np1, const Name_pairs& np2);
        friend bool operator!=(const Name_pairs& np1, const Name_pairs& np2);

    private:
        std::vector<std::string> m_names;
        std::vector<double> m_ages;
};

Name_pairs::Name_pairs() 
{}

void Name_pairs::read_names() {
    std::cout << "Enter names separated by ',' or new line. EOF (ctrl + z) to exit .\n";
    // 录入多个字符串的方式
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
                // 当输入数字时, '\n'留在缓冲区中, cin将接收流中剩下的第一个有效数字, 
                // 所以检查数字后面除了换行之外没有其他东西
                if (c != '\n') {
                    std::cin.ignore(std::numeric_limits<int>::max(), '\n');
                    // 把回车（包括回车）之前的所以字符从输入缓冲（流）中清除出去
                } else {
                    m_ages.push_back(age);
                    break;
                }
            }
            std::cout << "Invalid age entered!\n Renter age for " << n << ": ";
        }
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

std::ostream& operator<<(std::ostream& os, const Name_pairs& np) {
    // 因为操作符<<是Name_pairs类的友元，所以可以直接访问Name_pairs成员
    if (np.m_names.size() == np.m_ages.size()) {
        for (auto itr{np.m_names.begin()}; itr < np.m_names.cend(); ++itr) {
            std::size_t index = static_cast<std::size_t>(itr - np.m_names.begin());
            os << np.m_names.at(index) << " is " << np.m_ages.at(index) << " years old. \n";
        }
    } else {
        ppp::error("vector sizes do not match!");
    }
    return os;
}

bool operator==(const Name_pairs& np1, const Name_pairs& np2) {
    return np1.m_names == np2.m_names && np1.m_ages == np2.m_ages;
}

bool operator!=(const Name_pairs& np1, const Name_pairs& np2) {
    return !(np1 == np2);
}

int main()
try {
    Name_pairs np;
    np.read_names();
    np.read_ages();
    Name_pairs copy_np{np};

    if (np == copy_np) {
        std::cout << "np == copy_np\n";
    } else if (np != copy_np) {
        std::cout << "np != copy_np\n";
    }

    std::cout << "np:\n" << np << "\n";
    std::cout << "copy_np:\n" << copy_np << "\n";

    np.sort();
    if (np == copy_np) {
        std::cout << "np == copy_np\n";
    } else if (np != copy_np) {
        std::cout << "np != copy_np\n";
    }
    std::cout << "np:\n" << np << '\n';
    std::cout << "copy_np:\n" << copy_np << "\n";
    
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

