/*
 * @Author: seenli 
 * @Date: 2020-11-19 21:15:11 
 * @Last Modified by:   seenli 
 * @Last Modified time: 2020-11-19 21:15:11 
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    vector<string> msg {"Hello", "C++", "World", "from", "VS Code", "and the C++ extension!"};

    for (const string& word : msg)
    {
        cout << word << " ";
    }
    cout << endl;
    system("pause");
    return 0;
}