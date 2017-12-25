#ifndef EXECUTE_H_
#define EXECUTE_H_

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <stdexcept>

using namespace std;

const int BUFF_SIZE = 128;

string execute(string _cmd) {
	char cmd[BUFF_SIZE];
	strcpy(cmd, _cmd.c_str());

	char buffer[BUFF_SIZE];
	string result;
	FILE* pipe = popen(cmd, "r");
	if(!pipe)
		throw runtime_error("popen() failed");

	try {
		while(!feof(pipe)) {
			if(fgets(buffer, BUFF_SIZE, pipe))
				result += buffer;
		}

	} catch (...) {
		pclose(pipe);
		throw;
	}

	return result;
}
/* ----- end of function execute ----- */

#endif
