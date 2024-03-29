#include <iostream>
#include <string>

/*
	模板进阶
		1.非类型模板参数
		2.模板特化
		3.模板的分离式编译
*/

/**
	非类型模板参数
		1.模板形参与模板实参均可具有非类型形式，即非类型模板参数。
		2.模板非类型形参
			a.模板非类型形参是可带有名字的模板非类型形参和可带有名字及默认值的模板非类型形参等。
			b.模板非类型形参必须拥有结构化类型，它可以是到对象或函数的左值引用类型、整数类型、指向对象或函数的指针类型、指向成员对象或成员函数的成员指针类型、枚举类型、"std::nullptr_t"(C++11起)、浮点类型(C++20起)、拥有特定属性的字面类类型(C++20起)。
			c.数组与函数类型可以写在模板声明中，但它们会被自动替换为适合的对象指针和函数指针。
			d.在类模板体内使用的模板非类型形参的名字是不可修改的纯右值，除非它的类型是左值引用类型以及C++20起支持的类类型。
		3.模板非类型实参：在实例化拥有模板非类型形参的模板时，视标准而言有不同限制。
			a.C++17前，字符串字面量、数组元素的地址和非静态成员的地址，不能被用作模板实参，来实例化它对应的模板非类型形参是对象指针的模板形参的模板；具体有如下限制：
				a'.对于整型和算术类型，实例化时所提供的模板实参必须是模板形参类型的经转换常量表达式(因此适用某些隐式转换)。
				b'.对于对象指针，模板实参必须指定某个具有静态存储期和(内部或外部)连接的完整对象的地址，或者是求值为适当的空指针或是C++11起支持的"std::nullptr_t"值的常量表达式。
				c'.对于函数指针，合法的实参是指向具有连接的函数的指针(或求值为空指针值的常量表达式)。
				d'.对于左值引用形参，实例化时所提供的实参不能是临时量、无名左值或无连接的具名左值(即实参必须具有连接)。
				e'.对于成员指针，实参必须是表示成"&类名::成员"的成员指针，或求值为空指针值或C++11起支持的"std::nullptr_t"值的常量表达式。
			b.C++17起，模板非类型形参可以使用的模板实参，可以是该模板形参类型的任何经转换常量表达式。(拓展)
				a'.具有例外，引用或指针类型的模板非类型形参以及C++20起的类类型的模板非类型形参和它的子对象之中的引用或指针类型的非静态数据成员，它们都不能指代下列对象或者是下列对象的地址：
					a''.临时对象(包括在引用初始化期间创建的对象)。
					b''.字符串字面量。
					c''."typeid"的结果。
					d''.预定义变量"__func__"。
					e''.子对象(包括非静态类成员、基类子对象或数组元素)。(C++20起要求为以上之一的(C++20起))
		4.容器库中C++11起支持的封装固定大小数组的容器"std::array"是使用非类型模板参数的一个例子。
			a."std::array"的声明：template<typename T, std::size_t N> class array;
			b.该结构体结合了C风格数组的性能、可访问性与容器的优点，比如可获取大小、支持赋值、随机访问迭代器等，是对标C数组的一种现代化替代方案，但并不常用。
			c.文档：https://zh.cppreference.com/w/cpp/container/array。
		5.模板形参与模板实参相关文档：https://zh.cppreference.com/w/cpp/language/template_parameters。
*/

////非类型模板参数示例：使用非类型模板参数。
//template<typename T, size_t N>//此处的"size_t"就是非类型模板形参。
//class Array
//{
//private:
//	T m_Array[N];
//public:
//	size_t GetSize() const
//	{
//		return N;
//	}
//};
//
//int main()
//{
//	Array<int, 5> array{};//此处的"5"就是非类型模板实参。
//	std::cout << array.GetSize() << std::endl;
//	return 0;
//}

/**
	模板特化：允许对给定的模板实参集定制模板代码，即为特定类型或值提供的特化实现，而不是使用模板的默认实现。
		1.显式(全)特化的细节(以下默认为全特化)
			a.显式特化可以在任何可以定义它的主模板的作用域中声明，并且可以与定义它的主模板的作用域不同。
			b.显式特化必须在非特化模板声明后出现。
			c.特化必须在导致隐式实例化的首次使用之前，在每个发生这种使用的翻译单元中声明。
			d.只有声明没有定义的模板特化可以像其他不完整类型一样使用(例如可以使用到它的指针和引用)。
			e.函数模板的显式特化是否内联等只与显式特化自身有关，主模板的声明是否带有对应说明符对它没有影响。
		2.函数模板的显式(全)特化(以下默认为全特化)(拓展)
			a.当特化函数模板时，如果模板实参推导能通过函数实参提供，那么就可以忽略它的模板实参。
			b.与某个特化带有相同名字和相同形参列表的函数不是特化，而是函数模板中的模板重载。
			c.不能在函数模板、成员函数模板以及隐式实例化类时的类模板的成员函数的显式特化中指定默认函数实参。
			d.显式特化不能是友元声明。
		3.类模板特化
			a.类模板的特化可详细区分为全特化和部分特化，而模板部分特化是主要针对类模板而言的(随着学习的深入，在学习到重载决议时，会再详细介绍函数重载与函数特化)。
				a'.全特化：对于给定的模板实参集，提供了完整的实现。
				b'.部分特化：对于给定的模板实参集，提供了部分实现或加入了额外的限制。
			b.语法：template < 形参列表 > 类关键词 类头名 < 实参列表 > 声明。
				a'.其中"类头名"标识先前声明的类模板。
				b'.此声明必须与它所特化的主模板定义处于相同的命名空间中。
			c.类模板特化的实参列表有特定的限制(以下只列举部分限制)：
				a'.实参列表不能与非特化的实参列表相同，即它必须有所特化。
				b'.实参列表中不能出现默认实参。
		4.特化的优点
			a.可以用于优化特定类型或值的性能。
			b.可以为不适合默认实现的类型或值提供特殊行为。
*/

