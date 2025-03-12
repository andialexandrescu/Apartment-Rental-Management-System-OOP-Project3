# Project Title:
## Vacation Rental Console App

## Project Summary

It replicates a holiday apartment rental management application, having two user interfaces, being intended for the host and the tenant. In addition, offers and packages are included, along with specifying the facilities and displaying the configuration of the rooms in the listed apartments.
The application was made in C++ and implements OOP concepts, such as operator overload, inheritance, abstract classes, virtual functions, template classes and design patterns.
Testing via the GoogleTest framework is included.

# Description:
It represents an apartment rental management system meant to respond to inquiries based on user input. The user must first specify the intent of using the platform, getting to experience two possible interfaces: Tenant's view or Host's view.

A tenant is able to input search criteria, such as location, number of rooms/guests (1), and maximum price range per individual (per night). A list of results is displayed containing the apartments that fit the chosen criteria. Then, the individual is prompted to either choose an apartment or return to the searching submenu. Once a choice is made, the tenant has to enter the apartment ID assigned and specify the dates of their booking (2). Shortly after, the user has to re-enter the number of guests, mentioning how many are underage, in order to compute the total price of their stay. The last steps of their booking involve user registration and initiating the card transfer process.

The host is prompted immediately to create an account and specify the number of apartments they plan to upload on the platform. After specifying the apartment details, including the layout of rooms and their respective amenities, the host can view a floor plan and access the updated search submenu.

# Technical Implementations:

(1) - These choices are slightly different, considering an apartment might host more people due to its capacity, however, it might have fewer rooms than expected.

(2) - Each apartment has a vector of int variables, being the dates in the year on which it has already been booked by other clients. Since the user must include a start and end date of their stay, this specific time interval is being checked whether it's available or not, then the apartment is booked if it is not overlapping with another time frame.

There's a singular search engine that contains all the apartments listed on the platform. An `ApartmentListingPost` instance is a post including information about the listing itself, along with the corresponding apartment, apartment layout, and comments left by customers, which are posts that exist on their own. A `VacationPackagePost` represents vacation deals that can be separated into categories based on the type of package offered. A `VacationPackagePost` is catered for tour operators and travel agencies, since a representative can create a post containing posts on their own, which can also be downcasted to `ApartmentListingPost`, each being associated with a `PackageType` key.

## Assignment 1

