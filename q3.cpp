/*Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
bool isValid(char* s) {
    if (NULL == s) {
        return true;
    }
    int len      = strlen(s);
    int      sp       = 0;
    char*    stack    = (char*)malloc(len);
    memset(stack, 0, len);
    
    for (int i=0; i<len; i++) {
        switch (s[i]) {
            case '(':
                stack[sp] = '(';
                sp++;
                break;
                
            case ')':
                if (sp < 1){
                    return false;
                }
                if (stack[sp-1] == '(') {
                    sp--;
                } else {
                    stack[sp] = ')';
                    sp++;
                }
                break;
                
            case '[':
                stack[sp] = '[';
                sp++;
                break;
                
            case ']':
                if (sp < 1){
                    return false;
                }
                if (stack[sp-1] == '[') {
                    sp--;
                } else {
                    stack[sp] = ']';
                    sp++;
                }
                break;
                
            case '{':
                stack[sp] = '{';
                sp++;
                break;
                
            case '}':
                if (sp < 1){
                    return false;
                }
                if (stack[sp-1] == '{') {
                    sp--;
                } else {
                    stack[sp] == '}';
                    sp++;
                }
                break;
        }
    }
    free(stack);
    stack = NULL;
    if (sp) {
        return false;
    } else {
        return true;
    }
}
int main(){
	int l;
	printf("Enter string length:");
	scanf("%d",&l);
	char s[l+1];
	printf("\nEnter string: ");
	scanf("%s",s);
	bool x=isValid(s);
	printf("%s",x?"true":"false");
	return 0;
}
