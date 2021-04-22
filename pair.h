// klasa pair opisuje pare liczb w ktorej pierwsza wartosc jest znaczaca, porownywana 
// druga wartosc nie ma zadnych przywilejow
// 
// Autor: Piotr Drabik				Data: 04.02.2021

#ifndef PAIR_H
#define PAIR_H

namespace my {


    template<class KEY, class VAL>
    class pair{
    public:
        pair<KEY,VAL>() {
            first = KEY(0);
            second = VAL(0);
        }

        // kostruktor kopiujacy generowany jest automatycznie

        pair<KEY,VAL>(KEY x , VAL y):first(x),second(y) {}


        explicit pair(const KEY &x) {
            first = x;
            second = VAL(0);
        }

        pair(const pair<KEY,VAL> &y) {
            first = y.first;
            second = y.second;
        };

         pair<KEY,VAL> &operator=(const pair<KEY,VAL> &y) {
            if (this == &y) return *this;
            first = y.first;
            second = y.second;
            return *this;
        }

        bool operator==(const pair<KEY,VAL> &rhs) const { return first == rhs.first; };

        bool operator!=(const pair<KEY,VAL> &rhs) const { return first != rhs.first; };

        bool operator<(const pair<KEY,VAL> &rhs) const { return first < rhs.first; };

        bool operator>(const pair<KEY,VAL> &rhs) const { return first > rhs.first; };

        bool operator<=(const pair<KEY,VAL> &rhs) const { return first <= rhs.first; };

        bool operator>=(const pair<KEY,VAL> &rhs) const { return first >= rhs.first; };

        ~pair<KEY, VAL>() = default;


        KEY first; // key 
        VAL second; // value


    };

}
#endif // !PAIR_H

