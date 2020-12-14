/*
 * @Author: seenli
 * @Date: 2020-12-14 14:40:22
 * @LastEditors: seenli
 * @LastEditTime: 2020-12-14 14:40:58
 * @FilePath: \Ch05\ch05_ex14_2.cpp
 * @Description: Programming Principles and Practice Using C++ Second Edition
 */

#include "std_lib_facilities.h"


using pType = pair <vector<string>, vector<int>>;
using vType = vector<pType>;
using numType = pType::second_type::value_type;

numType add(numType n1, numType n2)
{
	if(((n2 > 0) && (n1 > (numeric_limits< numType>::max() - n2))) ||
		((n2 < 0) && (n1 < (numeric_limits< numType>::min() - n2)))){
		error("overflow error");
	}
	return n1 + n2;
}

int main()
try{
	const string termination{"q"};

	vType weekdays{
	{ {"sun","sunday"   }, {} },
	{ {"mon","monday"   }, {} },
	{ {"tue","tuesday"  }, {} },
	{ {"wed","wednesday"}, {} },
	{ {"thu","thursday" }, {} },
	{ {"fri","friday"   }, {} },
	{ {"sat","saturday" }, {} }
	};

	unsigned rejects{};
	cout << "Enter days of the week (ex:Mon or Monday) and a value. Enter q to exit\n";
	while(true){
		string day;
		cin >> day;
		for(auto& c : day){
			c = narrow_cast<char>(tolower(c));
		}
		// check for matching day
		auto validDay{weekdays.begin()};
		for(; validDay < weekdays.end(); ++validDay){
			bool found{false};
			for(auto d : validDay->first){
				if(d == day){
					found = true;
					break;
				}
			}
			if(found){
				break;
			}
		}
		// day not found, check if valid termination
		if(validDay == weekdays.end()){
			if(day == termination){
				// stop while loop
				break;
			}
			++rejects;
		}
		// valid day now look for number value
		else{
			numType value{};
			if(!(cin >> value)){
				cin.clear();
				// check if input number was overflowed
				if(value == numeric_limits<numType>::max() ||
					value == numeric_limits<numType>::min()){
					error("Entered number overflowed number type!");
				}
				++rejects;
			} else{
				validDay->second.push_back(value);
			}
		}
	}

	//print the results
	cout << endl;
	for(auto d : weekdays){
		numType sum{};
		for(auto num : d.second){
			sum = add(sum, num);
		}
		cout << left << setfill('.') << setw(20) << d.first.at(1) << " " << sum << '\n';
	}
	cout << "\n\n" << left << setfill('.') << setw(20) << "rejects" << " " << rejects << endl;

	keep_window_open();
	return 0;
}
catch(exception& e){
	cerr << "error: " << e.what() << '\n';
	keep_window_open();
	return 1;
}
catch(...){
	cerr << "Oops: unknown exception!\n";
	keep_window_open();
	return 2;
}
