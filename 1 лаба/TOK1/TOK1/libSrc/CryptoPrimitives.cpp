#include "stdafx.h"
#include "CryptoPrimitives.h"
#include <vector>

using namespace std;

typedef unsigned char WordType;
class CEncoder: public IEncoder<WordType> {
private:
	static int changeKeyIndex(const int index, const int maxValue) {
		if (index < maxValue) {
			return index + 1;
		}
		else {
			return 0;
		}
	}
public:
	WordType encode(const vector<WordType> message, const vector<int> key) {
		int keyIndex = 0;
		vector<WordType> outputMessage = vector<WordType>();
		for (int i = 0; i < message.size(); i++) {
			const int intValue = static_cast<int>(message[i]);
			const int summaryValue = (intValue + key[keyIndex]);
			const int maxSymbolValue = static_cast<int>(std::numeric_limits<WordType>::max());
			if (summaryValue > maxSymbolValue) {
				outputMessage.push_back(static_cast<WordType>(summaryValue - maxSymbolValue));
			} 
			else if (summaryValue < 0) {
				outputMessage.push_back(static_cast<WordType>(maxSymbolValue + summaryValue));
			}
			else {
				outputMessage.push_back(static_cast<WordType>(summaryValue));
			}
			keyIndex = changeKeyIndex(keyIndex, key.size());
		}
	}
	WordType decode(const vector<WordType> message, const vector<int> key) {
		vector<int> reverseKey = vector<int>();
		for (int i = 0; i < key.size(); i++) {
			reverseKey.push_back(-key[i]);
		}
		return encode(message, reverseKey);
	}
};