//
// Created by User on 04.10.2020.
//

#ifndef PMI_T_3_H_CPP_BUFFERED_READER_H
#define PMI_T_3_H_CPP_BUFFERED_READER_H

class BufferedReader {
public:
    explicit BufferedReader(PackageStream *stream);

    int32_t Read(char *output_buffer, int32_t buffer_len);
};

#endif //PMI_T_3_H_CPP_BUFFERED_READER_H
