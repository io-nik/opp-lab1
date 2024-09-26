//
// Created by ionik on 09.09.2024.
//

/*!
\file
\brief Заголовочный файл с описанием функций обработки

Данный файл содержит в себе определения функций обработки .json строк и структур Part
*/

#ifndef LAB1_PROCESS_H
#define LAB1_PROCESS_H

#include <iostream>
#include "Part.h"

namespace process {
    /*!
     * @brief
     * Функция преобразования структуры Part в .json строку
     * @throw
     * -
     * @param
     * -
     * @return
     * std::string
     */
    std::string structToString(const Part& part);

    /*!
     * @brief
     * Функция преобразования .json строки в структуру Part
     * @throw
     * -
     * @param
     * -
     * @return
     * Part
     */
    Part stringToStruct(const std::string& json);
}

#endif //LAB1_PROCESS_H
