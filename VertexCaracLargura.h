#pragma once
#include "VertexCaract.h"
class VertexCaracLargura :	public Vertex
{
private:
	float largura;
public:
	float getlargura();
    void setLargura(float l);
	bool operator>(VertexCaracLargura a);
    bool operator==(VertexCaracLargura a);
	VertexCaracLargura();
	~VertexCaracLargura();
};

