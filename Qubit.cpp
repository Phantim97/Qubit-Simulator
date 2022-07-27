#include "Qubit.h"

#include <iostream>

//Pauli-X Gate
void Qubit::X()
{
	if (probability_.s0 == 1.0)
	{
		probability_.s1 = 1;
		probability_.s0 = 0;
		amplitude_.s0.real(0);
		amplitude_.s1.real(1);
	}
	else if (probability_.s1 == 1.0)
	{
		probability_.s0 = 1;
		probability_.s1 = 0;

		amplitude_.s0.real(1);
		amplitude_.s1.real(0);
		
	}
}

//Pauli-Y Gate
void Qubit::Y()
{

}

//Pauli-Z Gate
void Qubit::Z()
{
}

//Hadamard Gate
void Qubit::H()
{
	
}

//Measure
void Qubit::M()
{
	std::cout << "Probabilities: |0> = " << probability_.s0
		<< " || |1> = " << probability_.s1 << "\nAmplitudes: ["
		<< amplitude_.s0.real() << " + " << amplitude_.s0.imag()
		<< "i, " << amplitude_.s1.real() << " + " << amplitude_.s1.imag() << "i]\n\n";
}