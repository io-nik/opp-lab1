//
// Created by ionik on 06.09.2024.
//

/*!
\file
\brief Заголовочный файл с описанием структуры Part

Данный файл содержит в себе определения структуры Part и функций, использующихся для проверки программы в тестах
*/

#ifndef LAB1_PART_H
#define LAB1_PART_H

#include <iostream>

struct Part {
    std::string id;
    std::string name;
    unsigned int count{};
};

/*!
 * @brief
 * Функция получения стркутуры типа Part
 * @throw
 * -
 * @param
 * 3 параметра - id детали, name - имя детали, count - кол-во нужного кол-ва деталей
 * @return
 * структура типа Part
 */
Part create(std::string _id, std::string _name, unsigned int _count);

/*!
 * @brief
 * Функция сравнения двух структур типа Part
 * @throw
 * -
 * @param
 * Part& p1, Part& p2 - ссылки на сравниваемые структуры
 * @return
 * bool: true, если структуры идентичны, false - если нет
 */
bool compare(Part& p1, Part& p2);

#endif //LAB1_PART_H
