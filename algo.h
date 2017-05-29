#ifndef ALGO_H
#define ALGO_H

template<typename Iter, typename T>
Iter auFind(Iter beg, Iter end, const T& k)
{
	while(beg != end and *beg != k) 
	{
		++beg;
	}
	return beg;
}
#endif
