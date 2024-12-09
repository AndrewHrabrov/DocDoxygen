/** @file
 * @author Храбров А.А.
 * @version 1.0
 * @date 09.12.2024
 * @copyright ИБСТ ПГУ
 * @warning Тестовый
 * @brief Заголовочный файл для модуля table.cpp
*/

#pragma once
#include <string>
#include <vector>
#include <stdexcept>

/** @brief Шифрование методом табличной 
 * маршрутной перестановки
 * @details Ключ устанавливается в конструкторе.
 * Для зашифровывания и расшифровывания предназначены методы 
 * encrypt и decrypt.
 */

class tableCipher {
public:
    /** @brief Конструктор для установки ключа
     * @param [in] columns Строка-ключ
     */
    tableCipher(unsigned int columns); 
    
    /**
     * @brief Зашифровывание
     * @param [in] sourcetext Исходный текст. Не должен быть пустой строкой.
     * @return Зашифрованная строка
     * @throw tableCipher_error, если текст пустой
     */
    std::wstring encrypt(const std::wstring& sourcetext); 
    
    /**
     * @brief Расшифровывание
     * @param [in] ciphertext Зашифрованный текст. Не должен быть пустой строкой.
     * @return Расшифрованная строка
     * @throw tableCipher_error, если текст пустой
     */
    std::wstring decrypt(const std::wstring& ciphertext); 
    
    /**
     * @brief Метод проверки ключа на валидность
     * @param [in] s Ключ
     * @return s Валидный ключ
     * @throw tableCipher_error, если ключ пустой, слшиком простой(равен 1)
     * или слишком большой(больше 100)
     */
    unsigned int getValidKey(unsigned int key);

private:
    unsigned int columns; ///< Ключ=количество столбцов
};

/** @brief Класс исключений
 * @details Класс отлова исключений
 */

class tableCipher_error: public std::invalid_argument
{
public:
    explicit tableCipher_error (const std::string& what_arg):
        std::invalid_argument(what_arg) {}
    explicit tableCipher_error (const char* what_arg):
        std::invalid_argument(what_arg) {}
};
