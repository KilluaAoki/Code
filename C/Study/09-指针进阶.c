#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <Windows.h>

/*
	指针进阶
		1.字符指针
		2.数组指针
		3.指针数组
		4.数组传参和指针传参
		5.函数指针
		6.函数指针数组
		7.指向函数指针数组的指针
		8.回调函数
		9.指针与数组相关习题
*/

/**
	字符指针
		1.字符串常量在内存中存储的位置是文字常量区，文字常量区的元素只读不可修改。
		2.字符数组是在内存中是单独开辟的一块栈区内存，数组在被字符串赋值时，其实是将字符串常量的值复制到数组，也就是栈中，这样是可以通过访问内存进行修改的。
		3.当字符指针初始化的值为常量字符串，其实指向的是文字常量区的首字符地址，因文字常量区的元素只读不可修改，故不可通过指针变量间接访问从而修改字符串的值。
*/

////字符指针示例一
//int main()
//{
//	char arr[] = "Killua Aoki";//本质上是把"Killua Aoki"这个常量字符串的值复制存储在了字符变量数组"arr"所在的栈区空间中。
//	
//	*arr = '*';
//
//	printf("%s\n", arr);
//
//	char* ptr = "Killua Aoki";//本质上是把"Killua Aoki"这个常量字符串的首字符"K"的地址存储在了指针变量"ptr"中，也就是指向的是常量字符串首字符，指向的是文字常量区；更标准的写法是在"char"左边再加上"const"关键字。
//	
//	//*ptr = '*';//错误：写入访问权限冲突，因为指针变量"ptr"所指向的是常量字符串的首字符地址，指向内存中的文字常量区，其元素只读不可修改，所以会导致报错，但是指针变量所指向的地址是可以改变的。
//
//	printf("%s\n", ptr);
//
//	return 0;
//}

////字符指针示例二
//int main()
//{
//	char str1[] = "Killua Aoki";
//	char str2[] = "Killua Aoki";
//
//	const char* str3 = "Killua Aoki";
//	const char* str4 = "Killua Aoki";
//
//	if (str1 == str2)//判断为假，因为用相同的常量字符串去初始化不同的数组时会开辟出不同的栈区内存块，其首元素的地址不相同，所以会进入"else"。
//		printf("str1 and str2 are same\n");
//	else
//		printf("str1 and str2 are not same\n");
//	
//	if (str3 == str4)//判断为真，"str3"和"str4"指向的是同一个常量字符串的首字符，C语言会将常量字符串存储到单独的一个内存区域，也就是文字常量区，当几个指针指向同一个字符串的时候，实际上是指向同一块内存。
//		printf("str3 and str4 are same\n");
//	else
//		printf("str3 and str4 are not same\n");
//
//	return 0;
//}

/**
	指针数组：用于存放指针的数组。
*/

////指针数组示例：模拟二维数组，但不同于二维数组，二维数组内的元素在内存中是连续存放的，但这种形式是一个数组内的元素是连续存放的，不同数组的地址不连续。
//int main()
//{
//	int arr1[5] = { 0,1,2,3,4 };
//	int arr2[5] = { 1,2,3,4,5 };
//	int arr3[5] = { 2,3,4,5,6 };
//	int* ptr1[3] = { arr1,arr2,arr3 };//"ptr1"是数组，数组有三个元素，其中存放的元素是指向"int"类型的指针。
//	int(*ptr2[3])[5] = { &arr1,&arr2,&arr3 };//"ptr2"是数组，数组有三个元素，存放的元素是指向存放着五个元素的整型数组的数组指针。
//	for (int i = 0; i < 3; i++)
//	{
//		for (int j = 0; j < 5; j++)
//		{
//			printf("%d ", ptr1[i][j]);//"ptr1[i][j]"等价于"*(ptr1[i] + j)"。
//		}
//		printf("\n");
//	}
//	printf("\n");
//	for (int i = 0; i < 3; i++)
//	{
//		for (int j = 0; j < 5; j++)
//		{
//			printf("%d ", *(*ptr2[i] + j));//"*(*ptr2[i] + j)"等价于"(*ptr2[i])[j]"。
//		}
//		printf("\n");
//	}
//	return 0;
//}

