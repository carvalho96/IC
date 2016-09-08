#include "VertexCaracPeso.h"



float VertexCaracPeso::getPeso()
{
	return Peso;
}

bool VertexCaracPeso::operator>(VertexCaracPeso a)
{
	if (Peso > a.Peso)
		return true;
	else
		return false;
}

bool VertexCaracPeso::operator==(VertexCaracPeso a)
{
    if (Peso == a.Peso)
		return true;
	else
		return false;
}

VertexCaracPeso::VertexCaracPeso()
{
    setVtype(PESO);
}
void VertexCaracPeso::setPeso(float pesotemp){
	Peso = pesotemp;
}


VertexCaracPeso::~VertexCaracPeso()
{
}
