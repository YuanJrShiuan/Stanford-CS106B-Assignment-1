/*
 * File: FindDNAMatch.cpp
 * ----------------------
 * Name: [TODO: enter name here]
 * This file solves the DNA matching exercise from the text.
 * [TODO: rewrite the documentation]
 */

#include <iostream>
#include <string>
#include "console.h"
#include <cmath>
using namespace std;

/* Prototypes */

int findDNAMatch(string s1, string s2, int start = 0);
string matchingStrand(string strand);
void findAllMatches(string s1, string s2);

/* Main program */

int main() {
   findAllMatches("TTGCC", "TAACGGTACGTC");
   findAllMatches("TGC", "TAACGGTACGTC");   //这里是不是多了个空格？
   findAllMatches("CCC", "TAACGGTACGTC");
   return 0;
}

/*
 * Function: findAllMatches
 * Usage: findAllMatches(s1, s2);
 * ------------------------------
 * Finds all positions at which s1 can bind to s2.
 */

void findAllMatches(string s1, string s2) {
   int start = 0;
   while (true) {
      int index = findDNAMatch(s1, s2, start);
      if (index == -1) break;
      cout << s1 << " matches " << s2 << " at position " << index << endl;
      start = index + 1;
   }
   if (start == 0) {
      cout << s1 << " has no matches in " << s2 << endl;
   }
}


/*
 * Function: findDNAMatch
 * Usage: int pos = findDNAMatch(s1, s2);
 *        int pos = findDNAMatch(s1, s2, start);
 * ---------------------------------------------
 * Returns the first index position at which strand s1 would bind to
 * the strand s2, or -1 if no such position exists.  If the start
 * parameter is supplied, the search begins at that index position.
 */

int findDNAMatch(string s1, string s2, int start) {

    int l1 = s1.length();
    int l2 = s2.length();
    bool flag;
    string tmp = matchingStrand(s1);
    for(int i = start;i<l2-l1;i++)  //外层循环s2,内层循环s1,将s1的每一个字符和每段s2对比
    {
        flag = false;
        for(int j = 0;j<l1;j++)
        {
            if((tmp[j]!=s2[i+j]))  //abs(s1[j]-s2[j+i])!='T'-'A' && abs(s1[j]-s2[j+i]) != 'G'-'C'
            {                     //如此便不可以不用matchingStrand函数
                flag = false;
                break;          //枚举所有不恰当情况
            }
            flag = true;
        }
        if(flag == true) return i;
    }
    return -1;
}
string matchingStrand(string strand)
{
    string tno = "";
    int len = strand.length();
    for(int i =0;i<len;i++)             //一一对应
    {
        if(strand[i] == 'T') tno+="A";
        else if(strand[i] == 'C') tno += "G";
        else tno+="C";
    }
    return tno;
}
