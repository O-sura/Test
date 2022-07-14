#include <stdio.h>
#include <stdlib.h>

int arr[] = {10,23,4,56,3,67,89,12};
int *arrPtr;
int len = sizeof(arr)/sizeof(arr[0]);

void copyArray();
void printArray();
void deleteElement();
void updateElement();
void mergeArrays(int ptr1[],int ptr2[]);

void main(){

//printArray();
//copyArray(arrPtr,arr);
//deleteElement();
//updateElement();
int hello[] = {11,89,73,29,80,50};
mergeArrays(hello,arr);
return 0;
}

void copyArray(int *ptr,int *arr){
    if(arr == NULL)
        printf("Invalid parameters\n");
    else
    {
        ptr = (int *)malloc(sizeof(int)*len);
        for(int i = 0;i<len;i++){
            ptr[i] = arr[i];
        }
        printf("Elements from the new array\n");
        for(int i = 0;i<len;i++){
            printf("Element %d: %d\n",i+1,ptr[i]);
        }
        printf("\n");

    }
}

void printArray(){
    int i;
    for(i = 0;i<len;i++){
        printf("Element %d: %d\n",i+1,arr[i]);
    }
    printf("\n");
}

void deleteElement(){
    int index,i = 0;
    printf("Enter the element number to delete: ");
    scanf("%d",&index);
    if(index < 0 || index > len){
        printf("Invalid Index\n");
    }
    else{
        for(i = index - 1; i < len;i++){
            arr[i] = arr[i+1];
        }
        len--;
        printf("Successfully Deleted\n");
        printArray();
    }

}

void updateElement(){
    int index,val,i = 0;
    printf("Enter the element number to update: ");
    scanf("%d",&index);
    if(index < 0 || index > len){
        printf("Invalid Index\n");
    }
    else{
        printf("Enter the new value: ");
        scanf("%d",&val);
        arr[index - 1] = val;
        printf("Successfully Updated\n");
        printArray();
    }

}

void mergeArrays(int ptr1[],int ptr2[]){
    if(ptr1 == NULL || ptr2 == NULL)
        printf("Invalid arguments\n");
    else{
        int l1 = sizeof(ptr1);
        int l2 = sizeof(ptr2);
        printf("%d",(l1+l2));
        int *newArr = (int *)malloc(sizeof(int)*(l1+l2));
        int i,j,k;
        i = j = k = 0;
        while(i < l1 && j < l2){
            if(ptr1[i] < ptr2[j]){
                newArr[k] = ptr1[i];
                k++;
                i++;
            }
            else{
                newArr[k] = ptr2[j];
                k++;
                j++;
            }
        }
        if(i < l1 || j < l2){
            if(i < l1){
                while( i < l1){
                    newArr[k] = ptr1[i];
                    i++;
                    k++;
                }
            }
            else{
               while( j < l2){
                    newArr[k] = ptr2[j];
                    j++;
                    k++;
                }
            }
         }
            printf("New Merged Array(Sorted)\n");
            for(int l = 0;l<(l1+l2);l++){
                printf("Element %d: %d\n",l+1,newArr[l]);
            }
            printf("\n");
        }
}
