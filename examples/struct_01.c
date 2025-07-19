#include <stdio.h>


struct Point {
	int x;
	int y;
};

int calculatePoints(struct Point p1, struct Point p2){

	int result = (p1.x - p2.x) + (p1.y - p2.y);
	if(result < 0){ result *= -1; }
	return result;
}

int main(){

	struct Point p1 = {6, 6};
	struct Point p2 = {4, 1};
	
	int manhattanDistance = calculatePoints(p1, p2);
	printf("Manhattan distance: %d", manhattanDistance);

	return 0;

}
