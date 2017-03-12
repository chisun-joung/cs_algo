#include <stdio.h>
#include <malloc.h>
#include <limits.h>

#include "heap.h"

/*--------------------------------------------------------------------------------------
Function name	: createHeap() - �� ���� �Լ�
Parameters		: hPtr - �� ����ü�� �ּ�
				  size - ���� ũ��(���尡���� �������� ����)
Returns			: ���� �����ϸ� TRUE, �����ϸ� FALSE ����
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
	return TRUE;  // ���ϰ��� �����ϼ���.
}
/*--------------------------------------------------------------------------------------
Function name	: printHeape() - �� ���� ������ ��� (����->���� ����)
Parameters		: hPtr - �� ����ü�� �ּ�
Returns			: ����
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
Function name	: destroyHeap() - �� �Ҹ� �Լ�
Parameters		: hPtr - �� ����ü�� �ּ�
Returns			: ����
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
Function name	: deleteDownHeap() - ������ ������ �ϳ��� ����
Parameters		: hPtr - �� ����ü�� �ּ�
				  getData - ���� ���� ������ ���庯���� �ּ�
Returns			: ���������� �����ϸ� TRUE ����, �����ϸ� FALSE ����
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
Function name	: downHeap() - ���� ��带 ��ġ�� �°� down ��Ŵ
Parameters		: hPtr - �� ����ü�� �ּ�
				  position - �ϰ�(down heap)��ų �������� ��ġ
Returns			: ����
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
Function name	: isHeapEmpty() - ���� ������ ����ִ°� �˻�
Parameters		: hPtr - �� ����ü�� �ּ�
Returns			: ������ ��������� TRUE ����, ������� ������ FALSE ����
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
Function name	: isHeapFull() - ���� ���� �ִ°� �˻�
Parameters		: hPtr - �� ����ü�� �ּ�
Returns			: �� �� ������ TRUE ����, �� �� ���� ������ FALSE ����
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
