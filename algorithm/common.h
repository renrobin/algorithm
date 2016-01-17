
#define ARRAY_SIZE(a) (sizeof(a)/sizeof(a[0]))


inline void printArray(int data[], int size)
{
	for (int i=0; i<size; ++i)
	{
		std::cout<<data[i]<<'\t';
	}
	std::cout<<"\n";
}

// print elements in range [l,u] of the array
inline void printArray(int data[], int l, int u)
{
	for (int i=l; i<=u; ++i)
	{
		std::cout<<data[i]<<'\t';
	}
	std::cout<<"\n";
}