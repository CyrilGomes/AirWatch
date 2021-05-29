#include<exception>

struct UnknownSensorException : public std::exception
{
	const char * what () const throw ()
    {
    	return "(!) The entered Sensor ID is unknown";
    }
};

struct UnknownCleanerException : public std::exception
{
	const char * what () const throw ()
    {
    	return "(!) The entered Cleaner ID is unknown";
    }
};

struct EmptyReadingsException : public std::exception
{
	const char * what () const throw ()
    {
    	return "(!) There is no readings in this Sensor";
    }
};

struct TimeSpanOutOfBoundException : public std::exception
{
	const char * what () const throw ()
    {
    	return "(!) The time period you entered is not in the scope of the database";
    }
};

struct LocationTooFarAwayException : public std::exception
{
	const char * what () const throw ()
    {
    	return "(!) The entered location is too far away from any sensors";
    }
};

struct AccountDoNoExistException : public std::exception
{
	const char * what () const throw ()
    {
    	return "(!) Given account does not exist, please try again";
    }
};

struct IncorrectPasswordException : public std::exception
{
	const char * what () const throw ()
    {
    	return "(!) Incorrect password, please try again";
    }
};

struct AccountAlreadyExistsException : public std::exception
{
	const char * what () const throw ()
    {
    	return "(!) Given account already exists, please try again";
    }
};