////模板特化示例一：函数模板的显式(全)特化。
//template<typename T>//主模板。
//void print(T value)
//{
//	std::cout << value << std::endl;
//}
//
//template<>//模板特化。
//void print<std::string>(std::string value)
//{
//	std::cout << "\"" << value << "\"" << std::endl;
//}
//
//int main()
//{
//	print(42);//输出: 42。
//	print("hello");//输出: "hello"。
//	return 0;
//}

////模板特化示例二：类模板的全特化。
//template<typename T>//主模板。
//class MyTemplateClass
//{
//public:
//	void print()
//	{
//		std::cout << "This is a generic template class." << std::endl;
//	}
//};
//
//template<>//模板特化。
//class MyTemplateClass<int>
//{
//public:
//	void print()
//	{
//		std::cout << "This is a specialized template class for int type." << std::endl;
//	}
//};
//
//int main()
//{
//	MyTemplateClass<double> myTemplateClass1;
//	myTemplateClass1.print();//输出: This is a generic template class。
//
//	MyTemplateClass<int> myTemplateClass2;
//	myTemplateClass2.print();//输出: This is a specialized template class for int type。
//
//	return 0;
//}

////模板特化示例三：类模板的部分特化。
//template<typename T>
//class MyClass
//{
//public:
//	MyClass(T val) : value(val)
//	{
//	}
//
//	void print()
//	{
//		std::cout << "Value = " << value << std::endl;
//	}
//
//private:
//	T value;
//};
//
//template<typename T>
//class MyClass<T*>//部分特化，注意此处的"T*"表示指向"T"类型的指针，并没有给出具体的类型，因此是部分特化。
//{
//public:
//	MyClass(T* val) : ptr(val)
//	{
//	}
//
//	void print()
//	{
//		std::cout << "Pointer value = " << *ptr << std::endl;
//	}
//
//private:
//	T* ptr;
//};
//
//int main()
//{
//	MyClass<int> obj1(10);
//	obj1.print();//输出: Value = 10。
//
//	int num = 20;
//	MyClass<int*> obj2(&num);
//	obj2.print();//输出: Pointer value = 20。
//
//	return 0;
//}

/**
	模板的分离式编译
		1.关于模板的实例化
			a.在要求完整对象类型的语境中引用某个类模板特化时，或在要求函数定义存在的语境中引用某个函数模板特化时，除非模板已经被显式特化或显式实例化，否则模板即被实例化(模板代码被实际编译)。
			b.模板的定义必须在隐式实例化点可见，这也模板库通常都在头文件中提供所有模板定义的原因。
			c.模板只有实例化才会被实际编译，即产生具体类型的代码。
		2.编译阶段下编译器对模板的处理
			a.预处理器翻译单元与翻译单元
				a'.在进行编译前，预处理器会对源文件进行预处理操作，其主要包括将源文件展开，递归地将所有的"#include"指令替换为指令中声明的实际文件，而这一步骤将产生预处理翻译单元。
				b'.进一步的步骤包括对"#define"指令进行宏展开，以及对"#ifdef"指令进行条件编译，等等；这将使预处理翻译单元转换为翻译单元，翻译单元是预处理器的输出结果，即经过预处理后的源文件。
				c'.编译器根据翻译单元生成一个目标文件，而后就可以进一步处理和进入链接阶段(可能与其他目标文件一起)以形成可执行程序。
			b.编译器处理C++源文件时，可将此阶段称为编译阶段，以下是关于模板的编译阶段的说明：
				a'.进行编译时，编译器会将各个预处理记号转换成记号，将所有记号当作一个翻译单元进行语法和语义分析并进行翻译。
				b'.此后编译器会检验每个翻译单元，产生所要求的模板实例化的列表，其中包括显式实例化所要求的实例化；随后定位模板定义，并进行所要求的实例化，以产生实例化单元。
				c'.而后将翻译单元、实例化单元和为满足外部引用所需的库组件交由链接器，进入链接阶段，进而汇集成一个程序映像，它含有在它的执行环境中执行所需的信息。
				d'.一些编译器不实现实例化单元，而是简单地在进行编译时编译每个模板实例化，将代码存储在它所显式或隐式要求的对象文件中，然后由链接器在链接阶段将这些编译后的实例化合二为一。
		3.模板在分离式编译环境下产生的问题
			a.在分离式编译的环境下，编译器编译当前的翻译单元时，并不知道另一翻译单元的存在，而当遇到模板的声明或实例化时，在没有模板的定义下，其只能假设模板的定义在另一翻译单元中(产生具有外部链接的未决符号)，并不会实例化模板，而是交由链接器处理。
			b.当编译器遇到模板的定义时，若是在当前翻译单元下有模板的实例化，那么编译器才会实例化模板，进而产生具体类型的代码，但若是没有模板的实例化，那么编译器则不会实例化模板，这将导致模板代码无法被实际编译。
			c.若模板未被实例化，也就代表着模板代码没能转化为具体类型的代码，即模板代码未被实际编译，这将导致链接器在解析先前产生的具有外部链接的未决符号时，无法找到该模板的具体实现，从而导致链接失败。
		4.解决模板在分离式编译环境下产生的问题
			a.在模板定义处，显式实例化模板，从而解决模板代码未被实际编译的问题。
			b.将模板的声明和定义放在同一个翻译单元中，从而解决模板代码未被实际编译的问题。
*/