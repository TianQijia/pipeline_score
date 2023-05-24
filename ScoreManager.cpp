#include "ScoreManager.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <string>
#include <vector>

int ScoreManager:: readFile(){
    // 确定科目数
    int numOfSubjectsInt = ScoreManager::subject.size();
    if (numOfSubjectsInt==0){
        std::cout<<"Please enter the number of subjects: (eg. 4)"<<std::endl;
        std::string numOfSubjects;
        std::cin >> numOfSubjects;
        int numOfSubjectsInt = std::stoi(numOfSubjects);
        // 确定科目名称,存入subject中
        // 用逗号分隔
        std::cout<<"Please enter the name of subjects: (eg. math,english,chinese)"<<std::endl;
        std::string nameOfSubjects;
        std:: cin >> nameOfSubjects;
        std::stringstream ss(nameOfSubjects);
        std::string item;
        for(int i=0;i<numOfSubjectsInt;i++){
            std::getline(ss, item, ',');
            ScoreManager::subject.push_back(item);
        }
    }
    // 读取文件路径，尝试打开
    std::cout<<"Please enter the filepath in this folder(including .txt):"<<std::endl;
    std::string filepath;
    std::cin>>filepath;
    std::ifstream input_file(filepath);
    if (!input_file.is_open()) {
        std::cerr << "Error: failed to open file." << std::endl;
        return 1;
    }

    // 逐行读取数据
    // 从文件里获取成绩
    std::string line;
    while (std::getline(input_file, line)) {
        std::vector<std::string> row;
        Student Temp;
        // 使用字符串流分割每行中的数据
        std::stringstream ss(line);
        std::string item;
        for(int i=0;i<=numOfSubjectsInt;i++){
            std::getline(ss, item, ',');
            if (i==0) Temp.name=item;
            else Temp.score.push_back(std::stoi(item));
        }
        ScoreManager::main_data.push_back(Temp);
    }

    input_file.close();
    std::cout << "Read file successfully!" << std::endl;
    std::cout << std::endl;
    return 0;

} 

// 将成绩输出到文件中
int ScoreManager::writeFile(){
    // 读取文件路径，尝试打开
    std::string filepath;
    std::cout<<"Please enter the filepath in this folder(including .txt):"<<std::endl;
    std::cin>>filepath;
    //导出数据至该文件中
    std::ofstream output_file(filepath);
    if (!output_file.is_open()) {
        std::cerr << "Error: failed to open file." << std::endl;
        return 1;
    }
    // 写入数据
    for(int i=0;i<ScoreManager::main_data.size();i++){
        output_file<<ScoreManager::main_data[i].name<<",";
        for(int j=0;j<ScoreManager::main_data[i].score.size();j++){
            output_file<<ScoreManager::main_data[i].score[j];
            if(j!=ScoreManager::main_data[i].score.size()-1) output_file<<",";
        }
        output_file<<std::endl;
    }
    std::cout << "Write file successfully!" << std::endl;
    std::cout << std::endl;
    return 0;
}

// 从命令行里输入数据
int ScoreManager::addData(){
    // 读取数据
    std::string name;
    std::cout<<"Please enter the name of the student: (eg. amy)"<<std::endl;
    std::cin>>name;
    if (ScoreManager::subject.size()==0){
        std::cout<<"Please enter the number of subjects: (eg. 4)"<<std::endl;
        std::string numOfSubjects;
        std::cin >> numOfSubjects;
        int numOfSubjectsInt = std::stoi(numOfSubjects);
        // 确定科目名称,存入subject中
        // 用逗号分隔
        std::cout<<"Please enter the name of subjects: (eg. math,english,chinese)"<<std::endl;
        std::string nameOfSubjects;
        std:: cin >> nameOfSubjects;
        std::stringstream ss(nameOfSubjects);
        std::string item;
        for(int i=0;i<numOfSubjectsInt;i++){
            std::getline(ss, item, ',');
            ScoreManager::subject.push_back(item);
        }
    }
    else{
        std :: cout << "The subjects order is: " ;
        for(int i=0;i<ScoreManager::subject.size();i++){
            std :: cout << ScoreManager::subject[i] << " ";
        }
        std :: cout << std::endl;

    }
    std::vector<int> score;
    std::cout<<"Please enter the scores of the student: eg(100,86,98)"<<std::endl;
    std::string scoreStr;
    std::cin>>scoreStr;
    std::stringstream ss(scoreStr);
    std::string item;
    while(std::getline(ss, item, ',')){
        score.push_back(stoi(item));
    }
    // 将数据加入到main_data中
    Student Temp;
    Temp.name=name;
    Temp.score=score;
    ScoreManager::main_data.push_back(Temp);
    std::cout << "Add data successfully!" << std::endl;
    std::cout << std::endl;
    return 0;
}

// 一个用户的全部成绩（一行）
int ScoreManager::modifyData(){
    // 读取数据
    std::string name;
    std::cout<<"Please enter the name of the student: (eg. amy)"<<std::endl;
    std::cin>>name;
    std::vector<int> score;
    std::cout<<"Please enter the scores of the student(a line): (eg. 100,46,78)"<<std::endl;
    std::string scoreStr;
    std::cin>>scoreStr;
    std::stringstream ss(scoreStr);
    std::string item;
    while(std::getline(ss, item, ',')){
        score.push_back(stoi(item));
    }
    // 将数据加入到main_data中
    for(int i=0;i<ScoreManager::main_data.size();i++){
        if(ScoreManager::main_data[i].name==name){
            ScoreManager::main_data[i].score=score;
            std::cout << "Modify data successfully!" << std::endl;
            return 0;
        }
    }
    std::cout << "Modify data failed!" << std::endl;
    std::cout << std::endl;
    return 1;
}


int ScoreManager::deleteData(){
    // 读取数据
    std::string name;
    std::cout<<"Please enter the name of the student: (eg. amy)"<<std::endl;
    std::cin>>name;
    // 将数据加入到main_data中
    for(int i=0;i<ScoreManager::main_data.size();i++){
        if(ScoreManager::main_data[i].name==name){
            ScoreManager::main_data.erase(ScoreManager::main_data.begin()+i);
            std::cout << "Delete data successfully!" << std::endl;
            return 0;
        }
    }
    std::cout << "Delete data failed!" << std::endl;
    std::cout << std::endl;
    return 1;
}

std::vector<Student> ScoreManager::getData(){
    return ScoreManager::main_data;
}