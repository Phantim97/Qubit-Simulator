#include <iostream>
#include "Qubit.h"

int main()
{
	Qubit q(0);

	q.M()->H()->Y()->Z()->Y()->H()->M();

	Qubit q2(0);

	q2.H(); //Put q2 into superposition

	//Simulate a measurement on qubit in superposition 5 times
	constexpr int n = 5;
	for (int i = 0; i < n; i++)
	{
		q2.M();
	}
	
	return 0;
}
