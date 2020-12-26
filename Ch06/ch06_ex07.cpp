/*
 * @Author: seenli
 * @Date: 2020-12-26 16:39:08
 * @LastEditors: seenli
 * @LastEditTime: 2020-12-26 16:53:07
 * @FilePath: \Ch06\ch06_ex07.cpp
 * @Description: Programming Principles and Practice Using C++ Second Edition
 */

// Grammar for bitwise logical expressions

/*
Expression

OR :
XOR
OR "|" XOR			// OR

XOR :
AND
XOR "^" AND			// exclusive or

AND :
Primary
And "&" Primary		// And

Primary :
Number
"(" Expression ")"	// grouping
Number "!" Primary	// NOT
Number "~" Primary	// Complement

Number :
	number
*/