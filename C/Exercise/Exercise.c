#include <math.h>
#include <time.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>

////求两个数的较大值：使用函数求出输入的两个数中的较大值。
////示例：
////	输入：10 20
////	输出：20
//int Max(int x, int y)
//{
//	return x > y ? x : y;
//}
//
//int main()
//{
//	int x = 0, y = 0;
//	scanf_s("%d%d", &x, &y);
//	printf("%d\n", Max(x, y));
//	return 0;
//}

////计算Y的值：https://www.nowcoder.com/practice/61a0f16117484d219b59c62224b33b1c。
//int Y(int x)
//{
//	return x == 0 ? 0 : x > 0 ? -1 : 1;
//}
//
//int main()
//{
//	int x = 0;
//	scanf("%d", &x);
//	printf("%d", Y(x));
//	return 0;
//}

////出生日期输入输出：https://www.nowcoder.com/practice/4a4a9dd1edb6453ba4a0432319200743。(使用格式控制与输出解题)
//int main()
//{
//	int year = 0, month = 0, date = 0;
//	scanf("%4d%2d%2d", &year, &month, &date);
//	printf("year=%d\nmonth=%.2d\ndate=%02d\n", year, month, date);
//	return 0;
//}

////出生日期输入输出：https://www.nowcoder.com/practice/4a4a9dd1edb6453ba4a0432319200743。(使用求余的方式解题)
//int main()
//{
//	int input = 0;
//	scanf("%d", &input);
//	printf("year=%d\nmonth=%02d\ndate=%02d\n", input / 100 / 100, input / 100 % 100, input % 100);
//	return 0;
//}

////学生基本信息输入输出：https://www.nowcoder.com/practice/58b6a69b4bf943b49d2cd3c15770b9fd。
//int main()
//{
//	unsigned int id = 0;
//	float x = 0, y = 0, z = 0;
//	scanf_s("%d;%f,%f,%f", &id, &x, &y, &z);
//	printf("The each subject score of No. %d is %.2f, %.2f, %.2f.", id, x, y, z);
//	return 0;
//}

////"printf"函数的返回值：https://www.nowcoder.com/practice/a19ef1d8e55c4cc786f11cbf6b2fde61。
//int main()
//{
//	printf("\n%d\n", printf("Hello world!"));
//	return 0;
//}

////小乐乐找最大数：https://www.nowcoder.com/practice/ae6a21920cac4f9184c8ecfcc87f89b9。
//int main()
//{
//	int a = 0, b = 0, c = 0, d = 0;
//	scanf("%d%d%d%d", &a, &b, &c, &d);
//	printf("%d\n", (a > b ? a : b) > (c > d ? c : d) ? (a > b ? a : b) : (c > d ? c : d));
//	return 0;
//}

////从大到小输出：输入三个数，从大到小输出。
////示例：
////	输入：2 3 1
////	输出：3 2 1
//void Swap(int* p1, int* p2)
//{
//	*p1 = *p1 ^ *p2;
//	*p2 = *p1 ^ *p2;
//	*p1 = *p1 ^ *p2;
//}
//
//int main()
//{
//	int a = 0, b = 0, c = 0;
//	scanf_s("%d%d%d", &a, &b, &c);
//	if (a < b)
//	{
//		Swap(&a, &b);
//	}
//	if (a < c)
//	{
//		Swap(&a, &c);
//	}
//	if (b < c)
//	{
//		Swap(&b, &c);
//	}
//	printf("%d %d %d\n", a, b, c);
//	return 0;
//}

////打印"3"的倍数的数：打印"1~100"中所有"3"的倍数的数字。
//int main()
//{
//	for (int i = 1; i <= 100; ++i)
//	{
//		if (i % 3 == 0)
//			printf("%d ", i);
//	}
//	return 0;
//}

////最大公约数和最小公倍数：输入两个数，求这两个数的最大公约数和最小公倍数。
//int GetFactor(int x, int y)
//{
//	return y ? GetFactor(y, x % y) : x;
//}
//
//int main()
//{
//	int a = 0, b = 0;
//	scanf_s("%d%d", &a, &b);
//	int c = GetFactor(a, b);
//	printf("最大公约数：%d\n", c);
//	printf("最小公倍数：%d\n", a * b / c);
//	return 0;
//}

////打印闰年：打印"1000~2000"之间的闰年。
//int main()
//{
//	for (int i = 1000; i <= 2000; ++i)
//	{
//		if ((i % 4 == 0 && i % 100 != 0) || i % 400 == 0)
//		{
//			printf("%d ", i);
//		}
//	}
//	printf("\n");
//	return 0;
//}

////打印素数：打印"100~200"之间的素数。
//bool JudgmentPrimeNumber(int num)
//{
//	if (num < 2)
//	{
//		return false;
//	}
//	for (int i = 2; i <= (int)sqrt(num); ++i)
//	{
//		if (num % i == 0)
//		{
//			return false;
//		}
//	}
//	return true;
//}
//
//int main()
//{
//	for (int i = 100; i <= 200; ++i)
//	{
//		if (JudgmentPrimeNumber(i))
//		{
//			printf("%d ", i);
//		}
//	}
//	return 0;
//}

////数"9"的个数：打印"1~100"的所有整数中出现数字9的次数。
//int main()
//{
//	int count = 0;
//	for (int i = 1; i <= 100; ++i)
//	{
//		if (i % 10 == 9)
//		{
//			count++;
//		}
//		if (i / 10 == 9)
//		{
//			count++;
//		}
//	}
//	printf("%d\n", count);
//	return 0;
//}

////分数求和：计算"1/1 -1/2 +1/3 -1/4 +1/5 ……  +1/99 -1/100"的值。(标志翻转法)
//int main()
//{
//	double sum = 0;
//	int flag = 1;
//	for (int i = 1; i <= 100; ++i)
//	{
//		sum += (1.0 / i) * flag;
//		flag = -flag;
//	}
//	printf("%lf\n", sum);
//	return 0;
//}

////分数求和：计算"1/1 -1/2 +1/3 -1/4 +1/5 ……  +1/99 -1/100"的值。(常用方法)
//int main()
//{
//	double sum = 0;
//	for (int i = 1; i <= 100; ++i)
//	{
//		if (i % 2 == 0)
//		{
//			sum -= 1.0 / i;
//		}
//		else
//		{
//			sum += 1.0 / i;
//		}
//	}
//	printf("%lf\n", sum);
//	return 0;
//}

////求最大值：求十个整数中的最大值。
//int main()
//{
//	int arr[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
//	int max = arr[0];
//	for (int i = 1; i < sizeof(arr) / sizeof(arr[0]); ++i)
//	{
//		if (max < arr[i])
//		{
//			max = arr[i];
//		}
//	}
//	printf("Max = %d\n", max);
//	return 0;
//}

////乘法口诀表：在屏幕上输出"9*9"乘法口诀表。
//int main()
//{
//	for (int i = 1; i <= 9; ++i)
//	{
//		for (int j = 1; j <= i; ++j)
//		{
//			printf("%d * %d = %-2d  ", i, j, i * j);
//		}
//		printf("\n");
//	}
//	return 0;
//}

////猜数字游戏
//void Menu()
//{
//	printf("*****************************\n");
//	printf("********** 1. Play **********\n");
//	printf("********** 0. Exit **********\n");
//	printf("*****************************\n");
//}
//
//void Game()
//{
//	int randNum = rand() % 100 + 1;
//	int input = 0;
//	system("cls");
//	while (1)
//	{
//		printf("请输入0~100之间的数字>>");
//		scanf_s("%d", &input);
//		if (input > randNum)
//		{
//			printf("猜大了。\n");
//		}
//		else if (input < randNum)
//		{
//			printf("猜小了。\n");
//		}
//		else
//		{
//			printf("\n恭喜你猜对了！\n\n五秒后返回主菜单...\n");
//			Sleep(5000);
//			break;
//		}
//	}
//}
//
//int main()
//{
//	int input = 0;
//	srand((unsigned int)time(NULL));
//	do
//	{
//		system("cls");
//		Menu();
//		printf("Please Enter>>");
//		scanf_s("%d", &input);
//		switch (input)
//		{
//		case 1:
//			Game();
//			break;
//		case 0:
//			printf("\nExit!\n");
//			break;
//		default:
//			printf("\nInput Error! Please Enter Again\n\n");
//			system("pause");
//			break;
//		}
//	} while (input);
//	return 0;
//}

////二分查找：编写代码在一个整型有序数组中查找具体的某个数。
////要求：
////	1. 找到了就打印数字所在的下标。
////	2. 找不到则打印：找不到。
//int main()
//{
//	int num = 7;
//	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	int left = 0, right = sizeof(arr) / sizeof(arr[0]) - 1;
//	while (left <= right)
//	{
//		int middle = ((right - left) >> 1) + left;
//		if (arr[middle] > num)
//		{
//			right = middle - 1;
//		}
//		else if (arr[middle] < num)
//		{
//			left = middle + 1;
//		}
//		else
//		{
//			printf("%d\n", middle);
//			break;
//		}
//	}
//	if (left > right)
//	{
//		printf("找不到\n");
//	}
//	return 0;
//}

