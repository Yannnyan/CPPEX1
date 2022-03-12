# include <cstdlib>
# include <iostream>
# include "mat.hpp"
using namespace std;

constexpr int START = 33;
constexpr int END = 127;
char swapChar(char x, char y, char cur){
    return cur == x ? y : x;
}
string createRow(string last, char cur, int size, int start, int end){
    string curStr;
    if (last.empty()){
        for(int i=0; i< size; i++){
            curStr += cur;
        }
        return curStr;
    }
    for(int i=0; i< size; i++){
        if(i < start || i > end){
            curStr += last.at(i);
        }
        else{
            curStr += cur;
        }
    }
    return curStr;
}

string insertRow(string last, string newRow, int at, int sizeRow, int numRows){
    // 0 1 2 3 4 5 6 7 8 9
    int insertAt = at * sizeRow;
    if (newRow.empty()){
        return last;
    }
    if (last.empty()){
        return newRow;
    }
    string left = last.substr(0, insertAt);
    string right = last.substr(insertAt, (sizeRow * numRows) - insertAt);
    left.append(newRow);
    return left.append(right);
}

string transition(string ret, int a, int b){
    string l;
    for(int i=0; i< b; i++){
        for(int j=0; j< a; j++){
            l += ret.at(i * a + j);
        }
        l+= '\n';
    }
    return l;
}

string ariel::mat(int a, int b, char x, char y){
    if ((int)x < START || (int)y < START || (int)x >= END  || (int)y >= END){
        throw std::invalid_argument("Bad character.");
    }
    if(a <=0 || b <= 0){
        throw std::invalid_argument("rows or collumns cant be zero or negative.");
    }
    if(a % 2 == 0 || b % 2 == 0){
        throw std::invalid_argument("Mat size is always odd.");
    }
    if (a == 1 && b == 1){
        return string(1,x);
    }
    int i = 0;
    int j =0;
    string ret;
    string last;
    char cur = x;
    int insertAt = -1;
    for(i=0; i< b; i++){
        last = createRow(last, cur, a, j, a-j-1);
        ret = insertRow(ret, last, j, a, i);
        if(i % 2 == 1){
            j++;
            cur = swapChar(x,y, cur);
        }
    }
    return transition(ret,a,b);
}

