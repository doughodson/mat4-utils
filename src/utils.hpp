
#ifndef __utils_HPP__
#define __utils_HPP__

#include <iosfwd>
#include <cstdint>

typedef struct {
   int32_t mopt;
   int32_t nrows;
   int32_t ncols;
   int32_t imagf;
   int32_t namelen;
} MAT4Header;

int read_mat_file_header(std::istream& is, bool& swap, MAT4Header& header);


#endif
