/*引用头文件*/
#include <stdio.h>
#include <string.h>

////第一段代码
//int main()//"main"函数是程序的入口：可以在文件中的任意位置；在一个工程中"main"函数有且仅有一个。
//{
//	printf("打印的第一串代码\n");//"printf"：库函数，意为在屏幕上打印(输出)信息；"printf"的使用需要引用头文件"stdio.h"。
//	printf("打印的第二串代码\n");//"\n"：换行。
//	printf("打印的第三串代码\n");
//	return 0;
//}

////数据类型的大小示例
//int main()
//{
//	//使用"sizeof"计算数据类型的大小："sizeof"是关键字，属于操作符，意为计算类型或者变量所占空间的大小，单位为字节。
//	printf("%d\n",sizeof(char));		//打印字符数据类型的大小；"%d"：以"int"整型的方式进行打印。
//	printf("%d\n",sizeof(short));		//打印短整型的大小。
//	printf("%d\n",sizeof(int));			//打印整型的大小。
//	printf("%d\n",sizeof(long));		//打印长整型的大小；C语言标准规定sizeof(long)>=sizeof(int)，所以long与int大小都为4字节。
//	printf("%d\n",sizeof(long long));	//打印更长整型的大小。
//	printf("%d\n",sizeof(float));		//打印单精度浮点数的大小。
//	printf("%d\n",sizeof(double));		//打印双精度浮点数的大小。
//	return 0;
//}

////创建变量示例
//int main()
//{
//	printf("%s\n", "Aoki");//"Aoki"即为一串常量字符串。"%s"：以字符串的方式进行打印。
//	int age = 18;//创建一个变量的格式。
//	float height = 183.5f;//单精度变量赋值后面加"f"是表明该数字为单精度浮点型(float)。
//	double weight = 60.5;//双精度变量不需要添加"f"，默认不添加即是双精度浮点型(double)。
//	age = age + 1;//改变你的变量。
//	printf("%d\n", age);//证明变量是可以被改变的。
//	height = height + 0.5f;
//	weight = weight + 5;
//	printf("%f\n", height);//"%f"：代表单精度浮点型数据(float)。
//	printf("%lf\n", weight);//"%lf"：代表双精度浮点型数据(double)。
//	return 0;
//}

////局部变量与全局变量示例
//int a = 100;//全局变量，在括号外部定义。
//int main()
//{
//	int a = 10;//局部变量，在括号内部定义。
//	printf("%d\n", a);//当全局变量和局部变量名字相同的情况下，局部变量优先；但并不建议把全局变量和局部变量的名字写成一样的。
//	return 0;
//}

////编写一个代码：求两个整数的和。
//int main()
//{
//	int num = 0;
//	int num1 = 0;
//	int num2 = 0;
//	scanf_s("%d%d", &num1,&num2);//"scanf"：输入函数。
//	num = num1 + num2;
//	//printf("%d", num1);
//	//printf("+");
//	//printf("%d", num2);
//	//printf("=");
//	//printf("%d\n", num);
//	printf("%d+%d=%d\n", num1,num2,num);
//	return 0;
//}

/*
	作用域&生命周期
		1.局部变量的作用域，就是变量所在的局部范围。
		2.全局变量的作用域，就是整个工程；若跨越文件则需要使用"extern"进行声明。
		3.变量的生命周期指的是：变量的创建和销毁之间的时间段。
		4.局部变量的生命周期：进入局部范围生命开始，出局部范围生命结束。
		5.全局变量的生命周期：程序的生命周期。
*/

////作用域示例
//int year = 2021;//全局变量
//int main()
//{
//	int a = 10;
//	printf("a=%d\n", a);//局部变量变量"a"于此起作用，此处花括号"{}"内就是它的作用域，若离开则销毁。
//	return 0;
//}

/*
	常量
		1.字面常量
		2.被"const"修饰的常变量
			a.本质依旧是变量，但是被"const"修饰，具有常属性(不能被改变的属性)。
			b.被"const"修饰的常变量在C语言中只是在语法层面限制了变量不能直接被改变。
		3."#define"定义的标识符常量：主要在函数外部定义。
		4.枚举常量：使用关键字"enum"定义；指可以被一一列举的常量，如：性别、三原色。
*/

