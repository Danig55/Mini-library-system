//
// Created by dani_gyoshev on 3.12.25 г..
//

#ifndef LIBRARY_PROJECT_LIBRARY_H
#define LIBRARY_PROJECT_LIBRARY_H

#include <vector>
#include <string>
#include <sstream>
#include "Book.h"
#include "Member.h"
#include "loan.h"

class Library {
    std::vector<Book> books;
    std::vector<Member> members;
    std::vector<Loan> loans;

    bool hasMemberInternal(const std::string& memberId) const {
        for (const auto& m : members) {
            if (m.getMemberId() == memberId) return true;
        }
        return false;
    }
public:

    void addBook(const Book& b) { books.push_back(b); }
    void addMember(const Member& m) { members.push_back(m); }

    bool hasBook(const std::string& isbn) const {
        for (const auto& b : books) {
            if (b.getIsbn() == isbn) return true;
        }
        return false;
    }

    bool isBookAvailable(const std::string& isbn) const {
        if (!hasBook(isbn)) return false;
        for (const auto& l : loans) {
            if (l.getIsbn() == isbn && !l.isReturned()) return false;
        }
        return true;
    }

    bool loanBook(const std::string& isbn, const std::string& memberId,
                  const std::string& start, const std::string& due) {
        if (!hasBook(isbn)) return false;
        if (!hasMemberInternal(memberId)) return false;
        if (!isBookAvailable(isbn)) return false;
        loans.emplace_back(isbn, memberId, start, due, false);
        return true;
    }

    bool returnBook(const std::string& isbn, const std::string& memberId) {
        for (auto& l : loans) {
            if (l.getIsbn() == isbn && l.getMemberId() == memberId && !l.isReturned()) {
                l.markReturned();
                return true;
            }
        }
        return false;
    }

    std::vector<Book> findByAuthor(const std::string& authorName) const {
        std::vector<Book> result;
        for (const auto& b : books) {
            // Позволяваме частично съвпадение по име на автора (напр. "Vazov" съвпада с "Ivan Vazov")
            if (b.getAuthor().getName().find(authorName) != std::string::npos) {
                result.push_back(b);
            }
        }
        return result;
    }

    std::string to_string() const {
        std::size_t activeLoans = 0;
        for (const auto& l : loans) if (!l.isReturned()) ++activeLoans;
        std::stringstream ss;
        ss << "Library: books=" << books.size()
           << ", members=" << members.size()
           << ", active_loans=" << activeLoans;
        return ss.str();
    }
};

#endif //LIBRARY_PROJECT_LIBRARY_H