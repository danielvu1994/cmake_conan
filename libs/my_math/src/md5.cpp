#include "Poco/MD5Engine.h"
#include "Poco/DigestStream.h"
#include "my_print/print_result.h"

#include <iostream>

int printf_md5(){
     Poco::MD5Engine md5;
     Poco::DigestOutputStream ds(md5);
     ds << "abcdefghijklmnopqrstuvwxyz";
     ds.close();
     std::cout << Poco::DigestEngine::digestToHex(md5.digest()) << std::endl;
     return 0;
}

void print_wrapper(std::string result_type, float result_value) {
	print_result( result_type, result_value);
}
