#pragma once

#include <string>
#include <vector>
#include <fstream>
#include <memory>
#include <exception>


#include "Figure.h"
#include "Factory.h"

class Command;
class Document;


class Command {
public:
    Command(Document& document);
    virtual ~Command() = default;
    virtual void Undo() = 0;


protected:
    Document& document_;
};

class AddCommand : public Command {
public:
    AddCommand(Document& document);
    void Undo() override;
};

class DeleteCommand : public Command {
public:
    DeleteCommand(Document& document, std::shared_ptr<Figure>& new_figure, size_t new_index);
    void Undo() override;

private:
    std::shared_ptr<Figure> figure_;
    unsigned int index_;
};


class Document {
public:
    friend class AddCommand;
    friend class DeleteCommand;

    Document(std::string new_name);

    void Print(std::ostream& os) const;

    void Rename(const std::string& new_name);

    void Undo();

    void Save() const;

    void Load(const std::string& filename);

    void Insert(std::shared_ptr<Figure> new_figure);

    void EraseByIndex(size_t index);

private:

    std::vector<std::shared_ptr<Figure>> figures_;
    std::vector<std::shared_ptr<Command>> commands_;
    std::string document_name_;
};