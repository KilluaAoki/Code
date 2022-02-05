#include <stdio.h>

/*
	1.算术操作符：+（加）、-（减）、*（乘）、/（除）、%（取模）。
	2.移位操作符：<<（左移）、>>（右移）。
	3.位操作符：&（按位与）、|（按位或）、^（按位异或）。
	4.赋值操作符：=。
		a.复合赋值符：+=、-=、*=、/=、%=、<<=、>>=、&=、|=、^=。
	5.单目操作符
		a.逻辑反操作：!。
		b.正负值：+、-。
		c.取地址：&。
		d.计算类型或者变量所占空间的大小：sizeof（单位为字节byte）。
		e.对一个数的二进制进行按位取反：~。
		f.前后置自增自减操作符：前置++、后置++、前置--、后置--。
		g.间接访问操作符(解引用操作符)：*。
		h.强制类型转换：(类型)。
	6.关系操作符：>、>=、<、<=、!=、==。
	7.逻辑操作符：&&（逻辑与）、||（逻辑或）。
	8.条件操作符：exp1?exp2:exp3。（三目操作符）
	9.逗号表达式：exp1,exp2,exp3,…expN。
	10.下标引用、函数调用和结构成员
		a.下标引用操作符：[]。
		b.函数调用操作符：()。
		c.访问结构成员
			1.结构体.成员名：.。
			2.结构体指针->成员名：->。
*/

////算术操作符：+（加）、-（减）、*（乘）、/（除）、%（取模）。
////	1.除了“%”操作符之外，其他的几个操作符都可以作用于整数以及浮点数。
////	2.对于“/”操作符来说，如果两个操作数都为整数，则执行整数除法；而只要有浮点数执行的就是浮点数除法。
////	3.“%”操作符的两个操作数必须为整数；返回的是整除之后的余数。
//int main()
//{
//	////“/”除
//	//int a = 0;
//	//a = 5 / 2;
//	//printf("当两个操作数都是整数，并且类型为int时：5/2=%d。\n", a);
//	//double b = 0;
//	//b = 5 / 2;
//	//printf("当两个操作数都是整数，并且类型为double时：5/2=%f。\n", b);
//	//double c = 0;
//	//c = 5.0 / 2;
//	//printf("当两个操作数有浮点数，并且类型为double时：5.0/2=%f。\n", c);
//
//	////“%”取模
//	//int a = 0;
//	//a = 5 % 2;//两个操作数必须为整数，否则错误。
//	//printf("%d\n", a);
//
//	return 0;
//}

////移位操作符：<<（左移）、>>（右移）。
////	1.移位操作符的操作数只能是整数。
////	2.移动的是二进制位。
////	3.对于移位运算符，不要移动负数位，这个是标准未定义的。
//int main()
//{
//	////“<<”左移：左边抛弃、右边补0。
//	//int a = 1;
//	//int b = a << 1;//把”a“的值（二进制），向左移动一位，放到“b”中（不改变“a”原本的值）。
//	////00000000000000000000000000000001（左移前）
//	////00000000000000000000000000000010（左移后）
//	//printf("a=%d\nb=%d\n", a, b);
//	
//	//“>>”右移：分为逻辑移位和算术移位。
//	//	1.逻辑移位：左边用0填充，右边丢弃。
//	//	2.算术移位：左边用原该值的符号位填充，右边丢弃。
//	int a = 10;
//	int b = a >> 1;
//	//00000000000000000000000000001010（左移前）
//	//00000000000000000000000000000101（左移后）
//	printf("a=%d\nb=%d\n", a, b);
//
//	//原反补：存放在内存中的值是补码（二进制）。
//	//	1.正数：原码反码补码相同。
//	//	2.负数：原码最高位为符号位（用1来表示负）；反码为原码按位取反后的值（符号位不变）；补码为反码+1。
//	int c = -1;
//	//原码：10000000000000000000000000000001。
//	//反码：11111111111111111111111111111110。
//	//补码：11111111111111111111111111111111。（内存中存放的-1）
//	int d = c >> 1;
//	//探究当前IDE是逻辑移位还是算术移位：若为逻辑移位，则左边用0填充，右边丢弃；若为算术移位，左边用原该值的符号位填充，右边丢弃。
//	printf("c=%d\nd=%d\n", c, d);//得知“d”为-1，故使用的是算术移位。
//
//	return 0;
//}