////交换数组：将数组"A"中的内容和数组"B"中的内容进行交换(数组一样大)。
//void Swap(int* p1, int* p2)
//{
//	*p1 = *p1 ^ *p2;
//	*p2 = *p1 ^ *p2;
//	*p1 = *p1 ^ *p2;
//}
//
//void PrintArray(int arr[], int size)
//{
//	for (int i = 0; i < size; ++i)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//}
//
//int main()
//{
//	int arr1[] = { 1, 2, 3, 4, 5 };
//	int arr2[] = { 6, 7, 8, 9, 10 };
//	int size = sizeof(arr1) / sizeof(arr1[0]);
//	for (int i = 0; i < size; ++i)
//	{
//		Swap(&arr1[i], &arr2[i]);
//	}
//	PrintArray(arr1, size);
//	PrintArray(arr2, size);
//	return 0;
//}

////输入密码：模拟三次密码输入的场景。
////要求：
////	1. 密码正确，提示“登录成功”。
////	2. 密码错误，提示“登录失败”，但可以重新输入。
////	3. 最多可输入三次，三次输入均错误，则退出程序。
//int main()
//{
//	int i = 0;
//	char arr[20] = { 0 };
//	for (i = 0; i < 3; ++i)
//	{
//		printf("请输入密码>>");
//		scanf_s("%s", arr, 20);
//		if (strcmp(arr, "88888888") == 0)
//		{
//			printf("登录成功。\n");
//			break;
//		}
//		else
//		{
//			printf("登录失败。\n");
//		}
//	}
//	if (i == 3)
//	{
//		printf("错误次数过多，退出程序！\n");
//	}
//	return 0;
//}

////输入字符并打印：编写一个程序，不断接收键盘字符并打印。
////要求：
////	1. 如果接收的是小写字符，输出对应的大写字符。
////	2. 如果接收的是大写字符，输出对应的小写字符。
////	3. 如果接收的是数字则不输出。
//int main()
//{
//	char input = 0;
//	while (scanf_s("%c", &input, 1) != EOF)
//	{
//		if (input >= 'a' && input <= 'z')
//		{
//			printf("%c\n", input - 32);
//		}
//		else if (input >= 'A' && input <= 'Z')
//		{
//			printf("%c\n", input + 32);
//		}
//	}
//	return 0;
//}

////交换两个整数：将输入的两个数的内容使用函数进行交换(不允许创建临时变量)。
//void Swap(int* x, int* y)
//{
//	*x = *x ^ *y;
//	*y = *x ^ *y;
//	*x = *x ^ *y;
//}
//
//int main()
//{
//	int input_1 = 0, input_2 = 0;
//	scanf_s("%d%d", &input_1, &input_2);
//	printf("交换前：%d %d。\n", input_1, input_2);
//	Swap(&input_1, &input_2);
//	printf("交换后：%d %d。\n", input_1, input_2);
//	return 0;
//}

////乘法口诀表：使用函数打印输入"N"就打印"1~N"的乘法口诀表。
//void PrintMultiplicationTable(int x)
//{
//	for (int i = 1; i <= x; ++i)
//	{
//		for (int j = 1; j <= i; ++j)
//		{
//			printf("%-2d * %-2d = %-3d  ", i, j, i * j);
//		}
//		printf("\n");
//	}
//}
//
//int main()
//{
//	int input = 0;
//	scanf_s("%d", &input);
//	PrintMultiplicationTable(input);
//	return 0;
//}

////函数判断素数：使用函数判断输入的数是否为素数，并使用这个函数打印"1~100"之间的素数。
//bool JudgmentPrimeNumber(int num)
//{
//	if (num < 2)
//	{
//		return false;
//	}
//	for (int i = 2; i <= (int)sqrt(num); ++i)
//	{
//		if (num % i == 0)
//		{
//			return false;
//		}
//	}
//	return true;
//}
//
//int main()
//{
//	int input = 0;
//	scanf_s("%d", &input);
//	if (JudgmentPrimeNumber(input))
//	{
//		printf("\n你输入的数是素数\n");
//	}
//	else
//	{
//		printf("\n你输入的数不是素数\n");
//	}
//	printf("\n即将清屏打印1~200之间的素数\n\n");
//	system("pause");
//	system("cls");
//	for (int i = 1; i <= 200; ++i)
//	{
//		if (JudgmentPrimeNumber(i))
//		{
//			printf("%d ", i);
//		}
//	}
//	return 0;
//}

////函数判断闰年：使用函数判断输入的数是不是闰年，并使用这个函数打印"1000~2000"之间的闰年。
//bool JudgmentLeapYear(int year)
//{
//	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
//	{
//		return true;
//	}
//	return false;
//}
//
//int main()
//{
//	int input = 0;
//	scanf_s("%d", &input);
//	if (JudgmentLeapYear(input))
//	{
//		printf("\n你输入的数是闰年\n");
//	}
//	else
//	{
//		printf("\n你输入的数不是闰年\n");
//	}
//	printf("\n即将清屏打印1000~2000之间的闰年\n\n");
//	system("pause");
//	system("cls");
//	for (int i = 1000; i <= 2000; ++i)
//	{
//		if (JudgmentLeapYear(i))
//		{
//			printf("%d ", i);
//		}
//	}
//	return 0;
//}

////打印一个数的每一位：使用递归打印一个整数的每一位。
//void PrintNum(size_t num)
//{
//	if (num > 9)
//	{
//		PrintNum(num / 10);
//	}
//	printf("%zu ", num % 10);
//}
//
//int main()
//{
//	size_t num = 0;
//	scanf_s("%zu", &num);
//	PrintNum(num);
//	return 0;
//}

////求阶乘：使用递归和非递归分别求输入的数的阶乘(不考虑溢出的问题)。(递归)
//size_t Factorial(size_t num)
//{
//	assert(num >= 0);
//	return num == 0 ? 1 : num * Factorial(num - 1);
//}
//
//int main()
//{
//	size_t num = 0;
//	scanf_s("%zu", &num);
//	printf("%zu! = %zu\n", num, Factorial(num));
//	return 0;
//}

////求阶乘：使用递归和非递归分别求输入的数的阶乘(不考虑溢出的问题)。(循环)
//size_t Factorial(size_t num)
//{
//	assert(num >= 0);
//	size_t sum = 1;
//	while (num)
//	{
//		sum *= num--;
//	}
//	return sum;
//}
//
//int main()
//{
//	size_t num = 0;
//	scanf_s("%zu", &num);
//	printf("%zu! = %zu\n", num, Factorial(num));
//	return 0;
//}

////"strlen"函数的模拟：使用递归和非递归分别模拟"strlen"函数的使用。(递归)
//size_t MyStrlen(char* str)
//{
//	return *str == '\0' ? 0 : 1 + MyStrlen(str + 1);
//}
//
//int main()
//{
//	char arr[] = "KilluaAoki";
//	printf("%zu\n", MyStrlen(arr));
//	return 0;
//}

////"strlen"函数的模拟：使用递归和非递归分别模拟"strlen"函数的使用。(循环)
//size_t MyStrlen(char* str)
//{
//	size_t count = 0;
//	while (*str++)
//	{
//		count++;
//	}
//	return count;
//}
//
//int main()
//{
//	char arr[] = "KilluaAoki";
//	printf("%zu\n", MyStrlen(arr));
//	return 0;
//}

////字符串逆序：使用迭代实现字符串逆转。
////要求：
////	1. 函数声明："reverse_string(char* str)"。
////	2. 将参数字符串中的字符反向排列，不是逆向打印。
////	3. 不能使用C语言库函数中的字符串操作函数。
//size_t MyStrlen(char* str)
//{
//	return *str == '\0' ? 0 : 1 + MyStrlen(str + 1);
//}
//
//void Swap(char* str1, char* str2)
//{
//	(*str1 ^ *str2) && (*str2 ^= *str1 ^= *str2, *str1 ^= *str2);
//}
//
//void reverse_string(char* str)
//{
//	size_t length = MyStrlen(str);
//	char* left = str;
//	char* right = str + length - 1;
//	while (left < right)
//	{
//		Swap(left, right);
//		left++;
//		right--;
//	}
//}
//
//int main()
//{
//	char arr[] = "ikoAaulliK";
//	reverse_string(arr);
//	printf("%s\n", arr);
//	return 0;
//}

////字符串逆序：使用递归实现字符串逆转。
////要求：
////	1. 函数声明："reverse_string(char* str)"。
////	2. 将参数字符串中的字符反向排列，不是逆向打印。
////	3. 不能使用C语言库函数中的字符串操作函数。
//size_t MyStrlen(char* str)
//{
//	return *str == '\0' ? 0 : 1 + MyStrlen(str + 1);
//}
//
//void reverse_string(char* str)
//{
//	char tmp = *str;
//	size_t length = MyStrlen(str);
//	*str = *(str + length - 1);
//	*(str + length - 1) = '\0';
//	if (length > 2)//if (MyStrlen(str + 1) >= 2)
//	{
//		reverse_string(str + 1);
//	}
//	*(str + length - 1) = tmp;
//}
//
//int main()
//{
//	char arr[] = "ikoAaulliK";
//	reverse_string(arr);
//	printf("%s\n", arr);
//	return 0;
//}

