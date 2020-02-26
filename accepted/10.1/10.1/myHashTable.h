#pragma once

struct HashTable;

// �������� ���-�������.
HashTable * createHashTable();

// ������� ���������� ����� � ���-�������.
int capacityOfHashTable(HashTable * hashTable);

// �������� ������� � ���-�������.
void addHashElement(HashTable * hashTable, char value[]);

// ����������� ���-�������.
void printHashTable(HashTable * hashTable);

// ������� ����������� ����������.
float loadFactor(HashTable * hashTable);

// �������� ������������ ����� ������ � ��������.
int maxLengthOfListInSegment(HashTable * hashTable);

// �������� ������� ����� ������.
float averageLengthOfLists(HashTable * hashTable);

// �������� ���-�������.
void deleteHashTable(HashTable * hashTable);