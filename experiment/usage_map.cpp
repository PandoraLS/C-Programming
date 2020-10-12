/*
 * @Author: seenli 
 * @Date: 2020-10-06 20:43:04 
 * @Last Modified by: seenli
 * @Last Modified time: 2020-10-10 12:17:55
 */

/* 参考链接：简述C++中map和unordered_map的用法
 * https://blog.csdn.net/jingyi130705008/article/details/82633778
 *  
*/

#include<iostream>
#include<map>
#include<string>
 
using namespace std;
 
int main()
{
	// 构造函数
	map<string, int> dict;
	
	// 插入数据的三种方式
	dict.insert(pair<string,int>("apple",2));
	dict.insert(map<string, int>::value_type("orange",3));
	dict["banana"] = 6;
 
	// 判断是否有元素
	if(dict.empty())
		cout<<"该字典无元素"<<endl;
	else
		cout<<"该字典共有"<<dict.size()<<"个元素"<<endl;
 
	// 遍历
	map<string, int>::iterator iter;
	for(iter=dict.begin();iter!=dict.end();iter++)
		cout<<iter->first<<ends<<iter->second<<endl;
 
	// 查找
	if((iter=dict.find("banana"))!=dict.end()) //  返回一个迭代器指向键值为key的元素，如果没找到就返回end()
		cout<<"已找到banana,其value为"<<iter->second<<"."<<endl;
	else
		cout<<"未找到banana."<<endl;
 
	if(dict.count("watermelon")==0) // 返回键值等于key的元素的个数
		cout<<"watermelon不存在"<<endl;
	else
		cout<<"watermelon存在"<<endl;
	
	pair<map<string, int>::iterator, map<string, int>::iterator> ret;
	ret = dict.equal_range("banana"); // 查找键值等于 key 的元素区间为[start,end)，指示范围的两个迭代器以 pair 返回
	cout<<ret.first->first<<ends<<ret.first->second<<endl;
	cout<<ret.second->first<<ends<<ret.second->second<<endl;
 
	iter = dict.lower_bound("boluo"); // 返回一个迭代器，指向键值>=key的第一个元素。
	cout<<iter->first<<endl;
	iter = dict.upper_bound("boluo"); // 返回一个迭代器，指向值键值>key的第一个元素。
	cout<<iter->first<<endl;
	system("pause");
	return 0;
}