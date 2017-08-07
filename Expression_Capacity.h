#pragma once
#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include <sstream> 
#include <utility> 
using namespace std;

class Expression_Capacity
{
public:
	Expression_Capacity(string str);
	bool test();         // 外部接口，判断表达式是否合法  
	double calculate();  // 外部接口，计算表达式的值   
private:
	vector<pair<string, int>> word;
	int word_analysis(vector<pair<string, int>>& vec, const string str);
	string str;//算术表达式
	int index;//位置
	int err;  //判断错误
	int syn;  //单词终别编码
	void T();
	void F();
	void E();
	void Next();
	bool Right;//保存text结果
private:
	int prior(int syn);//判断运算符优先级
	bool isOperator(int syn);// 判断是否是运算符 
	double stringToDouble(const string& str);//字符串转浮点型数
	void popTwoNumbers(stack<double>& s, double& first, double& second); //从栈中连续取出两个数
	vector<pair<string, int>> getPostfix(const vector<pair<string, int>>& vec); //从中缀表达式转后缀表达式
	double expCalculate(const vector<pair<string, int>>& vec); //计算后缀表达式结果
};
