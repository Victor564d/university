
#pragma warning(disable : 4996)
#include<stdio.h>
#include<windows.h> 

main()
{
	int a,b,error = 0;
	SetConsoleCP(1251); 
	SetConsoleOutputCP(1251);
	printf("\n Вводите целые числа, 0 остановит ввод");
	scanf("%d", &a);
	while (1) 
	{
		b = a;
		scanf("%d", &a);
		printf("\n");
		if (a == 0)  break; 
		if (b < a)  error = 1; 
	}
	if (error == 1) 
		printf("Нет");
	else 		
		printf("Да");

	return 0;
}
