#pragma once

struct MyHashTable;

// �������� ���-�������.
MyHashTable* createHashTable();

// ������� ���������� ����� � ���-�������.
int capacityOfHashTable(MyHashTable* hashTable);

// �������� ������� � ���-�������.
void addElementToHashTable(MyHashTable* hashTable, char value[]);

// �������� �������������� ����� ���-�������.
bool isContainInHashTable(MyHashTable* hashTable, char value[]);

// ���������� ��������� �����.
int numberOfEntries(MyHashTable* hashTable, char value[]);

// ����������� ���-�������.
void printHashTable(MyHashTable* hashTable);

// ������� ����������� ����������.
float loadFactor(MyHashTable* hashTable);

// �������� ������������ ����� ������ � ��������.
int maxLengthOfListInSegment(MyHashTable* hashTable);

// �������� ������� ����� ������.
float averageLengthOfLists(MyHashTable* hashTable);

// �������� ���-�������.
void deleteHashTable(MyHashTable* hashTable);