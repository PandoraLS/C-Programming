/*
 * @Author: seenli 
 * @Date: 2020-11-22 21:35:52 
 * @Last Modified by: seenli
 * @Last Modified time: 2020-11-23 15:15:39
 */

/**
 * Vocab类的实现和实例化
*/

#include <iostream>
#include <stdlib.h>
#include <map>

using namespace std;

class Vocab{
    public:
        map<string, int> Token2Id;
        map<int, string> Id2Token;

        int add_token(string token) {
            
        }
};


int main() {
    typedef map<string, int> BasePairMap;
    BasePairMap m;
    m["power"] = 0;
    m["select"] = 1;
    m["sky"] = 241;
}