////常量示例
//int main()
//{
//	////字面常量
//	//3.14; 10; 'a'; "abcdef";
//	
//	////被"const"修饰的常变量
//	//const int num = 10;
//	//num = 20;//编译器报错：表达式必须是可修改的左值。
//	//printf("num=%d\n", num);
//	
//	////"#define"定义的标识符常量
//	//#define MAX 10000
//	//int max = MAX;
//	//printf("%d\n", MAX);
//	
//	////枚举常量
//	//enum Sex//括号内就是这种枚举常量的未来取值，有且只能取其中的一个；括号中的男、女、保密都属于枚举常量。
//	//{
//	//	man=1,//赋上一个最初始的值。
//	//	woman,
//	//	secrecy
//	//};
//	//printf("man=%d\n", man);			//打印的值为1。
//	//printf("woman=%d\n", woman);		//往下依次递增至2(初始值是1)。
//	//printf("secrecy%d\n", secrecy);	//往下依次递增至3(初始值是1)。
//
//	return 0;
//}

/*
	字符串：用双引号括引起来的一串字符。
		1.字符串的结束标志是"\0"。
		2.在计算字符串长度的时候"\0"是结束标志，计入元素个数但不计入字符串的长度。
		3.使用"char"字符数据类型定义字符、字符串以及字符数组。
*/

////字符串使用示例
//int main()
//{
//	//一串字符串常量示例
//	"abcdef";
//	
//	//创建字符数组(使用双引号引起的字符串)。
//	char arr1[] = "abcd";//方括号中没有定义元素个数，默认根据后面的双引号中的元素定义。
//	printf("%d\n", sizeof(arr1));//使用"sizeof"计算元素个数，可知数组"arr"共有5个元素，在结尾位置隐藏了一个"\0"的字符。
//	
//	//创建字符数组(使用单引号引起的单个字符)。
//	char arr2[] = { 'a','b','c' };
//	char arr3[] = { 'a','b','c','\0'};
//	printf("%s\n", arr1);//"%s"：打印字符串；打印出4个字符。
//	printf("%s\n", arr2);//打印出乱码：因为使用单引号创建的数组不会默认添加"\0"作为结束标志，在"arr2"内容中有很多不知道的东西。
//	printf("%s\n", arr3);//手动放下"\0"，打印出3个字符，并且没有乱码。
//
//	//使用"strlen"求字符串长度：使用"strlen"需要引用头文件"string.h"。
//	int len = strlen("abc");
//	printf("%d\n", len);//打印出的结果为：3；也代表了"\0"不算入字符串长度。
//	printf("%d\n", strlen(arr1));//打印出的结果为：4。
//	printf("%d\n", strlen(arr2));//打印出的结果为：随机值。
//
//	return 0;
//}

/*
	转义字符：可转变字符原有意思的字符。
		1.常用转义字符：混个眼熟就好了，可不是要你背昂，会用示例里的就好啦！
			a." \? "：在书写连续多个问号时使用，防止他们被解析成三字母词。
			b." \' "：用于表示字符常量单引号" ' "。
			c." \" "：用于表示一个字符串内部的双引号。
			d." \\ "：用于表示一个反斜杠，防止它被解释为一个转义序列符。
			e." \a "：警告字符，蜂鸣，可使本机发出声音。
			f." \b "：退格符。
			g." \f "：换页符。
			h." \n "：换行符。
			i." \r "：回车符。
			j." \t "：水平制表符。
			l." \v "：垂直制表符。
			m." \ddd "："ddd"表示1~3个八进制的数字。
			n." \xdd "："dd"表示2个十六进制数字。
		2.在转义字符"\ddd"中，并非一定需要3个八进制数字，请注意范围。
*/

