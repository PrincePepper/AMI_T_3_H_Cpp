//
// Created by Semen Sereda on 04.10.2020.
//

#ifndef PMI_T_3_H_CPP_BUFFERED_READER_H
#define PMI_T_3_H_CPP_BUFFERED_READER_H

class BufferedReader {
 public:
  explicit BufferedReader(PackageStream *stream) {
    stroke = stream;
    packageLen = stream->PackageLen();
  }

  int32_t Read(char *output_buffer, int32_t buffer_len) {
    buffer = output_buffer;
    int position = 0;
    int32_t package_len = stroke->ReadPackage(buffer);
    while (position < buffer_len && packageLen <= stroke->PackageLen()) {
      package_len = stroke->ReadPackage(buffer);
      int32_t len = min(package_len, buffer_len);
      package_len -= buffer_len;
      memcpy(output_buffer + position, buffer + position, len);
    }
  }
 private:
  PackageStream *stroke;
  int32_t packageLen;
  char *buffer;
};

#endif //PMI_T_3_H_CPP_BUFFERED_READER_H
