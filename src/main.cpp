#include <stdio.h>

// Our example class which 
// we will create instances of. 
// Due to alignment reasons
// the size of this class
// is 12 bytes. 
// 2 x int(4) = 8
// 1 x char(1) =9
// We expect to have 9 bytes, 
// but the allocation is
// done with 4byte alignment, 
// so 12 bytes is used. 
class Player {

public:
	unsigned int age;
	unsigned int score;
	unsigned char shortSign;	

};

// Static memory for 10 (12 * 10) Player objects (or any objects which are 12 byte sized) 
// place for 10 Player objects
char mymem[12*10]; 

// our pointer which keeps track where we can allocate from
char* objPtr = mymem; 

// Points to the last allocated object
char* lastPtr = mymem;

// Generic allocation function. 
// The caller needs to know what to 
// cast to.
void* AllocObject(unsigned int size) {
	objPtr = lastPtr + size;	
	lastPtr = objPtr;
	return objPtr;

}

// Deallocating is a bit more complicated
// to to possible memory fragmentation. 
void* DeleteObj(void* obj, unsigned int size) {
	
	
}


int main(int argc, char** args)  {

	printf("sizeof player %d\n", sizeof(Player));	
	printf("sizeof uchar %d\n", sizeof(unsigned char));

	Player* p = (Player*)AllocObject(sizeof(Player));
	p->age = 12;
	p->score = 99;
	p->shortSign = 1;

	printf("Player member print: %d %d %d\n", p->age, p->score, p->shortSign);

	Player* p2 = (Player*)AllocObject(sizeof(Player));
	p2->age = 13;
	p2->score = 100;
	p2->shortSign = 255; 
	printf("Player2 member print: %d %d %d\n", p2->age, p2->score, p2->shortSign);

	

	
	return 0;
}

