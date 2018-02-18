#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include<unordered_map> 

using namespace std;


// tip1 Valid Palindrome 判断是否为回文 A man, a plan, a canal: Panama" is a palindrome
bool isPalindrome(string &a)
{
	string simple;
	size_t lenth = a.size();
	string revSimple;
	for (int i = 0; i < lenth; i++)
	{
		if (isalnum(a[i]))
		{
			if (a[i] >= 'A' && a[i] <= 'Z') //大写转为小写
				simple.push_back(a[i] +32);
			else
				simple.push_back(a[i]);
		}
			
	}

	for (int i = simple.size()-1; i >= 0; --i)
	{
		revSimple.push_back(simple[i]);
	}
	if (simple == revSimple)
		return true;
	else
		return false;
}
bool isPalindrome2(string &a)
{
	int front = 0, back = a.size()-1;
	while (front < back)
	{
		if (!isalnum(a[front]))
		{
			front++;
			continue;
		}
		if (!isalnum(a[back]))
		{
			back--;
			continue;
		}

		if (tolower(a[front]) == tolower(a[back]))
		{
			front++; back--;
		}
		else
			return false;
	}
	return true;
}


//tip2 Longest Palindromic Substring  寻找字符串中最长的回文字符串 字符串长度《1000字节*******
string longestPalindrom1(string &s) //穷举法  substrsubstr ：返回一个从指定位置开始的指定长度的子字符串 stringvar.substr(start, [length])
{
	string result;
	if (s.empty()) return s;

	int n = s.size();
	int longest = 0, left = 0, right = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j <= n; ++j) {
			string substr = s.substr(i, j - i);
			if (isPalindrome(substr) && substr.size() > longest) {
				longest = j - i;
				left = i;
				right = j;
			}
		}
	}

	result = s.substr(left, right - left);
	return result;
}
string palindrome(string& s, int l, int r) {
	while (l >= 0 && r<s.size() && s[l] == s[r]) l--, r++;
	return s.substr(l + 1, r - l - 1);
}
string longestPalindrome2(string s) {
	if (s.empty()) return s;

	string res;
	for (int i = 0; i<s.size(); i++) {
		string t;
		t = palindrome(s, i, i);
		if (t.size() > res.size()) res = t;

		t = palindrome(s, i, i + 1);
		if (t.size() > res.size()) res = t;
	}
	return res;
}

//tip3 space replacement 给定字符串以及字符串长度，使用%20代替所有的空格
string replaceSpace(string &s)
{
	string result;
	size_t lenth = s.size();
	string add = "%20";
	for (int i = 0; i < lenth; i++)
	{
		if (isspace(s[i]))
			result += add;
		else
			result.push_back(s[i]);
	}
	return result;
}

//tip4 判断两字符串是否匹配，字符串中的？代替任意一个字符，*代替任意过个字符
bool isMatch(string s, string p) {
	int star = 0, ss = 0, i = 0, j = 0;
	while (s[i]) {
		if (p[j] == '?' || p[j] == s[i]) { j++; i++; continue; }
		if (p[j] == '*') { star = ++j; ss = i; continue; }
		if (star) { j = star; i = ++ss; continue; }
		return false;
	}
	while (p[j] == '*') j++;
	return !p[j];
}

//tip5 最后一个单词的长度
int lenth_lastWord1(string &a)
{
	if (a.empty())
		return 0;
	int lenth = a.size();
	string word;
	int i = lenth - 1;
	while (a[i] == ' ')
		i--;
	for (; i >= 0; --i)
	{
		if (!isspace(a[i]))
			word.push_back(a[i]);
		else
			return word.size();
	}

}
int lenth_lastWord2(string &a)
{
	if (a.empty())
		return 0;
	int lenth = a.size();
	int count = 0;
	for (int i = lenth - 1; i >= 0; --i)
	{
		if (a[i] == ' ')
		{
			if (count) return count;
			else continue;
		}
		else
			count++;
	}

}


//tip6 count and say 根据个数产生新数 如1-》11  2-》12 11-》21  111221=>312211
string countAndSay(int n) {
	if (n == 0) return "";
	string res = "1";
	while (--n) {
		string cur = "";
		for (int i = 0; i < res.size(); i++) {
			int count = 1;
			while ((i + 1 < res.size()) && (res[i] == res[i + 1])) {
				count++;
				i++;
			}
			cur += to_string(count) + res[i]; // 整数转为string
		}
		res = cur;
	}
	return res;
}

int main()
{
	int a,b;
	cin >> a;
	cout << countAndSay(a);

	system("PAUSE");

	return 0;
}