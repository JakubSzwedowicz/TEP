//
// Author: jakubszwedowicz
// Date: 16.12.2021.
// e-mail: kuba.szwedowicz@gmail.com 
//

#ifndef LIST_5_CONTROL_BLOCK_HPP
#define LIST_5_CONTROL_BLOCK_HPP

namespace tep
{
    class Control_Block
    {
    public:
        Control_Block();

        int get_counter() const;

        int is_valid() const;

        void decrement();

        void increment();

    private:
        int m_counter;
    };
}

#endif //LIST_5_CONTROL_BLOCK_HPP
