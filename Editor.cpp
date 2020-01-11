//
// Created by Илья on 03.01.2020.
//

#include "Editor.h"


void Editor::Print(std::ostream& os) const {
    if (!HasDocument()) {
        os << "No document\n";
    }
    document_->Print(os);
}

void Editor::CreateDocument(std::string& name) {
    document_ = std::make_shared<Document>(name);
}

bool Editor::HasDocument() const {
    return bool(document_);
};

void Editor::Insert(std::shared_ptr<Figure> new_figure) {
    if (!HasDocument()) {
        throw std::logic_error("No Document");
    }
    document_->Insert(std::move(new_figure));
}

void Editor::Delete(size_t index) {
    if (!HasDocument()) {
        throw std::logic_error("No Document");
    }
    document_->EraseByIndex(index);
}

void Editor::SaveDocument() {
    if (document_ == nullptr) {
        throw std::logic_error("Document wanst created");
    }
    document_ ->Save();
}

void Editor::LoadDocument(std::string& name) {
    document_ = std::make_shared<Document>(name);
    document_->Load(name);
}

void Editor::Undo() {
    if (!HasDocument()) {
        throw std::logic_error("Document wanst created");
    }
    document_->Undo();
}