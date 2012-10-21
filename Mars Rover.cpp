/*@@
Author:	Justinzhang
Email:	uestczhangchao@gmail.com
Time:	2012年10月13日20:33:37
Desc:	ThoughtWork's Assignments.
@@*/
#include <iostream>
#include <string>
using namespace std;

/*The robot's x, y value and direction*/
typedef struct 
{
	int x;
	int y;
	char facing;
}coordinate;

class Rover
{
public:
	coordinate p;
	
	Rover(int x, int y, char dir)
	{
		p.x = x;
		p.y = y;
		p.facing = dir;
	};
	/*show robot's position and direction*/
	void show_robots()
	{
		cout << p.x << " " << p.y << " " << p.facing <<endl;
	}
	/*process the commands*/
	void process(string commands)
	{
		for (int idx = 0; idx < commands.length(); idx++) {
			process(commands.at(idx));
		}
	}
	
private:
	/*
	process every tiny mommand namely: L R and M, if the command is wrong,
	exit the program
	*/
	void process(char command) {
		if (command =='L') {
			turnLeft();
		} else if (command =='R') {
			turnRight();
		} else if (command == 'M') {
			move();
		} else {
			cout << "wrong command, reenter angin" << endl;
			throw (1);
		}
	}
	/*move command will change the robot's coordinate*/
	void move() {
		if (p.facing == 'N') {
			p.y++;
		} else if (p.facing == 'E') {
			p.x++;
		} else if (p.facing == 'S') {
			p.y--;
		} else if (p.facing == 'W') {
			p.x--;
		}
	}
	/*corespond to the L command, this function fill change the robot's direction*/
	void turnLeft() 
	{
		switch(p.facing)
		{
		case 'N':
			p.facing = 'W';
			break;
		case 'W':
			p.facing = 'S';
			break;
		case 'S':
			p.facing = 'E';
			break;
		case 'E':
			p.facing = 'N';
			break;
		}
	}
	/*corespond to the R command, this command will change the robot's direction*/
	void turnRight() 
	{
		switch(p.facing)
		{
		case 'N':
			p.facing = 'E';
			break;
		case 'E':
			p.facing = 'S';
			break;
		case 'S':
			p.facing = 'W';
			break;
		case 'W':
			p.facing = 'N';
			break;
		}
	}
};

int main()
{
	int x = 0, y = 0;
	char dir = 'N';
	string commands;
	before:
	cout << "please input robot's x y and direction!" << endl;
	cin >> x >> y >> dir;
	cout << "please input robot's commands" << endl;

	Rover r(x,y,dir);
	next:;
	cin >> commands;
	try
	{
	r.process(commands);
	r.show_robots();
	goto before;
	}
	catch(int x)
	{
		if(x == 1)
		{
			cout << "command error found, reenter commands" << endl;
			goto next;
		}

	}
	return 0;
}