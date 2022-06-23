#include <iostream>

#include "my_math/addition.h"
#include "my_math/division.h"
#include "my_math/md5.h"

using namespace std;

int main() {
	float first_no, second_no, result_add, result_div;

	std::cout << "Enter first number \t";
	std::cin >> first_no;
	cout << "Enter second number\t";
	cin >> second_no;


	result_add = addition(first_no, second_no);
	result_div = division(first_no, second_no);

	print_wrapper("Addition", result_add);
	print_wrapper("Division", result_div);

	printf_md5();
	system("pause");

	return 0;
}
