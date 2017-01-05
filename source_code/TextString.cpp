#include <string.h>
#include <stdio.h>
#include "TextString.h"

TextString::TextString()
{
	str = nullptr;
}
TextString::TextString(const TextString &incoming)
{
	str = nullptr;
	CopyFrom(incoming);
}
TextString::~TextString()
{
	CleanUp();
}

TextString &TextString::operator=(const TextString &incoming)
{
	CopyFrom(incoming);
	return *this;
}

void TextString::CopyFrom(const TextString &incoming)
{
	Set(incoming.GetPointer());
}

void TextString::CleanUp(void)
{
	if (nullptr != str)
	{
		delete[] str;
		str = nullptr;
	}
}

void TextString::Add(char c)
{
	if (nullptr == str)
	{
		const char newStr[2] = { c,0 };
		Set(newStr);
	}
	else
	{
		// Allocate
		auto l = strlen(str);
		char *newStr = new char[l + 2];

		// Copy
		strcpy(newStr, str);
		newStr[l] = c;
		newStr[l + 1] = 0;

		// Set(newStr);
		// delete [] newStr;

		// CleanUp
		CleanUp();

		// Re-point
		str = newStr;
	}
}

void TextString::Add(const char str[])
{
	for (int i = 0; str[i] != 0; ++i)
	{
		Add(str[i]);
	}
}

void TextString::Set(const char incoming[])
{
	if (incoming != str)
	{
		auto l = strlen(incoming);
		char *newStr = new char[l + 1];
		strcpy(newStr, incoming);

		CleanUp();

		str = newStr;
	}
}

void TextString::BackSpace(void)
{
	if (nullptr != str)
	{
		auto l = strlen(str);
		// Quick version
		// if(0<l)
		// {
		// 	str[l-1]=0;
		// }

		if (0<l)
		{
			str[l - 1] = 0;

			// Allocate
			char *newStr = new char[l];

			// Copy
			strcpy(newStr, str);

			// CleanUp
			CleanUp();

			// Re-point
			str = newStr;
		}
	}
}

const char *TextString::GetPointer(void) const
{
	if (nullptr != str)
	{
		return str;
	}
	else
	{
		return "";
	}
}

int TextString::Strlen(void) const
{
	return strlen(GetPointer());
}

const char *TextString::Fgets(FILE *fp)
{
	CleanUp();

	char str[16];
	for (;;)
	{
		if (nullptr != fgets(str, 15, fp))
		{
			for (int i = 0; str[i] != 0; ++i)
			{
				if (str[i] == '\n')
				{
					return GetPointer();
				}
				Add(str[i]);
			}
		}
		else
		{
			if (0<Strlen())
			{
				return GetPointer();
			}
			else
			{
				return nullptr;
			}
		}
	}
}