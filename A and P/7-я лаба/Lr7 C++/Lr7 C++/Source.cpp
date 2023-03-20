#pragma warning(disable : 4996) ;

#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

#define DESCENDING_SORT (0)
#define ASCENDING_SORT  (1)

typedef
struct clerk
{
    int
        num, exp;

    char
        name[32],
        surname[32],
        position[32],
        division[32];
    double
        salary;
}
clerk_t;
/* ������ ���������� */
void print_clerkOne(const clerk_t* e);
/* ������ ����������  � ����*/
void print_clerk(const clerk_t* e, int arr_len);
/* ���� ���������� */
clerk_t* scan_clerk(int arr_len);
/* ���������� �� ���� */
void sort_array(clerk_t* arr, int arr_len, int sort_order_flag);
/*
    ����� ������ � ������������ �������.
    ������� ������ ����� ������.
*/
static int search_element(clerk_t arr[], int arr_size, const char* division);



int main()
{
    clerk_t* mas;
    SetConsoleCP(1251); // ������ ������� �������� ��� �������.
    SetConsoleOutputCP(1251);
    int selector = 1;  int n = 0; mas = 0; // �������� - ����� ������, ��� -��� ������, ��� ��� �������� ��� 0
    while (selector != 0) //���� ���� , ������� �� ���� ��� ��� ����� 0
    {
        system("cls");
        cout<<("\n\n�������� ����������� ����� \n");
        cout << ("1 - ���� ������� � ���������� \n");
        if (n > 0) {
            cout << ("2 - ����� ������� �� ����� \n");
            cout << ("3 - ���������� �� ���� \n");
            cout << ("4 - ����� ������ � ������������ ������� \n");
        }
        cout << ("\n0 - �����\n\n");
        cin >> selector; //������� ��������
        switch (selector)  //����� ������� � ����������� �� ���������
        {
        case 1: {cout << ("\n ������� ������ ������� --> "); cin >> n; mas = scan_clerk(n); break; };  //����
        case 2: {print_clerk(mas, n); break;  }; //�����
        case 3: {int flag; cout << ("������� ���� ����������, 0 - �� ��������, 1 - �� ����������� -->"); cin >> flag; sort_array(mas, n, flag); break;  }; //������������� � �������
        case 4: {  char divis[32]; cout << ("������� ������������� � ������� ����� �������� ����� --> "); cin >> divis;
            int max_ock = search_element(mas, n, divis);
            if (max_ock != -1) {
                cout << "\n����� � ������������ �������(�����) -->  "<< max_ock<<endl;
                print_clerkOne(&mas[max_ock]);
            }
            else cout << ("\n�� ��������� ������� ���������/��� ����������� ������ ");
            cout << ("\a");
            getch();
            break; }; // ������������ �� ���������
        default:
            break;
        }
    }
    delete []mas;
    return 0;
}

/* ������ ���������� */
void print_clerkOne(const clerk_t* e)
{
    cout << ("�����:\r\n");
    cout << " *  ���������� �����: "<< e->num<< "\r"<<endl;
    cout << " *  �������:         "<< e->surname << "\r"<<endl;
    cout << " *  ���:             "<< e->name << "\r" << endl;
    cout << " *  ���������:       " <<e->position << "\r" << endl;
    cout << " *  ����:            " <<e->exp << "\r" << endl;
    cout << " *  �������������:   " <<e->division << "\r" << endl;
    cout << " *  �����:           "<< e->salary << "\r" << endl;
}

/* ������ ����������  � ���� */
void print_clerk(const clerk_t* e, int arr_len)
{
    for (int i = 0; i < arr_len; i++) { //���� ������ 
        print_clerkOne(&e[i]);
    }
    cout << ("\a"); // ���� ��������� ������ 
    getch(); //���� ���� ���� ����
}

/* ���� ���������� */
clerk_t* scan_clerk(int arr_len)
{
    clerk_t* e = new clerk_t[arr_len]; //��������� ������
    for (int i = 0; i < arr_len; i++) { //���� �����
        cout << ("���������� ���������� � �����:\r\n");
        cout << (" *  ������� �������:       "); scanf("%s", &e[i].surname);
        cout << (" *  ������� ���:           "); scanf("%s", e[i].name);
        cout << (" *  ������� ���������:     "); scanf("%s", e[i].position);
        cout << (" *  ������� ����(���):     "); scanf("%d", &e[i].exp);
        cout << (" *  ������� �������������: "); scanf("%s", e[i].division);
        cout << (" *  ������� �����:         "); scanf("%lf", &e[i].salary);
        e[i].num = i; //������ ������������� = ������ ��� �������� 
    }

    return e; //���������� ���������
}

/* ���������� �� ���� */
void sort_array(clerk_t* arr, int arr_len, int sort_order_flag)
{
    clerk_t tmp = { 0 };

    for (int i = arr_len - 1; i > 0; i--) // ���������� ������� �������� 
        for (int j = 0; j < i; j++)
            if (
                (sort_order_flag) ?
                (((arr[j]).salary) > ((arr[j + 1]).salary)) :   // ���� ���������� �� �����������
                ((arr[j]).salary) < ((arr[j + 1]).salary))     // ���� ���������� �� ��������

            {
                tmp = arr[j]; //��������� ����������
                arr[j] = arr[j + 1];// ������ ������� 
                arr[j + 1] = tmp;
            }

    // ����������� ���������� ���������� �������
    for (int i = 0; i < arr_len; i++)
        arr[i].num = i;
}

/*
    ����� ������ � ������������ �������.
    ������� ������ ����� ������.
*/
static int search_element(clerk_t arr[], int arr_size, const char* division)
{
    int max_salary_num = -1; //������ ��������� ���� ��� -1;

    for (int i = 0; i < arr_size; i++) //� ����� ������������� ���� ������ �������
        if (!strcmp(arr[i].division, division) && //���� ��������� ���������
            (
                (max_salary_num != -1) ? //��������� , ���� ���� �� ����� -1, �� ���������� ��������� ������������� ��������� � ������� ���������� 
                (arr[i].salary > arr[max_salary_num].salary) :
                (1) //����� ������� 1, �� �� ��������� ������ �������� � ������������ �������  
                )
            )
            max_salary_num = i; //���������� ������ � ������������ �������

    return max_salary_num; // ���������� ������������ ����� 
}
