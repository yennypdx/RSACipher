#pragma once
#include <iostream>
#include <algorithm>
#include <math.h>

class RsaClass
{
private:
	unsigned long long int dPrivateKey;

protected:	
	unsigned int pKey;
	unsigned int qKey;
	unsigned int nVal;
	unsigned long long int phiVal;
	
public:
	RsaClass();
	RsaClass(unsigned int pValue, unsigned int qValue, unsigned int eValue, unsigned int nValue);

public:
	unsigned int getPrivateKey() { return dPrivateKey; }
	unsigned long long getPhiVal() { return phiVal; }

public:
	unsigned long long int getCipherText(unsigned int nPublicKey, unsigned int ePublicKey, unsigned int msg);
	unsigned long long int getPlainText(unsigned int nPublicKey, unsigned int msg);
	unsigned long long int gcd(unsigned int aVal, unsigned int bVal);
	unsigned long long int modInverse(unsigned int eVal, unsigned int nVal);
};
