/*
 * @Author: seenli 
 * @Date: 2020-10-12 18:13:50 
 * @Last Modified by: seenli
 * @Last Modified time: 2020-10-12 18:15:52
 */

/*
Section 4 exercise 9.
 Try to calculate the number of rice grains that the inventor asked for in exercise 8 above.
 You'll find that the number is so large that it won't fit in an int or a double.
 Observe what happens when the number gets too large to represent exactly as an int and as a double.
 What is the largest number of squares for which you can calculate the exact number of grains (using an int)?
 What is the largest number of squares for which you can calculate the approximate number of grains (using a double)?
*/

#include "std_lib_facilities.h"

int main() {
    cout << "The maximum number represented int on this PC is " << numeric_limits<int>::max() << endl;
	cout << "The maximum number represented unsigned on this PC is " << numeric_limits<unsigned>::max() << endl;
	cout << "The maximum number represented long on this PC is " << numeric_limits<long>::max() << endl;
	cout << "The maximum number represented unsigned long on this PC is " << numeric_limits<unsigned long>::max() << endl;
	cout << "The maximum number represented long long on this PC is " << numeric_limits<long long>::max() << endl;
	cout << "The maximum number represented unsigned long long on this PC is " << numeric_limits<unsigned long long>::max() << endl;
	cout << "The maximum number represented double on this PC is " << numeric_limits<double>::max() << endl;
	cout << "The maximum number represented long double on this PC is " << numeric_limits<long double>::max() << endl;

    constexpr int maxSquares = 64;
    unsigned long long current_square_grains{1};        // 目前谷物的平方
    decltype(current_square_grains) previous_square_grains{0}; // 之前谷物的平方  
    cout << "size of square = " << sizeof(current_square_grains) << endl;
    cout << "max limit of square = " << numeric_limits<decltype(current_square_grains)>::max() << "\n\n";

    decltype(current_square_grains) sum{0};
    for (int square = 1; square <= maxSquares; square++) {
        if (square == 1) {
            current_square_grains = 1;
        } else {
            current_square_grains = previous_square_grains * 2;
        }
        previous_square_grains = current_square_grains;
        sum += current_square_grains;
        // cout << "squares to this point is " << sum << " grains. \n";

        if(current_square_grains <= 1000 && sum >= 1000){
			std::cout << square << " provides approximately 1000 grains.\n\n";
		} else if(current_square_grains <= 1000000 && sum >= 1000000){
			std::cout << square << " provides approximately 1,000,000 grains.\n\n";
		} else if(current_square_grains <= 1000000000 && sum >= 1000000000){
			std::cout << square << " provides approximately 1,000,000,000 grains.\n\n";
		} else if(current_square_grains <= 1000000000000 && sum >= 1000000000000){
			std::cout << square << " provides approximately 1,000,000,000,000 grains.\n\n";
		} else if(current_square_grains <= 1000000000000000 && sum >= 1000000000000000){
			std::cout << square << " provides approximately 1,000,000,000,000,000 grains.\n\n";
		} else if(current_square_grains <= 1000000000000000000 && sum >= 1000000000000000000){
			std::cout << square << " provides approximately 1,000,000,000,000,000,000 grains.\n\n";
		}
    }

    keep_window_open();
    return 0;
}