//
// Created by dani_gyoshev on 30.11.25 г..
//

#ifndef LIBRARY_PROJECT_LOAN_H
#define LIBRARY_PROJECT_LOAN_H
#include <string>
#include <sstream>

class Loan {
    std::string isbn;
    std::string memberId;
    std::string startDate;
    std::string dueDate;
    bool returned;
public:
    Loan(std::string isbn,
         std::string memberId,
         std::string startDate,
         std::string dueDate,
         const bool returned = false)
        : isbn(std::move(isbn)),
          memberId(std::move(memberId)),
          startDate(std::move(startDate)),
          dueDate(std::move(dueDate)),
          returned(returned) {
        if (this->dueDate < this->startDate) {
            this->dueDate = this->startDate;
        }
    }

    void markReturned() { returned = true; }

    bool isOverdue(const std::string& today) const {
        return !returned && (dueDate < today);
    }

    std::string to_string() const {
        std::stringstream ss;
        ss << "Loan[isbn=" << isbn
           << ", memberId=" << memberId
           << ", startDate=" << startDate
           << ", dueDate=" << dueDate
           << ", returned=" << (returned ? "true" : "false")
           << "]";
        return ss.str();
    }
    // Минимални getter-и за нуждите на Library
    const std::string& getIsbn() const { return isbn; }
    const std::string& getMemberId() const { return memberId; }
    bool isReturned() const { return returned; }
};
#endif //LIBRARY_PROJECT_LOAN_H