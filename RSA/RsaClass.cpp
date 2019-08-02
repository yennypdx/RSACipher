#include "RsaClass.h"

RsaClass::RsaClass()
{
	pKey = 0;
	qKey = 0;
	nVal = 0;
	dPrivateKey = 0;
	phiVal = 0;
}

RsaClass::RsaClass(int pValue, int qValue, int eValue, int nValue)
{	
	pKey = pValue;
	qKey = qValue;
	nVal = nValue;	
	phiVal = ((pValue-1)*(qValue-1));
	dPrivateKey = modInverse(eValue, phiVal);
}

int RsaClass::getCipherText(int nPublicKey, int ePublicKey, int msg)
{
	// Encryption c = (msg ^ e) % n
	int cipheredText = pow(msg, ePublicKey);
	cipheredText = cipheredText % nPublicKey;

	return cipheredText;
}

int RsaClass::getPlainText(int nPublicKey, int ePublicKey, int msg)
{
	int dVal = getPrivateKey();
	// Decryption m = (c ^ d) % n 
	int plainText = pow(msg, dVal);
	plainText = plainText % nPublicKey;

	return plainText;
}

int RsaClass::gcd(int a, int b)
{
	int temp;
	while (1)
	{
		temp = a % b;
		if (temp == 0)
			return b;
		a = b;
		b = temp;
	}
}

int RsaClass::modInverse(int eVal, int phi)
{
	// a x ≡ 1 (mod m) 
	eVal = eVal % phi;
	for (int x = 1; x < phi; x++)
		if ((eVal * x) % phi == 1)
			return x;
}
