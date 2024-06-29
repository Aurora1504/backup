#include<stdio.h>
#include<math.h>
#include<unistd.h>

typedef struct {
	double x, y, z;
} point;

char brightness[12] = ".,-~:;=!*#$@";
point cube[10000];
int pixels = 0;

void generate() {
	for(int i = -15; i <= 15; i++) {
		for(int j = -15; j <= 15; j++) {
			cube[pixels].x = j;
			cube[pixels].y = i;
			cube[pixels].z = -15.0;
			pixels++;
			cube[pixels].x = j;
			cube[pixels].y = i;
			cube[pixels].z = 15.0;
			pixels++;
		}
	}

	for(int i = -15; i <= 15; i++) {
		for(int j = -15; j <= 15; j++) {
			cube[pixels].x = j;
			cube[pixels].y = 15.0;
			cube[pixels].z = i;
			pixels++;
			cube[pixels].x = j;
			cube[pixels].y = -15.0;
			cube[pixels].z = i;
			pixels++;
		}
	}
	
	for(int i = -15; i <= 15; i++) {
		for(int j = -15; j <= 15; j++) {
			cube[pixels].x = 15.0;
			cube[pixels].y = i;
			cube[pixels].z = j;
			pixels++;
			cube[pixels].x = -15.0;
			cube[pixels].y = i;
			cube[pixels].z = j;
			pixels++;
		}
	}
}

void rotate(double phi) {
	double cosphi = cos(phi);
	for(int i = 0; i < pixels; i++) {
		cube[i].x = cosphi*x;
		cube[i].y = sin(phi)*y;
		cube[i].z = cosphi*z;
	}
}

void render() {

}

int main() {
	generate();
	double angle = 0.0;
	while(1) {
		printf("\033[2J\033[6;30H");
		render();
		angle += 0.2;
		sleep(1);
		rotate(angle);
	}
}
