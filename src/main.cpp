#include <stdio.h>

class Player {

public:
	unsigned int age;
	unsigned int score;
	unsigned char shortSign;	

};

char mymem[12*10]; // place for 10 Player objects
char* objPtr = mymem;

int main(int argc, char** args)  {

	printf("sizeof player %d\n", sizeof(Player));	
	printf("sizeof uchar %d\n", sizeof(unsigned char));

	Player* p = (Player*)objPtr;
	p->age = 12;
	p->score = 99;
	p->shortSign = 1;
	objPtr += sizeof(Player);

	printf("Player member print: %d %d %d\n", p->age, p->score, p->shortSign);

	Player* p2 = (Player*)objPtr;
	p2->age = 13;
	p2->score = 100;
	p2->shortSign = 255; 
	printf("Player2 member print: %d %d %d\n", p2->age, p2->score, p2->shortSign);
	return 0;
}

