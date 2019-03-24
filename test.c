/*************************************************************************
 > File Name: test.c
 > Author: test*/

#include"Danum.h"
#include<iostream>

int main()
{
	char a[1000];
	char b[1000];
	Danum aa;
	Danum bb;
	std::cout<<"你们要的大数加和简略版"<<std::endl;
	std::cout<<"有BUG别忘了告诉我嗷"<<std::endl;
    std::cin>>a;
	aa.Make(a);
	std::cin>>b;
	bb.Make(b);
	Danum cc;
	cc=aa+bb;
	cc=cc+cc;
	std::cout<<cc<<std::endl;
}