////转义字符使用示例
//int main()
//{
//	//"printf"在打印数据时，可以指定打印的格式。
//	printf("\n");					//打印发现空了一行，因为转义字符"\n"意为换行。
//	printf("c:\test\test.c\n");		//无法打印出"\t"，因为"\t"为转义字符(横向制表(Tab))。
//	printf("c:\\test\\test.c\n");	//可加"\"防止被转变。
//	printf("(are you ok??)");		//在某些编译器中"??)"属于三字母词会被转义成"]"。
//	printf("%c\n", '\'');			//"%c"：打印字符；打印单引号；不加"\"会出现语法问题：落单了一个单引号。
//	printf("\a");					//"\a"：属于转义字符，意为蜂鸣。
//
//	//转义字符"\ddd"(八进制)和"\xdd"(十六进制)的运用
//	printf("%c\n", '\130');//八进制的"130"为十进制的"88"，选用ASCII码值表中的88对应的字符"X"表示，故打印结果是：X。
//	printf("%c\n", '\101');//八进制的"101"为十进制的"65"，在ASCII码值表中"65"代表字符"A"。
//	printf("%c\n", '\x30');//十六进制的"30"为十进制"48"，在ASCII码值表中"48"代表字符"0"。
//	printf("%d\n", '\130');//因为"printf"打印的格式是"%d"整型，故结果是：88。
//	printf("%d\n", strlen("c:\test\108\test.c"));//计算出字符串的长度是为：14；注意"8"不属于八进制。
//	
//	return 0;
//}

//注释是用来解释代码的。
//添加注释快捷键"Ctrl+K+C"；取消注释快捷键"Ctrl+K+U"。
//C++的注释风格为：" // "，引用到C语言。
//C语言的注释风格为：" /**/ "，不支持嵌套注释，遇到第一个"*/"就没了。

////选择语句：又称分支语句。
//int main()
//{
//	int 输入的值 = 0;
//	printf("你是gay吗？\n请输入是或不是(是代表1，不是代表2)>");
//	scanf_s("%d", &输入的值);
//	if (输入的值==1)
//	{
//		printf("\n那你是1还是0嘞？(不要跟我说你是0.5哦~)\n请输入1或0>");
//		scanf_s("%d", &输入的值);
//		if (输入的值==1)
//		{
//			printf("\n这不发个微信来嘛哈哈哈(bushi)。\n");
//			return 0;
//		}
//		if (输入的值==0)
//		{
//			printf("\n呜呜呜好兄弟，两个0是没有好结果的。\n");
//			return 0;
//		}
//		else
//		{
//			printf("\n输入的什么玩意给我重新打开再来一次。\n");
//		}
//		return 0;
//	}
//	if (输入的值==2)
//	{
//		printf("\n拒绝恐同，从我做起！\n");
//		return 0;
//	}
//	else
//	{
//		printf("\n输入的什么玩意给我重新打开再来一次。\n");
//	}
//	return 0;
//}

////循环语句："while"。
//int main()
//{
//	int line = 0;
//	while(line<30000)
//	{
//		printf("写代码：%d行。\n", line);
//		line++;
//	}
//	if (line == 30000)
//	{
//		printf("\n恭喜达成成就：写代码30000行。\n");
//	}
//	return 0;
//}

////函数：简化代码，代码复用。
//int Add(int x, int y)
//{
//	int z = 0;
//	z = x + y;
//	return z;//返回的值为"z"。
//}
//int main()
//{
//	int num1 = 0;
//	int num2 = 0;
//	scanf_s("%d%d", &num1, &num2);
//	printf("%d", Add(num1, num2));
//	return 0;
//}

////数组：一组相同类型的元素的集合。
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };//第一个元素下标为0，依次递增，规定使用下标访问。
//	char ch[5] = "abc";//不完全初始化，剩余补充为："\0"。
//	int 下标 = 0;
//	while (下标<10)
//	{
//		printf("%d ", arr[下标]);//第一次打印为下标为"0"的元素"1"。
//		下标++;
//	}
//	return 0;
//}

////操作符
//int main()
//{
//	int a = 9 / 2;
//	printf("%d\n", a);//打印结果为4。
//	float b = 9.0 / 2;//两端需要取一个为小数就能打印出答案9/2=4.500000。
//	printf("%f\n", b);//"%f"：打印浮点型。
//	int c = 9 % 2;//取模(余数)。
//	printf("%d\n", c);
//	int d = 2;//"int"整型的大小是：4byte=32bit。
//	int e = d << 1;//左移操作符：移动的是二进制位，右边补"0"。
//	printf("%d\n", e);//打印结果为：4。
//	int f = 0;//"0"表示假，非"0"表示真，并不是"1"就表示真。
//	printf("%d\n", !f);//一般非"0"表示为"1"；"!"多应用于if语句。
//	int arr[10] = { 0 };
//	printf("%d\n", (int)sizeof arr);//"(int)"：强制类型转换为"int"；计算数组的总大小；一个整型元素是4个bite，10个元素=40bite。
//	int 数组元素个数 = sizeof(arr) / sizeof(arr[0]);//计算数组元素个数。
//	printf("%d\n", 数组元素个数);
//	return 0;
//}