////字符串逆序：使用递归实现字符串逆转。
////要求：
////	1. 函数名："reverse_string"。
////	2. 将参数字符串中的字符反向排列，不是逆向打印。
////	3. 不能使用C语言库函数中的字符串操作函数。
////	4. 自行设计参数。
//size_t MyStrlen(char* str)
//{
//	return *str == '\0' ? 0 : 1 + MyStrlen(str + 1);
//}
//
//void Swap(char* str1, char* str2)
//{
//	(*str1 ^ *str2) && (*str2 ^= *str1 ^= *str2, *str1 ^= *str2);
//}
//
//void reverse_string(char* str, size_t size)
//{
//	char* left = str;
//	char* right = str + size - 1;
//	if (left < right)
//	{
//		reverse_string(left + 1, size - 1 - 1);
//		Swap(left, right);
//	}
//}
//
//int main()
//{
//	char arr[] = "ikoAaulliK";
//	size_t size = MyStrlen(arr);
//	reverse_string(arr, size);
//	printf("%s\n", arr);
//	return 0;
//}

////计算一个数的每位之和：使用递归计算一个非负整数的每位之和。
////要求：
////	1. 函数名为："DigitSum"。
////	2. 输入一个非负整数，返回组成它的数字之和。
////示例：
////	输入：1729
////	输出：19
//unsigned int DigitSum(unsigned int num)
//{
//	if (num > 9)
//	{
//		return DigitSum(num / 10) + num % 10;
//	}
//	return num;
//}
//
//int main()
//{
//	unsigned int num = 0;
//	scanf_s("%u", &num);
//	printf("%u\n", DigitSum(num));
//	return 0;
//}

////计算一个数的次方：使用递归和循环实现"N"的"K"次方。(递归)
//int MyIntPow(int x, int y)
//{
//	if (y == 0)
//	{
//		return 1;
//	}
//	return x * MyIntPow(x, y - 1);
//}
//
//int main()
//{
//	int num1 = 0;
//	int num2 = 0;
//	scanf_s("%d%d", &num1, &num2);
//	printf("MyIntPow(%d,%d) = %d", num1, num2, MyIntPow(num1, num2));
//	return 0;
//}

////计算一个数的次方：使用递归和循环实现"N"的"K"次方。(循环)
//int MyIntPow(int x, int y)
//{
//	int multiply = 1;
//	for (int i = 0; i < y; ++i)
//	{
//		multiply = multiply * x;
//	}
//	return multiply;
//}
//
//int main()
//{
//	int num1 = 0;
//	int num2 = 0;
//	scanf_s("%d%d", &num1, &num2);
//	printf("MyIntPow(%d,%d) = %d", num1, num2, MyIntPow(num1, num2));
//	return 0;
//}

////计算斐波那契数：使用递归和非递归分别实现斐波那契数。(递归)
//size_t FibonacciSequence(int x)
//{
//	if (x <= 2)
//	{
//		return 1;
//	}
//	return FibonacciSequence(x - 1) + FibonacciSequence(x - 2);
//}
//
//int main()
//{
//	int input = 0;
//	scanf_s("%d", &input);
//	printf("%zu\n", FibonacciSequence(input));
//	return 0;
//}

////计算斐波那契数：使用递归和非递归分别实现斐波那契数。(循环)
//size_t FibonacciSequence(int num)
//{
//	size_t x = 1, y = 1, sum = 1;
//	while (num-- >= 3)
//	{
//		sum = x + y;
//		x = y;
//		y = sum;
//	}
//	return sum;
//}
//
//int main()
//{
//	int input = 0;
//	scanf_s("%d", &input);
//	printf("%zu\n", FibonacciSequence(input));
//	return 0;
//}

////交换数组：将数组"A"中的内容和数组"B"中的内容进行交换(数组一样大)。
//void Swap(int arr1[], int arr2[], int size)
//{
//	for (int i = 0; i < size; ++i)
//	{
//		(arr1[i] ^ arr2[i]) && (arr2[i] ^= arr1[i] ^= arr2[i], arr1[i] ^= arr2[i]);
//	}
//}
//
//void PrintIntArray(int arr[], int size)
//{
//	for (int i = 0; i < size; ++i)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//}
//
//int main()
//{
//	int arr1[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
//	int arr2[10] = { 0, -1, -2, -3, -4, -5, -6, -7, -8, -9 };
//	int size = sizeof(arr1) / sizeof(arr1[0]);
//	PrintIntArray(arr1, size);
//	PrintIntArray(arr2, size);
//	Swap(arr1, arr2, size);
//	PrintIntArray(arr1, size);
//	PrintIntArray(arr2, size);
//	return 0;
//}

////数组操作：创建一个整型数组，并完成对数组的相应操作。
////要求：
////	1. 实现函数"init"，将数组内元素全部初始化为"0"。
////	2. 实现函数"print"，打印数组内的每一个元素。
////	3. 实现函数"reverse"，完成对数组元素的逆置。
////	4. 实现函数"empty"，清空数组内所有元素。
//void Swap(int* ptr1, int* ptr2)
//{
//	(*ptr1 ^ *ptr2) && (*ptr2 ^= *ptr1 ^= *ptr2, *ptr1 ^= *ptr2);
//}
//
//void init(int arr[], int size)
//{
//	if (arr == NULL || size == 0)
//	{
//		return;
//	}
//	for (int i = 0; i < size; ++i)
//	{
//		arr[i] = 0;
//	}
//}
//
//void print(int arr[], int size)
//{
//	if (arr == NULL || size == 0)
//	{
//		return;
//	}
//	for (int i = 0; i < size; ++i)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//}
//
//void reverse(int arr[], int size)
//{
//	if (arr == NULL || size <= 1)
//	{
//		return;
//	}
//	int left = 0;
//	int right = size - 1;
//	while (left < right)
//	{
//		Swap(&arr[left], &arr[right]);
//		left++;
//		right--;
//	}
//}
//
//void empty(int arr[], int* size)
//{
//	if (arr == NULL || size == 0)
//	{
//		return;
//	}
//	init(arr, *size);
//	*size = 0;
//}
//
//int main()
//{
//	int arr[10];
//	int size = sizeof(arr) / sizeof(arr[0]);
//
//	init(arr, size);
//	print(arr, size);
//
//	for (int i = 1; i < size; ++i)
//	{
//		arr[i] = i;
//	}
//	print(arr, size);
//
//	reverse(arr, size);
//	print(arr, size);
//	empty(arr, &size);
//
//	return 0;
//}

////冒泡排序：实现一个对整型数组的冒泡排序。
//void Swap(int* ptr1, int* ptr2)
//{
//	(*ptr1 ^ *ptr2) && (*ptr2 ^= *ptr1 ^= *ptr2, *ptr1 ^= *ptr2);
//}
//
//void BubbleSort(int arr[], int size)
//{
//	if (arr == NULL || size <= 1)
//	{
//		return;
//	}
//	for (int end = size - 1; end > 0; --end)
//	{
//		int flag = 0;
//		for (int i = 0; i < end; ++i)
//		{
//			if (arr[i] > arr[i + 1])
//			{
//				Swap(&arr[i], &arr[i + 1]);
//				flag = 1;
//			}
//		}
//		if (flag == 0)
//		{
//			return;
//		}
//	}
//}
//
//void PrintIntArray(int arr[], int size)
//{
//	if (arr == NULL || size == 0)
//	{
//		return;
//	}
//	for (int i = 0; i < size; ++i)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//}
//
//int main()
//{
//	int arr[] = { -1, -2, -3, -4, -5, -6, -7, -8, -9, 0 };
//	int size = sizeof(arr) / sizeof(arr[0]);
//	PrintIntArray(arr, size);
//	BubbleSort(arr, size);
//	PrintIntArray(arr, size);
//	return 0;
//}

////小乐乐走台阶：https://www.nowcoder.com/practice/ebf04de0e02c486099d78b7c3aaec255。(递归)
//int Fib(int n)
//{
//	return n < 2 ? 1 : Fib(n - 1) + Fib(n - 2);
//}
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	printf("%d\n", Fib(n));
//	return 0;
//}

////小乐乐走台阶：https://www.nowcoder.com/practice/ebf04de0e02c486099d78b7c3aaec255。(迭代)
//int Fib(int n)
//{
//	int x = 1, y = 1, sum = 1;
//	while (--n)
//	{
//		sum = x + y;
//		x = y;
//		y = sum;
//	}
//	return sum;
//}
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	printf("%d\n", Fib(n));
//	return 0;
//}

////小乐乐走台阶：https://www.nowcoder.com/practice/ebf04de0e02c486099d78b7c3aaec255。(动态规划)
//int Fib(int n)
//{
//	if (n < 1)
//	{
//		return 0;
//	}
//	int arr[n + 1];
//	arr[0] = 1;
//	arr[1] = 1;
//	for (int i = 2; i <= n; ++i)
//	{
//		arr[i] = arr[i - 1] + arr[i - 2];
//	}
//	return arr[n];
//}
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	printf("%d\n", Fib(n));
//	return 0;
//}

