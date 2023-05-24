#include <iostream>
#include <string>
#include <vector>
#include <string>
#include <fstream>
#ifndef STUDENT_H
#define STUDENT_H


// 成绩单，初始化
struct Student{
    std::string name;
     //0:語文 1：數學 2：英語
    //当数据缺省（没有输入）的时候，就将数据设置为-1就行
    std::vector<int> score ={};
};

#endif