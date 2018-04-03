#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100
int check_matching(char data[], int start, int last);
void inFile(char filename[]);
void result(int state);
void error(char str[]);
typedef char Element;
Element data[MAX_STACK_SIZE];

int top;
void init_stack() { top = -1; }
int is_empty() { return top == -1; }
int is_full() { return top == MAX_STACK_SIZE - 1; }
int size() { return top + 1; }

void error(char str[])
{
	printf("%s\n", str);
	exit(1);
}
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

void inFile(char filename[]) { //파일의 문자열들을 배열에 저장하는 함수
	char ch;
	char expr[1000];
	int index = 0;
	int start = 0;

	FILE *in;
	in = fopen(filename, "rt");
	if (in == NULL) {
		printf("%s file open error!\n", filename);
		exit(1);
	}
	while ((ch = fgetc(in)) != EOF) {
		expr[index] = ch;
		index++;
		printf("%c", ch);
		if (ch == ' ') {//파일의 문자열들을 space(공백)으로 구분하여, 새로운 문자열 등장마다 괄호검사를 호출 
			result(check_matching(expr, start, index));  //괄호검사 함수 호출  parameter->(배열, 인덱스 시작값, 인덱스 마지막값) 
			start = index;		//괄호검사가 끝나면 위치를 바꿔줌
		}
		
	}
}

int check_matching(char data[],int start, int last) //괄호 검사 함수  안건들였음
{
	int i = start;
	int  prev;
	char ch;
	
	init_stack();

	for (i; i < last; i++) {
		ch = data[i];
		if (ch == '[' || ch == '(' || ch == '{')
			push(ch);
		else if (ch == ']' || ch == ')' || ch == '}') {
			if (is_empty()) 
				return 2;
			prev = pop();
			if ((ch == ']'&&prev != '[') || (ch == ')'&&prev != '(') || (ch == '}'&&prev != '{')) {
				return 3;
			}
		}
	} 
	if(is_empty()) 
		return 1;

	return 0;
}

void result(int state) { //정상, 오류 결과 출력 함수
	if (state == 0) {
		printf(": 정상\n");
	}
	else {
		printf(": 규칙 %d위반\n", state);
	}
}
void main()
{
	inFile("lab3.txt");
}
