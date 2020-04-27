#pragma once

const int maxSize = 20;

struct Record;

struct PhoneBook;

// ������� ���������� �����.
PhoneBook* createPhoneBook();

// ������� ������.
Record* createRecord(int number, char newName[]);

// ������� ���������� ������� � �����.
int numberOfRecordsInBook(PhoneBook* phoneBook);

// ������� ������ � ������ �����.
Record* headOfPhoneBook(PhoneBook* phoneBook);

// ������� ����� �������� � ������.
int numberInRecord(Record* record);

// ������� ��� � ������.
char* nameInRecord(Record* record);

// ������� �����.
void deleteBook(PhoneBook* phoneBook);

// ������� ������ �� �����.
Record* removeRecordFromBook(PhoneBook* phoneBook);

// ��������� �� ������ �� �����.
bool isRecordsRead(PhoneBook* phoneBook);

// �������� ������ � �����.
void addRecordInPhoneBook(PhoneBook* phoneBook, Record* recordInBook);

// ������� ����� �� �������.
void showBook(PhoneBook* phoneBook);

// ��������� ������ � ������.
void putRecordsToArray(PhoneBook* phoneBook, int numbers[]);