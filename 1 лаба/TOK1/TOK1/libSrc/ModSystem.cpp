#include "stdafx.h"
#include "ModSystem.h"
using namespace std;

bool ModSystem::areŅomparable(int comparedNumber, int number, int module)
{
	const int remainder = comparedNumber % module;
	const int remainder2 = number % module;
	return remainder == remainder2;
}

bool ModSystem::areŅomparable(vector<int> comparedNumbers, int number, int module)
{
	for (int i = 0; i < comparedNumbers.size(); i++) {
		if (!ModSystem::areŅomparable(comparedNumbers[i], number, module)) {
			return false;
		}
	}
	return true;
}
