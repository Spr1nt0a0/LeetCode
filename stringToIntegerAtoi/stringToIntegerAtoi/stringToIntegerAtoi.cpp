// stringToIntegerAtoi.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define INT_MIN     (-2147483647 - 1)
#define INT_MAX      2147483647

int atoi(const char *str) {
	if (str == NULL || *str == '\0') {
		return 0;
	}

	int ret = 0;

	for (; isspace(*str); str++);  //移除空格符

	bool neg = false;
	if (*str == '-' || *str == '+') {  //取正负号
		neg = (*str == '-');
		str++;
	}

	for (; isdigit(*str); str++) {
		int digit = (*str - '0');
		if (neg) {
			if (-ret < (INT_MIN + digit) / 10) {  //判断下界
				return INT_MIN;
			}
		}
		else {
			if (ret >(INT_MAX - digit) / 10) {  //判断下界
				return INT_MAX;
			}
		}

		ret = 10 * ret + digit;  //转换成数值
	}

	return neg ? -ret : ret;  //加上正负号
}


int main()
{
	printf("\"%s\" = %d\n", "123", atoi("123"));
	printf("\"%s\" = %d\n", "   123", atoi("    123"));
	printf("\"%s\" = %d\n", "+123", atoi("+123"));
	printf("\"%s\" = %d\n", " -123", atoi(" -123"));
	printf("\"%s\" = %d\n", "123ABC", atoi("123ABC"));
	printf("\"%s\" = %d\n", " abc123ABC", atoi(" abc123ABC"));
	printf("\"%s\" = %d\n", "2147483647", atoi("2147483647"));
	printf("\"%s\" = %d\n", "-2147483648", atoi("-2147483648"));
	printf("\"%s\" = %d\n", "2147483648", atoi("2147483648"));
	printf("\"%s\" = %d\n", "-2147483649", atoi("-2147483649"));
	return 0;
}
