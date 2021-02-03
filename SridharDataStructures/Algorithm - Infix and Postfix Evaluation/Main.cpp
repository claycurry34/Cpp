#define _CRT_SECURE_NO_WARNINGS
#include "StringClass.h"
using namespace std;

int main()
{
	String s1 = "String1";
	String s2 = s1;

	s2[6] = '2';
	String s3(20);

	s3 = s1;
	s3.concatenate(" + ");
	s3.concatenate(s2);

	cout << s1 << ", " << s2 << ", " << s3 << ", " << endl;
}