////序列中删除指定数字：https://www.nowcoder.com/practice/7bbcdd2177a445a9b66da79512b32dd7。
//int main()
//{
//	int n = 0, del = 0;
//	scanf("%d", &n);
//	int arr1[n];
//	for (int i = 0; i < n; ++i)
//	{
//		scanf("%d", &arr1[i]);
//	}
//	scanf("%d", &del);
//	int arr2[n];
//	int count = 0;
//	for (int i = 0, j = 0; i < n; ++i)
//	{
//		if (arr1[i] != del)
//		{
//			arr2[j++] = arr1[i];
//			count++;
//		}
//	}
//	for (int i = 0; i < count; ++i)
//	{
//		printf("%d ", arr2[i]);
//	}
//	return 0;
//}

////最高分与最低分之差：https://www.nowcoder.com/practice/e0e4f81dcd55408a8973f8033bbeb1d2。
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int arr[n];
//	for (int i = 0; i < n; ++i)
//	{
//		scanf("%d", &arr[i]);
//	}
//	int max = arr[0];
//	int min = arr[0];
//	for (int i = 0; i < n; ++i)
//	{
//		if (max < arr[i])
//		{
//			max = arr[i];
//		}
//		if (min > arr[i])
//		{
//			min = arr[i];
//		}
//	}
//	printf("%d\n", max - min);
//	return 0;
//}

////字母大小写转换：https://www.nowcoder.com/practice/850ebd30a2a34cfc87199da3fc15786a。
//int main()
//{
//	char input = 0;
//	while (scanf("%c", &input) != EOF)
//	{
//		getchar();
//		if (input >= 'A' && input <= 'Z')
//		{
//			printf("%c\n", input + 32);
//		}
//		if (input >= 'a' && input <= 'z')
//		{
//			printf("%c\n", input - 32);
//		}
//	}
//	return 0;
//}

////判断是不是字母：https://www.nowcoder.com/practice/91a588dd4cd244bfa616f17603ec123c。
//int main()
//{
//	char input = 0;
//	while (scanf("%c", &input) != EOF)
//	{
//		getchar();
//		if (input >= 'A' && input <= 'z')
//		{
//			printf("%c is an alphabet.\n", input);
//		}
//		else
//		{
//			printf("%c is not an alphabet.\n", input);
//		}
//	}
//	return 0;
//}

////最高分数：https://www.nowcoder.com/practice/52c18a3b49a54fc98107fbdde1415f90。
//int main()
//{
//	int a, b, c;
//	scanf("%d %d %d", &a, &b, &c);
//	printf("%d\n", a > b ? (a > c ? a : c) : (b > c ? b : c));
//	return 0;
//}

////变种水仙花：https://www.nowcoder.com/practice/c178e3f5cc4641dfbc8b020ae79e2b71。
//int main()
//{
//	for (int i = 10000; i < 100000; ++i)
//	{
//		int sum = 0;
//		for (int j = 10; j <= 10000; j *= 10)
//		{
//			sum += (i % j) * (i / j);
//		}
//		if (i == sum)
//		{
//			printf("%d ", i);
//		}
//	}
//	return 0;
//}

////两个整数二进制位不同个数：https://www.nowcoder.com/practice/16e48900851646c0b2c6cdef9d7ea051。
//int main()
//{
//	int x = 0, y = 0, z = 0, count = 0;
//	scanf("%d %d", &x, &y);
//	z = x ^ y;
//	while (z)
//	{
//		z &= z - 1;
//		count++;
//	}
//	printf("%d\n", count);
//	return 0;
//}

////打印整数二进制的奇数位和偶数位：获取一个整数二进制序列中所有的偶数位和奇数位，分别打印出二进制序列。
//int main()
//{
//	int num = 10;
//	for (int i = 31; i >= 0; --i)
//	{
//		printf("%c", (num & (1 << i)) == 0 ? '0' : '1');
//	}
//	printf("\n");
//	for (int i = 30; i >= 0; i -= 2)
//	{
//		printf(" %c", (num & (1 << i)) == 0 ? '0' : '1');
//	}
//	printf("\n");
//	for (int i = 31; i >= 0; i -= 2)
//	{
//		printf("%c ", (num & (1 << i)) == 0 ? '0' : '1');
//	}
//	return 0;
//}

////位1的个数：https://leetcode.cn/problems/number-of-1-bits/。(接口型)
//int hammingWeight(uint32_t n)
//{
//	int count = 0;
//	while (n)
//	{
//		n &= n - 1;
//		count++;
//	}
//	return count;
//}

////交换变量：将两个整数的内容进行交换(不允许创建临时变量)。
//void Swap(int* ptr1, int* ptr2)
//{
//	((*ptr1) ^ (*ptr2)) && ((*ptr2) ^= (*ptr1) ^= (*ptr2), (*ptr1) ^= (*ptr2));
//}
//
//int main()
//{
//	int x, y;
//	scanf_s("%d %d", &x, &y);
//	printf("交换前：x = %d，y = %d。\n", x, y);
//	Swap(&x, &y);
//	printf("交换后：x = %d，y = %d。\n", x, y);
//}

////X形图案：https://www.nowcoder.com/practice/83d6afe3018e44539c51265165806ee4。
//int main()
//{
//	int n = 0;
//	while (scanf("%d", &n) != EOF)
//	{
//		getchar();
//		for (int i = 0; i < n; ++i)
//		{
//			for (int j = 0; j < n; ++j)
//			{
//				if (i == j || j == n - i - 1)
//				{
//					printf("*");
//				}
//				else
//				{
//					printf(" ");
//				}
//			}
//			printf("\n");
//		}
//	}
//	return 0;
//}

////获得月份天数：https://www.nowcoder.com/practice/13aeae34f8ed4697960f7cfc80f9f7f6。
//int main()
//{
//	int year, month;
//	int arr1[12] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
//	int arr2[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
//	while (scanf("%d %d", &year, &month) != EOF)
//	{
//		getchar();
//		if (((year % 4 == 0) && (year % 100 != 0)) || year % 400 == 0)
//		{
//			printf("%d\n", arr1[month - 1]);
//		}
//		else
//		{
//			printf("%d\n", arr2[month - 1]);
//		}
//	}
//	return 0;
//}

////三角形判断：https://www.nowcoder.com/practice/689ec1e742394e09b1059556fc167b65。
//int main()
//{
//	int a, b, c;
//	while (scanf("%d %d %d", &a, &b, &c) != EOF)
//	{
//		getchar();
//		if (a + b > c && a + c > b && b + c > a)
//		{
//			if (a == b && a == c && b == c)
//			{
//				printf("Equilateral triangle!\n");
//			}
//			else if (((a == b) && (a != c)) || ((a == c) && (a != b)) || ((b == c) && (b != a)))
//			{
//				printf("Isosceles triangle!\n");
//			}
//			else
//			{
//				printf("Ordinary triangle!\n");
//			}
//		}
//		else
//		{
//			printf("Not a triangle!\n");
//		}
//	}
//	return 0;
//}

////使用指针打印数组内容：写一个函数打印数组的内容，不使用数组下标，使用指针。
////要求：
////	1. 实现函数能够打印数组的内容。
////	2. 数组为整型一维数组。
////	3. 不可使用数组的下标，只可使用指针。
//void PrintfArray(const int* const parr, size_t size)
//{
//	for (int i = 0; i < size; ++i)
//	{
//		printf("%d ", *(parr + i));
//	}
//	printf("\n");
//}
//
//int main()
//{
//	int arr[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
//	size_t size = sizeof(arr) / sizeof(arr[0]);
//	PrintfArray(arr, size);
//	return 0;
//}

////反转字符串：https://leetcode.cn/problems/reverse-string/。
//void reverseString(char* s, int sSize)
//{
//	char* left = s;
//	char* right = s + sSize - 1;
//	while (left < right)
//	{
//		char tmp = *left;
//		*left = *right;
//		*right = tmp;
//		left++;
//		right--;
//	}
//}

////规律数列求和：https://www.nowcoder.com/practice/e05d1c142b3d4898be7183289a00ce5f。
//int main()
//{
//	long long num = 0;
//	long long sum = 0;
//	for (int i = 0; i < 10; i++)
//	{
//		num = num * 10 + 9;
//		sum += num;
//	}
//	printf("%lld\n", sum);
//	return 0;
//}

////规律数列求和：求"Sn= a + aa + aaa + aaaa + aaaaa"的和，其中"a"是一个数字。
//int main()
//{
//	int a = 0;
//	int num = 0;
//	int sum = 0;
//	scanf_s("%d", &a);
//	for (int i = 0; i < 5; ++i)
//	{
//		num = num * 10 + a;
//		sum += num;
//	}
//	printf("%d\n", sum);
//	return 0;
//}

