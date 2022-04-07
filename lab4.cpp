//#include<stdio.h>
//#include<stdlib.h>
//#define maxsize[20];
//
//void create();
//void display();
//void insert_begin();
//void selection_sort();
//
//struct mobile
//
//{
//	char=model[20];
//	char=brand_name[50];
//	int=memory_capacity;
//	float=price;
//};
//int main()
//{
//	int choice;
//	while(1)
//	{
//	}
//}



#include<stdio.h>
#include<stdlib.h>
#define size 20

void insert();
void display();
void sort_brand();
void sort_price();

struct mobile
{
char model_name[size];
char brand_name[size];
int mem_cap;
float price;
struct mobile *link;
};

int main()
{
struct mobile *temp, *ptr;
int choice;
while(1)
{
printf("\n1. Add mobile detail\n");
printf("\n2. display details");
printf("\n3. sort the list based on brands and display details");
printf("\n4. sort the list based on price display details");
printf("\n5. Exit\n");
printf("\nEnter your choice: ");
scanf("%d", &choice);
switch(choice)
{
int i;
case 1: ptr =(struct mobile *)malloc(5*sizeof(struct mobile));
for(i=0;i<5; i++)
{
printf("\n Enter the Model Name: ");
scanf("%s", &(ptr + i)->model_name);
printf("\n Enter the brand name: ");
scanf("%s", &(ptr + i)->brand_name);
printf("\n Enter the memory size: ");
scanf("%d", &(ptr + i)->mem_cap);
printf("\n Enter the price: ");
scanf("%f", &(ptr + i)->price);
}
break;
case 2:
for(i=0;i<5; i++)
{
printf("Model Name\t:%s\t\n", (ptr + i)->model_name);
printf("brand name\t:%s\t\n", (ptr + i)->brand_name);
printf("memory capacity\t:%d\t\n", (ptr + i)->mem_cap);
printf("price\t:%.2f\t\n", (ptr + i)->price);
printf("\n\n\n");
}
break;
// case 3: sort_brand();
//
// break;
// case 4: sort_price();
// break;
case 5: exit(1);
break;
default:printf("\n Invalid input!!!\n");
break;
}
}

return 0;
}

