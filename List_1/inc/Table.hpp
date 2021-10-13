//
// Author: JakubSzwedowicz
// Date: 12.10.2021.
// e-mail: kuba.szwedowicz@gmail.com 
//

#ifndef LIST_1_TABLE_HPP
#define LIST_1_TABLE_HPP

#include <string>

class Table
{
private:
    std::string m_name;
    int m_size;
    int* m_array;
public:
    explicit Table();
    Table(std::string a_name, int a_size);
    Table(Table& a_other);
    ~Table();

    void set_name(std::string a_name);
    bool set_new_size(int a_new_size);
    Table* clone();

};
#endif //LIST_1_TABLE_HPP
