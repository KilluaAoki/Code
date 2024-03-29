#include <stdio.h>
#include <string.h>
#include <limits.h>

/*
	数据的存储
		1.数据类型的归类
		2.整型类型在内存中的存储
		3.浮点类型在内存中的存储
*/

/**
	数据类型的归类
		1.整型类型："char"字符数据类型、"short"短整型、"int"整型、"long"长整型、"long long"更长的整型(与C99标准添加)。
			a."char"字符数据类型：此类型是专为存储字符而设计的，C语言通过使用字母的数值编码存储字符("ASCII"编码)，故"char"类型也是另一种整型，所以也可以用"char"类型表示比"short"类型更小的整型。
			b.每一个整型类型都可以分为无符号的类型"unsigned"以及有符号的类型"signed"，除了"char"字符类型，默认情况下整型变量都为有符号的类型，若需声明无符号的类型的话则要在类型前加上"unsigned"，即显式地将类型设置为无符号类型。
			c.有符号类型是因为需要表示数值的正负而出现的，即把最高位用作符号位用来表示数值的正负，而生活中有一些数值并没有负数，这就出现了无符号类型，故最高位就能用来表示数值，以此扩大数值范围。
			d.因"char"类型常用来表示字符，故在默认情况下既不是有符号也不是无符号，是否有符号是由编译器决定的，若要将"char"类型用来表示数值，则就要额外注意有符号和无符号给"char"类型所带来的差异，并且显示地将类型设置为无符号类型或有符号类型。
			e.C语言中常量的类型是根据数值的后缀和数值的范围确定的，除非有理由将数值表示为其他类型(使用特定的后缀表示特定类型以及数值超过"int"类型的范围)，否则默认都为"int"类型。
			f.实际上，除了"char"类型以及"int"类型外，其余整型类型都是"int"类型的简写，即"short"是"short int"的简写、"long"是"long int"的简写、"long long"是"long long int"的简写。
			g.不同环境下部分类型的大小不一定相同，编译器可能使用不同的数据位宽，导致不同环境下部分类型的取值范围不相同，需自行测试。
		2.浮点类型："float"单精度浮点类型、"double"双精度浮点类型、"long double"多精度浮点类型(于C90标准添加)。
		3.构造类型(自定义类型)：数组类型、"struct"结构类型、"enum"枚举类型、"union"联合类型。
		4.指针类型：可以从函数类型、变量类型或一个不完备类型中导出指针的数据类型，从中导出的数据类型被称之为被引用类型。
		5.空类型：即"void"类型，通常应用于函数的返回值类型、函数的参数、指针类型。
			a.若应用于函数的返回值类型，表示这个函数不返回值，但并不意味着这个函数永不返回或不能返回值，只是表示该函数的返回值没有意义，调用方应当无视。
			b.函数的参数括号中的"void"，代表着该函数没有参数。
			c.在指针类型位置的"void"表示这个指针可以指向任何类型的数据(函数除外)。
		6.C99标准中添加了复数类型、虚数类型以及布尔类型，并且在C11标准中添加了原子类型。
*/

////计算数据类型的大小示例
//int main()
//{
//	printf("char\t\t存储大小:%zu byte\n", sizeof(char));
//	printf("short\t\t存储大小:%zu byte\n", sizeof(short));
//	printf("int\t\t存储大小:%zu byte\n", sizeof(int));
//	printf("long\t\t存储大小:%zu byte\n", sizeof(long));
//	printf("long long\t存储大小:%zu byte\n", sizeof(long long));
//	printf("float\t\t存储大小:%zu byte\n", sizeof(float));
//	printf("double\t\t存储大小:%zu byte\n", sizeof(double));
//	printf("long double\t存储大小:%zu byte\n", sizeof(long double));
//	return 0;
//}

