/*
 * File: NumericConversion.cpp
 * ---------------------------
 * Name: [TODO: enter name here]
 * This file is the starter project for the numeric-conversion problem
 * in which you implement the functions intToString and stringToInt.
 * [TODO: rewrite the documentation]
 */

#include <iostream>
#include <string>
#include "console.h"
#include <cmath>
using namespace std;

/* Function prototypes */

string intToString(int n);
int stringToInt(string str);

/* Main program */

int main() {

   cout << "Integer 123 ----> " << intToString(123) << endl;
   cout << "Integer -42 ----> " << intToString(-42) << endl;
   cout << "String 671 ----> " << stringToInt("671") << endl;
   cout << "String -99 ----> " << stringToInt("-99") << endl;
   return 0;
}

string intToString(int n)
{
   string str = "";
   if (n<0)            //特殊情况
   {
       str += '-';     //str[0] = '-' 不行，why?
       n = abs(n);
   }
   if(n>=10) str+=intToString(n/10);  //能继续划分则递归
   str += (n%10)+48;                  //将数字添加进字符串
   return str;
}

int stringToInt(string str)
{
   int n = 0;
   bool flag = false;                   //用来判断正负的标记
   int len = str.length();              //用来调整数位
   if(str[0] == '\0') return 0;         //为空串时返回0
   if(str[0] == '-') flag = true;
   else n = int(str[0]-48)*pow(10,len-1);
   n += stringToInt(str.substr(1));    //不断递归子串
   if(flag == true) n = n*-1;
   return n;
}
/*
春雨楼头尺八箫，何时归看浙江潮。
芒鞋破钵无人识，踏过樱花第几桥？
                ——苏曼殊
*/
