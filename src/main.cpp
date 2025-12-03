
#include <iostream>
#include "../include/Library.h"
#include <thread>
#include <chrono>


using namespace std;

int main() {
    using std::chrono::milliseconds;
    auto pause = [] (const int ms = 600) {
        std::this_thread::sleep_for(milliseconds(ms));
    };

    std::cout << "=== Library demo started ===\n";
    pause();

    Library lib;
    Author a{"Ivan Vazov", 1850};
    Book b1{"Pod igoto", a, 1894, 25.50, "ISBN-001"};
    Book b2{"Nema zemya", a, 1900, 18.90, "ISBN-002"};

    lib.addBook(b1);
    lib.addBook(b2);
    std::cout << "Added 2 books. Total books: " << Book::getTotalBook() << "\n";
    pause();

    lib.addMember(Member{"Petar Petrov", "M001", 2023});
    std::cout << "Added member M001 (Petar Petrov).\n";
    pause();

    cout << lib.to_string() << "\n";
    pause();

    if (lib.loanBook("ISBN-001", "M001", "2025-11-03", "2025-11-17"))
        cout << "Loan created.\n";
    else
        cout << "Loan failed.\n";
    pause();

    cout << "Available ISBN-001? " << boolalpha << lib.isBookAvailable("ISBN-001") << "\n";
    pause();


    cout << "Trying to loan ISBN-001 again to the same member...\n";
    bool secondLoan = lib.loanBook("ISBN-001", "M001", "2025-11-05", "2025-11-20");
    cout << "Second loan success? " << boolalpha << secondLoan << "\n";
    pause();

    lib.returnBook("ISBN-001", "M001");
    cout << "Available ISBN-001? " << boolalpha << lib.isBookAvailable("ISBN-001") << "\n";
    pause();

    lib.addMember(Member{"Maria Ivanova", "M002", 2024});
    cout << "Added member M002 (Maria Ivanova).\n";
    pause();

    bool loan2 = lib.loanBook("ISBN-002", "M002", "2025-11-10", "2025-11-25");
    cout << "Loan ISBN-002 to M002 created? " << boolalpha << loan2 << "\n";
    pause();

    cout << lib.to_string() << "\n";
    pause();

    for (const auto& bk : lib.findByAuthor("Vazov")) {
        cout << bk.to_string() << "\n";
        pause(300);
    }

    std::cout << "=== Library demo finished ===\n";
    return 0;
}
