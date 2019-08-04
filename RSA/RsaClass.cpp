#include "RsaClass.h"

RsaClass::RsaClass()
{
	pKey = 0;
	qKey = 0;
	nVal = 0;
	dPrivateKey = 0;
	phiVal = 0;
}

RsaClass::RsaClass(unsigned int pValue, unsigned int qValue, 
	unsigned int eValue, unsigned int nValue)
{
	pKey = pValue;
	qKey = qValue;
	nVal = nValue;
	phiVal = ((pValue - 1) * (qValue - 1));
	dPrivateKey = modInverse(eValue, phiVal);
}

unsigned long long int RsaClass::getCipherText(unsigned int nPublicKey, 
	unsigned int ePublicKey, unsigned int msg)
{
	// Encryption c = (msg ^ e) % n
	unsigned long long int cipheredText = pow(msg, ePublicKey);
	cipheredText = cipheredText % nPublicKey;

	return cipheredText;
}

unsigned long long int RsaClass::getPlainText(unsigned int nPublicKey, unsigned int msg)
{
	unsigned long long dVal = getPrivateKey();
	// Decryption m = (c ^ d) % n 
	unsigned long long plainText = pow(msg, dVal);
	plainText = plainText % nPublicKey;

	return plainText;
}

unsigned long long int RsaClass::gcd(unsigned int aVal, unsigned int bVal)
{
	unsigned long long temp;
	while (1)
	{
		temp = aVal % bVal;
		if (temp == 0)
			return bVal;
		aVal = bVal;
		bVal = temp;
	}
}

unsigned long long int RsaClass::modInverse(unsigned int eVal, unsigned int phi)
{
	// a x ≡ 1 (mod m) 
	eVal = eVal % phi;
	for (unsigned long long int x = 1; x < phi; x++)
		if ((eVal * x) % phi == 1)
			return x;
}
