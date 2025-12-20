//
// Created by david on 12/17/2025.
//

#ifndef DATA_PROCESSOR_WRITER_HPP
#define DATA_PROCESSOR_WRITER_HPP
#include <filesystem>
#include <fstream>

#include "data_frame.hpp"

namespace df
{
    template<typename T>
    class Writer {
        public:
            virtual ~Writer() = default;
            void write(const DataFrame<T> &df, const std::filesystem::path &path);
        protected:
            virtual void writeImpl(const DataFrame<T> &df, std::ostream &ost) = 0;
    };

    template<typename T>
    void Writer<T>::write(const DataFrame<T> &df, const std::filesystem::path &path)
    {
        std::ofstream ofs(path);
        if (!ofs.is_open())
        {
            throw std::runtime_error("Failed to open: " + path.string());
        }
        writeImpl(df, ofs);
    }


}

#endif //DATA_PROCESSOR_WRITER_HPP