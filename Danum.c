/*************************************************************************
 > File Name: test.c
 > Author: test*/
#include"Danum.h"//这个名字霸气吧，Da_num

Danum::Danum()//Private 有三个参数，value,sign,lenth
{
	sign=0;
	lenth=0;
}

Danum::~Danum()
{

}
void Danum::Make(const char a[])//用于构造大数，读入一个字符串
{
	int note=0;
	if(a[note]=='-')
		sign=1;
	else
	{
		sign=0;
		note--;
	}
     	note++;
	while(a[note]!='\0')
	{
		value.insert(value.begin(),a[note]);
		lenth++;
		note++;
	}
}

Danum Danum::operator+ ( Danum   n)//由于需要对阶，没有用const，但后期去零保证了与原数据的一致性，好像不需要对阶。。。。
{
	int type=0;
	if(lenth!=n.lenth)//先补零对阶，可以避免一大堆讨论,缺点会浪费空间，好像浪费了挺多
	{
		if(lenth<n.lenth)
		{
			type=1;
			while(lenth<n.lenth)
			{	
                value.push_back('0');
				lenth++;
			}
		}
		else
		{
			type=2;
			while(lenth>n.lenth)
			{
				n.value.push_back('0');
				n.lenth++;
		    }
		}
	}
	Danum result;
	if(sign==n.sign)//分两种情况，符号相同与不同，相同直接加，不同直接减，减不够了反着减。突然加零没什么好处，可能调得心态炸了，下次再改吧（-W-）-￥
	{
		int ifover=0;
		int now=0;
		while(now<=lenth-1)
		{
			int sum=value[now]+n.value[now]-'0'+ifover;
			ifover=0;
			if(sum>'9')
			{
				ifover=1;
		        sum-=10;
			}
				result.value.push_back(sum);
				result.lenth++;
			now++;
		}
		if(ifover!=0)
		{
			result.lenth++;
			result.value.push_back(ifover+'0');
		}
		result.sign=sign;
	}
	else
	{
			result.sign=sign;
			int ifloss=0;
			int now=0;
			while(now<=lenth-1)
			{
				int sum=value[now]-n.value[now]+'0'+ifloss;
				ifloss=0;
				if(sum<'0')
				{
					ifloss=-1;
					sum+=9+1;
				}
					result.value.push_back(sum);
					result.lenth++;
					now++;
			}
			if(ifloss==-1)
			
	     	{
				result=n+*this;
			}
	}
	if(type==1)
	{
		int now=lenth-1;
		while(value[now]=='0')
		{
			value.pop_back();
			lenth--;
			now--;
		}
	}
	if(type==2)
	{
		int now=n.lenth-1;
		while(n.value[now]=='0')
		{
			n.value.pop_back();
			n.lenth--;
			now--;
		}

	}
	int now=result.lenth-1;
	while(result.value[now]=='0')
	{
		result.value.pop_back();
		result.lenth--;
		now--;
	}
	return result;
}

void Danum::operator= (const Danum & n) //赋值重置
{
	sign=n.sign;
	value=n.value;
	lenth=n.lenth;
}

std::ostream &  operator<< (std::ostream & os,const Danum & n)//建立友元实现‘=’重载
{
	if(n.sign==1&&n.value[0]!='0')
		os<<'-';
	for(int i=n.lenth-1;i>=0;i--)
	{
		os<<n.value[i];
	}
	return os;
}

