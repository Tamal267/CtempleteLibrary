#include<stdio.h>
#include<string.h>

void strReverse(char str[]){
  int n = strlen(str);
  int i,j;
  for(int i=0,j=n-1;i<=j;i++,j--){
  	char temp = str[i];
	str[i] = str[j];
	str[j] = temp;
  }
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
  strReverse(result);
}

void compliment(char s[], int len,char comp[]){
	len-=2;
	int l = len+1;
	int ln = strlen(s) - 2;
	char a;
	while(len>=0){
		if(ln<0) comp[len] = '9';
		else comp[len] = (9 - (s[ln] - '0')) + '0';
		len--;
		ln--;
	}
	comp[l] = (10 - (s[strlen(s) - 1] - '0')) + '0' ;
	comp[l+1] = '\0';
}

void sub(char s1[], char s2[], char diff[]){
	int len = strlen(s1) > strlen(s2) ? strlen(s1) : strlen(s2);
	char comps2[len];
	compliment(s2,len,comps2);
	char add[len+2];
	addition(s1,comps2,add);
	int ln = strlen(add);
	if(ln>len){
		for(int i=1;add[i]!='\0';i++) diff[i-1] = add[i];
	}
	else{
		strcpy(diff,add);
		compliment(diff,ln,add);
		diff[0]='-';
		diff[1] = '\0';
		strcat(diff,add);
	}
}

int main(){
	char diff[100];
	char add[100];
	char s1[100]; 
	char s2[100];
	scanf("%s",s1);
	scanf("%s",s2);
	addition(s1,s2,add);
	printf("Addition of two numbers: %s\n",add);
	sub(s1,s2,diff);
	printf("Subtraction of two numbers: %s\n",diff);
}
