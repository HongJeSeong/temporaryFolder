#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100
typedef char Element;

Element data[MAX_STACK_SIZE];
int top;
void error(char str[])
{
   printf("%s\n", str);
   exit(1);
}
void init_stack() { top = -1; }
int is_empty() { return top == -1; }
int is_full() { return top == MAX_STACK_SIZE - 1; }
int size() { return top + 1; }
void push(Element e)
{
   if (is_full())
      error("스택 포화에러");
   data[++top] = e;
}
Element pop()
{
   if (is_empty())
      error("스택 공백 에러");
   return data[top];
}
Element peek()
{
   if (is_empty())
      error("스택 공백에러");
   return data[top];
}
int check_matching(char filename[])
{
   int index = 0;
   int i = 0, prev;
   char ch;
   char expr[100000];
   init_stack();
   FILE *in;
   in = fopen(filename, "r");
   if (in == NULL) {
      printf("%s file open error!\n", filename);
      exit(1);
   }
   while ((ch = fgetc(in)) != EOF) {
      expr[index] = ch;
      index++;
   }

      
   while (expr[i] != '\0') {
      ch = expr[i++];
      if (ch == '[' || ch == '(' || ch == '}')
         push(ch);
      else if (ch==']'||ch==')'||ch=='}'){
         if (is_empty())
            return 2;
         prev = pop();
         if ((ch == ']'&&prev != '[') || (ch == ')'&&prev != '(') || (ch == '}'&&prev != '{')) {
            return 3;
         }
      }
   }
   if (is_empty() ==0) return 1;
   return 0;
}

void main()
{
   int errorcode, i;

   printf("%d",check_matching("lab3.txt"));
}
