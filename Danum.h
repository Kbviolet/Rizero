/*************************************************************************
 > File Name: test.c
 > Author: test*/
#ifndef DANUM_H_
#define DANUM_H_

#include<iostream>
#include"vector"
#include<iostream>
 using namespace std;
class Danum
{
	private:
		vector<char> value;
		int  sign;
		int lenth;
	public:
		Danum();
		~Danum();
		void Make(const char []);
		Danum operator+( Danum  n);
		void operator=(const Danum & n);
		friend std::ostream & operator<<(std::ostream & os,const Danum & n);
};
#endif