/**
	整型类型在内存中的存储：计算机中所有信息都是以二进制的形式存储在电脑内部的，而整数在内存中是以二进制补码的形式进行存储的。
		1.整数的二进制表示方式：原码、反码、补码。
			a.正整数：原码、反码、补码皆相同。
			b.负整数：原码即一个数值原本的二进制(最高位为"1"表示负数，即符号位)、反码是由原码的符号位不变其他位按位取反得来的、补码是在反码的基础上再加"1"得来的。
			c.原码补码相互转换：符号位不变其他位按位取反再加"1"。
		2.大端存储模式和小端存储模式：计算机的一个内存单元的大小是一个字节，C语言中存在着超过一个字节(多字节)的数据类型，并且对于位数大于"8"位的计算机，寄存器的宽度大于一个字节，所以就存在了数据在计算机内存中存储各字节的存储顺序问题。
			a.把数据的低位字节序(以字节为单位在电脑中存放时的序列)的内容存放在高地址处，高位字节序的内容存放在低地址处，为大端存储模式。
			b.把数据的低位字节序(以字节为单位在电脑中存放时的序列)的内容存放在低地址处，高位字节序的内容存放在高地址处，为小端存储模式。
		3.整型类型的取值范围
			a.通过"sizeof"关键字计算出各个数据类型在当前环境中大小，通过确定其是否为有符号数据类型或无符号数据类型，从而计算出各个数据类型的取值范围。
			b.在C语言的头文件"limits.h"中，通过"#define"预处理指令定义了各个整型数据类型的数值极限为符号常量，编译器厂商通过提供此头文件指出了其编译器中的各个整型数据类型中的最大取值与最小取值、各个整型数据类型的位宽等。
*/

////整型在内存中的存储示例一：调试观察数值在内存中的存储。
//int main()
//{
//	int a = -10;//调试观察变量"a"在内存中的存储，发现内存中的值为：f6ffffff(注意此处是十六进制的表示形式，并不代表计算机是以十六进制的形式存储的)，当前环境下为小端存储模式，实际上内存中的值大端存储模式下的"fffffff6"，即"-10"的十六进制。
//	//"-10"的原码：10000000000000000000000000001010。
//	//"-10"的反码：11111111111111111111111111110101。
//	//"-10"的补码：11111111111111111111111111110110。
//	
//	printf("%x\n", a);
//
//	int b = (+1) - 1;//处理器中只有加法器，减法是通过加法器进行运算的，故"(+1) - 1"实际上为"(+1) + (-1)"。
//	//"+1"的补码：00000000000000000000000000000001。
//	//"-1"的原码：10000000000000000000000000000001。
//	//"-1"的反码：11111111111111111111111111111110。
//	//"-1"的补码：11111111111111111111111111111111。
//	//"1"的补码与"-1"的补码相加结果为：(1)00000000000000000000000000000000，相加后进位值第"33"位(由最低位向最高位数)，此环境下"int"类型为"32"位，故最高位"1"被截断后存放进变量"b"中。
//	
//	printf("%d\n", b);
//
//	return 0;
//}

////整型在内存中的存储示例二：两种方法判断当前的存储模式是大端存储模式还是小端存储模式。
//int CheckSystem()
//{
//	int a = 1;
//	return (*(char*)&a);
//}
//
//int main()
//{
//	////方法一：通过调试，观察是大端存储模式还是小端存储模式。
//	//int num = 0x700f0001;//调试观察变量"num"在内存中的存储，发现内存中的值为：01000f70，为小端存储模式。
//
//	////方法二：通过指针识别地址，判断是大端存储模式还是小端存储模式。
//	//if (CheckSystem())
//	//	printf("小端存储模式\n");
//	//else
//	//	printf("大端存储模式\n");
//
//	return 0;
//}

