#include "Student.h"
#include <iostream>
#include <map>
#include <string>
#include <vector>

// 该类提供文件输入数据，命令行输入数据，数据增删改查，数据提取和输出
class ScoreManager{
public:
    int readFile();
    int writeFile();
    int addData();
    int modifyData();
    int deleteData();
    std::vector<Student> getData();
    std::vector<std::string> subject = {};
    std::vector<Student> main_data;
    
};