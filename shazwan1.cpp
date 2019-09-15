// shazwan1.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <conio.h>
#include <math.h>
using namespace std;

float isobaric(int);
float isochroic(int);
float isothermal(int);
float AdiaPoly(int);

int main()
{
	bool conti=0;
	int ch1, ch2;
	char cont;
	float RESULT;
	do {
		cout << "Enter Type Of Process \n1.Isobaric \n2.Isochronic \n3.Isothermal \n4.Abiabatic or Polytrophic\n";
		cin >> ch1;
		cout << "Enter \n1.Work Done\n2.Missing Variable calculation:";
		cin >> ch2;
		switch (ch1) {
		case 1: {	RESULT=isobaric(ch2); getch(); break;}
		case 2: {	RESULT=isochroic(ch2); getch(); break; }
		case 3: {	RESULT=isothermal(ch2); getch(); break; }
		case 4: {	RESULT=AdiaPoly(ch2); getch(); break; }
		}
		cout << "Result of operation " << RESULT<<endl;
		cout << "Do you wish to continue? Y/y for Yes N/n for No : ";
		cin >> cont;
		if (cont=='Y'||cont=='y')
		{
			conti = 1;
		}
		else
		{
			conti = 0;
		}
	} while (conti == 1);
	cout << "Program will now exit ";
	return 0;
}
float isobaric(int choice)
{
	float  V1, V2, P1, P2, T1, T2;
	float P, v1, v2;
	if (choice==1)
	{
		cout << "Enter P, V1 & V2 : \n";
		cin >> P >> v1 >> v2;
		return (float(P * (v2 - v1)));
	}
	else if(choice == 2)
	{
		cout << "Enter V1, V2, T1, T2 , -1 for missing value : ";
		cin >> V1 >> V2 >> T1 >> T2;
		if (V1 == -1)
		{
			if (T2 != -1)
				return (float(V2 * T1 / T2));//V1 out
			else
			{
				cout << "Invalid Input ";
				exit(0);
			}
		}
		else if (V2 == -1)
		{
			if (T1 != 0)
				return (float(V1 * T2 / T1));//V2 out
			else
			{
				cout << "Invalid Input ";
				exit(0);
			}
		}
		else if (T2 == -1)
		{
			if (V1 != 0)
				return (float(T1 * V2 / V1));//T2 out
			else
			{
				cout << "Invalid Input ";
				exit(0);
			}
		}
		else if (T1 == -1)
		{
			if (V2 != 0)
				return (float(T2 * V1 / V2));//T1 out
			else
			{
				cout << "Invalid Input ";
				exit(0);
			}
		}
	}	
}
float isochroic(int choice)
{	
	float  V1, V2, P1, P2, T1, T2;
	if(choice == 1)
	return 0;
	else
	{
		cout << "Enter P1 P2 T1 T2 , -1 for missing value :";
		cin >> P1 >> P2 >> T1 >> T2;
		if (P1 == -1)
		{
			if (T2 != -1)
				return (float(P2 * T1 / T2));
			else
			{
				cout << "Invalid Input ";
				exit(0);
			}
		}
		else if (P2 == -1)
		{
			if (T1 != 0)
				return (float(P1 * T2 / T1));
			else
			{
				cout << "Invalid Input ";
				exit(0);
			}
		}
		else if (T2 == -1)
		{
			if (P1 != 0)
				return (float(T1 * P2 / P1));
			else
			{
				cout << "Invalid Input ";
				exit(0);
			}
		}
		else if (T1 == -1)
		{
			if (P2 != 0)
				return (float(T2 * P1 / P2));
			else
			{
				cout << "Invalid Input ";
				exit(0);
			}
		}
	}
}
float isothermal(int choice)
{
	float C, V1, V2, P1 , P2;
	if (choice == 1) {
		cout << "Enter C, V1 and V2 : ";
		cin >> C >> V1 >> V2;
		return (float(C*log(V1/V2)));
	}
	else if (choice == 2) {
		cout << "Enter P1 P2 V1 V2 , -1 for missing value :";
		cin >> P1 >> P2 >> V1 >> V2;
		if (P1 == -1)
		{	
			if(V1 !=-1)
			return (float(P2 * V2 / V1));
			else
			{
				cout << "Invalid Input ";
				exit(0);
			}
		}
		else if (P2 == -1)
		{
			if (V2 != 0)
				return (float(P1 * V1 / V2));
			else
			{
				cout << "Invalid Input "; 
				exit(0);
			}
		}
		else if (V1 == -1)
		{
			if (P1 != 0)
				return (float(V2 * P2 / P1));
			else
			{
				cout << "Invalid Input ";
				exit(0);
			}
		}
		else if (V2 == -1)
		{
			if (P2 != 0)
				return (float(V1 * P1 / P2));
			else
			{
				cout << "Invalid Input ";
				exit(0);
			}
		}
	}
	else
	{
		cout << "Incorrect Input \nEnter '1' for C*log(V1/V2) \n '2' for P1V1 = P2V2 ";
		return isothermal(choice);
	}
}
float AdiaPoly(int choice) {
	float P1, P2, V1, V2, T1, T2, N, calc = 0;
	if (choice == 1)
	{
		cout << "Enter P1,P2,V1,V2,T1,T2 & γ or η";
		cin >> P1 >> P2 >> V1 >> V2 >> N;
		calc = (P2 * V2);
		calc -= (P1 * V1);
		calc /= (1 - N);
		return (float(calc));
	}
	else if (choice == 2)
	{
		int choice1; 
		cout << "Enter 1 or 2 or 3 for Relation \n 1.P & V \n 2.T & V \n 3.P & T :";
		cin >> choice1;
		switch (choice1) {
		case 1: {
			cout << "Relation P & V ";
			cout << "Enter P1 , P2 , V1 , V2 & γ or η \n Enter -1 for missing value\n";
			cin >> P1 >> P2 >> V1 >> V2 >> N;
			if (P1 == -1) {
				calc = V2 / V1;
				calc = pow(calc, N);
				calc *= P2;
				return (float(calc));//P1 out
			}
			else if (P2 == -1) {
				calc = V1 / V2;
				calc = pow(calc, N);
				calc *= P1;
				return (float(calc));//P2 out
			}
			else if (V1 == -1) {
				float x = 1 / N;
				calc = P2 / P1;
				calc = pow(calc, x);
				calc *= V2;
				return (float(calc));//V1 out
			}
			else if (V2 == -1) {
				float x = 1 / N;
				calc = P1 / P2;
				calc = pow(calc, x);
				calc *= V1;
				return (float(calc));//V2 out
			}
			else {
				cout << "Invalid Input";
				exit(0);
			}
			break;
		}
		case 2: {
			cout << "Relation T & V ";
			cout << "Enter T1 , T2 , V1 , V2 & γ or η \n Enter -1 for missing value\n";
			cin >> T1 >> T2 >> V1 >> V2 >> N;
			N = N - 1;
			if (T1 == -1) {
				calc = V2 / V1;
				calc = pow(calc, N);
				calc *= T2;
				return (float(calc));//T1 out
			}
			else if (T2 == -1) {
				calc = V1 / V2;
				calc = pow(calc, N);
				calc *= T1;
				return (float(calc));//T2 out
			}
			else if (V1 == -1) {
				float x = 1 / N;
				calc = T2 / T1;
				calc = pow(calc, x);
				calc *= V2;
				return (float(calc));//V1 out
			}
			else if (V2 == -1) {
				float x = 1 / N;
				calc = T1 / T2;
				calc = pow(calc, x);
				calc *= V1;
				return (float(calc));//V2 out
			}
			else {
				cout << "Invalid Input";
				exit(0);
			}
			break;
		}
		case 3: {
			cout << "Relation T & P ";
			cout << "Enter T1 , T2 , P1 , P2 & γ or η \n Enter -1 for missing value\n";
			cin >> T1 >> T2 >> P1 >> P2 >> N;
			N = N - 1;
			N /= N;
			if (T1 == -1) {
				calc = P2 / P1;
				calc = pow(calc, N);
				calc *= T2;
				return (float(calc));//T1 out
			}
			else if (T2 == -1) {
				calc = P1 / P2;
				calc = pow(calc, N);
				calc *= T1;
				return (float(calc));//T2 out
			}
			else if (P1 == -1) {
				float x = 1 / N;
				calc = T2 / T1;
				calc = pow(calc, x);
				calc *= P2;
				return (float(calc));//P1 out
			}
			else if (P2 == -1) {
				float x = 1 / N;
				calc = T1 / T2;
				calc = pow(calc, x);
				calc *= P1;
				return (float(calc));//P2 out
			}
			else {
				cout << "Invalid Input";
				exit(0);

			}
			break;
		}
		}
	}
}
