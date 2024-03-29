#ifndef DataEmptyException_H
#define DataEmptyException_H

#include <stdexcept>
#include <cstring>

class DataEmptyException : public std::exception
{
private:
    /* data */
    char *_msg;

public:
    /*  */
    DataEmptyException() = delete;
    DataEmptyException(const DataEmptyException &) = delete;
    DataEmptyException(DataEmptyException &&) = default;
    DataEmptyException &operator=(const DataEmptyException &) = delete;
    DataEmptyException &&operator=(DataEmptyException &&) = delete;

    DataEmptyException(const char *msg)
    {
        // strlen();
        _msg = new char[strlen(msg) + 1];
        strcpy(_msg, msg);
    }

    ~DataEmptyException()
    {
        delete _msg;
    }

    virtual const char *what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW override
    {
        return _msg;
    }
};

#endif // DataEmptyException_H