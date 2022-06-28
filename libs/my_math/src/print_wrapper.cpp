#include "Poco/MD5Engine.h"
#include "Poco/DigestStream.h"
#include "my_print/print_result.h"

#include <iostream>

int printf_md5_wrapper(){
     return printf_md5();
}

void print_wrapper(std::string result_type, float result_value) {
	print_result( result_type, result_value);
}