////打印"阿姆斯特朗数"：求出"0~100000"之间的所有的"阿姆斯特朗数"并输出。
////介绍：
////	1. "阿姆斯特朗数"，又称为"自恋数"，"水仙花数"即"阿姆斯特朗数"的分支之一。
////	2. 若一个"N"位正整数等于其各位数字的"N"次方之和，则称该数为"阿姆斯特朗数"，如："153"即为"阿姆斯特朗数"。
//int MyIntPow(int x, int y)
//{
//	int multiply = 1;
//	for (int i = 0; i < y; ++i)
//	{
//		multiply *= x;
//	}
//	return multiply;
//}
//
//int main()
//{
//	for (int i = 0; i <= 100000; ++i)
//	{
//		int num = i;
//		int sum = 0;
//		int digits = 1;
//		while (num >= 9)
//		{
//			num /= 10;
//			digits++;
//		}
//		num = i;
//		while (num)
//		{
//			sum += MyIntPow(num % 10, digits);
//			num /= 10;
//		}
//		if (sum == i)
//		{
//			printf("%d ", i);
//		}
//	}
//	return 0;
//}

////菱形图案：https://www.nowcoder.com/practice/8b935f8ffe99445dbd42494febd13e45。
//int main()
//{
//	int n = 0;
//	while (scanf("%d", &n) == 1)
//	{
//		for (int i = 0; i <= n; i++)
//		{
//			for (int j = 0; j < n - i; ++j)
//			{
//				printf(" ");
//			}
//			for (int j = 0; j <= i; ++j)
//			{
//				printf("* ");
//			}
//			printf("\n");
//		}
//		for (int i = 0; i < n; ++i)
//		{
//			for (int j = 0; j <= i; ++j)
//			{
//				printf(" ");
//			}
//			for (int j = 0; j < n - i; j++)
//			{
//				printf("* ");
//			}
//			printf("\n");
//		}
//	}
//	return 0;
//}

////喝汽水：每瓶汽水一元钱，两个空瓶可以换一瓶汽水，若有二十元钱，得出一共可以喝几瓶汽水。
//int main()
//{
//	int money = 20;
//	int total = money;
//	int empty = money;
//	while (empty >= 2)
//	{
//		total += empty / 2;
//		empty = empty / 2 + empty % 2;
//	}
//	printf("%d\n", total);
//	return 0;
//}

////"strlen"库函数实现：模拟实现"strlen"库函数。
//size_t MyStrlenCount(const char* str)
//{
//	int count = 0;
//	while (*str++)
//	{
//		count++;
//	}
//	return count;
//}
//
//size_t MyStrlenRecursion(const char* str)
//{
//	if (!*str)
//	{
//		return 0;
//	}
//	return 1 + MyStrlenRecursion(str + 1);
//}
//
//size_t MyStrlenPointer(const char* str)
//{
//	const char* tmp = str;
//	while (*tmp++);
//	return tmp - str - 1;
//}
//
//int main()
//{
//	char* str = "KilluaAoki";
//
//	//计数：创建临时变量。
//	printf("%zu\n", MyStrlenCount(str));
//
//	//递归：不创建临时变量。
//	printf("%zu\n", MyStrlenRecursion(str));
//
//	//指针：指针运算。
//	printf("%zu\n", MyStrlenPointer(str));
//
//	return 0;
//}

////"strcpy"库函数实现：模拟实现"strcpy"库函数。
//char* MyStrcpy(char* dest, const char* src)
//{
//	char* tmp = dest;
//	while ((*tmp++ = *src++) != '\0');
//	return dest;
//}
//
//int main()
//{
//	char arr1[20] = "XXXXXXXXXX";
//	char arr2[] = "KilluaAoki";
//	printf("%s\n", MyStrcpy(arr1, arr2));
//	return 0;
//}

////调整奇数偶数顺序：调整数组使奇数全部都位于偶数前面。
////要求：
////	1. 输入一个整数数组，使奇数全部都位于偶数前面。
////	2. 实现函数能够调整数组中数字的顺序。
////	3. 奇数位于数组的前半部分，偶数位于数组的后半部分。
//void Swap(int* ptr1, int* ptr2)
//{
//	(*ptr1 ^ *ptr2) && (*ptr2 ^= *ptr1 ^= *ptr2, *ptr1 ^= *ptr2);
//}
//
//void PrintArray(const int* ptr, size_t size)
//{
//	for (int i = 0; i < size; ++i)
//	{
//		printf("%d ", *(ptr + i));
//	}
//	printf("\n");
//}
//
//void AdjustmentArray(int* ptr, size_t size)
//{
//	int j = 0;
//	for (int i = 0; i < size; ++i)
//	{
//		if (ptr[j] % 2 == 0 && ptr[i] % 2 != 0)
//		{
//			Swap(&ptr[j++], &ptr[i]);
//		}
//		else if (ptr[j] % 2 != 0)
//		{
//			j++;
//		}
//	}
//}
//
//int main()
//{
//	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	size_t size = sizeof(arr) / sizeof(arr[0]);
//	PrintArray(arr, size);
//	AdjustmentArray(arr, size);
//	PrintArray(arr, size);
//	return 0;
//}

////有序序列合并：https://www.nowcoder.com/practice/a9e943b0dab142759807d0cfb6863897。(排序)
//void Swap(int* ptr1, int* ptr2)
//{
//	(*ptr1 ^ *ptr2) && (*ptr2 ^= *ptr1 ^= *ptr2, *ptr1 ^= *ptr2);
//}
//
//void PrintArray(int arr[], int size)
//{
//	for (int i = 0; i < size; ++i)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//}
//
//void BubbleSort(int arr[], int size)
//{
//	for (int i = size - 1; i > 0; --i)
//	{
//		for (int j = 0; j < i; ++j)
//		{
//			if (arr[j] > arr[j + 1])
//			{
//				Swap(&arr[j], &arr[j + 1]);
//			}
//		}
//	}
//}
//
//int main()
//{
//	int n, m;
//	scanf("%d%d", &n, &m);
//	int arr[m + n];
//	for (int i = 0; i < m + n; ++i)
//	{
//		scanf("%d", &arr[i]);
//	}
//	BubbleSort(arr, m + n);
//	PrintArray(arr, m + n);
//	return 0;
//}

////小乐乐改数字：https://www.nowcoder.com/practice/fcd30aac9c4f4028b23919a0c649824d。(方法一)
//int main()
//{
//	char arr[10];
//	scanf("%s", arr, 10);
//	int len = (int)strlen(arr);
//	for (int i = 0; i < len; ++i)
//	{
//		if ((arr[i] - '0') % 2 == 0)
//		{
//			arr[i] = '0';
//		}
//		else
//		{
//			arr[i] = '1';
//		}
//	}
//	size_t num = 0;
//	for (int i = 0; i < len; i++)
//	{
//		num = num * 10 + (arr[i] - '0');
//	}
//	printf("%zu\n", num);
//	return 0;
//}

//////小乐乐改数字：https://www.nowcoder.com/practice/fcd30aac9c4f4028b23919a0c649824d。(方法二)
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int sum = 0;
//	int x = 0;
//	while (n)
//	{
//		int i = (n % 10) % 2;
//		sum += i * (int)pow(10, x++);
//		n /= 10;
//	}
//	printf("%d", sum);
//	return 0;
//}

////带空格直角三角形图案：https://www.nowcoder.com/practice/192d1039c3d44155bb868073f5482670。
//int main()
//{
//	int n = 0;
//	while (scanf("%d", &n) == 1)
//	{
//		for (int i = 0; i < n; ++i)
//		{
//			for (int j = 0; j <= n - 2 - i; ++j)
//			{
//				printf("  ");
//			}
//			for (int j = 0; j <= i; ++j)
//			{
//				printf("* ");
//			}
//			printf("\n");
//		}
//	}
//	return 0;
//}

////网购：https://www.nowcoder.com/practice/5d7dfd405e5f4e4fbfdff6862c46b751。
//int main()
//{
//	double price = 0;
//	int coupon = 0;
//	int month = 0;
//	int date = 0;
//	scanf("%lf %d %d %d", &price, &month, &date, &coupon);
//	if (month == 11)
//	{
//		if (coupon == 1)
//		{
//			printf("%.2lf\n", price * 0.7 - 50 >= 0 ? price * 0.7 - 50 : 0);
//		}
//		else
//		{
//			printf("%.2lf\n", price * 0.7 >= 0 ? price * 0.7 : 0);
//		}
//	}
//	else
//	{
//		if (coupon == 1)
//		{
//			printf("%.2lf\n", price * 0.8 - 50 >= 0 ? price * 0.8 - 50 : 0);
//		}
//		else
//		{
//			printf("%.2lf\n", price * 0.8 >= 0 ? price * 0.8 : 0);
//		}
//	}
//	return 0;
//}

////猜名次：五位运动员参加了十米台跳水比赛，请根据信息编程确定比赛的名次。
////信息：
////	A选手说：B第二，我第三。
////	B选手说：我第二，E第四。
////	C选手说：我第一，D第二。
////	D选手说：C最后，我第三。
////	E选手说：我第四，A第一。
////	比赛结束后，每位选手都说对了一半。
//int main()
//{
//	for (int a = 1; a < 6; ++a)
//	{
//		for (int b = 1; b < 6; ++b)
//		{
//			for (int c = 1; c < 6; ++c)
//			{
//				for (int d = 1; d < 6; ++d)
//				{
//					for (int e = 1; e < 6; ++e)
//					{
//						if ((b == 2) + (a == 3) == 1 && (b == 2) + (e == 4) == 1 && (c == 1) + (d == 2) == 1 &&
//							(c == 5) + (d == 3) == 1 && (e == 4) + (a == 1) == 1 && a * b * c * d * e == 120)
//						{
//							printf("A = %d B = %d C = %d D = %d E = %d\n", a, b, c, d, e);
//						}
//					}
//				}
//			}
//		}
//	}
//	return 0;
//}

