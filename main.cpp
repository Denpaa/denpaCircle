// This is free and unencumbered software released into the public domain.
//
// Anyone is free to copy, modify, publish, use, compile, sell, or
// distribute this software, either in source code form or as a compiled
// binary, for any purpose, commercial or non-commercial, and by any
// means.
//
// In jurisdictions that recognize copyright laws, the author or authors
// of this software dedicate any and all copyright interest in the
// software to the public domain. We make this dedication for the benefit
// of the public at large and to the detriment of our heirs and
// successors. We intend this dedication to be an overt act of
// relinquishment in perpetuity of all present and future rights to this
// software under copyright law.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
// EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
// MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
// IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR
// OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
// ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
// OTHER DEALINGS IN THE SOFTWARE.
//
// For more information, please refer to <http://unlicense.org/>
//
// main.cpp
// denpaCircle
// Draws a circle in the command line.

#include <stdio.h>
#include <stdint.h>

int main(void) {
	char bitmap[64][64] = {};
	
	int centerX = 32;
	int centerY = 32;
	int radius = 20;
	
	{
		int diameter = radius + radius;
		int x = radius;
		int y = 0;
		int dY = -2;
		int dX = diameter + diameter - 4;
		int d = diameter - 1;
		
		while (y <= x) {
			bitmap[centerY - y][centerX - x] = 1;
			bitmap[centerY - y][centerX + x] = 1;
			bitmap[centerY + y][centerX - x] = 1;
			bitmap[centerY + y][centerX + x] = 1;
			bitmap[centerY - x][centerX - y] = 1;
			bitmap[centerY - x][centerX + y] = 1;
			bitmap[centerY + x][centerX - y] = 1;
			bitmap[centerY + x][centerX + y] = 1;
			
			d += dY;
			dY -= 4;
			++y;
			
			int mask = (d >> 31);
			d += (dX & mask);
			dX -= (4 & mask);
			x += mask;
		}
	}
	
	for (int i = 0; i < 64; ++i) {
		for (int j = 0; j < 64; ++j) {
			char left = ' ';
			char right = ' ';
			if (bitmap[i][j] == 1) {
				left = '[';
				right = ']';
			}
			printf("%c%c", left, right);
		}
		printf("\n");
	}
	
	return 0;
}
