#pragma once
#include "Init.h"
#include <fstream>
#include <iostream>
using namespace std;

// load map
void readMap(GLuint tilemap[MAP_H][MAP_W])
{
	ifstream map;
	cout<<"Which map should be loaded?"<< endl;
	cout<<"1:A straight start to end race"<<endl;
	cout<<"2:A loop circuit for infinite driving:"<<endl;
	cout<<"(1/2): ";
	char ans;
	cin>>ans;

	if (ans=='1') {	
		map.open("pointrace.txt"); }
	else
	{
		if (ans=='2') {
			map.open("loop.txt"); }
		else
			exit(0);
	}
	
	if (!map.is_open())
	{
		cout<<"cannot find map data!"<<endl;
		system("pause");
		exit(1);
	}

	for (int i=0;i<MAP_H;i++)
	{
		for (int j=0;j<MAP_W;j++)
		{
			map>>tilemap[i][j];
		}
	}

	map.close();
}