////猜凶手：日本某地发生了一件谋杀案，警察通过排查确定杀人凶手必为四个嫌疑犯中的一个，请根据信息编程确定谁是凶手。
////信息：
////	A说：不是我。
////	B说：是C。
////	C说：是D。
////	D说：C在胡说。
////	已知3个人说了真话，1个人说的是假话。
//int main()
//{
//	for (int killer = 'A'; killer <= 'D'; ++killer)
//	{
//		if (((killer != 'A') + (killer == 'C') + (killer == 'D') + (killer != 'D')) == 3)
//		{
//			printf("killer = %c\n", killer);
//		}
//	}
//	return 0;
//}

////杨辉三角：https://www.nowcoder.com/practice/e671c6a913d448318a49be87850adbcc。
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int arr[n][n];
//	for (int i = 0; i < n; ++i)
//	{
//		for (int j = 0; j < i + 1; ++j)
//		{
//			if (i == j || j == 0)
//			{
//				arr[i][j] = 1;
//			}
//			else
//			{
//				arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
//			}
//			printf("%5d", arr[i][j]);
//		}
//		printf("\n");
//	}
//	return 0;
//}

////字符串左旋：实现一个函数，可以左旋字符串中的"k"个字符。(常规方法)
////信息：
////	"ABCD"左旋一个字符得到"BCDA"
////	"ABCD"左旋两个字符得到"CDAB"
//void Swap(char* str1, char* str2)
//{
//	(*str1 ^ *str2) && (*str2 ^= *str1 ^= *str2, *str1 ^= *str2);
//}
//
//char* LeftRotateString(char* str, int k)
//{
//	size_t len = strlen(str);
//	if (len <= 1)
//		return str;
//	k %= (int)len;
//	for (int i = 0; i < k; ++i)
//	{
//		char* left = str;
//		char* right = str + 1;
//		while (*right)
//		{
//			Swap(left, right);
//			left++;
//			right++;
//		}
//	}
//	return str;
//}
//
//int main()
//{
//	int k = 0;
//	scanf_s("%d", &k);
//	char arr[] = "ABCD";
//	printf("%s\n", LeftRotateString(arr, k));
//	return 0;
//}

////字符串左旋：实现一个函数，可以左旋字符串中的"k"个字符。(三步翻转法)
////信息：
////	"ABCD"左旋一个字符得到"BCDA"
////	"ABCD"左旋两个字符得到"CDAB"
//void Swap(char* str1, char* str2)
//{
//	(*str1 ^ *str2) && (*str2 ^= *str1 ^= *str2, *str1 ^= *str2);
//}
//
//void ReverseString(char* left, char* right)
//{
//	while (left < right)
//	{
//		Swap(left, right);
//		left++;
//		right--;
//	}
//}
//
//char* LeftRotateString(char* str, int k)
//{
//	size_t len = strlen(str);
//	if (len <= 1)
//		return str;
//	k %= (int)len;
//	ReverseString(str, str + len - 1);
//	ReverseString(str, str + len - k - 1);
//	ReverseString(str + len - k, str + len - 1);
//	return str;
//}
//
//int main()
//{
//	int k = 0;
//	scanf_s("%d", &k);
//	char arr[] = "ABCD";
//	printf("%s\n", LeftRotateString(arr, k));
//	return 0;
//}

////杨氏矩阵：https://leetcode.cn/problems/search-a-2d-matrix-ii/。
//bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target)
//{
//	int x = matrixSize - 1;
//	int y = 0;
//	while (x >= 0 && y < *matrixColSize)
//	{
//		if (target > matrix[x][y])
//		{
//			y++;
//		}
//		else if (target < matrix[x][y])
//		{
//			x--;
//		}
//		else
//		{
//			return true;
//		}
//	}
//	return false;
//}

////判断字符串旋转：写一个函数，判断一个字符串是否为另外一个字符串旋转之后的字符串。(模拟方法)
////要求：
////	1. 给定"s1 = AABCD"和"s2 = BCDAA"，返回"1"。
////	2. 给定"s1 = abcd"和"s2 = ACBD"，返回"0"。
////信息：
////	"AABCD"左旋一个字符得到"ABCDA"。
////	"AABCD"左旋两个字符得到"BCDAA"。
////	"AABCD"右旋一个字符得到"DAABC"。
//bool RotateString(char* str1, char* str2)
//{
//	size_t m = strlen(str1), n = strlen(str2);
//	if (m != n)
//		return false;
//	for (int i = 0; i < n; i++)
//	{
//		bool flag = true;
//		for (int j = 0; j < n; j++)
//		{
//			if (str1[(i + j) % n] != str2[j])
//			{
//				flag = false;
//				break;
//			}
//		}
//		if (flag)
//		{
//			return true;
//		}
//	}
//	return false;
//}
//
//int main()
//{
//	char arr1[] = "abcd";
//	char arr2[] = "ACBD";
//	printf("%s\n", RotateString(arr1, arr2) == true ? "true" : "false");
//	return 0;
//}

////判断字符串旋转：写一个函数，判断一个字符串是否为另外一个字符串旋转之后的字符串。(搜索子字符串方法)
////要求：
////	1. 给定"s1 = AABCD"和"s2 = BCDAA"，返回"1"。
////	2. 给定"s1 = abcd"和"s2 = ACBD"，返回"0"。
////信息：
////	"AABCD"左旋一个字符得到"ABCDA"。
////	"AABCD"左旋两个字符得到"BCDAA"。
////	"AABCD"右旋一个字符得到"DAABC"。
//bool RotateString(char* str1, char* str2)
//{
//	size_t m = strlen(str1), n = strlen(str2);
//	if (m != n)
//		return false;
//	char* str = (char*)malloc(sizeof(char) * (m + n + 1));
//	sprintf(str, "%s%s", str2, str2);
//	return strstr(str, str1);
//}
//
//int main()
//{
//	char arr1[] = "abcd";
//	char arr2[] = "ACBD";
//	printf("%s\n", RotateString(arr1, arr2) == true ? "true" : "false");
//	return 0;
//}

////"qsort"库函数的使用练习：练习使用库函数"qsort"，排序各种类型的数据。(整型数组排序)
//void PrintArray(int arr[], size_t size)
//{
//	for (int i = 0; i < size; ++i)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//}
//
//int CompareIntArray(const void* p1, const void* p2)
//{
//	return *(int*)p1 - *(int*)p2;
//}
//
//int main()
//{
//	int arr[] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
//	size_t size = sizeof(arr) / sizeof(arr[0]);
//	qsort(arr, size, sizeof(arr[0]), CompareIntArray);
//	PrintArray(arr, size);
//	return 0;
//}

////"qsort"库函数的使用练习：练习使用库函数"qsort"，排序各种类型的数据。(结构体类型数组内的数据排序)
//struct Student
//{
//	char name[20];
//	size_t age;
//};
//
//void PrintStudent(struct Student arr[], size_t size)
//{
//	for (int i = 0; i < size; ++i)
//	{
//		printf("{ %s, %zu },", arr[i].name, arr[i].age);
//	}
//	printf("\n");
//}
//
//int ComparName(const void* p1, const void* p2)
//{
//	return strcmp(((struct Student*)p1)->name, ((struct Student*)p2)->name);
//}
//
//int ComparAge(const void* p1, const void* p2)
//{
//	return (int)(((struct Student*)p1)->age) - (int)(((struct Student*)p2)->age);
//}
//
//int main()
//{
//	struct Student arr[] = {{ "A", 19 },
//							{ "X", 21 },
//							{ "B", 20 },
//							{ "Y", 19 },
//							{ "C", 18 },
//							{ "Z", 20 }};
//	size_t size = sizeof(arr) / sizeof(arr[0]);
//
//	PrintStudent(arr, size);
//
//	qsort(arr, size, sizeof(arr[0]), ComparName);
//
//	PrintStudent(arr, size);
//
//	qsort(arr, size, sizeof(arr[0]), ComparAge);
//
//	PrintStudent(arr, size);
//
//	return 0;
//}

////模仿"qsort"库函数模拟实现冒泡排序：模仿库函数"qsort"，实现一个通用的冒泡排序。
//void PrintArray(int arr[], size_t size)
//{
//	for (int i = 0; i < size; ++i)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//}
//
//void Swap(char* str1, char* str2, size_t size)
//{
//	for (size_t i = 0; i < size; ++i)
//	{
//		(*str1 ^ *str2) && (*str2 ^= *str1 ^= *str2, *str1 ^= *str2);
//		str1++;
//		str2++;
//	}
//}
//
//int CompareIntArray(const void* p1, const void* p2)
//{
//	return *(int*)p1 - *(int*)p2;
//}
//
//void BubbleSort(void* base, size_t num, size_t size, int (* compar)(const void*, const void*))
//{
//	if (num <= 1)
//		return;
//	for (size_t end = num - 1; end > 0; --end)
//	{
//		for (size_t i = 1; i <= end; ++i)
//		{
//			if (compar((char*)base + (i - 1) * size, (char*)base + i * size) > 0)
//			{
//				Swap((char*)base + (i - 1) * size, (char*)base + i * size, size);
//			}
//		}
//	}
//}
//
//int main()
//{
//	int arr[] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
//	size_t size = sizeof(arr) / sizeof(arr[0]);
//	BubbleSort(arr, size, sizeof(arr[0]), CompareIntArray);
//	PrintArray(arr, size);
//	return 0;
//}

