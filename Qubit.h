#pragma once
#include <complex>

//Probability of a State
struct Probability
{
	double s0 = .5;
	double s1 = .5;

	void set_state(const bool init_state)
	{
		this->s0 = !init_state;
		this->s1 = init_state;
	}

	bool operator==(const Probability&other) const
	{
		return this->s0 == other.s0 && this->s1 == other.s1;
	}
};

struct Amplitudes
{
	std::complex<double> alpha = { 0,0 };
	std::complex<double> beta = { 0 ,0 };

	void set_amplitudes(const bool state)
	{
		if (state == 0)
		{
			alpha.real(1);
			alpha.imag(0);
		}
		else
		{
			beta.real(1);
			alpha.imag(0);
		}
	}

	bool operator==(const Amplitudes& other) const
	{
		return this->alpha == other.alpha && this->beta == other.beta;
	}
};

class Qubit
{
private:
	//Note |psi> = a|0> + b|1> where |a|^2 + |b|^2 = 1 (alpha and beta)
	Probability probability_;
	Amplitudes amplitude_;
public:
	Qubit(const bool state)
	{
		probability_.set_state(state);

		if (probability_.s0 == 1)
		{
			amplitude_.alpha = 1;
		}
		else
		{
			amplitude_.beta = 1;
		}
	}

	Qubit* X();
	Qubit* Y();
	Qubit* Z();
	Qubit* H();

	Qubit* M();

	bool operator==(const Qubit& q) const
	{
		return this->amplitude_ == q.amplitude_ && this->probability_ == q.probability_;
	}
};