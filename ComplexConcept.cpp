// DZ_34.7.1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <concepts>
#include <string>
#include <type_traits>

// Проверка, что у типа T есть метод hash(), возвращающий что-то, конвертируемое к long
template <typename T>
concept HasHashMethod = requires(T t) {
    { t.hash() } -> std::convertible_to<long>;
};

// Проверка, что у типа T есть метод toString(), возвращающий std::string
template <typename T>
concept HasToStringMethod = requires(T t) {
    { t.toString() } -> std::same_as<std::string>;
};

// Проверка, что у типа T отсутствует виртуальный деструктор
template <typename T>
concept NoVirtualDestructor = !std::has_virtual_destructor_v<T>;

// Основной концепт, объединяющий все условия
template <typename T>
concept ComplexConcept = HasHashMethod<T> && HasToStringMethod<T> && NoVirtualDestructor<T>;