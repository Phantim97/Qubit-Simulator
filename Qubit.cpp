#include "Qubit.h"

#include <iostream>

//Pauli-X Gate
Qubit* Qubit::X()
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

	return this;
}

//Pauli-Y Gate
Qubit* Qubit::Y()
{
	if (probability_.s0 == 1 || probability_.s1 == 1)
	{
		this->X();
	}
	else
	{
		
	}

	return this;
}

//Pauli-Z Gate
Qubit* Qubit::Z()
{
	if (probability_.s0 != 1 && probability_.s1 != 1)
	{
		probability_.s0 = 0.5;
		probability_.s1 = 0.5;
	
	}

	return this;
}

//Hadamard Gate
Qubit* Qubit::H()
{
	if (probability_.s0 == 1 || probability_.s1 == 1)
	{
		int sign = 1;
		if (probability_.s1 == 1)
		{
			sign = -1;
		}

		probability_.s0 = .5;
		probability_.s1 =.5;
		amplitude_.s0.real(1 / sqrt(2));
		amplitude_.s1.real(sign * 1 / sqrt(2));
	}
	else if (amplitude_.s1.real() == 1 / sqrt(2))
	{
		probability_.s0 = 1;
		probability_.s1 =0;
		amplitude_.s0.real(1);
		amplitude_.s1.real(0);
	}
	else if (amplitude_.s1.real() == - 1/sqrt(2))
	{
		probability_.s0 = 0 ;
		probability_.s1 = 1.0;
		amplitude_.s0.real(0);
		amplitude_.s1.real(1);
	}

	return this;
}

//Measure
Qubit* Qubit::M()
{
	std::cout << "Probabilities: |0> = " << probability_.s0
		<< " || |1> = " << probability_.s1 << "\nAmplitudes: ["
		<< amplitude_.s0.real() << " + " << amplitude_.s0.imag()
		<< "i, " << amplitude_.s1.real() << " + " << amplitude_.s1.imag() << "i]\n\n";

	return this;
}