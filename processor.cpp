#include <iostream>
#include <new>
#include <random>
#include "memory.h"
std::random_device rd;
std::mt19937_64 gen(rd());
template<class T, class U>
T divide(T a, U b) {
	return a / b;
}
template<class T, class U>
T fixed_multiply(T val) { /* declare like this fixed_multiply<int,2>(10) */
	return val * U;
}
unsigned long long factorial(unsigned short int a) {
	unsigned long long result;
	if (a <= 19) {
		if (a > 1) {
			result = a * factorial(a - 1);
			return(result);
		}
		else
			return 1;
	}
	else {
		return 5; /* This is my error number */
	}
}
static unsigned long long int find_rand_for_name(short int c, short int LON, unsigned long long int count) {
	int i;
	for (i = 'a'; i <= 'z'; i++) {
		if (c == LON - 1) {
			count++;
		}
		if (c < LON - 1)
			count = find_rand_for_name(c + 1, LON, count);
	}
	return count;
}
static wchar_t * find_random_name(short int c, short int LON, wchar_t* name, unsigned long long int *count, unsigned long long int rand) {
	int i;
	wchar_t* check = 0;
	if (c == 0)
		name = new (std::nothrow) wchar_t[LON + 1];
	if (name) {
		for (i = 'a'; i <= 'z'; i++) {
			if (c == 0)
				i -= 32;
			name[c] = i;
			if (c == 0)
				i += 32;
			if (c == LON - 1) {
				(*count)++;
				if (rand == *count) {
					name[c + 1] = 0;
					return name;
				}
			}
			if (c < LON - 1 && !check)
				check = find_random_name(c + 1, LON, name, count, rand);
			if (check)
				return check;
			name[c + 1] = 0;
		}
	}
	else {
		std::cout << "I have encountered an error allocating memory for a name.";
	}
	return 0;
}
std::wstring random_name(short int LON) {
	unsigned long long int count = 0;
	unsigned long long int rd;
	wchar_t* name_buf;
	std::wstring name;
	rd = find_rand_for_name(0, LON, 0);
	std::uniform_int_distribution<unsigned long long> distribution(0, rd);
	rd = distribution(gen);
	name_buf = find_random_name(0, LON, 0, &count, rd);
	if(name_buf)
		name = name_buf;
	else {
		std::cout << "[count is " << count << "]\n";
		name = L"";
	}
	delete[] name_buf;
	return name;
}