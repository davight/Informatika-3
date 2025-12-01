#ifndef LIBDF_DATAFRAME_HPP
#define LIBDF_DATAFRAME_HPP
#include <vector>

namespace df {

    template<typename T>
    class DataFrame {
        public:
            DataFrame(std::vector<T> data);
            void print(std::ostream &ost) const;
            std::size_t size() const;

            template<typename Extractor>
            const T* min(Extractor extractor) const;

            template<typename Extractor>
            const T* max(Extractor extractor) const;

            template<typename Predicate>
            std::vector<const T*> filter(Predicate predicate) const;

            template<typename ValueType, typename Extractor>
            const ValueType mean(Extractor extractor) const;

            template<typename F>
            void apply(F fun) const;
        private:
            std::vector<T> m_data;
    };

    template<typename T>
    DataFrame<T>::DataFrame(std::vector<T> data) : m_data(data)
    {
    }

    template<typename T>
    void DataFrame<T>::print(std::ostream &ost) const
    {
        //ost << "Pocet dat: " << m_data.size() << "\n";
    }

    template<typename T>
    std::size_t DataFrame<T>::size() const
    {
        return m_data.size();
    }

    template<typename T>
    template<typename Extractor>
    const T* DataFrame<T>::min(Extractor extractor) const
    {
        const T* min = &m_data[0];
        for (const T &value : m_data)
        {
            if (extractor(value) < extractor(*min))
            {
                min = &value;
            }
        }
        return min;
    }


    template<typename T>
    template<typename Extractor>
    const T* DataFrame<T>::max(Extractor extractor) const
    {
        const T* max = &m_data[0];
        for (const T &value : m_data)
        {
            if (extractor(value) > extractor(*max))
            {
                max = &value;
            }
        }
        return max;
    }

    template<typename T>
    template<typename Predicate>
    std::vector<const T*> DataFrame<T>::filter(Predicate predicate) const
    {
        std::vector<const T*> result;
        result.reserve(m_data.size());
        for (const T &value : m_data)
        {
            if (predicate(value))
            {
                result.push_back(&value);
            }
        }
        result.shrink_to_fit();
        return result;
    }


    template<typename T>
    template<typename ValueType, typename Extractor>
    const ValueType DataFrame<T>::mean(Extractor extractor) const
    {
        ValueType sum {};
        auto size = static_cast<ValueType>(m_data.size());
        for (const T &value : m_data)
        {
            sum += static_cast<ValueType>(extractor(value));
        }
        return sum / size;
    }

    template<typename T>
    template<typename F>
    void DataFrame<T>::apply(F fun) const
    {
        for (auto &value : m_data)
        {
            fun(value);
        }
    }


} // namespace df

#endif
