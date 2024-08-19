#include <chrono>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <string>
#include "commands.h"
using namespace std;
extern struct commands comm[];
std::wstring GetDateTime() {
    time_t rawtime;
    struct tm timeinfo;
    wchar_t buffer[20];
    time(&rawtime);
    localtime_s(&timeinfo, &rawtime);
    auto now = std::chrono::system_clock::now();
    auto tt = std::chrono::system_clock::to_time_t(now);
    auto nowTruncated = std::chrono::system_clock::from_time_t(tt);
    auto ms = (now - nowTruncated).count();
    wcsftime(buffer, 20, L"%Y-%m-%d %H:%M:%S", &timeinfo);
    return std::wstring(buffer) + L"." + std::to_wstring(ms).substr(0, 3);
}
static void training() {
    int a(38);
    int b{1};
    std::wstring mifan;
    int result = a + b;
    mifan = LR"(\ The result of )" + std::to_wstring(a) + L" plus " + std::to_wstring(b) + L" is ";
    std::wcout<<mifan<<result<<L" */"<<std::endl;
    cout << R"( \                              /)" << endl;
    cout << R"(  \    """"""""""""""""""""    /)" << endl;
    cout << R"(   \""""""""""""""""""""""""""/)" << endl;
    cout << R"(    \"""""""""mifan""""""""""/)" << endl;
    cout << R"(     \""""""""""""""""""""""/)" << endl;
    cout << R"(      \--------------------/)" << endl;
}
int main(int argc, char* argv[]) {
    std::wstring buf;
    wcout<<GetDateTime()<<endl;
    srand(static_cast<unsigned int>(time(0)));
    training();
    getline(std::wcin, buf);
    if (buf == L"3.14159") {
        do {
            std::cout << "I will echo!\n";
            getline(std::wcin, buf);
            for (wchar_t c : buf) {
                std::wcout << L"[" << c << L"]";
            }
            std::cout << std::endl;
            for (wchar_t c : buf) {
                cout << "[0x" << hex << static_cast<int>(c) << dec << "]";
            }
            std::cout << std::endl;
            /* iterrate through commands and compare them with buf and checks if sizes
            are equal or that there is definitely a proceeding space. Then runs the command
            function. Otherwise it would run dance if they typed danced.*/
            for (int i = 0; comm[i].command != L""; i++) {
                if (buf.compare(0, comm[i].command.size(), comm[i].command) == 0) {
                    if (buf.size() == comm[i].command.size() || buf.size() > comm[i].command.size() && buf[comm[i].command.size()] == ' ')
                        comm[i].func(buf);
                }
            }
        } while (buf != L"q");
    }
}