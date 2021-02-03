#include <iostream>
#include "StackLinked.h"
#include "StringClass.h"
#define nl std::endl;
class StringTokenizer
{
	StackLinked<StringClass> tokens;
	bool isOperator(char);
	bool isOperand(char);
public:
	StringTokenizer(StringClass&);
	bool hasMoreTokens();
	StringClass getToken();
	void displayASCII();
};
bool StringTokenizer::isOperator(char c)
{
	if (c > 39 && c < 44) return true; // ()*+
	if (c == 45) return true; // -
	if (c == 47) return true; // /
	if (c == 33) return true; // !
	return false;
}
bool StringTokenizer::isOperand(char c)
{
	int index = 0;
	if (c > 47 && c < 58) return true;	// 0-9
	if (c == 46) return true;	// '.'
	return false;
}
StringTokenizer::StringTokenizer(StringClass& str)
{
	int strPos = 0, strLen = str.length();
	char c; StringClass thisToken(10);

	while (strPos < strLen)
	{
		c = str[strPos++];
		if (isOperator(c)) tokens.push(c);
		else if (isOperand(c))
		{
			thisToken = "";
			thisToken += c;
			while (isOperand(str[strPos]) || str[strPos] == ',')
			{
				if (str[strPos] == ',') strPos++;
				else
				thisToken += str[strPos++];
			}
			tokens.push(thisToken);
		}
	}
}
bool StringTokenizer::hasMoreTokens()
{
	return !tokens.isEmpty();
}
StringClass StringTokenizer::getToken()
{
	return tokens.pop();
}
void StringTokenizer::displayASCII()
{
	char space = ' '; // ASCII: { 32 }
	char operators[8] = { '!', '(', ')','*', '+', '-', '/', '^' };
	char operands[11] = { '.', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
	std::cout << "The American Standard Code for Information Interchange (1963)" << nl;
	std::cout << "ASCII printable characters:\n" << nl;
	std::cout << "[space] " << (int)space << '\n' << nl;
	std::cout << "Operators" << nl;
	for(int i = 0; i < 8; i++)		std::cout << (int)operators[i] << " " << operators[i] << nl;
	std::cout << "\nOperands" << nl;
	for (int i = 0; i < 8; i++)		std::cout << (int)operands[i] << " " << operands[i] << nl;
}


int main()
{
	StringClass input;
	std::cin >> input;
	StringTokenizer myTokens(input);

	while (myTokens.hasMoreTokens())
		std::cout << myTokens.getToken() << " ";
}