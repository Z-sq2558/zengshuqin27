#include<stdio.h>
#include<string.h>
#include"linkstack.h"

int main(){
	LinkStack *s=InitStack();
	Push(s,80);
	Push(s,90);
	Pop(s);
	Push(s,70);
	printf("第一个实验的数值为:%d",GetTop(s));
	printf("\n");
	linkstack();
}
