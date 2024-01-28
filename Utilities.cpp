// Name: Meetpal Singh
// Seneca Student ID: 125926212
// Seneca email: msingh683@myseneca.ca
// Date of completion: 2023/4/8
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.


#include "Utilities.h"


namespace sdds {

	 char Utilities::m_delimiter=' ';		// sets the default value of m_delimiter

	void Utilities::setFieldWidth(size_t newWidth) {		// sets the new value of m_widthField

		m_widthField = newWidth;
	}



	size_t Utilities::getFieldWidth() const {	// returns m_widthField
		return this->m_widthField;
	}

	std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more) {		// extracts one token from a string based on m_delimiter
		
		if (str[next_pos] == this->m_delimiter)
		{
			more = false;

			throw "Invalid token";
		}

		std::string nStr;

		size_t a = str.find(m_delimiter,next_pos+1);

		if (a != std::string::npos) {
			nStr = str.substr(next_pos, a - next_pos);
			

			bool cont = true;

			do
			{
				if (nStr.substr(0, 1) == " ")
				{
					nStr.erase(0, 1);
				}
				else
					cont = false;
			} while (cont);

			cont = true;

			do
			{
				auto i = nStr.length();

				if (nStr.substr(i - 1, 1) == " ")
				{
					nStr.erase(i - 1, 1);

				}
				else
					cont = false;

			} while (cont);


			next_pos = a + 1;

			more = true;
		}


		else
		{
			std::string tmp = str;

			tmp.erase(0,  next_pos);


			bool cont = true;

			do
			{
				if (tmp.substr(0, 1) == " ")
				{
					tmp.erase(0, 1);
				}
				else
					cont = false;
			} while (cont);


			nStr = tmp;
			more = false;
		}


		

		if (nStr.length()>m_widthField)
		{
			m_widthField = nStr.length();
		}

		return nStr;

	}

	 void Utilities::setDelimiter(char newDelimiter) {   // sets the value of m_delimiter
		 m_delimiter = newDelimiter;
	}


	 char Utilities::getDelimiter() {		// returns the value of	m_delimiter
		 return m_delimiter;
	  }

}