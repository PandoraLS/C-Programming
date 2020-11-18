/*
 * @Author: seenli 
 * @Date: 2020-10-06 21:45:30 
 * @Last Modified by: seenli
 * @Last Modified time: 2020-10-06 21:48:27
 */

#include <iostream>
#include <string>
using namespace std;
int main()
{
    string b;
    getline(cin,b);
    int count=0;
    for(int i=0;i<=127;i++)
        if(b.find(i)!=string::npos)
            count++;
    cout<<count;
    system("pause");
    return 0;
}