////矩阵转置：https://www.nowcoder.com/practice/351b3d03e410496ab5a407b7ca3fd841。
//int main()
//{
//	int m = 0, n = 0;
//	scanf("%d%d", &n, &m);
//	int arr[n][m];
//	int copyArr[m][n];
//	for (int i = 0; i < n; ++i)
//	{
//		for (int j = 0; j < m; ++j)
//		{
//			scanf("%d", &arr[i][j]);
//			copyArr[j][i] = arr[i][j];
//		}
//	}
//	for (int i = 0; i < m; ++i)
//	{
//		for (int j = 0; j < n; ++j)
//		{
//			printf("%d ", copyArr[i][j]);
//		}
//		printf("\n");
//	}
//	return 0;
//}

////上三角矩阵判定：https://www.nowcoder.com/practice/f5a29bacfc514e5a935723857e1245e4。
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int arr[n][n];
//	for (int i = 0; i < n; ++i)
//	{
//		for (int j = 0; j < n; ++j)
//		{
//			scanf("%d", &arr[i][j]);
//		}
//	}
//	bool flag = false;
//	for (int i = 0; i < n; ++i)
//	{
//		for (int j = 0; j < i; ++j)
//		{
//			if (arr[i][j] != 0)
//			{
//				flag = true;
//			}
//		}
//		if (flag)
//			break;
//	}
//	if (!flag || arr[0][0] == 0)
//	{
//		printf("YES\n");
//	}
//	else
//	{
//		printf("NO\n");
//	}
//	return 0;
//}

////有序数组判断：https://www.nowcoder.com/practice/22e87f8a8d764a6582710f38d1b40c6e。
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int arr[n];
//	bool flag1 = false;
//	bool flag2 = false;
//	for (int i = 0; i < n; ++i)
//	{
//		scanf("%d", &arr[i]);
//		if (i >= 1)
//		{
//			if (arr[i] < arr[i - 1])
//				flag1 = true;
//			else if (arr[i] > arr[i - 1])
//				flag2 = true;
//		}
//	}
//	if (flag1 && flag2)
//		printf("unsorted\n");
//	else
//		printf("sorted\n");
//	return 0;
//}

////"strlen"库函数实现：模拟实现"strlen"库函数。(三种实现方法)
//size_t My_Strlen_Count(char* str)
//{
//	size_t count = 0;
//	while (*str++)
//	{
//		++count;
//	}
//	return count;
//}
//
//size_t My_Strlen_Recursion(char* str)
//{
//	if (*str == '\0')
//	{
//		return 0;
//	}
//	return 1 + My_Strlen_Recursion(str + 1);
//}
//
//size_t My_Strlen_Pointer(char* str)
//{
//	char* tmp = str;
//	while (*tmp++);
//	return tmp - 1 - str;
//}
//
//int main()
//{
//	char* str = "KilluaAoki";
//
//	//计数：创建临时变量。
//	printf("%zu\n", My_Strlen_Count(str));
//
//	//递归：不创建临时变量。
//	printf("%zu\n", My_Strlen_Recursion(str));
//
//	//指针：指针运算。
//	printf("%zu\n", My_Strlen_Pointer(str));
//
//	return 0;
//}

////"strcpy"库函数实现：模拟实现"strcpy"库函数。
//char* My_Strcpy(char* dest, const char* src)
//{
//	char* tmp = dest;
//	while ((*tmp++ = *src++));
//	return dest;
//}
//
//int main()
//{
//	char arr1[20] = "XXXXXXXXXX";
//	char arr2[] = "KilluaAoki";
//	printf("%s\n", My_Strcpy(arr1, arr2));
//	return 0;
//}

////"strcat"库函数实现：模拟实现"strcat"库函数。
//char* My_Strcat(char* dest, const char* src)
//{
//	char* tmp = dest;
//	while (*tmp++);
//	--tmp;
//	while ((*tmp++ = *src++));
//	return dest;
//}
//
//int main()
//{
//	char arr1[] = "Killua ";
//	char arr2[] = "Aoki";
//	printf("%s\n", My_Strcat(arr1, arr2));
//	return 0;
//}

////"strcmp"库函数实现：模拟实现"strcmp"库函数。
//int My_Strcmp(const char* str1, const char* str2)
//{
//	int ret = 0;
//
//	while ((ret = ((int)(*((unsigned char*)str1))) - *((unsigned char*)str2++)) == 0 && *str1++);
//
//	return ret;
//}
//
//int main()
//{
//	char arr1[] = "KilluaAoki";
//	char arr2[] = "KilluaAoki";
//
//	int ret = My_Strcmp(arr1, arr2);
//
//	if (ret == 0)
//	{
//		printf("==\n");
//	}
//	else if (ret < 0)
//	{
//		printf("<\n");
//	}
//	else
//	{
//		printf(">\n");
//	}
//
//	return 0;
//}

////"strstr"库函数实现：模拟实现"strstr"库函数。
//char* My_Strstr(const char* str, const char* substr)
//{
//	const char* str1 = str;
//	const char* str2 = substr;
//	do
//	{
//		if (*str2 == '\0')
//		{
//			return (char*)str;
//		}
//		if (*str1 == *str2)
//		{
//			++str1;
//			++str2;
//		}
//		else
//		{
//			str2 = substr;
//			if (*str1 == '\0')
//			{
//				return NULL;
//			}
//			str1 = ++str;
//		}
//	} while (1);
//}
//
//int main()
//{
//	char arr1[] = "KilluaAoki";
//	char arr2[] = "Aoki";
//	printf("%s\n", My_Strstr(arr1, arr2));
//	return 0;
//}

////"memcpy"库函数实现：模拟实现"memcpy"库函数。
//void* My_Memcpy(void* destination, const void* source, size_t num)
//{
//	unsigned char* ptr1 = destination;
//	const unsigned char* ptr2 = source;
//	while (num--)
//	{
//		*ptr1++ = *ptr2++;
//	}
//	return destination;
//}
//
//int main()
//{
//	int arr1[10] = { 0 };
//	int arr2[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
//	My_Memcpy(arr1, arr2, sizeof(arr2));
//	for (int i = 0; i < sizeof(arr1) / sizeof(arr1[0]); i++)
//	{
//		printf("%d ", arr1[i]);
//	}
//	return 0;
//}

////"memmove"库函数实现：模拟实现"memmove"库函数。
//void* My_Memmove(void* destination, const void* source, size_t num)
//{
//	unsigned char* ptr1 = destination;
//	const unsigned char* ptr2 = source;
//	if (ptr1 > ptr2)
//	{
//		while (num--)
//		{
//			ptr1[num] = ptr2[num];
//		}
//	}
//	else
//	{
//		while (num--)
//		{
//			*ptr1++ = *ptr2++;
//		}
//	}
//	return destination;
//}
//
//int main()
//{
//	int arr[10] = { 5, 6, 7, 8, 9, 0, 1, 2, 3, 4 };
//	My_Memmove(arr + 1, arr + 0, sizeof(arr[0]) * 4);
//	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}

////小乐乐与欧几里得：https://www.nowcoder.com/practice/da13e0cf321e4df9acd0fdf0a433cbb0。
//size_t GetFactor(size_t x, size_t y)
//{
//	return y == 0 ? x : GetFactor(y, x % y);
//}
//
//int main()
//{
//	size_t n = 0;
//	size_t m = 0;
//	scanf("%zu%zu", &n, &m);
//	size_t product = m * n;
//	size_t factor = GetFactor(n, m);
//	printf("%zu\n", (product / factor) + factor);
//	return 0;
//}

////空心正方形图案：https://www.nowcoder.com/practice/72347ee949dc47399186ee183632f303。
//int main()
//{
//	int input = 0;
//	while (scanf("%d", &input) != EOF)
//	{
//		for (int i = 0; i < input; ++i)
//		{
//			for (int j = 0; j < input; ++j)
//			{
//				if (i == 0 || i == input - 1 || j == 0 || j == input - 1)
//				{
//					printf("* ");
//				}
//				else
//				{
//					printf("  ");
//				}
//			}
//			printf("\n");
//		}
//	}
//	return 0;
//}

////箭形图案：https://www.nowcoder.com/practice/a6d1081e0c9a42f19e42ed6cd91556c1。
//int main()
//{
//	int input = 0;
//	while (scanf("%d", &input) != EOF)
//	{
//		for (int i = 1; i <= input * 2 + 1; i++)
//		{
//			for (int j = 1; j <= input * 2 + 1; j++)
//			{
//				if (i <= input + 1)
//				{
//					if ((2 * i + j >= 2 * input + 3) && (i + j <= 2 * input + 2))
//					{
//						printf("*");
//					}
//					else
//					{
//						printf(" ");
//					}
//				}
//				else
//				{
//					if ((2 * i - j <= 2 * input + 1) && (i >= j))
//					{
//						printf("*");
//					}
//					else
//					{
//						printf(" ");
//					}
//				}
//			}
//			printf("\n");
//		}
//	}
//	return 0;
//}

