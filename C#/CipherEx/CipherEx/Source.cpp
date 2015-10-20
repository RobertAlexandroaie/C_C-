/*
Here is a string of bytes encoded in hex:
8776459cf37d459fbb7b5ecfbb7f5fcfb23e478aaa3e4389f378439aa13e4e96a77b5fc1f
358439df36a4486a03e4381b63e5580a66c0c8ebd6d5b8aa13e459cf34e4d9fa67f02cf90
714288a17f589abf7f5886bc705fcfbc700c96bc6b5ecfb7775f8cbc68499daa3f

This sequence has been encrypted with the same cipher as in Didactic XOR 2,
except here the key is four-bytes long. So the first byte of the plaintext is
enciphered with the first byte of the key, and so on, until the fifth byte of
the plaintext gets enciphered with the first byte of the key again.
*/

#include<stdio.h>
#include<string.h>
#include<string>

int main() {

	char cipherText[213];

	strcpy(cipherText, "8776459cf37d459fbb7b5ecfbb7f5fcfb23e478aaa3e4389f378439aa13e4e96a77b5fc1f358439df36a4486a03e4381b63e5580a66c0c8ebd6d5b8aa13e459cf34e4d9fa67f02cf90714288a17f589abf7f5886bc705fcfbc700c96bc6b5ecfb7775f8cbc68499daa3f");

	printf("%s", cipherText);
	cipherText[212] = NULL;

	system("pause");
	return 0;
}
