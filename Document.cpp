#include "Document.h"

Command::Command(Document& document)
: document_(document) {}


AddCommand::AddCommand(Document& document)
: Command(document) {}

void AddCommand::Undo()  {
    document_.figures_.pop_back();
}

DeleteCommand::DeleteCommand(Document& document, std::shared_ptr<Figure>& new_figure, size_t new_index)
: Command(document) {
    figure_ = new_figure;
    index_ = new_index;
}

void DeleteCommand::Undo() {
    document_.figures_.insert(document_.figures_.begin() + index_, figure_);
}

Document::Document(std::string new_name)
: document_name_(std::move(new_name)) {}

void Document::Print(std::ostream& os) const {
    for (const auto& fig : figures_) {
        fig->Print(os);
    }
}

void Document::Rename(const std::string& new_name) {
    document_name_ = new_name;
}

void Document::Undo() {
    if (commands_.empty()) {
        return;
    }
    commands_.back()->Undo();
    commands_.pop_back();
}

void Document::Save() const {
    std::ofstream of(document_name_);
    if (!of) {
        throw std::runtime_error("File open failed");
    }
    of << figures_.size() << "\n";
    for (const auto& elem : figures_) {
        elem->Print(of);
    }
}

void Document::Load(const std::string& filename) {
    std::ifstream ifs(filename);
    if (!ifs) {
        throw std::runtime_error("File open failed");
    }
    size_t size;
    ifs >> size;
    figures_.clear();
    for (size_t i = 0; i < size; ++i) {
        figures_.push_back(Factory::FigureCreate(ifs));
    }
    Rename(filename);
}

void Document::Insert(std::shared_ptr<Figure> new_figure) {
    figures_.push_back(new_figure);
    commands_.push_back(std::make_shared<AddCommand>(*this));
}

void Document::EraseByIndex(size_t index) {
    if (index >= figures_.size()) {
        throw std::out_of_range("Wrong index");
    }
    commands_.push_back(std::make_shared<DeleteCommand>(*this, figures_[index], index));
    figures_.erase(figures_.begin() + index);
}