////操作符："~"按二进制位取反(把所有二进制位中的数字，1变成0，0变成1)
//int main()
//{
//	int a = 0;
//	//一个整数的二进制表示有三种：原码、反码、补码；整数在内存中储存的是补码；整型变量是4字节=32bit位。
//	//正数：原码、反码、补码相同
//	//负数：最高符号位1表示为负数；负数的原码变反码则是符号位不变，其余按位取反为反码；反码加1为补码。
//	printf("%d\n", ~a);//打印的是原码，内存存储的是补码。
//	return 0;
//}

////操作符："++"和"--"(只列举++的例子，--同理)
//int main()
//{
//	int a = 10, b = 0;
//
//	b = ++a;//前置"++"：先加后使用；
//	printf("%d\n", a);//打印结果为：11。
//	printf("%d\n", b);//打印结果为：11。
//
//	b = a++;//后置"++"：先使用后加；
//	printf("%d\n", a);//打印结果为：12。
//	printf("%d\n", b);//打印结果为：11。
//
//	return 0;
//}

////操作符："(类型)"强制类型转换
//int main()
//{
//	//int a = 3.14;//Ctrl+F7报警告：从"double"转换到"int"，可能丢失数据。
//	int a = (int)3.14;//强制转换"double"类型为"int"类型，再次Ctrl+F7便无警告。
//	printf("%d\n", a);
//	return 0;
//}

////逻辑操作符："&&"逻辑与和"||"逻辑或
//int main()
//{
//	//int a = 1; int b = 1; int c = a && b;
//	//printf("%d\n", c);//结果为：1，意思为当"a"和"b"中都为真则为真。
//
//	//int a = 1; int b = 0; int c = a && b;
//	//printf("%d\n", c);//结果为：0，意思为当"a"和"b"中只要有一个为假则都为假。
//
//	//int a = 1; int b = 0; int c = a || b;
//	//printf("%d\n", c);//结果为：1，意思为当"a"和"b"中只要有一个为真则为真。
//	return 0;
//}

////条件操作符："else1?else2:else3"；又名三目操作符；"else"为表达式；意为当"else1"成立则采用"else2"的结果，否则采用"else3"的结果。
//int main()
//{
//	int a = 0;
//	int b = 3;
//	int max = 0;
//
//	//if (a>b)
//	//{
//	//	max = a;
//	//}
//	//else
//	//{
//	//	max = b;
//	//}
//
//	max = a > b ? a : b;//如果"a>b"成立这结果为"a"否则为"b"，然后再将值赋给"max"变量。
//	
//	printf("%d\n", max);
//
//	return 0;
//}

////逗号表达式：逗号隔开的一串表达式；从左向右依次计算的，整个表达式的结果是最后一个表达式的结果。
//int main()
//{
//	int a = 0;int b = 3;int c = 5;
//	int d = (a = b + 2, c = a - 4, b = c + 2);//依次计算，"b"的值赋给了"d"。
//	printf("%d\n", d);//结果为：3。
//	return 0;
//}

////下标引用操作符
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	printf("%d\n", arr[5]);
//	return 0;
//}

////函数调用操作符：调用函数的时候，函数名后边的括号就是函数调用操作符。
//int main()
//{
//	printf("%d", 666);
//	return 0;
//}

