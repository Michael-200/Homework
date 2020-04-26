#pragma once

struct GraphEdges;

//�������� �����.
GraphEdges** createGraph(int maxNumbersOfTown);

//������������� �����.
void initEdges(GraphEdges** graph, int actualNumberOfCities);

//���������� �������� � �����.
void addToGraph(GraphEdges* edge, int element, int weight);

int getSize(GraphEdges* edge);

int getNode(GraphEdges* edge, int index);

int getWeight(GraphEdges* edge, int index);

// �������� �����.
void deleteGraph(GraphEdges** graph, int size);