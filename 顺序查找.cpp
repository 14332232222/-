#include<stdio.h>
#include<iostream>
using namespace std;
#define NUM 8

int source[NUM + 1] = { 69,65,90,37,92,6,28,54 };

int SeqSearch(int s[], int n, int key)
{
    int i;
    for (i = 0; s[i] != key; i++);
    if (i < n)
        return i;
    else
        return -1;
}

int main()
{
    int key, pos;

    printf("ԭ����Ϊ��");
    for (int i = 0; i < NUM; i++)
        printf("%d ", source[i]);
    printf("\n");

    printf("������ؼ��֣�");
    cin >> key;
    source[NUM] = key;        //����key�����һ��Ԫ��
    pos = SeqSearch(source, NUM, key);

    if (pos >= 0)
        printf("���ҳɹ����ڵ�%dλ�ã�\n", pos + 1);
    else
        printf("����ʧ�ܣ�");
    return 0;

}