#### Requirements
- [x] Definition of at least **2-3 classes** that interact within the chosen topic (either through composition, aggregation, or simply by calling each other's methods in a logical manner) (5p).
  - For one class:
    - [x] Initialization constructors.
    - [x] Overloaded constructor.
    - [x] Copy constructors.
    - [x] Copy `operator=`.
    - [x] Destructor.
    - [x] `operator<<` for display (std::ostream).
    - [x] `operator>>` for input (std::istream).
    - [x] Another overloaded operator as a member function.
    - [x] Another overloaded operator as a non-member function.
  - For the other classes, only what is necessary will be defined.
- [x] Implementation of at least 3 public member functions for specific functionalities of the chosen topic, among which at least 1-2 more complex functions (3p).
- Not just input/output or adding/removing elements from a vector.
- [x] Usage scenario of the defined classes (1p):
  - Creation of objects and calling all public member functions in `main`.
  - Only examples of keyboard input data will be added in the `tastatura.txt` file (if applicable); if you need data from files, create other files separately.
- [x] Option for reading and displaying n objects (1p).

### Assignment 2

#### Requirements
- [x] Separation of class code into `.h` (or `.hpp`) and `.cpp` [(0.5p)](https://github.com/Ionnier/poo/tree/main/proiect/P01#separarea-implement%C4%83rii-metodelor-din-clase).
- [x] As many `const` as possible [(0.5p)](https://github.com/Ionnier/poo/tree/main/labs/L04#reminder-const-everywhere).
- [x] Inheritance [(5p)](https://github.com/Ionnier/poo/tree/main/labs/L04#exemplu):
  - [x] At least one base class and **2 derived classes**.
  - [ ] Try to derive a previously created class.
    - If you fail:
      - Create another class that can be integrated with the previous classes.
      - Mention why you failed and what you tried.

        Note: I tried to change the logic of the `Reservation` class from project 1 because it behaves like a search engine, intending for `SearchEngine` to become a base class, but I couldn't come up with ideas to implement the derived classes `AdvertisedSearchEngine` and `ComparisonSearchEngine`.
        Therefore, I considered the idea of displaying a floor plan/layout of an apartment along with the amenities of each room to be a practical one.

  - [x] Illustrate [upcasting](https://github.com/Ionnier/poo/tree/main/labs/L04#solu%C8%9Bie-func%C8%9Bii-virtuale-late-binding) and [downcasting](https://github.com/Ionnier/poo/tree/main/labs/L04#smarter-downcast-dynamic-cast) using virtual functions and pointers to the base class.
    - This will be done through **2-3** methods specific to the chosen topic.
    - Input/output functions or the destructor are not included, although you will need to implement them.
  - [x] Calling the base class constructor from [derived constructors](https://github.com/Ionnier/poo/tree/main/labs/L04#comportamentul-constructorului-la-derivare).
  - [x] Overridden [copy constructor](https://github.com/Ionnier/poo/tree/main/labs/L04#comportamentul-constructorului-de-copiere-la-derivare)/`operator=` for correct copying/assignments.
  - [x] Virtual [destructor](https://github.com/Ionnier/poo/tree/main/labs/L04#solu%C8%9Bie-func%C8%9Bii-virtuale-late-binding).
- [x] `static` functions and attributes (in classes) [(1p)](https://github.com/Ionnier/poo/tree/main/labs/L04#static).
- [x] Exceptions [(1p)](https://github.com/Ionnier/poo/tree/main/labs/L04#exception-handling):
  - Start from `std::exception`.
  - Illustrate exception propagation.
  - Illustrate upcasting in catch blocks.
  - Use at least once where traditional error handling is more difficult.
- [x] Use of an abstract class (either for exceptions or inheritance) [(0.5p)](https://github.com/Ionnier/poo/tree/main/labs/L04#clase-abstracte).
- [x] Update the menu & usage scenario [(0.5p)](https://github.com/Ionnier/oop-template-t1/blob/main/main.cpp#L16).
- [x] Reading and displaying n objects [(0.5p)](https://github.com/Ionnier/oop-template-t1/blob/main/main.cpp#L13):
  - Can be combined with demonstrating upcasting & downcasting through a vector to a base class.
  - Can be done anywhere (if you already have a class with a vector, for example, a `Cart` class with a `vector<Product>`).
- [x] Existence of a pull request to the branch you are working on, including the addition of a new derived class that highlights that the changes made are minimal (0.5p).
  - The derived class cannot be one that was deleted and rewritten.
  - The derived class will have new member data + a behavior change on one of the virtual functions.

### Assignment 3

#### Requirements
- Template classes (2p):
  - [x] Creation of a template class hierarchy with at least 2 classes.
  - [x] Illustration of RTTI on template classes.
  - [x] Logical instantiations of the created classes.
- STL (2p):
  - [x] Use of two structures (containers) from STL (without `vector`).
  - [x] Use of an algorithm with a lambda function (e.g., `sort`, `transform`).
- Design Patterns (2p):
  - [x] Use of two design patterns.
- Presentation week 13 (4p):
  - [x] Answers to questions about the code / general C++.
  - [x] Explanation of another structure or algorithm not used (STL).
  - [x] Explanation of two other design patterns.

# Nu primesc notă pentru că nu am pus titlu și descriere

## Cerințe obligatorii

Nerespectarea duce la nepunctarea proiectului

- programul va fi scris în C++
- programul va avea un meniu interactiv (doar pentru ilustrarea funcționalității)
- programul nu are erori de compilare
- programul nu are warning-uri (folosind -Wall)
- existența a minim un punct din fiecare cerință
- fară variabile globale
- datele membre private
- fara headere specifice unui sistem de operare (<windows.h>)
- teste unitare pentru cerințele implementate (unde se poate, dacă nu apar probleme cu setup-ul de teste 😅)
- folosirea a funcționalităților limbajului fără sens
- folosirea a funcționlităților limbajului cu scopul de a încălca "legal" o altă regulă
  - folosirea excesivă a claselor friend
  - folosirea excesviă a elementelor statice

## Tema 1

#### Cerințe
- [x] definirea a minim **2-3 clase** care sa interactioneze in cadrul temei alese (fie prin compunere, agregare sau doar sa apeleze metodele celeilalte intr-un mod logic) (5p)
  - pentru o clasă:
    - [x] constructori de inițializare
    - [x] constructor supraîncărcat
    - [x] constructori de copiere
    - [x] `operator=` de copiere
    - [x] destructor
    - [x] `operator<<` pentru afișare (std::ostream)
    - [x] `operator>>` pentru citire (std::istream)
    - [x] alt operator supraîncărcat ca funcție membră
    - [x] alt operator supraîncărcat ca funcție non-membră
  - pentru celelalte clase se va definii doar ce e nevoie
- [x] implementarea a minim 3 funcții membru publice pentru funcționalități specifice temei alese, dintre care cel puțin 1-2 funcții mai complexe (3p)
- nu doar citiri/afișări sau adăugat/șters elemente într-un/dintr-un vector
- [x] scenariu de utilizare a claselor definite (1p):
  - crearea de obiecte și apelarea tuturor funcțiilor membru publice în main
  - vor fi adăugate în fișierul `tastatura.txt` DOAR exemple de date de intrare de la tastatură (dacă există); dacă aveți nevoie de date din fișiere, creați alte fișiere separat
- [x] opțiune pentru citirea și afișarea a n obiecte (1p)

### Tema 2

#### Cerințe
- [x] separarea codului din clase în `.h` (sau `.hpp`) și `.cpp` [(0.5p)](https://github.com/Ionnier/poo/tree/main/proiect/P01#separarea-implement%C4%83rii-metodelor-din-clase)
- [x] cât mai multe `const` [(0.5p)](https://github.com/Ionnier/poo/tree/main/labs/L04#reminder-const-everywhere)
- [x] moșteniri [(5p)](https://github.com/Ionnier/poo/tree/main/labs/L04#exemplu):
  - [x] minim o clasă de bază și **2 clase derivate**
  - [ ] încercați să derivați o clasă creată anterior
    - dacă nu reușiți
      - creați o altă clasă care poate fi integrată cu clasele anterioare
      - menționați de ce nu ați reușit și ce ați încercat

        mentiune: am incercat sa schimb logica clasei Reservation din proiectul 1 deoarece se comporta asemenea unui search engine, urmand ca SearchEngine sa devina o clasa de baza, insa nu mi-au venit idei pt a implementa clasele derivate AdvertisedSearchEngine si ComparisonSearchEngine.
        de aceea, am considerat ca ideea de a afisa un floor plan/ layout al unui apartament impreuna cu facilitatile fiecarei camere ar fi una practica.

  - [x] ilustrați [upcast](https://github.com/Ionnier/poo/tree/main/labs/L04#solu%C8%9Bie-func%C8%9Bii-virtuale-late-binding)-ul și [downcast](https://github.com/Ionnier/poo/tree/main/labs/L04#smarter-downcast-dynamic-cast)-ul folosind funcții virtuale și pointeri la clasa de bază
    - aceasta va fi făcută prin **2-3** metode specifice temei alese
    - funcțiile pentru citire / afișare sau destructorul nu sunt incluse deși o să trebuiască să le implementați
  - [x] apelarea constructorului din clasa de bază din [constructori din derivate](https://github.com/Ionnier/poo/tree/main/labs/L04#comportamentul-constructorului-la-derivare)
  - [x] suprascris [cc](https://github.com/Ionnier/poo/tree/main/labs/L04#comportamentul-constructorului-de-copiere-la-derivare)/op= pentru copieri/atribuiri corecte
  - [x] destructor [virtual](https://github.com/Ionnier/poo/tree/main/labs/L04#solu%C8%9Bie-func%C8%9Bii-virtuale-late-binding)
- [x] funcții și atribute `static` (în clase) [(1p)](https://github.com/Ionnier/poo/tree/main/labs/L04#static)
- [x] excepții [(1p)](https://github.com/Ionnier/poo/tree/main/labs/L04#exception-handling)
  - porniți de la `std::exception`
  - ilustrați propagarea excepțiilor
  - ilustrati upcasting-ul în blocurile catch
  - minim folosit într-un loc în care tratarea erorilor în modurile clasice este mai dificilă
- [x] folosirea unei clase abstracte (fie la exceptii, fie la moșteniri) [(0.5p)](https://github.com/Ionnier/poo/tree/main/labs/L04#clase-abstracte)
- [x] actualizarea meniului & scenariului de utilizare [(0.5p)](https://github.com/Ionnier/oop-template-t1/blob/main/main.cpp#L16)
- [x] citirea și afișarea a n obiecte [(0.5p)](https://github.com/Ionnier/oop-template-t1/blob/main/main.cpp#L13)
  - poate fi combinat cu demonstrarea upcasting-ului & downcast-ului printr-un vector către o clasă de bază
  - poate fi făcut oriunde (dacă aveți deja o clasă cu un vector, de exemplu o clasă Coș cu un vector<Produs>)
- [x] existența unui pull request către branch-ul în care lucrați ce include adăugarea unei noi derivate ce evidențiază că modificările aduse sunt minimale (0.5p)
  - derivata nu poate fi una ștearsă și rescrisă
  - derivata va avea date membre noi + o modificare de comportament pe una dintre funcțiile virtuale

### Tema 3

#### Cerințe
- Clase template (2p)
  - [x] crearea unei ierarhii de clase template cu minim 2 clase
  - [x] ilustrarea RTTI pe clase template
  - [x] instanțieri cu logică a claselor create
- STL (2p)
  - [x] utilizarea a două structuri (containere) din STL (fără vector)
  - [x] utilizarea a unui algoritm cu funcție lambda (de exemplu, sort, transform)
- Design Patterns (2p)
  - [x] utilizarea a două șabloane de proiectare
- Prezentare sapt 13(4p)
  - [x] răspunsuri la întrebări din cod / generale C++
  - [x] explicarea a unei alte structuri sau a altui algoritm neutilizat (STL)
  - [x] explicarea a altor două șabloane de proiectare


## Recomandare Tema

* rezolvați tema 1 cu niște itemi generali ca să puteți extinde tema cu ușurință la următoarele teme.
  - coș de cumpărături + produse
  - sistem de validare a documentelor + documente de identitate
  - sistem de gestionare a biletelor + bilet
* funcționalitatea creată să folosească metode ale obiectului generic
* ar fi bine ca relația de agregare să fie făcută cu un obiect general în stilul celor de mai sus ^
* branch-uri + commit-uri punctuale
