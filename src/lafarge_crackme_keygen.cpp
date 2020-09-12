#include <iostream>
#include <vector>
#include <string>

// parse username input
std::vector<unsigned char> parsingUserString(std::string iUserName) {
	std::vector<unsigned char> resultVector;
	for (int i = 1; i < iUserName.length(); i++)
	{
		resultVector.push_back(iUserName[i]);
	}
	resultVector.push_back(0);
	return resultVector;
}

// loc_40117A - Loop 01
std::vector<unsigned char> loc_40117A(std::vector<unsigned char> userNameParsed)
{
	// Hexadecimal array support for first transformation
	unsigned char byte_406328[5] = { 0xAA, 0x89, 0xC4, 0xFE, 0x46 };
	int EAX = 0;
	std::vector<unsigned char> loc_406345(userNameParsed.size(), 0);
	for (int i = 0; i < userNameParsed.size(); i++) {
		unsigned char CL = userNameParsed[i];
		unsigned char BL = CL ^ byte_406328[EAX];
		loc_406345[i] = BL;
		byte_406328[EAX] = CL;
		EAX = EAX + 1;
		if (EAX == 5) {
			EAX = 0;
		}
	}
	return loc_406345;
}

// loc_4011A3 - Loop 02
std::vector<unsigned char> loc_4011A3(std::vector<unsigned char> userNameParsed)
{
	// Hexadecimal array support for second transformation
	unsigned char byte_40632D[5] = { 0x78, 0xF0, 0xD0, 0x03, 0xE7 };
	int EAX = 0;
	std::vector<unsigned char> loc_406345(userNameParsed.size(), 0);
	for (int i = userNameParsed.size() - 1; i >=0; i--) {
		unsigned char CL = userNameParsed[i];
		unsigned char BL = CL ^ byte_40632D[EAX];
		loc_406345[i] = BL;
		byte_40632D[EAX] = CL;
		EAX = EAX + 1;
		if (EAX == 5) {
			EAX = 0;
		}
	}
	return loc_406345;
}

// loc_4011D1 - Loop 03
std::vector<unsigned char> loc_4011D1(std::vector<unsigned char> userNameParsed)
{
	// Hexadecimal array support for third transformation
	unsigned char byte_406332[5] = { 0xF7, 0xFD, 0xF4, 0xE7, 0xB9 };
	int EAX = 0;
	std::vector<unsigned char> loc_406345(userNameParsed.size(), 0);
	for (int i = 0; i < userNameParsed.size(); i++) {
		unsigned char CL = userNameParsed[i];
		unsigned char BL = CL ^ byte_406332[EAX];
		loc_406345[i] = BL;
		byte_406332[EAX] = CL;
		EAX = EAX + 1;
		if (EAX == 5) {
			EAX = 0;
		}
	}
	return loc_406345;
}

// loc_4011FA - Loop 04
std::vector<unsigned char> loc_4011FA(std::vector<unsigned char> userNameParsed)
{
	// Hexadecimal array support for fourth transformation
	unsigned char byte_406337[5] = { 0xB5, 0x1B, 0xC9, 0x50, 0x73 };
	int EAX = 0;
	std::vector<unsigned char> loc_406345(userNameParsed.size(), 0);
	for (int i = userNameParsed.size() - 1; i >= 0; i--) {
		unsigned char CL = userNameParsed[i];
		unsigned char BL = CL ^ byte_406337[EAX];
		loc_406345[i] = BL;
		byte_406337[EAX] = CL;
		EAX = EAX + 1;
		if (EAX == 5) {
			EAX = 0;
		}
	}
	return loc_406345;
}

// loc_401236 - Loop 05
std::vector<unsigned char> loc_401236(std::vector<unsigned char> userNameParsed)
{
	// Hexadecimal array support for fifth transformation
	unsigned char byte_temp[4] = { 0x00, 0x00, 0x00, 0x00 };
	int EAX = 0;
	std::vector<unsigned char> loc_406345(4, 0);
	for (int i = 0; i < userNameParsed.size(); i++) {
		unsigned char CL = userNameParsed[i];
		unsigned char BL = byte_temp[EAX];
		unsigned char DL = (CL + BL) & 0xFF;
		byte_temp[EAX] = DL;
		EAX = EAX + 1;
		if (EAX == 4) {
			EAX = 0;
		}
	}
	for (int i = 0; i < 4; i++) {
		loc_406345[i] = byte_temp[i];
	}
	return loc_406345;
}

