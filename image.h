#ifndef	IMAGE_H_
#define	IMAGE_H_

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

#include "execute.h"
#include "split.h"

const string txt_path	= "input.txt";
const int MAX_HEIGHT	= 50;
const int MAX_WIDTH		= 50;

class RGB {
	public:
		int r, g, b;

		void set(int _r, int _g, int _b) {
			r	= _r;
			g	= _g;
			b	= _b;
		}
		
		bool isBckgrd() {
			return 600 <= r + g + b;
		}
};

bool pixelize(string image_path, RGB rgb[MAX_HEIGHT][MAX_WIDTH]) {
	execute("convert " + image_path + " " + txt_path);

	ifstream txt(txt_path.data());
	if(txt.is_open()) {
		string line;
		while(getline(txt, line)) {
			stringstream ss;
			ss.str(line);

			int row, col, r, g, b;
			char c;

			ss >> col;
			ss >> c;
			ss >> row;
			ss >> c;
			ss >> c;
			ss >> r;
			ss >> c;
			ss >> g;
			ss >> c;
			ss >> b;

			rgb[row][col] = {r,g,b};
		}
		txt.close();
	}
	return true;
}

#endif
