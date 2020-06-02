#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>
#include <Windows.h>

// IU4-21 Medvetsky Alexander (Variant 17) (5 var)

struct Student {
    char Zach_Number[7];
    char Surname[32];
    char Name[32];
    char Patronymic[32];
    char Faculty[8];
    char Speciality[64];
};
int main() {

    char Buffer[1024];
    int Choise;
    Choise = -1;
    FILE *Studentsread = fopen("students.csv", "r");
    if (Studentsread == NULL) {
        printf("���������� ������� ���� ���������");
    }
    else{
        int Number_of_Lines = 0;
        while(! feof(Studentsread)) {
            if (fgetc(Studentsread) == '\n') {
                Number_of_Lines++;
            }
        }
        Number_of_Lines++;
        fclose(Studentsread);
        struct Student *Students;
        Students = (struct Student*)malloc(sizeof(struct Student));
        int n = 0;
        Studentsread = fopen("students.csv", "r");
        for (n = 0; n < Number_of_Lines; n++){

            fgets(Buffer, 1024, Studentsread);
            strcpy(Students[n].Zach_Number, strtok(Buffer, ";"));
            strcpy(Students[n].Surname, strtok(NULL, ";"));
            strcpy(Students[n].Name, strtok(NULL, ";"));
            strcpy(Students[n].Patronymic, strtok(NULL, ";"));
            strcpy(Students[n].Faculty, strtok(NULL, ";"));
            strcpy(Students[n].Speciality, strtok(NULL, "\n"));
            Students=(struct Student*)realloc(Students, (n+2)*sizeof(struct Student));
        }
        fclose(Studentsread);
        SetConsoleCP(1251);
        SetConsoleOutputCP(1251);

        printf("��� �� ������ �������?\n");
        printf("1 - �������� ��������\n2 - ������� ��������\n3 - ������������� ���������� �� ��������\n4 - ���������� ���������� � ��������\n 0 - ��������� � �����\n");

        while(Choise == -1) {
            printf("��� �����:");
            scanf("%d", &Choise);
            if (Choise == 1) {	
                printf("�������� ������ ��������:\n������� ����� �������� ������:");
                char Zach_Number[7];
                scanf("%s", Zach_Number);
                int Error = 0;
                for(n = 0; n < Number_of_Lines; n++) {
                    if(strcmp(Zach_Number, Students[n].Zach_Number) == 0) {
                        printf("������� � ����� �������� ������� ��� ����������\n");
                        Error = 1;
                        break;
                    }
                }
                if (Error == 1) {
                    break;
                }
                else{
                    printf("������� �������:");
                    char Surname[32];
                    scanf("%s", Surname);

                    printf("������� ���:");
                    char Name[32];
                    scanf("%s", Name);

                    printf("������� ��������:");
                    char Patronymic[32];
                    scanf("%s", Patronymic);

                    printf("������� ���������:");
                    char Faculty[8];
                    scanf("%s", Faculty);

                    int k = 0;
                    char c;
                    c = getchar();
                    printf("������� �������������:");
                    char Speciality[64];
                    c = getchar();
                    while (c != '\n') {
                        Speciality[k++] = c;
                        c = getchar();
                    }
                    Speciality[k] = '\0';

                    Number_of_Lines++;
                    Students = (struct Student*)realloc(Students, (Number_of_Lines)*sizeof(struct Student));
                    strcpy(Students[Number_of_Lines-1].Zach_Number, Zach_Number);
                    strcpy(Students[Number_of_Lines-1].Surname, Surname);
                    strcpy(Students[Number_of_Lines-1].Name, Name);
                    strcpy(Students[Number_of_Lines-1].Patronymic, Patronymic);
                    strcpy(Students[Number_of_Lines-1].Faculty, Faculty);
                    strcpy(Students[Number_of_Lines-1].Speciality, Speciality);

                    printf("�������! \n ������� � ���� \n");
                }
                Choise = -1;
            }

            else if(Choise == 2) {
                printf("������� ����� �������� ������ ��� ��������:");
                char Zach_Number[7];
                SetConsoleCP(1251);
                scanf("%s", Zach_Number);

                printf("��� �����\n");
                int n = 0;
                int a = -1;
                for(n = 0; n < Number_of_Lines; n++) {
                    if(strcmp(Zach_Number, Students[n].Zach_Number) == 0) {
                        printf("������� ������\n");
                        a = n;
                        break;
                    }
                }
                if (a == -1) {
                    printf("������� �� ������, ������� � ����.\n");
                }

                if(a == n) {
                    strcpy(Students[a].Zach_Number, "NULL");

                    printf("������� �������!\n\n");
                }
                Choise = -1;
            }

            else if(Choise == 3) {
                printf("������� ����� ������� ����� �������� ������ ��� ��������� ����������:");
                char Zach_Number[7];
                SetConsoleCP(1251);
                scanf("%s", Zach_Number);
                int n = 0;
                int a = -1;
                for(n = 0; n < Number_of_Lines; n++) {
                    if(strcmp(Zach_Number, Students[n].Zach_Number) == 0) {
                        printf("������� ������.\n");
                        a = n;
                        break;
                    }
                }
                if (a == -1) {
                    printf("������� �� ������, ������� � ����.\n");
                }
                else {
                    printf("���������� � ��������:\n%s %s %s %s %s %s\n", Students[a].Zach_Number, Students[a].Surname, Students[a].Name, Students[a].Patronymic,Students[a].Faculty, Students[a].Speciality);

                    printf("������� �������:");
                    char Surname[32];
                    scanf("%s", Surname);

                    printf("������� ���:");
                    char Name[32];
                    scanf("%s", Name);

                    printf("������� ��������:");
                    char Patronymic[32];
                    scanf("%s", Patronymic);

                    printf("������� ���������:");
                    char Faculty[8];
                    scanf("%s", Faculty);

                    char c;
                    c = getchar();
                    printf("������� �������������:");
                    char Speciality[64];
                    int k = 0;
                    c = getchar();
                    while (c != '\n') {
                        Speciality[k++] = c;
                        c = getchar();
                    }
                    Speciality[k] = '\0';

                    strcpy(Students[a].Zach_Number, Zach_Number);
                    strcpy(Students[a].Surname, Surname);
                    strcpy(Students[a].Name, Name);
                    strcpy(Students[a].Patronymic, Patronymic);
                    strcpy(Students[a].Faculty, Faculty);
                    strcpy(Students[a].Speciality, Speciality);
                    printf("�������� ��������� �������, ������� � ����.\n");
                }
                Choise = -1;
            }
            else if(Choise == 4) {
                printf("������� ����� �������� ������, ����� ����������� ���������� � ��������:");
                char Zach_Number[7];
                SetConsoleCP(1251);
                scanf("%s", Zach_Number);
                int n = 0;
                int a = -1;
                for(n = 0; n < Number_of_Lines; n++) {
                    if(strcmp(Zach_Number, Students[n].Zach_Number) == 0) {
                        printf("������� ������.\n\n");
                        a = n;
                        break;
                    }
                }
                if (a == -1) {
                    printf("������� �� ������, ������� � ����.\n");
                }
                else{
                    printf("���������� � ��������:\n����� �������: %s\n�������: %s\n���: %s\n��������: %s\n���������: %s\n������������:%s\n",Students[a].Zach_Number, Students[a].Surname, Students[a].Name, Students[a].Patronymic,Students[a].Faculty, Students[a].Speciality);
                }
                Choise = -1;
            }
            if (Choise == 0) {
                printf("���������� ������\n");
                FILE *Studentsread = fopen("students.csv", "w");
                if (Studentsread == NULL) {
                    printf("���������� ������� ���� ���������");
                }
                else{
                    for(n = 0; n < Number_of_Lines; n++){
                        if (strcmp("NULL", Students[n].Zach_Number) != 0) {
                            fprintf(Studentsread, "%s;%s;%s;%s;%s;%s", Students[n].Zach_Number, Students[n].Surname, Students[n].Name, Students[n].Patronymic,Students[n].Faculty, Students[n].Speciality);
                            if(n != Number_of_Lines-1) {
                                fprintf(Studentsread,"\n");
                            }
                        }
                    }
                    fclose(Studentsread);
                    printf("��������� �������, ��������� ������.\n");
                }
                Choise = -1;

            }

        }
    }
    return 0;
}