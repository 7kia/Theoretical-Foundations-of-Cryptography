#pragma once

class IEncoder {
public:
	virtual byte encode(const vector<byte> message, const vector<int> key);
};

class IDecoder {
public:
	virtual byte decode(const vector<byte> message, const vector<int> key);
};

