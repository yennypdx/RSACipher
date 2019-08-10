import gmpy2

p = 15485867
q = 32452867
e = 9192679

p2 = 14567881
q2 = 15245513
e2 = 12136141

p3 = 14368993
q3 = 11508703
e3 = 3306811

print("------------------------------------")
print("          RSA CRYPTOGRAPHY          ")
print("------------------------------------\n")
number_to_encrypt = int(input("Enter your plain text to encrypt: "))

print("\nSet #1")
print("p=", p)
print("q=", q)
print("e=", e)
print("Set #2")
print("p=", p2)
print("q=", q2)
print("e=", e2)
print("Set #3")
print("p=", p3)
print("q=", q3)
print("e=", e3)
print("Please choose the set you are going to use from the above list!")
p = int(input("\nEnter the number for p-value: "))
q = int(input("Enter the number for q-value: "))
e = int(input("Enter the number for e-value: "))



print()
n = p*q
phi_n = (p-1)*(q-1)
print("n-Value: ", n)
print("totient value: ", phi_n)

def is_coprime_phi(phi_n, coprime_to_check):
    while phi_n % coprime_to_check == 0:
        coprime_to_check = input("Enter a prime number, to check if coprime with phi_n")
        e = coprime_to_check
    return True

if not is_coprime_phi(phi_n,e):
        raise ValueError("e is not coprime with phi_n")
        
def egcd(a, b):
    if a == 0:
        return (b, 0, 1)
    else:
        g, y, x = egcd(b % a, a)
        return (g, x - (b // a) * y, y)
    
def modinv(coprime, phi_n):
    g, x, y = egcd(coprime, phi_n)
    if g != 1:
        raise Exception('modular inverse does not exist')
    else:
        return x % phi_n
    
d = modinv(e, phi_n)
print("d-value: ", d)
pub_k = [e, n]
priv_k = [d, n]


def encrypt_this(m):
    result = gmpy2.powmod(m, e, n)
    return result

def decrypt_this(c):
    plain = gmpy2.powmod(c,d,n)
    return plain

choice = input("Would you like to [e]ncrypt or [d]ecrypt: ")
if(choice == 'e'):
    print()
    enc = encrypt_this(number_to_encrypt)
    print("Encrypted number: ", enc)
    print()
else:
    print(d)
    dec = decrypt_this(number_to_encrypt)
    print("Decrypted plain number: ", dec)
    print()