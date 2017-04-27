//============================================================================
// Name        : huffman.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <stdio.h>
#define MAX_CNT 100
char tree[MAX_CNT+1];  // 물건의 무게를 저장하는 배열(0번방 사용 안함)
char code[MAX_CNT+1];
int k;
void initTree();

int main()
{
	FILE *fp;
	char c;
	int j = 0;
	int index = 1;
	fp=fopen("d:\\data\\huffman.txt", "rt");
	if(fp == NULL) return -1;
	while(1){
		fscanf(fp,"%d\n",&k);
		if(k == 0) break;

		for(int i = 0 ; i < k ; i++){

			fscanf(fp,"%c",&c);

			fscanf(fp,"%s\n",code);
            index = 1;
            j = 0;
			while(code[j]!='\0'){
				if(code[j] == '0') index = index *2;
				if(code[j] == '1') index = index*2 +1;
				j++;
			}
			tree[index] = c;
		}

		fscanf(fp,"%s\n",code);
		j = 0;
		index=1;
		while(code[j]!='\0'){
			if(code[j] == '0') index = index *2;
			if(code[j] == '1') index = index *2 + 1;
			if(tree[index] != 0){
				printf("%c",tree[index]);
				index = 1;
			}
			j++;
		}
		printf("\n---------------------\n");
		initTree();

	}
	getchar();
	fclose(fp);
	return 0;
}

void initTree()
{
	for(int i=0; i< MAX_CNT+1;i++){
		tree[i] = 0;
		code[i] =0;
	}

}


//#include <stdio.h>
//#include<string.h>
//char str, strvalue[30], data[300], tree[1000000];
//
//int main()
//{
//	FILE *fp;
//	int k;
//	if((fp=fopen("d:\\data\\huffman.txt","rt")) == NULL)
//		return 0;
//
//	while(1){
//		memset(tree, 0, 1000000);
//		fscanf(fp, "%d", &k);
//		if(!k)
//			break;
//		for(int i=1; i<=k; i++){
//			fscanf(fp,"\n%c %s", &str, strvalue);
//			printf("%c %s\n", str, strvalue);
//			int idx=1;
//			for(int i=0; strvalue[i]!='\0'; i++)
//			{
//				if(strvalue[i]=='0') idx=idx*2;
//				else idx=idx*2+1;
//			}
//			tree[idx]=str;
//		}
//		fscanf(fp, "\n%s", data);
//		printf("%s %c\n", data, tree[36]);
//
//		int idx=1;
//		for(int i=0; data[i]!='\0'; i++)
//		{
//			if(data[i]=='0') idx=2*idx;
//			else idx=2*idx+1;
//			if(tree[idx]!=0)
//			{
//				printf("%c",tree[idx]);
//				idx=1;
//			}
//		}
//		printf("\n\n");
//	}
//	fclose(fp);
//	getchar();
//	return 0;
//}
