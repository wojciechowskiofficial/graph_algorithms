#include <iostream>
#include <math.h>
#include <cstdlib>
#include <fstream>
#include <ctime>

#include "Utility.h"
#include "Generator.h"
#include "Graph.h"

int main() {
	Ug * test = new Ug(8, 0.73);
	test->auto_gen();
	return 0;
}
