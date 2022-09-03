#ifndef CGC_ASCII
#define CGC_ASCII
#ifndef ASCII_H
#define ASCII_H

class AsciiInterface
{
public:
    AsciiInterface() {}
    ~AsciiInterface() {}
    virtual bool is_ascii(char *_stream) = 0;
};

#endif

#endif // CGC_ASCII
