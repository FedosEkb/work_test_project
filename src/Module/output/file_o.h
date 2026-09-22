/**
 * @file file_o.h
 * @author Baranov (you@domain.com)
 * @brief Наследник для работы c файлом
 * @version 0.1
 * @date 2026-09-22
 * 
 * @copyright Copyright (c) 2026
 * 
 */
#ifndef FILE_O_H
#define FILE_O_H

#include "i_base_output.h"
#include <iostream>
#include <limits>
#include <fstream>
#include <stdexcept>
#include <cerrno>
#include <cstring>
#include <string>

/**
 * @brief Наследник для работы с файлом
 * 
 */
class file_o final: public i_base_output
{
    std::ofstream stream_;
public:

    /**
     * @brief Запись данных
     * 
     * @param to_set контейнер задля записи
     * @param elem_to_print количество элементов для записи в контейнере
     * @return true была произведена последняя запись 
     * @return false запись не закончина
     */
    bool set_data(const std::array<double, stream_over_flag::arr_len>& to_set, size_t elem_to_print) override;

    /**
     * @brief Конструктор для работы с файлом
     *
     * @param file_name имя открываемого файла
     *
     * @throws std::runtime_error Если файл не удалось открыть. Сообщение
     *                            содержит имя файла и системную ошибку (errno).
     */
    explicit file_o(const std::string& file_name);
    ~file_o() = default;
};

#endif /* FILE_O_H */