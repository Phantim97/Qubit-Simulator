#pragma once
#include <complex>

struct Probability
{
	double s0 = .5;
	double s1 = .5;

	void set_state(const bool init_state)
	{
		this->s0 = !init_state;
		this->s1 = init_state;
	}
};

struct Amplitudes
{
	std::complex<double> s0 = { 0,0 };
	std::complex<double> s1 = { 0 ,0 };

	void set_amplitudes(const bool state)
	{
		if (state == 0)
		{
			s0.real(1);
			s0.imag(0);
		}
		else
		{
			s1.real(1);
			s0.imag(0);
		}
	}
};

class Qubit
{
private:
	Probability probability_;
	Amplitudes amplitude_;
public:
	Qubit(const bool state)
	{
		probability_.set_state(state);

		if (probability_.s0 == 1)
		{
			amplitude_.s0 = 1;
		}
		else
		{
			amplitude_.s1 = 1;
		}
	}

	Qubit* X();
	Qubit* Y();
	Qubit* Z();
	Qubit* H();

	Qubit* M();
};