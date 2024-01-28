// Name: Meetpal Singh
// Seneca Student ID: 125926212
// Seneca email: msingh683@myseneca.ca
// Date of completion: 2023/4/8
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.


#ifndef UTILITIES_H

#define UTILITIES_H


#include <string>

namespace sdds {


	class Utilities
	{
	public:
	

		void setFieldWidth(size_t newWidth);

		size_t getFieldWidth() const;

		std::string extractToken(const std::string& str, size_t& next_pos, bool& more);

		static void setDelimiter(char newDelimiter);

		static char getDelimiter();

	private:
		static char m_delimiter;
		size_t m_widthField=1;

	};


}

#endif // !UTILITIES_h
