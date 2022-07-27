#include "Qubit.h"
#include <iostream>

//Pauli-X Gate
Qubit* Qubit::X()
{
	//Just a NOT Gate for the Computational Basis States
	if (probability_.s0 == 1.0)
	{
		probability_.s1 = 1;
		probability_.s0 = 0;
		amplitude_.alpha.real(0);
		amplitude_.beta.real(1);
	}
	else if (probability_.s1 == 1.0)
	{
		probability_.s0 = 1;
		probability_.s1 = 0;

		amplitude_.alpha.real(1);
		amplitude_.beta.real(0);
		
	}

	return this;
}

//Pauli-Y Gate
Qubit* Qubit::Y()
{
	//Y Gate on Computational Basis state is really an X Gate
	if (probability_.s0 == 1 || probability_.s1 == 1)
	{
		this->X();
	}
	else
	{
		amplitude_.alpha.real(amplitude_.alpha.real() * -1);
		amplitude_.beta.real(amplitude_.beta.real() * -1);
	}

	return this;
}

//Pauli-Z Gate
Qubit* Qubit::Z()
{
	//Z Gate has no effect on the computational basis states |0> and |1>
	if (probability_.s0 != 1 && probability_.s1 != 1)
	{
		probability_.s0 = 0.5;
		probability_.s1 = 0.5;
		amplitude_.alpha.real(amplitude_.alpha.real() * -1);
		amplitude_.alpha.imag(amplitude_.alpha.imag() * -1);
		amplitude_.beta.real(amplitude_.beta.real() * -1);
		amplitude_.beta.imag(amplitude_.beta.imag() * -1);
	}

	return this;
}

//Hadamard Gate
Qubit* Qubit::H()
{
	//Computational Basis State Conditions
	if (probability_.s0 == 1 || probability_.s1 == 1)
	{
		int sign = 1;
		if (probability_.s1 == 1) //if |1> we need to invert the amplitude
		{
			sign = -1;
		}

		probability_.s0 = .5;
		probability_.s1 =.5;
		amplitude_.alpha.real(1 / sqrt(2));
		amplitude_.beta.real(sign * 1 / sqrt(2));
	}
	else if (amplitude_.beta.real() == 1 / sqrt(2)) //Back to |0>
	{
		probability_.s0 = 1;
		probability_.s1 =0;
		amplitude_.alpha.real(1);
		amplitude_.beta.real(0);
	}
	else if (amplitude_.beta.real() == - 1/sqrt(2)) //Back to |1>
	{
		probability_.s0 = 0 ;
		probability_.s1 = 1.0;
		amplitude_.alpha.real(0);
		amplitude_.beta.real(1);
	}

	return this;
}

//Measure
Qubit* Qubit::M()
{
	//Provide Probabilities of |0>, |1> and Amplitudes alpha and beta
	std::cout << "Probabilities: |0> = " << probability_.s0
		<< " || |1> = " << probability_.s1 << "\nAmplitudes: ["
		<< amplitude_.alpha.real() << " + " << amplitude_.alpha.imag()
		<< "i, " << amplitude_.beta.real() << " + " << amplitude_.beta.imag() << "i]\n\n";

	return this;
}