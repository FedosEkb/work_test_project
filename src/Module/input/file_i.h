/**
 * @file file_i.h
 * @author Baranov (you@domain.com)
 * @brief Реализация для работы файлом
 * @version 0.1
 * @date 2026-09-22
 * 
 * @copyright Copyright (c) 2026
 * 
 */

#ifndef FILE_I_H
#define FILE_I_H

#include "i_base_input.h"
#include <iostream>
#include <limits>
#include <fstream>
#include <cstring>
/**
 * @brief Наследник для работы c файлом
 */
class file_i final: public i_base_input 
{
    std::ifstream stream_; 
public:
    bool get_data(std::array<double, stream_over_flag::arr_len>& to_get,  size_t & elem_was_added) noexcept override;

    /**
     * @brief Конструктор для работы с файлом
     *
     * @param file_name имя открываемого файла
     *
     * @throws std::runtime_error Если файл не удалось открыть. Сообщение
     *                            содержит имя файла и системную ошибку (errno).
     */
    explicit file_i(const std::string& file_name);
    ~file_i() = default;
};

#endif /* FILE_I_H */