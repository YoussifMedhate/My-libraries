#include <iostream>
#include <vector>
#include <string>
using namespace std;
#pragma once
class clsString
{
private:
	string _Value;
public:
	
	//constructors
	clsString()
	{
		_Value = "";
	}
	clsString(const string value)
	{
		this->_Value = value;
	}

	//property
	string getValue()
	{
		return this->_Value;
	}

	void setValue(const string value)
	{
		this->_Value = value;
	}

	__declspec(property(get = getValue, put = setValue)) string Value;

	// Static main methods
	static vector <string> splitString(string value, const string deli = " ")
	{
		vector <string> vectorOfValuse;
		string word;
		int pos;
		while ((pos = value.find(deli)) != string::npos)
		{
			word = value.substr(0, pos);
			if (word != "")
			{
				vectorOfValuse.push_back(word);
			}
			value = value.erase(0, pos + deli.length());
		}
		if (value != "")
		{
			vectorOfValuse.push_back(value);
		}
		return vectorOfValuse;

	}

	static short Length(string S1)
	{
		return S1.length();
	};

	static short CountWords(string S1)
	{

		string delim = " ";   
		short Counter = 0;
		short pos = 0;
		string sWord;
		while ((pos = S1.find(delim)) != std::string::npos)
		{
			sWord = S1.substr(0, pos);    
			if (sWord != "")
			{
				Counter++;
			}

			S1.erase(0, pos + delim.length());
		}

		if (S1 != "")
		{
			Counter++;
		}

		return Counter;

	}

	static string  UpperFirstLetterOfEachWord(string S1)
	{

		bool isFirstLetter = true;

		for (short i = 0; i < S1.length(); i++)
		{

			if (S1[i] != ' ' && isFirstLetter)
			{
				S1[i] = toupper(S1[i]);

			}

			isFirstLetter = (S1[i] == ' ' ? true : false);

		}

		return S1;
	}
	
	static string  LowerFirstLetterOfEachWord(string S1)
	{

		bool isFirstLetter = true;

		for (short i = 0; i < S1.length(); i++)
		{

			if (S1[i] != ' ' && isFirstLetter)
			{
				S1[i] = tolower(S1[i]);

			}

			isFirstLetter = (S1[i] == ' ' ? true : false);

		}

		return S1;
	}

	static string  UpperAllString(string S1)
	{
		for (short i = 0; i < S1.length(); i++)
		{
			S1[i] = toupper(S1[i]);
		}
		return S1;
	}

	static string  LowerAllString(string S1)
	{
		for (short i = 0; i < S1.length(); i++)
		{
			S1[i] = tolower(S1[i]);
		}
		return S1;
	}

	static char  InvertLetterCase(char char1)
	{
		return isupper(char1) ? tolower(char1) : toupper(char1);
	}

	static string  InvertAllLettersCase(string S1)
	{
		for (short i = 0; i < S1.length(); i++)
		{
			S1[i] = InvertLetterCase(S1[i]);
		}
		return S1;
	}

	static short  CountCapitalLetters(string S1)
	{

		short Counter = 0;

		for (short i = 0; i < S1.length(); i++)
		{

			if (isupper(S1[i]))
				Counter++;

		}

		return Counter;
	}

	static short  CountSmallLetters(string S1)
	{

		short Counter = 0;

		for (short i = 0; i < S1.length(); i++)
		{

			if (islower(S1[i]))
				Counter++;

		}

		return Counter;
	}

	static short  CountSpecificLetter(string S1, char Letter, bool MatchCase = true)
	{

		short Counter = 0;

		for (short i = 0; i < S1.length(); i++)
		{

			if (MatchCase)
			{
				if (S1[i] == Letter)
					Counter++;
			}
			else
			{
				if (tolower(S1[i]) == tolower(Letter))
					Counter++;
			}

		}

		return Counter;
	}

	static bool IsVowel(char Ch1)
	{
		Ch1 = tolower(Ch1);

		return ((Ch1 == 'a') || (Ch1 == 'e') || (Ch1 == 'i') || (Ch1 == 'o') || (Ch1 == 'u'));

	}

