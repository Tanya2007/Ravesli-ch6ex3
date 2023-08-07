#include "_TBA_H.h"

std::string UTF8_to_CP1251(const std::string &utf8)
{
	if(!utf8.empty())
	{
		int wchlen = MultiByteToWideChar(CP_UTF8, 0, utf8.c_str(), -1, NULL, 0);
		if(wchlen > 0 && wchlen != 0xFFFD)
		{
			std::vector<wchar_t> wbuf(static_cast<std::size_t>(wchlen));
			MultiByteToWideChar(CP_UTF8, 0, utf8.c_str(), -1, &wbuf[0], wchlen);
			std::vector<char> buf(static_cast<std::size_t>(wchlen));
			WideCharToMultiByte(1251, 0, &wbuf[0], -1, &buf[0], wchlen, 0, 0);
			return std::string(&buf[0]);
		}
	}
	return std::string();
}