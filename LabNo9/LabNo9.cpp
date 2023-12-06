// LabNo9.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <Windows.h>
using namespace std;

struct Student {
    char Name[100];
    char Group[100];
    int Ochenka;
};

float srball(Student a) {
    return (float) a.Ochenka / 3;
}

int main()
{
    setlocale(LC_ALL, "ru");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Student A[100];
    char d[100];
    int n;
    //a 1 2 b 1 8 c 2 3 d 2 7
    cout << "Введите количество студентво: ";
    cin >> n;
    if (n >= 1) {
        cin.getline(d, 100);
        for (int i = 0; i < n; i++) {
            cout << "Введите ФИО студента: ";
            cin.getline(A[i].Name, 100);
            cout << "Введите группу студента: ";
            cin.getline(A[i].Group, 100);
            cout << "Введите оценку студента: ";
            cin >> A[i].Ochenka;

            cin.getline(d, 100);
        }
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                Student t;
                if (strcmp(A[i].Name, A[j].Name) > 0) {
                    t = A[j];
                    A[j] = A[i];
                    A[i] = t;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            cout << "ФИО: " << A[i].Name << " Группа: " << A[i].Group << " Оценка по 3 предметам: " << A[i].Ochenka << endl;
        }
        char* group[100];
        char t[100];
        strcpy(t, A[0].Group);
        group[0] = (&A[0])->Group;
        int ik = 1;
        for (int i = 1; i < n; i++) {
            if (!(strcmp(t, A[i].Group) == 0)) {
                strcpy(t, A[i].Group);
                bool Flag = false;
                for (int j = 0; j < ik; j++) {
                    if (strcmp(t, group[j]) == 0) {
                        Flag = true;
                        break;
                    }
                }
                if (!Flag) {
                    group[ik] = (&A[i])->Group;
                    ik++;
                }
            }
        }
        int sth[100];
        int ikp = 0;
        for (int i = 0; i < ik; i++) {
            int s = 0;
            int yn = 0;
            for (int j = 0; j < n; j++) {
                if (strcmp(group[i], A[j].Group) == 0) {
                    s += A[j].Ochenka;
                    yn++;
                }
            }
            float srt = (float)s / yn;
            for (int j = 0; j < n; j++) {
                if (strcmp(group[i], A[j].Group) == 0) {
                    if (srball(A[j]) < srt) {
                        sth[ikp] = j;
                        ikp++;
                        break;
                    }
                }
            }
        }
        for (int i = 0; i < ikp; i++) {
            for (int j = i + 1; j < ikp; j++) {
                int t;
                if (sth[i] > sth[j]) {
                    t = sth[j];
                    sth[j] = sth[i];
                    sth[i] = t;
                }
            }
        }
        cout << endl;
        for (int i = 0; i < ikp; i++) {
            cout << "ФИО: " << A[sth[i]].Name << " Группа: " << A[sth[i]].Group << " Оценка по 3 предметам: " << A[sth[i]].Ochenka << endl;
        }
    }
    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
