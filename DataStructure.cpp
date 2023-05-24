#include "DataStructure.h"
#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

// 根据科目排序， 有升序降序两种
void DS::sort(std::vector<Student> main_data, int subject, int order){
    //order = 1: 从小到大
    //order = 0: 从大到小
    if (order == 1){
        std::sort(main_data.begin(),main_data.end(),[&](Student a,Student b){return a.score[subject]<b.score[subject];});
    }
    else{
        std::sort(main_data.begin(),main_data.end(),[&](Student a,Student b){return a.score[subject]>b.score[subject];});
    }
    // print
    for (auto i : main_data){
        std::cout << i.name << " ";
        for (auto j : i.score){
            std::cout << j << " ";
        }
        std::cout << std::endl;
    }
}


// 根据科目求平均分
void DS :: getAverage(std::vector<Student> main_data, int subject){
    double sum = 0;
    for (auto i : main_data){
        sum += i.score[subject];
    }
    std::cout << "Average Score: " << sum / main_data.size() << std::endl;
    std::cout << std::endl;
}

// 根据科目求最高分
void DS :: findMaxscore(std::vector<Student> main_data, int subject){
    int max = 0;
    for (auto i : main_data){
        if (i.score[subject] > max){
            max = i.score[subject];
        }
    }
    std::cout << "Max Score: " << max << std::endl;
    std::cout << std::endl;
}

// 根据科目求最低分
void DS :: findMinscore(std::vector<Student> main_data, int subject){
    int min = 1000;
    for (auto i : main_data){
        if (i.score[subject] < min){
            min = i.score[subject];
        }
    }
    std::cout << "Min Score: " << min << std::endl;
    std::cout << std::endl;
}

// 根据姓名查找成绩
void DS :: findScoreByName(std::vector<Student> main_data, std::string name){
    for (auto i : main_data){
        if (i.name == name){
            for (auto j : i.score){
                std::cout << j << " ";
            }
            std::cout << std::endl;
            std::cout << std::endl;
            return;
        }
    }
    std::cout << "No such student!" << std::endl;
    std::cout << std::endl;
}

void DS :: printScore(std::vector<Student> main_data){
    for (auto i : main_data){
        std::cout << i.name << " ";
        for (auto j : i.score){
            std::cout << j << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}
