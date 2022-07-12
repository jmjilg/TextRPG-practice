

#include "Core.h"
int main()
{
	srand((unsigned int)time(0));

	GET_SINGLE(CCore)->Init();
	GET_SINGLE(CCore)->Run();
}