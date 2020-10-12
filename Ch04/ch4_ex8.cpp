/*
 * @Author: seenli 
 * @Date: 2020-10-10 17:04:18 
 * @Last Modified by: seenli
 * @Last Modified time: 2020-10-12 18:15:17
 */

/*
Section 4 exercise 8.
There is an old story that the emperor wanted to thank the inventor of the game of chess and asked the inventor to
name his reward. The inventor asked for one grain of rice for the first square, 2 for the second, 4 for the third,
and so on, doubling for each of the 64 squares. That may sound modest, but there wasn’t that much rice in the empire!
Write a program to calculate how many squares are required to give the inventor at least 1000 grains of rice,
at least 1,000,000 grains, and at least 1,000,000,000 grains.
You’ll need a loop, of course, and probably an int to keep track of which square you are at,
an int to keep the number of grains on the current square, and an int to keep track of the grains on all previous squares.
We suggest that you write out the value of all your variables for each iteration of the loop so that you can see what’s going on.
*/

#include "std_lib_facilities.h"

int main() {
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