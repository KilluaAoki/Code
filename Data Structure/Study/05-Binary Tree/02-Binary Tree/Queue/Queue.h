#pragma once

//引用二叉树头文件
#include "../Binary Tree.h"

//重命名队列数据元素类型
typedef BTNode* QueueDataType;

//定义结构体类型(队列节点(单链表节点))
typedef struct QueueNode
{
	QueueDataType data;
	struct QueueNode* next;
} QueueNode;

//定义结构体类型(双端链表实现队列)
typedef struct Queue
{
	size_t size;
	QueueNode* head;
	QueueNode* tail;
} Queue;

//初始化队列
void Init_Queue(Queue* ptr);

//向队列尾部插入元素
void Push_Queue(Queue* ptr, QueueDataType data);

//从首端弹出元素
void Pop_Queue(Queue* ptr);

//获取队列的首端元素数据
QueueDataType Front_Queue(Queue* ptr);

//获取队列的尾部元素数据
QueueDataType Back_Queue(Queue* ptr);

//判断队列是否为空队列
bool Empty_Queue(Queue* ptr);

//获取队列中的元素个数
size_t Size_Queue(Queue* ptr);

//销毁队列
void Destroy_Queue(Queue* ptr);