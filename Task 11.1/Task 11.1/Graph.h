#pragma once

struct GraphEdges;

//�������� �����.
GraphEdges** createGraph(int maxNumbersOfTown);

//������������� �����.
void initGraphs(GraphEdges** graph, int actualNumberOfCities);

//���������� �������� � �����.
void addToGraph(GraphEdges* graph, int element, int weight);

int getSize(GraphEdges* graph);

int getNode(GraphEdges* graph, int index);

int getWeight(GraphEdges* graph, int index);

// �������� �����.
void deleteGraph(GraphEdges** graph, int size);