////整型在内存中的存储示例三：通过"limits.h"头文件，输出各个整型数据类型的信息。
//int main()
//{
//	printf("CHAR_BIT       = %d\n", CHAR_BIT);
//	printf("CHAR_MIN       = %+d\n", CHAR_MIN);
//	printf("CHAR_MAX       = %+d\n", CHAR_MAX);
//	printf("SCHAR_MIN      = %+d\n", SCHAR_MIN);
//	printf("SCHAR_MAX      = %+d\n", SCHAR_MAX);
//	printf("UCHAR_MAX      = %u\n\n", UCHAR_MAX);
//
//	printf("SHRT_MIN       = %+d\n", SHRT_MIN);
//	printf("SHRT_MAX       = %+d\n", SHRT_MAX);
//	printf("USHRT_MAX      = %u\n\n", USHRT_MAX);
//
//	printf("INT_MIN        = %+d\n", INT_MIN);
//	printf("INT_MAX        = %+d\n", INT_MAX);
//	printf("UINT_MAX       = %u\n\n", UINT_MAX);
//
//	printf("LONG_MIN       = %+ld\n", LONG_MIN);
//	printf("LONG_MAX       = %+ld\n", LONG_MAX);
//	printf("ULONG_MAX      = %lu\n\n", ULONG_MAX);
//
//	printf("LLONG_MIN      = %+lld\n", LLONG_MIN);
//	printf("LLONG_MAX      = %+lld\n", LLONG_MAX);
//	printf("ULLONG_MAX     = %llu\n\n", ULLONG_MAX);
//
//	printf("SIZE_MAX       = %zu\n", SIZE_MAX);
//	
//	return 0;
//}

////整型在内存中的存储例题一
//int main()
//{
//	char a = -1;//将整数"-1"，放入"char"类型的变量"a"中，由编译器决定是有符号的"char"类型还是无符号的"char"类型，此处为有符号的"char"类型。
//	//"-1"的原码：10000000000000000000000000000001。
//	//"-1"的反码：11111111111111111111111111111110。
//	//"-1"的补码：11111111111111111111111111111111。
//	//放入"char"中发生截断：11111111。
//	
//	signed char b = -1;//将整数"-1"，放入有符号的"char"类型的变量"b"中。
//	//"-1"的原码：10000000000000000000000000000001。
//	//"-1"的反码：11111111111111111111111111111110。
//	//"-1"的补码：11111111111111111111111111111111。
//	//放入"char"中发生截断：11111111。
//	
//	unsigned char c = -1;//将整数"-1"，放入无符号的"char"类型的变量"c"中，因其为无符号的"char"类型，故符号位变为数值位。
//	//"-1"的原码：10000000000000000000000000000001。
//	//"-1"的反码：11111111111111111111111111111110。
//	//"-1"的补码：11111111111111111111111111111111。
//	//放入无符号的"char"类型的变量"c"中发生截断：11111111，因其为无符号的"char"类型，故符号位变为数值位，正整数原码、反码、补码相同，故得出结果为：255，同时也是无符号的"char"类型的最大值。
//	
//	printf("a = %d,b = %d,c = %d", a, b, c);//打印的结果为：a = -1,b = -1,c = 255。
//	//"%d"意为要以有符号整型为格式化数据打印，故不满足缺省整型的变量都会进行整型提升再打印。
//	//变量"a"整型提升后的补码：11111111111111111111111111111111(即"-1"的补码)，若以整型为格式化数据打印，则最高位为符号位，结果为"-1"。
//	//变量"b"整型提升后的补码：11111111111111111111111111111111(即"-1"的补码)，若以整型为格式化数据打印，则最高位为符号位，结果为"-1"。
//	//变量"c"整型提升后的补码：00000000000000000000000011111111(无符号数整型提升高位补"0")，若以整型为格式化数据打印，则最高位为符号位，结果为"255"。
//	
//	return 0;
//}

////整型在内存中的存储例题二
//int main()
//{
//	char a = -128;//将整数"-128"，放入"char"类型的变量"a"中。
//	//"-128"的原码：10000000000000000000000010000000。
//	//"-128"的反码：11111111111111111111111101111111。
//	//"-128"的补码：11111111111111111111111110000000。
//	//放入"char"中发生截断：10000000。
//	
//	printf("%u\n", a);//打印的结果为：4294967168。
//	//"%u"意为要以无符号整型为格式化数据打印，故不满足缺省整型的变量都会进行整型提升再打印。
//	//变量"a"整型提升后的补码：11111111111111111111111110000000(即"-128"的补码)，若以无符号整型为格式化数据打印，则最高位为数值位，结果为"4294967168"。
//	
//	return 0;
//}

