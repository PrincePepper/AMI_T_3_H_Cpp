//
// Created by Semen Sereda on 04.10.2020.
//
#include <algorithm>

#ifndef PMI_T_3_H_CPP_BUFFERED_READER_H
#define PMI_T_3_H_CPP_BUFFERED_READER_H

class BufferedReader {
 public:
  explicit BufferedReader(PackageStream *stream) {
    stroke = stream;
    buffer = new char[2000];
  }

  ~BufferedReader() {
    delete buffer;
  }

  int32_t Read(char *output_buffer, int32_t buffer_len) {
    while (position < buffer_len) {
      package += stroke->ReadPackage(buffer + position);
      position += stroke->PackageLen();
    }
    int32_t min = std::min(package, buffer_len);
    memcpy(output_buffer, buffer, min);
    if (package > buffer_len) {
      position = package - buffer_len;
      memmove(buffer, buffer + buffer_len, package - buffer_len);
    } else {
      position = 0;
    }
    if (position != 0) {
      package = position;
    } else {
      package = 0;
    }
    return min;
  }

 private:
  PackageStream *stroke;
  char *buffer;
  int32_t position = 0;
  int32_t package = 0;
};

#endif  // PMI_T_3_H_CPP_BUFFERED_READER_H
