#ifndef OOP_SEARCHENGINE_H
#define OOP_SEARCHENGINE_H

#include "Apartment.h"

// using singleton design pattern since all the apartments listed on the site share a single engine, being stored in a common timeline of apts, which is l_apts
class SearchEngine { // reservation also acts as a submenu for choosing an apartment
private:
    std::vector<Apartment> l_apts;
    SearchEngine() = default; // preventing direct instantiation
public:
    SearchEngine(const SearchEngine &other_obj) = delete; // copying other instances is not allowed
    SearchEngine& operator=(const SearchEngine &other_obj) = delete; // assignment not allowed either
    static SearchEngine& getTimeline();
    ~SearchEngine();

    // operators
    SearchEngine& operator+=(const Apartment &apt); // operator overloading as member functions
    friend std::ostream& operator<<(std::ostream& out, const SearchEngine &obj);// operator overloading as friend/ non-member functions
    // getters
    [[nodiscard]] std::vector<Apartment> getApts() const;

    // other methods
    static void searchResults();
    static void convertDate(int year, int month, int day, int &date);
    void proceedTransaction(bool &booked);
    static void computeTransaction(const Apartment &apt, int start_date, int end_date);
};

extern SearchEngine& query; // the query is declared as extern so it can be used across different source files

#endif //OOP_SEARCHENGINE_H