////整型在内存中的存储例题三
//int main()
//{
//	char a = 128;
//	//"128"的补码：00000000000000000000000010000000。
//	//放入"char"中发生截断：10000000，此时"char"类型为有符号的"char"，故最高位为符号位，数值会被直接解析成"-128"。
//	
//	printf("%u\n", a);//打印的结果为：4294967168。
//	//此处要以无符号整型为格式化数据打印，故不满足缺省整型的变量都会进行整型提升再打印。
//	//变量"a"整型提升后的补码：11111111111111111111111110000000(即"-128"的补码)，若以无符号整型为格式化数据打印，则最高位为数值位，结果为"4294967168"。
//
//	return 0;
//}

////整型在内存中的存储例题四
//int main()
//{
//	int i = -20;
//	//"-20"的原码：10000000000000000000000000010100。
//	//"-20"的反码：11111111111111111111111111101011。
//	//"-20"的补码：11111111111111111111111111101100。
//	
//	unsigned int j = 10;
//	//"10"的补码：00000000000000000000000000001010。
//	
//	printf("%d\n", i + j);//打印的结果为："-10"。
//	//"10+(-20)"的补码：11111111111111111111111111110110(即"-10"的补码)，若以整型为格式化数据打印，则最高位为符号位，结果为"-10"。
//	
//	return 0;
//}

////整型在内存中的存储例题五
//int main()
//{
//	unsigned int i;
//	for (i = 9; i >= 0; i--)//判断表达式恒成立，当无符号的整型类型由"0"再减去"1"时，会变为"4294967295"，故造成死循环。
//	{
//		printf("%u\n", i);
//	}
//	return 0;
//}

////整型在内存中的存储例题六
//int main()
//{
//	char a[1000];
//	int i;
//	for (i = 0; i < 1000; i++)
//	{
//		a[i] = -1 - i;
//	}
//	printf("%zu\n", strlen(a));//打印的结果为：255。
//	//"strlen"函数会寻找字符串的结束标志字符"\0"以统计并返回字符串的长度，字符"\0"的数值编码为"0"，故只要找到"a"数组中的"0"即输出结果。
//	//需要画图推导出结果，即画出有符号的"char"类型的取值范围轮回环。
//	
//	return 0;
//}

////整型在内存中的存储例题七
//int main()
//{
//	unsigned char i = 0;
//	for (i = 0; i <= 255; i++)//判断表达式恒成立，当无符号的"char"类型由"255"再加"1"时，会变为"0"，故造成无限循环。
//	{
//		printf("%u\n", i);
//	}
//	return 0;
//}

////整型在内存中的存储例题八
//int main()
//{
//	if (strlen("Aoki") - strlen("KilluaAoki") > 0)//"strlen"函数的返回值类型为"size_t"，即无符号整型类型，此处"4 - 10"的结果被解析成无符号数，故必然大于"0"。
//	{
//		printf(">\n");//结果为：>。
//	}
//	else
//	{
//		printf("<\n");
//	}
//	return 0;
//}

/**
	浮点类型在内存中的存储：根据国际标准IEEE(电气和电子工程协会)754规定，规定了浮点数在内存中存储的规则。
		1.根据规定，任意一个二进制浮点数可以表示为：(-1)^S * M * 2^E，其中"^"符号为次方而不是异或。
			a."S"表示符号位，若"S"为"0"则表示为正数，若"S"为"1"则表示为负数。
			b."M"表示有效数字位，并且"1 <= M < 2"。
			c."E"表示指数位。
		2.对于"32/64"位的浮点数，最高位为符号位"S"，接着的"8/11"位是指数位"E"，剩下的"23/52"位为有效数字位"M"。
		3.关于有效数字位"M"：因为计算机内部保存"M"时，默认这个数的第一位总是为：1，因此可以被舍去，这样做可以多出"1"位有效数字，待到读取时再把"M"第一位的"1"加上去。
		4.关于指数位"E"：存入内存时，"E"为无符号整数，但取出会分为三种情况："E"不全为"0"或不全为"1"、"E"全为"0"、"E"全为"1"。
			a.存入时"E"为无符号整数："8/11"位取值范围为"0~255/0~2047"，因为科学计数法指数位是有可能出现负数的，所以IEEE754规定存入内存时"E"的真实值必须先加上一个中间数"127/1023"(十进制)，再转换成二进制存入内存。
			b.取出时"E"不全为"0"或不全为"1"时：反推即可，注意各进制的转换和运算以及"M"舍去的"1"需要加上。
			c.取出时"E"全为"0"时：直接规定"E"的真实值即为"-126/-1023"(此处的"-"符号为减号)、"M"不再加上舍去的"1"，而是还原为以"0"为首的小数，即"0.xxx"("x"为任意十进制数)，这样做是为了表示正或负的"0"以及无限接近于"0"的值(正负取决于符号位"S")。
			d.取出时"E"全为"1"时：如果有效数字"M"全为"0"，表示值正或负无穷大(正负取决于符号位"S")。
*/