////公务员面试：https://www.nowcoder.com/practice/f3a134908d5b41869f14f58307008a97。
//int main()
//{
//	int input = 0, min = 101, max = -1, sum = 0, count = 0;
//	while (scanf("%d", &input) != EOF)
//	{
//		if (input > max)
//		{
//			max = input;
//		}
//		if (input < min)
//		{
//			min = input;
//		}
//		sum += input;
//		count++;
//		if (count == 7)
//		{
//			printf("%.2f\n", (sum - min - max) / 5.0);
//			min = 101, max = -1, sum = 0, count = 0;
//		}
//	}
//	return 0;
//}

////"strncpy"库函数实现：模拟实现"strncpy"库函数。
//char* My_Strncpy(char* destination, const char* source, size_t count)
//{
//	char* tmp = destination;
//	while (count--)
//	{
//		if ((*tmp++ = *source))
//		{
//			source++;
//		}
//	}
//	return destination;
//}
//
//int main()
//{
//	char arr1[20] = "XXXXXXAoki";
//	char arr2[] = "Killua";
//	printf("%s\n", My_Strncpy(arr1, arr2, 10));
//	return 0;
//}

////"strncat"库函数实现：模拟实现"strncat"库函数。
//char* My_Strncat(char* destination, const char* source, size_t count)
//{
//	char* tmp = destination;
//	while (*tmp++);
//	--tmp;
//	while (count-- && (*tmp = *source++))
//	{
//		++tmp;
//	}
//	*tmp = '\0';
//	return destination;
//}
//
//int main()
//{
//	char arr1[] = "Killua ";
//	char arr2[] = "Aoki";
//	printf("%s\n", My_Strncat(arr1, arr2, 4));
//	return 0;
//}

////"strncmp"库函数实现：模拟实现"strncmp"库函数。
//int My_Strncmp(const char* str1, const char* str2, size_t count)
//{
//	int ret = 0;
//	while (count-- && ((ret = ((int)(*((unsigned char*)str1))) - *((unsigned char*)str2++)) == 0) && *str1++);
//	return ret;
//}
//
//int main()
//{
//	char buffer1[] = "KilluaAoki";
//	char buffer2[] = "KilluaAoki";
//
//	int n = My_Strncmp(buffer1, buffer2, 10);
//
//	if (n > 0)
//	{
//		printf("'%s' is greater than '%s'.\n", buffer1, buffer2);
//	}
//	else if (n < 0)
//	{
//		printf("'%s' is less than '%s'.\n", buffer1, buffer2);
//	}
//	else
//	{
//		printf("'%s' is the same as '%s'.\n", buffer1, buffer2);
//	}
//
//	return 0;
//}

////"memcmp"库函数实现：模拟实现"memcmp"库函数。
//int My_Memcmp(const void* ptr1, const void* ptr2, size_t num)
//{
//	int ret = 0;
//	const unsigned char* p1 = (const unsigned char*)ptr1;
//	const unsigned char* p2 = (const unsigned char*)ptr2;
//	while (num-- && ((ret = ((int)(*p1++)) - *p2++) == 0));
//	return ret;
//}
//
//int main()
//{
//	char buffer1[] = "KilluaAoki";
//	char buffer2[] = "KilluaAoki";
//
//	int n = memcmp(buffer1, buffer2, sizeof(buffer1));
//
//	if (n > 0)
//	{
//		printf("'%s' is greater than '%s'.\n", buffer1, buffer2);
//	}
//	else if (n < 0)
//	{
//		printf("'%s' is less than '%s'.\n", buffer1, buffer2);
//	}
//	else
//	{
//		printf("'%s' is the same as '%s'.\n", buffer1, buffer2);
//	}
//
//	return 0;
//}

////"memset"库函数实现：模拟实现"memset"库函数。
//void* My_Memset(void* ptr, int value, size_t num)
//{
//	unsigned char* tmp = (unsigned char*)ptr;
//	while (num--)
//	{
//		*tmp++ = (unsigned char)value;
//	}
//	return ptr;
//}
//
//void PrintArray(int arr[], size_t size)
//{
//	for (size_t i = 0; i < size; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//}
//
//int main()
//{
//	int arr[10];
//
//	size_t size = sizeof(arr) / sizeof(arr[0]);
//
//	My_Memset(arr, 0, sizeof(arr));
//
//	PrintArray(arr, size);
//
//	return 0;
//}

////找单身狗：在一个数组中只有两个数字是出现一次，其他所有数字都出现了两次，编写函数找出这两个只出现一次的数字。
//void SingleNumber(const int arr[], size_t size, int* retX, int* retY)
//{
//	int xor = 0;
//	for (size_t i = 0; i < size; i++)
//	{
//		xor ^= arr[i];
//	}
//	int bit = (xor == INT_MIN ? xor : xor & ~(xor - 1));
//	*retX = *retY = 0;
//	for (size_t i = 0; i < size; i++)
//	{
//		if (arr[i] & bit)
//		{
//			*retX ^= arr[i];
//		}
//		else
//		{
//			*retY ^= arr[i];
//		}
//	}
//}
//
//int main()
//{
//	int arr[] = { 11, 22, 33, 44, 55, 22, 33, 44 };
//	size_t size = sizeof(arr) / sizeof(arr[0]);
//	int retX = 0;
//	int retY = 0;
//	SingleNumber(arr, size, &retX, &retY);
//	printf("%d %d\n", retX, retY);
//	return 0;
//}

////"atoi"库函数实现：模拟实现"atoi"库函数。
//enum Status
//{
//	VALID = 0,
//	INVALID
//} getStatus = INVALID;
//
//long long Core(const char* str, int flag)
//{
//	getStatus = INVALID;
//	long long ret = 0;
//	while (*str)
//	{
//		if (*str >= '0' && *str <= '9')
//		{
//			ret = ret * 10 + flag * (*str - '0');
//			if (ret > INT_MAX || ret < INT_MIN)
//			{
//				return 0;
//			}
//			++str;
//		}
//		else
//		{
//			return (int)ret;
//		}
//	}
//	if (*str == '\0')
//	{
//		getStatus = VALID;
//	}
//	return ret;
//}
//
//int My_Atoi(const char* str)
//{
//	if (str == NULL || *str == '\0')
//	{
//		return 0;
//	}
//	while (*str == ' ')
//	{
//		++str;
//	}
//	int flag = 1;
//	if (*str == '+')
//	{
//		flag = 1;
//		++str;
//	}
//	else if (*str == '-')
//	{
//		flag = -1;
//		++str;
//	}
//	long long ret = 0;
//	if (*str)
//	{
//		ret = Core(str, flag);
//	}
//	return (int)ret;
//}
//
//void Test(const char* str)
//{
//	int result = My_Atoi(str);
//	if (result == 0 && getStatus == INVALID)
//		printf("The input %s is invalid.\n", str);
//	else
//		printf("Number for %s is: %d.\n", str, result);
//}
//
//int main()
//{
//	Test(NULL);
//	Test("");
//	Test("123");
//	Test("+123");
//	Test("-123");
//	Test("1a33");
//	Test("+0");
//	Test("-0");
//	Test("+2147483647");
//	Test("-2147483647");
//	Test("+2147483648");
//	Test("-2147483648");
//	Test("+2147483649");
//	Test("-2147483649");
//	Test("+");
//	Test("+");
//	Test("-");
//	Test("+123abc123");
//	Test("-123abc123");
//	Test("+abc123abc");
//	Test("-abc123abc");
//	return 0;
//}

////实现"offsetof"宏：写一个宏，计算结构体中某变量相对于首地址的偏移，并给出说明。
//#define OFFSETOF(type, member) ((size_t)(&(((type*)0)->member)))
//
//struct MyStruct
//{
//	char x;
//	int y;
//	char z;
//};
//
//int main()
//{
//	struct MyStruct myStruct = { 0 };
//
//	printf("%zu\n", OFFSETOF(struct MyStruct, x));
//	printf("%zu\n", OFFSETOF(struct MyStruct, y));
//	printf("%zu\n", OFFSETOF(struct MyStruct, z));
//
//	return 0;
//}

////交换奇偶位：写一个宏，可以将输入的整数的二进制位的奇数位和偶数位交换。
//#define SWAP_ODD_EVEN(x) ((((x) & 0xaaaaaaaa) >> 1) | (((x) & 0x55555555) << 1))
//
//void PrintBinary(int x)
//{
//	for (int i = 31; i >= 0; i--)
//	{
//		printf("%-2d ", (x >> i) & 1);
//	}
//	printf("\n");
//}
//
//int main()
//{
//	int num = 0;
//	scanf_s("%d", &num);
//	PrintBinary(num);
//	num = SWAP_ODD_EVEN(num);
//	PrintBinary(num);
//	printf("%d\n", num);
//	return 0;
//}