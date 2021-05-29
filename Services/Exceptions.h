#include <exception>

struct UnknownSensorException : public std::exception
{

};

struct UnknownCleanerException : public std::exception
{

};

struct EmptyReadingsException : public std::exception
{

};

struct TimeSpanOutOfBoundException : public std::exception
{

};

struct LocationTooFarAwayException : public std::exception
{

};

struct AccountDoNoExistException : public std::exception
{

};

struct IncorrectPasswordException : public std::exception
{

};

struct AccountAlreadyExistsException : public std::exception
{

};