/** @file
 * @author Храбров А.А.
 * @version 1.0
 * @date 09.12.2024
 * @copyright ИБСТ ПГУ
 * @warning Тестовый
 * @brief Заголовочный файл для модуля modAlphaCipher.cpp
 */

#pragma once
#include <vector>
#include <string>
#include <map>
#include <stdexcept>
#include <codecvt>
#include <locale>

/** @brief Шифрование методом Гронсфельда
 *   @details Ключ устанавливается в конструкторе.
 * Для зашифровывания и расшифровывания предназначены методы encrypt и decrypt.
 *  @warning Реализация только для русского языка
 */

class modAlphaCipher {
private:
    std::wstring numAlpha = L"АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ"; ///< Русский алфавит по порядку
    std::map<wchar_t, int> alphaNum; ///< Ассоциативный массив "номер по символу"
    std::vector<int> key; ///< ключ
    
    /** @brief Метод преобразования строки в вектор
     * @details Каждой букве присваивается номер
     * согласно алфавиту по порядку
     * @param [in] s Строка
     * @return Вектор букв со своими позициями
     */
    std::vector<int> convert(const std::wstring& s); 
    
    /** @brief Метод преобразования вектора в строку
     * @details Каждой букве присваивается номер
     * согласно алфавиту по порядку
     * @param [in] v Вектор
     * @return Строка
     */
    std::wstring convert(const std::vector<int>& v); 
    
    /** @brief Метод получения валидного ключа
     * @param [in] key Ключ
     * @return Строка с валидныи ключом
     * @throw modAlphaCipher_error, 
     * если ключ невалидный
     */
    std::wstring getValidKey(const std::wstring& key); 
    
    /** @brief Метод получения валидного входного текста
     * @param [in] text Текст для зашифрования/расшифрования
     * @return Строка с валидныи текстом
     * @throw modAlphaCipher_error, 
     * если текст невалидный
     */
    std::wstring getValidText(const std::wstring& text); 

public:
    modAlphaCipher() = delete; ///< запретим конструктор без параметров
    
    /** @brief Конструктор для установки ключа
     * @details Записывает в переменную класса
     * вектор позиции букв полученные из строки с помощью convert
     * @param [in] skey Строка-ключ
     */
    modAlphaCipher(const std::wstring& skey); 
    
    /** @brief Функция зашифрования текста
     * @details Функция шифрует строку методом Гронсфельда
     * @param [in] open_text Строка с текстом для зашифрования
     */
    std::wstring encrypt(const std::wstring& open_text); 
    
    /** @brief Функция расшифрования текста
     * @details Функция расшифровывает строку 
     * зашифрованную методом Гронсфельда
     * @param [in] cipher_text Строка с зашифрованным текстом
     */
    std::wstring decrypt(const std::wstring& cipher_text); 
    std::wstring checkValid(std::wstring& open_text, std::wstring& cipher_text);
};

/** @brief Класс исключений
 * @details Класс для отлова исключений
 */
class modAlphaCipher_error: public std::invalid_argument
{
public:
    explicit modAlphaCipher_error (const std::string& what_arg):
        std::invalid_argument(what_arg) {}
    explicit modAlphaCipher_error (const char* what_arg):
        std::invalid_argument(what_arg) {}
};
