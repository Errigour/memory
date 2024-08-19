#ifndef MEMORY_H
#define MEMORY_H
#include <array>
#include <string>
class circle {
public:
	double radius;
	circle(double value) {
		radius = value;
	}
	long double circumference() {
		long double area = 3.14159 * radius * 2;
		return area;
	}
};
namespace memory {
	extern std::wstring myname;
	extern std::array<std::string, 12> months;
	extern std::array<std::string, 7> days;
	extern circle circle_in_memory;
}
#endif