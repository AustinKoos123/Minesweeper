#include "Exception.h"
#include <cstring>

/**************************************************************
*	  Purpose:		Default ctor
*
*     Entry:		Object created using no parameters
*
*     Exit:			m_msg initialized to nullptr
*
****************************************************************/
Exception::Exception() : m_msg(nullptr)
{

}

/**************************************************************
*	  Purpose:		One arg ctor
*
*     Entry:		Object created using one parameter
*
*     Exit:			m_msg initialized to msg
*
****************************************************************/
Exception::Exception(char* msg) : m_msg(nullptr)
{
	m_msg = new char[strlen(msg) + 1];
	strncpy(m_msg, msg, strlen(msg) + 1);
}

/**************************************************************
*	  Purpose:		Copy ctor
*
*     Entry:		Object passed or returned by value or
*					object instantiated with another object
*
*     Exit:			this will be a copy of copy
*
****************************************************************/
Exception::Exception(const Exception &copy)
{
	*this = copy;
}

/**************************************************************
*	  Purpose:		Destructor
*
*     Entry:		Object to be destroyed
*
*     Exit:			m_msg is deleted
*
****************************************************************/
Exception::~Exception()
{
	delete[] m_msg;
	m_msg = nullptr;
}

/**************************************************************
*	  Purpose:		Operator= function
*
*     Entry:		Object assigned to another object
*
*     Exit:			this will be a copy of rhs
*
****************************************************************/
Exception& Exception::operator=(const Exception &rhs)
{
	if (this != &rhs)
	{
		delete[] m_msg;
		m_msg = nullptr;

		if (rhs.m_msg != nullptr)
		{
			int msgLen = strlen(rhs.m_msg);

			m_msg = new char[msgLen];

			for (int i = 0; i <= msgLen; i++)
			{
				m_msg[i] = rhs.m_msg[i];
			}
		}
	}
	return *this;
}

/**************************************************************
*	  Purpose:		Returns m_msg
*
*     Entry:		Function called from invoking object
*
*     Exit:			m_msg returned
*
****************************************************************/
const char* Exception::getMessage()
{
	return m_msg;
}

/**************************************************************
*	  Purpose:		Sets m_msg to msg
*
*     Entry:		Fucntion called from invoking object
*
*     Exit:			m_msg set to msg
*
****************************************************************/
void Exception::setMessage(char* msg)
{
	delete[] m_msg;
	m_msg = nullptr;

	m_msg = new char[strlen(msg) + 1];

	strcpy(m_msg, msg);
}

/**************************************************************
*	  Purpose:		Operator<< function
*
*     Entry:		<< operator called from an Exception object
*
*     Exit:			m_msg will be outputted into stream
*
****************************************************************/
ostream& operator<<(ostream &stream, const Exception &except)
{
	stream << except.m_msg << endl;
	return stream;
}