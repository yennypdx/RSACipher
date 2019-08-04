#include <iostream>
#include "RsaClass.h"

int main()
{
	/* Assumed Keys Generated */
	unsigned int p = 907;
	unsigned int q = 773;
	
	/* Public Keys */
	unsigned int ePublicKey = 11;
	unsigned int nPublicKey = p * q;

	RsaClass rsa(p, q, ePublicKey, nPublicKey);
	
	/* Plain Text from User */
	unsigned int originalMessage = 4;
	std::cout << "MessageText: " << originalMessage << std::endl;
	
	/* Encryption */
	unsigned long long int ciphered =  rsa.getCipherText(nPublicKey, ePublicKey, originalMessage);
	std::cout << "CipheredText: " << ciphered << std::endl;

	/* Decryption */
	unsigned long long int message = rsa.getPlainText(nPublicKey, ciphered);
	std::cout << "Decrypted Message: " << message << std::endl;

	return 0;
}