/**
	数组指针：能够指向数组的指针。
		1.创建数组指针需注意数组指针变量名需先与"*"结合，若与"[]"先结合则表明是数组而不是指针，因为"[]"的优先级比"*"高，所以需加上"()"确保"*"先与变量名称结合。
		2.数组名不同情况下的差异
			a."sizeof(arr_name)"：意为计算整个数组的大小，此时的"arr_name"(数组名)表示整个数组。
			b."&arr_name"：意为取出整个数组的地址，此时的"arr_name"(数组名)表示整个数组。
			c.除"sizeof(arr_name)"和"&arr_name"两种情况，其余的数组名都表示为数组的首元素的地址。
			d.当数组名表示为整个数组的情况时，其类型为其数组的类型，与数组名表示为首元素的地址的情况不相同，也就是与指针类型不相同。
		3.数组指针多应用于二维数组，应用于一维数组过于麻烦。
		4.数组传参
			a.当一维数组以数组名进行传参，实参为数组，形参可以是数组也可以是指针。
				1.当实参为一级指针数组的数组名时，以数组名传参，实参可以是一级指针数组。
				2.当实参为一级指针数组的数组名时，以数组名传参，若要以指针接收，必须是二级指针，因为数组名是首元素的地址，指针数组的首元素是一级指针，一级指针的地址为二级指针，故需要二级指针接收。(其他级指针数组同理)
			b.当二维数组以数组名进行传参，实参为数组，形参可以是二维数组也可以是数组指针。
				1.当实参为二维数组的数组名时，以数组名传参，当形参为二维数组时，行可以省略，列不能省略，因为对于一个二维数组来说，可以不知道有多少行，但是必须知道每一行有多少元素。
				2.当实参为二维数组的数组名时，以数组名传参，当形参为指针时，不能是一级指针或二级指针，因为二维数组的数组名的首元素相当于首行的一维数组，需要指向一维数组的数组指针接收。
		5.指针传参：明确实参的类型，再以同样类型的形参接收。
*/

////创建数组指针示例
//int main()
//{
//	int arr[10] = { 0,1,2,3,4,5,6,7,8,9 };
//	int(*parr)[10] = &arr;//注意需添加括号，否则"parr"先与"[]"符号结合表示为数组；"*parr"说明"parr"是指针，"[10]"说明指针指向数组并且数组存放了"10"个元素，每个元素的类型是"int"，故"parr"是整型数组指针。
//	return 0;
//}

////数组名示例
//int main()
//{
//	int arr[10] = {0};//整型数组，里面共有"10"个整型元素。
//	int* p1 = arr;//整型指针，将数组"arr"首元素的地址存放在一个整型指针变量中。
//	int (*p2)[10] = &arr;//数组指针，使用取地址操作符将整个数组"arr"的地址存放在一个整型数组指针变量中，其指向的是整个数组"arr"的地址。
//
//	//以下两行打印的结果相同，只能说明两个指针指向的都是同一个位置，也就是值是相同的，但类型是不一样的。
//	printf("p1 = %p\n", p1);
//	printf("p2 = %p\n", p2);
//	
//	//以下两行打印的结果不相同，也就代表每个指针的步长不同，说明其两个指针类型不相同。
//	printf("p1 + 0 = %p\tp1 + 1 = %p\n", p1 + 0, p1 + 1);//"p1 + 1"相比于"p1 + 0"移动了"4"个字节。
//	printf("p2 + 0 = %p\tp2 + 1 = %p\n", p2 + 0, p2 + 1);//"p2 + 1"相比于"p2 + 0"移动了"40"个字节。
//
//	return 0;
//}

////数组指针应用于一维数组示例
//int main()
//{
//	int arr[10] = { 0,1,2,3,4,5,6,7,8,9 };
//	int(*parr)[10] = &arr;
//	for (int i = 0; i < 10; i++)
//	{
//		printf("%d ", *((*parr) + i));//"(*parr)"是对数组指针指向的整个数组进行解引用操作就相当于数组名，也就是数组首元素的地址，但这种形式过于麻烦。
//	}
//	return 0;
//}

////数组指针应用于二维数组示例
//void Print(int(*ptr)[5], int r, int c)//形参使用数组指针接收。
//{
//	for (int i = 0; i < r; i++)
//	{
//		for (int j = 0; j < c; j++)
//		{
//			printf("%d ", *(*(ptr + i) + j));
//		}
//		printf("\n");
//	}
//}
//
//int main()
//{
//	int arr[3][5] = { {1,2,3,4,5},{2,3,4,5,6},{3,4,5,6,7} };
//	Print(arr, 3, 5);//数组名作为实参，表示的是数组首元素的地址，而二维数组的数组名的首元素相当于首行的一维数组，故二维数组首元素的地址也就是首行的一维数组的地址。
//	return 0;
//}

