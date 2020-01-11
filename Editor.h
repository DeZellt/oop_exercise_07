#pragma once

#include <memory>
#include <iostream>
#include "Document.h"
#include "Figure.h"

class Editor {
public:
    void Print(std::ostream& os) const;

    void CreateDocument(std::string& name);

    bool HasDocument() const;

    void Insert(std::shared_ptr<Figure> new_figure);

    void Delete(size_t index);

    void SaveDocument();

    void LoadDocument(std::string& name);

    void Undo();

private:
    std::shared_ptr<Document> document_ = nullptr;
};