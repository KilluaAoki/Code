#include <iostream>

/*
	字符与字符串
		1.计算机中表达字符的方式
		2.关于C/C++的字符串字面量和字符串
*/

/**
	计算机中表达字符的方式
		1."ASCII"码："American Standard Code for Information Interchange"缩写，即美国信息交换标准代码，是电子通讯的字符编码标准。
			a.在计算机中，所有的数据在存储和运算时都要使用二进制数表示，那么字符也不例外，但用哪些二进制数字表示哪个符号就成了问题，这也就是俗称的编码问题。
			b.在不同计算机上，可以使用不同的编码标准，但是为了互通而不造成混乱，就需要有一种统一的编码方式，于是美国有关的标准化组织就推出了"ASCII"编码。
			c."ASCII"码规定，每个英文字符(包括大小写字母、数字、特殊符号)都对应着一个整数，在计算机里只要存储这个的整数，就能代表这个字符了。
			d."ASCII"码可分为控制字符和可打印字符，控制字符是用于控制显示设备的显示方式(换行、回车、退格等)，而可打印字符是用于显示的字符(包括字母、数字等)。
			e."ASCII"码局限在于只能显示基本拉丁字母("26"个)、阿拉伯数字和英式标点符号，只适用于英文，但使用计算机的人不仅仅是英文使用者，其不能解决其他语言该如何表示的问题。
		2."Unicode"标准：又被称为统一码或万国码等，是一种信息技术标准，用于对世界上大多数书写系统中表达的文本进行一致的编码、表示和处理。
			a."Unicode"标准由统一码联盟负责维护，此标准伴随着通用字符集的标准而发展，并且"Unicode"至今仍在不断增修，每个新版本都加入更多新的字符。
			b."Unicode"标准定义了三种和其他几种存在的编码方式，主要是"UTF-8"、"UTF-16"、"UTF-32"编码方式。("UTF"是"Unicode Transformation Format"的缩写，即把"Unicode"标准转做某种格式的意思)
				a'."UTF-8"编码方式：一种可变长度的编码方式，它可以使用一至四个字节表示一个符号，根据不同的符号而变化字节长度，兼容"ASCII"码。
				b'."UTF-16"编码方式：一种可变长度的编码方式，大部分字符都以固定长度的字节("2"字节)储存，但"UTF-16"无法兼容"ASCII"码。
				c'."UTF-32"编码方式：一种固定长度的编码方式，每个字符都用"4"字节储存，并不常用，也无法兼容"ASCII"码。
			c.普遍采用"UTF-8"编码方式，因为它兼容"ASCII"码，而且可以节省空间。
		3."GB18030"字符集：由中华人民共和国国家标准所规定的变长多字节字符集，适用于简体中文和繁体中文等，并且包含了"27484"个汉字。
			a.采用变长多字节编码，每个字可以由多个字节("1"个字节、"2"个字节或"4"个字节)组成，编码空间庞大，最多可定义"161"万个字符。
			b.支持中国国内少数民族文字、中日韩和繁体汉字以及"emoji"等字符。
			c."GB18030"字符集兼容"GB2312"编码、"GBK"编码以及"ASCII"码，并且其取代了旧发布的"GB2312"编码和"GBK"编码。
				a'."GB2312"编码于1980年发布，适用于汉字处理、汉字通信等系统之间的信息交换，共收入"6763"个汉字和非汉字图形字符"682"个，随后有了"GBK"编码。
				b'."GBK"编码是"GB2312"的扩展，于1995年发布，对"GB2312"编码进行了扩充，是中国和地区提供的第三大流行编码。
			d."GB18030"字符集算的上是"Unicode"的一种变换格式。
		4.C++中对各大编码格式的支持："char"类型、"wchar_t"类型、"char8_t"类型(C++20)、"char16_t"类型(C++11)、"char32_t"类型(C++11)。
			a."char"类型(编码格式随系统而改变)
				a'.大小为一字节，编码格式随系统默认编码格式而变。
				b''.字符串类型为"string"，字符串常量语法为："Hello"。
			b."wchar_t"类型(Windows平台)
				a'.大小为两个字节，编码格式为"UTF-16"。
				b''.字符串类型为"wstring"，字符串常量语法为：L"Hello"。
			c."wchar_t"类型(Linux平台)
				a'.大小为四个字节，编码格式为"UTF-32"。
				b'.字符串类型为"wstring"，字符串常量语法为：L"Hello"。
			d."char8_t"类型(C++20)
				a'.大小为一个字节，编码格式为"UTF-8"。
				b'.字符串类型为"u8string"，字符串常量语法为：u8"Hello"。
			e."char16_t"类型(C++11)
				a'.大小为两个字节，编码格式为"UTF-16"。
				b'.字符串类型为"u16string"，字符串常量语法为：u"Hello"。
			f."char32_t"类型(C++11)
				a'.大小为四个字节，编码格式为"UTF-32"。
				b'.字符串类型为"u32string"，字符串常量语法为：U"Hello"。
*/

////计算机中表达字符的方式示例：输出"ASCII"码中的可打印字符。
//int main()
//{
//	std::cout << "Printable ASCII:\n";
//	for (char i = 32; i < 127; ++i)
//	{
//		std::cout << i << ' ';
//		if (i % 16 == 15)
//			std::cout << '\n';
//	}
//}

/**
	关于C/C++的字符串字面量和字符串
		1.关于C/C++的字符串字面量
				a'.C语言中无前缀的字符串字面量类型为"char[N]"，其中"N"代表了字符串字面量的元素个数，并且包括了字符串字面量的空终止符。
				b'.C++中无前缀字符串字面量的类型为"const char[N]"，其中"N"代表了字符串字面量的元素个数，并且包括了字符串字面量的空终止符。
				c'.C++11前：字符串字面量可转换为且可赋值(初始化)给非"const"的指向"char"类型指针，以与C兼容，因为C中字符串字面量类型为"char[N]"。
				d'.C++11起：字符串字面量不可转换为或赋值(初始化)给非"const"的指向"char"类型指针，若想要这种转换则需使用显式转型(例如：const_cast)。
				e'.因为有很多现有代码依赖于C++11前的字符串字面量类型的隐式转换，若采用C++11起的强制禁止隐式转换，则会导致大量的编译错误(破坏代码)，并且不兼容C语言。
		2.关于C/C++的字符串
				a'.C语言中的字符串可初始化或赋值给指针以及数组(类型不再赘述)，并且其包含了字符串的空终止符作为字符串的结束标志。
				b'.C语言中关于字符以及字符串的函数，详见：https://zh.cppreference.com/w/c/string/byte。
				c'.C++中的字符串通常指的是"string"模板类，是为操作任何字符类型的字符串设计的模板类。
				d'.C++的"string"类中有着一个成员变量，用于指代字符串的长度，所以其可不需要像C语言中的字符串那样以空终止符作为字符串的结束标志(取决于标准与实现)。
*/