////数组指针和指针数组综合应用示例：画图或思维导图推导。
//int main()
//{
//	//创建整型
//	int num = 10;
//
//	//使用指针指向整型：即整型指针。
//	int* pnum = &num;
//
//	//使用指针指向整型指针：即二级整型指针。
//	int** ppnum = &pnum;
//
//	//使用数组存放整型指针：即整型指针数组。
//	int* arrpnum[1] = { pnum };
//
//	//使用指针指向整型指针数组：即整型指针数组指针。
//	int* (*parrpnum)[1] = &arrpnum;
//
//	//创建整型数组
//	int arr[10] = { 0,1,2,3,4,5,6,7,8,9 };
//	
//	//使用指针指向整型数组：即整型数组指针。
//	int(*parr1)[10] = &arr;
//
//	//使用指针指向整型数组指针：即二级整型数组指针。
//	int (**pparr1)[10] = &parr1;
//	
//	//使用数组存放整型数组指针：即整型数组指针数组。
//	int (*arrparr1[1])[10] = { parr1 };
//
//	//使用数组存放整型数组：即创建整型二维数组。(此处不必深究概念)
//	int aarr[3][5] = { { 1,2,3,4,5 },{ 2,3,4,5,6 },{ 3,4,5,6,7 } };
//
//	//使用指针指向整型二维数组：即二维整型数组指针。
//	int(*paarr1)[5] = aarr;//此行指针指向的是二维数组中的第一行元素(一维数组)。
//	int(*paarr2)[3][5] = &aarr;//此行指针指向的是整型二维数组。
//
//	//使用指针指向二维整型数组指针：即二级二维整型数组指针。
//	int(**ppaarr2)[3][5] = &paarr2;
//
//	//使用数组存放二维整型数组指针：即二维整型数组指针数组。
//	int(*arrpaarr2[1])[3][5] = { paarr2 };
//
//	return 0;
//}

/**
	函数指针：用于存放函数的地址，指向的是函数。
		1.使用"&"操作符取出函数的地址等价于函数名表示函数的地址(不同于数组)。
		2.函数指针变量名等价于函数名，通过函数名调用函数也等价于通过函数指针变量名调用函数。
*/

////创建函数指针并通过函数指针调用函数示例
//int Add(int x, int y)
//{
//	return x + y;
//}
//
//void Test(char* str)
//{
//	;
//}
//
//int main()
//{
//	//创建函数指针示例
//	int (*pAdd)(int, int) = &Add;//"pAdd"：指向返回值类型为"int"，并且参数类型为"(int, int)"的函数的指针；"&Add"等价于"Add"；
//	void (*pTest)(char*) = &Test;//"pTest"：指向返回值类型为"void"，并且参数类型为"(char*)"的函数的指针；"&Test"等价于"Test"；
//	
//	//通过函数指针调用函数示例(如下代码等价)
//	printf("%d\n", Add(2, 3));//通过函数名调用函数"Add"。
//	printf("%d\n", (*pAdd)(2, 3));//通过函数指针调用函数：对指针"pAdd"进行解引用，找到函数并传递参数，获取返回值再打印出来。
//	printf("%d\n", pAdd(2, 3));//通过函数指针调用函数：因"&Add"等价于"Add"，故"Add"等价于"pAdd"，故通过函数名调用函数"Add(2, 3)"等价于"pAdd(2, 3)"。
//	
//	return 0;
//}

////两段有趣的代码
//int main()
//{
//	//第一段
//	(*(void (*)())0)();//函数调用。
//	//将"0"强制类型转换为函数指针类型，其中返回值为"void"、接收参数为"()"，此时"0"被解释为一个函数地址。
//	//通过"*(void (*)())0"对"0"地址进行解引用操作。
//	//通过"(*(void(*)())0)()"对"0"地址处的函数进行调用。
//
//	//第二段
//	void (*signal(int, void(*)(int)))(int);//函数声明。
//	//"signal"先与后面的括号进行结合，说明"signal"是函数
//	//"signal"函数的参数类型为"(int, void(*)(int))"，说明参数类型为整型和函数指针，其中参数类型中的函数指针的返回值类型为"void"，参数类型为整型。
//	//去除"signal(int, void(*)(int))"即为"signal"函数的返回值类型。
//	//"signal"函数的返回值类型为函数指针，其中函数指针的返回值类型为"void"，参数类型为"int"。
//
//	//第二段Plus版
//	typedef void(*pfun_t)(int);//对"void(*)(int)"的函数指针类型重命名为"pfun_t"类型。
//	pfun_t signal(int, pfun_t);
//
//	return 0;
//}

