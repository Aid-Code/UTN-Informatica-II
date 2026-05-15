#ifndef STRING_H
#define STRING_H

class String
{
    private:



    public:
        char *inicio;
        int longitud;
        String(char*, int);
        ~String();
        void operator+=(char);
};

#endif // STRING_H
