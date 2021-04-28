//
// begin license header
//
// This file is part of Pixy CMUcam5 or "Pixy" for short
//
// All Pixy source code is provided under the terms of the
// GNU General Public License v2 (http://www.gnu.org/licenses/gpl-2.0.html).
// Those wishing to use Pixy source code, software and/or
// technologies under different licensing terms should contact us at
// cmucam@cs.cmu.edu. Such licensing terms are available for
// all portions of the Pixy codebase presented here.
//
// end license header
//

#include <Pixy2.h>

Pixy2 pixy;

int main() {
	printf("Starting...\n");

	pixy.init();
	// change to the line_tracking program.	Note, changeProg can use partial strings, so for example,
	// you can change to the line_tracking program by calling changeProg("line") instead of the whole
	// string changeProg("line_tracking")
	pixy.changeProg("line");


	while(true) {
		int8_t i;
		char buf[128];
	 
		pixy.line.getAllFeatures();

		// print all vectors
		for (i = 0; i < pixy.line.numVectors; i++) {
			printf("line %d: ", i);
			pixy.line.vectors[i].print();
		}
		
		// print all intersections
		for (i = 0; i < pixy.line.numIntersections; i++) {
			printf("intersection %d: ", i);
			pixy.line.intersections[i].print();
		}
		
		// print all barcodes
		for (i = 0; i < pixy.line.numBarcodes; i++) {
			printf("barcode %d: ", i);
			pixy.line.barcodes[i].print();
		}
	}
	
	return 0;
}
