#include <iostream>
#include "RsaClass.h"

int main()
{
	/* Assumed Keys Generated */
	int p = 907;
	int q = 773;
	
	/* Public Keys */
	int ePublicKey = 11;
	int nPublicKey = p * q;

	RsaClass rsa(p, q, ePublicKey, nPublicKey);
	
	/* Plain Text from User */
	int originalMessage = 4;
	std::cout << "MessageText: " << originalMessage << std::endl;
	
	/* Encryption */
	int ciphered =  rsa.getCipherText(nPublicKey, ePublicKey, originalMessage);
	std::cout << "CipheredText: " << ciphered << std::endl;

	/* Decryption */
	int message = rsa.getPlainText(nPublicKey, nPublicKey, ciphered);
	std::cout << "Decrypted Message: " << message << std::endl;

	return 0;
}