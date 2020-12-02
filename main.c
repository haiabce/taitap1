#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#define MAX 20
#define MAX_LEGAL_INDEX 19
#define MIN_LEGAL_INDEX 0

#define MAX_LEGAL_VALUE 100
#define MIN_LEGAL_VALUE 0

#define NO_ERROR 0X01

#define ILLEGAL_VALUE 0X10
#define VALUE_EXISTED 0X11

#define ILLEGAL_INDEX 0X20
#define INDEX_EXISTED 0X21


uint8_t assignment3[MAX] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,\
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
	
uint8_t NextIndex[MAX] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,\
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
	
uint8_t head = 0xFF;
uint8_t next = 0xFF;
/*****************************************************************************
Ham hien thi huong dan su dung
- Input: Void
- Output: Void
*****************************************************************************/
void Init()
{
    printf("Chuong trinh quan ly sinh vien bang linked list\n");
    printf("Nhap 'a': Them du lieu cua mot sinh vien\n");
    printf("Nhap 'r': Xoa du lieu cua mot sinh vien theo ID\n");
    printf("Nhap 'f': Tim kiem sinh vien theo ID\n");
    printf("Nhap 'p': In danh sach sinh vien hien tai\n");
    printf("Nhap 'e': thoat chuong trinh\n");
}
/*****************************************************************************/


void AddData( uint8_t* mang)
{
	int32_t temp = -1;
	int8_t index = -1;
	int8_t data = -1;
	do
	{
		printf("Nhap vao vi tri can them, 0 <= vi tri <= 20: \n");
		fflush(stdin);
		scanf("%d", &temp);
		if(temp < 0 || temp > 20)
		{
			printf("Gia tri khong hop le!\n");
		}
		else
		{
			index = (int8_t)temp;
		}
	}
	while(temp < 0 || temp > 20);
	printf("mang[%d] = %d\n", index, data);
	do
	{
		printf("Nhap vao gia tri can them, 0 <= gia tri <= 100: \n");
		//fflush(stdin);
		scanf("%d", &temp);
		if(temp < 0 || temp > 100)
		{
			printf("Gia tri khong hop le!\n");
		}
		else
		{
			data = (int8_t)temp;
		}
	}
	while(data < 0 || data > 100);
	
	printf("mang[%d] = %d\n", index, data);
	mang[index] = data;
}

bool checkExistIndex(uint8_t index)
{
	bool isExist = false;
	uint8_t i = 0;
	for(i=0 ; i<MAX ; i++)
	{
		if(NextIndex[i] == index)
		{
			isExist = true;
		}
	}
	return isExist;
	
}

bool checkExistValue(uint8_t value)
{
	bool isExist = false;
	uint8_t i = 0;
	for(i=0 ; i<MAX ; i++)
	{
		if(assignment3[i] == value)
		{
			isExist = true;
		}
	}
	return isExist;
}


uint8_t CheckIndex(int8_t index)
{
	uint8_t resultCode = 0;

	if ((index < MIN_LEGAL_INDEX) || (index > MAX_LEGAL_INDEX))
	{
		resultCode = ILLEGAL_INDEX;
	}
	else if (checkExistIndex(index) == true)
	{
		resultCode = INDEX_EXISTED;
	}
	else
	{
		resultCode = NO_ERROR;
	}

	return resultCode;
}

uint8_t CheckValue(int8_t value)
{
	uint8_t resultCode = 0;

	if ((value < MIN_LEGAL_VALUE) || (value > MAX_LEGAL_VALUE))
	{
		resultCode = ILLEGAL_INDEX;
	}
	else if (checkExistValue(value) == true)
	{
		resultCode = VALUE_EXISTED;
	}
	else
	{
		resultCode = NO_ERROR;
	}

	return resultCode;
}

void swap(uint8_t *num1, uint8_t *num2)
{
	uint8_t temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}

uint8_t deleteElement(uint8_t value)
{
	uint8_t i;
	for
}

