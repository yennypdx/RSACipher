import gmpy2
number_to_encrypt = 11123123

# variables
p = 102433
q = 104233
e = 10321

n = p*q

phi_n = (p-1)*(q-1)
print("Totient: ", phi_n)
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
print("d variable: ", d)

pub_k = [e, n]

priv_k = [d, n]
print("Priv key: ", priv_k)
def encrypt_this(m):
    result = gmpy2.powmod(m, e, n)
    return result

def decrypt_this(c):
    plain = gmpy2.powmod(c,d,n)
    return plain

enc = encrypt_this(number_to_encrypt)
print("Encrypted number: ", enc)

dec = decrypt_this(enc)
print("Decrypted plain number: ", dec)
