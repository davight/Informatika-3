//
// Created by david on 11/18/2025.
//

#include "data_frame.hpp"

namespace df
{
    template<typename T>
    DataFrame<T>::DataFrame(std::vector<T> data) : m_data(data)
    {
    }

    template<typename T>
    void DataFrame<T>::print(std::ostream &ost) const
    {
        ost << m_data;
    }

    template<typename T>
    std::size_t DataFrame<T>::size() const
    {
        return m_data.size();
    }

}
