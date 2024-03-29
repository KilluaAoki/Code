#pragma once

//引用头文件
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

//重命名堆数据元素类型
typedef int HeapDataType;

//定义结构体类型(数组实现堆)
typedef struct Heap
{
	HeapDataType* array_ptr;
	size_t size;
	size_t capacity;
} Heap;

//初始化堆
void Init_Heap(Heap* ptr);

//检查堆容量
void Check_Heap(Heap* ptr);

//交换元素
void Swap(HeapDataType* array_ptr, size_t x, size_t y);

//以树状打印堆：https://stackoverflow.com/questions/65140349/printing-binary-heap-in-tree-format-c-language。
void Print_Heap(HeapDataType* arr_ptr, size_t size);

//适用于小根堆的向上调整函数
void Insert_Min_Heap(HeapDataType* array_ptr, size_t index);

//适用于小根堆的向下调整函数
void Ify_Min_Heap(HeapDataType* array_ptr, size_t index, size_t size);

//适用于大根堆的向上调整函数
void Insert_Max_Heap(HeapDataType* array_ptr, size_t index);

//适用于大根堆的向下调整函数
void Ify_Max_Heap(HeapDataType* array_ptr, size_t index, size_t size);

//插入元素到堆中
void Push_Heap(Heap* ptr, HeapDataType data, void (* Adjustment)(HeapDataType*, size_t));

//删除堆顶元素
HeapDataType Pop_Heap(Heap* ptr, void (* Adjustment)(HeapDataType*, size_t, size_t));

//获取堆顶元素数据
HeapDataType Top_Heap(Heap* ptr);

//堆排序
void Sort_Heap(HeapDataType* array_ptr, size_t size, void (* Adjustment)(HeapDataType*, size_t, size_t));

//判断堆是否为空堆
bool Empty_Heap(Heap* ptr);

//获取堆中的元素个数
size_t Size_Heap(Heap* ptr);

//销毁堆
void Destroy_Heap(Heap* ptr);