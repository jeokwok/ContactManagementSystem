/* contacts manage system  
	2020.01.13

	by jeokwok  github
	version 1.0.0
*/

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <fstream>
#include "contactsFile.h"

using namespace std;

#define MAX  10
int g_count = 0;
#define  _CRT_SECURE_NO_WARNINGS
struct Person
{	
	string m_name;
	int m_sex;
	int m_age;

	//130-####-#### 
	int m_phone;  //130 

	int m_phone_2;//#### 
	int m_phone_3;//####
};

struct AddressBooks{
	struct Person personArray[MAX];
	int m_size;
};

void showMenu();
void addPerson(AddressBooks* a_bs);
void showPerson(AddressBooks* a_bs);
void delPerson(AddressBooks* a_bs);
void findPerson(AddressBooks* a_bs);
void modifyPerson(AddressBooks* a_bs);

void readContactsFile();
void writeContactsFile(AddressBooks* a_bs);

int main() {
	AddressBooks a_bs;
	a_bs.m_size = 0;
	g_count = a_bs.m_size;
	int select = 0;
	while (true) {
		showMenu();
		scanf_s("%d", &select);
		switch (select)
		{
		case 1:
			cout << "add contacts person" << endl;
			addPerson(&a_bs);
			break;
		case 2:
			cout << "show contacts " << endl;
			//readContactsFile();
			showPerson(&a_bs);
			break;
		case 3:
			cout << "del contacts person" << endl;
			delPerson(&a_bs);
			break;
		case 4:
			cout << "find contacts person" << endl;
			findPerson(&a_bs);
			break;
		case 5:
			cout << "modify contacts person" << endl;
			modifyPerson(&a_bs);
			break;
		case 0:
			printf("welcome back!");
			return 0;
			break;
		default:
			break;
		}
	}
	system("PAUSE");
	return 0;
}

//display menu 
void showMenu() {
	printf("welcome to the contacts manage system.\n");
	printf("1、添加联系人 \n");
	printf("2、显示联系人 \n");
	printf("3、删除联系人 \n");
	printf("4、查找联系人 \n");
	printf("5、修改联系人 \n");
	printf("0、退出系统 \n");
	printf("please input number to choose: \n");
}

//add contact 
void addPerson(AddressBooks* a_bs) {
	printf("please input name: \n");
	string name;
	cin >> name;
	a_bs->personArray[a_bs->m_size].m_name = name;

	printf("please input sex (man = 1, women = 2)\n");
	int sex;
	cin >> sex;
	a_bs->personArray[a_bs->m_size].m_sex = sex;

	printf("please input age: \n");
	int age;
	cin >> age;
	a_bs->personArray[a_bs->m_size].m_age = age;

	printf("please input phonenumber(130 #### ####): \n");
	int phone;
	int phone_2;
	int phone_3;

	cin >> phone;
	cin >> phone_2;
	cin >> phone_3;

	a_bs->personArray[a_bs->m_size].m_phone = phone;
	a_bs->personArray[a_bs->m_size].m_phone_2 = phone_2;
	a_bs->personArray[a_bs->m_size].m_phone_3 = phone_3;

	writeContactsFile(a_bs);

	a_bs->m_size = a_bs->m_size + 1;

	
	printf("add success and save to the file!\n");
	system("pause");
	system("cls");
}

//desplay person
void showPerson(AddressBooks* a_bs) {
	
	if (a_bs->m_size == 0)
	{
		cout << "the addressbooks is empty!" << endl;
		//printf("address is null \n");
	}
	else {
		for (size_t i = 0; i < a_bs->m_size; i++)
		{
			cout <<i + 1<<"  "<< "name: " << a_bs->personArray[i].m_name << "\t";
			cout << "sex: " << (a_bs->personArray[i].m_sex == 1 ? "男" : "女") << "\t";
			cout << "age: " << a_bs->personArray[i].m_age << "\t";
			cout << "phone: " << a_bs->personArray[i].m_phone << " " << a_bs->personArray[i].m_phone_2<< " " << a_bs->personArray[i].m_phone_3 << endl;
		}
	}
	system("pause");
	system("cls");
}
//judge result
int  isExit(AddressBooks* a_bs, string name) {
	for (size_t i = 0; i < a_bs->m_size; i++)
	{
		if (a_bs->personArray[i].m_name == name)
		{
			return i;
		}
	}
	return -1;
}
//delete contacts person
void delPerson(AddressBooks* a_bs) {
	cout << "please input name:" << endl;
	string name;
	cin >> name;
	int result = isExit(a_bs, name);
	if (result != -1) {
		for (size_t i = result; i < a_bs->m_size; i++)
		{
			a_bs->personArray[i] = a_bs->personArray[i + 1];
		}
		a_bs->m_size = a_bs->m_size - 1;
		cout << "delete contacts success!" << endl;
	}
	else {
		cout << "addressbooks is empty! " << endl;
	}
	system("pause");
	system("cls");
}