/**
	函数指针数组：本质上是数组，用于存放函数指针，也就是存放函数的地址。
*/

////创建函数指针数组示例
//int Add(int x, int y)
//{
//	return x + y;
//}
//
//int Sub(int x, int y)
//{
//	return x - y;
//}
//
//int main()
//{
//	int (*pAdd)(int, int) = &Add;
//	int (*pSub)(int, int) = &Sub;
//	int (*parr[2])(int, int) = { pAdd,pSub };//将"parr[2]"去掉即是数组存放的元素类型，故此数组存放的是函数指针。
//	return 0;
//}

////计算器
//void Menu()
//{
//	printf("**************************************\n");
//	printf("**********   1.Add  2.Sub   **********\n");
//	printf("**********   3.Mul  4.Div   **********\n");
//	printf("**********      0.Exit      **********\n");
//	printf("**************************************\n");
//}
//
//int Add(int x, int y)
//{
//	return x + y;
//}
//
//int Sub(int x, int y)
//{
//	return x - y;
//}
//
//int Mul(int x, int y)
//{
//	return x * y;
//}
//
//int Div(int x, int y)
//{
//	return x / y;
//}
//
//int main()
//{
//	int input = 0, x = 0, y = 0;
//	do
//	{
//		Menu();
//		printf("Please Enter>>");
//		scanf_s("%d", &input);
//		switch (input)
//		{
//		case 1:
//			printf("请输入两个正整数>>");
//			scanf_s("%d %d", &x, &y);
//			printf("%d\n", Add(x, y));
//			break;
//		case 2:
//			printf("请输入两个正整数>>");
//			scanf_s("%d %d", &x, &y);
//			printf("%d\n", Sub(x, y));
//			break;
//		case 3:
//			printf("请输入两个正整数>>");
//			scanf_s("%d %d", &x, &y);
//			printf("%d\n", Mul(x, y));
//			break;
//		case 4:
//			printf("请输入两个正整数>>");
//			scanf_s("%d %d", &x, &y);
//			printf("%d\n", Div(x, y));
//			break;
//		case 0:
//			printf("Exit!\n");
//			break;
//		default:
//			printf("Input Error,Please Enter Again!\n");
//			break;
//		}
//		if (input)
//		{
//			system("pause");
//			system("cls");
//		}
//	} while (input);
//	return 0;
//}

////计算器(利用函数指针数组实现)
//void Menu()
//{
//	printf("**************************************\n");
//	printf("**********   1.Add  2.Sub   **********\n");
//	printf("**********   3.Mul  4.Div   **********\n");
//	printf("**********      0.Exit      **********\n");
//	printf("**************************************\n");
//}
//
//int Add(int x, int y)
//{
//	return x + y;
//}
//
//int Sub(int x, int y)
//{
//	return x - y;
//}
//
//int Mul(int x, int y)
//{
//	return x * y;
//}
//
//int Div(int x, int y)
//{
//	return x / y;
//}
//
//int main()
//{
//	int input = 0, x = 0, y = 0;
//	int (*arrptr[5])(int, int) = { NULL,Add,Sub,Mul,Div };
//	do
//	{
//		Menu();
//		printf("Please Enter>>");
//		scanf_s("%d", &input);
//		if (input >= 1 && input <= 4)
//		{
//			printf("请输入两个正整数>>");
//			scanf_s("%d %d", &x, &y);
//			printf("%d\n", arrptr[input](x, y));
//			system("pause");
//			system("cls");
//		}
//		else if (input == 0)
//		{
//			printf("Exit!\n");
//		}
//		else
//		{
//			printf("Input Error,Please Enter Again!\n");
//			system("pause");
//			system("cls");
//		}
//	} while (input);
//	return 0;
//}

/**
	函数指针数组指针：即指向函数指针数组的指针。
*/

////指向函数指针数组的指针示例
//void Test(int x, int y)
//{
//	;
//}
//
//int main()
//{
//	void (*p)(int, int) = Test;
//	void (*arrp[1])(int, int) = { p };
//	void(*(*parrp)[1])(int, int) = { &arrp };
//	return 0;
//}

/**
	回调函数：通过函数指针调用的函数。
		1.将一个函数的指针(地址)作为参数传递给另一个函数，当这个函数指针被用来调用其所指向的函数时，我们就说这是回调函数。
		2.回调函数不是由该函数的实现方直接调用，而是在特定的事件或条件发生时由另外一方进行调用，用于对该事件或条件进行响应。
*/

