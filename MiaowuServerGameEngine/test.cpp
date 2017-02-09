#include<cstdio>
#include<iostream>
#include"miaowuEngine.h"
int main() 
{
	NormalWorld world;
	Transform t = new ClassTransform(10.2f, 200);
	if (world.insertTransform(t))
	{
		printf("insertOK\n");
	}
	if (world.deleteTransform(t))
	{
		printf("deleteOK\n");
	}
	system("pause");
}