////位操作符：&（按位与）、|（按位或）、^（按位异或）。
////	1.“&”（按位与）：对应的二进制位进行按位与，两边都为真则为真，否则为假。
////	2.“|”（按位或）：对应的二进制位进行按位或，两边只要有一边为真则为真，否则为假。
////	3.“^”（按位异或）：对应的二进制位进行按位异或，相同为0，相异为1。
//int main()
//{
//	int a = 0;
//	
//	//“&”（按位与）
//	a = 6 & 10;
//	printf("6&10=%d\n", a);
//
//	//“|”（按位或）
//	a = 6 | 10;
//	printf("6|10=%d\n", a);
//
//	//“^”（按位异或）
//	a = 6 ^ 10;
//	printf("6^10=%d\n", a);
//
//	return 0;
//}

////使用按位异或的方法，不创建临时变量，实现两个数的交换。
//int main()
//{
//	int a = 3, b = 5;
//	printf("交换前：a=%d，b=%d。\n", a, b);
//	a = a ^ b;
//	//a=00000000000000000000000000000011（3的二进制）
//	//b=00000000000000000000000000000101（5的二进制）
//	//a=00000000000000000000000000000110（6的二进制）
//	b = a ^ b;
//	//a=00000000000000000000000000000110（6的二进制）
//	//b=00000000000000000000000000000101（5的二进制）
//	//b=00000000000000000000000000000011（3的二进制）
//	a = a ^ b;
//	//a=00000000000000000000000000000110（6的二进制）
//	//b=00000000000000000000000000000011（3的二进制）
//	//a=00000000000000000000000000000101（5的二进制）
//	printf("交换后：a=%d，b=%d。\n", a, b);
//	//x^y=z,x^z=y,y^z=x
//	return 0;
//}

////求一个整数存储在内存中的二进制中1的个数
//int main()
//{
//	int num = -1, count = 0;
//	//原码：10000000000000000000000000000001。
//	//反码：11111111111111111111111111111110。
//	//补码：11111111111111111111111111111111。
//	for (int i = 0; i < 32; i++)
//	{
//		if (num & 1)
//		{
//			count++;
//			num >> 1;
//		}
//	}
//	printf("count=%d\n", count);
//	return 0;
//}

////把二进制中的某个位置置成1并还原成0，如13的第五位置成1并还原成0。
//int main()
//{
//	int a = 13;//a=00000000000000000000000000001101。
//	a = a | (1 << 4);//将第五位置成1。
//	a = a & ~(1 << 4);//将第五位置成0。
//	printf("a=%d\n", a);
//	return 0;
//}

////赋值操作符：=（等于）。
////	1.可以连续赋值，但不推荐。
////	2.可以复合赋值，使代码更简洁。
////	3.注意区分单个“=”和两个“==”，前者意为赋值，后者意为判断。
//int main()
//{
//	int a = 0, b = 0, c = 0;
//	a = b = 100;//连续赋值：将100赋值于“b”，再将“b”赋值于“a”。
//	a += b;//复合赋值：等同于“a=a+b”。
//	return 0;
//}

////单目操作符：只有一个操作数的操作符。
////	a.逻辑反操作：!。
////	b.正负值：+、-。
////	c.取地址：&。
////	d.计算类型或者变量所占空间的大小：sizeof（单位为字节byte）。
////	e.对一个数的二进制进行按位取反：~。
////	f.前后置自增自减操作符：前置++、后置++、前置--、后置--。
////	g.间接访问操作符(解引用操作符)：*。
////	h.强制类型转换：(类型)。
//int main()
//{
//	////a.逻辑反操作：!。
//	//int flag = 0;
//	//printf("%d\n", !flag);//本身为假，进行逻辑反操作后变为真，故打印出1。
//	
//	////b.正负值：+、-。
//	//int a = 10;//即“int a = +10;”其中“+”被隐藏。
//	//a = -a;//令“a”为“-”。
//	//printf("%d\n", -a);//打印出10，因为负负得正。
//
//	////c.取地址：&。（见g.）
//
//	////d.计算类型或者变量所占空间的大小：sizeof（单位为字节byte）。
//	////	1.“sizeof”括号中的表达式是不参与运算的。
//	////	2.计算字符串所占空间的大小时，隐藏的“\0”同样会被计算。
//	////	3.“sizeof”是操作数，不是函数。
//	////	4.当“sizeof”计算数组传参后的类型或变量，其实计算的是指针变量的大小，在32位平台结果为4，在64位平台结果为8。
//	//int a = 10;
//	//printf("%zd\n", sizeof(a));//计算整形变量”a“所占空间的大小；其中”a“两边的括号可以删去，证明sizeof不是函数。
//	//printf("%zd\n", sizeof(int));//计算整型的大小；其中“int”两边的括号不能删去。
//	//int arr[10] = { 0 };
//	//printf("%zd\n", sizeof(arr));//计算数组“arr”所占空间的大小。
//	//printf("%zd\n", sizeof(int [10]));//“int [10]”是arr数组的类型。
//	//short b = 5;
//	//int c = 10;
//	//printf("%zd\n", sizeof(b = c + 2));//计算的是短整型的大小。
//	//printf("%d\n", b);//结果为5，证明“sizeof”括号中的表达式是不参与运算的。
//
//	////e.对一个数的二进制进行按位取反：~。
//	//int a = -1;
//	////原码：10000000000000000000000000000001。
//	////反码：11111111111111111111111111111110。
//	////补码：11111111111111111111111111111111。
//	//int b = ~a;
//	////11111111111111111111111111111111
//	////00000000000000000000000000000000
//	//printf("%d\n", a);
//	//printf("%d\n", b);
//
//	////f.前后置自增自减操作符：前置++、后置++、前置--、后置--。
//	//int a = 0;
//	//printf("%d\n", a++);//先使用，再自增。
//	//printf("%d\n", ++a);//先自增，再使用。
//	//printf("%d\n", a--);//先使用，再自减。
//	//printf("%d\n", --a);//先自减，再使用。
//
//	////g.间接访问操作符(解引用操作符)：*。
//	//int a = 10;
//	//printf("%p\n", &a);//”&“：取地址操作符。
//	//int * pa = &a;//”pa“：指针变量；作用为存放地址。
//	//*pa = 20;//”*“：间接访问操作符(解引用操作符)。
//	//printf("%d\n", a);
//
//	////h.强制类型转换：(类型)。
//	//int a = (int)3.14;
//
//	return 0;
//}