////计算器(利用回调函数实现)
//void Menu()
//{
//	printf("**************************************\n");
//	printf("**********   1.Add  2.Sub   **********\n");
//	printf("**********   3.Mul  4.Div   **********\n");
//	printf("**********      0.Exit      **********\n");
//	printf("**************************************\n");
//}
//
//int Add(int x, int y)
//{
//	return x + y;
//}
//
//int Sub(int x, int y)
//{
//	return x - y;
//}
//
//int Mul(int x, int y)
//{
//	return x * y;
//}
//
//int Div(int x, int y)
//{
//	return x / y;
//}
//
//int Calc(int(*ptr)(int, int))
//{
//	int x = 0, y = 0;
//	printf("请输入两个正整数>>");
//	scanf_s("%d %d", &x, &y);
//	return ptr(x, y);
//}
//
//int main()
//{
//	int input = 0;
//	do
//	{
//		Menu();
//		printf("Please Enter>>");
//		scanf_s("%d", &input);
//		switch (input)
//		{
//		case 1:
//			printf("%d\n", Calc(Add));
//			break;
//		case 2:
//			printf("%d\n", Calc(Sub));
//			break;
//		case 3:
//			printf("%d\n", Calc(Mul));
//			break;
//		case 4:
//			printf("%d\n", Calc(Div));
//			break;
//		case 0:
//			printf("Exit!");
//			break;
//		default:
//			printf("Input Error,Please Enter Again!\n");
//			break;
//		}
//		if (input) 
//		{
//			system("pause");
//			system("cls");
//		}
//	} while (input);
//	return 0;
//}

////使用冒泡排序，将整型数组排列为升序。
//void Bubble_Sort(int arr[], int size)
//{
//	for (int i = 0; i < size - 1; i++)
//	{
//		for (int j = 0; j < size - 1 - i; j++)
//		{
//			if (arr[j] > arr[j + 1])
//			{
//				int tmp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = tmp;
//			}
//		}
//	}
//}
//
//void Print(int arr[], int size)
//{
//	for (int i = 0; i < size; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//}
//
//int main()
//{
//	int arr[10] = { 9,8,7,6,5,4,3,2,1,0 };
//	int size = sizeof(arr) / sizeof(arr[0]);
//	Print(arr, size);
//	Bubble_Sort(arr,size);
//	Print(arr, size);
//	return 0;
//}

/***
	"qsort"函数：使用快速排序算法，对数组内的元素进行排序。
		1.头文件："stdlib.h"。
		2.函数声明：void qsort(void* base, size_t num, size_t size, int (*compar)(const void*,const void*));。
			a.函数头"void"表示此函数无返回值。
			b.函数参数"void* base"：无类型指针，可接收任意类型的指针变量，类似垃圾桶；在此函数中表示指向要排序的数组的第一个对象的指针，并转换为"void*"类型。
			c.函数参数"size_t num"：无符号整数类型；在此函数中表示数组中由"base"指向的元素个数。
			d.函数参数"size_t size"：无符号整数类型；在此函数中表示数组中每个元素的大小(以字节为单位)。
			e.函数参数"int (*compar)(const void*,const void*)"：整型函数指针；此函数指针用于指向比较两个元素的函数，这个函数被"qsort"调用，故为回调函数。
		3."qsort"函数参数中"compar"函数指针指向的函数声明：int compar(const void* p1, const void* p2);。
			a.函数头"int"表示此函数返回值类型为整型。
			b.函数参数"const void* p1"&"const void* p2"：将两个指针作为参数，并转换为由"const"修饰的"void*"类型(const void*)。
		4."compar"函数指针指向的函数的返回值设计：该函数通过返回(以稳定和传递的方式)定义元素的顺序。(函数参数变量名声明见上)
			a.若返回值"<0"，则表明"p1"指向的元素在"p2"指向的元素之前。
			d.若返回值"=0"，则表明"p1"指向的元素等价于"p2"指向的元素。
			c.若返回值">0"，则表明"p1"指向的元素在"p2"指向的元素之后。
*/

////使用"qsort"函数，将整型数组排列为升序。
//void Print(int arr[], int size)
//{
//	for (int i = 0; i < size; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//}
//
//int Compar_Int(const void* p1, const void* p2)
//{
//	return *(int*)p1 - *(int*)p2;
//}
//
//int main()
//{
//	int arr[10] = { 9,8,7,6,5,4,3,2,1,0 };
//	int size = sizeof(arr) / sizeof(arr[0]);
//	Print(arr, size);
//	qsort(arr, size, sizeof(arr[0]), Compar_Int);
//	Print(arr, size);
//	return 0;
//}

