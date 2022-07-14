#include <stdio.h>
#include <string.h>

union hellow{
    char name;
    int data;
};


int main(){

  union hellow n2;
  n2.name = 'A';
  printf("%c\t%d\n",n2.name,n2.data);

}
