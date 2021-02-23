/*You are given a string s, return the number of segments in the string. */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int countSegments(char* s){
	if (s==NULL)
		return 0;
	int count=0;
	char *p;
	p=strtok(s," ");
	while(1){
		if(p==NULL)
			break;
		p=strtok(NULL," ");
		count++;
	}
	return count;
}
int main(){
	char s[100];
	printf("\nEnter string:");
	scanf("%[^\n]",s);
	printf("\n%d",countSegments(s));
	return 0;
}
