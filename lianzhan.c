#include<stdio.h>
#include<stdbool.h>
#include<malloc.h>

typedef int elementype;

typedef struct node{
	elementype data;
	struct node *next;
}stacknode, *linkstackptr;

typedef struct stack{
	linkstackptr top;
	int count;
}Linkstack;

/*若栈S为空栈，则返回TRUE,否则返回FALSE*/
 int stackempty(Linkstack S)
 {
     if(S.count==0)
          return 1;
     else
	   return 0;
}
bool push(Linkstack*S,elementype e)
{
  linkstackptr s=(linkstackptr)malloc(sizeof(stacknode));
  s->data=e;
  s->next=S->top;
  S->top=s;
  S->count++;
  return true;
}

int pop(Linkstack *s,elementype *e)
{
   linkstackptr p;
   if(stackempty(*s))
      return 0;
   else
  {
    *e=s->top->data;
    p=s->top;
    s->top=s->top->next;
    free(p);
    s->count--;
    return 1;
   }
}

void visit(elementype p)
{
  printf("%d",p);
}

bool traversestack(Linkstack s)
{
   linkstackptr p;
   p=s.top;
   while(p)
   {
      visit(p->data);
      p=p->next;
    }
    printf("\n");
    return true;
}

/* 构造一个空栈S */
bool lnitStack(Linkstack *S)
{
   S->top=(linkstackptr)malloc(sizeof(stacknode));
   if(!S->top)
	return false;
   S->top=NULL;
   S->count=0;
   return true;
}

bool ClearStack(Linkstack *S)
{
    linkstackptr p,q;
    p=S->top;
    while(p)
    {
	q=p;
	p=p->next;
	free(q);
     }
     S->count=0;
     return true;
}

int StackLength(Linkstack S)
{
    return S.count;
}

int GetTop(Linkstack S,elementype *e)
{
    if(S.top==NULL)
	    return 0;
    else
	    *e=S.top->data;
    return 1;
}

int main()
{
    int j;
    Linkstack s;
    int e;
    if(lnitStack(&s)==true)
	   for(j=1;j<=10;j++)
                push(&s,j);
    printf("栈中元素依次为：");
    traversestack(s);
    pop(&s,&e);
    printf("弹出的栈顶元素e=%d\n",e);
    printf("栈空否:%d(1:空 0:否)\n",stackempty(s));
    GetTop(s,&e);
    printf("栈顶元素e=%d栈的长度为%d\n",e,StackLength(s));
    ClearStack(&s);
    printf("清空栈后,栈空否: %d(1:空 0:否)\n",stackempty(s));

    return 0;
}




   
