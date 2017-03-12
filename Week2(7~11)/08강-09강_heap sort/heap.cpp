#include <stdio.h>
#include <malloc.h>
#include <limits.h>

#include "heap.h"

/*--------------------------------------------------------------------------------------
Function name	: createHeap() - 힙 생성 함수
Parameters		: hPtr - 힙 구조체의 주소
				  size - 힙의 크기(저장가능한 데이터의 개수)
Returns			: 생성 성공하면 TRUE, 실패하면 FALSE 리턴
--------------------------------------------------------------------------------------*/
BOOL createHeap(Heap *hPtr , int size)
{
	if(hPtr == NULL)
        return FALSE;
    hPtr->heap = (int *)calloc(size+1,sizeof(int));
    if(hPtr->heap==NULL)
        return FALSE;
    hPtr->hSize = size;
    hPtr->count = 0;
    hPtr->heap[0] = INT_MAX;
	return TRUE;  // 리턴값은 수정하세요.
}
/*--------------------------------------------------------------------------------------
Function name	: printHeape() - 힙 내의 데이터 출력 (상위->하위 방항)
Parameters		: hPtr - 힙 구조체의 주소
Returns			: 없음
--------------------------------------------------------------------------------------*/
void printHeap(const Heap * hPtr)
{
    int i;
    if(hPtr==NULL)
        return;

    for(i=1; i <= hPtr->count; ++i)
    {
        printf("%3d", hPtr->heap[i]);
    }
    printf("\n");
}
/*--------------------------------------------------------------------------------------
Function name	: destroyHeap() - 힙 소멸 함수
Parameters		: hPtr - 힙 구조체의 주소
Returns			: 없음
--------------------------------------------------------------------------------------*/
void destroyHeap(Heap *hPtr)
{
	if(hPtr == NULL)
        return;
    if(hPtr->heap != NULL)
        free(hPtr->heap);
    hPtr->heap = NULL;
    hPtr->hSize = 0;
    hPtr->count = 0;
}

/*--------------------------------------------------------------------------------------
Function name	: deleteDownHeap() - 힙에서 데이터 하나를 삭제
Parameters		: hPtr - 힙 구조체의 주소
				  getData - 힙에 꺼낸 데이터 저장변수의 주소
Returns			: 성공적으로 삭제하면 TRUE 리턴, 실패하면 FALSE 리턴
--------------------------------------------------------------------------------------*/
BOOL deleteDownHeap(Heap * hPtr, int * getData)
{
	if(hPtr == NULL)
        return FALSE;
    if(isHeapEmpty(hPtr))
        return FALSE;
    *getData = hPtr->heap[1];
    hPtr->heap[1] = hPtr->heap[hPtr->count];
    hPtr->heap[hPtr->count] = INT_MIN;
    --hPtr->count;

    downHeap(hPtr,1);
	return TRUE;
}
/*--------------------------------------------------------------------------------------
Function name	: downHeap() - 지정 노드를 위치에 맞게 down 시킴
Parameters		: hPtr - 힙 구조체의 주소
				  position - 하강(down heap)시킬 데이터의 위치
Returns			: 없음
--------------------------------------------------------------------------------------*/
void downHeap(Heap *hPtr, int position)
{
	int childPosition;
	int downData;

	if(hPtr == NULL)
        return;

    downData = hPtr->heap[position];

    while(position <= hPtr->count / 2)
    {
        childPosition = position << 1;
        if(hPtr->heap[childPosition] < hPtr->heap[childPosition + 1])
        {
            ++childPosition;
        }
        if(downData >= hPtr->heap[childPosition])
            break;
        hPtr->heap[position] = hPtr->heap[childPosition];
        position = childPosition;

    }
    hPtr->heap[position] = downData;
}

/*--------------------------------------------------------------------------------------
Function name	: isHeapEmpty() - 힙이 완전히 비어있는가 검사
Parameters		: hPtr - 힙 구조체의 주소
Returns			: 완전히 비어있으면 TRUE 리턴, 비어있지 않으면 FALSE 리턴
--------------------------------------------------------------------------------------*/
BOOL isHeapEmpty(Heap *hPtr)
{
    if(hPtr==NULL)
        return FALSE;
    if(hPtr->count == 0)
        return TRUE;
    else
        return FALSE;
}
/*--------------------------------------------------------------------------------------
Function name	: isHeapFull() - 힙이 꽉차 있는가 검사
Parameters		: hPtr - 힙 구조체의 주소
Returns			: 꽉 차 있으면 TRUE 리턴, 꽉 차 있지 않으면 FALSE 리턴
--------------------------------------------------------------------------------------*/
BOOL isHeapFull(Heap *hPtr)
{
	if(hPtr == NULL)
        return FALSE;
    if(hPtr->count == hPtr->hSize)
        return TRUE;
    else
        return FALSE;
}
