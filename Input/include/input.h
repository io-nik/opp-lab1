//
// Created by ionik on 07.09.2024.
//

/*!
\file
\brief Заголовочный файл с описанием функций ввода

Данный файл содержит в себе определения функций ввода, используемые для получения .json строк и структур Part
*/

#ifndef LAB1_INPUT_H
#define LAB1_INPUT_H

#include <iostream>
#include "Part.h"

namespace input {
    /*!
    * @brief структура Part описанная в файле Part.cpp
    */

    /*!
    * @brief
    * Функция получения беззнакового числа
    * @throw
    * exception типа std::runtime_error в случае конца файла или плохого ввода
    * @param
    * -
    * @return
    * Возвращает unsinged int
    */
    unsigned int getUnsgnInt();

    /*!
     * @brief
     * Функция получения поля count структуры Part
     * @throw
     * exception типа std::runtime_error в случае конца файла или неправильного ввода
     * @param
     * -
     * @return
     * Возвращает unsigned int
     */
    unsigned int getCount();

    /*!
     * @brief
     * Функция получения произвольной строки
     * @throw
     * exception типа std::runtime_error в случае конца файла или неправильного ввода
     * @param
     * -
     * @return
     * std::string
     */
    std::string getString();

    /*!
     * @brief
     * Функция получения поля id структуры Part
     * @throw
     * exception типа std::runtime_error в случае конца файла или неправильного ввода
     * @param
     * -
     * @return
     * std::string
     */
    std::string getId();

    /*!
     * @brief
     * Функция получения поля name структуры Part
     * @throw
     * exception типа std::runtime_error в случае конца файла или неправильного ввода
     * @param
     * -
     * @return
     * std::string
     */
    std::string getName();

    /*!
     * @brief
     * Функция получения структуры Part
     * @throw
     * exception типа std::runtime_error в случае конца файла или неправильного ввода
     * @param
     * -
     * @return
     * структуру типа Part
     */
    Part inputStruct();

    /*!
     * @brief
     * Функция получения строки для функции перевода строки в структуру
     * @throw
     * exception типа std::runtime_error в случае конца файла или неправильного ввода
     * @param
     * -
     * @return
     * std::string
     */
    std::string inputString();
}

#endif //LAB1_INPUT_H