////使用"qsort"函数，将结构体数据进行排序。(调试观察)
//struct Student
//{
//	char name[20];
//	int age;
//};
//
//int Compar_Name(const void* p1, const void* p2)
//{
//	return strcmp(((struct Student*)p1)->name, ((struct Student*)p2)->name);
//}
//
//int Compar_Age(const void* p1, const void* p2)
//{
//	return ((struct Student*)p1)->age - ((struct Student*)p2)->age;
//}
//
//int main()
//{
//	struct Student arr[6] = { {"A",19},{"X",21},{"B",20},{"Y",19},{"C",18},{"Z",20} };
//	int size = sizeof(arr) / sizeof(arr[0]);
//	qsort(arr, size, sizeof(arr[0]), Compar_Name);//按照名字进行排序。
//	qsort(arr, size, sizeof(arr[0]), Compar_Age);//按照年龄进行排序。
//	return 0;
//}

////模仿"qsort"函数改造冒泡排序，并实现将整型数组排列为升序。
//void Print(int arr[], int size)
//{
//	for (int i = 0; i < size; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//}
//
//void Swap(char* p1, char* p2, size_t size)
//{
//	for (size_t i = 0; i < size; i++)
//	{
//		char tmp = *p1;
//		*p1 = *p2;
//		*p2 = tmp;
//		p1++, p2++;
//	}
//}
//
//int Compar_Int(const void* p1, const void* p2)
//{
//	return *(int*)p1 - *(int*)p2;
//}
//
//void Bubble_Sort(void* base, size_t num, size_t size, int (*compar)(const void*, const void*))
//{
//	if (num <= 0)
//		return;
//	for (size_t i = 0; i < num - 1; i++)
//	{
//		for (size_t j = 0; j < num - 1 - i; j++)
//		{
//			if (compar((char*)base + j * size, (char*)base + (j + 1) * size) > 0)
//			{
//				Swap((char*)base + j * size, (char*)base + (j + 1) * size, size);
//			}
//		}
//	}
//}
//
//void Int_Arr_Sort()
//{
//	int arr[10] = { 9,8,7,6,5,4,3,2,1,0 };
//	int size = sizeof(arr) / sizeof(arr[0]);
//	Print(arr, size);
//	Bubble_Sort(arr, size, sizeof(arr[0]), Compar_Int);
//	Print(arr, size);
//}
//
//int main()
//{
//	Int_Arr_Sort();
//	return 0;
//}

////模仿"qsort"函数改造冒泡排序，并实现将结构体数据进行排序。(调试观察)
//struct Student
//{
//	char name[20];
//	int age;
//};
//
//void Swap(char* p1, char* p2, size_t size)
//{
//	for (size_t i = 0; i < size; i++)
//	{
//		char tmp = *p1;
//		*p1 = *p2;
//		*p2 = tmp;
//		p1++, p2++;
//	}
//}
//
//int Compar_Name(const void* p1, const void* p2)
//{
//	return strcmp(((struct Student*)p1)->name, ((struct Student*)p2)->name);
//}
//
//int Compar_Age(const void* p1, const void* p2)
//{
//	return ((struct Student*)p1)->age - ((struct Student*)p2)->age;
//}
//
//void Bubble_Sort(void* base, size_t num, size_t size, int (*compar)(const void*, const void*))
//{
//	if (num <= 0)
//		return;
//	for (size_t i = 0; i < num - 1; i++)
//	{
//		for (size_t j = 0; j < num - 1 - i; j++)
//		{
//			if (compar((char*)base + j * size, (char*)base + (j + 1) * size) > 0)
//			{
//				Swap((char*)base + j * size, (char*)base + (j + 1) * size, size);
//			}
//		}
//	}
//}
//
//void Structure_Name_Sort(struct Student arr[],int size)
//{
//	Bubble_Sort(arr, size, sizeof(arr[0]), Compar_Name);
//}
//
//void Structure_Age_Sort(struct Student arr[],int size)
//{
//	Bubble_Sort(arr, size, sizeof(arr[0]), Compar_Age);
//}
//
//int main()
//{
//	struct Student arr[] = { {"Acb",19},{"Xxx",21},{"Bbb",20},{"Yyy",19},{"Ccc",18},{"Zzz",20},{"Abc",22} };
//	int size = sizeof(arr) / sizeof(arr[0]);
//	Structure_Name_Sort(arr, size);
//	Structure_Age_Sort(arr, size);
//	return 0;
//}

