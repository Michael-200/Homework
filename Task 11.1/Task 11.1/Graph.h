#pragma once

struct Graph;

//�������� �����.
Graph** createGraph(int maxNumbersOfTown);

//������������� �����.
void initGraphs(Graph** graph, int actualnumberOfCities);

//���������� �������� � �����.
void addToGraph(Graph* graph, int element, int weight);

int getSize(Graph* graph);

int getNote(Graph* graph, int index);

int getWeight(Graph* graph, int index);

// �������� �����.
void deleteGraph(Graph** graph, int size);