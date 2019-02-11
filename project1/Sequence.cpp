//#include "Sequence.h"
#include "pch.h"

//using namespace std;
Sequence::Sequence(size_type sz)
{
	numElts = sz;
	elts = new value_type[sz];
	for (size_type i = 0; i < numElts; i++)
		//need to intialize as undefined right now let it be 0
		elts[i] = 0;
}

Sequence::~Sequence()
{

	delete[] elts;
	
}

Sequence::Sequence(const Sequence& s)
{
	numElts = s.numElts;
	elts = new value_type[numElts];
	for (size_type i = 0; i < numElts; i++)
		elts[i] = s.elts[i];


}

Sequence::value_type& Sequence::operator[](size_type position)
{
	if (position >= numElts) {
		throw exception("invalid sequence index");
	}
	return elts[position];
}

Sequence& Sequence::operator=(const Sequence& s)
{
	if (this != &s)
	{
		delete[] elts;

		numElts = s.numElts;
		elts = new value_type[numElts];
		for (value_type i = 0; i < numElts; i++)
		{
			elts[i] = s.elts[i];
		}
	}

	return *this;
}
Sequence::value_type& Sequence::at(size_type position)
{
	if (position >= numElts) {
		throw exception("invalid sequence index");
	}
	return elts[position];
}

void Sequence::push_back(const value_type& value)
{
	
	value_type * tempElts = new value_type[numElts+1];
	for (size_type i = 0; i < numElts; i++)
		tempElts[i] = elts[i];
	tempElts[numElts] = value;
	delete[] elts;
	elts = tempElts;
	numElts++;
}
void Sequence::pop_back()
{
	
	value_type * tempElts = new value_type[numElts - 1];
	for (size_type i = 0; i < numElts-1; i++)
		tempElts[i] = elts[i];
	delete[] elts;
	elts = tempElts;
	numElts--;
	
}

Sequence::size_type Sequence::size() const
{
	return this->numElts;
}
const Sequence::value_type& Sequence::front() const
{
	return this->elts[0];
}

const Sequence::value_type& Sequence::back() const
{
	return this->elts[numElts-1];
}

bool Sequence::empty() const
{
	if (numElts > 0) 
	{
	
		return false; 
	
	}else{
		
	return true;
	}
}

void Sequence::clear()
{
	 elts=nullptr;
	 numElts = 0;
}

void Sequence::insert(size_type position, value_type value)
{
	numElts++;
	value_type * tempElts = new value_type[numElts + 1];


	for (size_type i = 0; i < position; i++)
		tempElts[i] = elts[i];

	tempElts[position] = value;
	size_type j = position;
		for (size_type i = position + 1; i < numElts; i++)
		{	tempElts[i] = elts[j];
	j++;
}
		

	
	
	 elts=nullptr;
	elts = tempElts;
}
/*

void Sequence::erase(size_type position, size_type count)
{
}

*/


 ostream& operator<<(ostream& os, Sequence& s)
{
	//os << s;
	//return os;

	for (Sequence::size_type i = 0; i < s.numElts; i++)
		//need to intialize as undefined right now let it be 0
		os<<s.elts[i];
	return os;
}