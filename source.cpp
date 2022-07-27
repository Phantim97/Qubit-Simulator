#include <iostream>

#include "Qubit.h"

int main()
{
	Qubit q(0);

	q.M()->H()->M()->H()->M();

	return 0;
}
