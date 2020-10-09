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
  }

  int32_t Read(char *output_buffer, int32_t buffer_len) {
    buffer = new char[strlen(output_buffer) + 1];
    int32_t position = 0;
    int32_t package = 0;
    while (position < buffer_len && package <= stroke->PackageLen()) {
      package += stroke->ReadPackage(buffer + position);
      position += stroke->PackageLen();
    }
    int32_t min = std::min(package, buffer_len);
    memcpy(output_buffer, buffer, min);
    return min;
  }

 private:
  PackageStream *stroke;
  char *buffer;
};

#endif  // PMI_T_3_H_CPP_BUFFERED_READER_H
