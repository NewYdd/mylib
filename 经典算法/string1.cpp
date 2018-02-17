#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include<unordered_map> 

using namespace std;

//tip1 查找字符串
int strStr(string &target, string &source)
{
	if(target.empty() || target.size() > source.size())
		return -1;
	else
	{	const int lenth_target =target.size();
		const int lenth_source =source.size();
		
		for(int i = 0;i < lenth_source-lenth_target +1;++i)
		{
			int j = 0;
			for(;j < lenth_target;++j)
			{
				if(target[j]!=source[i+j]) break;
			}
			if(j == lenth_target ) return i;
		}
		return -1;
	}
}

//tip2 判断两个字符串是否为变形词  统计各字符出现的频次
bool isAnagrams(string &a, string &b)
{
	if (a.empty() || b.empty())
		return false;
	if (a.size() != b.size())
		return false;
	int letterCount[256] = { 0 };

	for (int i = 0; i != a.size(); ++i) {
		++letterCount[a[i]];
		--letterCount[b[i]];
	}
	for (int i = 0; i != b.size(); ++i) {
		if (letterCount[b[i]] != 0) {
			return false;

		}
	}
/*	//如果b的size大于256，这样更优
	for (int i = 0; i <256; ++i) {
		if (letterCount[i] != 0) {
			return false;

		}
	}
*/
	return true;
}
bool isAnagrams2(string &a, string &b)
{
	if (a.empty() || b.empty())
		return false;
	if (a.size() != b.size())
		return false;
	sort(a.begin(), a.end());  //sort函数需要#include <algorithm>
	sort(b.begin(),b.end());
	if (a == b)
		return true;
	else
		return false;
}

//tip3 比较字符串 判断A是否包含B中所有字符
bool compareStr(string &a, string &b)
{
	if (a.empty() || b.size() > a.size())
		return false;
	if (b.empty())
		return true;

	int letterCount[256] = { 0 };
	for (int i = 0; i != a.size(); ++i) {
		++letterCount[a[i]];
		--letterCount[b[i]];
	}
	for (int i = 0; i != b.size(); ++i) {
		if (letterCount[b[i]] < 0) {
			return false;
		}
	}
	return true;
}

//tip4 确定字符串数组中的变形词组 如{"abc","cba","ad"} return {"abc","cba"}
vector<string>  isAnaGroup(vector<string> &source)
{
	vector<string> result;
	vector<bool> visited(source.size(), false);

	for (int i = 0; i < source.size();i++)
	{
		bool flag = false;
		for (int j = i+1; j < source.size(); j++)
		{
			if (isAnagrams(source[i], source[j])&& !visited[j])
			{
				result.push_back(source[j]);
				visited[j] = true;
				flag = true;
			}
		}
		if (flag && !visited[i])
		{
			result.push_back(source[i]);	
		}
	}
	if (!result.empty())
		return result;
	vector<string> none;
	return none;
}
vector<string>  isAnaGroup2(vector<string> &strs)
{
	unordered_map<string, int> hash;		
	for (int i = 0; i < strs.size(); i++) {
		string str = strs[i];
		sort(str.begin(), str.end());
		++hash[str];
	}

	vector<string> result;
	for (int i = 0; i < strs.size(); i++) {
		string str = strs[i];
		sort(str.begin(), str.end());
		if (hash[str] > 1) {
			result.push_back(strs[i]);
		}
	}

	return result;
}

/*
使用到一个c++的容器——unordered_map，它是一个关联容器，内部采用的是hash表结构，拥有快速检索的功能。
关联性：通过key去检索value，而不是通过绝对地址（和顺序容器不同）
unordered_map<const Key, T> map;
1 迭代器
unordered_map<Key,T>::iterator it;
(*it).first;             // the key value (of type Key)
(*it).second;            // the mapped value (of type T)
(*it);                   // the "element value" (of type pair<const Key,T>)

2.改变某个key的value map[key]=value

3.map 初始化
unordered_map<string,string> mymap =
{
	{"house","maison"},
	{"apple","pomme"},
	{"tree","arbre"},
	{"book","livre"},
	{"door","porte"},
	{"grapefruit","pamplemousse"}
};//等号可去掉 或者=号换成花括号
*/

//tip5 longest common substr 寻找两个字符串最长的相同部分
int longestSubstr(string &a, string &b)
{
	if (a.empty() || b.empty())
		return 0;
	int longest=0, temp=0;
	for (int i = 0; i < a.size(); ++i)
	{
		for (int j = 0; j < b.size(); ++j)
		{
			temp = 0;
			while((i+temp)<a.size() && (j+temp)<b.size() && a[i+temp] == b[j+temp])
			{
				temp++;
			}
			if (temp > longest)
				longest = temp;
		
		}
	}
	return longest;

}

// tip6 rotate string 按给定偏移量偏移字符串 如"ABCDEF" offset=2 "EFABCD"
string rotateStr(string &a, int offset)
{
	int real_offset = offset % a.size();
	string result=a;
	for (int i = 0; i < real_offset; ++i)
	{
		string temp = result;
		for (int j = 1; j < a.size(); j++)
		{
			result[j] = temp[j - 1];
		}
		result[0] = temp[a.size() - 1];
	}
	return result;
}
int main()
{
	string a;
	int b=0;
	cin >> a >> b;
	cout << a << b << endl;
	cout<<rotateStr(a, b)<<endl;

	system("PAUSE");

	return 0;
}