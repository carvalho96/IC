#include "VertexPerson.h"
#include <string>

void VertexPerson::setname(string nome)
{

    name = nome;
}

std::string VertexPerson::getname()
{
	return name;
}

bool VertexPerson::operator>(VertexPerson a)
{
	if (name > a.getname())
		return true;
	else
		return false;
}

bool VertexPerson::operator==(VertexPerson a)
{
    if (name == a.getname())
		return true;
	else
		return false;
}



VertexPerson::VertexPerson()
{
    setVtype(PERSON);
}


VertexPerson::~VertexPerson()
{
}
