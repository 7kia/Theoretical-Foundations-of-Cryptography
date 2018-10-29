#include "CryptoPrimitives.h"

class CEncoder: public IEncoder {
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
	static byte encode(const vector<byte> message, const vector<int> key) {
		int keyIndex = 0;
		vector<byte> outputMessage = new vector<byte>();
		for (int i = 0; i < message.size(); i++) {
			const int intValue = static_cast<int>(message[i]);
			const int summaryValue = (intValue + key[keyIndex]);
			const int maxSymbolValue = static_cast<int>(std::numeric_limits<byte>::max());
			if (summaryValue > maxSymbolValue) {
				outputMessage.push_back(static_cast<byte>(summaryValue - maxSymbolValue));
			} 
			if else (summaryValue < 0) {
				outputMessage.push_back(static_cast<byte>(maxSymbolValue + summaryValue));
			}
			else {
				outputMessage.push_back(static_cast<byte>(summaryValue));
			}
			keyIndex = changeKeyIndex(keyIndex, key.size());
		}
	}
};

class CDecoder: public IDecoder {
private:
	int changeKeyIndex(const int index, const int maxValue) {
		if (index < maxValue) {
			return index + 1;
		}
		else {
			return 0;
		}
	}
public:
	byte decode(const vector<byte> message, const vector<int> key) {
		vector<int> reverseKey = new vector<int>();
		for (int i = 0; i < key.size(); i++) {
			reverseKey.push_back(-key[i]);
		}
		return CEncoder.encode(message, reverseKey);
	}
};