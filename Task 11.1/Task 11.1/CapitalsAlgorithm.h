#pragma once
#include "Graph.h"

//���������������� ������ �� �����.
void ParseData(char path[], Graph** graph, List** citiesInfo, bool isCityInCountry[], int* numberOfCapitals, int* numberOfCities);

//��������� ��������, ������� ����� ��������� ���������� � �������� � citiesInfo.
void RunAlgorithm(int numberOfCapitals, int maxWeight, List** citiesInfo, bool isCityInCountry[], Graph** graph);