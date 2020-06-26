<<<<<<< HEAD
#include<stdio.h>

enum {XMAX = 10,YMAX};

struct point
{
  	int x;
  	int y;
};
struct rect
{
	struct point p1;
	struct point p2;
};

struct rect screen;
struct point middle;

/* makepoint :assigns coordinates to structure members*/
struct point makepoint(int x,int y)
{
	struct point temp;
	temp.x = x;
	temp.y = y;

	return temp;
}

/* addpt():add two points*/
struct point addpt(struct point a1,struct point a2)
{
	a1.x = a1.x + a2.x; 
	a1.y = a1.y + a2.y;
	return a1; 
}
/* ptinrect() : i sgiven pt is in rect or not */
int ptinrect(struct point p, struct rect r)
{
	return p.x >= r.p1.x && p.x <= r.p2.x && p.y >=  r.p1.y && p.y <= r.p2.y;
}
int main()
{
	/* ex1
	screen.p1 = makepoint(0,0);	
	screen.p2 = makepoint(XMAX,YMAX);	
	
	middle = makepoint((screen.p1.x + screen.p2.x)/2,
						(screen.p1.y + screen.p2.y)/2);
	printf("middle.x = %d,middle.y = %d\n",middle.x,middle.y);
	*/
	
	/* ex2
	struct point result,x1 = {40,96},y1 = {50,60};
	result = addpt(x1,y1);
	printf("result.x = %d,result.y = %d\n",result.x,result.y);
	*/

	/* ex3 */

	screen.p1 = makepoint(5,15);
	screen.p2 = makepoint(20,25);
	struct point pts = {12,22};

	if(ptinrect(pts,screen))
		printf("Yes its in Rectangle\n");
	else
		printf("No not in Rectangle\n");

  	return 0;
=======
#include<stdio.h>

enum {XMAX = 10,YMAX};

struct point
{
  	int x;
  	int y;
};
struct rect
{
	struct point p1;
	struct point p2;
};

struct rect screen;
struct point middle;

/* makepoint :assigns coordinates to structure members*/
struct point makepoint(int x,int y)
{
	struct point temp;
	temp.x = x;
	temp.y = y;

	return temp;
}

/* addpt():add two points*/
struct point addpt(struct point a1,struct point a2)
{
	a1.x = a1.x + a2.x; 
	a1.y = a1.y + a2.y;
	return a1; 
}
/* ptinrect() : i sgiven pt is in rect or not */
int ptinrect(struct point p, struct rect r)
{
	return p.x >= r.p1.x && p.x <= r.p2.x && p.y >=  r.p1.y && p.y <= r.p2.y;
}
int main()
{
	/* ex1
	screen.p1 = makepoint(0,0);	
	screen.p2 = makepoint(XMAX,YMAX);	
	
	middle = makepoint((screen.p1.x + screen.p2.x)/2,
						(screen.p1.y + screen.p2.y)/2);
	printf("middle.x = %d,middle.y = %d\n",middle.x,middle.y);
	*/
	
	/* ex2
	struct point result,x1 = {40,96},y1 = {50,60};
	result = addpt(x1,y1);
	printf("result.x = %d,result.y = %d\n",result.x,result.y);
	*/

	/* ex3 */

	screen.p1 = makepoint(5,15);
	screen.p2 = makepoint(20,25);
	struct point pts = {12,22};

	if(ptinrect(pts,screen))
		printf("Yes its in Rectangle\n");
	else
		printf("No not in Rectangle\n");

  	return 0;
>>>>>>> 4b0d632f0ae60fef75da6c73052e705dbc271f56
}