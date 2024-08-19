#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <stdio.h>
#include <string>
#include <sstream>
#include <thread>
#include "commands.h"
#include "memory.h"
using namespace std;
extern std::wstring random_name(short int LON);
extern unsigned long long factorial(unsigned short int a);
FUNC(dance) {
    cout << "\\o/\n";
    cout << " | \n";
    cout << "/ \\\n";
    cout << "*Huzza*\n";
    this_thread::sleep_for(chrono::milliseconds(2024));
    cout << "-\\o/\n";
    cout << " -| \n";
    cout << "-/ \\\n";
    cout << "*Swoosh*\n";
    this_thread::sleep_for(chrono::milliseconds(2024));
    cout << "\\o/-\n";
    cout << " |- \n";
    cout << "/ \\-\n";
    cout << "*Woosh*\n";
    this_thread::sleep_for(chrono::milliseconds(2024));
    cout << "\\o/\n";
    cout << " |/\n";
    cout << "/  \n";
    cout << "*Hua*\n";
    this_thread::sleep_for(chrono::milliseconds(2024));
    cout << "\\o/\n";
    cout << "\\| \n";
    cout << "  \\\n";
    cout << "*Hah*\n";
    this_thread::sleep_for(chrono::milliseconds(2024));
    cout << " o \n";
    cout << "/|\\\n";
    cout << "/ \\\n";
    cout << "*Oh Yea*\n";
    this_thread::sleep_for(chrono::milliseconds(2024));
    cout << "Phew that was fun!\n";
}
FUNC(date) {
    time_t rawtime;
    struct tm timeinfo;
    rawtime = time(nullptr);
    if (localtime_s(&timeinfo, &rawtime) != 0) {
        std::cerr << "Error converting time." << std::endl;
        cout << "Bzzt...... Error converting time.\n";
    }
    else {
        std::cout << "Boop beep boop. The date is, " << timeinfo.tm_mon+1 << "/" << timeinfo.tm_mday << "/" << timeinfo.tm_year + 1900 - 2000 << "." << std::endl;
    }
}
FUNC(dayofweek) {
    time_t rawtime;
    struct tm timeinfo;
    rawtime = time(nullptr);
    if (localtime_s(&timeinfo, &rawtime) != 0) {
        std::cerr << "Error converting time." << std::endl;
        cout << "Bzzt...... Error converting time.\n";
    }
    else {
        std::cout << "Beeeeeeep. Today is, " << memory::days[timeinfo.tm_wday] << "." << endl;
    }
}
FUNC(factor) {
    unsigned short int factor;
    unsigned long long result;
    string output;
    if (com.size() > 7) {
        std::wstringstream(com.substr(7)) >> factor;
        output = "The factorial of "+to_string(factor)+" is ";
        result = factorial(factor);
        if (result == 5)
            std::cout << "I'm not capable of factoring that number.\n";
        else
        {
            output += to_string(result) + ".\n";
            std::cout << output;
        }
    }
}
FUNC(help) {
    unsigned short int index;
    cout << "Roger roger, echo delta foxtrot, man down!\n";
    if (com[0] == '?')
        index = 2;
    else
        index = 5;
    if (com.size() > index) {
        if (com.compare(index, 5, L"dance") == 0) {
            cout << "I will do a jig for you if you type \"dance\".\n";
        }
        else if (com.compare(index, 4, L"date") == 0) {
            cout << "I will tell you the date.\n";
        }
        else if (com.compare(index, 9, L"dayofweek") == 0) {
            cout << "I will tell you the day of the week.\n";
        }
        else if (com.compare(index, 6, L"factor") == 0) {
            cout << "I will find the factorial of numbers 0 through 19.\n"
                    "Just type \"factor 7\" to see the factorial of 7.\n";
        }
        else if (com.compare(index, 4, L"help") == 0 || com.compare(index, 1, L"?") == 0) {
            cout << "\"Help\" will display the default help text along with the commands.\n"
                    "If you want help with a command type \"help command\".\n";
        }
        else if (com.compare(index, 5, L"MaxUp") == 0 || com.compare(index, 1, L"?") == 0) {
            cout << "This will start the MaxUp game.\n";
        }
        else if (com.compare(index, 5, L"namer") == 0) {
            cout << "I will tell you a random name 3 characters long. If you provide an\n"
                    "argument between 1 to 7. Example \"namer 5\", I will pick a name\n"
                    "that long. Be warned the highest number 7 takes a bit of time so\n"
                    "be prepared to type alt+F4 to close the terminal.\n";
        }
        else if (com.compare(index, 4, L"name") == 0) {
            cout << "The command \"name\" by itself will prompt me to tell you my name.\n"
                    "If you type something after \"name\" it will change my name to what you type.\n"
                    "An example of this is typing \"name Bob\".\n";
        }
        else if (com.compare(index, 4, L"time") == 0) {
            cout << "I will tell you the time if you type \"time\". Alternatively you can\n"
                    "type \"time extend\" to see the extended time data.\n";
        }
        else
            cout << "Not sure I know that command, did you misstype help?\n";
    }
    else {
        wcout << L"I am " << memory::myname << L". I am an artificial intelligent robot.\n";
        cout << "I can process the following commands.\n";
        cout << "\"dance\" \"date\" \"dayofweek\" \"factor\" \"help\" \"MaxUp\" \"name\" \"namer\" \"time\" \"?\".\n";
        cout << "Type \"help command\" for more help on each command.\n";
    }
}
FUNC(MaxUp) {
    struct stats {
        short int l; //level
        short int m; //muscles
    } s; //student
    char* input = 0;
    char playing = 1;
    input = (char *)malloc(3);
    s.l = 1;
    s.m = 0;
    if (!input)
        cout << "Memory error initializing MaxUp.\n";
    while (playing == 1) {
        printf("Max Up!\n");
        printf("1. Train 2. Fight 3. Exit ");
        fgets(input, 3, stdin);
        if (input[1] != '\n' || (input[0] != '\n' && input[1] != '\n')) {
            while (input[0] != '\n' && input[1] != '\n')
                fgets(input, 3, stdin);
            input[0] = 0;
        }
        if (input[1] != '\n' || input[0] < '1' || input[0]>'3') {
            printf("Incorrect Input\n");
            continue;
        }
        if (input[0] == '3') {
            playing = 0;
            printf("May you train another day!\n");
        }
        if (input[0] == '1') {
            if (s.m < 20) {
                s.m++;
            }
            else
                printf("Your muscles are Maxed Up!\n");
            printf("Muscles: %d\n", s.m);
        }
        if (input[0] == '2') {
            if (s.m >= s.l * 2) {
                s.l++;
                if (s.l >= 10) {
                    printf("+------------------------------+\n");
                    printf("|Victory, you are now a Master!|\n");
                    printf("|Level: %d                     |\n", s.l);
                    printf("|Muscles: %d                   |\n", s.m);
                    printf("+------------------------------+\n");
                    playing = 0;
                }
                else
                    printf("Level: %d\n", s.l);
            }
            else {
                printf("You were defeated!\n");
            }
        }
    }
    if (input)
        free(input);
}
FUNC(name) {
    if (com.size() > 5)
        memory::myname = com.substr(5);
    wcout << L"My name is " + memory::myname + L".\n";
}
FUNC(namer) {
    wstring name;
    short int LON;
    if (com.size() > 6) {
        std::wstringstream(com.substr(6)) >> LON;
        if (LON > 0 && LON < 8)
            name = random_name(LON);
        else {
            cout << "I can only calculate names with length 1 to 7. Otherwise it will take forever.\n";
            return;
        }

    }
    else {
        name = random_name(3);
    }
    if (name != L"")
        wcout << L"Let's see, I guess a random name would be " << name << L".\n";
    else
        cout << "Another error has occured and I can't generate a name.\n";
}
FUNC(ptr) {
    int a;
    int* ptr = new (nothrow) int;
    int* ptr2 = new (nothrow) int[5];
    if (ptr) {
        *ptr = 38;
        cout << ++(*ptr) << endl;
        delete ptr;
    }
    if (ptr2) {
        ptr2[0] = 39;
        ptr2[1] = 40;
        ptr2[2] = 41;
        ptr2[3] = 42;
        ptr2[4] = 43;
        for (a = 0; a < 5; a++)
            cout << ++(*(ptr2+a)) << endl;
        delete[] ptr2;
    }
    cout << "You're to old!\n";
}
FUNC(sniff) {
}
FUNC(time) {
    time_t rawtime;
    struct tm timeinfo;
    rawtime = time(nullptr);
    if (localtime_s(&timeinfo, &rawtime) != 0) {
        std::cerr << "Error converting time." << std::endl;
        cout << "Bzzt...... Error converting time.\n";
    }
    else {
        if (com.size() == 4) {
            std::cout << "Beep boop beep. The time is, " << timeinfo.tm_hour << ":";
            cout << setw(2) << setfill('0') << timeinfo.tm_min;
            cout << std::defaultfloat << "." << std::endl;
        }
        else if( com.size() > 5 && com.compare(5, 6, L"extend") == 0) {
            cout << "Extended Time:\n";
            std::cout << "Year: " << (timeinfo.tm_year + 1900) << std::endl;
            std::cout << "Month: " << memory::months[timeinfo.tm_mon] << std::endl;
            std::cout << "Day: " << timeinfo.tm_mday << std::endl;
            std::cout << "Day of week: " << memory::days[timeinfo.tm_wday] << std::endl;
            std::cout << "Hour: " << timeinfo.tm_hour << std::endl;
            std::cout << "Minute: " << timeinfo.tm_min << std::endl;
            std::cout << "Second: " << timeinfo.tm_sec << std::endl;
        }

    }
}
struct commands comm[] = {
{ L"dance", dance },
{ L"date", date },
{ L"dayofweek", dayofweek },
{ L"factor", factor },
{ L"help", help },
{ L"MaxUp", MaxUp },
{ L"name", name },
{ L"namer", namer },
{ L"ptr", ptr },
{ L"sniff", sniff },
{ L"time", time },
{ L"?", help },
{ L"", 0 } };