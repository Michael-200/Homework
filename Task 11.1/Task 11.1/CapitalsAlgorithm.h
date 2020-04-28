#pragma once
#include "Graph.h"

//���������������� ������ �� �����.
void parseData(char path[], GraphEdges** graph, List** citiesInfo, bool isCityInCountry[], int* numberOfCapitals, int* numberOfCities);

//��������� ��������, ������� ����� ��������� ���������� � �������� � citiesInfo.
void runAlgorithm(int numberOfCapitals, int maxWeight, List** citiesInfo, bool isCityInCountry[], GraphEdges** graph);