	static short  CountVowels(string S1)
	{

		short Counter = 0;

		for (short i = 0; i < S1.length(); i++)
		{

			if (IsVowel(S1[i]))
				Counter++;

		}

		return Counter;
	}

	static string TrimLeft(string S1)
	{


		for (short i = 0; i < S1.length(); i++)
		{
			if (S1[i] != ' ')
			{
				return S1.substr(i, S1.length() - i);
			}
		}
		return "";
	}

	static string TrimRight(string S1)
	{


		for (short i = S1.length() - 1; i >= 0; i--)
		{
			if (S1[i] != ' ')
			{
				return S1.substr(0, i + 1);
			}
		}
		return "";
	}

	static string Trim(string S1)
	{
		return (TrimLeft(TrimRight(S1)));

	}

	static string JoinString(vector<string> vString, string Delim)
	{

		string S1 = "";

		for (string& s : vString)
		{
			S1 = S1 + s + Delim;
		}

		return S1.substr(0, S1.length() - Delim.length());


	}

	static string JoinString(string arrString[], short Length, string Delim)
	{

		string S1 = "";

		for (short i = 0; i < Length; i++)
		{
			S1 = S1 + arrString[i] + Delim;
		}

		return S1.substr(0, S1.length() - Delim.length());

	}
	
	static string ReverseWordsInString(string S1)
	{

		vector<string> vString;
		string S2 = "";

		vString = splitString(S1, " ");

		// declare iterator
		vector<string>::iterator iter = vString.end();

		while (iter != vString.begin())
		{

			--iter;

			S2 += *iter + " ";

		}

		S2 = S2.substr(0, S2.length() - 1); //remove last space.

		return S2;
	}

	static string ReplaceWord(string S1, string StringToReplace, string sRepalceTo, bool MatchCase = true)
	{

		vector<string> vString = splitString(S1, " ");

		for (string& s : vString)
		{

			if (MatchCase)
			{
				if (s == StringToReplace)
				{
					s = sRepalceTo;
				}

			}
			else
			{
				if (LowerAllString(s) == LowerAllString(StringToReplace))
				{
					s = sRepalceTo;
				}

			}

		}

		return JoinString(vString, " ");
	}

	static string RemovePunctuations(string S1)
	{

		string S2 = "";

		for (short i = 0; i < S1.length(); i++)
		{
			if (!ispunct(S1[i]))
			{
				S2 += S1[i];
			}
		}

		return S2;

	}


	// Object main methods
	vector <string> split(string deli = " ")
	{
		return splitString(_Value, deli);
	}

	short Length()
	{
		return this->_Value.length();
	};

	short CountWords()
	{
		return CountWords(_Value);
	}

	string  UpperFirstLetterOfEachWord()
	{
		return UpperFirstLetterOfEachWord(_Value);
	}

	string  LowerFirstLetterOfEachWord()
	{
		return LowerFirstLetterOfEachWord(_Value);
	}

	string  UpperAllString()
	{

		return UpperAllString(_Value);
	}

	string  LowerAllString()
	{

		return LowerAllString(_Value);

	}

	void  InvertAllLettersCase()
	{
		_Value = InvertAllLettersCase(_Value);
	}

	short  CountCapitalLetters()
	{
		return CountCapitalLetters(_Value);
	}

	short  CountSmallLetters()
	{
		return CountSmallLetters(_Value);
	}
	
	short  CountSpecificLetter(char Letter, bool MatchCase = true)
	{
		return CountSpecificLetter(_Value, Letter, MatchCase);
	}

	short  CountVowels()
	{
		return CountVowels(_Value);
	}

	void TrimLeft()
	{
		_Value = TrimLeft(_Value);
	}

	void TrimRight()
	{
		_Value = TrimRight(_Value);
	}

	void Trim()
	{
		_Value = Trim(_Value);
	}

	void ReverseWordsInString()
	{
		_Value = ReverseWordsInString(_Value);
	}

	string ReplaceWord(string StringToReplace, string sRepalceTo)
	{
		return ReplaceWord(_Value, StringToReplace, sRepalceTo);
	}

	void RemovePunctuations()
	{
		_Value = RemovePunctuations(_Value);
	}

};

