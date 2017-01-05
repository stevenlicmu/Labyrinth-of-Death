#ifndef TEXTSTRING_H_IS_INCLUDED
#define TEXTSTRING_H_IS_INCLUDED

class TextString
{
protected:
	char *str;
public:
	TextString();
	TextString(const TextString &incoming);
	~TextString();
	void CleanUp(void);

	TextString &operator=(const TextString &incoming);

	void CopyFrom(const TextString &incoming);

	void Add(char c);
	void Add(const char str[]);
	void BackSpace(void);

	void Set(const char incoming[]);
	const char *GetPointer(void) const;

	int Strlen(void) const;

	const char *Fgets(FILE *fp);
};

#endif