#include <iostream>

//1.包含头文件
#include "../include/nlog.h"

//2.连接动态库的lib文件, 注意在项目设置中已将附加库目录设置为"$(SolutionDir)bin\msvc10\lib\"
#ifdef _DEBUG
#pragma comment(lib, "nlogd.lib")
#else
#pragma comment(lib, "nlog.lib")
#endif

int main()
{
    _NLOG_APP("Hello %s!", "World");                                        //打印C风格    多字节

    _NLOG_WAR() << nlog::time   << L" 从此刻起我们的征途便是星辰大海...";   //打印C++风格  宽字节

    _NLOG_ERR("Oh, %s! ", "No") << L"有人动了你的代码并在里面下了毒...";    //混搭式打印
    
    _NLOG_SHUTDOWN();                                                       //关闭nlog, 清理资源

    return 0;
}