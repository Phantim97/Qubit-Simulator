#include <iostream>

#include "Qubit.h"

int main()
{
	Qubit q(0);

	q.M()->H()->Y()->Z()->Y()->H()->M();

	return 0;
}
