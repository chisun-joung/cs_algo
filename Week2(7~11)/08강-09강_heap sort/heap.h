#pragma once 

enum BOOL {FALSE, TRUE};

typedef struct _heap { 
	int * heap;
	int hSize; 
	int count;  /* heap에 저장되어있는 데이터의 수 */
}Heap; 

BOOL createHeap(Heap *hPtr , int size);			/* 힙 생성 함수 */
void destroyHeap(Heap *hPtr);					/* 힙 소멸 함수 */
//BOOL insertUpHeap(Heap *hPtr, int inData);		/* 힙에 데이터 하나를 저장함 */
BOOL deleteDownHeap(Heap * hPtr, int * getData);	/* 힙에 데이터 하나를 삭제 */
void downHeap(Heap *hPtr, int position);		/* 지정 노드를 위치에 맞게 down 시킴 */
void printHeap(const Heap * hPtr);				/* 힙 내의 데이터 출력 (상위->하위 방항) */
BOOL isHeapEmpty(Heap *hPtr);					/* 힙이 완전히 비어있는가 검사 */
BOOL isHeapFull(Heap *hPtr);						/* 힙이 꽉차 있는가 검사 */
