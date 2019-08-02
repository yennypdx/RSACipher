#pragma once
#include <iostream>
#include <algorithm>
#include <math.h>

class RsaClass
{
private:
	int dPrivateKey;

protected:	
	int pKey;
	int qKey;
	int nVal;	
	int phiVal;
	
public:
	RsaClass();
	RsaClass(int pValue, int qValue, int eValue, int nValue);

public:
	int getPrivateKey() { return dPrivateKey; }
	int getPhiVal() { return phiVal; }

public:
	int getCipherText(int nPublicKey, int ePublicKey, int msg);
	int getPlainText(int nPublicKey, int ePublicKey, int msg);
	int gcd(int a, int b);
	int modInverse(int eVal, int nVal);
};
