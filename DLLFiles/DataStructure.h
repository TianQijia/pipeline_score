#include "Student.h"
#include <iostream>
#include <string>
#include <vector>
#include <map>

// 该类提供数据访问，排序，最大最小值，平均值和指定用户查询
class DS{
public:
    void sort(std::vector<Student> main_data, int subject, int order);
    void getAverage(std::vector<Student> main_data, int subject);
    void findMaxscore(std::vector<Student> main_data, int subject);
    void findMinscore(std::vector<Student> main_data, int subject);
    void findScoreByName(std::vector<Student> main_data, std::string name);
    void printScore(std::vector<Student> main_data);

};