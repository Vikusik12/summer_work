#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

void convert(char *string, char *digit)
{
  while(*string!='\0')
  {
    if(*string>='a' && *string<='c'|| (*string>='A' && *string<='C'))
    {
        *digit='2';
        digit++;
        string++;
        continue;
    }
        if(*string>='d' && *string<='f'|| (*string>='D' && *string<='F'))
    {
        *digit='3';
        digit++;
        string++;
        continue;
    }
        if(*string>='g' && *string<='i'|| (*string>='G' && *string<='I'))
    {
        *digit='4';
        digit++;
        string++;
        continue;
    }
        if(*string>='j' && *string<='l'|| (*string>='J' && *string<='L'))
    {
        *digit='5';
        digit++;
        string++;
        continue;
    }
        if(*string>='m' && *string<='o'|| (*string>='M' && *string<='O'))
    {
        *digit='6';
        digit++;
        string++;
        continue;
    }
        if(*string>='p' && *string<='s'|| (*string>='P' && *string<='S'))
    {
        *digit='7';
        digit++;
        string++;
        continue;
    }
        if(*string>='t' && *string<='v'|| (*string>='T' && *string<='V'))
    {
        *digit='8';
        digit++;
        string++;
        continue;
    }
        if(*string>='w' && *string<='z'|| (*string>='W' && *string<='Z'))
    {
        *digit='9';
        digit++;
        string++;
        continue;
    }
        if(*string=='+')
    {
        *digit='0';
        digit++;
        string++;
        continue;
    }
    else
    string++;
  }
 
}
int main(int argc, char *argv[])
{ 
    char name[100];
    char converted[100];
    char *point = argv[1];
    char number[100];
    bool flag = false;
    bool found= false;
    if(argc>2)
    {
        printf("Invalid argc");
        return -1;
    }
        if(argc == 1)
    {
        flag=true;
    }
    
   while(!feof(stdin))
   {
    fgets(name, 100, stdin);
    *(name + strlen(name) - 1) = '\0';
    fgets(number, 100, stdin);
    *(number + strlen(number) - 1) = '\0';
    if(flag)
    {
        printf("%s, %s\n", name, number);
        continue;
    }
    convert(name, converted);//converted 123456789 
   if (strstr(converted, point)) 
   {
     printf("%s, %s\n", name, number);
     found=true;
   }
   else if (strstr(number, point)) 
   {
       printf("%s, %s\n", name, number);
       found=true;
   }
   }
   if(!found)
   printf("Not found\n");
     return 0;
}
    //printf("%s ", number);
      //  if(atoi(name)!=0)
      //  {
      //    printf("\b, %s\n",name);  
      //   // sprintf(string, "\b, %s\n", name);
      //    //strcpy(string,string);
      //     //printf("%s", string);
      //  }
      //  else 
      //  printf("%s ",name);

      // sprintf(strin, "%s ", name);
     //  printf("%s", string);