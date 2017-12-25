#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>

#include "execute.h"
#include "image.h"

using namespace std;

const string input = "input.txt";

int main(int argc, char* argv[]) {
	if(argc != 2) {
		cout << "param error" << endl;
		return EXIT_FAILURE;
	}

	RGB rgb[MAX_HEIGHT][MAX_WIDTH];
	for(int i = 0; i < MAX_HEIGHT; ++i)
		for(int j = 0; j < MAX_WIDTH; ++j)
			rgb[i][j].set(255,255,255);

	pixelize(static_cast<string>(argv[1]), rgb);

	for(int i = 0; i < MAX_HEIGHT; ++i) {
		for(int j = 0; j < MAX_WIDTH; ++j)
			if(rgb[i][j].isBckgrd()) {
				cout << " ";
			} else {
				cout << "#";
			}

		cout << endl;
	}
	return EXIT_SUCCESS;
}
/* ----- end of function main ----- */

