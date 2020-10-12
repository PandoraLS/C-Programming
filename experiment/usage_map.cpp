/*
 * @Author: seenli 
 * @Date: 2020-10-06 20:43:04 
 * @Last Modified by: seenli
 * @Last Modified time: 2020-10-10 12:17:55
 */

/* �ο����ӣ�����C++��map��unordered_map���÷�
 * https://blog.csdn.net/jingyi130705008/article/details/82633778
 *  
*/

#include<iostream>
#include<map>
#include<string>
 
using namespace std;
 
int main()
{
	// ���캯��
	map<string, int> dict;
	
	// �������ݵ����ַ�ʽ
	dict.insert(pair<string,int>("apple",2));
	dict.insert(map<string, int>::value_type("orange",3));
	dict["banana"] = 6;
 
	// �ж��Ƿ���Ԫ��
	if(dict.empty())
		cout<<"���ֵ���Ԫ��"<<endl;
	else
		cout<<"���ֵ乲��"<<dict.size()<<"��Ԫ��"<<endl;
 
	// ����
	map<string, int>::iterator iter;
	for(iter=dict.begin();iter!=dict.end();iter++)
		cout<<iter->first<<ends<<iter->second<<endl;
 
	// ����
	if((iter=dict.find("banana"))!=dict.end()) //  ����һ��������ָ���ֵΪkey��Ԫ�أ����û�ҵ��ͷ���end()
		cout<<"���ҵ�banana,��valueΪ"<<iter->second<<"."<<endl;
	else
		cout<<"δ�ҵ�banana."<<endl;
 
	if(dict.count("watermelon")==0) // ���ؼ�ֵ����key��Ԫ�صĸ���
		cout<<"watermelon������"<<endl;
	else
		cout<<"watermelon����"<<endl;
	
	pair<map<string, int>::iterator, map<string, int>::iterator> ret;
	ret = dict.equal_range("banana"); // ���Ҽ�ֵ���� key ��Ԫ������Ϊ[start,end)��ָʾ��Χ�������������� pair ����
	cout<<ret.first->first<<ends<<ret.first->second<<endl;
	cout<<ret.second->first<<ends<<ret.second->second<<endl;
 
	iter = dict.lower_bound("boluo"); // ����һ����������ָ���ֵ>=key�ĵ�һ��Ԫ�ء�
	cout<<iter->first<<endl;
	iter = dict.upper_bound("boluo"); // ����һ����������ָ��ֵ��ֵ>key�ĵ�һ��Ԫ�ء�
	cout<<iter->first<<endl;
	system("pause");
	return 0;
}