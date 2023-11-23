#include "CheckBracket.h"

CheckBracket::CheckBracket(std::string Src)
	: Src(Src), Stack(new LStack<char>), iStrSize(Src.length()) {}

CheckBracket::~CheckBracket()
{
	delete Stack;
	Stack = nullptr;
}

bool CheckBracket::Check()
{
	bool Ret = true;
	if (iStrSize > 0)
	{
		char szTmp;
		for (int i = 0; i < iStrSize; ++i)
		{
			szTmp = Src[i];

			switch (szTmp)
			{
			case'(':
				Stack->Push(szTmp);
				continue;
			case'{':
				Stack->Push(szTmp);
				continue;
			case'[':
				Stack->Push(szTmp);
				continue;

			case ')':
				if (Stack->IsEmpty())
				{
					return false;
				}
				else
				{
					if ('(' == Stack->Pop())
					{
						continue;
					}
					else
					{
						return false;
					}
				}
			case '}':
				if (Stack->IsEmpty())
				{
					return false;
				}
				else
				{
					if ('{' == Stack->Pop())
					{
						continue;
					}
					else
					{
						return false;
					}
				}

			case ']':
				if (Stack->IsEmpty())
				{
					return false;
				}
				else
				{
					if ('[' == Stack->Pop())
					{
						continue;
					}
					else
					{
						return false;
					}
				}
			default:
				continue;
			}
		}
	}
	else
	{
		std::cout << "Please Input String Rightly" << std::endl;
		return false;
	}
}