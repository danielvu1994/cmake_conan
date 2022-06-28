#include <iostream>
#include "Poco/MD5Engine.h"
#include "Poco/DigestStream.h"
#include "my_print/print_result.h"

int printf_md5(){
     Poco::MD5Engine md5;
     Poco::DigestOutputStream ds(md5);
     ds << "abcdefghijklmnopqrstuvwxyz";
     ds.close();
     std::cout << Poco::DigestEngine::digestToHex(md5.digest()) << std::endl;
     return 0;
}

void print_result(std::string result_type, float result_value) {
	std::cout << result_type << " result: \t" << result_value << "\n";
}
