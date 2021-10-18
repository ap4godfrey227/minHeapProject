#define _CRT_SECURE_NO_WARNINGS
#include "util.h"
#include "heap.h"
#include <iostream>
#include <fstream>

//================================================================

int nextCommand(){

	char c;
	while(1){
		scanf("%c", &c);
		if(c == ' ' || c == '\t' || c == '\n'){
			continue;
		}
		
		if(c == 'S' || c == 's'){
			break;
		}

		if(c == 'C' || c == 'c'){
			break;
		}

		if(c == 'R' || c == 'r'){
			break;
		}

		if(c == 'P' || c == 'p'){
			break;
		}

		if(c == 'W' || c == 'w'){
			break;
		}
		if (c == 'D' || c == 'd') {
			break;
		}
		if (c == 'I' || c == 'i') {
			break;
		}
		if (c == 'K' || c == 'k') {
			break;
		}
		
	}
	return c;
}
