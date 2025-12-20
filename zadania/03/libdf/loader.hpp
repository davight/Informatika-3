#ifndef LIBDF_LOADER_HPP
#define LIBDF_LOADER_HPP
#include <filesystem>

#include "data_frame.hpp"

namespace df {

    template<typename T>
    class Loader {
        public:
            virtual ~Loader() = default;
            virtual DataFrame<T> load(const std::filesystem::path &path) = 0;
    };

} // namespace df

#endif
