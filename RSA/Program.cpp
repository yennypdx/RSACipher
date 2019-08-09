#include <iostream>
#include <iostream>
#include <algorithm>
#include <math.h>


using namespace std;

unsigned long long int gcd(unsigned long long int a, unsigned long long int b);
unsigned long long int mod_inverse(unsigned long long int a, unsigned long long int b);
unsigned long long int getCipherText(unsigned long long int nPublicKey,
	unsigned long long int ePublicKey, unsigned long long int msg);
unsigned long long int getPlainText(unsigned long long int nPublicKey, unsigned long long int dKey, 
	unsigned long long int msg);

// to be deleted
unsigned int generatePKey(){return 11930;}
unsigned int generateQKey(){return 12473;}

int main()
{
	unsigned long long int pKey = 0;
	unsigned long long int qKey = 0;
	unsigned long long int ePublicKey = 10000;
	unsigned long long int nPublicKey = 0;
	unsigned long long int totient = 0;
	unsigned long long int dKey = 0;
	unsigned long long int ciphered = 0;
	char choice = 'e';
	char ex = 'x';
	unsigned long long int messageToEncrypt = 0;
	unsigned long long int messageToDecrypt = 0;

	// TODO: attach the appropriate method to get p and q values below
	cout << "------------------------------------" << endl;
	cout << "          RSA CRYPTOGRAPHY          " << endl;
	cout << "------------------------------------" << endl << endl;

	cout << "Generating p-value..." << endl;
	pKey = generatePKey();
	cout << ">> p-Value: " << pKey << endl;
	cout << "Generating q-value..." << endl;
	qKey = generateQKey();
	cout << ">> q-Value: " << qKey << endl;
	totient = (pKey - 1) * (qKey - 1);	// generate phi-value
	nPublicKey = pKey * qKey;
	cout << std::endl;
	cout << "------------------------------------" << endl;	

	do
	{
		cout << "Choose to [e]ncrypt or [d]ecrypt: ";
		cin >> choice;
		switch (choice) {
		case 'e':
			cout << "Enter your message in an integer value: ";
			cin >> messageToEncrypt;
			ciphered = getCipherText(nPublicKey, ePublicKey, messageToEncrypt);

			cout << "Ciphered Message: " << ciphered << std::endl;
			std::cout << "------------------------------------" << std::endl;
			break;
		case 'd':
			unsigned long long int track;
			while (ePublicKey < totient) {
				track = gcd(ePublicKey, totient);
				if (track == 1)
					break;
				else
					ePublicKey++;
			}

			unsigned long long int d1 = 1 / ePublicKey;
			dKey = mod_inverse(d1, totient);

			cout << "Enter your encrypted message in an integer value: ";
			cin >> messageToDecrypt;
			unsigned long long int plainText = getPlainText(nPublicKey, dKey, messageToDecrypt);

			cout << "Decrypted Message: " << plainText << endl;
			std::cout << "------------------------------------" << std::endl;
			break;
		}
		
		cout << "Exit [y/n]: ";
		cin >> ex;
	} while (ex != 'y');
		
	std::cout << "------------------------------------" << std::endl;
	return 0;
}

unsigned long long int mod_inverse(unsigned long long int a, unsigned long long int b)
{
	unsigned long long int g[100], u[100], v[100];
	unsigned long long int i = 1;
	unsigned long long int y;
	g[0] = b;
	g[1] = a;
	u[0] = v[1] = 1;
	u[1] = v[0] = 0;

	while (g[i]){
		g[i] = u[i] * b + v[i] * a;
		y = g[i - 1] / g[i];
		g[i + 1] = g[i - 1] - y * g[i];
		u[i + 1] = u[i - 1] - y * u[i];
		i++;
	}

	if (v[i - 1] <= 0){
		return v[i - 1] + b;
	}else{
		return v[i - 1] + 2 * b;
	}
}

unsigned long long int gcd(unsigned long long int a, unsigned long long int b) {
	unsigned long long int t;
	while (1) {
		t = a % b;
		if (t == 0)
			return b;
		a = b;
		b = t;
	}
}

unsigned long long int getCipherText(unsigned long long int nPublicKey, 
	unsigned long long int ePublicKey, unsigned long long int msg)
{
	// Encryption c = (msg ^ e) % n
	unsigned long long int cipheredText = pow(msg, ePublicKey);
	cipheredText = cipheredText % nPublicKey;

	return cipheredText;
}

unsigned long long int getPlainText(unsigned long long int nPublicKey, 
	unsigned long long int dKey, unsigned long long int msg)
{
	// Decryption m = (c ^ d) % n 
	unsigned long long int plainText = pow(msg, dKey);
	plainText = plainText % nPublicKey;

	return plainText;
}