////关键字：由C语言提供的，不能自己创建关键字；变量名不能是关键字。
//int main()
//{
//	//"extern"：声明外部符号(比如跨文件的全局变量，需要使用"extern"声明一下)。
//
//	//"void"表示无或者空的意思。
//
//	//"auto"：每个局部变量都有"auto"修饰，但被自动省略掉了；同时"auto"在新的C语言语法中也有其他用法，暂时不考虑。
//	{
//		auto int a = 0;//自动创建，自动销毁的，即为自动变量。
//		int b = 0;//auto省略掉了。
//	}
//	
//	//register关键字：大量或频繁被使用的数据，放在寄存器中可提升效率；
//	{
//		register int a = 0;//建议num的值存放在寄存器中(编译器说的算，只是建议)；寄存器存在于速度金字塔顶尖。
//	}
//						 
//	//"define"和"include"不是关键字，是预处理指令。
//	//"define"可定义标识符常量、可定义宏。
//	{
//		#define MAX 1000//定义标识符常量。
//		printf("%d\n", MAX); 
//	}
//	{
//		#define ADD(X,Y) ((X)+(Y))//定义宏；注意这里的括号。
//		printf("%d\n", 4 * ADD(2, 3));//先乘除后加减，若上行不加括号则打印结果为11。
//	}
//
//	//"typedef"：类型重定义，即类型重命名。
//	{
//		typedef unsigned int u_int;//将"unsigned"起了个别名叫"u_int"；意义在于缩短了名字，不用打那么多(其实我有Tab呀呜呜)。
//		unsigned int a = 100;//"unsigned"：无符号的。
//		u_int b = 100;//可以发现同时起作用。
//	}
//	 
//	//存储的区域分为栈区(局部变量和函数参数)、堆区(动态内存分配的)和静态区(全局变量、静态变量、"static"修饰的变量)等。
//	//"static"：静态的，用来修饰变量和函数的；"static"修饰局部变量、全局变量、函数。
//	//"static"修饰的局部变量，总是存在内存的静态区，即使变量所存在的函数运行介绍，这个静态变量的值也不会被销毁，能够重复使用这个值。
//	//"static"修饰的全局变量，使得这个全局变量只能在自己所在的源文件(.c)内部可以使用(外部文件使用"extern"声明也无法使用)；本质是把全局变量的外部链接属性更改为内部链接属性。
//	//"static"修饰的函数同全局变量(上一行)。
//	//"static"修饰的局部变量是在程序的编译阶段就分配好了地址，可调试转反汇编查看以下代码，可发现"static"没有对应的汇编指令，并且调试不执行"static"的代码。
//	{
//		int i = 0;
//		while (i < 10)
//		{
//			static int a = 1;//"static"修饰的局部变量出局部变量作用域后被保留了，改变了局部变量的生命周期(本质上是改变了变量的存储区域)。
//			a++;
//			printf("%d ", a);//打印的结果为：2 3 4 5 6 7 8 9 10 11。
//			i++;
//		}
//	}
//	
//	return 0;
//}

////指针：地址。
//int main()
//{
//	//使用实例
//	int a = 10;//"a"在内存中分配的空间为4个字节。
//	printf("%p\n", &a);//%p：以地址的形式打印。
//	int* pa = &a;//"pa"是用来存放地址的；在C语言中"pa"叫指针变量；"*"说明"pa"是指针变量；"int"说明"pa"指向的对象是"int"类型的；"*pa"就是通过"pa"里边的地址，找到"a"；取出的地址是"a"第一个字节的地址(较小的地址)。
//	*pa = 20; //"*"：间接访问操作符，又称解引用操作符。
//	printf("%d\n", a);
//
//	//计算指针变量的大小
//	//	指针变量的大小取决于地址的大小。
//	//	32位平台下地址是32个bit位(即4个字节)。
//	//	64位平台下地址是64个bit位(即8个字节)。
//	//	指针大小在32位平台是4个字节，64位平台是8个字节。
//	printf("%d\n", sizeof(char*));
//	printf("%d\n", sizeof(short*));
//	printf("%d\n", sizeof(int*));
//	printf("%d\n", sizeof(long*));
//	printf("%d\n", sizeof(long long*));
//	printf("%d\n", sizeof(float*));
//	printf("%d\n", sizeof(double*));
//	
//	return 0;
//}	

////结构体：结构体使得C语言有能力描述复杂类型，而且可以让C语言创建新的类型出来。
//struct Stu//struct：创建类型。
//{
//	char name[20];//名字
//	int age; //年龄
//	double score;//成绩
//};
//struct Book
//{
//	char name[20];//名字
//	float price;//价格
//	char id;//页面号
//};
//int main()
//{
//	struct Stu s={"Aoki",19,99.9};//结构体的创建和初始化。
//	printf("1：%s %d %lf\n", s.name, s.age, s.score);//"."操作符：结构成员访问操作符。
//	
//	struct Stu *ps = &s;//把结构交给指针变量。
//	printf("2：%s %d %lf\n", (*ps).name, (*ps).age, (*ps).score);
//
//	printf("3：%s %d %lf\n", ps->name, ps->age, ps->score);//结构体指针"->"成员变量名。
//
//	return 0;
//}