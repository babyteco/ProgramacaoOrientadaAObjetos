#ifndef MYSTRING_H
#define MYSTRING_H

class String {
public:
    String(const char* dado = "", int tamanho = 0);
    String(const String& other);
    String operator=(const String& other);
    String operator+(const String& s1) const;
    const char* c_str() const;
private:
    char* _data;
    int tam;
};


#endif
