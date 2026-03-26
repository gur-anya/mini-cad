#pragma once

#include <string>

/**
 * @brief Базовый интерфейс команды.
 *
 * Реализует паттерн Command.
 * Каждая операция инкапсулируется в отдельный объект.
 */
class Command
{
public:
    virtual ~Command() = default;

    /**
     * @brief Выполняет команду.
     */
    virtual void execute() = 0;

    /**
     * @brief Отменяет выполнение команды.
     */
    virtual void undo() = 0;

    /**
     * @brief Возвращает имя команды.
     * @return строковое имя команды
     */
    virtual std::string name() const = 0;
};
