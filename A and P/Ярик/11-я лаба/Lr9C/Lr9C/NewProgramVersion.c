#pragma warning(disable : 4996) ;
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>

#define clear() system("cls")

typedef struct {
    int id;
    char name[40];
    char surname[40];
    int birth_date;
    int stud_date;
    struct  {
        int fiz;
        int math;
        int it;
        int history;
    } marks;
} STudent;

const int SizeStudent = sizeof(STudent);

int create_file(FILE* f); //������ � ����
int sort_file(FILE* f); //���������� �����
int print_file(FILE* f); //����� �����
int getNewSelector(int selector, char c);
void MenuSelect(int selector, FILE* f);
void printINFO(STudent d);
char Menu[][30] = { "������ � ����","���������� �����","����� �����","�����" };

int main() {
    char c;  SetConsoleCP(1251); // ������ ������� �������� ��� �������.
    SetConsoleOutputCP(1251);
    //�������� ������������� ����� ��� ������ � ������ � �����
    FILE* f = fopen("data.dat", "rb+");
    if (!f) {
        //�������� ������ ����� ��� ����������
        f = fopen("data.dat", "wb+");
        if (!f) {
            puts("�� ���� ������� (�������) ����\n");
            return 1;
        }
    }
    //����� ���� � ������ ��������������� �������
    int selector = 1;
    while (1) {
        clear(); 
        puts("_____________________________________________");
        for (int i = 0; i < 4; i++) 
        {
            if (i + 1 == selector) printf("-->  %s\n", Menu[i]);
            else   printf("%s\n", Menu[i]);
        }
        puts("_____________________________________________");
        puts("������������ ��������� , enter - �������\n");
        c = getch(); 
        selector = getNewSelector(selector,c,4);
        if (c == 13) {
            if (selector == 4) return 0;
            MenuSelect(selector, f);
        }
        
    }
}

int getNewSelector(int selector,char c, int selectMax)
{
    switch (c)
    {
    case 72://�����
        if (selector > 1) selector--;
        break;
    case 80://����
        if (selector < selectMax) selector++;
        break;
    }
    return selector;
}

void MenuSelect(int selector, FILE *f) 
{
    switch (selector) {
    case 1:
        create_file(f);
        break;
    case 2:
        sort_file(f);
        break;
    case 3:
        print_file(f);
        break;
    }
}

void printINFO(STudent d) 
{

    printf("������ �����     --> %d\n", d.id);
    printf("�������          --> %s\n", d.surname);
    printf("���              --> %s\n", d.name);
    printf("��� ��������     --> %d\n", d.birth_date);
    printf("��� �����������  --> %d\n", d.YerStud);
    puts("--------------------������--------------------");
    printf("\t ������           --> %d\n", d.marks.fiz);
    printf("\t ����������       --> %d\n", d.marks.math);
    printf("\t ���������������� --> %d\n", d.marks.it);
    printf("\t �������          --> %d\n", d.marks.history);
    puts("----------------------------------------------");
}

int create_file(FILE* f) {
    STudent d;  clear();
    char Menu[][30] = { "�������� ������","�����" }; 
    int selector = 1;int flag = 0;
    fseek(f, 0, SEEK_END); //��������� � ����� �����

    while (1) {
        clear();
        puts("_____________________________________________");
        for (int i = 0; i < 2; i++)
        {
            if (i + 1 == selector) printf("-->  %s\n", Menu[i]);
            else   printf("%s\n", Menu[i]);
        }
        puts("_____________________________________________");
        if (flag) 
        {
            puts("-----------��������� ��������� ������-----------");
            printINFO(d);
            puts("------------------------------------------------");
        }
        puts("������������ ��������� , enter - �������\n");
        char c = getch();
        selector = getNewSelector(selector,c,2);
        if (c==13)
        switch (selector) {
        case 1:
             {
                puts("_________________________________________");
                printf("������ �����    -->"); scanf("%d", &d.id);
                printf("�������         -->"); scanf("%s", &d.surname);
                printf("���             -->"); scanf("%s", &d.name);
                printf("��� ��������    -->"); scanf("%d", &d.birth_date);
                printf("��� ����������� -->"); scanf("%d", &d.YerStud);
                puts("----------------������----------------");
                printf("������           -->"); scanf("%d", &d.marks.fiz);
                printf("����������       -->"); scanf("%d", &d.marks.math);
                printf("���������������� -->"); scanf("%d", &d.marks.it);
                printf("�������          -->"); scanf("%d", &d.marks.history);
                puts("--------------------------------------");
                fwrmathe(&d, SizeStudent, 1, f); flag = 1;
            }
            break;
        case 2:
            return 1;
        }
    }
}



int sort_file(FILE* f) {
    long i, j;  clear();
    STudent d1, d2;
    fseek(f, 0, SEEK_END); //��������� � �����
    long len = ftell(f) / SizeStudent;//���������� ���������� �������
    rewind(f); //��������� � ������
    //����������� ����������
    for (i = len - 1; i >= 1; i--)
        for (j = 0; j <= i - 1; j++) {
            fseek(f, j * SizeStudent, SEEK_SET); //��������� �� j-�� ������
            fread(&d1, SizeStudent, 1, f); //������ ������ j � d1
            fread(&d2, SizeStudent, 1, f); //������ ����. ������ � d2
            if (d1.id > d2.id) {
                //��������� �� 2 ���. �����
                fseek(f, (-2) * SizeStudent, SEEK_CUR);
                //����� ��������
                fwrmathe(&d2, SizeStudent, 1, f); //������� ���������� d2
                fwrmathe(&d1, SizeStudent, 1, f); // ����� ���������� d1
            }
        }
    puts("���������� ������� ���������");
    getch();
    return 0;
}


int print_file(FILE* f) {
    STudent d;  clear();
    int n; int Posid = 1;
    rewind(f); //��������� � ������ �����
    puts("________________ ���� ������ ��������� __________________");
    do {
        n = fread(&d, SizeStudent, 1, f);//������ ��������� �� �����
        if (n < 1) break; //���� n<1, �� ����� �����
        printf("���������� ����� --> %d\n", Posid);
        printINFO(d);
        puts("_________________________________________________________");
        Posid++;
    } while (1);
    puts("������� ����� �������");
    getch();
    return 0;
}


// ������ ���������: CTRL+F5 ��� ���� "�������" > "������ ��� �������"
// ������� ���������: F5 ��� ���� "�������" > "��������� �������"

// ������ �� ������ ������ 
//   1. � ���� ������������ ������� ����� ��������� ����� � ��������� ���.
//   2. � ���� Team Explorer ����� ������������ � ������� ���������� ��������.
//   3. � ���� "�������� ������" ����� ������������� �������� ������ ������ � ������ ���������.
//   4. � ���� "������ ������" ����� ������������� ������.
//   5. ��������������� �������� ������ ���� "������" > "�������� ����� �������", ����� ������� ����� ����, ��� "������" > "�������� ������������ �������", ����� �������� � ������ ������������ ����� ����.
//   6. ����� ����� ������� ���� ������ �����, �������� ������ ���� "����" > "�������" > "������" � �������� SLN-����.
