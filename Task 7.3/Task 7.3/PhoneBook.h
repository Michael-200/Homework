#pragma once

const int maxSize = 20;

struct Record
{
	int number;
	char name[maxSize]{};
	Record* next = nullptr;
};

struct PhoneBook
{
	int numberOfRecords = 0;
	Record* head = nullptr;
};

// ������� ���������� �����.
PhoneBook* createPhoneBook();

// ������� �����.
void deleteBook(PhoneBook* phoneBook);

// ��������� �� ������ �� �����.
bool isRecordsRead(PhoneBook* phoneBook);

// �������� ������ � �����.
void addRecordInPhoneBook(PhoneBook* phoneBook, Record* recordInBook);

// ���������� ��������.
PhoneBook* mergeSort(PhoneBook* phoneBook, bool& isNumberSort);

// ������� ����� �� �������.
void showBook(PhoneBook* phoneBook);

// ��������� ������ � ������.
void putRecordsToArray(PhoneBook* phoneBook, int numbers[]);
void putRecordsToArray(PhoneBook* phoneBook, int numbers[]);