/**
	指针与数组相关习题：所有习题在"VS2022"及"x86"环境下运行，存储模式为小端存储模式。
		1.使用"sizeof"计算数组大小中的数组名表示的是整个数组，计算的是数组中所有元素的大小总和，单位是字节。
		2.使用"&"操作符取出数组名的地址，取出的是整个数组的地址，此时数组名表示为整个数组，取出的地址指向的位置依然是数组的首元素，其自增操作代表的是越过整个数组。
		3.当数组名表示为整个数组的情况时，其地址依旧是首元素的地址，但是类型与数组名表示为首元素的地址的情况并不相同。
*/

////指针与数组相关习题例一：计算出以下所有的输出结果，答案中指针类型大小表示为"4/8"、随机值表示为"随机值"、可能导致程序出错的代码表示为"错误"并注释屏蔽。
//int main()
//{
//	////整型数组
//	//int a[] = { 1,2,3,4 };
//	//printf("%zu\n", sizeof(a));//16。
//	//printf("%zu\n", sizeof(a + 0));//4/8。
//	//printf("%zu\n", sizeof(*a));//4。
//	//printf("%zu\n", sizeof(a + 1));//4/8。
//	//printf("%zu\n", sizeof(a[1]));//4。
//	//printf("%zu\n", sizeof(&a));//4/8。
//	//printf("%zu\n", sizeof(*&a));//16。
//	//printf("%zu\n", sizeof(&a + 1));//4/8。
//	//printf("%zu\n", sizeof(&a[0]));//4/8。
//	//printf("%zu\n", sizeof(&a[0] + 1));//4/8。
//	//printf("\n");
//	
//	////字符数组一
//	//char arr1[] = { 'a','b','c','d','e','f' };
//	//printf("%zu\n", sizeof(arr1));//6。
//	//printf("%zu\n", sizeof(arr1 + 0));//4/8。
//	//printf("%zu\n", sizeof(*arr1));//1。
//	//printf("%zu\n", sizeof(arr1[1]));//1。
//	//printf("%zu\n", sizeof(&arr1));//4/8。
//	//printf("%zu\n", sizeof(&arr1 + 1));//4/8。
//	//printf("%zu\n", sizeof(&arr1[0] + 1));//4/8。
//	//printf("%zu\n", strlen(arr1));//随机值。
//	//printf("%zu\n", strlen(arr1 + 0));//随机值。
//	////printf("%zu\n", strlen(*arr1));//错误。
//	////printf("%zu\n", strlen(arr1[1]));//错误。
//	//printf("%zu\n", strlen(&arr1));//随机值。
//	//printf("%zu\n", strlen(&arr1 + 1));//随机值-6。
//	//printf("%zu\n", strlen(&arr1[0] + 1));//随机值-1。
//	//printf("\n");
//
//	////字符数组二
//	//char arr2[] = "abcdef";
//	//printf("%zu\n", sizeof(arr2));//7。
//	//printf("%zu\n", sizeof(arr2 + 0));//4/8。
//	//printf("%zu\n", sizeof(*arr2));//1。
//	//printf("%zu\n", sizeof(arr2[1]));//1。
//	//printf("%zu\n", sizeof(&arr2));//4/8。
//	//printf("%zu\n", sizeof(&arr2 + 1));//4/8。
//	//printf("%zu\n", sizeof(&arr2[0] + 1));//4/8。
//	//printf("%zu\n", strlen(arr2));//6。
//	//printf("%zu\n", strlen(arr2 + 0));//6。
//	////printf("%zu\n", strlen(*arr2));//错误。
//	////printf("%zu\n", strlen(arr2[1]));//错误。
//	//printf("%zu\n", strlen(&arr2));//6。
//	//printf("%zu\n", strlen(&arr2 + 1));//随机值。
//	//printf("%zu\n", strlen(&arr2[0] + 1));//5。
//	//printf("\n");
//	
//	////字符指针
//	//char* p = "abcdef";
//	//printf("%zu\n", sizeof(p));//4/8。
//	//printf("%zu\n", sizeof(p + 1));//4/8。
//	//printf("%zu\n", sizeof(*p));//1。
//	//printf("%zu\n", sizeof(p[0]));//1。
//	//printf("%zu\n", sizeof(&p));//4/8。
//	//printf("%zu\n", sizeof(&p + 1));//4/8。
//	//printf("%zu\n", sizeof(&p[0] + 1));//4/8。
//	//printf("%zu\n", strlen(p));//6。
//	//printf("%zu\n", strlen(p + 1));//5。
//	////printf("%zu\n", strlen(*p));//错误。
//	////printf("%zu\n", strlen(p[0]));//错误。
//	//printf("%zu\n", strlen(&p));//随机值。
//	//printf("%zu\n", strlen(&p + 1));//随机值。
//	//printf("%zu\n", strlen(&p[0] + 1));//5。
//	//printf("\n");
//
//	////二维数组
//	//int a[3][4] = { 0 };
//	//printf("%zu\n", sizeof(a));//48。
//	//printf("%zu\n", sizeof(a[0][0]));//4。
//	//printf("%zu\n", sizeof(a[0]));//16。
//	//printf("%zu\n", sizeof(a[0] + 1));//4/8。
//	//printf("%zu\n", sizeof(*(a[0] + 1)));//4。
//	//printf("%zu\n", sizeof(a + 1));//4/8。
//	//printf("%zu\n", sizeof(*(a + 1)));//16。
//	//printf("%zu\n", sizeof(&a[0] + 1));//4/8。
//	//printf("%zu\n", sizeof(*(&a[0] + 1)));//16。
//	//printf("%zu\n", sizeof(*a));//16。
//	//printf("%zu\n", sizeof(a[3]));//16。
//	//printf("\n");
//}

