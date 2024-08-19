#ifndef COMMANDS_H
#define COMMANDS_H
#include <string>
#define FUNC(name) static void name(std::wstring com)
struct commands {
	std::wstring command;
	void (*func)(std::wstring com);
};
#endif