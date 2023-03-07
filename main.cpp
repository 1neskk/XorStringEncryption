#include <vector>
#include <cstring>
#include <iostream>
#include <string>


char* xor_encrypt(const char* key, const char* plaintext) {
	size_t key_len = strlen(key);
	size_t plaintext_len = strlen(plaintext);

	char* encrypted = new char[plaintext_len + 1];
	for (size_t i = 0; i < plaintext_len; i++) {
		encrypted[i] = plaintext[i] ^ key[i % key_len];
	}
	encrypted[plaintext_len] = '\0';
	return encrypted;
}

char* xor_decrypt(const char* key, const char* encrypted) {
	size_t key_len = strlen(key);
	size_t encrypted_len = strlen(encrypted);

	char* decrypted = new char[encrypted_len + 1];
	for (size_t i = 0; i < encrypted_len; i++) {
		decrypted[i] = encrypted[i] ^ key[i % key_len];
	}
	decrypted[encrypted_len] = '\0';
	return decrypted;
}

int main() {
	const char* key = "my_secret_key";
	const char* plaintext = "Hello, world!";

	char* encrypted = xor_encrypt(key, plaintext);
	std::cout << "Encrypted string: " << encrypted << std::endl;

	char* decrypted = xor_decrypt(key, encrypted);
	std::cout << "Decrypted string: " << decrypted << std::endl;

	delete[] encrypted;
	delete[] decrypted;

	return 0;
}
