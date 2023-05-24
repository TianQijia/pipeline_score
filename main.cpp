#include "ScoreManager.h"
#include "DataStructure.h"
#include <windows.h>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <thread>
#include <algorithm>

//读取动态库并运行
void InstallLibrary()
{
    typedef void (*TimeWorkFunc)(std::vector<Student>& main_data);
    
    HINSTANCE hGetProcIDDLL = LoadLibrary("my_plugin.dll");

    if (!hGetProcIDDLL) {
        std::cout << "could not load the dynamic library" << std::endl;
        return ;
    }

    TimeWorkFunc TimeWork = (TimeWorkFunc)GetProcAddress(hGetProcIDDLL, "TimeWork");

    if (!TimeWork) {
        std::cout << "could not locate the function" << std::endl;
        return ;
    }

    std::vector<Student> main_data;
    TimeWork(main_data);

    FreeLibrary(hGetProcIDDLL);
    return ;
}

int main()
{
    ScoreManager sm;
    DS ds;
    int choice;
    //注意，这种方法开启线程之后，无法自动销毁线程，因此只能读取一次数据后运行
    std::thread t(InstallLibrary);
    t.detach();
    while (true)
    {
        std::cout << "------------------------------------- " << std::endl;
        std::cout << "please enter number bewtween 0 and 8: " << std::endl;
        std::cout << "0: exit" << std::endl;
        std::cout << "1: add score from file" << std::endl;
        std::cout << "2: add score from command line" << std::endl;
        std::cout << "3: modify score" << std::endl;
        std::cout << "4: delete score" << std::endl;
        std::cout << "5: sort score" << std::endl;
        std::cout << "6: get average score" << std::endl;
        std::cout << "7: get max score" << std::endl;
        std::cout << "8: get min score" << std::endl;
        std::cout << "9: get score by name" << std::endl;
        std::cout << "------------------------------------- " << std::endl;
        std::cin >> choice;
        std::string pos;
        switch (choice)
        {
            case 0:
                sm.writeFile();
                return 0;
            case 1:
                sm.readFile();
                break;
            case 2:
                sm.addData();
                break;
            case 3:
                sm.modifyData();
                break;
            case 4:
                sm.deleteData();
                break;
            case 5:
                // order = 1: 从小到大
                // order = 0: 从大到小
                int order;
                std::cout << "please enter the subject and order: (eg math 1[rising]/0[declining]) " << std::endl;
                std::cin >> pos >> order;
                for (int i = 0; i < sm.subject.size(); i++)
                {
                    if (sm.subject[i] == pos)
                    {
                        ds.sort(sm.main_data, i, order);
                    }
                }
                break;
            case 6:
                std::cout << "please enter the subject: " << std::endl;
                std::cin >> pos;
                for (int i = 0; i < sm.subject.size(); i++)
                {
                    if (sm.subject[i] == pos)
                    {
                        ds.getAverage(sm.main_data, i);
                        break;
                    }
                }
                break;
            case 7:
                std::cout << "please enter the subject: " << std::endl;
                std::cin >> pos;
                for (int i = 0; i < sm.subject.size(); i++)
                {
                    if (sm.subject[i] == pos)
                    {
                        ds.findMaxscore(sm.main_data, i);
                        break;
                    }
                }
                break;
            case 8:
                std::cout << "please enter the subject: " << std::endl;
                std::cin >> pos;
                for (int i = 0; i < sm.subject.size(); i++)
                {
                    if (sm.subject[i] == pos)
                    {
                        ds.findMinscore(sm.main_data, i);
                        break;
                    }
                }
                break;
            case 9:
                std::cout << "please enter the name: " << std::endl;
                std::cin >> pos;
                ds.findScoreByName(sm.main_data, pos);
                break;
            default:
                std::cout << "invalid choice" << std::endl;
                break;
        }
    }
    return 0;
}