/*
 * File: AddCommas.cpp
 * -------------------
 * Name: [TODO: enter name here]
 * This program adds commas to numeric strings.
 * [TODO: rewrite the documentation]
 */

#include <iostream>
#include <string>
#include "simpio.h"
#include "console.h"
using namespace std;

/* Function prototypes */

string addCommas(string digits);

/* Main program */
// 原主函数无法识别输入非数字字符串的情况，故做出一些改进
int main() {
   while (true) {
      string digits = getLine("Enter a number: ");
      if (addCommas(digits) == ""){
          cout << "Invalid input!";        //增加一个提示输出
          break;
      }
      cout << addCommas(digits) << endl;
   }
   return 0;
}

/*
 * Function: addCommas
 * Usage: string str = addCommas(digits);
 * --------------------------------------
 * Adds commas at every third position of the string digits
 * starting on the right.
 */

string addCommas(string digits) {
    int len = digits.length();
    for(int i = 0;i<len;i++)
        if(digits[i]< '0' || digits[i] > '9')  //判断输入是否为一个数字字符串
            return "";
    int n;
    if(len % 3 == 0) n = 3;       //用n来表示逗号放置位置，但是要考虑字符长度为3的倍数和小于3的情况
    else n = len %3;
    for(;n < len+(len/3)-1;n+=4)
        digits.insert(n,",");     //用成员函数便捷插入
    return digits;
}
