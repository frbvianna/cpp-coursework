#ifndef __I_PRINTABLE__H__
#define __I_PRINTABLE__H__
#include <iostream>
class I_Printable {
    friend std::ostream &operator<<(std::ostream &os, const I_Printable &obj);
public:
    virtual void print(std::ostream &os) const = 0;
    virtual ~I_Printable() = default;
};
#endif  //!__I_PRINTABLE__H__