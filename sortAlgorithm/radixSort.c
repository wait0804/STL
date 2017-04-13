#include<stdio.h>
#include<malloc.h>
 
void radixSort(int *a, int count);
void countSort(int *bitNumber, int count, int *newA, int *c, int *a);
void showArray(int *a, int count);
 
void showArray(int *a, int count){
    int i;
 
    for(i = 0; i < count; i++){
        printf("%d ", a[i]);    
    }
    printf("\n");
}
 
void countSort(int *bitNumber, int count, int *newA, int *c, int *a){
    int i;
 
    //�Ӹ�λ-->ʮλ-->��λ,ÿһ�ε����������,�����ռ䶼�����ʼ��Ϊ0;
    for(i = 0; i < 10; i++){
        c[i] = 0;
    }
 
    for(i = 0; i < count; i++){
        c[bitNumber[i]]++;
    }
 
    for(i = 1; i < 10; i++){
        c[i] += c[i-1];
    }
 
    for(i = count-1; i >= 0; i--){
        newA[c[bitNumber[i]]-1] = a[i];  //a[i]��ԭ����ȡ��λ˳��һ��
        c[bitNumber[i]]--;
    }
}
 
void radixSort(int *a, int count){
    int *bitNumber;
    int *newA;
    int c[10] = {0};
    int i;
 
    //��λ��������
    bitNumber = (int *)malloc(sizeof(int) * count);
    newA = (int *)malloc(sizeof(int) * count);
    for(i = 0; i < count; i++){
        bitNumber[i] = a[i]%10;
    }
    countSort(bitNumber, count, newA, c, a);  //bitNumber:����Ҫ�ŵ�����;newA:�����������е��¿ռ�
                                      // c:�������ռ� a:����ԭ������
    for(i = 0; i < count; i++){
        a[i] = newA[i];
    }
 
    //ʮλ��������
    for(i = 0; i < count; i++){
        bitNumber[i] = a[i]/10%10;
    }
    countSort(bitNumber, count, newA, c, a);                      
    for(i = 0; i < count; i++){
        a[i] = newA[i];
    }
 
    //��λ����
    for(i = 0; i < count; i++){
        bitNumber[i] = a[i]/100%10;
    }
    countSort(bitNumber, count, newA, c, a);  
                                      
    for(i = 0; i < count; i++){
        a[i] = newA[i];
    }
    //ǧλ����
    for(i = 0; i < count; i++){
        bitNumber[i] = a[i]/1000%10;
    }
    countSort(bitNumber, count, newA, c, a);  
                                      
    for(i = 0; i < count; i++){
        a[i] = newA[i];
    }
 
}
 
void main(void){
    int a[] = {23, 1000, 90, 34, 2, 6, 3, 444, 555, 666, 777, 888, 999, 111, 222};
    int count = sizeof(a)/sizeof(int);
    radixSort(a, count);
    showArray(a, count);
}