////浮点类型在内存中的存储示例
//int main()
//{
//	float num = 5.5f;
//	//"5.5"的二进制为：101.1。
//	//将"5.5"的二进制转换为科学计数：1.011 * 2^2。(注意是二进制而不是十进制，并且"^"符号为次方而不是异或)
//	//根据规定将科学计数进行转换：(-1)^0 * 1.011 * 2^2，初步得出"S = 0"、"M = 1.011"、"E = 2"。
//	//存入内存时："S"不变、"E"的真实值将加上对应的中间数再转换为二进制存入、"M"的第一位"1"被舍去再存入。
//	//故存入内存中的表示为二进制的值为：01000000101100000000000000000000。
//	//转换为十六进制进行展示：40B00000，又因为是小端存储模式，故调试观察的值为：0000B040。
//	
//	return 0;
//}

////浮点类型在内存中的存储例题
//int main()
//{
//	int n = 9;//以整型类型的存储方式，将数值存入内存中。
//	//"9"的补码：00000000000000000000000000001001。
//	
//	float* pFloat = (float*)&n;
//	
//	printf("n的值为：%d\n", n);//结果为：9。
//	
//	printf("*pFloat的值为：%f\n", *pFloat);//将存入内存中的二进制序列以单精度浮点类型为格式化数据打印，即将内存中整型值"9"的二进制序列认为是浮点数的二进制序列，分析得出是一个非常小的数。
//	//内存中变量"n"的值为：00000000000000000000000000001001。
//	//若将此值的二进制序列认为是浮点数的二进制序列，则可得出"S = 0"、"E = -126"、"M = 0.00000000000000000001001"。
//	//根据规定将科学计数进行转换：(-1)^0 * 0.00000000000000000001001 * 2^-126。
//	//再将其转换为二进制的科学计数：0.00000000000000000001001 * 2^-126。
//	//可以得出是一个非常小的数，以单精度浮点类型的精度无法将此数完全打印。
//	
//	*pFloat = 9.0f;//以单精度浮点类型的存储方式，将数值存入内存中。
//	//"9.0"的二进制为：1001.0。
//	//将"9.0"的二进制转换为科学计数：1.001 * 2^3。
//	//根据规定将科学计数进行转换：(-1)^0 * 1.001 * 2^3，初步得出"S = 0"、"M = 1.001"、"E = 3"。
//	//存入内存时："S"不变、"E"的真实值将加上对应的中间数再转换为二进制存入、"M"的第一位"1"被舍去再存入。
//	//故存入内存中的表示为二进制的值为：01000001000100000000000000000000。
//	//转换为十六进制进行展示：41100000，又因为是小端存储模式，故调试观察的值为：00001041。
//	
//	printf("num的值为：%d\n", n);//将存入内存中的二进制序列以整型类型为格式化数据打印，即将内存中浮点数值"9.0"的二进制序列认为是整型值的二进制序列，分析得出值为：1091567616。
//	//内存中变量"n"的值为：01000001000100000000000000000000。
//	//若将此值的二进制序列认为是整型值的二进制序列，则可得出值为："1091567616"。
//	
//	printf("*pFloat的值为：%f\n", *pFloat);//结果为：9.000000。
//	
//	return 0;
//}