uint8_t AddElement(uint8_t index, uint8_t value)
{
	bool sorted = false;
	uint8_t tempNext = next;
	uint8_t prev = tempNext;
	uint8_t resultCode = 0;
	if(CheckIndex(index) != NO_ERROR)
	{
		resultCode = CheckIndex(index);
	}
	else if(CheckValue(value) != NO_ERROR)
	{
		resultCode = CheckValue(value);
	}
	else /*There's no error*///NextIndex[]
	{
		assignment3[index] = value;
		/*Mang rong, them vao phan tu dau tien*/
		if(head == 0xFF)
		{
			head = index;
			resultCode = NO_ERROR;
		}
		/*Mang da co 1 phan tu, them vao phan tu thu 2*/
		else if(tempNext == 0xFF)
		{
			/*Neu gia tri moi them vao lon hon gia tri dau tien*/
			if(assignment3[index] > assignment3[head])
			{
				NextIndex[head] = index;
				next = index;
			}
			else
			{
				next = head;
				head = index;
				NextIndex[head] = tempNext;
			}
		}
		/*Them vao cac phan tu 3, 4, 5,...*/
		else
		{
			/*Neu gia tri moi them vao nho hon phan tu dau tien*/
			if(value < assignment3[head])
			{
				NextIndex[index] = head;
				head = index;
			}
			/*Neu khong thi*/
			else
			{
				for(tempNext = head ; (tempNext != 0xFF) && !sorted ; tempNext = NextIndex[tempNext])
				{
					if(value < assignment3[tempNext])
					{
						NextIndex[index] = tempNext;
						NextIndex[prev] = index;
						sorted = true;
					}
					else
					{
						prev = tempNext;
					}
				}
				if(sorted == false)
				{
					NextIndex[prev] = index;
				}
			}
		}
	}
	
	return resultCode;
}

uint8_t EnterIndex()
{
	int32_t temp;
	uint8_t index = 0;
	do
	{
		printf("Nhap vao vi tri can them, 0 <= vi tri <= 20: \n");
		fflush(stdin);
		scanf("%d", &temp);
		if(temp < 0 || temp > 19)
		{
			printf("Gia tri khong hop le!\n");
		}
		else
		{
			index = (int8_t)temp;
		}
	}
	while(temp < 0 || temp > 20);
	return index;
}


uint8_t EnterValue()
{
	int32_t temp;
	int8_t value = 0;
	do
	{
		printf("Nhap vao gia tri can them, 0 <= gia tri <= 100: \n");
		fflush(stdin);
		scanf("%d", &temp);
		if(temp < 0 || temp > 100)
		{
			printf("Gia tri khong hop le!\n");
		}
		else
		{
			value = (int8_t)temp;
		}
	}
	while(temp < 0 || temp > 100);
	
	return value;
}


void printWithSorting(void)
{
	uint8_t tempNext = next;
	
	printf("\n---------------------\n");
	if(head != 0xFF)
	{
		printf("\n%d\n", assignment3[head]);
	}
	tempNext = NextIndex[head];
	while(tempNext != 0xFF)
	{
		printf("\n%d\n", assignment3[tempNext]);
		tempNext = NextIndex[tempNext];
	}
	printf("\n---------------------\n");
}

void printWithoutSorting(void)
{
	uint8_t i;
	printf("\n-----------------------\n");
	for(i = 0 ; i<MAX ; i++)
	{
		if(assignment3[i] != 0xFF)
			printf("%d\n", assignment3[i]);
	}
	printf("\n-----------------------\n");
}



int main(int argc, char *argv[]) {
	int i;
	
	int8_t value = 0;
	int8_t index = 0;
	
	index = EnterIndex();
	value = EnterValue();
	i = AddElement(index, value);
	
	index = EnterIndex();
	value = EnterValue();
	i = AddElement(index, value);
	printAll();
	
	index = EnterIndex();
	value = EnterValue();
	i = AddElement(index, value);
	printAll();
	
	index = EnterIndex();
	value = EnterValue();
	i = AddElement(index, value);
	printAll();
	
	index = EnterIndex();
	value = EnterValue();
	i = AddElement(index, value);
	printAll();
	

	
	
	return 0;
}

