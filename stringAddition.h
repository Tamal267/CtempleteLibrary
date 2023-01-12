/*
    This program is for string addition
    Function parameter: 3
    void addition(char *string1, char *string2, char *result)

*/
#include<stdio.h>
#include<string.h>
void reverse(char str[], int n){
  char s[n+1];
  int i;
  for(i=0;i<n;i++) s[i] = str[n-i-1];
  s[i] = '\0';
  strcpy(str,s);
}
void addition(char str1[], char str2[] , char result[]){
  int len1 = strlen(str1);
  int len2 = strlen(str2);
  int i = len1-1,j=len2-1,k=0,sum=0,carry=0;
  while(i>=0 || j>=0){
    if(i<0) sum = 48 + str2[j] - 2*48 + carry;
    else if(j<0) sum = str1[i] + 48 - 2*48 + carry;
    else sum = str1[i] + str2[j] - 2*48 + carry;
    carry=sum/10;
    sum%=10;
    result[k++] = sum + 48;
    i--;
    j--;
  }
  if(carry) result[k++]='1';
  result[k]='\0';
  reverse(result,strlen(result));
}
