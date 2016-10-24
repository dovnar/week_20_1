#include <iostream>
using namespace std;

struct Student
{
	char* Surname;
	char* Group;
	int* Progress;
};

int const countStudent = 10;
int const countAppraisal = 5;

void enterStudent(Student* student);
void printExcellentStudents(Student* student);
void printPoorStudents(Student* student);

void main()
{
	Student* student = new Student[countStudent];
	for (int i = 0; i < countStudent; i++)
	{
		student[i].Surname = new char[256];
		student[i].Group = new char[256];
		student[i].Progress = new int[countAppraisal];
	}
	enterStudent(student);
	int menu = 0;
	do
	{
		cout << "exit: 0\nprint list of excellent students: 1\nprint list of poor students: 2\nenter: ";
		fflush(stdin);
		cin >> menu; 
		menu == 1 ? printExcellentStudents(student) : (menu == 2 ? printPoorStudents(student) : menu = 0);
	} while (menu != 0);
	for (int i = 0; i < countStudent; i++)
	{
		delete[] student[i].Surname;
		delete[] student[i].Group;
		delete[] student[i].Progress;
	}
	delete[] student;
}

void enterStudent(Student* student)
{
	for (int i = 0; i < countStudent; i++)
	{
		fflush(stdin);
		cout << "enter Surname: ";
		getchar();
		cin.getline(student[i].Surname ,countStudent); fflush(stdin);
		cout << "enter Group: ";
		getchar();
		cin.getline(student[i].Group ,countStudent); fflush(stdin);
		for (int j = 0; j < countAppraisal; j++)
		{
			cout << "enter Appraisal: ";
			cin >> student[i].Progress[j]; 
		}
	}
}

//Выводить список отличников (>75% отличных оценок); 
void printExcellentStudents(Student * student)
{
	cout << "print list of poor students :" << endl;
	int chekPrint = 0;
	for (int i = 0; i < countStudent; i++)
	{
		int countExcellentAppraisal = 0;
		for (int j = 0; j < countAppraisal; j++)
		{
			if (student[i].Progress[j] > 3)
			{
				countExcellentAppraisal++;
			}
		}
		if (countExcellentAppraisal*100/ countAppraisal > 75)
		{
			chekPrint++;
			cout << "Group: " << student[i].Group << endl;
			cout << "Surname: " << student[i].Surname << endl;
			cout << "Progress: ";
			for (int j = 0; j < countAppraisal; j++)
			{
				cout << student[i].Progress[j] << "\t";
			}
			cout << endl;
		}
	}
	if (chekPrint != 0)
	{
		cout << "the list of students is empty!!!" << endl;
	}
}

//Выводить список двоечников (>50% оценок 2 и 3);
void printPoorStudents(Student * student)
{
	cout << "print list of poor students: " << endl;
	int chekPrint = 0;
	for (int i = 0; i < countStudent; i++)
	{
		int countPoorAppraisal = 0;
		for (int j = 0; j < countAppraisal; j++)
		{
			if (student[i].Progress[j] < 4)
			{
				countPoorAppraisal++;
			}
		}
		if (countPoorAppraisal * 100 / countAppraisal > 50)
		{
			chekPrint++;
			cout << "Group: " << student[i].Group << endl;
			cout << "Surname: " << student[i].Surname << endl;
			cout << "Progress: ";
			for (int j = 0; j < countAppraisal; j++)
			{
				cout << student[i].Progress[j] << "\t";
			}
			cout << endl;
		}
	}
	if (chekPrint != 0)
	{
		cout << "the list of students is empty!!!" << endl;
	}
}

/*Описать структуру Student (фамилия, группа, успеваемость (массив из 5 int)). 
Создать массив студентов и написать программу, позволяющую: 
Выводить список отличников (>75% отличных оценок); 
Выводить список двоечников (>50% оценок 2 и 3); */