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
        private:
            std::vector<T> m_data;
    };
} // namespace df

#endif
