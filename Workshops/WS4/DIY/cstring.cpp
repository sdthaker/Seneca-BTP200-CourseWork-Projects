// Workshop 3 Lab
// Name: Soham Thaker
// SID: 011-748-159
//Email: sdthaker1@myseneca.ca
//Date of Completion: 2021/02/01
//The below code is my not own code and I have used professor's logic for strStr and strCat function


#include "cstring.h"

namespace sdds {

	void strCpy(char* des, const char* src) {

		int srcLen = strLen(src), j;

		for (j = 0; j < srcLen+1; j++)
			des[j] = src[j];
	}

	void strnCpy(char* des, const char* src, int len) {

		/*int srcLen = strLen(src);

		if (len > srcLen) {
			
			int i = 0;
			for (i = 0; i < srcLen; i++)
					des[i] = src[i];
			des[i] = '\0';
		}
		else {
			int i = 0;
			for (i = 0; i < len; i++)
				des[i] = src[i];
			des[i] = '\0';
		}*/
		int i = 0;
		for (i = 0; i < len; i++)
			des[i] = src[i];
		//des[i] = '\0';
	}

	int strCmp(const char* s1, const char* s2) {

		int len = strLen(s1);
		int flag = 0;

		for (int i = 0; i < len && !flag; i++) {

			if (s1[i] == s2[i])
				flag = 0;
			else if (s1[i] > s2[i])
				flag = 1;
			else
				flag = -1;
		}
		return flag;
	}

	int strnCmp(const char* s1, const char* s2, int len) {
		
		int flag = 0;

		for (int i = 0; i < len; i++) {

			if ((int)s1[i] < (int)s2[i])
				return -1;
			else if ((int)s1[i] > (int)s2[i])
				return 1;
			else
				flag = 0;
		}
		return flag;
	}

	int strLen(const char* s) {

		int i = 0;

		for (i = 0; s[i] != '\0'; i++);

		return i;
	}

	const char* strStr(const char* str1, const char* str2) {

		auto len1 = strLen(str1);
		auto len2 = strLen(str2);
		for (auto i = 0; i < len1 - len2; ++i)
			if (strnCmp(&str1[i], str2, len2) == 0)
				return &str1[i];
		return nullptr;
	}

	void strCat(char* des, const char* src) {

		auto len = strLen(des);
		strCpy(&des[len], src);
	}
}