// loc_40125A - Loop 06
std::vector<unsigned char> loc_40125A(std::vector<unsigned char> userNameParsed)
{
	std::vector<unsigned char> loc_406345;
	unsigned char divisor = 0xA;
	unsigned char remainder = 0;
	long long a = userNameParsed[0] * pow(0x10, 6);
	long long b = userNameParsed[1] * pow(0x10, 4);
	long long c = userNameParsed[2] * pow(0x10, 2);
	long long d = userNameParsed[3];
	long long numerator = a + b + c + d;
	while (numerator != 0) {
		remainder = numerator % divisor;
		numerator = numerator / divisor;
		loc_406345.push_back(remainder + 0x30);
	}
	return loc_406345;
}

// loc_401278 - Loop 07 - Reserved
std::vector<unsigned char> loc_401278(std::vector<unsigned char> userNameParsed)
{
	std::vector<unsigned char> loc_406345;
	for (int i = userNameParsed.size() - 1; i >= 0; i--) {
		loc_406345.push_back(userNameParsed[i]);
	}
	return loc_406345;
}

// parsing to reg. code
std::string regCodeParsing(std::vector<unsigned char> userNameParsed) {
	std::string result = "";
	for (int i = userNameParsed.size() - 1; i >= 0; i--) {
		result = result + (char)userNameParsed[i];
	}
	return result;
}


int main() {
	/*std::string str = "myusername";
	std::vector<unsigned char> par = parsingUserString(str);
	std::vector<unsigned char> loc_40117A_res = loc_40117A(par);
	for (auto v : loc_40117A_res) {
		std::cout << (int)v << " ";
	}
	std::cout << std::endl;
	std::vector<unsigned char> loc_4011A3_res = loc_4011A3(loc_40117A_res);
	for (auto v : loc_4011A3_res) {
		std::cout << (int)v << " ";
	}
	std::cout << std::endl;
	std::vector<unsigned char> loc_4011D1_res = loc_4011D1(loc_4011A3_res);
	for (auto v : loc_4011D1_res) {
		std::cout << (int)v << " ";
	}
	std::cout << std::endl;
	std::vector<unsigned char> loc_4011FA_res = loc_4011FA(loc_4011D1_res);
	for (auto v : loc_4011FA_res) {
		std::cout << (int)v << " ";
	}
	std::cout << std::endl;
	std::vector<unsigned char> loc_401236_res = loc_401236(loc_4011FA_res);
	for (auto v : loc_401236_res) {
		std::cout << (int)v << " ";
	}
	loc_401236_res = loc_401278(loc_401236_res);
	std::cout << std::endl;
	std::vector<unsigned char> loc_40125A_res = loc_40125A(loc_401236_res);
	for (auto v : loc_40125A_res) {
		std::cout << (int)v << " ";
	}
	std::cout << std::endl;
	std::cout << "Reg code: " << regCodeParsing(loc_40125A_res) << std::endl;*/
	std::string username;
	std::cout << "LaFarge crackme #2" << std::endl;
	do {
		std::cout << "> Enter your username: ";
		std::getline(std::cin, username);
		if (username.length() < 4) {
			std::cout << "The username must have at least 4 chars!!!" << std::endl;
			std::cout << "Enter input username again." << std::endl;
		}
	} while (username.length() < 4);
	std::vector<unsigned char> par = parsingUserString(username);
	std::vector<unsigned char> loc_40117A_res = loc_40117A(par);
	std::vector<unsigned char> loc_4011A3_res = loc_4011A3(loc_40117A_res);
	std::vector<unsigned char> loc_4011D1_res = loc_4011D1(loc_4011A3_res);
	std::vector<unsigned char> loc_4011FA_res = loc_4011FA(loc_4011D1_res);
	std::vector<unsigned char> loc_401236_res = loc_401236(loc_4011FA_res);
	loc_401236_res = loc_401278(loc_401236_res);
	std::vector<unsigned char> loc_40125A_res = loc_40125A(loc_401236_res);
	std::cout << "> Reg code: " << regCodeParsing(loc_40125A_res) << std::endl;
	std::cin.get();
	return 0;
}