//关系操作符：>、>=、<、<=、!=、==。
//	1.注意区分单个“=”和两个“==”，前者意为赋值，后者意为判断。
//	2.“!=”：用于测试不相等；“==”：用于测试相等。
//	3.比较2个字符串相等，不能使用“==”。 

////逻辑操作符：&&（逻辑与）、||（逻辑或）。
////	1.需要与位操作符区分开。
////	2.当“&&”从左到右遍历代码，一旦为假，边不会再向右执行。
////	2.当“||”从左到右遍历代码，一旦为真，边不会再向右执行。
//int main()
//{
//	int a = 0, b = 0, c = 0, d = 0;
//	
//	a = 0, b = 2, c = 3, d = 4;
//	a++ && ++b && d++;
//	printf("a=%d b=%d c=%d d=%d\n", a, b, c, d);
//	
//	a = 0, b = 2, c = 3, d = 4;
//	a++ || ++b || d++;
//	printf("a=%d b=%d c=%d d=%d\n", a, b, c, d);
//	
//	return 0;
//}

////条件操作符：exp1?exp2:exp3。
//int main()
//{
//	int a = 0;
//	printf("%d\n", a != 0 ? 1 : 2);//如果“a”不等于0，则输出1，否则输出2。
//	return 0;
//}

////逗号表达式：exp1,exp2,exp3,…expN。
////	1.用逗号隔开的多个表达式。
////	2.要从左向右依次计算，但是整个表达式的结果是最后一个表达式的结果。
//int main()
//{
//	////示例1
//	//int a = 1, b = 2;
//	//int c = (a > b, a = b + 10, a, b = a + 1);
//	//printf("%d\n", c);
//
//	////示例2
//	//int a = 0, b = 0, c = 0, d = 0;
//	//if (a = b + 1, c = a / 2, d > 0)
//	//{
//	//	printf("Aoki\n");
//	//}
//	//else
//	//{
//	//	printf("Killua\n");
//	//}
//
//	return 0;
//}

////下标引用、函数调用和结构成员。
////	a.下标引用操作符：[]。
////	b.函数调用操作符：()。
////	c.访问结构成员
////		1.结构体.成员名：.。
////		2.结构体指针->成员名：->。
//struct Book
//{
//	char name[20];
//	int price;
//};
//int main()
//{
//	////a.下标引用操作符：[]。
//	//int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };//这里的“[]”是创建数组的语法格式，和下标引用操作符无关。
//	//printf("%d\n", arr[4]);//“[]”的操作数共有两个：“arr”和“4”。
//
//	////b.函数调用操作符：()。
//	//int a = 10, b = 20;
//	//printf("%d\n", a + b);//这里的“()”就是函数调用操作符。
//
//	////访问结构体成员
//	////	1.结构体.成员名：.。
//	////	2.结构体指针->成员名：->。
//	//struct Book a = {"C", 55};
//	//struct Book * pa = &a;
//	//printf("书名：%s\n", a.name);
//	//printf("定价：%d\n", a.price);
//	//printf("书名：%s\n", pa->name);
//	//printf("定价：%d\n", pa->price);
//	//printf("书名：%s\n", (*pa).name);
//	//printf("定价：%d\n", (*pa).price);
//
//	return 0;
//}