#pragma once
class ModSystem {
	public static bool areÑomparable(int comparedNumber, int number, int module) {
		const int remainder = comparedNumber % module;
		const int remainder2 = number % module;
		return remainder == remainder2;
	}

	public static bool areÑomparable(array<int> comparedNumbers, int number, int module) {
		for (int i = 0; i < comparedNumbers.size(); i++) {
			if (!ModSystem.areÑomparable(comparedNumbers[i], number, module)) {
				return false;
			}
		}
		return true;
	}

};