#include "ScoreManager.h"
#include "DataStructure.h"
#include <iostream>
#include <chrono>
#include <thread>

void timer(int seconds,std::vector<Student>& main_data)
{
    DS new_data;
    while (true) {
        std::this_thread::sleep_for(std::chrono::seconds(seconds));
        //在此处修改执行的函数
        new_data.getAverage(main_data,0);
    }
}

extern "C" int TimeWork(std::vector<Student>&main_data)
{
    int seconds = 5;
    std::thread t(timer, seconds,main_data);
    t.join();
    return 0;
}