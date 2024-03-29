#pragma once

//引用头文件
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

//重命名栈数据元素类型
typedef int StackDataType;

//定义结构体类型(数组实现栈)
typedef struct Stack
{
	StackDataType* array_ptr;
	size_t top;
	size_t capacity;
} Stack;

//初始化栈
void Init_Stack(Stack* ptr);

//将一个元素压入栈中
void Push_Stack(Stack* ptr, StackDataType data);

//将一个元素从栈中弹出
void Pop_Stack(Stack* ptr);

//获取栈的栈顶元素数据
StackDataType Top_Stack(Stack* ptr);

//判断栈是否为空栈
bool Empty_Stack(Stack* ptr);

//获取栈中的元素个数
size_t Size_Stack(Stack* ptr);

//销毁栈
void Destroy_Stack(Stack* ptr);