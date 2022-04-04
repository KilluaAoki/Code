#include <stdio.h>
#include <assert.h>

/*
	栈区内存
		1.局部变量是存放在栈区上的。
		2.栈区内存的使用习惯是先使用高地址空间，再使用低地址空间。
*/

/*
一段神奇的错误代码：研究程序死循环的原因(32位下运行)。
	解答：因为局部变量是存放在栈区上的，并且栈区内存的使用习惯是先使用高地址空间再使用低地址空间，如下代码中“i”比“arr”先创建，故“i”
的地址高于“arr”，又因为数组随着下标的增长，地址是由低到高变化的，所以当循环体循环次数超过数组下标，就有可能访问到“i”的地址，将“i”重置
成0，重新开始循环造成死循环；在不同平台下创建变量的地址相隔不相同，若在Linux(gcc)会相隔1个整型，Windows(vc6.0)没有相隔、(vs2019)
会相隔2个整型。
*/
//int main()
//{
//	int i = 0;
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };//数组随着下标的增长，地址也在由低到高的变化。
//	for ( i = 0; i <= 12; i++)//越界访问。
//	{
//		arr[i] = 0;
//		printf("Aoki\n");
//	}
//	return 0;
//}

////模拟“strcpy”函数：返回值为目标空间的起始地址。
//char* my_strcpy(char* dest, const char* src)//使用“const”修饰“*src”保证指针指向的内容不能通过指针来改变(具体见“const”解析)。
//{
//	assert(dest != NULL && src != NULL);//断言：若表达式为假便会终止程序；“&&”从左到右遍历代码，一旦为假，边不会再向右执行。
//	char* tempptr = dest;//使用临时指针变量记录下”dest“的起始地址。
//	while (*dest++ = *src++)//当“*src”指向“\0”时，将“\0”赋值给“*dest”，同时表达式的结果为假，循环会停止。
//	{
//		;
//	}
//	return tempptr;//返回目标空间的起始地址。
//}
//int main()
//{
//	char arr1[15] = "XXXXXXXXXX";
//	char arr2[] = "Aoki";
//	printf("%s\n", my_strcpy(arr1, arr2));//链式访问。
//	return 0;
//}

/*
	“const”的使用
		1.当使用“const”修饰变量，这个变量就被称之为常变量，变量不能被修改，但是其本质上还是变量。
		2.当使用“const”修饰指针变量时
			a.“const“放在”*“的左边，表示指针变量所指向的内容不能被修改，但是指针变量本身所指向的地址可以被修改。
			b.“const“放在”*“的右边，表示指针变量所指向的位置也就是其本身不能被修改，但是指针变量所指向的内容可以被修改。
*/

////“const”使用示例
//int main()
//{
//	////“const”修饰变量使用示例
//	//int a = 0;//变量“a”。
//	//const int b = 0;//常变量“b”。
//	//a = 100;//变量修改成功。
//	//b = 100;//变量修改失败，编译器报错：表达式必须是可修改的左值。
//
//	////“const”修饰指针变量使用示例(“const“放在”*“的左边)
//	//int	arr1[5] = { 1,2,3,4,5 };
//	//int	arr2[5] = { 1,2,3,4,5 };
//	//int* pa = arr1;
//	//const int* pb = arr1;
//	//*pa = 0;//变量修改成功：数组下标为“0“的元素被修改成整型”0“。
//	//*pb = 0;//变量修改失败：经过”const“修饰的”*pb“不能修改所指向的内容；编译器报错：表达式必须是可修改的左值。
//	//pb = arr2;//变量修改成功：指针变量所指向的地址被修改成数组”arr2“首元素的地址。
//			  
//	////“const”修饰指针变量使用示例(“const“放在”*“的右边)
//	//int	arr1[5] = { 1,2,3,4,5 };
//	//int	arr2[5] = { 1,2,3,4,5 };
//	//int* pa = arr1;
//	//int* const pb = arr1;
//	//*pa = 0;//变量修改成功：数组下标为“0“的元素被修改成整型”0“。
//	//*pb = 1;//变量修改成功：数组下标为“0“的元素被修改成整型”1“。
//	//pb = arr2;//变量修改失败：经过”const“修饰的”pb“不能修改所指向的地址；编译器报错：表达式必须是可修改的左值。
//
//	return 0;
//}

////模拟“strlen”函数
//size_t my_strlen(const char* str)
//{
//	assert(str);
//	const char* tempptr = str;
//	while (*str++);
//	return (str - tempptr - 1);
//}
//int main()
//{
//	char arr[] = "Aoki";
//	printf("%lld\n", my_strlen(arr));
//	return 0;
//}