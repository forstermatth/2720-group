#include "Output.h"
#include "output_testfixture.h"
#include "Exceptions.h"

void OutputFixture::setUp(){
	out = new Output();
}

void OutputFixture::tearDown(){
	delete out;
}
