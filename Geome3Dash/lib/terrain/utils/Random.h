#ifndef RANDOM_H
#define RANDOM_H

class Random
{
public:
	static float randomFloat(float a, float b);
	static float randomFloatSeeded(float a, float b, unsigned int seed);
	static float wave1(float x);
	static float wave2(float x);
	static float wave(float x, float y);	
};

#endif