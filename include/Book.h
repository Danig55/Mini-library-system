//
// Created by dani_gyoshev on 28.11.25 г..
//

#ifndef LIBRARY_PROJECT_BOOK_H
#define LIBRARY_PROJECT_BOOK_H
#include <string>
#include <utility>
#include "Author.h"
#include <sstream>

class Book {
    std::string title;
    Author author;
    int year;
    double price;
    std::string isbn;
    inline static int totalBooks = 0;
    public:
    Book(): title("Unknown"), year(1990), price(0.0), isbn("Unknown"){
        totalBooks++;
    }
    Book(std::string title, Author author, const int year, const double price, std::string isbn) : title(std::move(title)), author(std::move(author)), year(year), price(price), isbn(std::move(isbn)) {
        totalBooks++;
    }
    Book(const Book& other)
        : title(other.title),
          author(other.author),
          year(other.year),
          price(other.price),
          isbn(other.isbn) {
        totalBooks++;
    }
    // Move constructor
    Book(Book&& other) noexcept
        : title(std::move(other.title)),
          author(std::move(other.author)),
          year(other.year),
          price(other.price),
          isbn(std::move(other.isbn)) {
        totalBooks++;
    }
    Book& operator=(const Book& other) {
        if (this != &other) {
            title = other.title;
            author = other.author;
            year = other.year;
            price = other.price;
            isbn = other.isbn;
        }
        return *this;
    }
    Book& operator=(Book&& other) noexcept {
        if (this != &other) {
            title = std::move(other.title);
            author = std::move(other.author);
            year = other.year;
            price = other.price;
            isbn = std::move(other.isbn);
            // Reset source
            other.year = 0;
            other.price = 0.0;
            other.title.clear();
            other.isbn.clear();
        }
        return *this;
    }
    ~Book() {
        totalBooks--;
    }
    void setPrice(const double p) {price = (p >= 0) ? p : 0.0;}
    void setYear(const int y) {year = (y >= 1850 && y <=2025) ? y : 1990;}
    std::string to_string() const {
        std::stringstream ss;
        ss << "Title: " << title << "\n"
        << "Author: " << author.to_string() << "\n"
        << "Year: " << year << "\n"
        << "Price: " << price << "\n"
        << "Isbn: " << isbn << "\n";
        return ss.str();
    }
    static int getTotalBook(){return totalBooks;};
    // Минимални getter-и за нуждите на Library
    const std::string& getIsbn() const { return isbn; }
    const Author& getAuthor() const { return author; }
};


#endif //LIBRARY_PROJECT_BOOK_H