////指针与数组相关习题例二：程序输出的结果是什么？
//int main()
//{
//	int a[5] = { 1, 2, 3, 4, 5 };
//	int* ptr = (int*)(&a + 1);
//	printf("%d\n", *(a + 1));//2。
//	printf("%d\n", *(ptr - 1));//5。
//	return 0;
//}

////指针笔试题例三：已知结构体"Test"类型的变量大小是20个字节，假设"p"的值为"0x00100000"，程序输出的结果是什么？
//struct Test
//{
//	int Num;
//	char* pcName;
//	short sDate;
//	char cha[2];
//	short sBa[4];
//}*p = (struct Test*)0x00100000;
//
//int main()
//{
//	printf("0x%p\n", p + 0x1);//0x00100014。
//	printf("0x%p\n", (struct Test*)((unsigned long)p + 0x1));//0x00100001。
//	printf("0x%p\n", (unsigned int*)p + 0x1);//0x00100004。
//	return 0;
//}

////指针笔试题例四：程序输出的结果是什么？
//int main()
//{
//	int a[4] = { 1, 2, 3, 4 };
//	int* ptr1 = (int*)(&a + 1);
//	int* ptr2 = (int*)((int)a + 1);
//	printf("%#x,%#x", ptr1[-1], *ptr2);//"%#x"："%x"意为以十六进制的形式进行打印，"#"意为添加上"0x"；0x4,0x2000000。
//	return 0;
//}

////指针笔试题例五：程序输出的结果是什么？
//int main()
//{
//	int a[3][2] = { (0, 1), (2, 3), (4, 5) };
//	int* p = a[0];
//	printf("%d", p[0]);//1。
//	return 0;
//}

////指针笔试题例六：程序输出的结果是什么？
//int main()
//{
//	int a[5][5];
//	int(*p)[4] = (int(*)[4])a;
//	printf("%p,%d\n", (void*)(&p[4][2] - &a[4][2]), &p[4][2] - &a[4][2]); //FFFFFFFC,-4。
//	return 0;
//}

////指针笔试题例七：程序输出的结果是什么？
//int main()
//{
//	int a[2][5] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	int* ptr1 = (int*)(&a + 1);
//	int* ptr2 = (int*)(*(a + 1));
//	printf("%d,%d", *(ptr1 - 1), *(ptr2 - 1));//10,5。
//	return 0;
//}

////指针笔试题例八：程序输出的结果是什么？
//int main()
//{
//	char* a[] = { "work","at","alibaba"};
//	char** pa = a;
//	pa++;
//	printf("%s\n", *pa);//at。
//	return 0;
//}

////指针笔试题例九：程序输出的结果是什么？
//int main()
//{
//	char* c[] = { "ENTER","NEW","POINT","FIRST" };
//	char** cp[] = { c + 3,c + 2,c + 1,c };
//	char*** cpp = cp;
//	printf("%s\n", **++cpp);//POINT。
//	printf("%s\n", *-- * ++cpp + 3);//ER。
//	printf("%s\n", *cpp[-2] + 3);//ST。
//	printf("%s\n", cpp[-1][-1] + 1);//EW。
//	return 0;
//}