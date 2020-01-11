#include <iostream>

#include "Document.h"
#include "Editor.h"
#include "Trapeze.h"
#include "Rectangle.h"


int main () {
    Editor editor;
    std::string command;
    while (std::cin >> command) {
        if (command == "create") {
            std::string name;
            std::cout << "Enter name of new document\n";
            std::cin >> name;
            editor.CreateDocument(name);
        } else if (command == "load") {
            std::string name;
            std::cout << "Enter path to the file\n";
            std::cin >> name;
            try {
                editor.LoadDocument(name);

            } catch (std::exception& e) {
                std::cout << e.what();
            }
        } else if (command == "save") {
            try {
                editor.SaveDocument();
            } catch (std::exception& e) {
                std::cout << e.what();
            }
        } else if (command == "add") {
            try {
                std::shared_ptr<Figure> new_fig = Factory::FigureCreate(std::cin);
                editor.Insert(new_fig);
            } catch (std::exception& e) {
                std::cout << e.what() << '\n';
                continue;
            }
            std::cout << "Ok\n";
        } else if (command == "remove") {
            size_t index;
            std::cout << "Enter index\n";
            std::cin >> index;
            try {
                editor.Delete(index);
                std::cout << "Ok\n";
            } catch (std::exception& err) {
                std::cout << err.what() << "\n";
            }
        } else if (command == "undo") {
            try {
                editor.Undo();
            } catch (std::exception& e) {
                std::cout << e.what();
            }
        } else if (command == "print") {
            editor.Print(std::cout);
        } else {
            std::cout << "Unknown command\n";
            std::cin.ignore(32768, '\n');
        }
    }
}