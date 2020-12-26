/*
 * @Author: seenli
 * @Date: 2020-12-20 19:54:44
 * @LastEditors: Please set LastEditors
 * @LastEditTime: 2020-12-26 16:33:05
 * @FilePath: \Ch06\ch06_ex06.cpp
 * @Description: Programming Principles and Practice Using C++ Second Edition
 */

/*
A program that checks if a sentence is correct.
According to the grammar from 6.4.1
Assume sentence is terminated " . " surrounded by whitespace
Reply "ok" or "not ok"

Sentence:
	Noun Verb						// e.g., C++ rules
	Sentence conjunction Sentence	// e.g., Birds fly but fish swim
conjunction:
	"and"
	"or"
	"but"
Verb:
	"rules"
	"fly"
	"swim"
Noun:
	"birds"
	"fish"
	"c++"
Article:
	"the"
*/

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------
class str
{
    private:
        string in_str;
    public:
        str() : in_str(" ") {}
        str(string s) : in_str(s) {}
        bool compare(const vector<string>& vs);
};

bool str::compare(const vector<string>& vs)
{
	bool match = false;
	match = (find(begin(vs), end(vs), in_str) != end(vs));
	return match;
}

//------------------------------------------------------------------------------
class str_stream
{
    private:
        bool full;
        str buffer;
    public:
        str_stream()						// make a str_stream that reads cin
            : full(false), buffer("")
        {}	// The constructor just sets full to indicate that the buffer is empty:
        str get();							// get a str
        void putback(str old);
};

//------------------------------------------------------------------------------
void str_stream::putback(str s) {
	// precondition check
	if(full){
		error("putback() into full buffer");
	}
	buffer = s;
	full = true;
}

//------------------------------------------------------------------------------
str str_stream::get()	// read a string from cin
{
	// do we already have a string ready
	if(full){
		full = false;		// remove string from buffer
		return buffer;
	}
	string new_string;
	cin >> new_string;	// note that >> skips whitespace (space, newline, tab, etc.)
	transform(new_string.begin(), new_string.end(), new_string.begin(), [](char c){ return narrow_cast<char, int>(tolower(c)); });
	return str(new_string);
}

//------------------------------------------------------------------------------
str_stream ss;	// provides get() and putback()

//------------------------------------------------------------------------------
bool article()
{
	vector<string> test{"the"};
	str s = ss.get();
	if(!(s.compare(test))){
		return false;
	}
	return true;
}

//------------------------------------------------------------------------------
bool noun()
{
	vector<string> test{"birds","fish","c++"};
	bool check = false;
	str s = ss.get();
	// check for a noun
	if(s.compare(test)){
		check = true;
	} else{
		ss.putback(s);
		// no noun but check if is article
		if(article()){
			check = noun();
		}
	}
	return check;
}

//------------------------------------------------------------------------------
bool verb()
{
	bool check = noun();
	str s = ss.get();
	if(check){
		vector<string> test{"rules","fly","swim"};

		if(!(s.compare(test))){
			check = false;
		}
	}
	return check;
}

//------------------------------------------------------------------------------
bool conjunct() {
	bool check = verb();
	str s = ss.get();
	if(check){
		vector<string> test{"and","or","but"};
		if(s.compare(test)){
			check = verb();
		} else{
			test = {"."};
			if(!(s.compare(test))){
				check = false;
			}
		}
	}
	return check;
}

//------------------------------------------------------------------------------
int main()
try{
    cout << "Enter a sentence terminated with \" . \" surrounded by whitespace\n";
    if(conjunct()) {
        cout << "Sentence is OK.\n";
    } else{
        cout << "Sentence is Not OK.\n";
    }
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