void findPerson(AddressBooks* a_bs) {
	if (a_bs->m_size == 0)
	{
		cout << "the contects is empty!" << endl;
	}
	else {
		cout << "please input name:" << endl;
		
		cout << " please input name first word" << endl;
		char ch;  //english name  first word
		cin >> ch;
		

		string name;
		cin >> name;
		int result = isExit(a_bs, name);
		if (result == -1)
		{
			cout << "the contacts is empty!" << endl;
		}
		else {
			cout << g_count + 1<< "  name: " << a_bs->personArray[result].m_name << "\t";
			cout << "sex: " << (a_bs->personArray[result].m_sex == 1 ? "男" : "女") << "\t";
			cout << "age: " << a_bs->personArray[result].m_age << "\t";
			//cout << "phone: " << a_bs->personArray[result].m_phone << endl;
			cout << "phone: " << a_bs->personArray[result].m_phone << " " << a_bs->personArray[result].m_phone_2 << " " << a_bs->personArray[result].m_phone_3 << endl;
		}
	}
	system("pause");   
	system("cls");
}

void modifyPerson(AddressBooks* a_bs) {
	if (a_bs->m_size == 0) {
		cout << "the contacts is empty!" << endl;
	}
	else {
		cout << "please input name to modify:" << endl;
		string name;
		cin >> name;
		int result = isExit(a_bs, name);
		if (result != -1)
		{
			// old datas 
			cout <<"<old datas>" <<g_count << "  name: " << a_bs->personArray[result].m_name << "\t";
			cout << "sex: " << (a_bs->personArray[result].m_sex == 1 ? "男" : "女") << "\t";
			cout << "age: " << a_bs->personArray[result].m_age << "\t";
			cout << "phone: " << a_bs->personArray[result].m_phone << " " << a_bs->personArray[result].m_phone_2 << " " << a_bs->personArray[result].m_phone_3 << endl;

			cout << "please input name:" << endl;
			string n_ame;
			cin >> n_ame;
			a_bs->personArray[result].m_name = n_ame;

			cout << "please input sex(man = 1, women = 2):" << endl;
			int sex;
			cin >> sex;
			a_bs->personArray[result].m_sex = sex;

			cout << "please input age:" << endl;
			int age;
			cin >> age;
			a_bs->personArray[result].m_age = age;

			cout << "please input phonenumber(130 #### ####):" << endl;
			int phone;
			int phone_2;
			int phone_3;

			cin >> phone;
			cin >> phone_2;
			cin >> phone_3;

			a_bs->personArray[a_bs->m_size].m_phone = phone;
			a_bs->personArray[a_bs->m_size].m_phone_2 = phone_2;
			a_bs->personArray[a_bs->m_size].m_phone_3 = phone_3;

			cout << "modify person success!" << endl;
		}
	}
	system("pause");
	system("cls");
}


//read contacts file
void readContactsFile() {
	ifstream ifs;
	ifs.open(CONTACTS_FILE, ios::in);

	
	if (!ifs.is_open())
	{
		cout << "file is null!" << endl;
		ifs.close();
		return;
	}
	else {
		string f_name;
		int f_sex;
		int f_age;
		int f_phone;
		while (ifs >> f_name, ifs >> f_sex, ifs >> f_age, ifs >> f_phone)
		{
			cout << f_name << "\t";
			cout << f_sex << "\t";
			cout << f_age << "\t";
			cout << f_phone << endl;
		}		
	}
	ifs.close();
}

//write contacts file
void writeContactsFile(AddressBooks* a_bs) {
	ofstream ofs;
	ofs.open(CONTACTS_FILE, ios::app); //| ios::trunc

	if (!ofs.is_open())
	{
		cout << "file is null! " << endl;
		ofs.close();
		return;
	}
	else {
		string f_name;
		int f_sex;
		int f_age;
		int f_phone;

		f_name = a_bs->personArray[a_bs->m_size].m_name;
		string sex;
		f_sex = a_bs->personArray[a_bs->m_size].m_sex;
		if (f_sex == 1)
		{
			sex = "man";
		}
		else {
			sex = "women";
		}
		f_age = a_bs->personArray[a_bs->m_size].m_age;
		f_phone = a_bs->personArray[a_bs->m_size].m_phone;
		
		ofs << f_name << "\t";
		ofs << sex << "\t";
		ofs << f_age << "\t";
		ofs << f_phone << endl;
		
		/*ofs << f_name << "\t";
		ofs << sex  << "\t";
		ofs << f_age << "\t";
		ofs << f_phone << endl;	
		ofs << "\n";*/
	}
	ofs.close();	
}






